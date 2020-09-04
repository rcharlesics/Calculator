#pragma once

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

#include <QObject>
#include <QCoreApplication>

#include <greenhousecontext.h>
#include <greenhousestates.h>

#include <Calculator/statemachinefactory.hpp>
#include <Calculator/remoteiteminterfaces.hpp>
#include <Calculator/surfacecontroller.hpp>
#include <Calculator/display.hpp>


using namespace testing;

class StateMachineFactory : public QObject, public Test
{
// Test interface
protected:
void SetUp();
void TearDown();

GreenHouse::Context *context = nullptr;
GreenHouse::RemoteUXInterfaceManager *interfaceManager = nullptr;
};

void StateMachineFactory::SetUp()
{
    context = new GreenHouse::Context();
    new GreenHouse::WebSocketRPCServer(context);
    interfaceManager = new GreenHouse::RemoteUXInterfaceManager(context);
    Calculator::initializeRemoteUXInterfaces(interfaceManager);
}

void StateMachineFactory::TearDown()
{
    if (context && context->contextStateMachine())
        context->contextStateMachine()->stop();
    delete interfaceManager;
    delete context;
}

TEST_F(StateMachineFactory, InitializedContextExecutionStart)
{
    context->store(new Calculator::SurfaceController);
    context->store(new Calculator::Display);

    Calculator::StateMachineFactory smf;
    context->startExecution(smf, this);
    ASSERT_NE(context->contextStateMachine(), nullptr);
}

TEST_F(StateMachineFactory, UninitializedContextExecutionStart)
{
    Calculator::StateMachineFactory smf;
    context->startExecution(smf, this);
    ASSERT_NE(context->contextStateMachine(), nullptr);
}

TEST_F(StateMachineFactory, StateMachineReady)
{
    Calculator::StateMachineFactory smf;
    context->startExecution(smf, this);
    ASSERT_NE(context->contextStateMachine(), nullptr);
    ASSERT_THAT(context->contextStateMachine()->ready(), Eq(false));
    qApp->processEvents();
    //The state machine shouldn't be ready after it's first started
    //we only declare it ready after the root state has entered and we got at least one clean loop pass
    ASSERT_THAT(context->contextStateMachine()->ready(), Eq(false));
    qApp->processEvents();
    ASSERT_THAT(context->contextStateMachine()->ready(), Eq(true));
}

TEST_F(StateMachineFactory, RemoteUXInterfaceAccess)
{
    Calculator::StateMachineFactory smf;
    context->startExecution(smf, this);
    auto interfaceManager = context->remoteUXInterfaceManager();
    ASSERT_EQ(interfaceManager->uxInterfaceCount(), 1);
ASSERT_NE(interfaceManager->uxInterface(QStringLiteral("MainView_MainViewIFace")), nullptr);


}

TEST_F(StateMachineFactory, StateAccess)
{
    Calculator::StateMachineFactory smf;
    context->startExecution(smf, this);
ASSERT_NE(context->stateForName(QStringLiteral("MainView")), nullptr);
ASSERT_NE(context->stateForName(QStringLiteral("MainViewHidden")), nullptr);
ASSERT_NE(context->stateForName(QStringLiteral("MainView_MainView")), nullptr);
ASSERT_NE(context->stateForName(QStringLiteral("MainView_ScreenState")), nullptr);
ASSERT_NE(context->stateForName(QStringLiteral("Menus")), nullptr);
ASSERT_NE(context->stateForName(QStringLiteral("NoMenu")), nullptr);
ASSERT_NE(context->stateForName(QStringLiteral("NoPopup")), nullptr);
ASSERT_NE(context->stateForName(QStringLiteral("Popups")), nullptr);
ASSERT_NE(context->stateForName(QStringLiteral("Root_State")), nullptr);
ASSERT_NE(context->stateForName(QStringLiteral("Screens")), nullptr);

}

TEST_F(StateMachineFactory, InitialStatesActive)
{
    Calculator::StateMachineFactory smf;
    context->startExecution(smf, this);
    qApp->processEvents();
ASSERT_THAT(context->stateForName(QStringLiteral("Root_State"))->active(), Eq(true));
ASSERT_THAT(context->stateForName(QStringLiteral("MainView"))->active(), Eq(true));
ASSERT_THAT(context->stateForName(QStringLiteral("MainViewHidden"))->active(), Eq(true));
ASSERT_THAT(context->stateForName(QStringLiteral("Screens"))->active(), Eq(true));
ASSERT_THAT(context->stateForName(QStringLiteral("MainView_ScreenState"))->active(), Eq(true));
ASSERT_THAT(context->stateForName(QStringLiteral("Menus"))->active(), Eq(true));
ASSERT_THAT(context->stateForName(QStringLiteral("NoMenu"))->active(), Eq(true));
ASSERT_THAT(context->stateForName(QStringLiteral("Popups"))->active(), Eq(true));
ASSERT_THAT(context->stateForName(QStringLiteral("NoPopup"))->active(), Eq(true));

}


