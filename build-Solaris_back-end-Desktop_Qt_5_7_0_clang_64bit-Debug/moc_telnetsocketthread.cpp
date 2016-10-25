/****************************************************************************
** Meta object code from reading C++ file 'telnetsocketthread.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Solaris_back-end/telnetsocketthread.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'telnetsocketthread.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_TelnetSocketThread_t {
    QByteArrayData data[13];
    char stringdata0[153];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TelnetSocketThread_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TelnetSocketThread_t qt_meta_stringdata_TelnetSocketThread = {
    {
QT_MOC_LITERAL(0, 0, 18), // "TelnetSocketThread"
QT_MOC_LITERAL(1, 19, 5), // "error"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 23), // "QTcpSocket::SocketError"
QT_MOC_LITERAL(4, 50, 11), // "socketerror"
QT_MOC_LITERAL(5, 62, 13), // "accessChanged"
QT_MOC_LITERAL(6, 76, 6), // "access"
QT_MOC_LITERAL(7, 83, 15), // "auntoficChanged"
QT_MOC_LITERAL(8, 99, 8), // "auntofic"
QT_MOC_LITERAL(9, 108, 9), // "readyRead"
QT_MOC_LITERAL(10, 118, 12), // "disconnected"
QT_MOC_LITERAL(11, 131, 9), // "setAccess"
QT_MOC_LITERAL(12, 141, 11) // "setAuntofic"

    },
    "TelnetSocketThread\0error\0\0"
    "QTcpSocket::SocketError\0socketerror\0"
    "accessChanged\0access\0auntoficChanged\0"
    "auntofic\0readyRead\0disconnected\0"
    "setAccess\0setAuntofic"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TelnetSocketThread[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       2,   66, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x06 /* Public */,
       5,    1,   52,    2, 0x06 /* Public */,
       7,    1,   55,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    0,   58,    2, 0x0a /* Public */,
      10,    0,   59,    2, 0x0a /* Public */,
      11,    1,   60,    2, 0x0a /* Public */,
      12,    1,   63,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, QMetaType::Bool,    6,
    QMetaType::Void, QMetaType::Bool,    8,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    6,
    QMetaType::Void, QMetaType::Bool,    8,

 // properties: name, type, flags
       6, QMetaType::Bool, 0x00495103,
       8, QMetaType::Bool, 0x00495103,

 // properties: notify_signal_id
       1,
       2,

       0        // eod
};

void TelnetSocketThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        TelnetSocketThread *_t = static_cast<TelnetSocketThread *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->error((*reinterpret_cast< QTcpSocket::SocketError(*)>(_a[1]))); break;
        case 1: _t->accessChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->auntoficChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->readyRead(); break;
        case 4: _t->disconnected(); break;
        case 5: _t->setAccess((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: _t->setAuntofic((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (TelnetSocketThread::*_t)(QTcpSocket::SocketError );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TelnetSocketThread::error)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (TelnetSocketThread::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TelnetSocketThread::accessChanged)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (TelnetSocketThread::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TelnetSocketThread::auntoficChanged)) {
                *result = 2;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        TelnetSocketThread *_t = static_cast<TelnetSocketThread *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< bool*>(_v) = _t->access(); break;
        case 1: *reinterpret_cast< bool*>(_v) = _t->auntofic(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        TelnetSocketThread *_t = static_cast<TelnetSocketThread *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setAccess(*reinterpret_cast< bool*>(_v)); break;
        case 1: _t->setAuntofic(*reinterpret_cast< bool*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

const QMetaObject TelnetSocketThread::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_TelnetSocketThread.data,
      qt_meta_data_TelnetSocketThread,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *TelnetSocketThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TelnetSocketThread::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_TelnetSocketThread.stringdata0))
        return static_cast<void*>(const_cast< TelnetSocketThread*>(this));
    return QThread::qt_metacast(_clname);
}

int TelnetSocketThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void TelnetSocketThread::error(QTcpSocket::SocketError _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void TelnetSocketThread::accessChanged(bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void TelnetSocketThread::auntoficChanged(bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
