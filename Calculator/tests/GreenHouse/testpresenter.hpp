#pragma once

#include <QObject>
#include <greenhousecontext.h>
#include <greenhousemodel.h>

class TestPresenter : public QObject, public GreenHouse::ContextObjectAPI<0>
{
    Q_OBJECT
    Q_DISABLE_COPY(TestPresenter)

    Q_PROPERTY(int testProperty READ testProperty NOTIFY testPropertyChanged)
    int m_testProperty = { -1 };
    Q_PROPERTY(GreenHouse::Model *testModel READ testModel NOTIFY testModelChanged)
    GreenHouse::Model *m_testModel = { nullptr };

public:
    explicit TestPresenter();
    ~TestPresenter() override = default;
    TestPresenter(TestPresenter &&) = delete;
    TestPresenter &operator=(TestPresenter &&) = delete;

    void disableRPC();
    void enableRPC();
    bool rpcEnabled() const;

    virtual void testMethod();
    virtual int testProperty() const { return m_testProperty; }
    virtual void setTestProperty(int testProperty, bool publishToRPC = true);
    virtual GreenHouse::Model *testModel() const { return m_testModel; }
    virtual void setTestModel(GreenHouse::Model *testModel, bool publishToRPC = true);

public:
    // GreenHouse::ContextObject interface
    void handleMessage(const GreenHouse::MessageType, const QJsonObject &) override;
    void publishObjectState() override;

signals:
    void testEvent();
    void testPropertyChanged();
    void testModelChanged();
    void testMethodInvoked();

private:
    bool m_rpcEnabled = true;
};

class LocalTestPresenter : public QObject, public GreenHouse::ContextObjectAPI<1>
{
    Q_OBJECT
    Q_DISABLE_COPY(LocalTestPresenter)

    Q_PROPERTY(int testProperty READ testProperty NOTIFY testPropertyChanged)
    int m_testProperty = { -1 };

public:
    explicit LocalTestPresenter();
    ~LocalTestPresenter() override = default;
    LocalTestPresenter(LocalTestPresenter &&) = delete;
    LocalTestPresenter &operator=(LocalTestPresenter &&) = delete;

    void disableRPC();
    void enableRPC();
    bool rpcEnabled() const;

    virtual int testProperty() const { return m_testProperty; }
    virtual void setTestProperty(int testProperty, bool publishToRPC = true);

public:
    // GreenHouse::ContextObject interface
    void handleMessage(const GreenHouse::MessageType, const QJsonObject &) override;
    void publishObjectState() override;

signals:
    void testPropertyChanged();

private:
    bool m_rpcEnabled = true;
};
