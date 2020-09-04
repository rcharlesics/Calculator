include (../../globalflags.pri)
include (../../global.pri)
include (../../lib/GreenHouse/GreenHouse.pri)
include (../../lib/AppCore/AppCore.pri)

TARGET = Calculator_Backend
TEMPLATE = app
CONFIG += c++11

QT += core

SOURCES += \
    main.cpp

DESTDIR = $$builddir/bin

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

include("../../deploy.pri")
qtcAddDeployment()
