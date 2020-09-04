# GreenHouse Generated Project

This README file describes the structure of a GreenHouse generated application and how to go about working with it the app.

## Run.sh

Inspect scripts/run.sh to understand the commandline arguments that are accepted for the application. For example, supplying --simulator will enable a connection to be established between a simulator application and the main application.

## AppCommandLineParser class

Inspect appcommandlineparser.cpp/.h to see how debugging options are handled. This is the file you can adjust to add new logging levels to the application. It also shows the commandline processing of all arguments. You can actually see all the allowed flags for the application such as remoteBackend and simulator.

## Logging

You can updated appcore_log.cpp/.h to add new loggers. You can dictate which logging levels should be shown at runtime via updating the appcommandlineparser.cpp file. For example, add a new logging category in appcore_log.h like this:

```cpp
APPCORE_EXPORT Q_DECLARE_LOGGING_CATEGORY(backend)

#define logDebug() qCDebug(backend, )
#define logInfo() qCInfo(backend, )
#define logWarning() qCWarning(backend, )
#define logCritical() qCCritical(backend, )
```

Then add the logging category in appcore_log.h like this:

```cpp
Q_LOGGING_CATEGORY(backend, "backend")
```

Then in appcommandlineparser.cpp you can update your app's default logging filters by adding this string to to the m_loggingFilter's initialization. Then, if you wanted to show the debug statements by default, your constructor would look like this:

```cpp
AppCommandLineParser::AppCommandLineParser(const QStringList &args)
  : m_loggingFilters(QStringLiteral("*.debug=false\n"
                                    "qml.debug=true\n"
                                    "theming.debug=false\n"
                                    "greenhouse.debug=true\n"
                                    "appcore.debug=true\n"
                                    "backend.debug=true"))
  , m_remoteBackend(false)
  , m_backendPort(26185)
  , m_backendUrl(QStringLiteral("localhost"))
  , m_simulator(false)
  , m_simulatorPort(26186)
  , m_simulatorUrl(QStringLiteral("localhost"))
{
    // Code
}
```

## Simulator

GreenHouse applications come with a data simulator to test the UI. This can be used to test the UI before the backend plugin's are established, or to see what the application looks like in response to changing properties, signals, and methods.

When you open the the project, the available run targets for a CMake project are app, backend, and simulator. If the project is a qmake project, App, Backend, and Simulator run targets are your options (the other two are for tests). If you want to connect your app to the simulator, first add a command line argument "--simulator"

Then, run the simulator and the app (two GUIs will launch). The result is that you can control your application from the simulator.

Alternatively, configure a Run.sh custom executable in Qt Creator to launch both. With this run configuration added, a fourth run target will be available in Qt Creator called "Run.sh". You can just use this run target to launch both apps.

If you are running with the simulator, you may want to ensure the backend acts as the server so that the data and logic is sourced from there. By default, the simulator acts as the server and thus overwrites any changes that your backend plugin makes. To ensure that the backend acts as the server and that the simulator simply plugs into this connection, set an environment variable called DIRECTION_APP_TO_SIMULATOR (any value).

## Backend Plugins

The GreenHouse generator deposits the header and source interface for any defined backend objects in lib/AppCore/{PROJECT} (OBJECTNAME.cpp/OBJECTNAME.hpp). Do not edit these as they will be written over on next code generation. Instead, this class will be subclassed in plugins, where you will provide actual implementations for the object. This is what enables you to pass information from your backend (sourced from wherever you get your data) to the UI.

An option is to create at two plugins for each functionality, "BackendPlugin" and "MockBackendPlugin". MockBackendPlugin, would then be a dependency-free mocked implementation of the real backend. This is useful if you want to run the app in an environment where hardware and external libraries aren't yet available. It is also useful to test the UI and print things to the log. Here you can introduce application logic to ensure your UI is functioning properly. Just create an object that subclasses your generated backend object and provide any code you want.

Note: Alternatively, one can use the simulator directly to implement a backend. Then, it wouldn't be necessary to use a Mock plugin. To understand what's possible with the simulator, refer to the src/Simulator/SCRIPTING.md file.

From GreenHouse Version 1.2+, you can directly generate plugins (for qmake and CMake projects) and select the backend objects you'd like to be contained with each. Therefore, it is no longer necessary to create Qt plugins from scratch.

Both your "Mocked" and "True" plugins are built and distributed as shared objects (.so) along with the application binaries to be loaded at runtime. To configure the application to load the MockBackendPlugin (you are not in production or testing the BackendPlugin), ensure your src/App/plugins/config.json blacklists the Backend Plugin by name, such as "BackendPlugin". When you are ready to swap out the Mocked plugin with the real plugin (BackendPlugin), simply blacklist the MockBackendPlugin instead. This will ensure that the proper shared library is loaded at runtime.
