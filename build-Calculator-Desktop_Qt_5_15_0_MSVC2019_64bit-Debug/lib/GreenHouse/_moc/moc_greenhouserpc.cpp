/****************************************************************************
** Meta object code from reading C++ file 'greenhouserpc.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../Calculator/lib/GreenHouse/greenhouserpc.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'greenhouserpc.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_GreenHouse__WebSocketRPCServer_t {
    QByteArrayData data[9];
    char stringdata0[149];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GreenHouse__WebSocketRPCServer_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GreenHouse__WebSocketRPCServer_t qt_meta_stringdata_GreenHouse__WebSocketRPCServer = {
    {
QT_MOC_LITERAL(0, 0, 30), // "GreenHouse::WebSocketRPCServer"
QT_MOC_LITERAL(1, 31, 28), // "activeConnectionCountChanged"
QT_MOC_LITERAL(2, 60, 0), // ""
QT_MOC_LITERAL(3, 61, 17), // "activeConnections"
QT_MOC_LITERAL(4, 79, 15), // "socketConnected"
QT_MOC_LITERAL(5, 95, 8), // "socketId"
QT_MOC_LITERAL(6, 104, 18), // "socketDisconnected"
QT_MOC_LITERAL(7, 123, 21), // "untrustedDataReceived"
QT_MOC_LITERAL(8, 145, 3) // "msg"

    },
    "GreenHouse::WebSocketRPCServer\0"
    "activeConnectionCountChanged\0\0"
    "activeConnections\0socketConnected\0"
    "socketId\0socketDisconnected\0"
    "untrustedDataReceived\0msg"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GreenHouse__WebSocketRPCServer[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x06 /* Public */,
       4,    1,   37,    2, 0x06 /* Public */,
       6,    1,   40,    2, 0x06 /* Public */,
       7,    2,   43,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    8,    5,

       0        // eod
};

void GreenHouse::WebSocketRPCServer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<WebSocketRPCServer *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->activeConnectionCountChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->socketConnected((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->socketDisconnected((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->untrustedDataReceived((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (WebSocketRPCServer::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WebSocketRPCServer::activeConnectionCountChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (WebSocketRPCServer::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WebSocketRPCServer::socketConnected)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (WebSocketRPCServer::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WebSocketRPCServer::socketDisconnected)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (WebSocketRPCServer::*)(const QString & , const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WebSocketRPCServer::untrustedDataReceived)) {
                *result = 3;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject GreenHouse::WebSocketRPCServer::staticMetaObject = { {
    QMetaObject::SuperData::link<QWebSocketServer::staticMetaObject>(),
    qt_meta_stringdata_GreenHouse__WebSocketRPCServer.data,
    qt_meta_data_GreenHouse__WebSocketRPCServer,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *GreenHouse::WebSocketRPCServer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GreenHouse::WebSocketRPCServer::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_GreenHouse__WebSocketRPCServer.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "RPCServiceInterface"))
        return static_cast< RPCServiceInterface*>(this);
    return QWebSocketServer::qt_metacast(_clname);
}

int GreenHouse::WebSocketRPCServer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWebSocketServer::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void GreenHouse::WebSocketRPCServer::activeConnectionCountChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void GreenHouse::WebSocketRPCServer::socketConnected(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void GreenHouse::WebSocketRPCServer::socketDisconnected(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void GreenHouse::WebSocketRPCServer::untrustedDataReceived(const QString & _t1, const QString & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
struct qt_meta_stringdata_GreenHouse__WebSocketRPC_t {
    QByteArrayData data[1];
    char stringdata0[25];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GreenHouse__WebSocketRPC_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GreenHouse__WebSocketRPC_t qt_meta_stringdata_GreenHouse__WebSocketRPC = {
    {
QT_MOC_LITERAL(0, 0, 24) // "GreenHouse::WebSocketRPC"

    },
    "GreenHouse::WebSocketRPC"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GreenHouse__WebSocketRPC[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void GreenHouse::WebSocketRPC::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject GreenHouse::WebSocketRPC::staticMetaObject = { {
    QMetaObject::SuperData::link<QWebSocket::staticMetaObject>(),
    qt_meta_stringdata_GreenHouse__WebSocketRPC.data,
    qt_meta_data_GreenHouse__WebSocketRPC,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *GreenHouse::WebSocketRPC::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GreenHouse::WebSocketRPC::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_GreenHouse__WebSocketRPC.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "RPCServiceInterface"))
        return static_cast< RPCServiceInterface*>(this);
    return QWebSocket::qt_metacast(_clname);
}

int GreenHouse::WebSocketRPC::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWebSocket::qt_metacall(_c, _id, _a);
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
