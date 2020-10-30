#include "integration.h"

#include <appcommandlineparser.h>
#include <applicationpluginmanager.h>

#include <greenhousecontext.h>
#include <greenhousetestfixture.h>
#include <greenhousetheme.h>

#include <QQmlContext>
#include <QQuickWindow>

#include <QCoreApplication>

#include <Calculator/statemachinefactory.hpp>
#include <Calculator/remoteiteminterfaces.hpp>

Integration::Integration(QQmlEngine *engine, QObject *parent) :
    QObject(parent)
   , m_engine(engine)
{
   loadPluginConfig();
}


Integration::Integration(QObject *parent) :
    QObject(parent)
{
   loadPluginConfig();
}

Integration::~Integration()
{
    delete m_context;
}

void Integration::mainWindowCreated(QQuickItem *mainContainer, QQuickWindow *window)
{
    if (m_context) {
        // NOTE: We are dealing with a UI reload scenario, if we already have a valid context instance
        m_context->setRootItem(mainContainer);
    } else {
        m_context = new GreenHouse::Context(m_engine, QStringLiteral("Calculator"), mainContainer);

        if (m_applicationPluginManager)
            m_applicationPluginManager->inject(m_context);

        m_context->setLayoutPrefix(QStringLiteral("qrc:/Calculator/layouts/"));

        Calculator::StateMachineFactory factory;
        m_context->startExecution(factory, this);

        connectToSimulator(window);
        connectToBackend();
    }
    if (window)
        window->show();
}

void Integration::startExecution()
{
    if (!m_context) {
        m_context = new GreenHouse::Context();

        if (m_applicationPluginManager)
            m_applicationPluginManager->inject(m_context);

        Calculator::initializeRemoteUXInterfaces(new GreenHouse::RemoteUXInterfaceManager(m_context, this));
        auto remoteUIServer = new GreenHouse::WebSocketRPCServer(m_context, {}, QWebSocketServer::NonSecureMode);
        remoteUIServer->listen(QHostAddress::Any, 26187);
        remoteUIServer->setMessageTypeBlacklist({ GreenHouse::PropertyValueSet,
                                                  GreenHouse::EventInvoked,
                                                  GreenHouse::MethodInvoked,
                                                  GreenHouse::ModelPopulated,
                                                  GreenHouse::ModelRowRemoved,
                                                  GreenHouse::ModelRowPrepended,
                                                  GreenHouse::ModelRowAppended,
                                                  GreenHouse::ModelRowDataSet });
        remoteUIServer->setServiceName(QStringLiteral("Remote UI Server"));
        Calculator::StateMachineFactory factory;
        m_context->startExecution(factory, this);

        connectToSimulator(nullptr);
        connectToBackend();
    }
}

void Integration::loadPluginConfig()
{
    if (AppCommandLineParser::remoteBackend())
        return;
    QDir pluginDir;
    if (AppCommandLineParser::pluginPath().isEmpty()) {
        pluginDir = QDir(qApp->applicationDirPath());
        if (!QFile::exists(pluginDir.absoluteFilePath(QStringLiteral("plugins"))))
            pluginDir.cdUp();
        pluginDir.cd(QStringLiteral("plugins"));
    } else {
        pluginDir = QDir(AppCommandLineParser::pluginPath());
    }
    if (pluginDir.exists()) {
        m_applicationPluginManager = new ApplicationPluginManager(
                pluginDir.absoluteFilePath(QStringLiteral("config.json")), pluginDir.absolutePath(), this);
    }
}

void Integration::connectToBackend()
{
    if (!AppCommandLineParser::remoteBackend())
        return;
    auto backendSocket = new GreenHouse::WebSocketRPC(m_context);
    backendSocket->setServiceName(QStringLiteral("Remote Backend Socket"));
    backendSocket->connectTo(QUrl(QStringLiteral("ws://%1:%2")
                                    .arg(AppCommandLineParser::backendUrl())
                                    .arg(AppCommandLineParser::backendPort())));
}

void Integration::connectToSimulator(QQuickWindow *window)
{
    if (!AppCommandLineParser::simulator())
        return;
    QString variableDirection = QLatin1String(qgetenv("DIRECTION_APP_TO_SIMULATOR"));
    bool appToSimulator = !variableDirection.isEmpty();
    if (appToSimulator) {
        auto appServer = new GreenHouse::WebSocketRPCServer(m_context, {}, QWebSocketServer::NonSecureMode);
        appServer->setServiceName(QStringLiteral("Simulator Server"));
        appServer->listen(QHostAddress::Any, AppCommandLineParser::simulatorPort());
    } else {
        auto simulatorSocket = new GreenHouse::WebSocketRPC(m_context);
        simulatorSocket->setServiceName(QStringLiteral("Simulator Socket"));
        simulatorSocket->connectTo(QUrl(QStringLiteral("ws://%1:%2")
                                        .arg(AppCommandLineParser::simulatorUrl())
                                        .arg(AppCommandLineParser::simulatorPort())));
    }
    if (window)
        new GreenHouse::TestFixture(m_context, window);
}
