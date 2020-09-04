#include "applicationplugininterface.h"

ApplicationPluginInterface::ApplicationPluginInterface() = default;
ApplicationPluginInterface::~ApplicationPluginInterface() = default;

int ApplicationPluginInterface::populateContext(GreenHouse::Context *, const QList<int> &)
{
    return 0;
}

void ApplicationPluginInterface::resolveDependencies(GreenHouse::Context *) {}
