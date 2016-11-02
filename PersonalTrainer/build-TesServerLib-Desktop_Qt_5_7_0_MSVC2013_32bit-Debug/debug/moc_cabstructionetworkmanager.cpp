/****************************************************************************
** Meta object code from reading C++ file 'cabstructionetworkmanager.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../TesServerLib/cabstructionetworkmanager.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'cabstructionetworkmanager.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_CAbstructIONetworkManager_t {
    QByteArrayData data[6];
    char stringdata0[77];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CAbstructIONetworkManager_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CAbstructIONetworkManager_t qt_meta_stringdata_CAbstructIONetworkManager = {
    {
QT_MOC_LITERAL(0, 0, 25), // "CAbstructIONetworkManager"
QT_MOC_LITERAL(1, 26, 18), // "recvDataFromSocket"
QT_MOC_LITERAL(2, 45, 0), // ""
QT_MOC_LITERAL(3, 46, 16), // "sendDataToSocket"
QT_MOC_LITERAL(4, 63, 8), // "QString*"
QT_MOC_LITERAL(5, 72, 4) // "data"

    },
    "CAbstructIONetworkManager\0recvDataFromSocket\0"
    "\0sendDataToSocket\0QString*\0data"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CAbstructIONetworkManager[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   24,    2, 0x0a /* Public */,
       3,    1,   25,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    5,

       0        // eod
};

void CAbstructIONetworkManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CAbstructIONetworkManager *_t = static_cast<CAbstructIONetworkManager *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->recvDataFromSocket(); break;
        case 1: _t->sendDataToSocket((*reinterpret_cast< QString*(*)>(_a[1]))); break;
        default: ;
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
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
