/****************************************************************************
** Meta object code from reading C++ file 'surfacewidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "src/surfacewidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'surfacewidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_QRFBClient_t {
    QByteArrayData data[9];
    char stringdata0[99];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QRFBClient_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QRFBClient_t qt_meta_stringdata_QRFBClient = {
    {
QT_MOC_LITERAL(0, 0, 10), // "QRFBClient"
QT_MOC_LITERAL(1, 11, 9), // "connected"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 12), // "disconnected"
QT_MOC_LITERAL(4, 35, 17), // "framebufferResize"
QT_MOC_LITERAL(5, 53, 2), // "sz"
QT_MOC_LITERAL(6, 56, 17), // "framebufferUpdate"
QT_MOC_LITERAL(7, 74, 10), // "getMessage"
QT_MOC_LITERAL(8, 85, 13) // "requestUpdate"

    },
    "QRFBClient\0connected\0\0disconnected\0"
    "framebufferResize\0sz\0framebufferUpdate\0"
    "getMessage\0requestUpdate"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QRFBClient[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x06 /* Public */,
       3,    0,   45,    2, 0x06 /* Public */,
       4,    1,   46,    2, 0x06 /* Public */,
       6,    0,   49,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    0,   50,    2, 0x09 /* Protected */,
       8,    0,   51,    2, 0x09 /* Protected */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QSize,    5,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void QRFBClient::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<QRFBClient *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->connected(); break;
        case 1: _t->disconnected(); break;
        case 2: _t->framebufferResize((*reinterpret_cast< QSize(*)>(_a[1]))); break;
        case 3: _t->framebufferUpdate(); break;
        case 4: _t->getMessage(); break;
        case 5: _t->requestUpdate(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (QRFBClient::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QRFBClient::connected)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (QRFBClient::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QRFBClient::disconnected)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (QRFBClient::*)(QSize );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QRFBClient::framebufferResize)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (QRFBClient::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QRFBClient::framebufferUpdate)) {
                *result = 3;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject QRFBClient::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_QRFBClient.data,
    qt_meta_data_QRFBClient,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *QRFBClient::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QRFBClient::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QRFBClient.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "RFBClientWapper"))
        return static_cast< RFBClientWapper*>(this);
    return QWidget::qt_metacast(_clname);
}

int QRFBClient::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void QRFBClient::connected()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void QRFBClient::disconnected()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void QRFBClient::framebufferResize(QSize _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void QRFBClient::framebufferUpdate()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}
struct qt_meta_stringdata_CSurfaceWidget_t {
    QByteArrayData data[9];
    char stringdata0[121];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CSurfaceWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CSurfaceWidget_t qt_meta_stringdata_CSurfaceWidget = {
    {
QT_MOC_LITERAL(0, 0, 14), // "CSurfaceWidget"
QT_MOC_LITERAL(1, 15, 14), // "setSurfaceSize"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 11), // "surfaceSize"
QT_MOC_LITERAL(4, 43, 13), // "updateSurface"
QT_MOC_LITERAL(5, 57, 12), // "clearSurface"
QT_MOC_LITERAL(6, 70, 17), // "frameTimerTimeout"
QT_MOC_LITERAL(7, 88, 17), // "initialConnection"
QT_MOC_LITERAL(8, 106, 14) // "connectionLost"

    },
    "CSurfaceWidget\0setSurfaceSize\0\0"
    "surfaceSize\0updateSurface\0clearSurface\0"
    "frameTimerTimeout\0initialConnection\0"
    "connectionLost"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CSurfaceWidget[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x0a /* Public */,
       4,    0,   47,    2, 0x0a /* Public */,
       5,    0,   48,    2, 0x0a /* Public */,
       6,    0,   49,    2, 0x0a /* Public */,
       7,    0,   50,    2, 0x09 /* Protected */,
       8,    0,   51,    2, 0x09 /* Protected */,

 // slots: parameters
    QMetaType::Void, QMetaType::QSize,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void CSurfaceWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CSurfaceWidget *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->setSurfaceSize((*reinterpret_cast< QSize(*)>(_a[1]))); break;
        case 1: _t->updateSurface(); break;
        case 2: _t->clearSurface(); break;
        case 3: _t->frameTimerTimeout(); break;
        case 4: _t->initialConnection(); break;
        case 5: _t->connectionLost(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject CSurfaceWidget::staticMetaObject = { {
    QMetaObject::SuperData::link<QRFBClient::staticMetaObject>(),
    qt_meta_stringdata_CSurfaceWidget.data,
    qt_meta_data_CSurfaceWidget,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *CSurfaceWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CSurfaceWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CSurfaceWidget.stringdata0))
        return static_cast<void*>(this);
    return QRFBClient::qt_metacast(_clname);
}

int CSurfaceWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QRFBClient::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
