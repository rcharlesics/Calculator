#ifndef APPLICATIONPLUGINMANAGER_H
#define APPLICATIONPLUGINMANAGER_H

#include "appcore_global.h"
#include <QObject>
#include <QList>

class QPluginLoader;
class ApplicationPluginInterface;

namespace GreenHouse {
class Context;
}

///
/// \brief The ApplicationPluginManager class is used to load and manage application plugins
///
class APPCORE_EXPORT ApplicationPluginManager : public QObject
{
    Q_OBJECT
    Q_DISABLE_COPY(ApplicationPluginManager)
public:
    ///
    /// \brief ApplicationPluginManager creates a new ApplicationPluginManager instance
    /// \param configFileName the path to the plugin configuration file
    /// \param pluginPath the path to the directory containing application plugins
    /// \param parent an optional parent for the new instance
    ///
    explicit ApplicationPluginManager(const QString &configFile, const QString &pluginPath,
                                      QObject *parent = nullptr);
    ~ApplicationPluginManager() override;

    ///
    /// \brief inject used to inject all presenters/controllers from the loaded plugins into the
    /// provided context
    /// \param context the context instance for the plugin to inject to
    ///
    void inject(GreenHouse::Context *context);

private:
    QList<QPluginLoader *> m_plugins;
};

#endif // APPLICATIONPLUGINMANAGER_H
