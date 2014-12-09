/****************************************************************************
** Meta object code from reading C++ file 'studentviewtextbooks.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.0.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../cuTPS/studentviewtextbooks.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'studentviewtextbooks.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.0.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_StudentViewTextbooks_t {
    QByteArrayData data[7];
    char stringdata[131];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_StudentViewTextbooks_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_StudentViewTextbooks_t qt_meta_stringdata_StudentViewTextbooks = {
    {
QT_MOC_LITERAL(0, 0, 20),
QT_MOC_LITERAL(1, 21, 11),
QT_MOC_LITERAL(2, 33, 0),
QT_MOC_LITERAL(3, 34, 23),
QT_MOC_LITERAL(4, 58, 23),
QT_MOC_LITERAL(5, 82, 23),
QT_MOC_LITERAL(6, 106, 23)
    },
    "StudentViewTextbooks\0showDetails\0\0"
    "on_pushButton_6_clicked\0on_pushButton_7_clicked\0"
    "on_pushButton_8_clicked\0on_pushButton_5_clicked\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_StudentViewTextbooks[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x08,
       3,    0,   42,    2, 0x08,
       4,    0,   43,    2, 0x08,
       5,    0,   44,    2, 0x08,
       6,    0,   45,    2, 0x08,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void StudentViewTextbooks::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        StudentViewTextbooks *_t = static_cast<StudentViewTextbooks *>(_o);
        switch (_id) {
        case 0: _t->showDetails((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->on_pushButton_6_clicked(); break;
        case 2: _t->on_pushButton_7_clicked(); break;
        case 3: _t->on_pushButton_8_clicked(); break;
        case 4: _t->on_pushButton_5_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject StudentViewTextbooks::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_StudentViewTextbooks.data,
      qt_meta_data_StudentViewTextbooks,  qt_static_metacall, 0, 0}
};


const QMetaObject *StudentViewTextbooks::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *StudentViewTextbooks::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_StudentViewTextbooks.stringdata))
        return static_cast<void*>(const_cast< StudentViewTextbooks*>(this));
    return QWidget::qt_metacast(_clname);
}

int StudentViewTextbooks::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
