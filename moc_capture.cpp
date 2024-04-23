/****************************************************************************
** Meta object code from reading C++ file 'capture.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "capture.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'capture.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_capture_t {
    QByteArrayData data[15];
    char stringdata0[193];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_capture_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_capture_t qt_meta_stringdata_capture = {
    {
QT_MOC_LITERAL(0, 0, 7), // "capture"
QT_MOC_LITERAL(1, 8, 10), // "sendwidget"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 13), // "widgetchecked"
QT_MOC_LITERAL(4, 34, 9), // "getwidget"
QT_MOC_LITERAL(5, 44, 10), // "getjcflash"
QT_MOC_LITERAL(6, 55, 5), // "flash"
QT_MOC_LITERAL(7, 61, 9), // "showImage"
QT_MOC_LITERAL(8, 71, 17), // "pushButtonClicked"
QT_MOC_LITERAL(9, 89, 16), // "disPlaylprResult"
QT_MOC_LITERAL(10, 106, 13), // "handleTimeout"
QT_MOC_LITERAL(11, 120, 14), // "handlesTimeout"
QT_MOC_LITERAL(12, 135, 19), // "on_return_2_clicked"
QT_MOC_LITERAL(13, 155, 29), // "on_startCaptureButton_clicked"
QT_MOC_LITERAL(14, 185, 7) // "checked"

    },
    "capture\0sendwidget\0\0widgetchecked\0"
    "getwidget\0getjcflash\0flash\0showImage\0"
    "pushButtonClicked\0disPlaylprResult\0"
    "handleTimeout\0handlesTimeout\0"
    "on_return_2_clicked\0on_startCaptureButton_clicked\0"
    "checked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_capture[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   64,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    1,   67,    2, 0x0a /* Public */,
       5,    1,   70,    2, 0x0a /* Public */,
       7,    1,   73,    2, 0x08 /* Private */,
       8,    0,   76,    2, 0x08 /* Private */,
       9,    1,   77,    2, 0x08 /* Private */,
      10,    0,   80,    2, 0x08 /* Private */,
      11,    0,   81,    2, 0x08 /* Private */,
      12,    0,   82,    2, 0x08 /* Private */,
      13,    1,   83,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool,    3,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    6,
    QMetaType::Void, QMetaType::QImage,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   14,

       0        // eod
};

void capture::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<capture *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendwidget((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->getwidget((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->getjcflash((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->showImage((*reinterpret_cast< QImage(*)>(_a[1]))); break;
        case 4: _t->pushButtonClicked(); break;
        case 5: _t->disPlaylprResult((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->handleTimeout(); break;
        case 7: _t->handlesTimeout(); break;
        case 8: _t->on_return_2_clicked(); break;
        case 9: _t->on_startCaptureButton_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (capture::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&capture::sendwidget)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject capture::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_capture.data,
    qt_meta_data_capture,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *capture::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *capture::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_capture.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int capture::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
void capture::sendwidget(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
