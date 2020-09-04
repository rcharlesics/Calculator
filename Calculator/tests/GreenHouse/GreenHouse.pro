include (../../global.pri)
include (../gtest_dependency.pri)
include (../../lib/GreenHouse/GreenHouse.pri)
include (../../lib/AppCore/AppCore.pri)

TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG += thread
QT += qml quick gui
CONFIG += c++11

HEADERS += \
    testpresenter.hpp \
    testsignalsender.h \
    tst_appcommandlineparser.h \
    tst_context.h \
    tst_model.h \
    tst_rpc.h \
    tst_statemachine.h \
    tst_theme.h

SOURCES += \
    main.cpp \
    testpresenter.cpp \
    testsignalsender.cpp

RESOURCES += \
    ValidationFlow_themes.qrc \
    layouts.qrc \
    qml.qrc
