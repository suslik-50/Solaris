/****************************************************************************
** Meta object code from reading C++ file 'potoc_sun.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "potoc_sun.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'potoc_sun.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_potoc_sun_t {
    QByteArrayData data[15];
    char stringdata0[101];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_potoc_sun_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_potoc_sun_t qt_meta_stringdata_potoc_sun = {
    {
QT_MOC_LITERAL(0, 0, 9), // "potoc_sun"
QT_MOC_LITERAL(1, 10, 11), // "positionsun"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 1), // "x"
QT_MOC_LITERAL(4, 25, 1), // "y"
QT_MOC_LITERAL(5, 27, 1), // "z"
QT_MOC_LITERAL(6, 29, 13), // "slotNextValue"
QT_MOC_LITERAL(7, 43, 11), // "sunposition"
QT_MOC_LITERAL(8, 55, 3), // "run"
QT_MOC_LITERAL(9, 59, 5), // "debug"
QT_MOC_LITERAL(10, 65, 3), // "y_n"
QT_MOC_LITERAL(11, 69, 8), // "upreplay"
QT_MOC_LITERAL(12, 78, 1), // "i"
QT_MOC_LITERAL(13, 80, 9), // "timerstop"
QT_MOC_LITERAL(14, 90, 10) // "timerstart"

    },
    "potoc_sun\0positionsun\0\0x\0y\0z\0slotNextValue\0"
    "sunposition\0run\0debug\0y_n\0upreplay\0i\0"
    "timerstop\0timerstart"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_potoc_sun[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    3,   54,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   61,    2, 0x08 /* Private */,
       7,    3,   62,    2, 0x08 /* Private */,
       8,    0,   69,    2, 0x0a /* Public */,
       9,    1,   70,    2, 0x0a /* Public */,
      11,    1,   73,    2, 0x0a /* Public */,
      13,    0,   76,    2, 0x0a /* Public */,
      14,    0,   77,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Double, QMetaType::Double, QMetaType::Double,    3,    4,    5,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double, QMetaType::Double, QMetaType::Double,    3,    4,    5,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   10,
    QMetaType::Void, QMetaType::Int,   12,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void potoc_sun::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        potoc_sun *_t = static_cast<potoc_sun *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->positionsun((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3]))); break;
        case 1: _t->slotNextValue(); break;
        case 2: _t->sunposition((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3]))); break;
        case 3: _t->run(); break;
        case 4: _t->debug((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->upreplay((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->timerstop(); break;
        case 7: _t->timerstart(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (potoc_sun::*_t)(double , double , double );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&potoc_sun::positionsun)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject potoc_sun::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_potoc_sun.data,
      qt_meta_data_potoc_sun,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *potoc_sun::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *potoc_sun::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_potoc_sun.stringdata0))
        return static_cast<void*>(const_cast< potoc_sun*>(this));
    return QThread::qt_metacast(_clname);
}

int potoc_sun::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
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
void potoc_sun::positionsun(double _t1, double _t2, double _t3)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
