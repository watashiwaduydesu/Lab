/****************************************************************************
** Meta object code from reading C++ file 'start_activity.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../LibApplication/start_activity.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'start_activity.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_start_activity_t {
    QByteArrayData data[6];
    char stringdata0[93];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_start_activity_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_start_activity_t qt_meta_stringdata_start_activity = {
    {
QT_MOC_LITERAL(0, 0, 14), // "start_activity"
QT_MOC_LITERAL(1, 15, 19), // "onClick_btn_sign_up"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 19), // "onClick_btn_sign_in"
QT_MOC_LITERAL(4, 56, 16), // "onClick_btn_quit"
QT_MOC_LITERAL(5, 73, 19) // "open_window_session"

    },
    "start_activity\0onClick_btn_sign_up\0\0"
    "onClick_btn_sign_in\0onClick_btn_quit\0"
    "open_window_session"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_start_activity[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x0a /* Public */,
       3,    0,   35,    2, 0x0a /* Public */,
       4,    0,   36,    2, 0x0a /* Public */,
       5,    0,   37,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void start_activity::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        start_activity *_t = static_cast<start_activity *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->onClick_btn_sign_up(); break;
        case 1: _t->onClick_btn_sign_in(); break;
        case 2: _t->onClick_btn_quit(); break;
        case 3: _t->open_window_session(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject start_activity::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_start_activity.data,
      qt_meta_data_start_activity,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *start_activity::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *start_activity::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_start_activity.stringdata0))
        return static_cast<void*>(const_cast< start_activity*>(this));
    return QWidget::qt_metacast(_clname);
}

int start_activity::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
