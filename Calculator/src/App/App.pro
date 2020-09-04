include (../../globalflags.pri)
include (../../global.pri)
include (../../lib/GreenHouse/GreenHouse.pri)
include (../../lib/AppCore/AppCore.pri)

include (Calculator/Calculator.App.pri)

TARGET = Calculator
TEMPLATE = app
CONFIG += c++11

headless_build {
    DEFINES += HEADLESS
}

QT += qml quick

SOURCES += \
main.cpp \
integration.cpp

HEADERS += \
integration.h

RESOURCES += qml.qrc

DESTDIR = $$builddir/bin

# Additional import path used to resolve QML modules in Qt Creator's code model
# QML_IMPORT_PATH += ""

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
plugins/config.json

plugins.files = plugins/*.json
plugins.target = plugins
DEPLOYMENTFOLDERS += plugins

exists(../../scripts) {
    linux-g++|macx {
        CONFIG += file_copies
        runscript.files = ../../scripts/run.sh
        runscript.path = $$builddir/scripts
        COPIES += runscript
        
        make_executable.commands = chmod +x $$builddir/scripts/run.sh
        QMAKE_EXTRA_TARGETS += make_executable
        POST_TARGETDEPS += make_executable
    }
}

include("../../deploy.pri")
qtcAddDeployment()
