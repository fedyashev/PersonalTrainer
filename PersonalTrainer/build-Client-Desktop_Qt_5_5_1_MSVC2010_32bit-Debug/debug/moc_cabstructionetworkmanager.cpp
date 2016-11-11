/****************************************************************************
** Meta object code from reading C++ file 'cabstructionetworkmanager.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../lib/cabstructionetworkmanager.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'cabstructionetworkmanager.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_CAbstructIONetworkManager_t {
    QByteArrayData data[7];
    char stringdata0[90];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CAbstructIONetworkManager_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CAbstructIONetworkManager_t qt_meta_stringdata_CAbstructIONetworkManager = {
    {
QT_MOC_LITERAL(0, 0, 25), // "CAbstructIONetworkManager"
QT_MOC_LITERAL(1, 26, 12), // "disconnected"
QT_MOC_LITERAL(2, 39, 0), // ""
QT_MOC_LITERAL(3, 40, 18), // "recvDataFromSocket"
QT_MOC_LITERAL(4, 59, 16), // "sendDataToSocket"
QT_MOC_LITERAL(5, 76, 8), // "QString*"
QT_MOC_LITERAL(6, 85, 4) // "data"

    },
    "CAbstructIONetworkManager\0disconnected\0"
    "\0recvDataFromSocket\0sendDataToSocket\0"
    "QString*\0data"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CAbstructIONetworkManager[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   29,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   30,    2, 0x0a /* Public */,
       4,    1,   31,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 5,    6,

       0        // eod
};

void CAbstructIONetworkManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CAbstructIONetworkManager *_t = static_cast<CAbstructIONetworkManager *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->disconnected(); break;
        case 1: _t->recvDataFromSocket(); break;
        case 2: _t->sendDataToSocket((*reinterpret_cast< QString*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (CAbstructIONetworkManager::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CAbstructIONetworkManager::disconnected)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject CAbstructIONetworkManager::staticMetaObject = {
    { &CAbstructControllerItem::staticMetaObject, qt_meta_stringdata_CAbstructIONetworkManager.data,
      qt_meta_data_CAbstructIONetworkManager,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *CAbstructIONetworkManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CAbstructIONetworkManager::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_CAbstructIONetworkManager.stringdata0))
        return static_cast<void*>(const_cast< CAbstructIONetworkManager*>(this));
    return CAbstructControllerItem::qt_metacast(_clname);
}

int CAbstructIONetworkManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void CAbstructIONetworkManager::disconnected()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
