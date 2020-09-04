#include <QApplication>
#include <QIcon>

#include <greenhousecontext.h>

#include <appcommandlineparser.h>

#include "simulator.hpp"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    app.setApplicationName(QStringLiteral("Calculator_Simulator"));
    app.setApplicationVersion(QStringLiteral("1.0.0"));
    app.setOrganizationName(QStringLiteral("ICS"));
    app.setOrganizationDomain(QStringLiteral("com.ics"));
    app.setWindowIcon(QIcon(QStringLiteral(":/icons/Simulator.png")));

    AppCommandLineParser cmdParser(app.arguments());
    QLoggingCategory::setFilterRules(cmdParser.loggingFilters());

    const QString variableDirection = QLatin1String(qgetenv("DIRECTION_APP_TO_SIMULATOR"));
    const bool appToSimulator = !variableDirection.isEmpty();

    GreenHouse::Context ctx;
    // When using a custom Simulator class derived from the regular one instantiate the object here.
    Calculator::Simulator simulator(&ctx);
    simulator.init(QUrl(QStringLiteral("qrc:/qml/main.qml")));
    simulator.setServerPort(cmdParser.simulatorPort());

    GreenHouse::RPCServiceInterface *interface = nullptr;
    if (appToSimulator) {
        auto simulatorSocket = new GreenHouse::WebSocketRPC(&ctx);
        simulatorSocket->setServiceName(QStringLiteral("Simulator Socket"));
        simulatorSocket->connectTo(QUrl(QStringLiteral("ws://%1:%2")
                                        .arg(cmdParser.simulatorUrl())
                                        .arg(cmdParser.simulatorPort())));
        interface = simulatorSocket;
        simulator.setConnectionDirectionReversed(true);
        QObject::connect(simulatorSocket, &QWebSocket::connected,
                         [&simulator]() -> void { simulator.setActiveConnections(1); });
        QObject::connect(simulatorSocket, &QWebSocket::disconnected,
                         [&simulator]() -> void { simulator.setActiveConnections(0); });
    } else {
        auto simulatorServer =
                new GreenHouse::WebSocketRPCServer(&ctx, {}, QWebSocketServer::NonSecureMode);
        simulatorServer->setServiceName(QStringLiteral("Simulator Server"));
        simulatorServer->listen(QHostAddress::Any, quint16(simulator.serverPort()));
        QObject::connect(
                &simulator, &Calculator::Simulator::serverPortChanged,
                simulatorServer,
                [&]() -> void {
                    if (simulatorServer->isListening())
                        simulatorServer->close();
                    simulatorServer->listen(QHostAddress::Any, quint16(simulator.serverPort()));
                });
        QObject::connect(
                simulatorServer, &GreenHouse::WebSocketRPCServer::activeConnectionCountChanged,
                &simulator, &Calculator::Simulator::setActiveConnections);
        interface = simulatorServer;
    }
    interface->setMessageTypeBlacklist({ GreenHouse::EventInvoked, GreenHouse::MethodInvoked });
    interface->installPayloadHook([&](const QJsonObject &data) -> void {
        if (simulator.processMessagePayload(data))
            return;

        auto objIt = data.constFind(GreenHouse::THEMES_RESPONSE_TAG);
        if (objIt != data.constEnd()) {
            const QJsonArray array = objIt.value().toArray();
            QStringList themes;
            for (auto value : array)
                themes.append(value.toString());
            simulator.setAvailableThemes(themes);
        }

        objIt = data.constFind(GreenHouse::OBJECT_ID_TAG);
        if (objIt != data.constEnd()) {
            auto objectWrapper = simulator.object(objIt.value().toInt());
            if (!objectWrapper)
                return;

            objIt = data.constFind(GreenHouse::MSG_TYPE_TAG);
            if (objIt == data.constEnd())
                return;

            GreenHouse::MessageType messageType =
                    GreenHouse::MessageType(objIt.value().toInt(GreenHouse::InvalidOperation));
            if (messageType != GreenHouse::MethodInvoked)
                return;

            objIt = data.constFind(GreenHouse::MSG_DATA_TAG);
            if (objIt == data.constEnd())
                return;

            const QJsonObject payloadData = objIt.value().toObject();
            auto method = objectWrapper->method(payloadData.value(GreenHouse::NAME_TAG).toString());
            if (method)
                method->call(payloadData.value(GreenHouse::ARGS_TAG).toObject().toVariantMap());
        }
    });

    return app.exec();
}
