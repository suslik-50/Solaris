/****************************************************************************
** Meta object code from reading C++ file 'corners_solar_battery.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "corners_solar_battery.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'corners_solar_battery.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_corners_solar_battery_t {
    QByteArrayData data[19];
    char stringdata0[120];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_corners_solar_battery_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_corners_solar_battery_t qt_meta_stringdata_corners_solar_battery = {
    {
QT_MOC_LITERAL(0, 0, 21), // "corners_solar_battery"
QT_MOC_LITERAL(1, 22, 4), // "data"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 1), // "a"
QT_MOC_LITERAL(4, 30, 1), // "b"
QT_MOC_LITERAL(5, 32, 4), // "time"
QT_MOC_LITERAL(6, 37, 4), // "name"
QT_MOC_LITERAL(7, 42, 3), // "run"
QT_MOC_LITERAL(8, 46, 17), // "position_salleter"
QT_MOC_LITERAL(9, 64, 8), // "vector_s"
QT_MOC_LITERAL(10, 73, 8), // "salleter"
QT_MOC_LITERAL(11, 82, 6), // "name_s"
QT_MOC_LITERAL(12, 89, 12), // "position_sun"
QT_MOC_LITERAL(13, 102, 1), // "x"
QT_MOC_LITERAL(14, 104, 1), // "y"
QT_MOC_LITERAL(15, 106, 1), // "z"
QT_MOC_LITERAL(16, 108, 1), // "t"
QT_MOC_LITERAL(17, 110, 5), // "debug"
QT_MOC_LITERAL(18, 116, 3) // "y_n"

    },
    "corners_solar_battery\0data\0\0a\0b\0time\0"
    "name\0run\0position_salleter\0vector_s\0"
    "salleter\0name_s\0position_sun\0x\0y\0z\0t\0"
    "debug\0y_n"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_corners_solar_battery[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    4,   39,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    0,   48,    2, 0x0a /* Public */,
       8,    3,   49,    2, 0x0a /* Public */,
      12,    4,   56,    2, 0x0a /* Public */,
      17,    1,   65,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Double, QMetaType::Double, QMetaType::Double, QMetaType::QString,    3,    4,    5,    6,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 9, QMetaType::Double, QMetaType::QString,   10,    5,   11,
    QMetaType::Void, QMetaType::Double, QMetaType::Double, QMetaType::Double, QMetaType::Double,   13,   14,   15,   16,
    QMetaType::Void, QMetaType::Bool,   18,

       0        // eod
};

void corners_solar_battery::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        corners_solar_battery *_t = static_cast<corners_solar_battery *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->data((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4]))); break;
        case 1: _t->run(); break;
        case 2: _t->position_salleter((*reinterpret_cast< vector_s(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 3: _t->position_sun((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3])),(*reinterpret_cast< double(*)>(_a[4]))); break;
        case 4: _t->debug((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (corners_solar_battery::*_t)(double , double , double , QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&corners_solar_battery::data)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject corners_solar_battery::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_corners_solar_battery.data,
      qt_meta_data_corners_solar_battery,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *corners_solar_battery::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *corners_solar_battery::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_corners_solar_battery.stringdata0))
        return static_cast<void*>(const_cast< corners_solar_battery*>(this));
    return QThread::qt_metacast(_clname);
}

int corners_solar_battery::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void corners_solar_battery::data(double _t1, double _t2, double _t3, QString _t4)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
