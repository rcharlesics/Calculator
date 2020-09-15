#pragma once

#include "testsignalsender.h"

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

#include <utility>

#include <greenhousecontext.h>
#include <greenhousestatemachine.h>
#include <greenhousestates.h>
#include <greenhousetransitions.h>

#include <QQmlApplicationEngine>
#include <QQuickItem>
#include <QCoreApplication>
#include <QTimer>

using namespace testing;

class TestStateMachineFactory : public GreenHouse::StateMachineFactory
{
public:
    TestStateMachineFactory(QString stateNamePrefix = QString())
      : m_stateNamePrefix(std::move(stateNamePrefix))
    {
    }

    GreenHouse::StateMachine *createStateMachine(GreenHouse::Context *context) const;

    QString stateNamePrefix() const { return m_stateNamePrefix; }

private:
    QString m_stateNamePrefix;
};

GreenHouse::StateMachine *
TestStateMachineFactory::createStateMachine(GreenHouse::Context *context) const
{
    GreenHouse::SignalTransition *sTr = nullptr;

    auto sm = new GreenHouse::StateMachine(context);
    auto initialState =
            new GreenHouse::State(m_stateNamePrefix + QStringLiteral("Initial"), sm->rootState());
    auto initialItemState =
            new GreenHouse::ItemState(m_stateNamePrefix + QStringLiteral("IntroState"),
                                      QStringLiteral("IntroLayoutImpl.qml"), initialState);
    initialState->setInitialState(initialItemState);
    sm->rootState()->setInitialState(initialState);
    auto secondaryState = new GreenHouse::LayerState(
            m_stateNamePrefix + QStringLiteral("Secondary"), 0, sm->rootState());
    auto secondaryItemState =
            new GreenHouse::ItemState(m_stateNamePrefix + QStringLiteral("HomeState"),
                                      QStringLiteral("HomeLayoutImpl.qml"), secondaryState);
    auto secondaryConditionalState = new GreenHouse::ConditionalState(
            m_stateNamePrefix + QStringLiteral("ConditionalState"), secondaryState);
    secondaryConditionalState->addConditionFunction(
            [secondaryItemState](GreenHouse::Context *, const QVariantList &) -> QString {
                return secondaryItemState->name();
            });
    secondaryState->setInitialState(secondaryConditionalState);

    // Automatically jump out of the initial state when the sm is ready
    sTr = new GreenHouse::SignalTransition(sm, QStringLiteral("readyChanged"), initialState);
    sTr->setTargetState(secondaryState);

    // Initial to secondary signal transition
    // cppcheck-suppress memleak
    sTr = new GreenHouse::SignalTransition(context->get<TestSignalSender>(),
                                           QStringLiteral("testSignal"), initialState);
    sTr->setTargetState(secondaryState);

    // Root state back transition
    sTr = new GreenHouse::SignalTransition(context->get<TestSignalSender>(),
                                           QStringLiteral("testSignal2"), sm->rootState());
    sTr->setBackTransition(true);
    // cppcheck-suppress memleak
    return sm;
}

class StateMachine : public Test
{
    // Test interface
protected:
    void SetUp();
    void TearDown();

    QQmlApplicationEngine *qmlEngine = nullptr;
    GreenHouse::Context *context = nullptr;
    TestSignalSender *testSignalSender;
};

void StateMachine::SetUp()
{
    qmlEngine = new QQmlApplicationEngine;
    qmlEngine->load(QUrl(QStringLiteral("qrc:/test-main.qml")));
    QQuickItem *rootItem = qmlEngine->rootObjects().isEmpty()
            ? nullptr
            : qobject_cast<QQuickItem *>(qmlEngine->rootObjects().first());
    context = new GreenHouse::Context(qmlEngine, QStringLiteral("ValidationFlow"), rootItem);
    testSignalSender = new TestSignalSender;
    context->store(testSignalSender);
    TestStateMachineFactory factory;
    context->setLayoutPrefix(QStringLiteral("qrc:/layouts/primary/"));
    context->startExecution(factory, qmlEngine);
}

void StateMachine::TearDown()
{
    if (context && context->contextStateMachine())
        context->contextStateMachine()->stop();
    delete context;
    delete qmlEngine;
}

TEST_F(StateMachine, StateMachinePresent)
{
    ASSERT_NE(context->contextStateMachine(), nullptr);
}

TEST_F(StateMachine, ContextCorrect)
{
    ASSERT_EQ(context->contextStateMachine()->context(), context);
}

TEST_F(StateMachine, RootStatePresent)
{
    ASSERT_NE(context->contextStateMachine()->rootState(), nullptr);
}

TEST_F(StateMachine, RootStateAccessibleByName)
{
    ASSERT_EQ(context->contextStateMachine()->rootState(),
              context->stateForName(context->contextStateMachine()->rootState()->name()));
}

TEST_F(StateMachine, InitialStateAccessibleByName)
{
    ASSERT_TRUE(context->stateForName(QStringLiteral("Initial")) != nullptr);
}

TEST_F(StateMachine, SecondaryStateAccessibleByName)
{
    ASSERT_TRUE(context->stateForName(QStringLiteral("Secondary")) != nullptr);
}

TEST_F(StateMachine, UnknownStateIsNull)
{
    ASSERT_TRUE(context->stateForName(QStringLiteral("FooBar")) == nullptr);
}

TEST_F(StateMachine, BackTransitionSetup)
{
    {
        auto tr = new GreenHouse::SignalTransition(context->get<TestSignalSender>(),
                                                   QStringLiteral("testSignal2"),
                                                   context->contextStateMachine()->rootState());
        tr->setTargetState(context->stateForName(QStringLiteral("Initial")));
        ASSERT_NE(tr->targetState(), nullptr);
        ASSERT_FALSE(tr->backTransition());

        tr->setBackTransition(true);
        ASSERT_EQ(tr->transitionType(), QAbstractTransition::InternalTransition);
        ASSERT_EQ(tr->targetState(), nullptr);
        ASSERT_TRUE(tr->backTransition());
    }
    {
        auto tr = new GreenHouse::SignalTransition(context->get<TestSignalSender>(),
                                                   QStringLiteral("testSignal"),
                                                   context->contextStateMachine()->rootState());
        tr->setTargetState(context->stateForName(QStringLiteral("Initial")));
        ASSERT_NE(tr->targetState(), nullptr);
        ASSERT_FALSE(tr->backTransition());

        tr->setBackTransition(true);
        ASSERT_EQ(tr->transitionType(), QAbstractTransition::InternalTransition);
        ASSERT_EQ(tr->targetState(), nullptr);
        ASSERT_TRUE(tr->backTransition());
    }
}

TEST_F(StateMachine, ParallelTriggeringSetup)
{
    {
        auto tr = new GreenHouse::SignalTransition(context->get<TestSignalSender>(),
                                                   QStringLiteral("testSignal2"),
                                                   context->contextStateMachine()->rootState());
        ASSERT_TRUE(tr->parallelTriggeringAllowed());

        tr->setParallelTriggeringAllowed(false);
        ASSERT_FALSE(tr->parallelTriggeringAllowed());
    }
    {
        auto tr = new GreenHouse::SignalTransition(context->get<TestSignalSender>(),
                                                   QStringLiteral("testSignal"),
                                                   context->contextStateMachine()->rootState());
        ASSERT_TRUE(tr->parallelTriggeringAllowed());

        tr->setParallelTriggeringAllowed(false);
        ASSERT_FALSE(tr->parallelTriggeringAllowed());
    }
}

TEST_F(StateMachine, BlockedIfTargetActiveSetup)
{
    {
        auto tr = new GreenHouse::SignalTransition(context->get<TestSignalSender>(),
                                                   QStringLiteral("testSignal2"),
                                                   context->contextStateMachine()->rootState());
        ASSERT_FALSE(tr->blockedIfTargetActive());

        tr->setBlockedIfTargetActive(true);
        ASSERT_TRUE(tr->blockedIfTargetActive());
    }
    {
        auto tr = new GreenHouse::SignalTransition(context->get<TestSignalSender>(),
                                                   QStringLiteral("testSignal"),
                                                   context->contextStateMachine()->rootState());
        ASSERT_FALSE(tr->blockedIfTargetActive());

        tr->setBlockedIfTargetActive(true);
        ASSERT_TRUE(tr->blockedIfTargetActive());
    }
}

TEST_F(StateMachine, TransitionTargetStup)
{
    {
        auto tr = new GreenHouse::SignalTransition(context->get<TestSignalSender>(),
                                                   QStringLiteral("testSignal2"),
                                                   context->contextStateMachine()->rootState());
        ASSERT_EQ(tr->targetState(), nullptr);

        tr->setTargetState(context->stateForName(QStringLiteral("Initial")));
        ASSERT_TRUE(tr->targetState() == context->stateForName(QStringLiteral("Initial")));

        tr->setTargetState(QStringLiteral("Secondary"));
        ASSERT_TRUE(tr->targetState() == context->stateForName(QStringLiteral("Secondary")));
    }
    {
        auto tr = new GreenHouse::SignalTransition(context->get<TestSignalSender>(),
                                                   QStringLiteral("testSignal"),
                                                   context->contextStateMachine()->rootState());
        ASSERT_EQ(tr->targetState(), nullptr);

        tr->setTargetState(context->stateForName(QStringLiteral("Initial")));
        ASSERT_TRUE(tr->targetState() == context->stateForName(QStringLiteral("Initial")));

        tr->setTargetState(QStringLiteral("Secondary"));
        ASSERT_TRUE(tr->targetState() == context->stateForName(QStringLiteral("Secondary")));
    }
}

TEST_F(StateMachine, TransitionStateMachineLevelVerification)
{
    {
        auto tr = new GreenHouse::SignalTransition(context->get<TestSignalSender>(),
                                                   QStringLiteral("testSignal2"),
                                                   context->contextStateMachine()->rootState());
        ASSERT_EQ(tr->stateMachineLevel(), 1);
    }
    {
        auto tr = new GreenHouse::SignalTransition(
                context->get<TestSignalSender>(), QStringLiteral("testSignal2"),
                context->stateForName(QStringLiteral("Initial")));
        ASSERT_EQ(tr->stateMachineLevel(), 2);
    }
    {
        auto tr = new GreenHouse::SignalTransition(
                context->get<TestSignalSender>(), QStringLiteral("testSignal2"),
                context->stateForName(QStringLiteral("Secondary")));
        ASSERT_EQ(tr->stateMachineLevel(), 2);
    }
    {
        auto tr = new GreenHouse::SignalTransition(
                context->get<TestSignalSender>(), QStringLiteral("testSignal2"),
                context->stateForName(QStringLiteral("HomeState")));
        ASSERT_EQ(tr->stateMachineLevel(), 3);
    }
    {
        auto tr = new GreenHouse::SignalTransition(
                context->get<TestSignalSender>(), QStringLiteral("testSignal2"),
                context->stateForName(QStringLiteral("ConditionalState")));
        ASSERT_EQ(tr->stateMachineLevel(), 3);
    }
    {
        auto tr = new GreenHouse::SignalTransition(context->get<TestSignalSender>(),
                                                   QStringLiteral("testSignal"),
                                                   context->contextStateMachine()->rootState());
        ASSERT_EQ(tr->stateMachineLevel(), 1);
    }
    {
        auto tr = new GreenHouse::SignalTransition(
                context->get<TestSignalSender>(), QStringLiteral("testSignal"),
                context->stateForName(QStringLiteral("Initial")));
        ASSERT_EQ(tr->stateMachineLevel(), 2);
    }
    {
        auto tr = new GreenHouse::SignalTransition(
                context->get<TestSignalSender>(), QStringLiteral("testSignal"),
                context->stateForName(QStringLiteral("Secondary")));
        ASSERT_EQ(tr->stateMachineLevel(), 2);
    }
    {
        auto tr = new GreenHouse::SignalTransition(
                context->get<TestSignalSender>(), QStringLiteral("testSignal"),
                context->stateForName(QStringLiteral("HomeState")));
        ASSERT_EQ(tr->stateMachineLevel(), 3);
    }
    {
        auto tr = new GreenHouse::SignalTransition(
                context->get<TestSignalSender>(), QStringLiteral("testSignal"),
                context->stateForName(QStringLiteral("ConditionalState")));
        ASSERT_EQ(tr->stateMachineLevel(), 3);
    }
}

TEST_F(StateMachine, StateTypesCorrect)
{
    auto initialState = context->stateForName(QStringLiteral("Initial"));
    ASSERT_NE(initialState, nullptr);
    ASSERT_EQ(initialState->stateType(), GreenHouse::State::Generic);

    auto introState = context->stateForName(QStringLiteral("IntroState"));
    ASSERT_NE(introState, nullptr);
    ASSERT_EQ(introState->stateType(), GreenHouse::State::Item);

    auto secondaryState = context->stateForName(QStringLiteral("Secondary"));
    ASSERT_NE(secondaryState, nullptr);
    ASSERT_EQ(secondaryState->stateType(), GreenHouse::State::Layer);

    auto homeState = context->stateForName(QStringLiteral("HomeState"));
    ASSERT_NE(homeState, nullptr);
    ASSERT_EQ(homeState->stateType(), GreenHouse::State::Item);

    auto secondaryConditionalState = context->stateForName(QStringLiteral("ConditionalState"));
    ASSERT_NE(secondaryConditionalState, nullptr);
    ASSERT_EQ(secondaryConditionalState->stateType(), GreenHouse::State::Conditional);
}

TEST_F(StateMachine, StateMachineRunning)
{
    ASSERT_THAT(context->contextStateMachine()->isRunning(), Eq(false));
    qApp->processEvents();
    ASSERT_THAT(context->contextStateMachine()->isRunning(), Eq(true));
}

TEST_F(StateMachine, StateMachineReady)
{
    ASSERT_THAT(context->contextStateMachine()->ready(), Eq(false));
    qApp->processEvents();
    // The state machine shouldn't be ready after it's first started
    // we only declare it ready after the root state has entered and we got at least one clean loop
    // pass
    ASSERT_THAT(context->contextStateMachine()->ready(), Eq(false));
    qApp->processEvents();
    ASSERT_THAT(context->contextStateMachine()->ready(), Eq(true));
}

TEST_F(StateMachine, StateMachineSwap)
{
    TestStateMachineFactory factory(QStringLiteral("Alt"));
    context->startExecution(factory, qmlEngine);
    ASSERT_THAT(context->contextStateMachine()->ready(), Eq(false));
    ASSERT_FALSE(context->contextStateMachine()->rootState()->precreateUiOnEntry());
    qApp->processEvents();
    auto introState = qobject_cast<GreenHouse::ItemState *>(
            context->stateForName(factory.stateNamePrefix() + QStringLiteral("IntroState")));
    ASSERT_NE(introState, nullptr);
    ASSERT_NE(introState->item(), nullptr);
    auto homeState = qobject_cast<GreenHouse::ItemState *>(
            context->stateForName(factory.stateNamePrefix() + QStringLiteral("HomeState")));
    ASSERT_NE(homeState, nullptr);
    ASSERT_EQ(homeState->item(), nullptr);

    // The state machine shouldn't be ready after it's first started
    // we only declare it ready after the root state has entered and we got at least one clean loop
    // pass
    ASSERT_THAT(context->contextStateMachine()->ready(), Eq(false));
    qApp->processEvents();
    ASSERT_THAT(context->contextStateMachine()->ready(), Eq(true));
}

TEST_F(StateMachine, StateMachineSwapWithUiPrecreation)
{
    TestStateMachineFactory factory(QStringLiteral("Alt"));
    context->startExecution(factory, qmlEngine, true);
    ASSERT_THAT(context->contextStateMachine()->ready(), Eq(false));
    ASSERT_TRUE(context->contextStateMachine()->rootState()->precreateUiOnEntry());
    qApp->processEvents();
    auto introState = qobject_cast<GreenHouse::ItemState *>(
            context->stateForName(factory.stateNamePrefix() + QStringLiteral("IntroState")));
    ASSERT_NE(introState, nullptr);
    ASSERT_NE(introState->item(), nullptr);
    auto homeState = qobject_cast<GreenHouse::ItemState *>(
            context->stateForName(factory.stateNamePrefix() + QStringLiteral("HomeState")));
    ASSERT_NE(homeState, nullptr);
    ASSERT_NE(homeState->item(), nullptr);

    // We the state machine shouldn't be ready after it's first started
    // we only declare it ready after the root state has entered and we got atleast one clean loop
    // pass
    ASSERT_THAT(context->contextStateMachine()->ready(), Eq(false));
    qApp->processEvents();
    ASSERT_THAT(context->contextStateMachine()->ready(), Eq(true));
}

TEST_F(StateMachine, RootStateActive)
{
    ASSERT_THAT(context->contextStateMachine()->rootState()->active(), Eq(false));
    qApp->processEvents();
    ASSERT_THAT(context->contextStateMachine()->rootState()->active(), Eq(true));
}

TEST_F(StateMachine, RootStateEntryAction)
{
    bool entryTriggered = false;
    auto entryAction = [&entryTriggered](GreenHouse::Context *, const QVariantList &) -> void {
        entryTriggered = true;
    };
    context->contextStateMachine()->rootState()->addEntryFunction(entryAction);
    ASSERT_THAT(context->contextStateMachine()->rootState()->active(), Eq(false));
    ASSERT_THAT(entryTriggered, Eq(false));
    qApp->processEvents();
    // The root state is active but the entry action shouldn't be triggered yet
    // as because we need the let the state machine settle after it was started.
    ASSERT_THAT(context->contextStateMachine()->rootState()->active(), Eq(true));
    ASSERT_THAT(entryTriggered, Eq(false));
    qApp->processEvents();
    ASSERT_THAT(context->contextStateMachine()->rootState()->active(), Eq(true));
    ASSERT_THAT(entryTriggered, Eq(true));
}

TEST_F(StateMachine, InitialStateEntryAction)
{
    bool entryTriggered = false;
    GreenHouse::State *initial = context->stateForName(QStringLiteral("Initial"));
    auto entryAction = [&entryTriggered](GreenHouse::Context *, const QVariantList &) -> void {
        entryTriggered = true;
    };
    initial->addEntryFunction(entryAction);
    ASSERT_THAT(entryTriggered, Eq(false));
    ASSERT_THAT(initial->active(), Eq(false));
    qApp->processEvents();
    // The initial state is active but the entry action shouldn't be triggered yet
    // as because we need the let the state machine settle after it was started.
    ASSERT_THAT(initial->active(), Eq(true));
    ASSERT_THAT(entryTriggered, Eq(false));
    ASSERT_EQ(
            context->contextStateMachine()->rootState()->activeChildName().compare(initial->name()),
            0);
    qApp->processEvents();
    ASSERT_THAT(initial->active(), Eq(false));
    ASSERT_THAT(entryTriggered, Eq(true));
}

TEST_F(StateMachine, InitialStateExitAction)
{
    bool exitTriggered = false;
    GreenHouse::State *initial = context->stateForName(QStringLiteral("Initial"));
    auto exitAction = [&exitTriggered](GreenHouse::Context *, const QVariantList &) -> void {
        exitTriggered = true;
    };
    initial->addExitFunction(exitAction);
    ASSERT_THAT(exitTriggered, Eq(false));
    ASSERT_THAT(initial->active(), Eq(false));
    qApp->processEvents();
    ASSERT_THAT(initial->active(), Eq(true));
    qApp->processEvents();
    ASSERT_THAT(initial->active(), Eq(false));
    ASSERT_THAT(exitTriggered, Eq(true));
}

TEST_F(StateMachine, SecondaryStateActive)
{
    GreenHouse::State *secondary = context->stateForName(QStringLiteral("Secondary"));
    ASSERT_THAT(secondary->active(), Eq(false));
    qApp->processEvents();
    ASSERT_THAT(secondary->active(), Eq(false));
    qApp->processEvents();
    ASSERT_THAT(secondary->active(), Eq(true));
}

TEST_F(StateMachine, StateEntryActionContextMatched)
{
    bool contextMatched = false;
    GreenHouse::State *initial = context->stateForName(QStringLiteral("Initial"));
    auto entryAction = [&contextMatched, this](GreenHouse::Context *ctx,
                                               const QVariantList &) -> void {
        contextMatched = context == ctx;
    };
    initial->addEntryFunction(entryAction);
    qApp->processEvents();
    qApp->processEvents();
    ASSERT_THAT(contextMatched, Eq(true));
}

TEST_F(StateMachine, StateExitActionContextMatched)
{
    bool contextMatched = false;
    GreenHouse::State *initial = context->stateForName(QStringLiteral("Initial"));
    auto exitAction = [&contextMatched, this](GreenHouse::Context *ctx,
                                              const QVariantList &) -> void {
        contextMatched = context == ctx;
    };
    initial->addExitFunction(exitAction);
    qApp->processEvents();
    qApp->processEvents();
    ASSERT_THAT(contextMatched, Eq(true));
}

TEST_F(StateMachine, ActiveTransitionReporting)
{
    // No transitions active
    ASSERT_THAT(context->activeTransitions(QStringLiteral("GreenHouse::SignalTransition")).length(),
                Eq(0));
    qApp->processEvents();
    // We should be in the intial state
    ASSERT_THAT(context->activeTransitions(QStringLiteral("GreenHouse::SignalTransition")).length(),
                Eq(3));
    qApp->processEvents();
    // We should be in the secondary state
    ASSERT_THAT(context->activeTransitions(QStringLiteral("GreenHouse::SignalTransition")).length(),
                Eq(1));

    // Triggering the back transition, we should get back to the initial state
    context->get<TestSignalSender>()->testSignal2();
    qApp->processEvents();
    ASSERT_THAT(context->activeTransitions(QStringLiteral("GreenHouse::SignalTransition")).length(),
                Eq(3));

    // Triggering test signal transition, we should get into the secondary state
    emit testSignalSender->testSignal();
    qApp->processEvents();
    ASSERT_THAT(context->activeTransitions(QStringLiteral("GreenHouse::SignalTransition")).length(),
                Eq(1));
}

TEST_F(StateMachine, BackTransition)
{
    GreenHouse::State *initial = context->stateForName(QStringLiteral("Initial"));
    GreenHouse::State *secondary = context->stateForName(QStringLiteral("Secondary"));
    // State machine not ready yet
    ASSERT_THAT(initial->active(), Eq(false));
    ASSERT_THAT(secondary->active(), Eq(false));
    qApp->processEvents();

    // We should be in the intial state
    ASSERT_THAT(initial->active(), Eq(true));
    ASSERT_THAT(secondary->active(), Eq(false));
    qApp->processEvents();

    // We should be in the secondary state
    ASSERT_THAT(initial->active(), Eq(false));
    ASSERT_THAT(secondary->active(), Eq(true));

    // Triggering the back transition, we should get back to the initial state
    context->get<TestSignalSender>()->testSignal2();
    qApp->processEvents();
    ASSERT_THAT(initial->active(), Eq(true));
    ASSERT_THAT(secondary->active(), Eq(false));

    // Triggering the back transition again, we should not change states as there should be no back
    // target
    context->get<TestSignalSender>()->testSignal2();
    qApp->processEvents();
    ASSERT_THAT(initial->active(), Eq(true));
    ASSERT_THAT(secondary->active(), Eq(false));
}

TEST_F(StateMachine, HasUI)
{
    auto home = qobject_cast<GreenHouse::ItemState *>(
            context->stateForName(QStringLiteral("HomeState")));
    ASSERT_THAT(home->active(), Eq(false));
    qApp->processEvents();
    ASSERT_THAT(home->active(), Eq(false));
    qApp->processEvents();
    ASSERT_THAT(home->active(), Eq(true));
    ASSERT_NE(context->contextRootItem(), nullptr);
    ASSERT_NE(home->item(), nullptr);
}

TEST_F(StateMachine, RemoveUI)
{
    auto home = qobject_cast<GreenHouse::ItemState *>(
            context->stateForName(QStringLiteral("HomeState")));
    ASSERT_THAT(home->active(), Eq(false));
    qApp->processEvents();
    ASSERT_THAT(home->active(), Eq(false));
    qApp->processEvents();
    ASSERT_THAT(home->active(), Eq(true));
    context->removeUi();
    ASSERT_EQ(context->contextRootItem(), nullptr);
    ASSERT_EQ(home->item(), nullptr);
}

TEST_F(StateMachine, ChangeLayoutPrefix)
{
    auto home = qobject_cast<GreenHouse::ItemState *>(
            context->stateForName(QStringLiteral("HomeState")));
    ASSERT_THAT(home->active(), Eq(false));
    qApp->processEvents();
    ASSERT_THAT(home->active(), Eq(false));
    qApp->processEvents();
    ASSERT_THAT(home->active(), Eq(true));
    context->setLayoutPrefix(QStringLiteral("qrc:/layouts/secondary/"));
    ASSERT_TRUE(context->layoutPrefix().compare(QStringLiteral("qrc:/layouts/secondary/")) == 0);
    ASSERT_NE(context->contextRootItem(), nullptr);
    ASSERT_NE(home->item(), nullptr);
}

TEST_F(StateMachine, TrimUi)
{
    auto intro = qobject_cast<GreenHouse::ItemState *>(
            context->stateForName(QStringLiteral("IntroState")));
    auto home = qobject_cast<GreenHouse::ItemState *>(
            context->stateForName(QStringLiteral("HomeState")));
    ASSERT_THAT(intro->active(), Eq(false));
    ASSERT_THAT(home->active(), Eq(false));
    qApp->processEvents();
    ASSERT_THAT(intro->active(), Eq(true));
    ASSERT_THAT(home->active(), Eq(false));
    qApp->processEvents();
    ASSERT_THAT(intro->active(), Eq(false));
    ASSERT_THAT(home->active(), Eq(true));
    ASSERT_NE(context->contextRootItem(), nullptr);
    ASSERT_NE(intro->item(), nullptr);
    ASSERT_NE(home->item(), nullptr);
    context->contextStateMachine()->trimUi();
    ASSERT_EQ(intro->item(), nullptr);
    ASSERT_NE(home->item(), nullptr);
}

TEST_F(StateMachine, PreloadUI)
{
    context->contextStateMachine()->rootState()->setPrecreateUiOnEntry(true);
    auto intro = qobject_cast<GreenHouse::ItemState *>(
            context->stateForName(QStringLiteral("IntroState")));
    auto home = qobject_cast<GreenHouse::ItemState *>(
            context->stateForName(QStringLiteral("HomeState")));
    ASSERT_THAT(intro->active(), Eq(false));
    ASSERT_THAT(home->active(), Eq(false));
    qApp->processEvents();
    ASSERT_THAT(intro->active(), Eq(true));
    ASSERT_THAT(home->active(), Eq(false));
    ASSERT_NE(context->contextRootItem(), nullptr);
    ASSERT_NE(intro->item(), nullptr);
    ASSERT_NE(home->item(), nullptr);
}

TEST_F(StateMachine, ItemPropertyChangedTransitionNonExistingProperty)
{
    auto home = qobject_cast<GreenHouse::ItemState *>(
            context->stateForName(QStringLiteral("HomeState")));
    ASSERT_NE(home, nullptr);
    auto tr = new GreenHouse::ItemPropertyChangedTransition(
            QStringLiteral("NON_EXISTING_PROPERTY"),
            GreenHouse::ItemPropertyChangedTransition::AnyChange, QVariant(), home);
    tr->addTriggeredFunction([](GreenHouse::Context *, const QVariantList &) -> void {
        qApp->exit(1);
        FAIL() << "Non existing item property transitions should not be triggered.";
    });
    QTimer::singleShot(1000, tr, []() -> void { qApp->exit(0); });
    qApp->exec();
}

TEST_F(StateMachine, ItemPropertyChangedTransitionTriggerAnyChange)
{
    auto home = qobject_cast<GreenHouse::ItemState *>(
            context->stateForName(QStringLiteral("HomeState")));
    ASSERT_NE(home, nullptr);
    auto tr = new GreenHouse::ItemPropertyChangedTransition(
            QStringLiteral("activationCounter"),
            GreenHouse::ItemPropertyChangedTransition::AnyChange, QVariant(), home);
    tr->addTriggeredFunction([this](GreenHouse::Context *ctx, const QVariantList &) -> void {
        qApp->exit(0);
        ASSERT_EQ(context, ctx);
    });
    qApp->exec();
}

TEST_F(StateMachine, ItemPropertyChangedTransitionTriggerEqual)
{
    auto home = qobject_cast<GreenHouse::ItemState *>(
            context->stateForName(QStringLiteral("HomeState")));
    ASSERT_NE(home, nullptr);
    auto tr = new GreenHouse::ItemPropertyChangedTransition(
            QStringLiteral("activationCounter"), GreenHouse::ItemPropertyChangedTransition::Equal,
            1, home);
    tr->addTriggeredFunction([this](GreenHouse::Context *ctx, const QVariantList &) -> void {
        qApp->exit(0);
        ASSERT_EQ(context, ctx);
    });
    qApp->exec();
}

TEST_F(StateMachine, ItemPropertyChangedTransitionTriggerNotEqual)
{
    auto home = qobject_cast<GreenHouse::ItemState *>(
            context->stateForName(QStringLiteral("HomeState")));
    ASSERT_NE(home, nullptr);
    auto tr = new GreenHouse::ItemPropertyChangedTransition(
            QStringLiteral("activationCounter"),
            GreenHouse::ItemPropertyChangedTransition::NotEqual, 0, home);
    tr->addTriggeredFunction([this](GreenHouse::Context *ctx, const QVariantList &) -> void {
        qApp->exit(0);
        ASSERT_EQ(context, ctx);
    });
    qApp->exec();
}

TEST_F(StateMachine, ItemPropertyChangedTransitionTriggerGreaterThan)
{
    auto home = qobject_cast<GreenHouse::ItemState *>(
            context->stateForName(QStringLiteral("HomeState")));
    ASSERT_NE(home, nullptr);
    auto tr = new GreenHouse::ItemPropertyChangedTransition(
            QStringLiteral("activationCounter"),
            GreenHouse::ItemPropertyChangedTransition::GreaterThan, 0, home);
    tr->addTriggeredFunction([this](GreenHouse::Context *ctx, const QVariantList &) -> void {
        qApp->exit(0);
        ASSERT_EQ(context, ctx);
    });
    qApp->exec();
}

TEST_F(StateMachine, ItemPropertyChangedTransitionTriggerLessThan)
{
    auto home = qobject_cast<GreenHouse::ItemState *>(
            context->stateForName(QStringLiteral("HomeState")));
    ASSERT_NE(home, nullptr);
    auto tr = new GreenHouse::ItemPropertyChangedTransition(
            QStringLiteral("activationCounter"),
            GreenHouse::ItemPropertyChangedTransition::LessThan, 2, home);
    tr->addTriggeredFunction([this](GreenHouse::Context *ctx, const QVariantList &) -> void {
        qApp->exit(0);
        ASSERT_EQ(context, ctx);
    });
    qApp->exec();
}

TEST_F(StateMachine, ItemPropertyChangedTransitionTriggerGreaterThanOrEqual)
{
    auto home = qobject_cast<GreenHouse::ItemState *>(
            context->stateForName(QStringLiteral("HomeState")));
    ASSERT_NE(home, nullptr);
    auto tr = new GreenHouse::ItemPropertyChangedTransition(
            QStringLiteral("activationCounter"),
            GreenHouse::ItemPropertyChangedTransition::GreaterThanOrEqual, 1, home);
    tr->addTriggeredFunction([this](GreenHouse::Context *ctx, const QVariantList &) -> void {
        qApp->exit(0);
        ASSERT_EQ(context, ctx);
    });
    qApp->exec();
}

TEST_F(StateMachine, ItemPropertyChangedTransitionTriggerLessThanOrEqual)
{
    auto home = qobject_cast<GreenHouse::ItemState *>(
            context->stateForName(QStringLiteral("HomeState")));
    ASSERT_NE(home, nullptr);
    auto tr = new GreenHouse::ItemPropertyChangedTransition(
            QStringLiteral("activationCounter"),
            GreenHouse::ItemPropertyChangedTransition::LessThanOrEqual, 1, home);
    tr->addTriggeredFunction([this](GreenHouse::Context *ctx, const QVariantList &) -> void {
        qApp->exit(0);
        ASSERT_EQ(context, ctx);
    });
    qApp->exec();
}

TEST_F(StateMachine, ItemSignalTransitionTrigger)
{
    auto home = qobject_cast<GreenHouse::ItemState *>(
            context->stateForName(QStringLiteral("HomeState")));
    ASSERT_NE(home, nullptr);
    auto tr = new GreenHouse::ItemSignalTransition(QStringLiteral("homeViewActivated"), home);
    tr->addTriggeredFunction([this](GreenHouse::Context *ctx, const QVariantList &) -> void {
        qApp->exit(0);
        ASSERT_EQ(context, ctx);
    });
    qApp->exec();
}

TEST_F(StateMachine, ItemPropertyChangedTransitionTriggerEqualReal)
{
    auto home = qobject_cast<GreenHouse::ItemState *>(
            context->stateForName(QStringLiteral("HomeState")));
    ASSERT_NE(home, nullptr);
    auto tr = new GreenHouse::ItemPropertyChangedTransition(
            QStringLiteral("activationCounterReal"),
            GreenHouse::ItemPropertyChangedTransition::Equal, 1.0f, home);
    tr->addTriggeredFunction([this](GreenHouse::Context *ctx, const QVariantList &) -> void {
        qApp->exit(0);
        ASSERT_EQ(context, ctx);
    });
    qApp->exec();
}

TEST_F(StateMachine, ItemPropertyChangedTransitionTriggerNotEqualReal)
{
    auto home = qobject_cast<GreenHouse::ItemState *>(
            context->stateForName(QStringLiteral("HomeState")));
    ASSERT_NE(home, nullptr);
    auto tr = new GreenHouse::ItemPropertyChangedTransition(
            QStringLiteral("activationCounterReal"),
            GreenHouse::ItemPropertyChangedTransition::NotEqual, 0.0f, home);
    tr->addTriggeredFunction([this](GreenHouse::Context *ctx, const QVariantList &) -> void {
        qApp->exit(0);
        ASSERT_EQ(context, ctx);
    });
    qApp->exec();
}

TEST_F(StateMachine, ItemPropertyChangedTransitionTriggerGreaterThanReal)
{
    auto home = qobject_cast<GreenHouse::ItemState *>(
            context->stateForName(QStringLiteral("HomeState")));
    ASSERT_NE(home, nullptr);
    auto tr = new GreenHouse::ItemPropertyChangedTransition(
            QStringLiteral("activationCounterReal"),
            GreenHouse::ItemPropertyChangedTransition::GreaterThan, 0.0f, home);
    tr->addTriggeredFunction([this](GreenHouse::Context *ctx, const QVariantList &) -> void {
        qApp->exit(0);
        ASSERT_EQ(context, ctx);
    });
    qApp->exec();
}

TEST_F(StateMachine, ItemPropertyChangedTransitionTriggerLessThanReal)
{
    auto home = qobject_cast<GreenHouse::ItemState *>(
            context->stateForName(QStringLiteral("HomeState")));
    ASSERT_NE(home, nullptr);
    auto tr = new GreenHouse::ItemPropertyChangedTransition(
            QStringLiteral("activationCounterReal"),
            GreenHouse::ItemPropertyChangedTransition::LessThan, 2.0f, home);
    tr->addTriggeredFunction([this](GreenHouse::Context *ctx, const QVariantList &) -> void {
        qApp->exit(0);
        ASSERT_EQ(context, ctx);
    });
    qApp->exec();
}

TEST_F(StateMachine, ItemPropertyChangedTransitionTriggerGreaterThanOrEqualReal)
{
    auto home = qobject_cast<GreenHouse::ItemState *>(
            context->stateForName(QStringLiteral("HomeState")));
    ASSERT_NE(home, nullptr);
    auto tr = new GreenHouse::ItemPropertyChangedTransition(
            QStringLiteral("activationCounterReal"),
            GreenHouse::ItemPropertyChangedTransition::GreaterThanOrEqual, 1.0f, home);
    tr->addTriggeredFunction([this](GreenHouse::Context *ctx, const QVariantList &) -> void {
        qApp->exit(0);
        ASSERT_EQ(context, ctx);
    });
    qApp->exec();
}

TEST_F(StateMachine, ItemPropertyChangedTransitionTriggerLessThanOrEqualReal)
{
    auto home = qobject_cast<GreenHouse::ItemState *>(
            context->stateForName(QStringLiteral("HomeState")));
    ASSERT_NE(home, nullptr);
    auto tr = new GreenHouse::ItemPropertyChangedTransition(
            QStringLiteral("activationCounterReal"),
            GreenHouse::ItemPropertyChangedTransition::LessThanOrEqual, 1.0f, home);
    tr->addTriggeredFunction([this](GreenHouse::Context *ctx, const QVariantList &) -> void {
        qApp->exit(0);
        ASSERT_EQ(context, ctx);
    });
    qApp->exec();
}

TEST_F(StateMachine, ItemPropertyChangedTransitionTriggerEqualDouble)
{
    auto home = qobject_cast<GreenHouse::ItemState *>(
            context->stateForName(QStringLiteral("HomeState")));
    ASSERT_NE(home, nullptr);
    auto tr = new GreenHouse::ItemPropertyChangedTransition(
            QStringLiteral("activationCounterDouble"),
            GreenHouse::ItemPropertyChangedTransition::Equal, 1.0, home);
    tr->addTriggeredFunction([this](GreenHouse::Context *ctx, const QVariantList &) -> void {
        qApp->exit(0);
        ASSERT_EQ(context, ctx);
    });
    qApp->exec();
}

TEST_F(StateMachine, ItemPropertyChangedTransitionTriggerNotEqualDouble)
{
    auto home = qobject_cast<GreenHouse::ItemState *>(
            context->stateForName(QStringLiteral("HomeState")));
    ASSERT_NE(home, nullptr);
    auto tr = new GreenHouse::ItemPropertyChangedTransition(
            QStringLiteral("activationCounterDouble"),
            GreenHouse::ItemPropertyChangedTransition::NotEqual, 0.0, home);
    tr->addTriggeredFunction([this](GreenHouse::Context *ctx, const QVariantList &) -> void {
        qApp->exit(0);
        ASSERT_EQ(context, ctx);
    });
    qApp->exec();
}

TEST_F(StateMachine, ItemPropertyChangedTransitionTriggerGreaterThanDouble)
{
    auto home = qobject_cast<GreenHouse::ItemState *>(
            context->stateForName(QStringLiteral("HomeState")));
    ASSERT_NE(home, nullptr);
    auto tr = new GreenHouse::ItemPropertyChangedTransition(
            QStringLiteral("activationCounterDouble"),
            GreenHouse::ItemPropertyChangedTransition::GreaterThan, 0.0, home);
    tr->addTriggeredFunction([this](GreenHouse::Context *ctx, const QVariantList &) -> void {
        qApp->exit(0);
        ASSERT_EQ(context, ctx);
    });
    qApp->exec();
}

TEST_F(StateMachine, ItemPropertyChangedTransitionTriggerLessThanDouble)
{
    auto home = qobject_cast<GreenHouse::ItemState *>(
            context->stateForName(QStringLiteral("HomeState")));
    ASSERT_NE(home, nullptr);
    auto tr = new GreenHouse::ItemPropertyChangedTransition(
            QStringLiteral("activationCounterDouble"),
            GreenHouse::ItemPropertyChangedTransition::LessThan, 2.0, home);
    tr->addTriggeredFunction([this](GreenHouse::Context *ctx, const QVariantList &) -> void {
        qApp->exit(0);
        ASSERT_EQ(context, ctx);
    });
    qApp->exec();
}

TEST_F(StateMachine, ItemPropertyChangedTransitionTriggerGreaterThanOrEqualDouble)
{
    auto home = qobject_cast<GreenHouse::ItemState *>(
            context->stateForName(QStringLiteral("HomeState")));
    ASSERT_NE(home, nullptr);
    auto tr = new GreenHouse::ItemPropertyChangedTransition(
            QStringLiteral("activationCounterDouble"),
            GreenHouse::ItemPropertyChangedTransition::GreaterThanOrEqual, 1.0, home);
    tr->addTriggeredFunction([this](GreenHouse::Context *ctx, const QVariantList &) -> void {
        qApp->exit(0);
        ASSERT_EQ(context, ctx);
    });
    qApp->exec();
}

TEST_F(StateMachine, ItemPropertyChangedTransitionTriggerLessThanOrEqualDouble)
{
    auto home = qobject_cast<GreenHouse::ItemState *>(
            context->stateForName(QStringLiteral("HomeState")));
    ASSERT_NE(home, nullptr);
    auto tr = new GreenHouse::ItemPropertyChangedTransition(
            QStringLiteral("activationCounterDouble"),
            GreenHouse::ItemPropertyChangedTransition::LessThanOrEqual, 1.0, home);
    tr->addTriggeredFunction([this](GreenHouse::Context *ctx, const QVariantList &) -> void {
        qApp->exit(0);
        ASSERT_EQ(context, ctx);
    });
    qApp->exec();
}

TEST_F(StateMachine, ItemPropertyChangedTransitionTriggerEqualString)
{
    auto home = qobject_cast<GreenHouse::ItemState *>(
            context->stateForName(QStringLiteral("HomeState")));
    ASSERT_NE(home, nullptr);
    auto tr = new GreenHouse::ItemPropertyChangedTransition(
            QStringLiteral("activationCounterString"),
            GreenHouse::ItemPropertyChangedTransition::Equal, QStringLiteral("01"), home);
    tr->addTriggeredFunction([this](GreenHouse::Context *ctx, const QVariantList &) -> void {
        qApp->exit(0);
        ASSERT_EQ(context, ctx);
    });
    qApp->exec();
}

TEST_F(StateMachine, ItemPropertyChangedTransitionTriggerNotEqualString)
{
    auto home = qobject_cast<GreenHouse::ItemState *>(
            context->stateForName(QStringLiteral("HomeState")));
    ASSERT_NE(home, nullptr);
    auto tr = new GreenHouse::ItemPropertyChangedTransition(
            QStringLiteral("activationCounterString"),
            GreenHouse::ItemPropertyChangedTransition::NotEqual, QStringLiteral("0"), home);
    tr->addTriggeredFunction([this](GreenHouse::Context *ctx, const QVariantList &) -> void {
        qApp->exit(0);
        ASSERT_EQ(context, ctx);
    });
    qApp->exec();
}

TEST_F(StateMachine, ItemPropertyChangedTransitionTriggerGreaterThanString)
{
    auto home = qobject_cast<GreenHouse::ItemState *>(
            context->stateForName(QStringLiteral("HomeState")));
    ASSERT_NE(home, nullptr);
    auto tr = new GreenHouse::ItemPropertyChangedTransition(
            QStringLiteral("activationCounterString"),
            GreenHouse::ItemPropertyChangedTransition::GreaterThan, QStringLiteral("0"), home);
    tr->addTriggeredFunction([this](GreenHouse::Context *ctx, const QVariantList &) -> void {
        qApp->exit(0);
        ASSERT_EQ(context, ctx);
    });
    qApp->exec();
}

TEST_F(StateMachine, ItemPropertyChangedTransitionTriggerLessThanString)
{
    auto home = qobject_cast<GreenHouse::ItemState *>(
            context->stateForName(QStringLiteral("HomeState")));
    ASSERT_NE(home, nullptr);
    auto tr = new GreenHouse::ItemPropertyChangedTransition(
            QStringLiteral("activationCounterString"),
            GreenHouse::ItemPropertyChangedTransition::LessThan, QStringLiteral("011"), home);
    tr->addTriggeredFunction([this](GreenHouse::Context *ctx, const QVariantList &) -> void {
        qApp->exit(0);
        ASSERT_EQ(context, ctx);
    });
    qApp->exec();
}

TEST_F(StateMachine, ItemPropertyChangedTransitionTriggerGreaterThanOrEqualString)
{
    auto home = qobject_cast<GreenHouse::ItemState *>(
            context->stateForName(QStringLiteral("HomeState")));
    ASSERT_NE(home, nullptr);
    auto tr = new GreenHouse::ItemPropertyChangedTransition(
            QStringLiteral("activationCounterString"),
            GreenHouse::ItemPropertyChangedTransition::GreaterThanOrEqual, QStringLiteral("01"),
            home);
    tr->addTriggeredFunction([this](GreenHouse::Context *ctx, const QVariantList &) -> void {
        qApp->exit(0);
        ASSERT_EQ(context, ctx);
    });
    qApp->exec();
}

TEST_F(StateMachine, ItemPropertyChangedTransitionTriggerLessThanOrEqualString)
{
    auto home = qobject_cast<GreenHouse::ItemState *>(
            context->stateForName(QStringLiteral("HomeState")));
    ASSERT_NE(home, nullptr);
    auto tr = new GreenHouse::ItemPropertyChangedTransition(
            QStringLiteral("activationCounterString"),
            GreenHouse::ItemPropertyChangedTransition::LessThanOrEqual, QStringLiteral("01"), home);
    tr->addTriggeredFunction([this](GreenHouse::Context *ctx, const QVariantList &) -> void {
        qApp->exit(0);
        ASSERT_EQ(context, ctx);
    });
    qApp->exec();
}
