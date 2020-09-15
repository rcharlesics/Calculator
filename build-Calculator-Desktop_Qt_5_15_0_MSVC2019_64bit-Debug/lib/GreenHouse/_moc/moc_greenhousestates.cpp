/****************************************************************************
** Meta object code from reading C++ file 'greenhousestates.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../Calculator/lib/GreenHouse/greenhousestates.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'greenhousestates.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_GreenHouse__State_t {
    QByteArrayData data[1];
    char stringdata0[18];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GreenHouse__State_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GreenHouse__State_t qt_meta_stringdata_GreenHouse__State = {
    {
QT_MOC_LITERAL(0, 0, 17) // "GreenHouse::State"

    },
    "GreenHouse::State"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GreenHouse__State[] = {

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

void GreenHouse::State::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject GreenHouse::State::staticMetaObject = { {
    QMetaObject::SuperData::link<QState::staticMetaObject>(),
    qt_meta_stringdata_GreenHouse__State.data,
    qt_meta_data_GreenHouse__State,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *GreenHouse::State::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GreenHouse::State::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_GreenHouse__State.stringdata0))
        return static_cast<void*>(this);
    return QState::qt_metacast(_clname);
}

int GreenHouse::State::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QState::qt_metacall(_c, _id, _a);
    return _id;
}
struct qt_meta_stringdata_GreenHouse__LayerState_t {
    QByteArrayData data[1];
    char stringdata0[23];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GreenHouse__LayerState_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GreenHouse__LayerState_t qt_meta_stringdata_GreenHouse__LayerState = {
    {
QT_MOC_LITERAL(0, 0, 22) // "GreenHouse::LayerState"

    },
    "GreenHouse::LayerState"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GreenHouse__LayerState[] = {

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

void GreenHouse::LayerState::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject GreenHouse::LayerState::staticMetaObject = { {
    QMetaObject::SuperData::link<State::staticMetaObject>(),
    qt_meta_stringdata_GreenHouse__LayerState.data,
    qt_meta_data_GreenHouse__LayerState,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *GreenHouse::LayerState::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GreenHouse::LayerState::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_GreenHouse__LayerState.stringdata0))
        return static_cast<void*>(this);
    return State::qt_metacast(_clname);
}

int GreenHouse::LayerState::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = State::qt_metacall(_c, _id, _a);
    return _id;
}
struct qt_meta_stringdata_GreenHouse__ItemState_t {
    QByteArrayData data[6];
    char stringdata0[75];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GreenHouse__ItemState_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GreenHouse__ItemState_t qt_meta_stringdata_GreenHouse__ItemState = {
    {
QT_MOC_LITERAL(0, 0, 21), // "GreenHouse::ItemState"
QT_MOC_LITERAL(1, 22, 19), // "itemPropertyChanged"
QT_MOC_LITERAL(2, 42, 0), // ""
QT_MOC_LITERAL(3, 43, 4), // "name"
QT_MOC_LITERAL(4, 48, 5), // "value"
QT_MOC_LITERAL(5, 54, 20) // "itemInterfaceChanged"

    },
    "GreenHouse::ItemState\0itemPropertyChanged\0"
    "\0name\0value\0itemInterfaceChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GreenHouse__ItemState[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   24,    2, 0x06 /* Public */,
       5,    0,   29,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QVariant,    3,    4,
    QMetaType::Void,

       0        // eod
};

void GreenHouse::ItemState::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ItemState *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->itemPropertyChanged((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QVariant(*)>(_a[2]))); break;
        case 1: _t->itemInterfaceChanged(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ItemState::*)(const QString & , const QVariant & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ItemState::itemPropertyChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (ItemState::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ItemState::itemInterfaceChanged)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject GreenHouse::ItemState::staticMetaObject = { {
    QMetaObject::SuperData::link<State::staticMetaObject>(),
    qt_meta_stringdata_GreenHouse__ItemState.data,
    qt_meta_data_GreenHouse__ItemState,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *GreenHouse::ItemState::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GreenHouse::ItemState::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_GreenHouse__ItemState.stringdata0))
        return static_cast<void*>(this);
    return State::qt_metacast(_clname);
}

int GreenHouse::ItemState::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = State::qt_metacall(_c, _id, _a);
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
    return _id;
}

// SIGNAL 0
void GreenHouse::ItemState::itemPropertyChanged(const QString & _t1, const QVariant & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void GreenHouse::ItemState::itemInterfaceChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
struct qt_meta_stringdata_GreenHouse__ConditionalState_t {
    QByteArrayData data[4];
    char stringdata0[66];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GreenHouse__ConditionalState_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GreenHouse__ConditionalState_t qt_meta_stringdata_GreenHouse__ConditionalState = {
    {
QT_MOC_LITERAL(0, 0, 28), // "GreenHouse::ConditionalState"
QT_MOC_LITERAL(1, 29, 16), // "validTargetFound"
QT_MOC_LITERAL(2, 46, 0), // ""
QT_MOC_LITERAL(3, 47, 18) // "noValidTargetFound"

    },
    "GreenHouse::ConditionalState\0"
    "validTargetFound\0\0noValidTargetFound"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GreenHouse__ConditionalState[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   24,    2, 0x06 /* Public */,
       3,    0,   25,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void GreenHouse::ConditionalState::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ConditionalState *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->validTargetFound(); break;
        case 1: _t->noValidTargetFound(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ConditionalState::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ConditionalState::validTargetFound)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (ConditionalState::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ConditionalState::noValidTargetFound)) {
                *result = 1;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject GreenHouse::ConditionalState::staticMetaObject = { {
    QMetaObject::SuperData::link<State::staticMetaObject>(),
    qt_meta_stringdata_GreenHouse__ConditionalState.data,
    qt_meta_data_GreenHouse__ConditionalState,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *GreenHouse::ConditionalState::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GreenHouse::ConditionalState::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_GreenHouse__ConditionalState.stringdata0))
        return static_cast<void*>(this);
    return State::qt_metacast(_clname);
}

int GreenHouse::ConditionalState::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = State::qt_metacall(_c, _id, _a);
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
    return _id;
}

// SIGNAL 0
void GreenHouse::ConditionalState::validTargetFound()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void GreenHouse::ConditionalState::noValidTargetFound()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
