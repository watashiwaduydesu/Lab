/****************************************************************************
** Meta object code from reading C++ file 'edit_book_activity.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../LibApplication/edit_book_activity.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'edit_book_activity.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_edit_book_activity_t {
    QByteArrayData data[5];
    char stringdata0[77];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_edit_book_activity_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_edit_book_activity_t qt_meta_stringdata_edit_book_activity = {
    {
QT_MOC_LITERAL(0, 0, 18), // "edit_book_activity"
QT_MOC_LITERAL(1, 19, 18), // "onClick_btn_return"
QT_MOC_LITERAL(2, 38, 0), // ""
QT_MOC_LITERAL(3, 39, 18), // "onClick_btn_update"
QT_MOC_LITERAL(4, 58, 18) // "onClick_btn_remove"

    },
    "edit_book_activity\0onClick_btn_return\0"
    "\0onClick_btn_update\0onClick_btn_remove"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_edit_book_activity[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   29,    2, 0x0a /* Public */,
       3,    0,   30,    2, 0x0a /* Public */,
       4,    0,   31,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void edit_book_activity::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        edit_book_activity *_t = static_cast<edit_book_activity *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->onClick_btn_return(); break;
        case 1: _t->onClick_btn_update(); break;
        case 2: _t->onClick_btn_remove(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject edit_book_activity::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_edit_book_activity.data,
      qt_meta_data_edit_book_activity,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *edit_book_activity::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *edit_book_activity::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_edit_book_activity.stringdata0))
        return static_cast<void*>(const_cast< edit_book_activity*>(this));
    return QWidget::qt_metacast(_clname);
}

int edit_book_activity::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
