/****************************************************************************
** Meta object code from reading C++ file 'greenhousetheme.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../Calculator/lib/GreenHouse/greenhousetheme.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'greenhousetheme.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_GreenHouse__Theme_t {
    QByteArrayData data[26];
    char stringdata0[263];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GreenHouse__Theme_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GreenHouse__Theme_t qt_meta_stringdata_GreenHouse__Theme = {
    {
QT_MOC_LITERAL(0, 0, 17), // "GreenHouse::Theme"
QT_MOC_LITERAL(1, 18, 19), // "themeBaseDirChanged"
QT_MOC_LITERAL(2, 38, 0), // ""
QT_MOC_LITERAL(3, 39, 5), // "asset"
QT_MOC_LITERAL(4, 45, 2), // "id"
QT_MOC_LITERAL(5, 48, 19), // "animationFrameAsset"
QT_MOC_LITERAL(6, 68, 5), // "frame"
QT_MOC_LITERAL(7, 74, 13), // "frameIdLength"
QT_MOC_LITERAL(8, 88, 12), // "coloredAsset"
QT_MOC_LITERAL(9, 101, 7), // "colorId"
QT_MOC_LITERAL(10, 109, 4), // "font"
QT_MOC_LITERAL(11, 114, 5), // "color"
QT_MOC_LITERAL(12, 120, 15), // "foregroundColor"
QT_MOC_LITERAL(13, 136, 15), // "backgroundColor"
QT_MOC_LITERAL(14, 152, 8), // "fallback"
QT_MOC_LITERAL(15, 161, 19), // "alternativeColorIds"
QT_MOC_LITERAL(16, 181, 9), // "assetHash"
QT_MOC_LITERAL(17, 191, 12), // "assetDataStr"
QT_MOC_LITERAL(18, 204, 12), // "themeBaseDir"
QT_MOC_LITERAL(19, 217, 12), // "cacheEffects"
QT_MOC_LITERAL(20, 230, 4), // "Type"
QT_MOC_LITERAL(21, 235, 5), // "Color"
QT_MOC_LITERAL(22, 241, 4), // "Font"
QT_MOC_LITERAL(23, 246, 6), // "String"
QT_MOC_LITERAL(24, 253, 3), // "Int"
QT_MOC_LITERAL(25, 257, 5) // "Asset"

    },
    "GreenHouse::Theme\0themeBaseDirChanged\0"
    "\0asset\0id\0animationFrameAsset\0frame\0"
    "frameIdLength\0coloredAsset\0colorId\0"
    "font\0color\0foregroundColor\0backgroundColor\0"
    "fallback\0alternativeColorIds\0assetHash\0"
    "assetDataStr\0themeBaseDir\0cacheEffects\0"
    "Type\0Color\0Font\0String\0Int\0Asset"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GreenHouse__Theme[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       2,  100, // properties
       1,  108, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   64,    2, 0x06 /* Public */,

 // methods: name, argc, parameters, tag, flags
       3,    1,   65,    2, 0x02 /* Public */,
       5,    3,   68,    2, 0x02 /* Public */,
       8,    2,   75,    2, 0x02 /* Public */,
      10,    1,   80,    2, 0x02 /* Public */,
      11,    1,   83,    2, 0x02 /* Public */,
      12,    2,   86,    2, 0x02 /* Public */,
       9,    1,   91,    2, 0x02 /* Public */,
      15,    1,   94,    2, 0x02 /* Public */,
      16,    1,   97,    2, 0x02 /* Public */,

 // signals: parameters
    QMetaType::Void,

 // methods: parameters
    QMetaType::QUrl, QMetaType::QString,    4,
    QMetaType::QUrl, QMetaType::QString, QMetaType::Int, QMetaType::Int,    4,    6,    7,
    QMetaType::QUrl, QMetaType::QString, QMetaType::QString,    4,    9,
    QMetaType::QFont, QMetaType::QString,    4,
    QMetaType::QColor, QMetaType::QString,    4,
    QMetaType::QColor, QMetaType::QColor, QMetaType::QColor,   13,   14,
    QMetaType::QString, QMetaType::QColor,   11,
    QMetaType::QStringList, QMetaType::QString,    4,
    QMetaType::QByteArray, QMetaType::QByteArray,   17,

 // properties: name, type, flags
      18, QMetaType::QString, 0x00495103,
      19, QMetaType::Bool, 0x00095401,

 // properties: notify_signal_id
       0,
       0,

 // enums: name, alias, flags, count, data
      20,   20, 0x0,    5,  113,

 // enum data: key, value
      21, uint(GreenHouse::Theme::Color),
      22, uint(GreenHouse::Theme::Font),
      23, uint(GreenHouse::Theme::String),
      24, uint(GreenHouse::Theme::Int),
      25, uint(GreenHouse::Theme::Asset),

       0        // eod
};

void GreenHouse::Theme::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Theme *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->themeBaseDirChanged(); break;
        case 1: { QUrl _r = _t->asset((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QUrl*>(_a[0]) = std::move(_r); }  break;
        case 2: { QUrl _r = _t->animationFrameAsset((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< QUrl*>(_a[0]) = std::move(_r); }  break;
        case 3: { QUrl _r = _t->coloredAsset((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QUrl*>(_a[0]) = std::move(_r); }  break;
        case 4: { QFont _r = _t->font((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QFont*>(_a[0]) = std::move(_r); }  break;
        case 5: { QColor _r = _t->color((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QColor*>(_a[0]) = std::move(_r); }  break;
        case 6: { QColor _r = _t->foregroundColor((*reinterpret_cast< const QColor(*)>(_a[1])),(*reinterpret_cast< const QColor(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QColor*>(_a[0]) = std::move(_r); }  break;
        case 7: { QString _r = _t->colorId((*reinterpret_cast< const QColor(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 8: { QStringList _r = _t->alternativeColorIds((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QStringList*>(_a[0]) = std::move(_r); }  break;
        case 9: { QByteArray _r = _t->assetHash((*reinterpret_cast< const QByteArray(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QByteArray*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Theme::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Theme::themeBaseDirChanged)) {
                *result = 0;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<Theme *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = _t->themeBaseDir(); break;
        case 1: *reinterpret_cast< bool*>(_v) = _t->cacheEffects(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<Theme *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setThemeBaseDir(*reinterpret_cast< QString*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject GreenHouse::Theme::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_GreenHouse__Theme.data,
    qt_meta_data_GreenHouse__Theme,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *GreenHouse::Theme::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GreenHouse::Theme::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_GreenHouse__Theme.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int GreenHouse::Theme::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
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

// SIGNAL 0
void GreenHouse::Theme::themeBaseDirChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
struct qt_meta_stringdata_GreenHouse__ThemeManager_t {
    QByteArrayData data[6];
    char stringdata0[74];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GreenHouse__ThemeManager_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GreenHouse__ThemeManager_t qt_meta_stringdata_GreenHouse__ThemeManager = {
    {
QT_MOC_LITERAL(0, 0, 24), // "GreenHouse::ThemeManager"
QT_MOC_LITERAL(1, 25, 12), // "themeChanged"
QT_MOC_LITERAL(2, 38, 0), // ""
QT_MOC_LITERAL(3, 39, 5), // "theme"
QT_MOC_LITERAL(4, 45, 18), // "GreenHouse::Theme*"
QT_MOC_LITERAL(5, 64, 9) // "themeName"

    },
    "GreenHouse::ThemeManager\0themeChanged\0"
    "\0theme\0GreenHouse::Theme*\0themeName"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GreenHouse__ThemeManager[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       2,   20, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   19,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,

 // properties: name, type, flags
       3, 0x80000000 | 4, 0x00495009,
       5, QMetaType::QString, 0x00495001,

 // properties: notify_signal_id
       0,
       0,

       0        // eod
};

void GreenHouse::ThemeManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ThemeManager *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->themeChanged(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ThemeManager::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ThemeManager::themeChanged)) {
                *result = 0;
                return;
            }
        }
    } else if (_c == QMetaObject::RegisterPropertyMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< GreenHouse::Theme* >(); break;
        }
    }

#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<ThemeManager *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< GreenHouse::Theme**>(_v) = _t->theme(); break;
        case 1: *reinterpret_cast< QString*>(_v) = _t->themeName(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject GreenHouse::ThemeManager::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_GreenHouse__ThemeManager.data,
    qt_meta_data_GreenHouse__ThemeManager,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *GreenHouse::ThemeManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GreenHouse::ThemeManager::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_GreenHouse__ThemeManager.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int GreenHouse::ThemeManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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

// SIGNAL 0
void GreenHouse::ThemeManager::themeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
