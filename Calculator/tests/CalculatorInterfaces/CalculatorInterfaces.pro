include (../../global.pri)
include (../gtest_dependency.pri)
include (../../lib/GreenHouse/GreenHouse.pri)
include (../../lib/AppCore/AppCore.pri)

TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG += thread
QT += qml quick
CONFIG += c++11

HEADERS += \
tst_surfacecontroller.hpp \
tst_surfacecontroller_impl.hpp \
tst_display.hpp \
tst_display_impl.hpp \
tst_statemachine.hpp

SOURCES += \
tst_surfacecontroller.cpp \
tst_surfacecontroller_impl.cpp \
tst_display.cpp \
tst_display_impl.cpp \
tst_statemachine.cpp

SOURCES += \
main.cpp
