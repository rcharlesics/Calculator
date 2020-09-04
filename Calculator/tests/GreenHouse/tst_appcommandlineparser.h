#pragma once

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

#include <QStringList>
#include <QCoreApplication>

#include <appcommandlineparser.h>

using namespace testing;

class AppCommandLineParserTest : public Test
{
    // Test interface
protected:
    void SetUp();
    void TearDown();

    QStringList appArgs;
};

void AppCommandLineParserTest::SetUp()
{
    appArgs = qApp->arguments();
}

void AppCommandLineParserTest::TearDown() { }

TEST_F(AppCommandLineParserTest, InitializedContextExecutionStart)
{
    AppCommandLineParser parserA(appArgs);
    AppCommandLineParser parserB(appArgs);

    ASSERT_TRUE(parserA.loggingFilters() == parserB.loggingFilters());
    ASSERT_TRUE(parserA.pluginPath() == parserB.pluginPath());
    ASSERT_TRUE(parserA.backendPort() == parserB.backendPort());
    ASSERT_TRUE(parserA.backendUrl() == parserB.backendUrl());
    ASSERT_TRUE(parserA.simulator() == parserB.simulator());
    ASSERT_TRUE(parserA.simulatorPort() == parserB.simulatorPort());
    ASSERT_TRUE(parserA.simulatorUrl() == parserB.simulatorUrl());
}

TEST_F(AppCommandLineParserTest, PluginDirOption)
{
    QStringList args = appArgs;
    args.append({ QStringLiteral("--pluginDir"), QStringLiteral("/test/dir") });
    AppCommandLineParser parserA(args);
    AppCommandLineParser parserB(appArgs);

    ASSERT_TRUE(parserA.pluginPath() != parserB.pluginPath());
    ASSERT_TRUE(parserA.pluginPath() == QStringLiteral("/test/dir"));

    ASSERT_TRUE(parserA.loggingFilters() == parserB.loggingFilters());
    ASSERT_TRUE(parserA.backendPort() == parserB.backendPort());
    ASSERT_TRUE(parserA.backendUrl() == parserB.backendUrl());
    ASSERT_TRUE(parserA.simulator() == parserB.simulator());
    ASSERT_TRUE(parserA.simulatorPort() == parserB.simulatorPort());
    ASSERT_TRUE(parserA.simulatorUrl() == parserB.simulatorUrl());
}

TEST_F(AppCommandLineParserTest, BackedPortOption)
{
    QStringList args = appArgs;
    args.append({ QStringLiteral("--backendPort"), QStringLiteral("8080") });
    AppCommandLineParser parserA(args);
    AppCommandLineParser parserB(appArgs);

    ASSERT_TRUE(parserA.backendPort() != parserB.backendPort());
    ASSERT_TRUE(parserA.backendPort() == 8080);

    ASSERT_TRUE(parserA.loggingFilters() == parserB.loggingFilters());
    ASSERT_TRUE(parserA.pluginPath() == parserB.pluginPath());
    ASSERT_TRUE(parserA.backendUrl() == parserB.backendUrl());
    ASSERT_TRUE(parserA.simulator() == parserB.simulator());
    ASSERT_TRUE(parserA.simulatorPort() == parserB.simulatorPort());
    ASSERT_TRUE(parserA.simulatorUrl() == parserB.simulatorUrl());
}

TEST_F(AppCommandLineParserTest, BackedUrlOption)
{
    QStringList args = appArgs;
    args.append({ QStringLiteral("--backendUrl"), QStringLiteral("http://dummmy") });
    AppCommandLineParser parserA(args);
    AppCommandLineParser parserB(appArgs);

    ASSERT_TRUE(parserA.backendUrl() != parserB.backendUrl());
    ASSERT_TRUE(parserA.backendUrl() == QStringLiteral("http://dummmy"));

    ASSERT_TRUE(parserA.loggingFilters() == parserB.loggingFilters());
    ASSERT_TRUE(parserA.pluginPath() == parserB.pluginPath());
    ASSERT_TRUE(parserA.backendPort() == parserB.backendPort());
    ASSERT_TRUE(parserA.simulator() == parserB.simulator());
    ASSERT_TRUE(parserA.simulatorPort() == parserB.simulatorPort());
    ASSERT_TRUE(parserA.simulatorUrl() == parserB.simulatorUrl());
}

TEST_F(AppCommandLineParserTest, SimulatorOption)
{
    QStringList args = appArgs;
    args.append({ QStringLiteral("--simulator") });
    AppCommandLineParser parserA(args);
    AppCommandLineParser parserB(appArgs);

    ASSERT_TRUE(parserA.simulator() != parserB.simulator());
    ASSERT_TRUE(parserA.simulator());

    ASSERT_TRUE(parserA.loggingFilters() == parserB.loggingFilters());
    ASSERT_TRUE(parserA.pluginPath() == parserB.pluginPath());
    ASSERT_TRUE(parserA.backendPort() == parserB.backendPort());
    ASSERT_TRUE(parserA.backendUrl() == parserB.backendUrl());
    ASSERT_TRUE(parserA.simulatorPort() == parserB.simulatorPort());
    ASSERT_TRUE(parserA.simulatorUrl() == parserB.simulatorUrl());
}

TEST_F(AppCommandLineParserTest, SimulatorPortOption)
{
    QStringList args = appArgs;
    args.append({ QStringLiteral("--simulatorPort"), QStringLiteral("8080") });
    AppCommandLineParser parserA(args);
    AppCommandLineParser parserB(appArgs);

    ASSERT_TRUE(parserA.simulatorPort() != parserB.simulatorPort());
    ASSERT_TRUE(parserA.simulatorPort() == 8080);

    ASSERT_TRUE(parserA.loggingFilters() == parserB.loggingFilters());
    ASSERT_TRUE(parserA.pluginPath() == parserB.pluginPath());
    ASSERT_TRUE(parserA.backendPort() == parserB.backendPort());
    ASSERT_TRUE(parserA.backendUrl() == parserB.backendUrl());
    ASSERT_TRUE(parserA.simulator() == parserB.simulator());
    ASSERT_TRUE(parserA.simulatorUrl() == parserB.simulatorUrl());
}

TEST_F(AppCommandLineParserTest, SimulatorUrlOption)
{
    QStringList args = appArgs;
    args.append({ QStringLiteral("--simulatorUrl"), QStringLiteral("http://dummmy") });
    AppCommandLineParser parserA(args);
    AppCommandLineParser parserB(appArgs);

    ASSERT_TRUE(parserA.simulatorUrl() != parserB.simulatorUrl());
    ASSERT_TRUE(parserA.simulatorUrl() == QStringLiteral("http://dummmy"));

    ASSERT_TRUE(parserA.loggingFilters() == parserB.loggingFilters());
    ASSERT_TRUE(parserA.pluginPath() == parserB.pluginPath());
    ASSERT_TRUE(parserA.backendPort() == parserB.backendPort());
    ASSERT_TRUE(parserA.backendUrl() == parserB.backendUrl());
    ASSERT_TRUE(parserA.simulator() == parserB.simulator());
    ASSERT_TRUE(parserA.simulatorPort() == parserB.simulatorPort());
}
