/****************************************************************************
** Meta object code from reading C++ file 'ttsAPI.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/ttsAPI.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ttsAPI.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ttsAPI[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
       8,    7,    7,    7, 0x05,

 // slots: signature, parameters, type, tag, flags
      28,    7,    7,    7, 0x08,
      50,    7,    7,    7, 0x08,
      72,    7,    7,    7, 0x08,
      94,    7,    7,    7, 0x08,

 // methods: signature, parameters, type, tag, flags
     133,  116,    7,    7, 0x02,
     185,  161,    7,    7, 0x02,

       0        // eod
};

static const char qt_meta_stringdata_ttsAPI[] = {
    "ttsAPI\0\0playbackCompleted()\0"
    "onGoogleTtsResponse()\0onVozmeTtsResponse1()\0"
    "onVozmeTtsResponse2()\0onPlaybackCompleted()\0"
    "message,language\0google_tts(QString,QString)\0"
    "message,gender,language\0"
    "vozme_tts(QString,QString,QString)\0"
};

void ttsAPI::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ttsAPI *_t = static_cast<ttsAPI *>(_o);
        switch (_id) {
        case 0: _t->playbackCompleted(); break;
        case 1: _t->onGoogleTtsResponse(); break;
        case 2: _t->onVozmeTtsResponse1(); break;
        case 3: _t->onVozmeTtsResponse2(); break;
        case 4: _t->onPlaybackCompleted(); break;
        case 5: _t->google_tts((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 6: _t->vozme_tts((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData ttsAPI::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ttsAPI::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_ttsAPI,
      qt_meta_data_ttsAPI, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ttsAPI::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ttsAPI::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ttsAPI::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ttsAPI))
        return static_cast<void*>(const_cast< ttsAPI*>(this));
    return QObject::qt_metacast(_clname);
}

int ttsAPI::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void ttsAPI::playbackCompleted()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
