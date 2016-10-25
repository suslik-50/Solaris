/****************************************************************************
** Meta object code from reading C++ file 'drain_parametrs_solar_battery.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Solaris_back-end/drain_parametrs_solar_battery.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'drain_parametrs_solar_battery.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_drain_parametrs_solar_battery_t {
    QByteArrayData data[13];
    char stringdata0[139];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_drain_parametrs_solar_battery_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_drain_parametrs_solar_battery_t qt_meta_stringdata_drain_parametrs_solar_battery = {
    {
QT_MOC_LITERAL(0, 0, 29), // "drain_parametrs_solar_battery"
QT_MOC_LITERAL(1, 30, 18), // "data_solar_battery"
QT_MOC_LITERAL(2, 49, 0), // ""
QT_MOC_LITERAL(3, 50, 36), // "QMap<QString,solar_battery_sa..."
QT_MOC_LITERAL(4, 87, 8), // "new_data"
QT_MOC_LITERAL(5, 96, 3), // "run"
QT_MOC_LITERAL(6, 100, 10), // "deletedata"
QT_MOC_LITERAL(7, 111, 4), // "name"
QT_MOC_LITERAL(8, 116, 4), // "data"
QT_MOC_LITERAL(9, 121, 1), // "a"
QT_MOC_LITERAL(10, 123, 1), // "b"
QT_MOC_LITERAL(11, 125, 4), // "time"
QT_MOC_LITERAL(12, 130, 8) // "get_data"

    },
    "drain_parametrs_solar_battery\0"
    "data_solar_battery\0\0"
    "QMap<QString,solar_battery_salleter>\0"
    "new_data\0run\0deletedata\0name\0data\0a\0"
    "b\0time\0get_data"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_drain_parametrs_solar_battery[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x06 /* Public */,
       4,    0,   47,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   48,    2, 0x0a /* Public */,
       6,    1,   49,    2, 0x0a /* Public */,
       8,    4,   52,    2, 0x0a /* Public */,
      12,    0,   61,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void, QMetaType::Double, QMetaType::Double, QMetaType::Double, QMetaType::QString,    9,   10,   11,    7,
    QMetaType::Void,

       0        // eod
};

void drain_parametrs_solar_battery::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        drain_parametrs_solar_battery *_t = static_cast<drain_parametrs_solar_battery *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->data_solar_battery((*reinterpret_cast< QMap<QString,solar_battery_salleter>(*)>(_a[1]))); break;
        case 1: _t->new_data(); break;
        case 2: _t->run(); break;
        case 3: _t->deletedata((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->data((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4]))); break;
        case 5: _t->get_data(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (drain_parametrs_solar_battery::*_t)(QMap<QString,solar_battery_salleter> );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&drain_parametrs_solar_battery::data_solar_battery)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (drain_parametrs_solar_battery::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&drain_parametrs_solar_battery::new_data)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject drain_parametrs_solar_battery::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_drain_parametrs_solar_battery.data,
      qt_meta_data_drain_parametrs_solar_battery,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *drain_parametrs_solar_battery::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *drain_parametrs_solar_battery::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_drain_parametrs_solar_battery.stringdata0))
        return static_cast<void*>(const_cast< drain_parametrs_solar_battery*>(this));
    return QThread::qt_metacast(_clname);
}

int drain_parametrs_solar_battery::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void drain_parametrs_solar_battery::data_solar_battery(QMap<QString,solar_battery_salleter> _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void drain_parametrs_solar_battery::new_data()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
