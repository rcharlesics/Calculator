#include <QLoggingCategory>

#ifndef HEADLESS
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QQuickItem>
#else
#include <QCoreApplication>
#endif

#include "integration.h"

#include <appcommandlineparser.h>

int main(int argc, char *argv[])
{
#ifndef HEADLESS
    QGuiApplication app(argc, argv);
#else
    QCoreApplication app(argc, argv);
#endif

    app.setApplicationName(QStringLiteral("Calculator"));
    app.setApplicationVersion(QStringLiteral("1.0.0"));
    app.setOrganizationName(QStringLiteral("ICS"));
    app.setOrganizationDomain(QStringLiteral("com.ics"));

    AppCommandLineParser cmdParser(app.arguments());
    QLoggingCategory::setFilterRules(cmdParser.loggingFilters());

#ifndef HEADLESS
    QQmlApplicationEngine engine;
    Integration *integration = new Integration(&engine, &engine);
    engine.rootContext()->setContextProperty(QStringLiteral("Integration"), integration);
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
#else
    Integration integration(&cmdParser);
    integration.startExecution();
#endif

    return app.exec();
}
