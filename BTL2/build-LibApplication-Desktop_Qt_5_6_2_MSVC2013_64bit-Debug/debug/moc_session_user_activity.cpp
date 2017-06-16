/****************************************************************************
** Meta object code from reading C++ file 'session_user_activity.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../LibApplication/session_user_activity.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'session_user_activity.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_session_user_activity_t {
    QByteArrayData data[8];
    char stringdata0[170];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_session_user_activity_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_session_user_activity_t qt_meta_stringdata_session_user_activity = {
    {
QT_MOC_LITERAL(0, 0, 21), // "session_user_activity"
QT_MOC_LITERAL(1, 22, 17), // "onClick_btn_reset"
QT_MOC_LITERAL(2, 40, 0), // ""
QT_MOC_LITERAL(3, 41, 23), // "onDoubleClick_list_book"
QT_MOC_LITERAL(4, 65, 23), // "onTrigger_act_book_code"
QT_MOC_LITERAL(5, 89, 23), // "onTrigger_act_book_name"
QT_MOC_LITERAL(6, 113, 25), // "onTrigger_act_book_author"
QT_MOC_LITERAL(7, 139, 30) // "onTrigger_act_book_information"

    },
    "session_user_activity\0onClick_btn_reset\0"
    "\0onDoubleClick_list_book\0"
    "onTrigger_act_book_code\0onTrigger_act_book_name\0"
    "onTrigger_act_book_author\0"
    "onTrigger_act_book_information"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_session_user_activity[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x0a /* Public */,
       3,    0,   45,    2, 0x0a /* Public */,
       4,    0,   46,    2, 0x0a /* Public */,
       5,    0,   47,    2, 0x0a /* Public */,
       6,    0,   48,    2, 0x0a /* Public */,
       7,    0,   49,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void session_user_activity::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        session_user_activity *_t = static_cast<session_user_activity *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->onClick_btn_reset(); break;
        case 1: _t->onDoubleClick_list_book(); break;
        case 2: _t->onTrigger_act_book_code(); break;
        case 3: _t->onTrigger_act_book_name(); break;
        case 4: _t->onTrigger_act_book_author(); break;
        case 5: _t->onTrigger_act_book_information(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject session_user_activity::staticMetaObject = {
    { &session_base_activity::staticMetaObject, qt_meta_stringdata_session_user_activity.data,
      qt_meta_data_session_user_activity,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *session_user_activity::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *session_user_activity::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_session_user_activity.stringdata0))
        return static_cast<void*>(const_cast< session_user_activity*>(this));
    return session_base_activity::qt_metacast(_clname);
}

int session_user_activity::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = session_base_activity::qt_metacall(_c, _id, _a);
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
QT_END_MOC_NAMESPACE
