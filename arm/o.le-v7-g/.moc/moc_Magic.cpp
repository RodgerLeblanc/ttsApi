/****************************************************************************
** Meta object code from reading C++ file 'Magic.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/Magic.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Magic.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Magic[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       3,   59, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: signature, parameters, type, tag, flags
       7,    6,    6,    6, 0x05,
      24,    6,    6,    6, 0x05,
      38,    6,    6,    6, 0x05,
      55,    6,    6,    6, 0x05,

 // slots: signature, parameters, type, tag, flags
      79,   75,    6,    6, 0x08,
     113,    6,    6,    6, 0x08,
     134,    6,    6,    6, 0x08,
     147,    6,    6,    6, 0x08,

 // methods: signature, parameters, type, tag, flags
     163,    6,    6,    6, 0x02,

 // properties: name, type, flags
     189,  181, 0x0a495103,
     197,  181, 0x0a495103,
     202,  181, 0x0a495103,

 // properties: notify_signal_id
       0,
       1,
       2,

       0        // eod
};

static const char qt_meta_stringdata_Magic[] = {
    "Magic\0\0gpsInfoChanged()\0cityChanged()\0"
    "summaryChanged()\0magicReady(QString)\0"
    "pos\0positionUpdated(QGeoPositionInfo)\0"
    "readReverseGeocode()\0onGpsReady()\0"
    "onReadWeather()\0makeMagicHappen()\0"
    "QString\0gpsInfo\0city\0summary\0"
};

void Magic::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Magic *_t = static_cast<Magic *>(_o);
        switch (_id) {
        case 0: _t->gpsInfoChanged(); break;
        case 1: _t->cityChanged(); break;
        case 2: _t->summaryChanged(); break;
        case 3: _t->magicReady((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->positionUpdated((*reinterpret_cast< const QGeoPositionInfo(*)>(_a[1]))); break;
        case 5: _t->readReverseGeocode(); break;
        case 6: _t->onGpsReady(); break;
        case 7: _t->onReadWeather(); break;
        case 8: _t->makeMagicHappen(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Magic::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Magic::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Magic,
      qt_meta_data_Magic, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Magic::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Magic::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Magic::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Magic))
        return static_cast<void*>(const_cast< Magic*>(this));
    return QObject::qt_metacast(_clname);
}

int Magic::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
#ifndef QT_NO_PROPERTIES
      else if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = getGpsInfo(); break;
        case 1: *reinterpret_cast< QString*>(_v) = getCity(); break;
        case 2: *reinterpret_cast< QString*>(_v) = getSummary(); break;
        }
        _id -= 3;
    } else if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: setGpsInfo(*reinterpret_cast< QString*>(_v)); break;
        case 1: setCity(*reinterpret_cast< QString*>(_v)); break;
        case 2: setSummary(*reinterpret_cast< QString*>(_v)); break;
        }
        _id -= 3;
    } else if (_c == QMetaObject::ResetProperty) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 3;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void Magic::gpsInfoChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void Magic::cityChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void Magic::summaryChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void Magic::magicReady(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_END_MOC_NAMESPACE
