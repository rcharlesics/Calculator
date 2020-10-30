#ifndef APPCOMMANDLINEPARSER_H
#define APPCOMMANDLINEPARSER_H

#include "appcore_global.h"
#include <QString>

///
/// \brief The AppCommandLineParser class is used to parse the command line arguments passed to the
/// application
///
class APPCORE_EXPORT AppCommandLineParser
{
public:
    ///
    /// \brief AppCommandLineParser AppCommandLineParser creates a new AppCommandLineParser instance
    /// \param args - a list of command-line arguments
    ///
    AppCommandLineParser(const QStringList &args);

    ///
    /// \brief loggingFilters used to get a string containing the logging category filters
    /// \return
    ///
    static QString loggingFilters();

    ///
    /// \brief pluginPath used to get a string containing the plugin loading path
    /// \return
    ///
    static QString pluginPath();

    ///
    /// \brief remoteBackend used to determine if the application should connect to a remote
    ///  backend instead of loading local plugins
    ///
    /// \return
    ///
    static bool remoteBackend();

    ///
    /// \brief backendPort used to get a string containing the port used to connect to a remote
    /// backend
    ///
    /// \return
    ///
    static quint16 backendPort();

    ///
    /// \brief backendUrl used to get a string containing the url used to connect to a remote
    /// bakcend
    ///
    /// \return
    ///
    static QString backendUrl();

    ///
    /// \brief simulator used to determine if the application should connect to a simulator
    /// \return
    ///
    static bool simulator();

    ///
    /// \brief simulatorPort used to get a string containing the port used to connect to a simulator
    /// \return
    ///
    static quint16 simulatorPort();

    ///
    /// \brief simulatorUrl used to get a string containing the url used to connect to a simulator
    /// instance \return
    ///
    static QString simulatorUrl();

private:
    static QString s_loggingFilters;
    static QString s_pluginPath;

    static bool s_remoteBackend;
    static quint16 s_backendPort;
    static QString s_backendUrl;

    static bool s_simulator;
    static quint16 s_simulatorPort;
    static QString s_simulatorUrl;
};

#endif // APPCOMMANDLINEPARSER_H
