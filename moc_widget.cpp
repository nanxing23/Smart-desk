/****************************************************************************
** Meta object code from reading C++ file 'widget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "widget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'widget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Widget_t {
    QByteArrayData data[17];
    char stringdata0[241];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Widget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Widget_t qt_meta_stringdata_Widget = {
    {
QT_MOC_LITERAL(0, 0, 6), // "Widget"
QT_MOC_LITERAL(1, 7, 11), // "sendwidget1"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 13), // "widgetchecked"
QT_MOC_LITERAL(4, 34, 11), // "sendcputemp"
QT_MOC_LITERAL(5, 46, 4), // "temp"
QT_MOC_LITERAL(6, 51, 12), // "updateOutput"
QT_MOC_LITERAL(7, 64, 11), // "timerUpdate"
QT_MOC_LITERAL(8, 76, 17), // "on_shezhi_clicked"
QT_MOC_LITERAL(9, 94, 17), // "on_ledpwm_clicked"
QT_MOC_LITERAL(10, 112, 21), // "on_timebutton_clicked"
QT_MOC_LITERAL(11, 134, 15), // "on_time_clicked"
QT_MOC_LITERAL(12, 150, 15), // "on_near_clicked"
QT_MOC_LITERAL(13, 166, 15), // "on_week_clicked"
QT_MOC_LITERAL(14, 182, 24), // "on_capturebutton_clicked"
QT_MOC_LITERAL(15, 207, 17), // "on_aichat_clicked"
QT_MOC_LITERAL(16, 225, 15) // "on_file_clicked"

    },
    "Widget\0sendwidget1\0\0widgetchecked\0"
    "sendcputemp\0temp\0updateOutput\0timerUpdate\0"
    "on_shezhi_clicked\0on_ledpwm_clicked\0"
    "on_timebutton_clicked\0on_time_clicked\0"
    "on_near_clicked\0on_week_clicked\0"
    "on_capturebutton_clicked\0on_aichat_clicked\0"
    "on_file_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Widget[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   79,    2, 0x06 /* Public */,
       4,    1,   82,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   85,    2, 0x08 /* Private */,
       7,    0,   86,    2, 0x08 /* Private */,
       8,    0,   87,    2, 0x08 /* Private */,
       9,    0,   88,    2, 0x08 /* Private */,
      10,    0,   89,    2, 0x08 /* Private */,
      11,    0,   90,    2, 0x08 /* Private */,
      12,    0,   91,    2, 0x08 /* Private */,
      13,    0,   92,    2, 0x08 /* Private */,
      14,    0,   93,    2, 0x08 /* Private */,
      15,    0,   94,    2, 0x08 /* Private */,
      16,    0,   95,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::QString,    5,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Widget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Widget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendwidget1((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->sendcputemp((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->updateOutput(); break;
        case 3: _t->timerUpdate(); break;
        case 4: _t->on_shezhi_clicked(); break;
        case 5: _t->on_ledpwm_clicked(); break;
        case 6: _t->on_timebutton_clicked(); break;
        case 7: _t->on_time_clicked(); break;
        case 8: _t->on_near_clicked(); break;
        case 9: _t->on_week_clicked(); break;
        case 10: _t->on_capturebutton_clicked(); break;
        case 11: _t->on_aichat_clicked(); break;
        case 12: _t->on_file_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Widget::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Widget::sendwidget1)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Widget::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Widget::sendcputemp)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Widget::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_Widget.data,
    qt_meta_data_Widget,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Widget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Widget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Widget.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Widget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
void Widget::sendwidget1(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Widget::sendcputemp(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
