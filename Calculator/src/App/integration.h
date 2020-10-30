#ifndef INTEGRATION_H
#define INTEGRATION_H

#include <QObject>

#include <QQuickItem>
#include <QQmlEngine>

class ApplicationPluginManager;

namespace GreenHouse {
class Context;
}
///
/// \brief After generating a GreenHouse flow using GreenHouse Tooling, the generated file
/// integration.cpp is used to hook up application objects to the GreenHouse context in the
/// mainWindowCreated event handler. The Integration class provides the application with an
/// application plugin manager, command line parser, main GreenHouse context, and QML engine.
///
class Integration : public QObject
{
    Q_OBJECT
    Q_DISABLE_COPY(Integration)
public:
    explicit Integration(QQmlEngine *engine, QObject *parent = nullptr);
    explicit Integration(QObject *parent = nullptr);
    ~Integration();

    Q_INVOKABLE void mainWindowCreated(QQuickItem *mainContainer, QQuickWindow *window);
    void startExecution();

private:
    void loadPluginConfig();
    void connectToBackend();
    void connectToSimulator(QQuickWindow *window);

    QQmlEngine *m_engine = nullptr;
    ApplicationPluginManager *m_applicationPluginManager = nullptr;
    GreenHouse::Context *m_context = nullptr;
};

#endif // INTEGRATION_H
