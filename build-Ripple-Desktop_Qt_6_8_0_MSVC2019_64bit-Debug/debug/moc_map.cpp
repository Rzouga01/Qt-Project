/****************************************************************************
** Meta object code from reading C++ file 'map.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Ripple/map.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'map.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSmapENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSmapENDCLASS = QtMocHelpers::stringData(
    "map",
    "setCenter",
    "",
    "addMarker",
    "addSecondMarker",
    "clear",
    "sendClickedCoords",
    "coords",
    "getItemCount",
    "sendValues",
    "value1",
    "value2",
    "handleMapClick",
    "lat",
    "lng",
    "on_pushButton_2_clicked",
    "on_pushButton_clicked",
    "on_comboBox_3_currentTextChanged",
    "arg1"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSmapENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    2,   80,    2, 0x06,    1 /* Public */,
       3,    2,   85,    2, 0x06,    4 /* Public */,
       4,    2,   90,    2, 0x06,    7 /* Public */,
       5,    0,   95,    2, 0x06,   10 /* Public */,
       6,    1,   96,    2, 0x06,   11 /* Public */,
       8,    0,   99,    2, 0x06,   13 /* Public */,
       9,    2,  100,    2, 0x06,   14 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      12,    2,  105,    2, 0x0a,   17 /* Public */,
      15,    0,  110,    2, 0x08,   20 /* Private */,
      16,    0,  111,    2, 0x08,   21 /* Private */,
      17,    1,  112,    2, 0x08,   22 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QVariant, QMetaType::QVariant,    2,    2,
    QMetaType::Void, QMetaType::QVariant, QMetaType::QVariant,    2,    2,
    QMetaType::Void, QMetaType::QVariant, QMetaType::QVariant,    2,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Int,
    QMetaType::Void, QMetaType::Double, QMetaType::Double,   10,   11,

 // slots: parameters
    QMetaType::QString, QMetaType::QVariant, QMetaType::QVariant,   13,   14,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   18,

       0        // eod
};

Q_CONSTINIT const QMetaObject map::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_CLASSmapENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSmapENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSmapENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<map, std::true_type>,
        // method 'setCenter'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QVariant, std::false_type>,
        QtPrivate::TypeAndForceComplete<QVariant, std::false_type>,
        // method 'addMarker'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QVariant, std::false_type>,
        QtPrivate::TypeAndForceComplete<QVariant, std::false_type>,
        // method 'addSecondMarker'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QVariant, std::false_type>,
        QtPrivate::TypeAndForceComplete<QVariant, std::false_type>,
        // method 'clear'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'sendClickedCoords'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'getItemCount'
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'sendValues'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        // method 'handleMapClick'
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QVariant, std::false_type>,
        QtPrivate::TypeAndForceComplete<QVariant, std::false_type>,
        // method 'on_pushButton_2_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_comboBox_3_currentTextChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>
    >,
    nullptr
} };

void map::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<map *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->setCenter((*reinterpret_cast< std::add_pointer_t<QVariant>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QVariant>>(_a[2]))); break;
        case 1: _t->addMarker((*reinterpret_cast< std::add_pointer_t<QVariant>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QVariant>>(_a[2]))); break;
        case 2: _t->addSecondMarker((*reinterpret_cast< std::add_pointer_t<QVariant>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QVariant>>(_a[2]))); break;
        case 3: _t->clear(); break;
        case 4: _t->sendClickedCoords((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 5: { int _r = _t->getItemCount();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 6: _t->sendValues((*reinterpret_cast< std::add_pointer_t<double>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<double>>(_a[2]))); break;
        case 7: { QString _r = _t->handleMapClick((*reinterpret_cast< std::add_pointer_t<QVariant>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QVariant>>(_a[2])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 8: _t->on_pushButton_2_clicked(); break;
        case 9: _t->on_pushButton_clicked(); break;
        case 10: _t->on_comboBox_3_currentTextChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (map::*)(QVariant , QVariant );
            if (_t _q_method = &map::setCenter; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (map::*)(QVariant , QVariant );
            if (_t _q_method = &map::addMarker; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (map::*)(QVariant , QVariant );
            if (_t _q_method = &map::addSecondMarker; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (map::*)();
            if (_t _q_method = &map::clear; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (map::*)(QString );
            if (_t _q_method = &map::sendClickedCoords; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 4;
                return;
            }
        }
        {
            using _t = int (map::*)();
            if (_t _q_method = &map::getItemCount; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (map::*)(double , double );
            if (_t _q_method = &map::sendValues; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 6;
                return;
            }
        }
    }
}

const QMetaObject *map::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *map::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSmapENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int map::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void map::setCenter(QVariant _t1, QVariant _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void map::addMarker(QVariant _t1, QVariant _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void map::addSecondMarker(QVariant _t1, QVariant _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void map::clear()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void map::sendClickedCoords(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
int map::getItemCount()
{
    int _t0{};
    void *_a[] = { const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t0))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
    return _t0;
}

// SIGNAL 6
void map::sendValues(double _t1, double _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}
QT_WARNING_POP
