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

TEST_F(AppCommandLineParserTest, PluginDirOption)
{
    const QString defaultPluginPath = AppCommandLineParser::pluginPath();
    QStringList args = appArgs;
    args.append({ QStringLiteral("--pluginDir"), QStringLiteral("/test/dir") });
    AppCommandLineParser parserA(args);

    ASSERT_TRUE(parserA.pluginPath() != defaultPluginPath);
    ASSERT_TRUE(parserA.pluginPath() == QStringLiteral("/test/dir"));
}

TEST_F(AppCommandLineParserTest, BackedPortOption)
{
    const quint16 defaultPort = AppCommandLineParser::backendPort();
    QStringList args = appArgs;
    args.append({ QStringLiteral("--backendPort"), QStringLiteral("8080") });
    AppCommandLineParser parserA(args);

    ASSERT_TRUE(parserA.backendPort() != defaultPort);
    ASSERT_TRUE(parserA.backendPort() == 8080);
}

TEST_F(AppCommandLineParserTest, BackedUrlOption)
{
    const QString defaultUrl = AppCommandLineParser::backendUrl();
    QStringList args = appArgs;
    args.append({ QStringLiteral("--backendUrl"), QStringLiteral("http://dummmy") });
    AppCommandLineParser parserA(args);

    ASSERT_TRUE(parserA.backendUrl() != defaultUrl);
    ASSERT_TRUE(parserA.backendUrl() == QStringLiteral("http://dummmy"));
}

TEST_F(AppCommandLineParserTest, SimulatorOption)
{
    const bool defaultSim = AppCommandLineParser::simulator();
    QStringList args = appArgs;
    args.append({ QStringLiteral("--simulator") });
    AppCommandLineParser parserA(args);

    ASSERT_TRUE(parserA.simulator() != defaultSim);
    ASSERT_TRUE(parserA.simulator());
}

TEST_F(AppCommandLineParserTest, SimulatorPortOption)
{
    const quint16 defaultPort = AppCommandLineParser::simulatorPort();
    QStringList args = appArgs;
    args.append({ QStringLiteral("--simulatorPort"), QStringLiteral("8080") });
    AppCommandLineParser parserA(args);

    ASSERT_TRUE(parserA.simulatorPort() != defaultPort);
    ASSERT_TRUE(parserA.simulatorPort() == 8080);
}

TEST_F(AppCommandLineParserTest, SimulatorUrlOption)
{
    const QString defaultUrl = AppCommandLineParser::simulatorUrl();
    QStringList args = appArgs;
    args.append({ QStringLiteral("--simulatorUrl"), QStringLiteral("http://dummmy") });
    AppCommandLineParser parserA(args);

    ASSERT_TRUE(parserA.simulatorUrl() != defaultUrl);
    ASSERT_TRUE(parserA.simulatorUrl() == QStringLiteral("http://dummmy"));
}
