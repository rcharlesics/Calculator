include (../../globalflags.pri)
include (../../global.pri)
include (../../lib/GreenHouse/GreenHouse.pri)
include (../../lib/AppCore/AppCore.pri)

TARGET = Calculator_Simulator
TEMPLATE = app
CONFIG += c++11

QT += qml quick widgets

HEADERS += \
    simulator.hpp

SOURCES += \
    main.cpp \
    simulator.cpp

RESOURCES += \
    qml.qrc \
    resources.qrc \

macx: {
ICON = $$PWD/icons/Simulator.icns
}

win32: {
RC_ICONS = $$PWD/icons/Simulator.ico
}

DESTDIR = $$builddir/bin

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

exists (simScripts) {
OTHER_FILES += $$files(simScripts/*.js, true)
OTHER_FILES += $$files(simScripts/*.oif, true)
simScriptsFolder.source = simScripts
simScriptsFolder.target = simScripts
DEPLOYMENTFOLDERS += simScriptsFolder
}

include("../../deploy.pri")
qtcAddDeployment()

OTHER_FILES += \
    SCRIPTING.md
