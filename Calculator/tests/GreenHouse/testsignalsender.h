#ifndef TESTSIGNALSENDER_H
#define TESTSIGNALSENDER_H

#include <QObject>
#include <greenhousecontext.h>

class TestSignalSender : public QObject, public GreenHouse::ContextObjectAPI<0>
{
    Q_OBJECT
public:
    TestSignalSender();

signals:
    void testSignal();
    void testSignal2();
};

#endif // TESTSIGNALSENDER_H