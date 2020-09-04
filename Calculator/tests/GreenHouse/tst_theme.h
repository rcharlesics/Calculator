#pragma once

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

#include <greenhousecontext.h>
#include <greenhousetheme.h>

#include <QQmlApplicationEngine>
#include <QQuickItem>

using namespace testing;

class Theme : public Test
{
    // Test interface
protected:
    void SetUp();
    void TearDown();

    QQmlApplicationEngine *qmlEngine = nullptr;
    QQuickItem *rootItem = nullptr;
    GreenHouse::Context *context = nullptr;
};

void Theme::SetUp()
{
    qmlEngine = new QQmlApplicationEngine;
    qmlEngine->load(QUrl(QStringLiteral("qrc:/test-main.qml")));
    rootItem = qmlEngine->rootObjects().isEmpty()
            ? nullptr
            : qobject_cast<QQuickItem *>(qmlEngine->rootObjects().first());
    context = new GreenHouse::Context(qmlEngine, QLatin1String("ValidationFlow"), rootItem);
}

void Theme::TearDown()
{
    delete context;
}

TEST_F(Theme, HasThemes)
{
    ASSERT_GT(context->availableThemes().length(), 0);
}

TEST_F(Theme, DefaultThemeActive)
{
    ASSERT_TRUE(context->activeTheme().compare(QStringLiteral("DefaultTheme")) == 0);

    auto thm = qobject_cast<GreenHouse::ThemeManager *>(
            GreenHouse::ThemeManagerActivator::contextThemeManagerInstance(context));
    ASSERT_TRUE(thm);
    ASSERT_TRUE(thm->theme());
    ASSERT_TRUE(thm->theme() == context->activeThemeInstance());
}

TEST_F(Theme, AltThemeActive)
{
    context->activateTheme(QStringLiteral("AltTheme"));
    ASSERT_TRUE(context->activeTheme().compare(QStringLiteral("AltTheme")) == 0);
}

TEST_F(Theme, ThemeManagerInstanceAvailable)
{
    ASSERT_TRUE(GreenHouse::ThemeManagerActivator::contextThemeManagerInstance(context));
}

TEST_F(Theme, ThemeInstanceAvailable)
{
    auto thm = qobject_cast<GreenHouse::ThemeManager *>(
            GreenHouse::ThemeManagerActivator::contextThemeManagerInstance(context));
    ASSERT_TRUE(thm);
    ASSERT_TRUE(thm->theme());
}

TEST_F(Theme, ThemeBaseDirCorrect)
{
    auto thm = qobject_cast<GreenHouse::ThemeManager *>(
            GreenHouse::ThemeManagerActivator::contextThemeManagerInstance(context));
    ASSERT_TRUE(thm);
    ASSERT_TRUE(thm->theme());
    ASSERT_TRUE(thm->theme()->themeBaseDir().compare(
                        QStringLiteral("qrc:/Themes/ValidationFlow/DefaultTheme"))
                == 0);
}

TEST_F(Theme, AltThemeParentMatched)
{
    context->activateTheme(QStringLiteral("AltTheme"));
    auto thm = qobject_cast<GreenHouse::ThemeManager *>(
            GreenHouse::ThemeManagerActivator::contextThemeManagerInstance(context));
    ASSERT_TRUE(thm);
    ASSERT_TRUE(thm->theme());
    ASSERT_TRUE(context->activeTheme().compare(QStringLiteral("AltTheme")) == 0);
    ASSERT_TRUE(thm->theme()->parentTheme().compare(QStringLiteral("DefaultTheme")) == 0);
}

TEST_F(Theme, BaseThemeReactivation)
{
    context->activateTheme(QStringLiteral("AltTheme"));
    auto thm = qobject_cast<GreenHouse::ThemeManager *>(
            GreenHouse::ThemeManagerActivator::contextThemeManagerInstance(context));
    ASSERT_TRUE(thm);
    ASSERT_TRUE(thm->theme());
    ASSERT_TRUE(context->activeTheme().compare(QStringLiteral("AltTheme")) == 0);
    ASSERT_TRUE(thm->theme()->parentTheme().compare(QStringLiteral("DefaultTheme")) == 0);
    context->activateTheme(QStringLiteral("DefaultTheme"));
    ASSERT_TRUE(context->activeTheme().compare(QStringLiteral("DefaultTheme")) == 0);
    ASSERT_TRUE(thm->theme()->parentTheme().isEmpty());
}

TEST_F(Theme, InvalidThemeActivation)
{
    context->activateTheme(QStringLiteral("InvalidTheme"));
    auto thm = qobject_cast<GreenHouse::ThemeManager *>(
            GreenHouse::ThemeManagerActivator::contextThemeManagerInstance(context));
    ASSERT_TRUE(thm);
    ASSERT_FALSE(thm->theme());
}

TEST_F(Theme, MalformedThemeActivation)
{
    context->activateTheme(QStringLiteral("MalformedTheme"));
    auto thm = qobject_cast<GreenHouse::ThemeManager *>(
            GreenHouse::ThemeManagerActivator::contextThemeManagerInstance(context));
    ASSERT_TRUE(thm);
    ASSERT_FALSE(thm->theme());
}

TEST_F(Theme, GetValidAsset)
{
    auto thm = qobject_cast<GreenHouse::ThemeManager *>(
            GreenHouse::ThemeManagerActivator::contextThemeManagerInstance(context));
    ASSERT_TRUE(thm);
    ASSERT_TRUE(thm->theme());
    ASSERT_TRUE(thm->theme()->asset(QStringLiteral("GHLogoBig.png")).isValid());
}

TEST_F(Theme, GetUrlAsset)
{
    auto thm = qobject_cast<GreenHouse::ThemeManager *>(
            GreenHouse::ThemeManagerActivator::contextThemeManagerInstance(context));
    ASSERT_TRUE(thm);
    ASSERT_TRUE(thm->theme());
    ASSERT_TRUE(thm->theme()
                        ->asset(QStringLiteral("http:://AssetUrl"))
                        .toString()
                        .compare(QStringLiteral("http:://AssetUrl"))
                == 0);
}

TEST_F(Theme, GetInvalidAsset)
{
    auto thm = qobject_cast<GreenHouse::ThemeManager *>(
            GreenHouse::ThemeManagerActivator::contextThemeManagerInstance(context));
    ASSERT_TRUE(thm);
    ASSERT_TRUE(thm->theme());
    ASSERT_TRUE(thm->theme()->asset(QStringLiteral("InvalidAsset.png")).isEmpty());
}

TEST_F(Theme, GetInheritedAsset)
{
    context->activateTheme(QStringLiteral("AltTheme"));
    auto thm = qobject_cast<GreenHouse::ThemeManager *>(
            GreenHouse::ThemeManagerActivator::contextThemeManagerInstance(context));
    ASSERT_TRUE(thm);
    ASSERT_TRUE(thm->theme());
    ASSERT_TRUE(thm->theme()->asset(QStringLiteral("GHLogoBig.png")).isValid());
}

TEST_F(Theme, GetAnimatedAsset)
{
    context->activateTheme(QStringLiteral("AltTheme"));
    auto thm = qobject_cast<GreenHouse::ThemeManager *>(
            GreenHouse::ThemeManagerActivator::contextThemeManagerInstance(context));
    ASSERT_TRUE(thm);
    ASSERT_TRUE(thm->theme());
    ASSERT_TRUE(
            thm->theme()->animationFrameAsset(QStringLiteral("animation/ghlogo"), 0, 2).isValid());
    ASSERT_TRUE(
            thm->theme()->animationFrameAsset(QStringLiteral("animation/ghlogo"), 5, 2).isValid());
    ASSERT_TRUE(
            thm->theme()->animationFrameAsset(QStringLiteral("animation/ghlogo"), 9, 2).isValid());
    ASSERT_TRUE(
            thm->theme()->animationFrameAsset(QStringLiteral("animation/ghlogo"), 10, 2).isValid());
}

TEST_F(Theme, GetColoredAsset)
{
    auto thm = qobject_cast<GreenHouse::ThemeManager *>(
            GreenHouse::ThemeManagerActivator::contextThemeManagerInstance(context));
    ASSERT_TRUE(thm);
    ASSERT_TRUE(thm->theme());
    const QUrl assetUrl = thm->theme()->coloredAsset(QStringLiteral("GHLogoBigshadowColor.png"),
                                                     QStringLiteral("shadowRectColor"));
    ASSERT_TRUE(assetUrl.isValid());
    ASSERT_TRUE(assetUrl.toString().contains(QStringLiteral("shadowRectColor")));
}

TEST_F(Theme, GetNonExistingColorAsset)
{
    auto thm = qobject_cast<GreenHouse::ThemeManager *>(
            GreenHouse::ThemeManagerActivator::contextThemeManagerInstance(context));
    ASSERT_TRUE(thm);
    ASSERT_TRUE(thm->theme());
    const QUrl assetUrl = thm->theme()->coloredAsset(QStringLiteral("GHLogoBigshadowColor.png"),
                                                     QStringLiteral("invalidColor"));
    ASSERT_TRUE(assetUrl.isValid());
    ASSERT_FALSE(assetUrl.toString().contains(QStringLiteral("invalidColor")));
}

TEST_F(Theme, GetNonColoredAsset)
{
    auto thm = qobject_cast<GreenHouse::ThemeManager *>(
            GreenHouse::ThemeManagerActivator::contextThemeManagerInstance(context));
    ASSERT_TRUE(thm);
    ASSERT_TRUE(thm->theme());
    const QUrl assetUrl = thm->theme()->coloredAsset(QStringLiteral("GHLogoBig.png"),
                                                     QStringLiteral("shadowRectColor"));
    ASSERT_TRUE(assetUrl.isValid());
    ASSERT_FALSE(assetUrl.toString().contains(QStringLiteral("shadowRectColor")));
}

TEST_F(Theme, GetFont)
{
    auto thm = qobject_cast<GreenHouse::ThemeManager *>(
            GreenHouse::ThemeManagerActivator::contextThemeManagerInstance(context));
    ASSERT_TRUE(thm);
    ASSERT_TRUE(thm->theme());
    ASSERT_TRUE(thm->theme()
                        ->font(QStringLiteral("viewText"))
                        .family()
                        .compare(QStringLiteral("Droid Sans Mono"))
                == 0);
}

TEST_F(Theme, GetInheritedFont)
{
    context->activateTheme(QStringLiteral("AltTheme"));
    auto thm = qobject_cast<GreenHouse::ThemeManager *>(
            GreenHouse::ThemeManagerActivator::contextThemeManagerInstance(context));
    ASSERT_TRUE(thm);
    ASSERT_TRUE(thm->theme());
    ASSERT_TRUE(thm->theme()
                        ->font(QStringLiteral("viewText"))
                        .family()
                        .compare(QStringLiteral("Droid Sans Mono"))
                == 0);
}

TEST_F(Theme, GetColor)
{
    auto thm = qobject_cast<GreenHouse::ThemeManager *>(
            GreenHouse::ThemeManagerActivator::contextThemeManagerInstance(context));
    ASSERT_TRUE(thm);
    ASSERT_TRUE(thm->theme());
    const QColor themeColor = thm->theme()->color(QStringLiteral("textColor"));
    ASSERT_TRUE(themeColor.isValid());
    ASSERT_TRUE(thm->theme()->colorId(themeColor).compare(QStringLiteral("textColor")) == 0);
}

TEST_F(Theme, GetRawColor)
{
    auto thm = qobject_cast<GreenHouse::ThemeManager *>(
            GreenHouse::ThemeManagerActivator::contextThemeManagerInstance(context));
    ASSERT_TRUE(thm);
    ASSERT_TRUE(thm->theme());
    const QColor rawColor(196, 255, 0);
    const QColor themeColor = thm->theme()->color(QStringLiteral("#c4ff00"));
    ASSERT_TRUE(themeColor.isValid());
    ASSERT_TRUE(themeColor.red() == rawColor.red());
    ASSERT_TRUE(themeColor.green() == rawColor.green());
    ASSERT_TRUE(themeColor.blue() == rawColor.blue());
    ASSERT_TRUE(themeColor.alpha() == rawColor.alpha());
}

TEST_F(Theme, GetRawARGBColor)
{
    auto thm = qobject_cast<GreenHouse::ThemeManager *>(
            GreenHouse::ThemeManagerActivator::contextThemeManagerInstance(context));
    ASSERT_TRUE(thm);
    ASSERT_TRUE(thm->theme());
    const QColor rawColor(196, 255, 0, 196);
    const QColor themeColor = thm->theme()->color(QStringLiteral("#c4c4ff00"));
    ASSERT_TRUE(themeColor.isValid());
    ASSERT_TRUE(themeColor.red() == rawColor.red());
    ASSERT_TRUE(themeColor.green() == rawColor.green());
    ASSERT_TRUE(themeColor.blue() == rawColor.blue());
    ASSERT_TRUE(themeColor.alpha() == rawColor.alpha());
}

TEST_F(Theme, GetForegroundColor)
{
    auto thm = qobject_cast<GreenHouse::ThemeManager *>(
            GreenHouse::ThemeManagerActivator::contextThemeManagerInstance(context));
    ASSERT_TRUE(thm);
    ASSERT_TRUE(thm->theme());
    const QColor buttonDark = thm->theme()->color(QStringLiteral("buttonDark"));
    ASSERT_TRUE(buttonDark.isValid());
    const QColor buttonTextColor = thm->theme()->color(QStringLiteral("buttonTextColor"));
    ASSERT_TRUE(buttonTextColor.isValid());

    const QColor foregroundColor = thm->theme()->foregroundColor(buttonDark, QColor());
    ASSERT_TRUE(foregroundColor.isValid());
    ASSERT_TRUE(foregroundColor.red() == buttonTextColor.red());
    ASSERT_TRUE(foregroundColor.green() == buttonTextColor.green());
    ASSERT_TRUE(foregroundColor.blue() == buttonTextColor.blue());
    ASSERT_TRUE(foregroundColor.alpha() == buttonTextColor.alpha());
}

TEST_F(Theme, GetForegroundColorWithCollision)
{
    auto thm = qobject_cast<GreenHouse::ThemeManager *>(
            GreenHouse::ThemeManagerActivator::contextThemeManagerInstance(context));
    ASSERT_TRUE(thm);
    ASSERT_TRUE(thm->theme());
    const QColor panelColor = thm->theme()->color(QStringLiteral("panelColor"));
    ASSERT_TRUE(panelColor.isValid());
    const QColor panelColor2 = thm->theme()->color(QStringLiteral("panelColor2"));
    ASSERT_TRUE(panelColor2.isValid());
    ASSERT_TRUE(panelColor.red() == panelColor2.red());
    ASSERT_TRUE(panelColor.green() == panelColor2.green());
    ASSERT_TRUE(panelColor.blue() == panelColor2.blue());
    ASSERT_TRUE(panelColor.alpha() == panelColor2.alpha());

    const QColor buttonTextColor = thm->theme()->color(QStringLiteral("buttonTextColor"));
    ASSERT_TRUE(buttonTextColor.isValid());

    const QColor foregroundColor = thm->theme()->foregroundColor(panelColor, QColor());
    ASSERT_TRUE(foregroundColor.isValid());
    ASSERT_TRUE(foregroundColor.red() == buttonTextColor.red());
    ASSERT_TRUE(foregroundColor.green() == buttonTextColor.green());
    ASSERT_TRUE(foregroundColor.blue() == buttonTextColor.blue());
    ASSERT_TRUE(foregroundColor.alpha() == buttonTextColor.alpha());
}

TEST_F(Theme, GetInheritedColor)
{
    context->activateTheme(QStringLiteral("AltTheme"));
    auto thm = qobject_cast<GreenHouse::ThemeManager *>(
            GreenHouse::ThemeManagerActivator::contextThemeManagerInstance(context));
    ASSERT_TRUE(thm);
    ASSERT_TRUE(thm->theme());
    const QColor themeColor = thm->theme()->color(QStringLiteral("textColor"));
    ASSERT_TRUE(themeColor.isValid());
    ASSERT_TRUE(thm->theme()->colorId(themeColor).compare(QStringLiteral("textColor")) == 0);
}
