/****************************************************************************
** Meta object code from reading C++ file 'functionwidged.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Sources/Gui/functionwidged.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'functionwidged.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_FunctionWidged_t {
    QByteArrayData data[8];
    char stringdata0[167];
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
QT_MOC_LITERAL(3, 36, 23), // "on_Close_Button_clicked"
QT_MOC_LITERAL(4, 60, 22), // "on_Save_Button_clicked"
QT_MOC_LITERAL(5, 83, 34), // "on_pushButton_SetParameter_cl..."
QT_MOC_LITERAL(6, 118, 24), // "closeParameterFormWidget"
QT_MOC_LITERAL(7, 143, 23) // "saveParameterFormWidget"

    },
    "FunctionWidged\0closeFunctionWidget\0\0"
    "on_Close_Button_clicked\0on_Save_Button_clicked\0"
    "on_pushButton_SetParameter_clicked\0"
    "closeParameterFormWidget\0"
    "saveParameterFormWidget"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FunctionWidged[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   45,    2, 0x08 /* Private */,
       4,    0,   46,    2, 0x08 /* Private */,
       5,    0,   47,    2, 0x08 /* Private */,
       6,    0,   48,    2, 0x08 /* Private */,
       7,    0,   49,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void FunctionWidged::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        FunctionWidged *_t = static_cast<FunctionWidged *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->closeFunctionWidget(); break;
        case 1: _t->on_Close_Button_clicked(); break;
        case 2: _t->on_Save_Button_clicked(); break;
        case 3: _t->on_pushButton_SetParameter_clicked(); break;
        case 4: _t->closeParameterFormWidget(); break;
        case 5: _t->saveParameterFormWidget(); break;
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
    }
    Q_UNUSED(_a);
}

const QMetaObject FunctionWidged::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_FunctionWidged.data,
      qt_meta_data_FunctionWidged,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *FunctionWidged::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FunctionWidged::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
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
void FunctionWidged::closeFunctionWidget()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
