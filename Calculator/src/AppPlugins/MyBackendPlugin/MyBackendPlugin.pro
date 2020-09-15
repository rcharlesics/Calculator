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
    backend_log.h \
    mybackendplugin.h

SOURCES += \
    backend_log.cpp \
    mybackendplugin.cpp

include (Implementations.pri)

