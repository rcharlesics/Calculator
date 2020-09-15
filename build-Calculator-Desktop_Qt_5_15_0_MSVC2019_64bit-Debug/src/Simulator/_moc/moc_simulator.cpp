/****************************************************************************
** Meta object code from reading C++ file 'simulator.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../Calculator/src/Simulator/simulator.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'simulator.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Calculator__ArgumentWrapper_t {
    QByteArrayData data[7];
    char stringdata0[67];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Calculator__ArgumentWrapper_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Calculator__ArgumentWrapper_t qt_meta_stringdata_Calculator__ArgumentWrapper = {
    {
QT_MOC_LITERAL(0, 0, 27), // "Calculator::ArgumentWrapper"
QT_MOC_LITERAL(1, 28, 12), // "valueChanged"
QT_MOC_LITERAL(2, 41, 0), // ""
QT_MOC_LITERAL(3, 42, 5), // "value"
QT_MOC_LITERAL(4, 48, 4), // "name"
QT_MOC_LITERAL(5, 53, 8), // "typeName"
QT_MOC_LITERAL(6, 62, 4) // "type"

    },
    "Calculator::ArgumentWrapper\0valueChanged\0"
    "\0value\0name\0typeName\0type"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Calculator__ArgumentWrapper[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       4,   20, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   19,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,

 // properties: name, type, flags
       3, QMetaType::QVariant, 0x00495103,
       4, QMetaType::QString, 0x00095401,
       5, QMetaType::QString, 0x00095401,
       6, QMetaType::Int, 0x00095401,

 // properties: notify_signal_id
       0,
       0,
       0,
       0,

       0        // eod
};

void Calculator::ArgumentWrapper::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ArgumentWrapper *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->valueChanged(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ArgumentWrapper::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ArgumentWrapper::valueChanged)) {
                *result = 0;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<ArgumentWrapper *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QVariant*>(_v) = _t->value(); break;
        case 1: *reinterpret_cast< QString*>(_v) = _t->name(); break;
        case 2: *reinterpret_cast< QString*>(_v) = _t->name(); break;
        case 3: *reinterpret_cast< int*>(_v) = _t->type(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<ArgumentWrapper *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setValue(*reinterpret_cast< QVariant*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject Calculator::ArgumentWrapper::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_Calculator__ArgumentWrapper.data,
    qt_meta_data_Calculator__ArgumentWrapper,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Calculator::ArgumentWrapper::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Calculator::ArgumentWrapper::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Calculator__ArgumentWrapper.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Calculator::ArgumentWrapper::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 4;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void Calculator::ArgumentWrapper::valueChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
struct qt_meta_stringdata_Calculator__ScriptableObject_t {
    QByteArrayData data[12];
    char stringdata0[167];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Calculator__ScriptableObject_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Calculator__ScriptableObject_t qt_meta_stringdata_Calculator__ScriptableObject = {
    {
QT_MOC_LITERAL(0, 0, 28), // "Calculator::ScriptableObject"
QT_MOC_LITERAL(1, 29, 18), // "handlerCodeChanged"
QT_MOC_LITERAL(2, 48, 0), // ""
QT_MOC_LITERAL(3, 49, 15), // "syncHandlerCode"
QT_MOC_LITERAL(4, 65, 14), // "installHanlder"
QT_MOC_LITERAL(5, 80, 7), // "handler"
QT_MOC_LITERAL(6, 88, 17), // "reloadHandlerCode"
QT_MOC_LITERAL(7, 106, 11), // "clearTimers"
QT_MOC_LITERAL(8, 118, 12), // "installTimer"
QT_MOC_LITERAL(9, 131, 8), // "interval"
QT_MOC_LITERAL(10, 140, 14), // "uninstallTimer"
QT_MOC_LITERAL(11, 155, 11) // "handlerCode"

    },
    "Calculator::ScriptableObject\0"
    "handlerCodeChanged\0\0syncHandlerCode\0"
    "installHanlder\0handler\0reloadHandlerCode\0"
    "clearTimers\0installTimer\0interval\0"
    "uninstallTimer\0handlerCode"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Calculator__ScriptableObject[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       1,   64, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x06 /* Public */,
       3,    0,   50,    2, 0x06 /* Public */,

 // methods: name, argc, parameters, tag, flags
       4,    1,   51,    2, 0x02 /* Public */,
       6,    0,   54,    2, 0x02 /* Public */,
       7,    0,   55,    2, 0x02 /* Public */,
       8,    2,   56,    2, 0x02 /* Public */,
      10,    1,   61,    2, 0x02 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // methods: parameters
    QMetaType::Void, QMetaType::QObjectStar,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::QObjectStar,    9,    5,
    QMetaType::Void, QMetaType::QObjectStar,    5,

 // properties: name, type, flags
      11, QMetaType::QString, 0x00495103,

 // properties: notify_signal_id
       0,

       0        // eod
};

void Calculator::ScriptableObject::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ScriptableObject *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->handlerCodeChanged(); break;
        case 1: _t->syncHandlerCode(); break;
        case 2: _t->installHanlder((*reinterpret_cast< QObject*(*)>(_a[1]))); break;
        case 3: _t->reloadHandlerCode(); break;
        case 4: _t->clearTimers(); break;
        case 5: _t->installTimer((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QObject*(*)>(_a[2]))); break;
        case 6: _t->uninstallTimer((*reinterpret_cast< QObject*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ScriptableObject::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ScriptableObject::handlerCodeChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (ScriptableObject::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ScriptableObject::syncHandlerCode)) {
                *result = 1;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<ScriptableObject *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = _t->handlerCode(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<ScriptableObject *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setHandlerCode(*reinterpret_cast< QString*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject Calculator::ScriptableObject::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_Calculator__ScriptableObject.data,
    qt_meta_data_Calculator__ScriptableObject,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Calculator::ScriptableObject::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Calculator::ScriptableObject::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Calculator__ScriptableObject.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Calculator::ScriptableObject::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 1;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void Calculator::ScriptableObject::handlerCodeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void Calculator::ScriptableObject::syncHandlerCode()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
struct qt_meta_stringdata_Calculator__ContextObjectMethodWrapper_t {
    QByteArrayData data[7];
    char stringdata0[83];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Calculator__ContextObjectMethodWrapper_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Calculator__ContextObjectMethodWrapper_t qt_meta_stringdata_Calculator__ContextObjectMethodWrapper = {
    {
QT_MOC_LITERAL(0, 0, 38), // "Calculator::ContextObjectMeth..."
QT_MOC_LITERAL(1, 39, 4), // "call"
QT_MOC_LITERAL(2, 44, 0), // ""
QT_MOC_LITERAL(3, 45, 4), // "args"
QT_MOC_LITERAL(4, 50, 11), // "callOverRPC"
QT_MOC_LITERAL(5, 62, 4), // "name"
QT_MOC_LITERAL(6, 67, 15) // "methodArguments"

    },
    "Calculator::ContextObjectMethodWrapper\0"
    "call\0\0args\0callOverRPC\0name\0methodArguments"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Calculator__ContextObjectMethodWrapper[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       2,   30, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // methods: name, argc, parameters, tag, flags
       1,    1,   24,    2, 0x02 /* Public */,
       4,    1,   27,    2, 0x02 /* Public */,

 // methods: parameters
    QMetaType::Void, QMetaType::QVariantMap,    3,
    QMetaType::Void, QMetaType::QVariantMap,    3,

 // properties: name, type, flags
       5, QMetaType::QString, 0x00095401,
       6, QMetaType::QString, 0x00095401,

       0        // eod
};

void Calculator::ContextObjectMethodWrapper::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ContextObjectMethodWrapper *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->call((*reinterpret_cast< const QVariantMap(*)>(_a[1]))); break;
        case 1: _t->callOverRPC((*reinterpret_cast< const QVariantMap(*)>(_a[1]))); break;
        default: ;
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<ContextObjectMethodWrapper *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = _t->name(); break;
        case 1: *reinterpret_cast< QString*>(_v) = _t->methodArguments(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject Calculator::ContextObjectMethodWrapper::staticMetaObject = { {
    QMetaObject::SuperData::link<ScriptableObject::staticMetaObject>(),
    qt_meta_stringdata_Calculator__ContextObjectMethodWrapper.data,
    qt_meta_data_Calculator__ContextObjectMethodWrapper,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Calculator::ContextObjectMethodWrapper::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Calculator::ContextObjectMethodWrapper::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Calculator__ContextObjectMethodWrapper.stringdata0))
        return static_cast<void*>(this);
    return ScriptableObject::qt_metacast(_clname);
}

int Calculator::ContextObjectMethodWrapper::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = ScriptableObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 2;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}
struct qt_meta_stringdata_Calculator__ContextObjectEventWrapper_t {
    QByteArrayData data[7];
    char stringdata0[85];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Calculator__ContextObjectEventWrapper_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Calculator__ContextObjectEventWrapper_t qt_meta_stringdata_Calculator__ContextObjectEventWrapper = {
    {
QT_MOC_LITERAL(0, 0, 37), // "Calculator::ContextObjectEven..."
QT_MOC_LITERAL(1, 38, 4), // "call"
QT_MOC_LITERAL(2, 43, 0), // ""
QT_MOC_LITERAL(3, 44, 4), // "args"
QT_MOC_LITERAL(4, 49, 4), // "name"
QT_MOC_LITERAL(5, 54, 14), // "eventArguments"
QT_MOC_LITERAL(6, 69, 15) // "QList<QObject*>"

    },
    "Calculator::ContextObjectEventWrapper\0"
    "call\0\0args\0name\0eventArguments\0"
    "QList<QObject*>"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Calculator__ContextObjectEventWrapper[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       2,   28, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // methods: name, argc, parameters, tag, flags
       1,    1,   24,    2, 0x02 /* Public */,
       1,    0,   27,    2, 0x22 /* Public | MethodCloned */,

 // methods: parameters
    QMetaType::Void, QMetaType::QVariantMap,    3,
    QMetaType::Void,

 // properties: name, type, flags
       4, QMetaType::QString, 0x00095401,
       5, 0x80000000 | 6, 0x00095409,

       0        // eod
};

void Calculator::ContextObjectEventWrapper::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ContextObjectEventWrapper *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->call((*reinterpret_cast< const QVariantMap(*)>(_a[1]))); break;
        case 1: _t->call(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterPropertyMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 1:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<QObject*> >(); break;
        }
    }

#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<ContextObjectEventWrapper *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = _t->name(); break;
        case 1: *reinterpret_cast< QList<QObject*>*>(_v) = _t->eventArguments(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject Calculator::ContextObjectEventWrapper::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_Calculator__ContextObjectEventWrapper.data,
    qt_meta_data_Calculator__ContextObjectEventWrapper,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Calculator::ContextObjectEventWrapper::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Calculator::ContextObjectEventWrapper::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Calculator__ContextObjectEventWrapper.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Calculator::ContextObjectEventWrapper::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 2;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}
struct qt_meta_stringdata_Calculator__ContextObjectPropertyWrapper_t {
    QByteArrayData data[6];
    char stringdata0[71];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Calculator__ContextObjectPropertyWrapper_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Calculator__ContextObjectPropertyWrapper_t qt_meta_stringdata_Calculator__ContextObjectPropertyWrapper = {
    {
QT_MOC_LITERAL(0, 0, 40), // "Calculator::ContextObjectProp..."
QT_MOC_LITERAL(1, 41, 12), // "valueChanged"
QT_MOC_LITERAL(2, 54, 0), // ""
QT_MOC_LITERAL(3, 55, 5), // "value"
QT_MOC_LITERAL(4, 61, 4), // "name"
QT_MOC_LITERAL(5, 66, 4) // "type"

    },
    "Calculator::ContextObjectPropertyWrapper\0"
    "valueChanged\0\0value\0name\0type"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Calculator__ContextObjectPropertyWrapper[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       3,   20, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   19,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,

 // properties: name, type, flags
       3, QMetaType::QVariant, 0x00495103,
       4, QMetaType::QString, 0x00095401,
       5, QMetaType::Int, 0x00095401,

 // properties: notify_signal_id
       0,
       0,
       0,

       0        // eod
};

void Calculator::ContextObjectPropertyWrapper::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ContextObjectPropertyWrapper *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->valueChanged(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ContextObjectPropertyWrapper::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ContextObjectPropertyWrapper::valueChanged)) {
                *result = 0;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<ContextObjectPropertyWrapper *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QVariant*>(_v) = _t->value(); break;
        case 1: *reinterpret_cast< QString*>(_v) = _t->name(); break;
        case 2: *reinterpret_cast< int*>(_v) = _t->type(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<ContextObjectPropertyWrapper *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setValue(*reinterpret_cast< QVariant*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject Calculator::ContextObjectPropertyWrapper::staticMetaObject = { {
    QMetaObject::SuperData::link<ScriptableObject::staticMetaObject>(),
    qt_meta_stringdata_Calculator__ContextObjectPropertyWrapper.data,
    qt_meta_data_Calculator__ContextObjectPropertyWrapper,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Calculator::ContextObjectPropertyWrapper::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Calculator::ContextObjectPropertyWrapper::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Calculator__ContextObjectPropertyWrapper.stringdata0))
        return static_cast<void*>(this);
    return ScriptableObject::qt_metacast(_clname);
}

int Calculator::ContextObjectPropertyWrapper::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = ScriptableObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 3;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void Calculator::ContextObjectPropertyWrapper::valueChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
struct qt_meta_stringdata_Calculator__ContextObjectWrapper_t {
    QByteArrayData data[14];
    char stringdata0[249];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Calculator__ContextObjectWrapper_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Calculator__ContextObjectWrapper_t qt_meta_stringdata_Calculator__ContextObjectWrapper = {
    {
QT_MOC_LITERAL(0, 0, 32), // "Calculator::ContextObjectWrapper"
QT_MOC_LITERAL(1, 33, 6), // "method"
QT_MOC_LITERAL(2, 40, 39), // "Calculator::ContextObjectMeth..."
QT_MOC_LITERAL(3, 80, 0), // ""
QT_MOC_LITERAL(4, 81, 4), // "name"
QT_MOC_LITERAL(5, 86, 5), // "event"
QT_MOC_LITERAL(6, 92, 38), // "Calculator::ContextObjectEven..."
QT_MOC_LITERAL(7, 131, 8), // "property"
QT_MOC_LITERAL(8, 140, 41), // "Calculator::ContextObjectProp..."
QT_MOC_LITERAL(9, 182, 13), // "objectMethods"
QT_MOC_LITERAL(10, 196, 15), // "QList<QObject*>"
QT_MOC_LITERAL(11, 212, 12), // "objectEvents"
QT_MOC_LITERAL(12, 225, 16), // "objectProperties"
QT_MOC_LITERAL(13, 242, 6) // "object"

    },
    "Calculator::ContextObjectWrapper\0"
    "method\0Calculator::ContextObjectMethodWrapper*\0"
    "\0name\0event\0Calculator::ContextObjectEventWrapper*\0"
    "property\0Calculator::ContextObjectPropertyWrapper*\0"
    "objectMethods\0QList<QObject*>\0"
    "objectEvents\0objectProperties\0object"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Calculator__ContextObjectWrapper[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       5,   38, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // methods: name, argc, parameters, tag, flags
       1,    1,   29,    3, 0x02 /* Public */,
       5,    1,   32,    3, 0x02 /* Public */,
       7,    1,   35,    3, 0x02 /* Public */,

 // methods: parameters
    0x80000000 | 2, QMetaType::QString,    4,
    0x80000000 | 6, QMetaType::QString,    4,
    0x80000000 | 8, QMetaType::QString,    4,

 // properties: name, type, flags
       4, QMetaType::QString, 0x00095401,
       9, 0x80000000 | 10, 0x00095409,
      11, 0x80000000 | 10, 0x00095409,
      12, 0x80000000 | 10, 0x00095409,
      13, QMetaType::QObjectStar, 0x00095401,

       0        // eod
};

void Calculator::ContextObjectWrapper::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ContextObjectWrapper *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: { Calculator::ContextObjectMethodWrapper* _r = _t->method((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< Calculator::ContextObjectMethodWrapper**>(_a[0]) = std::move(_r); }  break;
        case 1: { Calculator::ContextObjectEventWrapper* _r = _t->event((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< Calculator::ContextObjectEventWrapper**>(_a[0]) = std::move(_r); }  break;
        case 2: { Calculator::ContextObjectPropertyWrapper* _r = _t->property((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< Calculator::ContextObjectPropertyWrapper**>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterPropertyMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 3:
        case 2:
        case 1:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<QObject*> >(); break;
        }
    }

#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<ContextObjectWrapper *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = _t->name(); break;
        case 1: *reinterpret_cast< QList<QObject*>*>(_v) = _t->objectMethods(); break;
        case 2: *reinterpret_cast< QList<QObject*>*>(_v) = _t->objectEvents(); break;
        case 3: *reinterpret_cast< QList<QObject*>*>(_v) = _t->objectProperties(); break;
        case 4: *reinterpret_cast< QObject**>(_v) = _t->object(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject Calculator::ContextObjectWrapper::staticMetaObject = { {
    QMetaObject::SuperData::link<ScriptableObject::staticMetaObject>(),
    qt_meta_stringdata_Calculator__ContextObjectWrapper.data,
    qt_meta_data_Calculator__ContextObjectWrapper,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Calculator::ContextObjectWrapper::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Calculator::ContextObjectWrapper::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Calculator__ContextObjectWrapper.stringdata0))
        return static_cast<void*>(this);
    return ScriptableObject::qt_metacast(_clname);
}

int Calculator::ContextObjectWrapper::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = ScriptableObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 5;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}
struct qt_meta_stringdata_Calculator__ScriptAction_t {
    QByteArrayData data[6];
    char stringdata0[51];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Calculator__ScriptAction_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Calculator__ScriptAction_t qt_meta_stringdata_Calculator__ScriptAction = {
    {
QT_MOC_LITERAL(0, 0, 24), // "Calculator::ScriptAction"
QT_MOC_LITERAL(1, 25, 7), // "trigger"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 6), // "inPath"
QT_MOC_LITERAL(4, 41, 4), // "path"
QT_MOC_LITERAL(5, 46, 4) // "name"

    },
    "Calculator::ScriptAction\0trigger\0\0"
    "inPath\0path\0name"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Calculator__ScriptAction[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       1,   28, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // methods: name, argc, parameters, tag, flags
       1,    0,   24,    2, 0x02 /* Public */,
       3,    1,   25,    2, 0x02 /* Public */,

 // methods: parameters
    QMetaType::Void,
    QMetaType::Bool, QMetaType::QString,    4,

 // properties: name, type, flags
       5, QMetaType::QString, 0x00095401,

       0        // eod
};

void Calculator::ScriptAction::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ScriptAction *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->trigger(); break;
        case 1: { bool _r = _t->inPath((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<ScriptAction *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = _t->name(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject Calculator::ScriptAction::staticMetaObject = { {
    QMetaObject::SuperData::link<ScriptableObject::staticMetaObject>(),
    qt_meta_stringdata_Calculator__ScriptAction.data,
    qt_meta_data_Calculator__ScriptAction,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Calculator::ScriptAction::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Calculator::ScriptAction::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Calculator__ScriptAction.stringdata0))
        return static_cast<void*>(this);
    return ScriptableObject::qt_metacast(_clname);
}

int Calculator::ScriptAction::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = ScriptableObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 1;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}
struct qt_meta_stringdata_Calculator__Simulator_t {
    QByteArrayData data[80];
    char stringdata0[1094];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Calculator__Simulator_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Calculator__Simulator_t qt_meta_stringdata_Calculator__Simulator = {
    {
QT_MOC_LITERAL(0, 0, 21), // "Calculator::Simulator"
QT_MOC_LITERAL(1, 22, 23), // "activeScriptPathChanged"
QT_MOC_LITERAL(2, 46, 0), // ""
QT_MOC_LITERAL(3, 47, 29), // "sessionRecordingActiveChanged"
QT_MOC_LITERAL(4, 77, 38), // "sessionRecordingClickEventPau..."
QT_MOC_LITERAL(5, 116, 26), // "sessionReplayActiveChanged"
QT_MOC_LITERAL(6, 143, 17), // "serverPortChanged"
QT_MOC_LITERAL(7, 161, 24), // "activeConnectionsChanged"
QT_MOC_LITERAL(8, 186, 22), // "availableThemesChanged"
QT_MOC_LITERAL(9, 209, 14), // "scriptsChanged"
QT_MOC_LITERAL(10, 224, 34), // "connectionDirectionReversedCh..."
QT_MOC_LITERAL(11, 259, 20), // "activateScriptPathAt"
QT_MOC_LITERAL(12, 280, 11), // "QModelIndex"
QT_MOC_LITERAL(13, 292, 5), // "index"
QT_MOC_LITERAL(14, 298, 6), // "object"
QT_MOC_LITERAL(15, 305, 33), // "Calculator::ContextObjectWrap..."
QT_MOC_LITERAL(16, 339, 4), // "name"
QT_MOC_LITERAL(17, 344, 6), // "script"
QT_MOC_LITERAL(18, 351, 25), // "Calculator::ScriptAction*"
QT_MOC_LITERAL(19, 377, 6), // "msleep"
QT_MOC_LITERAL(20, 384, 5), // "msecs"
QT_MOC_LITERAL(21, 390, 7), // "trigger"
QT_MOC_LITERAL(22, 398, 10), // "afterMsecs"
QT_MOC_LITERAL(23, 409, 9), // "addScript"
QT_MOC_LITERAL(24, 419, 12), // "removeScript"
QT_MOC_LITERAL(25, 432, 13), // "activateTheme"
QT_MOC_LITERAL(26, 446, 7), // "themeId"
QT_MOC_LITERAL(27, 454, 15), // "objectTriggered"
QT_MOC_LITERAL(28, 470, 3), // "obj"
QT_MOC_LITERAL(29, 474, 15), // "addSessionDelay"
QT_MOC_LITERAL(30, 490, 2), // "ms"
QT_MOC_LITERAL(31, 493, 11), // "saveSession"
QT_MOC_LITERAL(32, 505, 7), // "fileUrl"
QT_MOC_LITERAL(33, 513, 11), // "loadSession"
QT_MOC_LITERAL(34, 525, 6), // "replay"
QT_MOC_LITERAL(35, 532, 11), // "sessionName"
QT_MOC_LITERAL(36, 544, 12), // "startProcess"
QT_MOC_LITERAL(37, 557, 7), // "command"
QT_MOC_LITERAL(38, 565, 7), // "argList"
QT_MOC_LITERAL(39, 573, 11), // "stopProcess"
QT_MOC_LITERAL(40, 585, 6), // "procId"
QT_MOC_LITERAL(41, 592, 11), // "killProcess"
QT_MOC_LITERAL(42, 604, 18), // "simulateClickEvent"
QT_MOC_LITERAL(43, 623, 6), // "mouseX"
QT_MOC_LITERAL(44, 630, 6), // "mouseY"
QT_MOC_LITERAL(45, 637, 10), // "rightClick"
QT_MOC_LITERAL(46, 648, 13), // "captureScreen"
QT_MOC_LITERAL(47, 662, 12), // "saveLocation"
QT_MOC_LITERAL(48, 675, 7), // "tabList"
QT_MOC_LITERAL(49, 683, 13), // "extraPageList"
QT_MOC_LITERAL(50, 697, 23), // "actionScriptFolderModel"
QT_MOC_LITERAL(51, 721, 17), // "QFileSystemModel*"
QT_MOC_LITERAL(52, 739, 21), // "actionScriptRootIndex"
QT_MOC_LITERAL(53, 761, 16), // "activeScriptPath"
QT_MOC_LITERAL(54, 778, 7), // "objects"
QT_MOC_LITERAL(55, 786, 15), // "QList<QObject*>"
QT_MOC_LITERAL(56, 802, 7), // "scripts"
QT_MOC_LITERAL(57, 810, 15), // "availableThemes"
QT_MOC_LITERAL(58, 826, 22), // "sessionRecordingActive"
QT_MOC_LITERAL(59, 849, 31), // "sessionRecordingClickEventPause"
QT_MOC_LITERAL(60, 881, 19), // "sessionReplayActive"
QT_MOC_LITERAL(61, 901, 10), // "serverPort"
QT_MOC_LITERAL(62, 912, 17), // "activeConnections"
QT_MOC_LITERAL(63, 930, 13), // "serverPortMin"
QT_MOC_LITERAL(64, 944, 13), // "serverPortMax"
QT_MOC_LITERAL(65, 958, 27), // "connectionDirectionReversed"
QT_MOC_LITERAL(66, 986, 11), // "ArgumenType"
QT_MOC_LITERAL(67, 998, 3), // "Var"
QT_MOC_LITERAL(68, 1002, 4), // "List"
QT_MOC_LITERAL(69, 1007, 3), // "Map"
QT_MOC_LITERAL(70, 1011, 6), // "String"
QT_MOC_LITERAL(71, 1018, 3), // "Int"
QT_MOC_LITERAL(72, 1022, 6), // "Double"
QT_MOC_LITERAL(73, 1029, 5), // "Float"
QT_MOC_LITERAL(74, 1035, 4), // "Bool"
QT_MOC_LITERAL(75, 1040, 9), // "ObjectPtr"
QT_MOC_LITERAL(76, 1050, 5), // "Model"
QT_MOC_LITERAL(77, 1056, 18), // "TranslatableString"
QT_MOC_LITERAL(78, 1075, 9), // "ByteArray"
QT_MOC_LITERAL(79, 1085, 8) // "UserType"

    },
    "Calculator::Simulator\0activeScriptPathChanged\0"
    "\0sessionRecordingActiveChanged\0"
    "sessionRecordingClickEventPauseChanged\0"
    "sessionReplayActiveChanged\0serverPortChanged\0"
    "activeConnectionsChanged\0"
    "availableThemesChanged\0scriptsChanged\0"
    "connectionDirectionReversedChanged\0"
    "activateScriptPathAt\0QModelIndex\0index\0"
    "object\0Calculator::ContextObjectWrapper*\0"
    "name\0script\0Calculator::ScriptAction*\0"
    "msleep\0msecs\0trigger\0afterMsecs\0"
    "addScript\0removeScript\0activateTheme\0"
    "themeId\0objectTriggered\0obj\0addSessionDelay\0"
    "ms\0saveSession\0fileUrl\0loadSession\0"
    "replay\0sessionName\0startProcess\0command\0"
    "argList\0stopProcess\0procId\0killProcess\0"
    "simulateClickEvent\0mouseX\0mouseY\0"
    "rightClick\0captureScreen\0saveLocation\0"
    "tabList\0extraPageList\0actionScriptFolderModel\0"
    "QFileSystemModel*\0actionScriptRootIndex\0"
    "activeScriptPath\0objects\0QList<QObject*>\0"
    "scripts\0availableThemes\0sessionRecordingActive\0"
    "sessionRecordingClickEventPause\0"
    "sessionReplayActive\0serverPort\0"
    "activeConnections\0serverPortMin\0"
    "serverPortMax\0connectionDirectionReversed\0"
    "ArgumenType\0Var\0List\0Map\0String\0Int\0"
    "Double\0Float\0Bool\0ObjectPtr\0Model\0"
    "TranslatableString\0ByteArray\0UserType"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Calculator__Simulator[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      31,   14, // methods
      16,  256, // properties
       1,  320, // enums/sets
       0,    0, // constructors
       0,       // flags
       9,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,  169,    2, 0x06 /* Public */,
       3,    0,  170,    2, 0x06 /* Public */,
       4,    0,  171,    2, 0x06 /* Public */,
       5,    0,  172,    2, 0x06 /* Public */,
       6,    0,  173,    2, 0x06 /* Public */,
       7,    0,  174,    2, 0x06 /* Public */,
       8,    0,  175,    2, 0x06 /* Public */,
       9,    0,  176,    2, 0x06 /* Public */,
      10,    0,  177,    2, 0x06 /* Public */,

 // methods: name, argc, parameters, tag, flags
      11,    1,  178,    2, 0x02 /* Public */,
      14,    1,  181,    2, 0x02 /* Public */,
      17,    1,  184,    2, 0x02 /* Public */,
      19,    1,  187,    2, 0x02 /* Public */,
      21,    2,  190,    2, 0x02 /* Public */,
      21,    1,  195,    2, 0x22 /* Public | MethodCloned */,
      23,    1,  198,    2, 0x02 /* Public */,
      24,    1,  201,    2, 0x02 /* Public */,
      25,    1,  204,    2, 0x02 /* Public */,
      27,    1,  207,    2, 0x02 /* Public */,
      29,    1,  210,    2, 0x02 /* Public */,
      31,    1,  213,    2, 0x02 /* Public */,
      33,    1,  216,    2, 0x02 /* Public */,
      34,    2,  219,    2, 0x02 /* Public */,
      34,    1,  224,    2, 0x22 /* Public | MethodCloned */,
      36,    2,  227,    2, 0x02 /* Public */,
      36,    1,  232,    2, 0x22 /* Public | MethodCloned */,
      39,    1,  235,    2, 0x02 /* Public */,
      41,    1,  238,    2, 0x02 /* Public */,
      42,    3,  241,    2, 0x02 /* Public */,
      42,    2,  248,    2, 0x22 /* Public | MethodCloned */,
      46,    1,  253,    2, 0x02 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // methods: parameters
    QMetaType::Void, 0x80000000 | 12,   13,
    0x80000000 | 15, QMetaType::QString,   16,
    0x80000000 | 18, QMetaType::QString,   16,
    QMetaType::Void, QMetaType::Int,   20,
    QMetaType::Void, QMetaType::QString, QMetaType::Int,   16,   22,
    QMetaType::Void, QMetaType::QString,   16,
    QMetaType::Bool, QMetaType::QString,   16,
    QMetaType::Bool, QMetaType::QString,   16,
    QMetaType::Void, QMetaType::QString,   26,
    QMetaType::Void, QMetaType::QObjectStar,   28,
    QMetaType::Void, QMetaType::Int,   30,
    QMetaType::Void, QMetaType::QUrl,   32,
    QMetaType::Void, QMetaType::QUrl,   32,
    QMetaType::Void, QMetaType::QString, QMetaType::Int,   35,   22,
    QMetaType::Void, QMetaType::QString,   35,
    QMetaType::QUuid, QMetaType::QString, QMetaType::QStringList,   37,   38,
    QMetaType::QUuid, QMetaType::QString,   37,
    QMetaType::Void, QMetaType::QUuid,   40,
    QMetaType::Void, QMetaType::QUuid,   40,
    QMetaType::Void, QMetaType::QReal, QMetaType::QReal, QMetaType::Bool,   43,   44,   45,
    QMetaType::Void, QMetaType::QReal, QMetaType::QReal,   43,   44,
    QMetaType::Void, QMetaType::QString,   47,

 // properties: name, type, flags
      48, QMetaType::QStringList, 0x00095401,
      49, QMetaType::QStringList, 0x00095401,
      50, 0x80000000 | 51, 0x00095409,
      52, 0x80000000 | 12, 0x00095409,
      53, QMetaType::QString, 0x00495001,
      54, 0x80000000 | 55, 0x00095409,
      56, 0x80000000 | 55, 0x00495009,
      57, QMetaType::QStringList, 0x00495001,
      58, QMetaType::Bool, 0x00495103,
      59, QMetaType::Int, 0x00495103,
      60, QMetaType::Bool, 0x00495001,
      61, QMetaType::Int, 0x00495103,
      62, QMetaType::Int, 0x00495001,
      63, QMetaType::Int, 0x00095401,
      64, QMetaType::Int, 0x00095401,
      65, QMetaType::Bool, 0x00495001,

 // properties: notify_signal_id
       0,
       0,
       0,
       0,
       0,
       0,
       7,
       6,
       1,
       2,
       3,
       4,
       5,
       0,
       0,
       8,

 // enums: name, alias, flags, count, data
      66,   66, 0x0,   13,  325,

 // enum data: key, value
      67, uint(Calculator::Simulator::Var),
      68, uint(Calculator::Simulator::List),
      69, uint(Calculator::Simulator::Map),
      70, uint(Calculator::Simulator::String),
      71, uint(Calculator::Simulator::Int),
      72, uint(Calculator::Simulator::Double),
      73, uint(Calculator::Simulator::Float),
      74, uint(Calculator::Simulator::Bool),
      75, uint(Calculator::Simulator::ObjectPtr),
      76, uint(Calculator::Simulator::Model),
      77, uint(Calculator::Simulator::TranslatableString),
      78, uint(Calculator::Simulator::ByteArray),
      79, uint(Calculator::Simulator::UserType),

       0        // eod
};

void Calculator::Simulator::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Simulator *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->activeScriptPathChanged(); break;
        case 1: _t->sessionRecordingActiveChanged(); break;
        case 2: _t->sessionRecordingClickEventPauseChanged(); break;
        case 3: _t->sessionReplayActiveChanged(); break;
        case 4: _t->serverPortChanged(); break;
        case 5: _t->activeConnectionsChanged(); break;
        case 6: _t->availableThemesChanged(); break;
        case 7: _t->scriptsChanged(); break;
        case 8: _t->connectionDirectionReversedChanged(); break;
        case 9: _t->activateScriptPathAt((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 10: { Calculator::ContextObjectWrapper* _r = _t->object((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< Calculator::ContextObjectWrapper**>(_a[0]) = std::move(_r); }  break;
        case 11: { Calculator::ScriptAction* _r = _t->script((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< Calculator::ScriptAction**>(_a[0]) = std::move(_r); }  break;
        case 12: _t->msleep((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 13: _t->trigger((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 14: _t->trigger((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 15: { bool _r = _t->addScript((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 16: { bool _r = _t->removeScript((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 17: _t->activateTheme((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 18: _t->objectTriggered((*reinterpret_cast< QObject*(*)>(_a[1]))); break;
        case 19: _t->addSessionDelay((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 20: _t->saveSession((*reinterpret_cast< const QUrl(*)>(_a[1]))); break;
        case 21: _t->loadSession((*reinterpret_cast< const QUrl(*)>(_a[1]))); break;
        case 22: _t->replay((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 23: _t->replay((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 24: { QUuid _r = _t->startProcess((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QStringList(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QUuid*>(_a[0]) = std::move(_r); }  break;
        case 25: { QUuid _r = _t->startProcess((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QUuid*>(_a[0]) = std::move(_r); }  break;
        case 26: _t->stopProcess((*reinterpret_cast< const QUuid(*)>(_a[1]))); break;
        case 27: _t->killProcess((*reinterpret_cast< const QUuid(*)>(_a[1]))); break;
        case 28: _t->simulateClickEvent((*reinterpret_cast< qreal(*)>(_a[1])),(*reinterpret_cast< qreal(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        case 29: _t->simulateClickEvent((*reinterpret_cast< qreal(*)>(_a[1])),(*reinterpret_cast< qreal(*)>(_a[2]))); break;
        case 30: _t->captureScreen((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Simulator::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Simulator::activeScriptPathChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Simulator::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Simulator::sessionRecordingActiveChanged)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Simulator::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Simulator::sessionRecordingClickEventPauseChanged)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (Simulator::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Simulator::sessionReplayActiveChanged)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (Simulator::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Simulator::serverPortChanged)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (Simulator::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Simulator::activeConnectionsChanged)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (Simulator::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Simulator::availableThemesChanged)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (Simulator::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Simulator::scriptsChanged)) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (Simulator::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Simulator::connectionDirectionReversedChanged)) {
                *result = 8;
                return;
            }
        }
    } else if (_c == QMetaObject::RegisterPropertyMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 2:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QFileSystemModel* >(); break;
        case 6:
        case 5:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<QObject*> >(); break;
        }
    }

#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<Simulator *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QStringList*>(_v) = _t->tabList(); break;
        case 1: *reinterpret_cast< QStringList*>(_v) = _t->extraPageList(); break;
        case 2: *reinterpret_cast< QFileSystemModel**>(_v) = _t->actionScriptFolderModel(); break;
        case 3: *reinterpret_cast< QModelIndex*>(_v) = _t->actionScriptRootIndex(); break;
        case 4: *reinterpret_cast< QString*>(_v) = _t->activeScriptPath(); break;
        case 5: *reinterpret_cast< QList<QObject*>*>(_v) = _t->objects(); break;
        case 6: *reinterpret_cast< QList<QObject*>*>(_v) = _t->scripts(); break;
        case 7: *reinterpret_cast< QStringList*>(_v) = _t->availableThemes(); break;
        case 8: *reinterpret_cast< bool*>(_v) = _t->sessionRecordingActive(); break;
        case 9: *reinterpret_cast< int*>(_v) = _t->sessionRecordingClickEventPause(); break;
        case 10: *reinterpret_cast< bool*>(_v) = _t->sessionReplayActive(); break;
        case 11: *reinterpret_cast< int*>(_v) = _t->serverPort(); break;
        case 12: *reinterpret_cast< int*>(_v) = _t->activeConnections(); break;
        case 13: *reinterpret_cast< int*>(_v) = _t->serverPortMin(); break;
        case 14: *reinterpret_cast< int*>(_v) = _t->serverPortMax(); break;
        case 15: *reinterpret_cast< bool*>(_v) = _t->connectionDirectionReversed(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<Simulator *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 8: _t->setSessionRecordingActive(*reinterpret_cast< bool*>(_v)); break;
        case 9: _t->setSessionRecordingClickEventPause(*reinterpret_cast< int*>(_v)); break;
        case 11: _t->setServerPort(*reinterpret_cast< int*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject Calculator::Simulator::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_Calculator__Simulator.data,
    qt_meta_data_Calculator__Simulator,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Calculator::Simulator::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Calculator::Simulator::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Calculator__Simulator.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Calculator::Simulator::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 31)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 31;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 31)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 31;
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 16;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 16;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 16;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 16;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 16;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void Calculator::Simulator::activeScriptPathChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void Calculator::Simulator::sessionRecordingActiveChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void Calculator::Simulator::sessionRecordingClickEventPauseChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void Calculator::Simulator::sessionReplayActiveChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void Calculator::Simulator::serverPortChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void Calculator::Simulator::activeConnectionsChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void Calculator::Simulator::availableThemesChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}

// SIGNAL 7
void Calculator::Simulator::scriptsChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 7, nullptr);
}

// SIGNAL 8
void Calculator::Simulator::connectionDirectionReversedChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 8, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
