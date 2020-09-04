#pragma once

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

#include <QCoreApplication>
#include <QTimer>

#include <greenhousecontext.h>
#include <greenhouseremoteuxinterface.h>

#include "testpresenter.hpp"

using namespace testing;

class RPCTest : public Test
{
    // Test interface
protected:
    void SetUp();
    void TearDown();

    GreenHouse::Context serverCtx;
    GreenHouse::RemoteUXInterfaceManager *remoteInterfaceManager;
    GreenHouse::WebSocketRPCServer *server;
    TestPresenter *serverIface;
    LocalTestPresenter *localIface;

    GreenHouse::Context clientCtx;
    GreenHouse::WebSocketRPC *clientSocket;
    TestPresenter *clientIface;
};

void RPCTest::SetUp()
{
    remoteInterfaceManager = new GreenHouse::RemoteUXInterfaceManager(&serverCtx);
    serverIface = new TestPresenter;
    localIface = new LocalTestPresenter;
    serverCtx.store(serverIface);
    serverCtx.store(localIface);
    server = new GreenHouse::WebSocketRPCServer(&serverCtx, {}, QWebSocketServer::NonSecureMode);
    server->setServerName(QStringLiteral("Test RPC Server"));
    server->listen(QHostAddress::Any, quint16(26186));

    clientIface = new TestPresenter;
    clientCtx.store(clientIface);
    clientSocket = new GreenHouse::WebSocketRPC(&clientCtx);
    clientSocket->setServiceName(QStringLiteral("Test RPC Socket"));
    clientSocket->connectTo(QUrl(QStringLiteral("ws://localhost:26186")));
}

void RPCTest::TearDown()
{
    delete remoteInterfaceManager;
}

TEST_F(RPCTest, RemoteItemShow)
{
    QObject::connect(clientSocket, &GreenHouse::WebSocketRPC::connected, [&]() -> void {
        clientSocket->installPayloadHook([&](const QJsonObject &data) -> void {
            auto objIt = data.constFind(GreenHouse::SHOW_VISUAL_LAYER_TAG);
            if (objIt != data.constEnd()) {
                ASSERT_TRUE(objIt.value().toString().compare(QStringLiteral("Test Layer")) == 0);
            }

            objIt = data.constFind(GreenHouse::SHOW_VISUAL_ITEM_TAG);
            if (objIt != data.constEnd()) {
                ASSERT_TRUE(objIt.value().toString().compare(QStringLiteral("Test Item")) == 0);
            }
        });
        remoteInterfaceManager->layerShown(QStringLiteral("Test Layer"));
        remoteInterfaceManager->itemShown(QStringLiteral("Test Item"));
        QTimer::singleShot(110, clientIface, [&]() -> void {
            const auto visibleLayers = remoteInterfaceManager->visibleLayers();
            ASSERT_TRUE(visibleLayers.count() == 1);
            ASSERT_TRUE(visibleLayers.constFind(QStringLiteral("Test Layer"))
                        != visibleLayers.constEnd());

            const auto visibleItems = remoteInterfaceManager->visibleItems();
            ASSERT_TRUE(visibleItems.count() == 1);
            ASSERT_TRUE(visibleItems.constFind(QStringLiteral("Test Item"))
                        != visibleItems.constEnd());
            clientSocket->close();
        });
    });
    QObject::connect(clientSocket, &GreenHouse::WebSocketRPC::disconnected,
                     [&]() -> void { qApp->exit(0); });
    qApp->exec();
}

TEST_F(RPCTest, RemoteItemHidden)
{
    QObject::connect(clientSocket, &GreenHouse::WebSocketRPC::connected, [&]() -> void {
        clientSocket->installPayloadHook([&](const QJsonObject &data) -> void {
            auto objIt = data.constFind(GreenHouse::SHOW_VISUAL_LAYER_TAG);
            if (objIt != data.constEnd()) {
                ASSERT_TRUE(objIt.value().toString().compare(QStringLiteral("Test Layer")) == 0);
                remoteInterfaceManager->layerHidden(QStringLiteral("Test Layer"));
            }

            objIt = data.constFind(GreenHouse::SHOW_VISUAL_ITEM_TAG);
            if (objIt != data.constEnd()) {
                ASSERT_TRUE(objIt.value().toString().compare(QStringLiteral("Test Item")) == 0);
                remoteInterfaceManager->itemHidden(QStringLiteral("Test Item"));
            }

            objIt = data.constFind(GreenHouse::HIDE_VISUAL_LAYER_TAG);
            if (objIt != data.constEnd()) {
                ASSERT_TRUE(objIt.value().toString().compare(QStringLiteral("Test Layer")) == 0);
            }

            objIt = data.constFind(GreenHouse::SHOW_VISUAL_ITEM_TAG);
            if (objIt != data.constEnd()) {
                ASSERT_TRUE(objIt.value().toString().compare(QStringLiteral("Test Item")) == 0);
            }
        });
        remoteInterfaceManager->layerShown(QStringLiteral("Test Layer"));
        remoteInterfaceManager->itemShown(QStringLiteral("Test Item"));
        QTimer::singleShot(110, clientIface, [&]() -> void {
            const auto visibleLayers = remoteInterfaceManager->visibleLayers();
            ASSERT_TRUE(visibleLayers.count() == 0);

            const auto visibleItems = remoteInterfaceManager->visibleItems();
            ASSERT_TRUE(visibleItems.count() == 0);
            clientSocket->close();
        });
    });
    QObject::connect(clientSocket, &GreenHouse::WebSocketRPC::disconnected,
                     [&]() -> void { qApp->exit(0); });
    qApp->exec();
}

TEST_F(RPCTest, PublishVisibleItems)
{
    QObject::connect(clientSocket, &GreenHouse::WebSocketRPC::connected, [&]() -> void {
        clientSocket->installPayloadHook([&](const QJsonObject &data) -> void {
            auto objIt = data.constFind(GreenHouse::SHOW_VISUAL_LAYER_TAG);
            if (objIt != data.constEnd()) {
                ASSERT_TRUE(objIt.value().toString().compare(QStringLiteral("Test Layer")) == 0);
                clientSocket->publishOrDiscoverActiveLayers();
            }

            objIt = data.constFind(GreenHouse::SHOW_VISUAL_ITEM_TAG);
            if (objIt != data.constEnd()) {
                ASSERT_TRUE(objIt.value().toString().compare(QStringLiteral("Test Item")) == 0);
                clientSocket->publishOrDiscoverActiveItems();
            }

            objIt = data.constFind(GreenHouse::ACTIVE_LAYER_SET_TAG);
            if (objIt != data.constEnd()) {
                auto array = objIt.value().toArray();
                if (array.count() > 0) {
                    ASSERT_TRUE(array.at(0).toString().compare(QStringLiteral("Test Layer")) == 0);
                }
            }

            objIt = data.constFind(GreenHouse::ACTIVE_ITEM_SET_TAG);
            if (objIt != data.constEnd()) {
                auto array = objIt.value().toArray();
                if (array.count() > 0) {
                    ASSERT_TRUE(array.at(0).toString().compare(QStringLiteral("Test Item")) == 0);
                }
            }
        });
        remoteInterfaceManager->layerShown(QStringLiteral("Test Layer"));
        remoteInterfaceManager->itemShown(QStringLiteral("Test Item"));
        QTimer::singleShot(110, clientIface, [&]() -> void {
            const auto visibleLayers = remoteInterfaceManager->visibleLayers();
            ASSERT_TRUE(visibleLayers.count() == 1);
            ASSERT_TRUE(visibleLayers.constFind(QStringLiteral("Test Layer"))
                        != visibleLayers.constEnd());

            const auto visibleItems = remoteInterfaceManager->visibleItems();
            ASSERT_TRUE(visibleItems.count() == 1);
            ASSERT_TRUE(visibleItems.constFind(QStringLiteral("Test Item"))
                        != visibleItems.constEnd());
            clientSocket->close();
        });
    });
    QObject::connect(clientSocket, &GreenHouse::WebSocketRPC::disconnected,
                     [&]() -> void { qApp->exit(0); });
    qApp->exec();
}

TEST_F(RPCTest, PayloadHook)
{
    bool hookTriggered = false;
    QObject::connect(clientSocket, &GreenHouse::WebSocketRPC::connected, [&]() -> void {
        clientSocket->installPayloadHook([&](const QJsonObject &data) -> void {
            hookTriggered = true;
            auto objIt = data.constFind(GreenHouse::OBJECT_ID_TAG);
            if (objIt != data.constEnd()) {
                ASSERT_TRUE(objIt.value().toInt() == TestPresenter::storeId()
                            || objIt.value().toInt() == LocalTestPresenter::storeId());
            }
            objIt = data.constFind(GreenHouse::THEME_ID_TAG);
            if (objIt != data.constEnd()) {
                ASSERT_TRUE(objIt.value().toString().compare(QStringLiteral("Test Theme")) == 0);
            }
            objIt = data.constFind(GreenHouse::LANGUAGE_ID_TAG);
            if (objIt != data.constEnd()) {
                ASSERT_TRUE(objIt.value().toString().compare(QStringLiteral("Test Language")) == 0);
            }
        });
        serverIface->setTestProperty(0);
        serverCtx.activateTheme(QStringLiteral("Test Theme"));
        serverCtx.activateLanguage(QStringLiteral("Test Language"));
        QTimer::singleShot(110, clientIface, [&]() -> void {
            ASSERT_TRUE(hookTriggered);
            clientSocket->close();
        });
    });
    QObject::connect(clientSocket, &GreenHouse::WebSocketRPC::disconnected,
                     [&]() -> void { qApp->exit(0); });
    qApp->exec();
}

TEST_F(RPCTest, PropertyMirroring)
{
    QObject::connect(clientSocket, &GreenHouse::WebSocketRPC::connected, [&]() -> void {
        serverIface->setTestProperty(0);
        localIface->setTestProperty(10);
        QTimer::singleShot(100, clientIface, [&]() -> void {
            ASSERT_TRUE(serverIface->testProperty() == 0);
            ASSERT_TRUE(clientIface->testProperty() == 0);
            ASSERT_TRUE(localIface->testProperty() == 10);
        });
        QTimer::singleShot(110, clientIface, [&]() -> void { clientSocket->close(); });
    });
    QObject::connect(clientSocket, &GreenHouse::WebSocketRPC::disconnected,
                     [&]() -> void { qApp->exit(0); });
    qApp->exec();
}

TEST_F(RPCTest, PropertyMirroringChunky)
{
    server->setAPIType(GreenHouse::Chunky);
    QObject::connect(clientSocket, &GreenHouse::WebSocketRPC::connected, [&]() -> void {
        serverIface->setTestProperty(0);
        localIface->setTestProperty(10);
        QTimer::singleShot(100, clientIface, [&]() -> void {
            ASSERT_TRUE(serverIface->testProperty() == 0);
            ASSERT_TRUE(clientIface->testProperty() == -1);
            ASSERT_TRUE(localIface->testProperty() == 10);
            server->flush();
        });
        QTimer::singleShot(200, clientIface, [&]() -> void {
            ASSERT_TRUE(serverIface->testProperty() == 0);
            ASSERT_TRUE(clientIface->testProperty() == 0);
            ASSERT_TRUE(localIface->testProperty() == 10);
        });
        QTimer::singleShot(210, clientIface, [&]() -> void { clientSocket->close(); });
    });
    QObject::connect(clientSocket, &GreenHouse::WebSocketRPC::disconnected,
                     [&]() -> void { qApp->exit(0); });
    qApp->exec();
}

TEST_F(RPCTest, PropertyMirroringBlocked)
{
    clientSocket->setMessageTypeBlacklist({ GreenHouse::PropertyValueSet });
    QObject::connect(clientSocket, &GreenHouse::WebSocketRPC::connected, [&]() -> void {
        serverIface->setTestProperty(0);
        QTimer::singleShot(100, clientIface, [&]() -> void {
            ASSERT_TRUE(serverIface->testProperty() == 0);
            ASSERT_TRUE(clientIface->testProperty() != 0);
        });
        QTimer::singleShot(110, clientIface, [&]() -> void { clientSocket->close(); });
    });
    QObject::connect(clientSocket, &GreenHouse::WebSocketRPC::disconnected,
                     [&]() -> void { qApp->exit(0); });
    qApp->exec();
}

TEST_F(RPCTest, ModelPopulation)
{
    QObject::connect(clientSocket, &GreenHouse::WebSocketRPC::connected, [&]() -> void {
        serverIface->testModel()->populate(
                QJsonArray({ QJsonObject({ { QStringLiteral("roleA"), QStringLiteral("value1") },
                                           { QStringLiteral("roleB"), 0 },
                                           { QStringLiteral("roleC"), false } }),
                             QJsonObject({ { QStringLiteral("roleA"), QStringLiteral("value2") },
                                           { QStringLiteral("roleB"), 1 },
                                           { QStringLiteral("roleC"), true } }),
                             QJsonObject({ { QStringLiteral("roleA"), QStringLiteral("value3") },
                                           { QStringLiteral("roleB"), 2 },
                                           { QStringLiteral("roleC"), false } }) }));
        QTimer::singleShot(100, clientIface, [&]() -> void {
            ASSERT_EQ(clientIface->testModel()->rowCount(), 3);
            ASSERT_FALSE(clientIface->testModel()->dataAt(0).isEmpty());
            ASSERT_TRUE(clientIface->testModel()
                                ->dataAt(0)
                                .value(QStringLiteral("roleA"))
                                .toString()
                                .compare(QStringLiteral("value1"))
                        == 0);
            ASSERT_TRUE(clientIface->testModel()
                                ->dataAt(1)
                                .value(QStringLiteral("roleA"))
                                .toString()
                                .compare(QStringLiteral("value2"))
                        == 0);
            ASSERT_TRUE(clientIface->testModel()
                                ->dataAt(2)
                                .value(QStringLiteral("roleA"))
                                .toString()
                                .compare(QStringLiteral("value3"))
                        == 0);
            ASSERT_TRUE(clientIface->testModel()->dataAt(0).value(QStringLiteral("roleB")).toInt()
                        == 0);
            ASSERT_TRUE(clientIface->testModel()->dataAt(1).value(QStringLiteral("roleB")).toInt()
                        == 1);
            ASSERT_TRUE(clientIface->testModel()->dataAt(2).value(QStringLiteral("roleB")).toInt()
                        == 2);
            ASSERT_FALSE(
                    clientIface->testModel()->dataAt(0).value(QStringLiteral("roleC")).toBool());
            ASSERT_TRUE(
                    clientIface->testModel()->dataAt(1).value(QStringLiteral("roleC")).toBool());
            ASSERT_FALSE(
                    clientIface->testModel()->dataAt(2).value(QStringLiteral("roleC")).toBool());
            ASSERT_EQ(clientIface->testModel()->roles().length(), 3);
            ASSERT_TRUE(clientIface->testModel()->roles().at(0).compare(QStringLiteral("roleA"))
                        == 0);
            ASSERT_TRUE(clientIface->testModel()->roles().at(1).compare(QStringLiteral("roleB"))
                        == 0);
            ASSERT_TRUE(clientIface->testModel()->roles().at(2).compare(QStringLiteral("roleC"))
                        == 0);
        });
        QTimer::singleShot(110, clientIface, [&]() -> void { clientSocket->close(); });
    });
    QObject::connect(clientSocket, &GreenHouse::WebSocketRPC::disconnected,
                     [&]() -> void { qApp->exit(0); });
    qApp->exec();
}

TEST_F(RPCTest, ModelRemoveRow)
{
    QObject::connect(clientSocket, &GreenHouse::WebSocketRPC::connected, [&]() -> void {
        serverIface->testModel()->populate(
                QJsonArray({ QJsonObject({ { QStringLiteral("roleA"), QStringLiteral("value1") },
                                           { QStringLiteral("roleB"), 0 },
                                           { QStringLiteral("roleC"), false } }),
                             QJsonObject({ { QStringLiteral("roleA"), QStringLiteral("value2") },
                                           { QStringLiteral("roleB"), 1 },
                                           { QStringLiteral("roleC"), true } }),
                             QJsonObject({ { QStringLiteral("roleA"), QStringLiteral("value3") },
                                           { QStringLiteral("roleB"), 2 },
                                           { QStringLiteral("roleC"), false } }) }));
        serverIface->testModel()->removeRow(0);
        QTimer::singleShot(100, clientIface, [&]() -> void {
            ASSERT_EQ(clientIface->testModel()->rowCount(), 2);
            ASSERT_FALSE(clientIface->testModel()->dataAt(0).isEmpty());
            ASSERT_TRUE(clientIface->testModel()
                                ->dataAt(0)
                                .value(QStringLiteral("roleA"))
                                .toString()
                                .compare(QStringLiteral("value2"))
                        == 0);
        });
        QTimer::singleShot(110, clientIface, [&]() -> void { clientSocket->close(); });
    });
    QObject::connect(clientSocket, &GreenHouse::WebSocketRPC::disconnected,
                     [&]() -> void { qApp->exit(0); });
    qApp->exec();
}

TEST_F(RPCTest, ModelAppendRow)
{
    QObject::connect(clientSocket, &GreenHouse::WebSocketRPC::connected, [&]() -> void {
        serverIface->testModel()->populate(
                QJsonArray({ QJsonObject({ { QStringLiteral("roleA"), QStringLiteral("value1") },
                                           { QStringLiteral("roleB"), 0 },
                                           { QStringLiteral("roleC"), false } }),
                             QJsonObject({ { QStringLiteral("roleA"), QStringLiteral("value2") },
                                           { QStringLiteral("roleB"), 1 },
                                           { QStringLiteral("roleC"), true } }),
                             QJsonObject({ { QStringLiteral("roleA"), QStringLiteral("value3") },
                                           { QStringLiteral("roleB"), 2 },
                                           { QStringLiteral("roleC"), false } }) }));
        serverIface->testModel()->appendRow(
                QJsonObject({ { QStringLiteral("roleA"), QStringLiteral("value4") },
                              { QStringLiteral("roleB"), 0 },
                              { QStringLiteral("roleC"), false } }));
        QTimer::singleShot(100, clientIface, [&]() -> void {
            ASSERT_EQ(clientIface->testModel()->rowCount(), 4);
            ASSERT_FALSE(clientIface->testModel()->dataAt(3).isEmpty());
            ASSERT_TRUE(clientIface->testModel()
                                ->dataAt(3)
                                .value(QStringLiteral("roleA"))
                                .toString()
                                .compare(QStringLiteral("value4"))
                        == 0);
        });
        QTimer::singleShot(110, clientIface, [&]() -> void { clientSocket->close(); });
    });
    QObject::connect(clientSocket, &GreenHouse::WebSocketRPC::disconnected,
                     [&]() -> void { qApp->exit(0); });
    qApp->exec();
}

TEST_F(RPCTest, ModelPrependRow)
{
    QObject::connect(clientSocket, &GreenHouse::WebSocketRPC::connected, [&]() -> void {
        serverIface->testModel()->populate(
                QJsonArray({ QJsonObject({ { QStringLiteral("roleA"), QStringLiteral("value1") },
                                           { QStringLiteral("roleB"), 0 },
                                           { QStringLiteral("roleC"), false } }),
                             QJsonObject({ { QStringLiteral("roleA"), QStringLiteral("value2") },
                                           { QStringLiteral("roleB"), 1 },
                                           { QStringLiteral("roleC"), true } }),
                             QJsonObject({ { QStringLiteral("roleA"), QStringLiteral("value3") },
                                           { QStringLiteral("roleB"), 2 },
                                           { QStringLiteral("roleC"), false } }) }));
        serverIface->testModel()->prependRow(
                QJsonObject({ { QStringLiteral("roleA"), QStringLiteral("value4") },
                              { QStringLiteral("roleB"), 0 },
                              { QStringLiteral("roleC"), false } }));
        QTimer::singleShot(100, clientIface, [&]() -> void {
            ASSERT_EQ(clientIface->testModel()->rowCount(), 4);
            ASSERT_FALSE(clientIface->testModel()->dataAt(0).isEmpty());
            ASSERT_TRUE(clientIface->testModel()
                                ->dataAt(0)
                                .value(QStringLiteral("roleA"))
                                .toString()
                                .compare(QStringLiteral("value4"))
                        == 0);
        });
        QTimer::singleShot(110, clientIface, [&]() -> void { clientSocket->close(); });
    });
    QObject::connect(clientSocket, &GreenHouse::WebSocketRPC::disconnected,
                     [&]() -> void { qApp->exit(0); });
    qApp->exec();
}

TEST_F(RPCTest, ModelSetRowData)
{
    QObject::connect(clientSocket, &GreenHouse::WebSocketRPC::connected, [&]() -> void {
        serverIface->testModel()->populate(
                QJsonArray({ QJsonObject({ { QStringLiteral("roleA"), QStringLiteral("value1") },
                                           { QStringLiteral("roleB"), 0 },
                                           { QStringLiteral("roleC"), false } }),
                             QJsonObject({ { QStringLiteral("roleA"), QStringLiteral("value2") },
                                           { QStringLiteral("roleB"), 1 },
                                           { QStringLiteral("roleC"), true } }),
                             QJsonObject({ { QStringLiteral("roleA"), QStringLiteral("value3") },
                                           { QStringLiteral("roleB"), 2 },
                                           { QStringLiteral("roleC"), false } }) }));
        serverIface->testModel()->setRowData(
                0,
                QJsonObject({ { QStringLiteral("roleA"), QStringLiteral("value4") },
                              { QStringLiteral("roleB"), 0 },
                              { QStringLiteral("roleC"), false } }));
        QTimer::singleShot(100, clientIface, [&]() -> void {
            ASSERT_EQ(clientIface->testModel()->rowCount(), 3);
            ASSERT_FALSE(clientIface->testModel()->dataAt(0).isEmpty());
            ASSERT_TRUE(clientIface->testModel()
                                ->dataAt(0)
                                .value(QStringLiteral("roleA"))
                                .toString()
                                .compare(QStringLiteral("value4"))
                        == 0);
        });
        QTimer::singleShot(110, clientIface, [&]() -> void { clientSocket->close(); });
    });
    QObject::connect(clientSocket, &GreenHouse::WebSocketRPC::disconnected,
                     [&]() -> void { qApp->exit(0); });
    qApp->exec();
}

TEST_F(RPCTest, EventMirroring)
{
    QObject::connect(clientSocket, &GreenHouse::WebSocketRPC::connected, [&]() -> void {
        QObject::connect(clientIface, &TestPresenter::testEvent,
                         [&]() -> void { clientSocket->close(); });
        serverIface->testEvent();
    });
    QObject::connect(clientSocket, &GreenHouse::WebSocketRPC::disconnected,
                     [&]() -> void { qApp->exit(0); });
    qApp->exec();
}

TEST_F(RPCTest, MethodMirroring)
{
    QObject::connect(clientSocket, &GreenHouse::WebSocketRPC::connected, [&]() -> void {
        QObject::connect(clientIface, &TestPresenter::testMethodInvoked,
                         [&]() -> void { clientSocket->close(); });
        serverIface->testMethod();
    });
    QObject::connect(clientSocket, &GreenHouse::WebSocketRPC::disconnected,
                     [&]() -> void { qApp->exit(0); });
    qApp->exec();
}
