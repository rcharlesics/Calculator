TEMPLATE = subdirs
DEFINES += QT_NO_CAST_FROM_ASCII QT_NO_CAST_TO_ASCII

GreenHouse_lib.subdir = lib/GreenHouse
GreenHouse_lib.target = GreenHouse-lib

GreenHouse_app_core.subdir = lib/AppCore
GreenHouse_app_core.target = GreenHouse-app-core
GreenHouse_app_core.depends = GreenHouse-lib

AppPlugins.subdir = src/AppPlugins
AppPlugins.target = App-Plugins
AppPlugins.depends = GreenHouse-lib GreenHouse-app-core

GreenHouse_app.subdir = src/App
GreenHouse_app.target = GreenHouse-app
GreenHouse_app.depends = GreenHouse-lib GreenHouse-app-core

GreenHouse_backend.subdir = src/Backend
GreenHouse_backend.target = GreenHouse-backend
GreenHouse_backend.depends = GreenHouse-lib GreenHouse-app-core

GreenHouse_sim.subdir = src/Simulator
GreenHouse_sim.target = GreenHouse-sim
GreenHouse_sim.depends = GreenHouse-lib GreenHouse-app-core

SUBDIRS += GreenHouse_lib GreenHouse_app_core AppPlugins GreenHouse_app GreenHouse_backend GreenHouse_sim

exists(tests) {
    AutoTests.subdir = tests
    AutoTests.target = Auto-Tests
    AutoTests.depends = GreenHouse-lib GreenHouse-app-core
    !no_build_tests {
        SUBDIRS += AutoTests
    }
}

translations.files = translations/*.qm
translations.target = translations
DEPLOYMENTFOLDERS += translations
include("deploy.pri")
qtcAddDeployment()

OTHER_FILES += _clang-format README.md
exists(scripts) {
    OTHER_FILES += scripts/*
}

