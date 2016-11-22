/****************************************************************************
** Meta object code from reading C++ file 'tcpsocketthread.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "tcpsocketthread.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'tcpsocketthread.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_TcpSocketThread_t {
    QByteArrayData data[13];
    char stringdata0[168];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TcpSocketThread_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TcpSocketThread_t qt_meta_stringdata_TcpSocketThread = {
    {
QT_MOC_LITERAL(0, 0, 15), // "TcpSocketThread"
QT_MOC_LITERAL(1, 16, 5), // "error"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 23), // "QTcpSocket::SocketError"
QT_MOC_LITERAL(4, 47, 11), // "socketerror"
QT_MOC_LITERAL(5, 59, 13), // "getDatadreain"
QT_MOC_LITERAL(6, 73, 13), // "sendTabelData"
QT_MOC_LITERAL(7, 87, 9), // "readyRead"
QT_MOC_LITERAL(8, 97, 12), // "disconnected"
QT_MOC_LITERAL(9, 110, 7), // "raschet"
QT_MOC_LITERAL(10, 118, 35), // "QMap<QString,QList<data_salle..."
QT_MOC_LITERAL(11, 154, 4), // "data"
QT_MOC_LITERAL(12, 159, 8) // "proverka"

    },
    "TcpSocketThread\0error\0\0QTcpSocket::SocketError\0"
    "socketerror\0getDatadreain\0sendTabelData\0"
    "readyRead\0disconnected\0raschet\0"
    "QMap<QString,QList<data_salleter> >\0"
    "data\0proverka"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TcpSocketThread[] = {

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
       5,    0,   52,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   53,    2, 0x08 /* Private */,
       7,    0,   54,    2, 0x08 /* Private */,
       8,    0,   55,    2, 0x08 /* Private */,
       9,    1,   56,    2, 0x08 /* Private */,
      12,    0,   59,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 10,   11,
    QMetaType::Void,

       0        // eod
};

void TcpSocketThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        TcpSocketThread *_t = static_cast<TcpSocketThread *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->error((*reinterpret_cast< QTcpSocket::SocketError(*)>(_a[1]))); break;
        case 1: _t->getDatadreain(); break;
        case 2: _t->sendTabelData(); break;
        case 3: _t->readyRead(); break;
        case 4: _t->disconnected(); break;
        case 5: _t->raschet((*reinterpret_cast< QMap<QString,QList<data_salleter> >(*)>(_a[1]))); break;
        case 6: _t->proverka(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (TcpSocketThread::*_t)(QTcpSocket::SocketError );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TcpSocketThread::error)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (TcpSocketThread::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TcpSocketThread::getDatadreain)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject TcpSocketThread::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_TcpSocketThread.data,
      qt_meta_data_TcpSocketThread,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *TcpSocketThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TcpSocketThread::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_TcpSocketThread.stringdata0))
        return static_cast<void*>(const_cast< TcpSocketThread*>(this));
    return QThread::qt_metacast(_clname);
}

int TcpSocketThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void TcpSocketThread::error(QTcpSocket::SocketError _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void TcpSocketThread::getDatadreain()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
