/****************************************************************************
** Meta object code from reading C++ file 'cabstructfsm.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../TesServerLib/cabstructfsm.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'cabstructfsm.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_CAbstructFSM_t {
    QByteArrayData data[7];
    char stringdata0[79];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CAbstructFSM_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CAbstructFSM_t qt_meta_stringdata_CAbstructFSM = {
    {
QT_MOC_LITERAL(0, 0, 12), // "CAbstructFSM"
QT_MOC_LITERAL(1, 13, 26), // "sendDataToIONetworkManager"
QT_MOC_LITERAL(2, 40, 0), // ""
QT_MOC_LITERAL(3, 41, 8), // "QString*"
QT_MOC_LITERAL(4, 50, 19), // "sendDataToDBManager"
QT_MOC_LITERAL(5, 70, 3), // "fsm"
QT_MOC_LITERAL(6, 74, 4) // "data"

    },
    "CAbstructFSM\0sendDataToIONetworkManager\0"
    "\0QString*\0sendDataToDBManager\0fsm\0"
    "data"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CAbstructFSM[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x06 /* Public */,
       4,    1,   32,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    1,   35,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 3,    2,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    6,

       0        // eod
};

void CAbstructFSM::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CAbstructFSM *_t = static_cast<CAbstructFSM *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendDataToIONetworkManager((*reinterpret_cast< QString*(*)>(_a[1]))); break;
        case 1: _t->sendDataToDBManager((*reinterpret_cast< QString*(*)>(_a[1]))); break;
        case 2: _t->fsm((*reinterpret_cast< QString*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (CAbstructFSM::*_t)(QString * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CAbstructFSM::sendDataToIONetworkManager)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (CAbstructFSM::*_t)(QString * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CAbstructFSM::sendDataToDBManager)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject CAbstructFSM::staticMetaObject = {
    { &CAbstructControllerItem::staticMetaObject, qt_meta_stringdata_CAbstructFSM.data,
      qt_meta_data_CAbstructFSM,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *CAbstructFSM::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CAbstructFSM::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_CAbstructFSM.stringdata0))
        return static_cast<void*>(const_cast< CAbstructFSM*>(this));
    return CAbstructControllerItem::qt_metacast(_clname);
}

int CAbstructFSM::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = CAbstructControllerItem::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void CAbstructFSM::sendDataToIONetworkManager(QString * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void CAbstructFSM::sendDataToDBManager(QString * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
