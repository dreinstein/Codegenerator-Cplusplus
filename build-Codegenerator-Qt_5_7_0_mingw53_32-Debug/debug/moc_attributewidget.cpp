/****************************************************************************
** Meta object code from reading C++ file 'attributewidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Sources/Gui/attributewidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'attributewidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_AttributeWidget_t {
    QByteArrayData data[10];
    char stringdata0[238];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AttributeWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AttributeWidget_t qt_meta_stringdata_AttributeWidget = {
    {
QT_MOC_LITERAL(0, 0, 15), // "AttributeWidget"
QT_MOC_LITERAL(1, 16, 20), // "closeAttributeWidget"
QT_MOC_LITERAL(2, 37, 0), // ""
QT_MOC_LITERAL(3, 38, 20), // "closeParameterWidget"
QT_MOC_LITERAL(4, 59, 19), // "saveAttributeWidget"
QT_MOC_LITERAL(5, 79, 28), // "on_pushButton__Close_clicked"
QT_MOC_LITERAL(6, 108, 26), // "on_pushButton_Save_clicked"
QT_MOC_LITERAL(7, 135, 36), // "on_checkBox_AttributePointer_..."
QT_MOC_LITERAL(8, 172, 38), // "on_checkBox_AttributeReferenc..."
QT_MOC_LITERAL(9, 211, 26) // "on_pushButton_Open_clicked"

    },
    "AttributeWidget\0closeAttributeWidget\0"
    "\0closeParameterWidget\0saveAttributeWidget\0"
    "on_pushButton__Close_clicked\0"
    "on_pushButton_Save_clicked\0"
    "on_checkBox_AttributePointer_clicked\0"
    "on_checkBox_AttributeReference_clicked\0"
    "on_pushButton_Open_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AttributeWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x06 /* Public */,
       3,    0,   55,    2, 0x06 /* Public */,
       4,    0,   56,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   57,    2, 0x08 /* Private */,
       6,    0,   58,    2, 0x08 /* Private */,
       7,    0,   59,    2, 0x08 /* Private */,
       8,    0,   60,    2, 0x08 /* Private */,
       9,    0,   61,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void AttributeWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        AttributeWidget *_t = static_cast<AttributeWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->closeAttributeWidget(); break;
        case 1: _t->closeParameterWidget(); break;
        case 2: _t->saveAttributeWidget(); break;
        case 3: _t->on_pushButton__Close_clicked(); break;
        case 4: _t->on_pushButton_Save_clicked(); break;
        case 5: _t->on_checkBox_AttributePointer_clicked(); break;
        //case 6: _t->on_checkBox_AttributeReference_clicked(); break;
        case 7: _t->on_pushButton_Open_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (AttributeWidget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&AttributeWidget::closeAttributeWidget)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (AttributeWidget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&AttributeWidget::closeParameterWidget)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (AttributeWidget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&AttributeWidget::saveAttributeWidget)) {
                *result = 2;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject AttributeWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_AttributeWidget.data,
      qt_meta_data_AttributeWidget,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *AttributeWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AttributeWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_AttributeWidget.stringdata0))
        return static_cast<void*>(const_cast< AttributeWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int AttributeWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void AttributeWidget::closeAttributeWidget()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void AttributeWidget::closeParameterWidget()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void AttributeWidget::saveAttributeWidget()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
