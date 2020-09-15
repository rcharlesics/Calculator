include (../../../globalflags.pri)
include (../../../global.pri)
include (../../../lib/GreenHouse/GreenHouse.pri)
include (../../../lib/AppCore/AppCore.pri)

TARGET = MyBackendPlugin
CONFIG += plugin
TEMPLATE = lib

DESTDIR = $$builddir/plugins

!win32: QMAKE_RPATHDIR += $$builddir/lib

DISTFILES += \
    MyBackendPlugin.json

HEADERS += \
    mybackendplugin.h

SOURCES += \
    mybackendplugin.cpp

include (Implementations.pri)

