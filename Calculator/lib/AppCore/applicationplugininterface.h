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
    /// \brief populateContext used to allow a plugin to inject presenter/controller instances into
    /// the provided context based on a requested interface list
    /// \param context the context instance for the plugin to inject to
    /// \param interfaceIdList a list containing type ids of the required presenters/controllers
    /// \return the number of injected instances
    ///
    /// NOTE: This method should only inject objects if their type id can be found on the
    /// interfaceIdList
    ///
    virtual int populateContext(GreenHouse::Context *context, const QList<int> &interfaceIdList);

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
