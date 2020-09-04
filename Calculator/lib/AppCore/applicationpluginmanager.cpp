#include "applicationpluginmanager.h"
#include "applicationplugininterface.h"
#include "appcore_log.h"

#include <greenhousecontext.h>

#include <QPluginLoader>
#include <QDir>
#include <QFileInfo>
#include <QJsonDocument>

struct AppCoreQRCInit {
    AppCoreQRCInit() { Q_INIT_RESOURCE(imports); }
};
static AppCoreQRCInit init;

namespace {
const QString WHITE_LIST_TAG = QStringLiteral("WhiteList");
const QString BLACK_LIST_TAG = QStringLiteral("BlackList");
const QString IID_TAG = QStringLiteral("IID");
const QString META_DATA_TAG = QStringLiteral("MetaData");
const QString NAME_TAG = QStringLiteral("name");
const QString VERSION_TAG = QStringLiteral("version");
}

ApplicationPluginManager::ApplicationPluginManager(const QString &configFileName,
                                                   const QString &pluginPath, QObject *parent)
  : QObject(parent)
{
    QMap<QString, QString> whiteList;
    QMap<QString, QString> blackList;
    QFile configFile(configFileName);
    if (configFile.exists() && configFile.open(QIODevice::ReadOnly)) {
        QJsonParseError err = {};
        const QJsonDocument configDoc = QJsonDocument::fromJson(configFile.readAll(), &err);
        if (err.error != QJsonParseError::NoError) {
            acWarning() << "Parsing of plugin configuration file" << configFileName
                        << "failed:" << err.errorString();
        } else {
            const QJsonObject configObj = configDoc.object();
            auto objIt = configObj.find(WHITE_LIST_TAG);
            if (objIt != configObj.constEnd()) {
                const QJsonArray whiteListArray = objIt.value().toArray();
                for (const QJsonValue &val : whiteListArray) {
                    const QJsonObject entry = val.toObject();
                    for (auto it = entry.constBegin(); it != entry.constEnd(); ++it)
                        whiteList.insert(it.key(), it.value().toString());
                }
            }

            objIt = configObj.find(BLACK_LIST_TAG);
            if (objIt != configObj.constEnd()) {
                const QJsonArray blackListArray = objIt.value().toArray();
                for (const QJsonValue &val : blackListArray) {
                    const QJsonObject entry = val.toObject();
                    for (auto it = entry.constBegin(); it != entry.constEnd(); ++it)
                        blackList.insert(it.key(), it.value().toString());
                }
            }
        }
    } else {
        acCritical() << "Plugins configuration file" << configFileName
                     << "does not exist or is not readable";
    }

    QDir pluginDir = QDir(pluginPath);
    if (pluginDir.exists()) {
        for (const QString &fileName : pluginDir.entryList(QDir::Files)) {
            QPluginLoader *plugin = new QPluginLoader(pluginDir.absoluteFilePath(fileName), this);
            const QJsonObject metaData = plugin->metaData();
            auto objIt = metaData.find(IID_TAG);
            if (objIt != metaData.constEnd()) {
                const QString iid = objIt.value().toString();
                if (iid.compare(QStringLiteral(ApplicationPluginInterface_iid)) == 0) {
                    objIt = metaData.find(META_DATA_TAG);
                    if (objIt != metaData.constEnd()) {
                        const QJsonObject pluginData = objIt.value().toObject();
                        objIt = pluginData.find(NAME_TAG);
                        if (objIt != pluginData.constEnd()) {
                            const QString name = objIt.value().toString();
                            objIt = pluginData.find(VERSION_TAG);
                            if (objIt != pluginData.constEnd()) {
                                const QString version = objIt.value().toString();
                                if (!name.isEmpty() && !version.isEmpty()
                                    && (whiteList.value(name).compare(version) == 0
                                        || (whiteList.isEmpty()
                                            && blackList.value(name).compare(version) != 0))) {
                                    acInfo() << "LOADED:" << name << version;
                                    m_plugins.append(plugin);
                                    continue;
                                } else {
                                    acInfo() << "BLOCKED BY CONFIG:" << name << version;
                                }
                            } else {
                                acWarning() << fileName << "ignored, missing plugin version.";
                            }
                        } else {
                            acWarning() << fileName << "ignored, missing plugin name.";
                        }
                    } else {
                        acWarning() << fileName << "ignored, missing plugin meta data.";
                    }
                }
            }
            plugin->deleteLater();
        }
    }
}

ApplicationPluginManager::~ApplicationPluginManager()
{
#if (QT_VERSION >= QT_VERSION_CHECK(5, 7, 0))
    for (QPluginLoader *plugin : m_plugins) {
        if (plugin->isLoaded())
            plugin->unload();
    }
#endif
}

void ApplicationPluginManager::inject(GreenHouse::Context *context)
{
    QList<ApplicationPluginInterface *> injected;
#if (QT_VERSION >= QT_VERSION_CHECK(5, 7, 0))
    for (QPluginLoader *plugin : qAsConst(m_plugins)) {
#else
    for (auto it = m_plugins.constBegin(); it != m_plugins.constEnd(); ++it) {
        QPluginLoader *plugin = *it;
#endif
        ApplicationPluginInterface *iface =
                qobject_cast<ApplicationPluginInterface *>(plugin->instance());
        if (iface) {
            iface->populateContext(context);
            injected.append(iface);
        } else {
            acWarning() << plugin->errorString();
            Q_ASSERT(iface);
        }
    }
#if (QT_VERSION >= QT_VERSION_CHECK(5, 7, 0))
    for (ApplicationPluginInterface *iface : qAsConst(injected)) {
#else
    for (auto it = injected.constBegin(); it != injected.constEnd(); ++it) {
        ApplicationPluginInterface *iface = *it;
#endif
        iface->resolveDependencies(context);
    }
}

void ApplicationPluginManager::inject(GreenHouse::Context *context,
                                      const QList<int> &interfaceIdList)
{
    QList<ApplicationPluginInterface *> injected;
#if (QT_VERSION >= QT_VERSION_CHECK(5, 7, 0))
    for (QPluginLoader *plugin : qAsConst(m_plugins)) {
#else
    for (auto it = m_plugins.constBegin(); it != m_plugins.constEnd(); ++it) {
        QPluginLoader *plugin = *it;
#endif
        ApplicationPluginInterface *iface =
                qobject_cast<ApplicationPluginInterface *>(plugin->instance());
        if (iface) {
            if (iface->populateContext(context, interfaceIdList) > 0)
                injected.append(iface);
        } else {
            acWarning() << plugin->errorString();
            Q_ASSERT(iface);
        }
    }
#if (QT_VERSION >= QT_VERSION_CHECK(5, 7, 0))
    for (ApplicationPluginInterface *iface : qAsConst(injected)) {
#else
    for (auto it = injected.constBegin(); it != injected.constEnd(); ++it) {
        ApplicationPluginInterface *iface = *it;
#endif
        iface->resolveDependencies(context);
    }
}
