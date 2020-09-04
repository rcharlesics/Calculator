include (../../globalflags.pri)
include (../../global.pri)
include (AppCore-local.pri)
include (Calculator/Calculator.Core.pri)
include (../GreenHouse/GreenHouse.pri)

TARGET = AppCore
TEMPLATE = lib

VERSION = $$APPCORE_VERSION

DEFINES += APPCORE_LIBRARY

QT += qml quick gui

SOURCES += \
    appcore_log.cpp \
    applicationpluginmanager.cpp \
    applicationplugininterface.cpp \
    appcommandlineparser.cpp

HEADERS += \
    appcore_global.h \
    appcore_log.h \
    interfaceid.h \
    applicationpluginmanager.h \
    applicationplugininterface.h \
    appcommandlineparser.h

RESOURCES += imports.qrc

DESTDIR = $$builddir/lib

unix {
    target.path = /usr/lib
    INSTALLS += target
}
