#ifndef APPLICATIONPLUGININTERFACE_H
#define APPLICATIONPLUGININTERFACE_H

#include "appcore_global.h"

#include <QObject>
#include <QList>

namespace GreenHouse {
class Context;
}

///
/// \brief The ApplicationPluginInterface class defines the interface for application plugins
///
class APPCORE_EXPORT ApplicationPluginInterface
{
public:
    ApplicationPluginInterface();
    virtual ~ApplicationPluginInterface();

    ///
    /// \brief populateContext used to allow a plugin to inject presenter/controller instances into
    /// the provided context
    ///  \param context the context instance for the plugin to inject to
    ///
    virtual void populateContext(GreenHouse::Context *context) = 0;

    ///
    /// \brief resolveDependencies invoked after the injection step is done in order to allow the
    /// plugin to resolve injected object dependencies
    /// \param context
    ///
    virtual void resolveDependencies(GreenHouse::Context *context);
};

#define ApplicationPluginInterface_iid "com.ics.greenhouse.ApplicationPluginInterface"

Q_DECLARE_INTERFACE(ApplicationPluginInterface, ApplicationPluginInterface_iid)

#endif // APPLICATIONPLUGININTERFACE_H
