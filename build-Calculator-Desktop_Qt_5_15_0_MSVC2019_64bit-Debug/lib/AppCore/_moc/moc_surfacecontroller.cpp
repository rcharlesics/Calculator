/****************************************************************************
** Meta object code from reading C++ file 'surfacecontroller.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../Calculator/lib/AppCore/Calculator/surfacecontroller.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'surfacecontroller.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Calculator__SurfaceController_t {
    QByteArrayData data[10];
    char stringdata0[155];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Calculator__SurfaceController_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Calculator__SurfaceController_t qt_meta_stringdata_Calculator__SurfaceController = {
    {
QT_MOC_LITERAL(0, 0, 29), // "Calculator::SurfaceController"
QT_MOC_LITERAL(1, 30, 10), // "showPopups"
QT_MOC_LITERAL(2, 41, 0), // ""
QT_MOC_LITERAL(3, 42, 10), // "hidePopups"
QT_MOC_LITERAL(4, 53, 9), // "showMenus"
QT_MOC_LITERAL(5, 63, 9), // "hideMenus"
QT_MOC_LITERAL(6, 73, 16), // "surfaceMenusBack"
QT_MOC_LITERAL(7, 90, 12), // "showMainView"
QT_MOC_LITERAL(8, 103, 12), // "hideMainView"
QT_MOC_LITERAL(9, 116, 38) // "surfaceMainViewMoveToMainView..."

    },
    "Calculator::SurfaceController\0showPopups\0"
    "\0hidePopups\0showMenus\0hideMenus\0"
    "surfaceMenusBack\0showMainView\0"
    "hideMainView\0surfaceMainViewMoveToMainView_MainView"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Calculator__SurfaceController[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       8,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x06 /* Public */,
       3,    0,   55,    2, 0x06 /* Public */,
       4,    0,   56,    2, 0x06 /* Public */,
       5,    0,   57,    2, 0x06 /* Public */,
       6,    0,   58,    2, 0x06 /* Public */,
       7,    0,   59,    2, 0x06 /* Public */,
       8,    0,   60,    2, 0x06 /* Public */,
       9,    0,   61,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Calculator::SurfaceController::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<SurfaceController *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->showPopups(); break;
        case 1: _t->hidePopups(); break;
        case 2: _t->showMenus(); break;
        case 3: _t->hideMenus(); break;
        case 4: _t->surfaceMenusBack(); break;
        case 5: _t->showMainView(); break;
        case 6: _t->hideMainView(); break;
        case 7: _t->surfaceMainViewMoveToMainView_MainView(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (SurfaceController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SurfaceController::showPopups)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (SurfaceController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SurfaceController::hidePopups)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (SurfaceController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SurfaceController::showMenus)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (SurfaceController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SurfaceController::hideMenus)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (SurfaceController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SurfaceController::surfaceMenusBack)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (SurfaceController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SurfaceController::showMainView)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (SurfaceController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SurfaceController::hideMainView)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (SurfaceController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SurfaceController::surfaceMainViewMoveToMainView_MainView)) {
                *result = 7;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject Calculator::SurfaceController::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_Calculator__SurfaceController.data,
    qt_meta_data_Calculator__SurfaceController,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Calculator::SurfaceController::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Calculator::SurfaceController::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Calculator__SurfaceController.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "GreenHouse::ContextObjectAPI<Id::SurfaceControllerId>"))
        return static_cast< GreenHouse::ContextObjectAPI<Id::SurfaceControllerId>*>(this);
    return QObject::qt_metacast(_clname);
}

int Calculator::SurfaceController::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void Calculator::SurfaceController::showPopups()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void Calculator::SurfaceController::hidePopups()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void Calculator::SurfaceController::showMenus()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void Calculator::SurfaceController::hideMenus()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void Calculator::SurfaceController::surfaceMenusBack()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void Calculator::SurfaceController::showMainView()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void Calculator::SurfaceController::hideMainView()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}

// SIGNAL 7
void Calculator::SurfaceController::surfaceMainViewMoveToMainView_MainView()
{
    QMetaObject::activate(this, &staticMetaObject, 7, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
