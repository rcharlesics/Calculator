#pragma once

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

#include <greenhousecontext.h>
#include <greenhousemodel.h>

#include <QQmlApplicationEngine>
#include <QQuickItem>
#include <QPointer>
#include <QTimer>

using namespace testing;

class TestContextObject0 : public GreenHouse::ContextObjectAPI<0>
{
public:
    TestContextObject0()
      : GreenHouse::ContextObjectAPI<0>()
    {
    }
};

class TestContextObject1 : public QObject, public GreenHouse::ContextObjectAPI<1>
{
    Q_PROPERTY(GreenHouse::Model *model READ model WRITE setModel)
    Q_PROPERTY(QObject *obj READ obj WRITE setObj)
public:
    TestContextObject1()
      : QObject(nullptr)
      , GreenHouse::ContextObjectAPI<1>()
      , m_model(new GreenHouse::Model(this))
      , m_obj(new QObject(this))
    {
    }

    GreenHouse::Model *model() const { return m_model; }
    QObject *obj() const { return m_obj; }

    void setModel(GreenHouse::Model *model)
    {
        if (GreenHouse::different(model, m_model) || m_obj == nullptr) {
            GreenHouse::cleanupProperty(m_model, this);
            m_model = model;
        }
    }

    void setObj(QObject *obj)
    {
        if (GreenHouse::different(obj, m_obj) || m_obj == nullptr) {
            GreenHouse::cleanupProperty(m_obj, this);
            m_obj = obj;
        }
    }

private:
    GreenHouse::Model *m_model;
    QObject *m_obj;
};

class Context : public Test
{
    // Test interface
protected:
    void SetUp();
    void TearDown();

    QQmlApplicationEngine *qmlEngine = nullptr;
    QQuickItem *rootItem = nullptr;
    GreenHouse::Context *context = nullptr;
    TestContextObject0 *testObj0;
    TestContextObject1 *testObj1;
};

void Context::SetUp()
{
    qmlEngine = new QQmlApplicationEngine;
    qmlEngine->load(QUrl(QStringLiteral("qrc:/test-main.qml")));
    rootItem = qmlEngine->rootObjects().isEmpty()
            ? nullptr
            : qobject_cast<QQuickItem *>(qmlEngine->rootObjects().first());
    context = new GreenHouse::Context(qmlEngine, QString(), rootItem);

    testObj0 = new TestContextObject0;
    testObj1 = new TestContextObject1;
    context->store(testObj0);
    context->store(testObj1);
}

void Context::TearDown()
{
    delete context;
}

TEST_F(Context, RootItemLoaded)
{
    ASSERT_NE(rootItem, nullptr);
}

TEST_F(Context, HasRootItem)
{
    ASSERT_NE(context->contextRootItem(), nullptr);
}

TEST_F(Context, HasCorrectRootItem)
{
    ASSERT_EQ(context->contextRootItem(), rootItem);
}

TEST_F(Context, HasNoRootItemAfterRemovingUi)
{
    context->removeUi();
    ASSERT_EQ(context->contextRootItem(), nullptr);
}

TEST_F(Context, ModelAndObjectPropertyCleanup)
{
    QPointer<GreenHouse::Model> modelPtr = testObj1->model();
    QPointer<QObject> objPtr = testObj1->obj();

    ASSERT_FALSE(modelPtr.isNull());
    ASSERT_FALSE(objPtr.isNull());

    testObj1->setModel(nullptr);
    testObj1->setModel(nullptr);
    testObj1->setObj(nullptr);
    testObj1->setObj(nullptr);

    QTimer::singleShot(10, [=]() -> void {
        qApp->exit(0);
        ASSERT_TRUE(modelPtr.isNull());
        ASSERT_TRUE(objPtr.isNull());
    });
    qApp->exec();
}

TEST_F(Context, ForeignModelAndObjectPropertyCleanup)
{
    QPointer<GreenHouse::Model> modelPtr = new GreenHouse::Model(qApp);
    QPointer<QObject> objPtr = new QObject(qApp);

    ASSERT_FALSE(modelPtr.isNull());
    ASSERT_FALSE(objPtr.isNull());

    testObj1->setModel(modelPtr);
    testObj1->setModel(nullptr);
    testObj1->setModel(modelPtr);
    testObj1->setModel(nullptr);
    testObj1->setObj(objPtr);
    testObj1->setObj(nullptr);

    QTimer::singleShot(10, [=]() -> void {
        qApp->exit(0);
        ASSERT_FALSE(modelPtr.isNull());
        ASSERT_FALSE(objPtr.isNull());
    });
    qApp->exec();
}

TEST_F(Context, ObjectHandleInvalidMessage)
{
    QPointer<GreenHouse::Model> modelPtr = testObj1->model();
    QPointer<QObject> objPtr = testObj1->obj();

    ASSERT_FALSE(modelPtr.isNull());
    ASSERT_FALSE(objPtr.isNull());

    testObj1->setModel(modelPtr);
    testObj1->setObj(objPtr);

    testObj1->handleMessage(GreenHouse::InvalidOperation, {});
    testObj1->handleMessage(GreenHouse::PropertyValueSet, {});
    testObj1->handleMessage(GreenHouse::EventInvoked, {});
    testObj1->handleMessage(GreenHouse::MethodInvoked, {});
    testObj1->handleMessage(GreenHouse::ModelPopulated, {});
    testObj1->handleMessage(GreenHouse::ModelRowRemoved, {});
    testObj1->handleMessage(GreenHouse::ModelRowPrepended, {});
    testObj1->handleMessage(GreenHouse::ModelRowAppended, {});
    testObj1->handleMessage(GreenHouse::ModelRowDataSet, {});

    QTimer::singleShot(10, [=]() -> void {
        qApp->exit(0);
        ASSERT_TRUE(modelPtr.isNull());
        ASSERT_TRUE(objPtr.isNull());
    });
}

TEST_F(Context, ObjectPublishState)
{
    QPointer<GreenHouse::Model> modelPtr = testObj1->model();
    QPointer<QObject> objPtr = testObj1->obj();

    ASSERT_FALSE(modelPtr.isNull());
    ASSERT_FALSE(objPtr.isNull());

    testObj1->setModel(modelPtr);
    testObj1->setObj(objPtr);
    testObj1->publishObjectState();

    QTimer::singleShot(10, [=]() -> void {
        qApp->exit(0);
        ASSERT_TRUE(modelPtr.isNull());
        ASSERT_TRUE(objPtr.isNull());
    });
}

TEST_F(Context, BaseTypePropertyCleanup)
{
    int dummyIntProp = 10;
    ASSERT_TRUE(GreenHouse::different(dummyIntProp, 0));
    GreenHouse::cleanupProperty(dummyIntProp, qApp);
    ASSERT_FALSE(GreenHouse::different(dummyIntProp, 10));

    float dummyFloatProp = 10.0f;
    ASSERT_TRUE(GreenHouse::different(dummyFloatProp, 10.00001f));
    GreenHouse::cleanupProperty(dummyFloatProp, qApp);
    ASSERT_FALSE(GreenHouse::different(dummyFloatProp, 10.0f));

    double dummyDoubleProp = 10.0;
    ASSERT_TRUE(GreenHouse::different(dummyDoubleProp, 10.00001));
    GreenHouse::cleanupProperty(dummyDoubleProp, qApp);
    ASSERT_FALSE(GreenHouse::different(dummyDoubleProp, 10.0));

    QString dummyQStringProp = QStringLiteral("DummyQStringProp");
    ASSERT_TRUE(GreenHouse::different(dummyQStringProp, QStringLiteral("DummyQStringProp_Alt")));
    GreenHouse::cleanupProperty(dummyQStringProp, qApp);
    ASSERT_FALSE(GreenHouse::different(dummyQStringProp, QStringLiteral("DummyQStringProp")));
}

TEST_F(Context, RootItemCorrectAfterChange)
{
    QQuickItem *newRoot = new QQuickItem(rootItem);
    context->setRootItem(newRoot);
    ASSERT_EQ(context->contextRootItem(), newRoot);
}

TEST_F(Context, ActiveLanguageIdIsEmpty)
{
    ASSERT_TRUE(context->activeLanguageId().isEmpty());
}

TEST_F(Context, ObjectsAccessibleByType)
{
    ASSERT_EQ(context->get<TestContextObject0>(), testObj0);
    ASSERT_EQ(context->get<TestContextObject1>(), testObj1);
}

TEST_F(Context, ObjectsAccessibleById)
{
    ASSERT_EQ(context->get(testObj0->storeId()), testObj0);
    ASSERT_EQ(context->get(testObj1->storeId()), testObj1);
}

TEST_F(Context, ObjectsReplacable)
{
    TestContextObject0 newTestObj0;
    ASSERT_EQ(context->get(testObj0->storeId()), testObj0);
    context->store(&newTestObj0);
    ASSERT_EQ(context->get(testObj0->storeId()), &newTestObj0);

    TestContextObject1 newTestObj1;
    ASSERT_EQ(context->get(testObj1->storeId()), testObj1);
    context->store(&newTestObj1);
    ASSERT_EQ(context->get(testObj1->storeId()), &newTestObj1);
}

TEST_F(Context, ObjectsRemovable)
{
    ASSERT_EQ(context->get(testObj0->storeId()), testObj0);
    context->remove(testObj0);
    ASSERT_EQ(context->get(testObj0->storeId()), nullptr);

    ASSERT_EQ(context->get(testObj1->storeId()), testObj1);
    context->remove(testObj1);
    ASSERT_EQ(context->get(testObj1->storeId()), nullptr);
}

TEST_F(Context, ObjectsNotFakeRemovable)
{
    TestContextObject0 fakeTestObj0;
    ASSERT_EQ(context->get(testObj0->storeId()), testObj0);
    context->remove(&fakeTestObj0);
    ASSERT_EQ(context->get(testObj0->storeId()), testObj0);

    TestContextObject1 fakeTestObj1;
    ASSERT_EQ(context->get(testObj1->storeId()), testObj1);
    context->remove(&fakeTestObj1);
    ASSERT_EQ(context->get(testObj1->storeId()), testObj1);
}

TEST_F(Context, OutOfScopeObjectsIsNull)
{
    ASSERT_EQ(context->get(9999), nullptr);
}
