/****************************************************************************
** Meta object code from reading C++ file 'potoc_salleter2.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Solaris_back-end/potoc_salleter2.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'potoc_salleter2.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_potoc_salleter2_t {
    QByteArrayData data[21];
    char stringdata0[167];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_potoc_salleter2_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_potoc_salleter2_t qt_meta_stringdata_potoc_salleter2 = {
    {
QT_MOC_LITERAL(0, 0, 15), // "potoc_salleter2"
QT_MOC_LITERAL(1, 16, 4), // "data"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 15), // "vector_salleter"
QT_MOC_LITERAL(4, 38, 11), // "speed_error"
QT_MOC_LITERAL(5, 50, 11), // "kontrol_sum"
QT_MOC_LITERAL(6, 62, 6), // "update"
QT_MOC_LITERAL(7, 69, 2), // "aa"
QT_MOC_LITERAL(8, 72, 2), // "ee"
QT_MOC_LITERAL(9, 75, 2), // "ii"
QT_MOC_LITERAL(10, 78, 6), // "dvudvu"
QT_MOC_LITERAL(11, 85, 6), // "urpurp"
QT_MOC_LITERAL(12, 92, 3), // "TT0"
QT_MOC_LITERAL(13, 96, 8), // "upreplay"
QT_MOC_LITERAL(14, 105, 8), // "Upreplay"
QT_MOC_LITERAL(15, 114, 3), // "run"
QT_MOC_LITERAL(16, 118, 9), // "StopTimer"
QT_MOC_LITERAL(17, 128, 10), // "StartTimer"
QT_MOC_LITERAL(18, 139, 13), // "slotNextValue"
QT_MOC_LITERAL(19, 153, 9), // "debug_t_f"
QT_MOC_LITERAL(20, 163, 3) // "y_n"

    },
    "potoc_salleter2\0data\0\0vector_salleter\0"
    "speed_error\0kontrol_sum\0update\0aa\0ee\0"
    "ii\0dvudvu\0urpurp\0TT0\0upreplay\0Upreplay\0"
    "run\0StopTimer\0StartTimer\0slotNextValue\0"
    "debug_t_f\0y_n"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_potoc_salleter2[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   64,    2, 0x06 /* Public */,
       4,    0,   67,    2, 0x06 /* Public */,
       5,    1,   68,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    6,   71,    2, 0x0a /* Public */,
      13,    1,   84,    2, 0x0a /* Public */,
      15,    0,   87,    2, 0x0a /* Public */,
      16,    0,   88,    2, 0x0a /* Public */,
      17,    0,   89,    2, 0x0a /* Public */,
      18,    0,   90,    2, 0x0a /* Public */,
      19,    1,   91,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::Double, QMetaType::Double, QMetaType::Double, QMetaType::Double, QMetaType::Double, QMetaType::Double,    7,    8,    9,   10,   11,   12,
    QMetaType::Void, QMetaType::Double,   14,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   20,

       0        // eod
};

void potoc_salleter2::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        potoc_salleter2 *_t = static_cast<potoc_salleter2 *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->data((*reinterpret_cast< vector_salleter(*)>(_a[1]))); break;
        case 1: _t->speed_error(); break;
        case 2: _t->kontrol_sum((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->update((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3])),(*reinterpret_cast< double(*)>(_a[4])),(*reinterpret_cast< double(*)>(_a[5])),(*reinterpret_cast< double(*)>(_a[6]))); break;
        case 4: _t->upreplay((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 5: _t->run(); break;
        case 6: _t->StopTimer(); break;
        case 7: _t->StartTimer(); break;
        case 8: _t->slotNextValue(); break;
        case 9: _t->debug_t_f((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (potoc_salleter2::*_t)(vector_salleter );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&potoc_salleter2::data)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (potoc_salleter2::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&potoc_salleter2::speed_error)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (potoc_salleter2::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&potoc_salleter2::kontrol_sum)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject potoc_salleter2::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_potoc_salleter2.data,
      qt_meta_data_potoc_salleter2,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *potoc_salleter2::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *potoc_salleter2::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_potoc_salleter2.stringdata0))
        return static_cast<void*>(const_cast< potoc_salleter2*>(this));
    return QThread::qt_metacast(_clname);
}

int potoc_salleter2::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
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
    return _id;
}

// SIGNAL 0
void potoc_salleter2::data(vector_salleter _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void potoc_salleter2::speed_error()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void potoc_salleter2::kontrol_sum(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
