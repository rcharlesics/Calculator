#include "appcommandlineparser.h"

#include <QCoreApplication>
#include <QCommandLineParser>
#include <QProcess>

struct AppCoreQRCInit {
    AppCoreQRCInit() { Q_INIT_RESOURCE(imports); }
};

namespace {

QString parseDebugOptions(const QString &debug)
{
    if (debug.contains(QStringLiteral("all")))
        return QStringLiteral("*.debug=true");
    else if (debug.contains(QStringLiteral("none")))
        return QStringLiteral("*.debug=false");
    QString res = QStringLiteral("*.debug=false\n");
    const QStringList enabledOptions = debug.split(QLatin1Char(','), QString::SkipEmptyParts);
    for (const QString &option : enabledOptions)
        res.append(QStringLiteral("%1.debug=true\n").arg(option.trimmed()));
    return res;
}
}

QString AppCommandLineParser::s_loggingFilters = QStringLiteral("*.debug=false\n"
                                                                "qml.debug=true\n"
                                                                "theming.debug=true\n"
                                                                "statemachine.debug=true\n"
                                                                "appcore.debug=true\n");

QString AppCommandLineParser::s_pluginPath = QString();

bool AppCommandLineParser::s_remoteBackend = false;
quint16 AppCommandLineParser::s_backendPort = 26185;
QString AppCommandLineParser::s_backendUrl = QStringLiteral("localhost");

bool AppCommandLineParser::s_simulator = false;
quint16 AppCommandLineParser::s_simulatorPort = 26186;
QString AppCommandLineParser::s_simulatorUrl = QStringLiteral("localhost");

AppCommandLineParser::AppCommandLineParser(const QStringList &args)
{
    static AppCoreQRCInit init;

#ifdef Q_OS_WASM
    QStringList envList = QProcess::systemEnvironment();
    for (QList<QString>::iterator it = envList.begin(); it != envList.end(); ++it) {
        QStringList lst = (*it).split(QStringLiteral("="));
        if (lst.count() < 2)
            continue;
        QString var = lst.value(0).trimmed();
        QString val = lst.value(1).trimmed();
        if (var.contains(QStringLiteral("REMOTE_BACKEND"))) {
            m_remoteBackend = val == QStringLiteral("1") || val.toLower() == QStringLiteral("true");
        } else if (var.contains(QStringLiteral("BACKEND_PORT"))) {
            m_backendPort = val.toInt();
        } else if (var.contains(QStringLiteral("BACKEND_URL"))) {
            m_backendUrl = val;
        }
    }
#endif

    QCommandLineParser parser;
    parser.setApplicationDescription(qApp->applicationName());
    const QCommandLineOption versionOption = parser.addVersionOption();
    const QCommandLineOption helpOption = parser.addHelpOption();

    // Add additional debug options here
    QLatin1String debugOptionDescription =
            QLatin1String("Enable debug options:\n"
                          "with <component> being a comma separated list of:\n"
                          "      greenhouse: enable GreenHouse library log messages\n"
                          "         theming: enable GreenHouse theming log messages\n"
                          "             rpc: enable GreenHouse RPC log messages\n"
                          "    statemachine: enable GreenHouse state machine log messages\n"
                          "         appcore: enable AppCore library log messages\n"
                          "             qml: enable QML console log messages\n"
                          "             all: Turn all log messages on (noisy)\n"
                          "            none: Turn all log messages off (default)\n");
    const QCommandLineOption debugOption(
            { QStringLiteral("d"), QStringLiteral("debug") },
            QCoreApplication::translate("main", debugOptionDescription.latin1()),
            QStringLiteral("component"), QStringLiteral("none"));
    parser.addOption(debugOption);

    QCommandLineOption pluginDir(
            { QStringLiteral("c"), QStringLiteral("pluginDir") },
            QCoreApplication::translate("main",
                                        "Used to specify a path to the plugin directory.\n"
                                        "   e.g. '/usr/lib64/plugin-dir' \n"),
            QStringLiteral("path"), QString());
    parser.addOption(pluginDir);

    QCommandLineOption remoteBackend(
            { QStringLiteral("remoteBackend") },
            QCoreApplication::translate(
                    "main",
                    "Used to sepcify if the application should connect to a remote backend.\n"));
    parser.addOption(remoteBackend);

    QCommandLineOption backendPort(
            { QStringLiteral("backendPort") },
            QCoreApplication::translate(
                    "main",
                    "Used to sepcify the port used to connect to a backend instance.\n"
                    "   e.g. '26186'. \n"),
            QStringLiteral("port"));
    parser.addOption(backendPort);

    QCommandLineOption backendUrl(
            { QStringLiteral("backendUrl") },
            QCoreApplication::translate(
                    "main",
                    "Used to sepcify the URL used to connect to a backend instance.\n"
                    "   e.g. 'localhost'. \n"),
            QStringLiteral("url"), s_backendUrl);
    parser.addOption(backendUrl);

    QCommandLineOption simulator(
            { QStringLiteral("simulator") },
            QCoreApplication::translate(
                    "main", "Used to sepcify if the application should connect to a simulator.\n"));
    parser.addOption(simulator);

    QCommandLineOption simulatorPort(
            { QStringLiteral("simulatorPort") },
            QCoreApplication::translate(
                    "main",
                    "Used to sepcify the port used to connect to a simulator instance.\n"
                    "   e.g. '26186'. \n"),
            QStringLiteral("port"));
    parser.addOption(simulatorPort);

    QCommandLineOption simulatorUrl(
            { QStringLiteral("simulatorUrl") },
            QCoreApplication::translate(
                    "main",
                    "Used to sepcify the URL used to connect to a simulator instance.\n"
                    "   e.g. 'localhost'. \n"),
            QStringLiteral("url"), s_simulatorUrl);
    parser.addOption(simulatorUrl);

    parser.process(args);

    if (parser.isSet(versionOption))
        parser.showVersion();

    if (parser.isSet(helpOption))
        parser.showHelp();

    if (parser.isSet(debugOption))
        s_loggingFilters = parseDebugOptions(parser.value(debugOption));

    if (parser.isSet(pluginDir))
        s_pluginPath = parser.value(pluginDir);

    if (parser.isSet(remoteBackend))
        s_remoteBackend = parser.isSet(remoteBackend);

    if (parser.isSet(backendPort))
        s_backendPort = parser.value(backendPort).toUInt();

    if (parser.isSet(backendUrl))
        s_backendUrl = parser.value(backendUrl);

    s_simulator = parser.isSet(simulator);

    if (parser.isSet(simulatorPort))
        s_simulatorPort = parser.value(simulatorPort).toUInt();

    if (parser.isSet(simulatorUrl))
        s_simulatorUrl = parser.value(simulatorUrl);
}

QString AppCommandLineParser::loggingFilters()
{
    return s_loggingFilters;
}

QString AppCommandLineParser::pluginPath()
{
    return s_pluginPath;
}

bool AppCommandLineParser::remoteBackend()
{
    return s_remoteBackend;
}

quint16 AppCommandLineParser::backendPort()
{
    return s_backendPort;
}

QString AppCommandLineParser::backendUrl()
{
    return s_backendUrl;
}

bool AppCommandLineParser::simulator()
{
    return s_simulator;
}

quint16 AppCommandLineParser::simulatorPort()
{
    return s_simulatorPort;
}

QString AppCommandLineParser::simulatorUrl()
{
    return s_simulatorUrl;
}
