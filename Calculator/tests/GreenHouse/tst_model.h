#pragma once

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

#include <greenhousemodel.h>

using namespace testing;

class Model : public Test
{
    // Test interface
protected:
    void SetUp();
    void TearDown();

    GreenHouse::Model model;
};

void Model::SetUp() {}

void Model::TearDown() {}

TEST_F(Model, RolesOnlyCtor)
{
    GreenHouse::Model localModel(
            { QStringLiteral("roleA"), QStringLiteral("roleB"), QStringLiteral("roleC") });
    ASSERT_EQ(localModel.rowCount(), 0);
    ASSERT_TRUE(localModel.dataAt(0).isEmpty());
    ASSERT_EQ(localModel.roles().length(), 3);
    ASSERT_TRUE(localModel.roles().at(0).compare(QStringLiteral("roleA")) == 0);
    ASSERT_TRUE(localModel.roles().at(1).compare(QStringLiteral("roleB")) == 0);
    ASSERT_TRUE(localModel.roles().at(2).compare(QStringLiteral("roleC")) == 0);
}

TEST_F(Model, RolesAndByteDataCtor)
{
    GreenHouse::Model localModel(
            { QStringLiteral("roleA"), QStringLiteral("roleB"), QStringLiteral("roleC") },
            QByteArray("["
                       "    {"
                       "        \"roleA\": \"value1\","
                       "        \"roleB\": 0,"
                       "        \"roleC\": false"
                       "    },"
                       "    {"
                       "        \"roleA\": \"value2\","
                       "        \"roleB\": 1,"
                       "        \"roleC\": true"
                       "    },"
                       "    {"
                       "        \"roleA\": \"value3\","
                       "        \"roleB\": 2,"
                       "        \"roleC\": false"
                       "    }"
                       "]"));
    ASSERT_EQ(localModel.rowCount(), 3);
    ASSERT_FALSE(localModel.dataAt(0).isEmpty());
    ASSERT_TRUE(localModel.dataAt(0)
                        .value(QStringLiteral("roleA"))
                        .toString()
                        .compare(QStringLiteral("value1"))
                == 0);
    ASSERT_TRUE(localModel.dataAt(1)
                        .value(QStringLiteral("roleA"))
                        .toString()
                        .compare(QStringLiteral("value2"))
                == 0);
    ASSERT_TRUE(localModel.dataAt(2)
                        .value(QStringLiteral("roleA"))
                        .toString()
                        .compare(QStringLiteral("value3"))
                == 0);
    ASSERT_TRUE(localModel.dataAt(0).value(QStringLiteral("roleB")).toInt() == 0);
    ASSERT_TRUE(localModel.dataAt(1).value(QStringLiteral("roleB")).toInt() == 1);
    ASSERT_TRUE(localModel.dataAt(2).value(QStringLiteral("roleB")).toInt() == 2);
    ASSERT_FALSE(localModel.dataAt(0).value(QStringLiteral("roleC")).toBool());
    ASSERT_TRUE(localModel.dataAt(1).value(QStringLiteral("roleC")).toBool());
    ASSERT_FALSE(localModel.dataAt(2).value(QStringLiteral("roleC")).toBool());
    ASSERT_EQ(localModel.roles().length(), 3);
    ASSERT_TRUE(localModel.roles().at(0).compare(QStringLiteral("roleA")) == 0);
    ASSERT_TRUE(localModel.roles().at(1).compare(QStringLiteral("roleB")) == 0);
    ASSERT_TRUE(localModel.roles().at(2).compare(QStringLiteral("roleC")) == 0);
}

TEST_F(Model, RolesAndInvalidByteDataCtor)
{
    GreenHouse::Model localModel(
            { QStringLiteral("roleA"), QStringLiteral("roleB"), QStringLiteral("roleC") },
            QByteArray("Malformed JsonData"));
    ASSERT_EQ(localModel.rowCount(), 0);
    ASSERT_TRUE(localModel.dataAt(0).isEmpty());
    ASSERT_EQ(localModel.roles().length(), 3);
    ASSERT_TRUE(localModel.roles().at(0).compare(QStringLiteral("roleA")) == 0);
    ASSERT_TRUE(localModel.roles().at(1).compare(QStringLiteral("roleB")) == 0);
    ASSERT_TRUE(localModel.roles().at(2).compare(QStringLiteral("roleC")) == 0);
}

TEST_F(Model, RolesAndJsonDataCtor)
{
    GreenHouse::Model localModel(
            { QStringLiteral("roleA"), QStringLiteral("roleB"), QStringLiteral("roleC") },
            QJsonArray({ QJsonObject({ { QStringLiteral("roleA"), QStringLiteral("value1") },
                                       { QStringLiteral("roleB"), 0 },
                                       { QStringLiteral("roleC"), false } }),
                         QJsonObject({ { QStringLiteral("roleA"), QStringLiteral("value2") },
                                       { QStringLiteral("roleB"), 1 },
                                       { QStringLiteral("roleC"), true } }),
                         QJsonObject({ { QStringLiteral("roleA"), QStringLiteral("value3") },
                                       { QStringLiteral("roleB"), 2 },
                                       { QStringLiteral("roleC"), false } }) }));
    ASSERT_EQ(localModel.rowCount(), 3);
    ASSERT_FALSE(localModel.dataAt(0).isEmpty());
    ASSERT_TRUE(localModel.dataAt(0)
                        .value(QStringLiteral("roleA"))
                        .toString()
                        .compare(QStringLiteral("value1"))
                == 0);
    ASSERT_TRUE(localModel.dataAt(1)
                        .value(QStringLiteral("roleA"))
                        .toString()
                        .compare(QStringLiteral("value2"))
                == 0);
    ASSERT_TRUE(localModel.dataAt(2)
                        .value(QStringLiteral("roleA"))
                        .toString()
                        .compare(QStringLiteral("value3"))
                == 0);
    ASSERT_TRUE(localModel.dataAt(0).value(QStringLiteral("roleB")).toInt() == 0);
    ASSERT_TRUE(localModel.dataAt(1).value(QStringLiteral("roleB")).toInt() == 1);
    ASSERT_TRUE(localModel.dataAt(2).value(QStringLiteral("roleB")).toInt() == 2);
    ASSERT_FALSE(localModel.dataAt(0).value(QStringLiteral("roleC")).toBool());
    ASSERT_TRUE(localModel.dataAt(1).value(QStringLiteral("roleC")).toBool());
    ASSERT_FALSE(localModel.dataAt(2).value(QStringLiteral("roleC")).toBool());
    ASSERT_EQ(localModel.roles().length(), 3);
    ASSERT_TRUE(localModel.roles().at(0).compare(QStringLiteral("roleA")) == 0);
    ASSERT_TRUE(localModel.roles().at(1).compare(QStringLiteral("roleB")) == 0);
    ASSERT_TRUE(localModel.roles().at(2).compare(QStringLiteral("roleC")) == 0);
}

TEST_F(Model, IsEmpty)
{
    ASSERT_EQ(model.rowCount(), 0);
    ASSERT_TRUE(model.dataAt(0).isEmpty());
    ASSERT_TRUE(model.roles().isEmpty());
}

TEST_F(Model, PopulateRoles)
{
    model.populate({ QStringLiteral("roleA"), QStringLiteral("roleB"), QStringLiteral("roleC") },
                   QJsonArray());
    ASSERT_EQ(model.rowCount(), 0);
    ASSERT_TRUE(model.dataAt(0).isEmpty());
    ASSERT_EQ(model.roles().length(), 3);
    ASSERT_TRUE(model.roles().at(0).compare(QStringLiteral("roleA")) == 0);
    ASSERT_TRUE(model.roles().at(1).compare(QStringLiteral("roleB")) == 0);
    ASSERT_TRUE(model.roles().at(2).compare(QStringLiteral("roleC")) == 0);
}

TEST_F(Model, PopulateData)
{
    model.populate(QJsonArray({ QJsonObject({ { QStringLiteral("roleA"), QStringLiteral("value1") },
                                              { QStringLiteral("roleB"), 0 },
                                              { QStringLiteral("roleC"), false } }),
                                QJsonObject({ { QStringLiteral("roleA"), QStringLiteral("value2") },
                                              { QStringLiteral("roleB"), 1 },
                                              { QStringLiteral("roleC"), true } }),
                                QJsonObject({ { QStringLiteral("roleA"), QStringLiteral("value3") },
                                              { QStringLiteral("roleB"), 2 },
                                              { QStringLiteral("roleC"), false } }) }));
    ASSERT_EQ(model.rowCount(), 3);
    ASSERT_FALSE(model.dataAt(0).isEmpty());
    ASSERT_TRUE(model.dataAt(0)
                        .value(QStringLiteral("roleA"))
                        .toString()
                        .compare(QStringLiteral("value1"))
                == 0);
    ASSERT_TRUE(model.dataAt(1)
                        .value(QStringLiteral("roleA"))
                        .toString()
                        .compare(QStringLiteral("value2"))
                == 0);
    ASSERT_TRUE(model.dataAt(2)
                        .value(QStringLiteral("roleA"))
                        .toString()
                        .compare(QStringLiteral("value3"))
                == 0);
    ASSERT_TRUE(model.dataAt(0).value(QStringLiteral("roleB")).toInt() == 0);
    ASSERT_TRUE(model.dataAt(1).value(QStringLiteral("roleB")).toInt() == 1);
    ASSERT_TRUE(model.dataAt(2).value(QStringLiteral("roleB")).toInt() == 2);
    ASSERT_FALSE(model.dataAt(0).value(QStringLiteral("roleC")).toBool());
    ASSERT_TRUE(model.dataAt(1).value(QStringLiteral("roleC")).toBool());
    ASSERT_FALSE(model.dataAt(2).value(QStringLiteral("roleC")).toBool());
    ASSERT_EQ(model.roles().length(), 3);
    ASSERT_TRUE(model.roles().at(0).compare(QStringLiteral("roleA")) == 0);
    ASSERT_TRUE(model.roles().at(1).compare(QStringLiteral("roleB")) == 0);
    ASSERT_TRUE(model.roles().at(2).compare(QStringLiteral("roleC")) == 0);
}

TEST_F(Model, PopulateFilteredData)
{
    model.setDataFilter([](const QJsonObject &rowData) -> bool {
        return rowData.value(QStringLiteral("roleC")).toBool();
    });
    model.populate(QJsonArray({ QJsonObject({ { QStringLiteral("roleA"), QStringLiteral("value1") },
                                              { QStringLiteral("roleB"), 0 },
                                              { QStringLiteral("roleC"), false } }),
                                QJsonObject({ { QStringLiteral("roleA"), QStringLiteral("value2") },
                                              { QStringLiteral("roleB"), 1 },
                                              { QStringLiteral("roleC"), true } }),
                                QJsonObject({ { QStringLiteral("roleA"), QStringLiteral("value3") },
                                              { QStringLiteral("roleB"), 2 },
                                              { QStringLiteral("roleC"), false } }) }));
    ASSERT_EQ(model.rowCount(), 1);
    ASSERT_FALSE(model.dataAt(0).isEmpty());
    ASSERT_TRUE(model.dataAt(0)
                        .value(QStringLiteral("roleA"))
                        .toString()
                        .compare(QStringLiteral("value2"))
                == 0);
    ASSERT_TRUE(model.dataAt(0).value(QStringLiteral("roleB")).toInt() == 1);
    ASSERT_TRUE(model.dataAt(0).value(QStringLiteral("roleC")).toBool());
    ASSERT_EQ(model.roles().length(), 3);
    ASSERT_TRUE(model.roles().at(0).compare(QStringLiteral("roleA")) == 0);
    ASSERT_TRUE(model.roles().at(1).compare(QStringLiteral("roleB")) == 0);
    ASSERT_TRUE(model.roles().at(2).compare(QStringLiteral("roleC")) == 0);
}

TEST_F(Model, PopulateRolesAndData)
{
    model.populate({ QStringLiteral("roleA"), QStringLiteral("roleB"), QStringLiteral("roleC") },
                   QJsonArray({ QJsonObject({ { QStringLiteral("roleA"), QStringLiteral("value1") },
                                              { QStringLiteral("roleB"), 0 },
                                              { QStringLiteral("roleC"), false } }),
                                QJsonObject({ { QStringLiteral("roleA"), QStringLiteral("value2") },
                                              { QStringLiteral("roleB"), 1 },
                                              { QStringLiteral("roleC"), true } }),
                                QJsonObject({ { QStringLiteral("roleA"), QStringLiteral("value3") },
                                              { QStringLiteral("roleB"), 2 },
                                              { QStringLiteral("roleC"), false } }) }));
    ASSERT_EQ(model.rowCount(), 3);
    ASSERT_FALSE(model.dataAt(0).isEmpty());
    ASSERT_TRUE(model.dataAt(0)
                        .value(QStringLiteral("roleA"))
                        .toString()
                        .compare(QStringLiteral("value1"))
                == 0);
    ASSERT_TRUE(model.dataAt(1)
                        .value(QStringLiteral("roleA"))
                        .toString()
                        .compare(QStringLiteral("value2"))
                == 0);
    ASSERT_TRUE(model.dataAt(2)
                        .value(QStringLiteral("roleA"))
                        .toString()
                        .compare(QStringLiteral("value3"))
                == 0);
    ASSERT_TRUE(model.dataAt(0).value(QStringLiteral("roleB")).toInt() == 0);
    ASSERT_TRUE(model.dataAt(1).value(QStringLiteral("roleB")).toInt() == 1);
    ASSERT_TRUE(model.dataAt(2).value(QStringLiteral("roleB")).toInt() == 2);
    ASSERT_FALSE(model.dataAt(0).value(QStringLiteral("roleC")).toBool());
    ASSERT_TRUE(model.dataAt(1).value(QStringLiteral("roleC")).toBool());
    ASSERT_FALSE(model.dataAt(2).value(QStringLiteral("roleC")).toBool());
    ASSERT_EQ(model.roles().length(), 3);
    ASSERT_TRUE(model.roles().at(0).compare(QStringLiteral("roleA")) == 0);
    ASSERT_TRUE(model.roles().at(1).compare(QStringLiteral("roleB")) == 0);
    ASSERT_TRUE(model.roles().at(2).compare(QStringLiteral("roleC")) == 0);
}

TEST_F(Model, PopulateFilteredRolesAndData)
{
    model.setDataFilter([](const QJsonObject &rowData) -> bool {
        return rowData.value(QStringLiteral("roleC")).toBool();
    });
    model.populate({ QStringLiteral("roleA"), QStringLiteral("roleB"), QStringLiteral("roleC") },
                   QJsonArray({ QJsonObject({ { QStringLiteral("roleA"), QStringLiteral("value1") },
                                              { QStringLiteral("roleB"), 0 },
                                              { QStringLiteral("roleC"), false } }),
                                QJsonObject({ { QStringLiteral("roleA"), QStringLiteral("value2") },
                                              { QStringLiteral("roleB"), 1 },
                                              { QStringLiteral("roleC"), true } }),
                                QJsonObject({ { QStringLiteral("roleA"), QStringLiteral("value3") },
                                              { QStringLiteral("roleB"), 2 },
                                              { QStringLiteral("roleC"), false } }) }));
    ASSERT_EQ(model.rowCount(), 1);
    ASSERT_FALSE(model.dataAt(0).isEmpty());
    ASSERT_TRUE(model.dataAt(0)
                        .value(QStringLiteral("roleA"))
                        .toString()
                        .compare(QStringLiteral("value2"))
                == 0);
    ASSERT_TRUE(model.dataAt(0).value(QStringLiteral("roleB")).toInt() == 1);
    ASSERT_TRUE(model.dataAt(0).value(QStringLiteral("roleC")).toBool());
    ASSERT_EQ(model.roles().length(), 3);
    ASSERT_TRUE(model.roles().at(0).compare(QStringLiteral("roleA")) == 0);
    ASSERT_TRUE(model.roles().at(1).compare(QStringLiteral("roleB")) == 0);
    ASSERT_TRUE(model.roles().at(2).compare(QStringLiteral("roleC")) == 0);
}

TEST_F(Model, AppendRow)
{
    model.populate({ QStringLiteral("roleA"), QStringLiteral("roleB"), QStringLiteral("roleC") },
                   QJsonArray());
    ASSERT_EQ(model.rowCount(), 0);
    ASSERT_TRUE(model.dataAt(0).isEmpty());

    model.appendRow(QJsonObject({ { QStringLiteral("roleA"), QStringLiteral("value1") },
                                  { QStringLiteral("roleB"), 0 },
                                  { QStringLiteral("roleC"), false } }));
    ASSERT_EQ(model.rowCount(), 1);
    ASSERT_FALSE(model.dataAt(0).isEmpty());
    ASSERT_TRUE(model.dataAt(0)
                        .value(QStringLiteral("roleA"))
                        .toString()
                        .compare(QStringLiteral("value1"))
                == 0);
    ASSERT_TRUE(model.dataAt(0).value(QStringLiteral("roleB")).toInt() == 0);
    ASSERT_TRUE(model.dataAt(0).value(QStringLiteral("roleC")).toBool() == false);

    model.appendRow(QJsonObject({ { QStringLiteral("roleA"), QStringLiteral("value2") },
                                  { QStringLiteral("roleB"), 1 },
                                  { QStringLiteral("roleC"), true } }));
    ASSERT_EQ(model.rowCount(), 2);
    ASSERT_FALSE(model.dataAt(1).isEmpty());
    ASSERT_TRUE(model.dataAt(1)
                        .value(QStringLiteral("roleA"))
                        .toString()
                        .compare(QStringLiteral("value2"))
                == 0);
    ASSERT_TRUE(model.dataAt(1).value(QStringLiteral("roleB")).toInt() == 1);
    ASSERT_TRUE(model.dataAt(1).value(QStringLiteral("roleC")).toBool());

    model.appendRow(QJsonObject({ { QStringLiteral("roleA"), QStringLiteral("value3") },
                                  { QStringLiteral("roleB"), 2 },
                                  { QStringLiteral("roleC"), false } }));
    ASSERT_EQ(model.rowCount(), 3);
    ASSERT_FALSE(model.dataAt(2).isEmpty());
    ASSERT_TRUE(model.dataAt(2)
                        .value(QStringLiteral("roleA"))
                        .toString()
                        .compare(QStringLiteral("value3"))
                == 0);
    ASSERT_TRUE(model.dataAt(2).value(QStringLiteral("roleB")).toInt() == 2);
    ASSERT_FALSE(model.dataAt(2).value(QStringLiteral("roleC")).toBool());
}

TEST_F(Model, AppendRowFiltered)
{
    model.setDataFilter([](const QJsonObject &rowData) -> bool {
        return rowData.value(QStringLiteral("roleC")).toBool();
    });
    model.populate({ QStringLiteral("roleA"), QStringLiteral("roleB"), QStringLiteral("roleC") },
                   QJsonArray());
    ASSERT_EQ(model.rowCount(), 0);
    ASSERT_TRUE(model.dataAt(0).isEmpty());

    model.appendRow(QJsonObject({ { QStringLiteral("roleA"), QStringLiteral("value1") },
                                  { QStringLiteral("roleB"), 0 },
                                  { QStringLiteral("roleC"), false } }));
    ASSERT_EQ(model.rowCount(), 0);

    model.appendRow(QJsonObject({ { QStringLiteral("roleA"), QStringLiteral("value2") },
                                  { QStringLiteral("roleB"), 1 },
                                  { QStringLiteral("roleC"), true } }));
    ASSERT_EQ(model.rowCount(), 1);
    ASSERT_FALSE(model.dataAt(0).isEmpty());
    ASSERT_TRUE(model.dataAt(0)
                        .value(QStringLiteral("roleA"))
                        .toString()
                        .compare(QStringLiteral("value2"))
                == 0);
    ASSERT_TRUE(model.dataAt(0).value(QStringLiteral("roleB")).toInt() == 1);
    ASSERT_TRUE(model.dataAt(0).value(QStringLiteral("roleC")).toBool());

    model.appendRow(QJsonObject({ { QStringLiteral("roleA"), QStringLiteral("value3") },
                                  { QStringLiteral("roleB"), 2 },
                                  { QStringLiteral("roleC"), false } }));
    ASSERT_EQ(model.rowCount(), 1);
}

TEST_F(Model, RemoveRow)
{
    model.populate({ QStringLiteral("roleA"), QStringLiteral("roleB"), QStringLiteral("roleC") },
                   QJsonArray({ QJsonObject({ { QStringLiteral("roleA"), QStringLiteral("value1") },
                                              { QStringLiteral("roleB"), 0 },
                                              { QStringLiteral("roleC"), false } }),
                                QJsonObject({ { QStringLiteral("roleA"), QStringLiteral("value2") },
                                              { QStringLiteral("roleB"), 1 },
                                              { QStringLiteral("roleC"), true } }),
                                QJsonObject({ { QStringLiteral("roleA"), QStringLiteral("value3") },
                                              { QStringLiteral("roleB"), 2 },
                                              { QStringLiteral("roleC"), false } }) }));
    model.removeRow(-1);
    ASSERT_EQ(model.rowCount(), 3);

    model.removeRow(3);
    ASSERT_EQ(model.rowCount(), 3);

    model.removeRow(0);
    ASSERT_EQ(model.rowCount(), 2);
    ASSERT_TRUE(model.dataAt(0)
                        .value(QStringLiteral("roleA"))
                        .toString()
                        .compare(QStringLiteral("value2"))
                == 0);
    ASSERT_TRUE(model.dataAt(0).value(QStringLiteral("roleB")).toInt() == 1);
    ASSERT_TRUE(model.dataAt(0).value(QStringLiteral("roleC")).toBool());
    ASSERT_TRUE(model.dataAt(1)
                        .value(QStringLiteral("roleA"))
                        .toString()
                        .compare(QStringLiteral("value3"))
                == 0);
    ASSERT_TRUE(model.dataAt(1).value(QStringLiteral("roleB")).toInt() == 2);
    ASSERT_FALSE(model.dataAt(1).value(QStringLiteral("roleC")).toBool());

    model.removeRow(1);
    ASSERT_EQ(model.rowCount(), 1);
    ASSERT_TRUE(model.dataAt(0)
                        .value(QStringLiteral("roleA"))
                        .toString()
                        .compare(QStringLiteral("value2"))
                == 0);
    ASSERT_TRUE(model.dataAt(0).value(QStringLiteral("roleB")).toInt() == 1);
    ASSERT_TRUE(model.dataAt(0).value(QStringLiteral("roleC")).toBool());

    model.removeRow(1);
    ASSERT_EQ(model.rowCount(), 1);
    ASSERT_TRUE(model.dataAt(0)
                        .value(QStringLiteral("roleA"))
                        .toString()
                        .compare(QStringLiteral("value2"))
                == 0);
    ASSERT_TRUE(model.dataAt(0).value(QStringLiteral("roleB")).toInt() == 1);
    ASSERT_TRUE(model.dataAt(0).value(QStringLiteral("roleC")).toBool());

    model.removeRow(0);
    ASSERT_EQ(model.rowCount(), 0);
}

TEST_F(Model, RemoveFilteredRow)
{
    model.setDataFilter([](const QJsonObject &rowData) -> bool {
        return rowData.value(QStringLiteral("roleC")).toBool();
    });
    model.populate({ QStringLiteral("roleA"), QStringLiteral("roleB"), QStringLiteral("roleC") },
                   QJsonArray({ QJsonObject({ { QStringLiteral("roleA"), QStringLiteral("value1") },
                                              { QStringLiteral("roleB"), 0 },
                                              { QStringLiteral("roleC"), false } }),
                                QJsonObject({ { QStringLiteral("roleA"), QStringLiteral("value2") },
                                              { QStringLiteral("roleB"), 1 },
                                              { QStringLiteral("roleC"), true } }),
                                QJsonObject({ { QStringLiteral("roleA"), QStringLiteral("value3") },
                                              { QStringLiteral("roleB"), 2 },
                                              { QStringLiteral("roleC"), false } }) }));
    model.removeRow(-1);
    ASSERT_EQ(model.rowCount(), 1);

    model.removeRow(3);
    ASSERT_EQ(model.rowCount(), 1);

    model.removeRow(0);
    ASSERT_EQ(model.rowCount(), 0);

    model.clearDataFilter();
    model.removeRow(0);
    ASSERT_EQ(model.rowCount(), 1);
    ASSERT_TRUE(model.dataAt(0)
                        .value(QStringLiteral("roleA"))
                        .toString()
                        .compare(QStringLiteral("value3"))
                == 0);
    ASSERT_TRUE(model.dataAt(0).value(QStringLiteral("roleB")).toInt() == 2);
    ASSERT_FALSE(model.dataAt(0).value(QStringLiteral("roleC")).toBool());

    model.removeRow(0);
    ASSERT_EQ(model.rowCount(), 0);
}

TEST_F(Model, setRowData)
{
    model.populate({ QStringLiteral("roleA"), QStringLiteral("roleB"), QStringLiteral("roleC") },
                   QJsonArray({ QJsonObject({ { QStringLiteral("roleA"), QStringLiteral("value1") },
                                              { QStringLiteral("roleB"), 0 },
                                              { QStringLiteral("roleC"), false } }),
                                QJsonObject({ { QStringLiteral("roleA"), QStringLiteral("value2") },
                                              { QStringLiteral("roleB"), 1 },
                                              { QStringLiteral("roleC"), true } }),
                                QJsonObject({ { QStringLiteral("roleA"), QStringLiteral("value3") },
                                              { QStringLiteral("roleB"), 2 },
                                              { QStringLiteral("roleC"), false } }) }));

    ASSERT_FALSE(model.setRowData(-1, QJsonObject()));
    ASSERT_EQ(model.rowCount(), 3);
    ASSERT_TRUE(model.dataAt(0)
                        .value(QStringLiteral("roleA"))
                        .toString()
                        .compare(QStringLiteral("value1"))
                == 0);
    ASSERT_TRUE(model.dataAt(1)
                        .value(QStringLiteral("roleA"))
                        .toString()
                        .compare(QStringLiteral("value2"))
                == 0);
    ASSERT_TRUE(model.dataAt(2)
                        .value(QStringLiteral("roleA"))
                        .toString()
                        .compare(QStringLiteral("value3"))
                == 0);
    ASSERT_TRUE(model.dataAt(0).value(QStringLiteral("roleB")).toInt() == 0);
    ASSERT_TRUE(model.dataAt(1).value(QStringLiteral("roleB")).toInt() == 1);
    ASSERT_TRUE(model.dataAt(2).value(QStringLiteral("roleB")).toInt() == 2);
    ASSERT_FALSE(model.dataAt(0).value(QStringLiteral("roleC")).toBool());
    ASSERT_TRUE(model.dataAt(1).value(QStringLiteral("roleC")).toBool());
    ASSERT_FALSE(model.dataAt(2).value(QStringLiteral("roleC")).toBool());

    ASSERT_FALSE(model.setRowData(3, QJsonObject()));
    ASSERT_EQ(model.rowCount(), 3);
    ASSERT_TRUE(model.dataAt(0)
                        .value(QStringLiteral("roleA"))
                        .toString()
                        .compare(QStringLiteral("value1"))
                == 0);
    ASSERT_TRUE(model.dataAt(1)
                        .value(QStringLiteral("roleA"))
                        .toString()
                        .compare(QStringLiteral("value2"))
                == 0);
    ASSERT_TRUE(model.dataAt(2)
                        .value(QStringLiteral("roleA"))
                        .toString()
                        .compare(QStringLiteral("value3"))
                == 0);
    ASSERT_TRUE(model.dataAt(0).value(QStringLiteral("roleB")).toInt() == 0);
    ASSERT_TRUE(model.dataAt(1).value(QStringLiteral("roleB")).toInt() == 1);
    ASSERT_TRUE(model.dataAt(2).value(QStringLiteral("roleB")).toInt() == 2);
    ASSERT_FALSE(model.dataAt(0).value(QStringLiteral("roleC")).toBool());
    ASSERT_TRUE(model.dataAt(1).value(QStringLiteral("roleC")).toBool());
    ASSERT_FALSE(model.dataAt(2).value(QStringLiteral("roleC")).toBool());

    ASSERT_TRUE(
            model.setRowData(0,
                             QJsonObject({ { QStringLiteral("roleA"), QStringLiteral("value4") },
                                           { QStringLiteral("roleB"), 3 },
                                           { QStringLiteral("roleC"), true } })));
    ASSERT_EQ(model.rowCount(), 3);
    ASSERT_TRUE(model.dataAt(0)
                        .value(QStringLiteral("roleA"))
                        .toString()
                        .compare(QStringLiteral("value4"))
                == 0);
    ASSERT_TRUE(model.dataAt(1)
                        .value(QStringLiteral("roleA"))
                        .toString()
                        .compare(QStringLiteral("value2"))
                == 0);
    ASSERT_TRUE(model.dataAt(2)
                        .value(QStringLiteral("roleA"))
                        .toString()
                        .compare(QStringLiteral("value3"))
                == 0);
    ASSERT_TRUE(model.dataAt(0).value(QStringLiteral("roleB")).toInt() == 3);
    ASSERT_TRUE(model.dataAt(1).value(QStringLiteral("roleB")).toInt() == 1);
    ASSERT_TRUE(model.dataAt(2).value(QStringLiteral("roleB")).toInt() == 2);
    ASSERT_TRUE(model.dataAt(0).value(QStringLiteral("roleC")).toBool());
    ASSERT_TRUE(model.dataAt(1).value(QStringLiteral("roleC")).toBool());
    ASSERT_FALSE(model.dataAt(2).value(QStringLiteral("roleC")).toBool());

    ASSERT_TRUE(
            model.setRowData(1,
                             QJsonObject({ { QStringLiteral("roleA"), QStringLiteral("value5") },
                                           { QStringLiteral("roleB"), 4 },
                                           { QStringLiteral("roleC"), false } })));
    ASSERT_EQ(model.rowCount(), 3);
    ASSERT_TRUE(model.dataAt(0)
                        .value(QStringLiteral("roleA"))
                        .toString()
                        .compare(QStringLiteral("value4"))
                == 0);
    ASSERT_TRUE(model.dataAt(1)
                        .value(QStringLiteral("roleA"))
                        .toString()
                        .compare(QStringLiteral("value5"))
                == 0);
    ASSERT_TRUE(model.dataAt(2)
                        .value(QStringLiteral("roleA"))
                        .toString()
                        .compare(QStringLiteral("value3"))
                == 0);
    ASSERT_TRUE(model.dataAt(0).value(QStringLiteral("roleB")).toInt() == 3);
    ASSERT_TRUE(model.dataAt(1).value(QStringLiteral("roleB")).toInt() == 4);
    ASSERT_TRUE(model.dataAt(2).value(QStringLiteral("roleB")).toInt() == 2);
    ASSERT_TRUE(model.dataAt(0).value(QStringLiteral("roleC")).toBool());
    ASSERT_FALSE(model.dataAt(1).value(QStringLiteral("roleC")).toBool());
    ASSERT_FALSE(model.dataAt(2).value(QStringLiteral("roleC")).toBool());

    ASSERT_TRUE(
            model.setRowData(2,
                             QJsonObject({ { QStringLiteral("roleA"), QStringLiteral("value6") },
                                           { QStringLiteral("roleB"), 5 },
                                           { QStringLiteral("roleC"), true } })));
    ASSERT_EQ(model.rowCount(), 3);
    ASSERT_TRUE(model.dataAt(0)
                        .value(QStringLiteral("roleA"))
                        .toString()
                        .compare(QStringLiteral("value4"))
                == 0);
    ASSERT_TRUE(model.dataAt(1)
                        .value(QStringLiteral("roleA"))
                        .toString()
                        .compare(QStringLiteral("value5"))
                == 0);
    ASSERT_TRUE(model.dataAt(2)
                        .value(QStringLiteral("roleA"))
                        .toString()
                        .compare(QStringLiteral("value6"))
                == 0);
    ASSERT_TRUE(model.dataAt(0).value(QStringLiteral("roleB")).toInt() == 3);
    ASSERT_TRUE(model.dataAt(1).value(QStringLiteral("roleB")).toInt() == 4);
    ASSERT_TRUE(model.dataAt(2).value(QStringLiteral("roleB")).toInt() == 5);
    ASSERT_TRUE(model.dataAt(0).value(QStringLiteral("roleC")).toBool());
    ASSERT_FALSE(model.dataAt(1).value(QStringLiteral("roleC")).toBool());
    ASSERT_TRUE(model.dataAt(2).value(QStringLiteral("roleC")).toBool());
}

TEST_F(Model, setRowDataFiltered)
{
    model.setDataFilter([](const QJsonObject &rowData) -> bool {
        return rowData.value(QStringLiteral("roleC")).toBool();
    });
    model.populate({ QStringLiteral("roleA"), QStringLiteral("roleB"), QStringLiteral("roleC") },
                   QJsonArray({ QJsonObject({ { QStringLiteral("roleA"), QStringLiteral("value1") },
                                              { QStringLiteral("roleB"), 0 },
                                              { QStringLiteral("roleC"), false } }),
                                QJsonObject({ { QStringLiteral("roleA"), QStringLiteral("value2") },
                                              { QStringLiteral("roleB"), 1 },
                                              { QStringLiteral("roleC"), true } }),
                                QJsonObject({ { QStringLiteral("roleA"), QStringLiteral("value3") },
                                              { QStringLiteral("roleB"), 2 },
                                              { QStringLiteral("roleC"), false } }) }));

    ASSERT_FALSE(model.setRowData(-1, QJsonObject()));
    ASSERT_EQ(model.rowCount(), 1);
    ASSERT_TRUE(model.dataAt(0)
                        .value(QStringLiteral("roleA"))
                        .toString()
                        .compare(QStringLiteral("value2"))
                == 0);
    ASSERT_TRUE(model.dataAt(0).value(QStringLiteral("roleB")).toInt() == 1);
    ASSERT_TRUE(model.dataAt(0).value(QStringLiteral("roleC")).toBool());

    ASSERT_FALSE(model.setRowData(2, QJsonObject()));
    ASSERT_EQ(model.rowCount(), 1);
    ASSERT_TRUE(model.dataAt(0)
                        .value(QStringLiteral("roleA"))
                        .toString()
                        .compare(QStringLiteral("value2"))
                == 0);
    ASSERT_TRUE(model.dataAt(0).value(QStringLiteral("roleB")).toInt() == 1);
    ASSERT_TRUE(model.dataAt(0).value(QStringLiteral("roleC")).toBool());

    ASSERT_TRUE(
            model.setRowData(0,
                             QJsonObject({ { QStringLiteral("roleA"), QStringLiteral("value4") },
                                           { QStringLiteral("roleB"), 3 },
                                           { QStringLiteral("roleC"), true } })));
    ASSERT_EQ(model.rowCount(), 1);
    ASSERT_TRUE(model.dataAt(0)
                        .value(QStringLiteral("roleA"))
                        .toString()
                        .compare(QStringLiteral("value4"))
                == 0);
    ASSERT_TRUE(model.dataAt(0).value(QStringLiteral("roleB")).toInt() == 3);
    ASSERT_TRUE(model.dataAt(0).value(QStringLiteral("roleC")).toBool());

    ASSERT_TRUE(
            model.setRowData(0,
                             QJsonObject({ { QStringLiteral("roleA"), QStringLiteral("value4") },
                                           { QStringLiteral("roleB"), 3 },
                                           { QStringLiteral("roleC"), false } })));
    ASSERT_EQ(model.rowCount(), 0);

    model.clearDataFilter();
    ASSERT_EQ(model.rowCount(), 3);
}

TEST_F(Model, SortData)
{
    model.populate({ QStringLiteral("roleA"), QStringLiteral("roleB"), QStringLiteral("roleC") },
                   QJsonArray({ QJsonObject({ { QStringLiteral("roleA"), QStringLiteral("value1") },
                                              { QStringLiteral("roleB"), 0 },
                                              { QStringLiteral("roleC"), false } }),
                                QJsonObject({ { QStringLiteral("roleA"), QStringLiteral("value2") },
                                              { QStringLiteral("roleB"), 1 },
                                              { QStringLiteral("roleC"), true } }),
                                QJsonObject({ { QStringLiteral("roleA"), QStringLiteral("value3") },
                                              { QStringLiteral("roleB"), 2 },
                                              { QStringLiteral("roleC"), false } }) }));
    ASSERT_EQ(model.rowCount(), 3);
    ASSERT_TRUE(model.dataAt(0)
                        .value(QStringLiteral("roleA"))
                        .toString()
                        .compare(QStringLiteral("value1"))
                == 0);
    ASSERT_TRUE(model.dataAt(1)
                        .value(QStringLiteral("roleA"))
                        .toString()
                        .compare(QStringLiteral("value2"))
                == 0);
    ASSERT_TRUE(model.dataAt(2)
                        .value(QStringLiteral("roleA"))
                        .toString()
                        .compare(QStringLiteral("value3"))
                == 0);
    ASSERT_TRUE(model.dataAt(0).value(QStringLiteral("roleB")).toInt() == 0);
    ASSERT_TRUE(model.dataAt(1).value(QStringLiteral("roleB")).toInt() == 1);
    ASSERT_TRUE(model.dataAt(2).value(QStringLiteral("roleB")).toInt() == 2);
    ASSERT_FALSE(model.dataAt(0).value(QStringLiteral("roleC")).toBool());
    ASSERT_TRUE(model.dataAt(1).value(QStringLiteral("roleC")).toBool());
    ASSERT_FALSE(model.dataAt(2).value(QStringLiteral("roleC")).toBool());

    model.sortData([](const QJsonValue &a, const QJsonValue &b) -> bool {
        const QJsonObject aObj = a.toObject();
        const QJsonObject bObj = b.toObject();
        return aObj.value(QStringLiteral("roleB")).toInt()
                > bObj.value(QStringLiteral("roleB")).toInt();
    });
    ASSERT_EQ(model.rowCount(), 3);
    ASSERT_TRUE(model.dataAt(2)
                        .value(QStringLiteral("roleA"))
                        .toString()
                        .compare(QStringLiteral("value1"))
                == 0);
    ASSERT_TRUE(model.dataAt(1)
                        .value(QStringLiteral("roleA"))
                        .toString()
                        .compare(QStringLiteral("value2"))
                == 0);
    ASSERT_TRUE(model.dataAt(0)
                        .value(QStringLiteral("roleA"))
                        .toString()
                        .compare(QStringLiteral("value3"))
                == 0);
    ASSERT_TRUE(model.dataAt(2).value(QStringLiteral("roleB")).toInt() == 0);
    ASSERT_TRUE(model.dataAt(1).value(QStringLiteral("roleB")).toInt() == 1);
    ASSERT_TRUE(model.dataAt(0).value(QStringLiteral("roleB")).toInt() == 2);
    ASSERT_FALSE(model.dataAt(2).value(QStringLiteral("roleC")).toBool());
    ASSERT_TRUE(model.dataAt(1).value(QStringLiteral("roleC")).toBool());
    ASSERT_FALSE(model.dataAt(0).value(QStringLiteral("roleC")).toBool());
}

TEST_F(Model, RoleNames)
{
    model.populate({ QStringLiteral("roleA"), QStringLiteral("roleB"), QStringLiteral("roleC") },
                   QJsonArray());
    ASSERT_EQ(model.roles().length(), 3);
    ASSERT_TRUE(model.roles().at(0).compare(QStringLiteral("roleA")) == 0);
    ASSERT_TRUE(model.roles().at(1).compare(QStringLiteral("roleB")) == 0);
    ASSERT_TRUE(model.roles().at(2).compare(QStringLiteral("roleC")) == 0);

    const auto roleNames = model.roleNames();
    ASSERT_EQ(roleNames.count(), 3);
    ASSERT_TRUE(roleNames.value(Qt::UserRole + 0) == QByteArray("roleA"));
    ASSERT_TRUE(roleNames.value(Qt::UserRole + 1) == QByteArray("roleB"));
    ASSERT_TRUE(roleNames.value(Qt::UserRole + 2) == QByteArray("roleC"));
}

TEST_F(Model, Data)
{
    model.populate({ QStringLiteral("roleA"), QStringLiteral("roleB"), QStringLiteral("roleC") },
                   QJsonArray({ QJsonObject({ { QStringLiteral("roleA"), QStringLiteral("value1") },
                                              { QStringLiteral("roleB"), 0 },
                                              { QStringLiteral("roleC"), false } }),
                                QJsonObject({ { QStringLiteral("roleA"), QStringLiteral("value2") },
                                              { QStringLiteral("roleB"), 1 },
                                              { QStringLiteral("roleC"), true } }),
                                QJsonObject({ { QStringLiteral("roleA"), QStringLiteral("value3") },
                                              { QStringLiteral("roleB"), 2 },
                                              { QStringLiteral("roleC"), false } }) }));
    ASSERT_TRUE(
            model.data(model.index(0), Qt::UserRole).toString().compare(QStringLiteral("value1"))
            == 0);
    ASSERT_EQ(model.data(model.index(0), Qt::UserRole + 1).toInt(), 0);
    ASSERT_FALSE(model.data(model.index(0), Qt::UserRole + 2).toBool());
    ASSERT_TRUE(model.data(model.index(0), Qt::UserRole + 3).isNull());
    ASSERT_TRUE(
            model.data(model.index(1), Qt::UserRole).toString().compare(QStringLiteral("value2"))
            == 0);
    ASSERT_EQ(model.data(model.index(1), Qt::UserRole + 1).toInt(), 1);
    ASSERT_TRUE(model.data(model.index(1), Qt::UserRole + 2).toBool());
    ASSERT_TRUE(model.data(model.index(1), Qt::UserRole + 3).isNull());
    ASSERT_TRUE(
            model.data(model.index(2), Qt::UserRole).toString().compare(QStringLiteral("value3"))
            == 0);
    ASSERT_EQ(model.data(model.index(2), Qt::UserRole + 1).toInt(), 2);
    ASSERT_FALSE(model.data(model.index(2), Qt::UserRole + 2).toBool());
    ASSERT_TRUE(model.data(model.index(2), Qt::UserRole + 3).isNull());
}

TEST_F(Model, DataFiltered)
{
    model.setDataFilter([](const QJsonObject &rowData) -> bool {
        return rowData.value(QStringLiteral("roleC")).toBool();
    });
    model.populate({ QStringLiteral("roleA"), QStringLiteral("roleB"), QStringLiteral("roleC") },
                   QJsonArray({ QJsonObject({ { QStringLiteral("roleA"), QStringLiteral("value1") },
                                              { QStringLiteral("roleB"), 0 },
                                              { QStringLiteral("roleC"), false } }),
                                QJsonObject({ { QStringLiteral("roleA"), QStringLiteral("value2") },
                                              { QStringLiteral("roleB"), 1 },
                                              { QStringLiteral("roleC"), true } }),
                                QJsonObject({ { QStringLiteral("roleA"), QStringLiteral("value3") },
                                              { QStringLiteral("roleB"), 2 },
                                              { QStringLiteral("roleC"), false } }) }));

    ASSERT_TRUE(
            model.data(model.index(0), Qt::UserRole).toString().compare(QStringLiteral("value2"))
            == 0);
    ASSERT_EQ(model.data(model.index(0), Qt::UserRole + 1).toInt(), 1);
    ASSERT_TRUE(model.data(model.index(0), Qt::UserRole + 2).toBool());
    ASSERT_TRUE(model.data(model.index(0), Qt::UserRole + 3).isNull());
}

TEST_F(Model, DataFilteredPostPopulate)
{
    model.populate({ QStringLiteral("roleA"), QStringLiteral("roleB"), QStringLiteral("roleC") },
                   QJsonArray({ QJsonObject({ { QStringLiteral("roleA"), QStringLiteral("value1") },
                                              { QStringLiteral("roleB"), 0 },
                                              { QStringLiteral("roleC"), false } }),
                                QJsonObject({ { QStringLiteral("roleA"), QStringLiteral("value2") },
                                              { QStringLiteral("roleB"), 1 },
                                              { QStringLiteral("roleC"), true } }),
                                QJsonObject({ { QStringLiteral("roleA"), QStringLiteral("value3") },
                                              { QStringLiteral("roleB"), 2 },
                                              { QStringLiteral("roleC"), false } }) }));

    model.setDataFilter([](const QJsonObject &rowData) -> bool {
        return rowData.value(QStringLiteral("roleC")).toBool();
    });
    ASSERT_TRUE(
            model.data(model.index(0), Qt::UserRole).toString().compare(QStringLiteral("value2"))
            == 0);
    ASSERT_EQ(model.data(model.index(0), Qt::UserRole + 1).toInt(), 1);
    ASSERT_TRUE(model.data(model.index(0), Qt::UserRole + 2).toBool());
    ASSERT_TRUE(model.data(model.index(0), Qt::UserRole + 3).isNull());
}
