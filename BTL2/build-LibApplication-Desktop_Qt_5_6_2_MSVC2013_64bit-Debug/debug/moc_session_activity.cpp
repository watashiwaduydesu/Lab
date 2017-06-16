/****************************************************************************
** Meta object code from reading C++ file 'session_activity.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "C:/Users/pc hp/Downloads/Assignment_02_KTLT_Version_1-master/LibApplication/session_activity.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'session_activity.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_session_activity_t {
    QByteArrayData data[14];
    char stringdata0[309];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_session_activity_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_session_activity_t qt_meta_stringdata_session_activity = {
    {
QT_MOC_LITERAL(0, 0, 16), // "session_activity"
QT_MOC_LITERAL(1, 17, 25), // "onTrigger_change_password"
QT_MOC_LITERAL(2, 43, 0), // ""
QT_MOC_LITERAL(3, 44, 14), // "onTrigger_exit"
QT_MOC_LITERAL(4, 59, 21), // "onTrigger_information"
QT_MOC_LITERAL(5, 81, 23), // "onTrigger_act_book_code"
QT_MOC_LITERAL(6, 105, 23), // "onTrigger_act_book_name"
QT_MOC_LITERAL(7, 129, 25), // "onTrigger_act_book_author"
QT_MOC_LITERAL(8, 155, 30), // "onTrigger_act_book_information"
QT_MOC_LITERAL(9, 186, 22), // "onTrigger_act_add_book"
QT_MOC_LITERAL(10, 209, 23), // "onTrigger_act_find_book"
QT_MOC_LITERAL(11, 233, 26), // "onTrigger_act_require_book"
QT_MOC_LITERAL(12, 260, 25), // "onTrigger_act_borrow_book"
QT_MOC_LITERAL(13, 286, 22) // "onTrigger_act_owe_book"

    },
    "session_activity\0onTrigger_change_password\0"
    "\0onTrigger_exit\0onTrigger_information\0"
    "onTrigger_act_book_code\0onTrigger_act_book_name\0"
    "onTrigger_act_book_author\0"
    "onTrigger_act_book_information\0"
    "onTrigger_act_add_book\0onTrigger_act_find_book\0"
    "onTrigger_act_require_book\0"
    "onTrigger_act_borrow_book\0"
    "onTrigger_act_owe_book"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_session_activity[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   74,    2, 0x0a /* Public */,
       3,    0,   75,    2, 0x0a /* Public */,
       4,    0,   76,    2, 0x0a /* Public */,
       5,    0,   77,    2, 0x0a /* Public */,
       6,    0,   78,    2, 0x0a /* Public */,
       7,    0,   79,    2, 0x0a /* Public */,
       8,    0,   80,    2, 0x0a /* Public */,
       9,    0,   81,    2, 0x0a /* Public */,
      10,    0,   82,    2, 0x0a /* Public */,
      11,    0,   83,    2, 0x0a /* Public */,
      12,    0,   84,    2, 0x0a /* Public */,
      13,    0,   85,    2, 0x0a /* Public */,

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
    QMetaType::Void,

       0        // eod
};

void session_activity::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        session_activity *_t = static_cast<session_activity *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->onTrigger_change_password(); break;
        case 1: _t->onTrigger_exit(); break;
        case 2: _t->onTrigger_information(); break;
        case 3: _t->onTrigger_act_book_code(); break;
        case 4: _t->onTrigger_act_book_name(); break;
        case 5: _t->onTrigger_act_book_author(); break;
        case 6: _t->onTrigger_act_book_information(); break;
        case 7: _t->onTrigger_act_add_book(); break;
        case 8: _t->onTrigger_act_find_book(); break;
        case 9: _t->onTrigger_act_require_book(); break;
        case 10: _t->onTrigger_act_borrow_book(); break;
        case 11: _t->onTrigger_act_owe_book(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject session_activity::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_session_activity.data,
      qt_meta_data_session_activity,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *session_activity::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *session_activity::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_session_activity.stringdata0))
        return static_cast<void*>(const_cast< session_activity*>(this));
    return QWidget::qt_metacast(_clname);
}

int session_activity::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
