/****************************************************************************
** Meta object code from reading C++ file 'classform.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Sources/Gui/classform.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'classform.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ClassForm_t {
    QByteArrayData data[11];
    char stringdata0[235];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ClassForm_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ClassForm_t qt_meta_stringdata_ClassForm = {
    {
QT_MOC_LITERAL(0, 0, 9), // "ClassForm"
QT_MOC_LITERAL(1, 10, 19), // "closeFunctionWidget"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 20), // "closeAttributeWidget"
QT_MOC_LITERAL(4, 52, 21), // "on_SaveButton_clicked"
QT_MOC_LITERAL(5, 74, 22), // "on_CloseButton_clicked"
QT_MOC_LITERAL(6, 97, 31), // "on_CreateFunctionButton_clicked"
QT_MOC_LITERAL(7, 129, 23), // "closeFunctionFormWidget"
QT_MOC_LITERAL(8, 153, 32), // "on_CreateAttributeButton_clicked"
QT_MOC_LITERAL(9, 186, 24), // "closeAttributeFormWidget"
QT_MOC_LITERAL(10, 211, 23) // "saveAttributeFormWidget"

    },
    "ClassForm\0closeFunctionWidget\0\0"
    "closeAttributeWidget\0on_SaveButton_clicked\0"
    "on_CloseButton_clicked\0"
    "on_CreateFunctionButton_clicked\0"
    "closeFunctionFormWidget\0"
    "on_CreateAttributeButton_clicked\0"
    "closeAttributeFormWidget\0"
    "saveAttributeFormWidget"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ClassForm[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x06 /* Public */,
       3,    0,   60,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   61,    2, 0x08 /* Private */,
       5,    0,   62,    2, 0x08 /* Private */,
       6,    0,   63,    2, 0x08 /* Private */,
       7,    0,   64,    2, 0x08 /* Private */,
       8,    0,   65,    2, 0x08 /* Private */,
       9,    0,   66,    2, 0x08 /* Private */,
      10,    0,   67,    2, 0x08 /* Private */,

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

       0        // eod
};

void ClassForm::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ClassForm *_t = static_cast<ClassForm *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->closeFunctionWidget(); break;
        case 1: _t->closeAttributeWidget(); break;
        case 2: _t->on_SaveButton_clicked(); break;
        case 3: _t->on_CloseButton_clicked(); break;
        case 4: _t->on_CreateFunctionButton_clicked(); break;
        case 5: _t->closeFunctionFormWidget(); break;
        case 6: _t->on_CreateAttributeButton_clicked(); break;
        case 7: _t->closeAttributeFormWidget(); break;
        case 8: _t->saveAttributeFormWidget(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (ClassForm::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ClassForm::closeFunctionWidget)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (ClassForm::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ClassForm::closeAttributeWidget)) {
                *result = 1;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject ClassForm::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_ClassForm.data,
      qt_meta_data_ClassForm,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ClassForm::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ClassForm::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ClassForm.stringdata0))
        return static_cast<void*>(const_cast< ClassForm*>(this));
    return QWidget::qt_metacast(_clname);
}

int ClassForm::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void ClassForm::closeFunctionWidget()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void ClassForm::closeAttributeWidget()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
