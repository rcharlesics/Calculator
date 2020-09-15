#ifndef MyBackendPlugin_H
#define MyBackendPlugin_H

#include <applicationplugininterface.h>

class MyBackendPlugin : public QObject, public ApplicationPluginInterface
{
    Q_OBJECT
    Q_DISABLE_COPY(MyBackendPlugin)
    Q_PLUGIN_METADATA(IID ApplicationPluginInterface_iid FILE "MyBackendPlugin.json")
    Q_INTERFACES(ApplicationPluginInterface)

public:
    explicit MyBackendPlugin(QObject *parent = nullptr);

    // ApplicationPluginInterface interface
public:
    void populateContext(GreenHouse::Context *context) override;
    void resolveDependencies(GreenHouse::Context *context) override;
};

#endif // MyBackendPlugin_H
