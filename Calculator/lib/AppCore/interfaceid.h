#ifndef INTERFACEID_H
#define INTERFACEID_H

#include "appcore_global.h"
#include <Calculator/interfaceidrange.hpp>

/**
 * This is where we add an interface id for every interface we add to the application
 *  E.g. to get an Authentication interface we'd do:
 *  \code
 *  UserInterfaceIdRangeStart = Calculator::Id::IdRangeEnd + 1,
 *  Authentication
 *  \endcode
 *
 *  Then define the interface itself, e.g. in authenticationinterface.h
 * \code
 *  #pragma once
 *  #include <greenhousecontext.h>
 *  #include <interfaceid.h>
 *
 *  class AuthenticationInterface : public QObject, public
 * GreenHouse::ContextObjectAPI<InterfaceId::Authentication>
 *  {
 *      Q_OBJECT
 *  public:
 *      using QObject::QObject;
 *
 *  signals:
 *      void successful();
 *  };
 * \endcode
 *
 * Objects implementing the above interface can be stored and reatreaved from an context instnace as
 * follows \code AuthenticationInterface *auth = new MockAuthenticationInterface(parent);
 * context->store(auth);
 * ...
 * auto auth = getContextObject<AuthenticationInterface>();
 * \endcode
 */

namespace InterfaceId {
enum APPCORE_EXPORT Id { UserInterfaceIdRangeStart = Calculator::Id::IdRangeEnd };
}
#endif // INTERFACEID_H
