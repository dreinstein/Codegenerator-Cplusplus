/****************************************************************************
** Meta object code from reading C++ file 'functionwidged.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Sources/Gui/functionwidged.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'functionwidged.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_FunctionWidged_t {
    QByteArrayData data[15];
    char stringdata0[358];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FunctionWidged_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FunctionWidged_t qt_meta_stringdata_FunctionWidged = {
    {
QT_MOC_LITERAL(0, 0, 14), // "FunctionWidged"
QT_MOC_LITERAL(1, 15, 19), // "closeFunctionWidget"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 18), // "saveFunctionWidget"
QT_MOC_LITERAL(4, 55, 24), // "closeParameterFormWidget"
QT_MOC_LITERAL(5, 80, 23), // "saveParameterFormWidget"
QT_MOC_LITERAL(6, 104, 34), // "on_pushButton_SetParameter_cl..."
QT_MOC_LITERAL(7, 139, 26), // "on_pushButton_Open_clicked"
QT_MOC_LITERAL(8, 166, 26), // "on_pushButton_Save_clicked"
QT_MOC_LITERAL(9, 193, 28), // "on_pushButton__Close_clicked"
QT_MOC_LITERAL(10, 222, 37), // "on_checkBox_FunctionReference..."
QT_MOC_LITERAL(11, 260, 35), // "on_checkBox_FunctionPointer_c..."
QT_MOC_LITERAL(12, 296, 39), // "on_functionListWidget_itemDou..."
QT_MOC_LITERAL(13, 336, 16), // "QListWidgetItem*"
QT_MOC_LITERAL(14, 353, 4) // "item"

    },
    "FunctionWidged\0closeFunctionWidget\0\0"
    "saveFunctionWidget\0closeParameterFormWidget\0"
    "saveParameterFormWidget\0"
    "on_pushButton_SetParameter_clicked\0"
    "on_pushButton_Open_clicked\0"
    "on_pushButton_Save_clicked\0"
    "on_pushButton__Close_clicked\0"
    "on_checkBox_FunctionReference_clicked\0"
    "on_checkBox_FunctionPointer_clicked\0"
    "on_functionListWidget_itemDoubleClicked\0"
    "QListWidgetItem*\0item"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FunctionWidged[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   69,    2, 0x06 /* Public */,
       3,    0,   70,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   71,    2, 0x08 /* Private */,
       5,    0,   72,    2, 0x08 /* Private */,
       6,    0,   73,    2, 0x08 /* Private */,
       7,    0,   74,    2, 0x08 /* Private */,
       8,    0,   75,    2, 0x08 /* Private */,
       9,    0,   76,    2, 0x08 /* Private */,
      10,    0,   77,    2, 0x08 /* Private */,
      11,    0,   78,    2, 0x08 /* Private */,
      12,    1,   79,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 13,   14,

       0        // eod
};

void FunctionWidged::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        FunctionWidged *_t = static_cast<FunctionWidged *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->closeFunctionWidget(); break;
        case 1: _t->saveFunctionWidget(); break;
        case 2: _t->closeParameterFormWidget(); break;
        case 3: _t->saveParameterFormWidget(); break;
        case 4: _t->on_pushButton_SetParameter_clicked(); break;
        case 5: _t->on_pushButton_Open_clicked(); break;
        case 6: _t->on_pushButton_Save_clicked(); break;
        case 7: _t->on_pushButton__Close_clicked(); break;
        case 8: _t->on_checkBox_FunctionReference_clicked(); break;
        case 9: _t->on_checkBox_FunctionPointer_clicked(); break;
        case 10: _t->on_functionListWidget_itemDoubleClicked((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (FunctionWidged::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&FunctionWidged::closeFunctionWidget)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (FunctionWidged::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&FunctionWidged::saveFunctionWidget)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject FunctionWidged::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_FunctionWidged.data,
      qt_meta_data_FunctionWidged,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *FunctionWidged::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FunctionWidged::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_FunctionWidged.stringdata0))
        return static_cast<void*>(const_cast< FunctionWidged*>(this));
    return QDialog::qt_metacast(_clname);
}

int FunctionWidged::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void FunctionWidged::closeFunctionWidget()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void FunctionWidged::saveFunctionWidget()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
