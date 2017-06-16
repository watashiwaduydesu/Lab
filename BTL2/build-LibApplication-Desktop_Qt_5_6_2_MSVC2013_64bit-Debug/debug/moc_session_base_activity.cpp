/****************************************************************************
** Meta object code from reading C++ file 'session_base_activity.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../LibApplication/session_base_activity.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'session_base_activity.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_session_base_activity_t {
    QByteArrayData data[6];
    char stringdata0[104];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_session_base_activity_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_session_base_activity_t qt_meta_stringdata_session_base_activity = {
    {
QT_MOC_LITERAL(0, 0, 21), // "session_base_activity"
QT_MOC_LITERAL(1, 22, 25), // "onTrigger_change_password"
QT_MOC_LITERAL(2, 48, 0), // ""
QT_MOC_LITERAL(3, 49, 14), // "onTrigger_exit"
QT_MOC_LITERAL(4, 64, 21), // "onTrigger_information"
QT_MOC_LITERAL(5, 86, 17) // "onTrigger_history"

    },
    "session_base_activity\0onTrigger_change_password\0"
    "\0onTrigger_exit\0onTrigger_information\0"
    "onTrigger_history"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_session_base_activity[] = {

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

void session_base_activity::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        session_base_activity *_t = static_cast<session_base_activity *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->onTrigger_change_password(); break;
        case 1: _t->onTrigger_exit(); break;
        case 2: _t->onTrigger_information(); break;
        case 3: _t->onTrigger_history(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject session_base_activity::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_session_base_activity.data,
      qt_meta_data_session_base_activity,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *session_base_activity::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *session_base_activity::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_session_base_activity.stringdata0))
        return static_cast<void*>(const_cast< session_base_activity*>(this));
    return QWidget::qt_metacast(_clname);
}

int session_base_activity::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
