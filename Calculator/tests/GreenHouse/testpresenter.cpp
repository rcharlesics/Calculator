#include "testpresenter.hpp"
#include <QDebug>

TestPresenter::TestPresenter()
  : QObject(nullptr)
  , m_testModel(new GreenHouse::Model(this))
{
    connect(this, &TestPresenter::testEvent, this, [this]() -> void {
        if (m_rpcEnabled) {
            rpcNotifyEventInvoked(QStringLiteral("testEvent"), {});
        }
    });

    connect(m_testModel, &GreenHouse::Model::populated, this,
            [this](const QStringList &roles, const QJsonArray &data) -> void {
                if (m_rpcEnabled)
                    this->rpcNotifyModelPopulated(QStringLiteral("testModel"), roles, data);
            });
    connect(m_testModel, &GreenHouse::Model::rowRemoved, this, [this](int row) -> void {
        if (m_rpcEnabled)
            this->rpcNotifyModelRowRemoved(QStringLiteral("testModel"), row);
    });
    connect(m_testModel, &GreenHouse::Model::rowPrepended, this,
            [this](const QJsonObject &data) -> void {
                if (m_rpcEnabled)
                    this->rpcNotifyModelRowPrepended(QStringLiteral("testModel"), data);
            });
    connect(m_testModel, &GreenHouse::Model::rowAppended, this,
            [this](const QJsonObject &data) -> void {
                if (m_rpcEnabled)
                    this->rpcNotifyModelRowAppended(QStringLiteral("testModel"), data);
            });
    connect(m_testModel, &GreenHouse::Model::rowDataSet, this,
            [this](int row, const QJsonObject &data) -> void {
                if (m_rpcEnabled)
                    this->rpcNotifyModelRowDataSet(QStringLiteral("testModel"), row, data);
            });
}

void TestPresenter::disableRPC()
{
    m_rpcEnabled = false;
}

void TestPresenter::enableRPC()
{
    m_rpcEnabled = true;
}

bool TestPresenter::rpcEnabled() const
{
    return m_rpcEnabled;
}

void TestPresenter::testMethod()
{
    if (m_rpcEnabled)
        rpcNotifyMethodInvoked(QStringLiteral("testMethod"), {});
    emit testMethodInvoked();
}

void TestPresenter::setTestProperty(int testProperty, bool publishToRPC)
{
    if (GreenHouse::different(m_testProperty, testProperty)) {
        GreenHouse::cleanupProperty(m_testProperty, this);
        m_testProperty = testProperty;
        emit testPropertyChanged();
    }
    if (publishToRPC && m_rpcEnabled)
        rpcNotifyPropertySet(QStringLiteral("testProperty"), testProperty);
}

void TestPresenter::setTestModel(GreenHouse::Model *testModel, bool publishToRPC)
{
    if (GreenHouse::different(m_testModel, testModel)) {
        GreenHouse::cleanupProperty(m_testModel, this);
        m_testModel = testModel;
        emit testModelChanged();
        connect(m_testModel, &GreenHouse::Model::populated, this,
                [this](const QStringList &roles, const QJsonArray &data) -> void {
                    if (m_rpcEnabled)
                        this->rpcNotifyModelPopulated(QStringLiteral("testModel"), roles, data);
                });
        connect(m_testModel, &GreenHouse::Model::rowRemoved, this, [this](int row) -> void {
            if (m_rpcEnabled)
                this->rpcNotifyModelRowRemoved(QStringLiteral("testModel"), row);
        });
        connect(m_testModel, &GreenHouse::Model::rowPrepended, this,
                [this](const QJsonObject &data) -> void {
                    if (m_rpcEnabled)
                        this->rpcNotifyModelRowPrepended(QStringLiteral("testModel"), data);
                });
        connect(m_testModel, &GreenHouse::Model::rowAppended, this,
                [this](const QJsonObject &data) -> void {
                    if (m_rpcEnabled)
                        this->rpcNotifyModelRowAppended(QStringLiteral("testModel"), data);
                });
        connect(m_testModel, &GreenHouse::Model::rowDataSet, this,
                [this](int row, const QJsonObject &data) -> void {
                    if (m_rpcEnabled)
                        this->rpcNotifyModelRowDataSet(QStringLiteral("testModel"), row, data);
                });
    }
    if (publishToRPC && m_rpcEnabled)
        rpcNotifyPropertySet(QStringLiteral("testModel"), testModel);
}

void TestPresenter::handleMessage(const GreenHouse::MessageType msgType, const QJsonObject &data)
{
    if (!m_rpcEnabled)
        return;
    if (msgType == GreenHouse::PropertyValueSet) {
        const QString name = data.value(GreenHouse::NAME_TAG).toString();
        const QJsonValue value = data.value(GreenHouse::VALUE_TAG);
        if (name.compare(QStringLiteral("testProperty")) == 0) {
            setTestProperty(value.toInt(), false);
            return;
        }
        if (name.compare(QStringLiteral("testModel")) == 0) {
            testModel()->populate(value.toArray());
            return;
        }
    } else if (msgType == GreenHouse::EventInvoked) {
        const QString name = data.value(GreenHouse::NAME_TAG).toString();
        const QJsonObject args = data.value(GreenHouse::ARGS_TAG).toObject();
        if (name.compare(QStringLiteral("testEvent")) == 0) {
            testEvent();
            return;
        }
    } else if (msgType == GreenHouse::MethodInvoked) {
        const QString name = data.value(GreenHouse::NAME_TAG).toString();
        const QJsonObject args = data.value(GreenHouse::ARGS_TAG).toObject();
        if (name.compare(QStringLiteral("testMethod")) == 0) {
            testMethod();
            return;
        }
    } else if (msgType == GreenHouse::ModelPopulated) {
        const QString name = data.value(GreenHouse::NAME_TAG).toString();
        const QJsonArray value = data.value(GreenHouse::VALUE_TAG).toArray();
        const QJsonArray args = data.value(GreenHouse::ARGS_TAG).toArray();
        QStringList roles;
        for (auto arg : args)
            roles.append(arg.toString());
        if (name.compare(QStringLiteral("testModel")) == 0) {
            m_testModel->populate(roles, value, true);
            return;
        }
    } else if (msgType == GreenHouse::ModelRowRemoved) {
        const QString name = data.value(GreenHouse::NAME_TAG).toString();
        const int row = data.value(GreenHouse::ARGS_TAG).toInt(-1);
        if (name.compare(QStringLiteral("testModel")) == 0) {
            m_testModel->removeRow(row, true);
            return;
        }
    } else if (msgType == GreenHouse::ModelRowPrepended) {
        const QString name = data.value(GreenHouse::NAME_TAG).toString();
        const QJsonObject value = data.value(GreenHouse::VALUE_TAG).toObject();
        if (name.compare(QStringLiteral("testModel")) == 0) {
            m_testModel->prependRow(value, true);
            return;
        }
    } else if (msgType == GreenHouse::ModelRowAppended) {
        const QString name = data.value(GreenHouse::NAME_TAG).toString();
        const QJsonObject value = data.value(GreenHouse::VALUE_TAG).toObject();
        if (name.compare(QStringLiteral("testModel")) == 0) {
            m_testModel->appendRow(value, true);
            return;
        }
    } else if (msgType == GreenHouse::ModelRowDataSet) {
        const QString name = data.value(GreenHouse::NAME_TAG).toString();
        const QJsonObject value = data.value(GreenHouse::VALUE_TAG).toObject();
        const int row = data.value(GreenHouse::ARGS_TAG).toInt(-1);
        if (name.compare(QStringLiteral("testModel")) == 0) {
            m_testModel->setRowData(row, value, true);
            return;
        }
    }
}

void TestPresenter::publishObjectState()
{
    if (!m_rpcEnabled)
        return;
    rpcNotifyPropertySet(QStringLiteral("testProperty"), testProperty());
    rpcNotifyPropertySet(QStringLiteral("testModel"), testModel());
}

LocalTestPresenter::LocalTestPresenter()
  : QObject(nullptr)
{
}

void LocalTestPresenter::disableRPC()
{
    m_rpcEnabled = false;
}

void LocalTestPresenter::enableRPC()
{
    m_rpcEnabled = true;
}

bool LocalTestPresenter::rpcEnabled() const
{
    return m_rpcEnabled;
}

void LocalTestPresenter::setTestProperty(int testProperty, bool publishToRPC)
{
    if (GreenHouse::different(m_testProperty, testProperty)) {
        GreenHouse::cleanupProperty(m_testProperty, this);
        m_testProperty = testProperty;
        emit testPropertyChanged();
    }
    if (publishToRPC && m_rpcEnabled)
        rpcNotifyPropertySet(QStringLiteral("testProperty"), testProperty);
}

void LocalTestPresenter::handleMessage(const GreenHouse::MessageType msgType,
                                       const QJsonObject &data)
{
    if (!m_rpcEnabled)
        return;
    if (msgType == GreenHouse::PropertyValueSet) {
        const QString name = data.value(GreenHouse::NAME_TAG).toString();
        const QJsonValue value = data.value(GreenHouse::VALUE_TAG);
        if (name.compare(QStringLiteral("testProperty")) == 0) {
            setTestProperty(value.toInt(), false);
            return;
        }
    } else if (msgType == GreenHouse::EventInvoked) {
    } else if (msgType == GreenHouse::MethodInvoked) {
    } else if (msgType == GreenHouse::ModelPopulated) {
    } else if (msgType == GreenHouse::ModelRowRemoved) {
    } else if (msgType == GreenHouse::ModelRowPrepended) {
    } else if (msgType == GreenHouse::ModelRowAppended) {
    } else if (msgType == GreenHouse::ModelRowDataSet) {
    }
}

void LocalTestPresenter::publishObjectState()
{
    if (!m_rpcEnabled)
        return;
    rpcNotifyPropertySet(QStringLiteral("testProperty"), testProperty());
}
