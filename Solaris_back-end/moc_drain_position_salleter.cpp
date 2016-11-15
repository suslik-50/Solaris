/****************************************************************************
** Meta object code from reading C++ file 'drain_position_salleter.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "drain_position_salleter.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'drain_position_salleter.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_drain_position_salleter_t {
    QByteArrayData data[18];
    char stringdata0[155];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_drain_position_salleter_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_drain_position_salleter_t qt_meta_stringdata_drain_position_salleter = {
    {
QT_MOC_LITERAL(0, 0, 23), // "drain_position_salleter"
QT_MOC_LITERAL(1, 24, 20), // "data_salleter_signal"
QT_MOC_LITERAL(2, 45, 0), // ""
QT_MOC_LITERAL(3, 46, 29), // "QMap<QString,vector_salleter>"
QT_MOC_LITERAL(4, 76, 8), // "new_data"
QT_MOC_LITERAL(5, 85, 3), // "run"
QT_MOC_LITERAL(6, 89, 10), // "deletedata"
QT_MOC_LITERAL(7, 100, 4), // "name"
QT_MOC_LITERAL(8, 105, 4), // "data"
QT_MOC_LITERAL(9, 110, 15), // "vector_salleter"
QT_MOC_LITERAL(10, 126, 1), // "x"
QT_MOC_LITERAL(11, 128, 1), // "y"
QT_MOC_LITERAL(12, 130, 1), // "z"
QT_MOC_LITERAL(13, 132, 2), // "vx"
QT_MOC_LITERAL(14, 135, 2), // "vy"
QT_MOC_LITERAL(15, 138, 2), // "vz"
QT_MOC_LITERAL(16, 141, 4), // "time"
QT_MOC_LITERAL(17, 146, 8) // "get_data"

    },
    "drain_position_salleter\0data_salleter_signal\0"
    "\0QMap<QString,vector_salleter>\0new_data\0"
    "run\0deletedata\0name\0data\0vector_salleter\0"
    "x\0y\0z\0vx\0vy\0vz\0time\0get_data"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_drain_position_salleter[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x06 /* Public */,
       4,    0,   52,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   53,    2, 0x0a /* Public */,
       6,    1,   54,    2, 0x0a /* Public */,
       8,    1,   57,    2, 0x0a /* Public */,
       8,    8,   60,    2, 0x0a /* Public */,
      17,    0,   77,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void, 0x80000000 | 9,    7,
    QMetaType::Void, QMetaType::Double, QMetaType::Double, QMetaType::Double, QMetaType::Double, QMetaType::Double, QMetaType::Double, QMetaType::QString, QMetaType::Double,   10,   11,   12,   13,   14,   15,    7,   16,
    QMetaType::Void,

       0        // eod
};

void drain_position_salleter::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        drain_position_salleter *_t = static_cast<drain_position_salleter *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->data_salleter_signal((*reinterpret_cast< QMap<QString,vector_salleter>(*)>(_a[1]))); break;
        case 1: _t->new_data(); break;
        case 2: _t->run(); break;
        case 3: _t->deletedata((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->data((*reinterpret_cast< vector_salleter(*)>(_a[1]))); break;
        case 5: _t->data((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3])),(*reinterpret_cast< double(*)>(_a[4])),(*reinterpret_cast< double(*)>(_a[5])),(*reinterpret_cast< double(*)>(_a[6])),(*reinterpret_cast< QString(*)>(_a[7])),(*reinterpret_cast< double(*)>(_a[8]))); break;
        case 6: _t->get_data(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (drain_position_salleter::*_t)(QMap<QString,vector_salleter> );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&drain_position_salleter::data_salleter_signal)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (drain_position_salleter::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&drain_position_salleter::new_data)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject drain_position_salleter::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_drain_position_salleter.data,
      qt_meta_data_drain_position_salleter,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *drain_position_salleter::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *drain_position_salleter::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_drain_position_salleter.stringdata0))
        return static_cast<void*>(const_cast< drain_position_salleter*>(this));
    return QThread::qt_metacast(_clname);
}

int drain_position_salleter::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
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
    return _id;
}

// SIGNAL 0
void drain_position_salleter::data_salleter_signal(QMap<QString,vector_salleter> _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void drain_position_salleter::new_data()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
