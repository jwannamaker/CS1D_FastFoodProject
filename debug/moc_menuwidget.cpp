/****************************************************************************
** Meta object code from reading C++ file 'menuwidget.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../menuwidget.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'menuwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MenuWidget_t {
    const uint offsetsAndSize[24];
    char stringdata0[201];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_MenuWidget_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_MenuWidget_t qt_meta_stringdata_MenuWidget = {
    {
QT_MOC_LITERAL(0, 10), // "MenuWidget"
QT_MOC_LITERAL(11, 21), // "transmit_confirmOrder"
QT_MOC_LITERAL(33, 0), // ""
QT_MOC_LITERAL(34, 11), // "Restaurant&"
QT_MOC_LITERAL(46, 20), // "transmit_cancelOrder"
QT_MOC_LITERAL(67, 18), // "transmit_adminView"
QT_MOC_LITERAL(86, 24), // "on_confirmButton_pressed"
QT_MOC_LITERAL(111, 23), // "on_cancelButton_pressed"
QT_MOC_LITERAL(135, 19), // "recieve_itemClicked"
QT_MOC_LITERAL(155, 5), // "Item&"
QT_MOC_LITERAL(161, 17), // "deleteItemClicked"
QT_MOC_LITERAL(179, 21) // "on_editButton_pressed"

    },
    "MenuWidget\0transmit_confirmOrder\0\0"
    "Restaurant&\0transmit_cancelOrder\0"
    "transmit_adminView\0on_confirmButton_pressed\0"
    "on_cancelButton_pressed\0recieve_itemClicked\0"
    "Item&\0deleteItemClicked\0on_editButton_pressed"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MenuWidget[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   62,    2, 0x06,    1 /* Public */,
       4,    0,   65,    2, 0x06,    3 /* Public */,
       5,    0,   66,    2, 0x06,    4 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       6,    0,   67,    2, 0x08,    5 /* Private */,
       7,    0,   68,    2, 0x08,    6 /* Private */,
       8,    1,   69,    2, 0x08,    7 /* Private */,
      10,    0,   72,    2, 0x08,    9 /* Private */,
      11,    0,   73,    2, 0x08,   10 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 9,    2,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MenuWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MenuWidget *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->transmit_confirmOrder((*reinterpret_cast< Restaurant(*)>(_a[1]))); break;
        case 1: _t->transmit_cancelOrder(); break;
        case 2: _t->transmit_adminView(); break;
        case 3: _t->on_confirmButton_pressed(); break;
        case 4: _t->on_cancelButton_pressed(); break;
        case 5: _t->recieve_itemClicked((*reinterpret_cast< Item(*)>(_a[1]))); break;
        case 6: _t->deleteItemClicked(); break;
        case 7: _t->on_editButton_pressed(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MenuWidget::*)(Restaurant & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MenuWidget::transmit_confirmOrder)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (MenuWidget::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MenuWidget::transmit_cancelOrder)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (MenuWidget::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MenuWidget::transmit_adminView)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject MenuWidget::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_MenuWidget.offsetsAndSize,
    qt_meta_data_MenuWidget,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_MenuWidget_t
, QtPrivate::TypeAndForceComplete<MenuWidget, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<Restaurant &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<Item &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *MenuWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MenuWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MenuWidget.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int MenuWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void MenuWidget::transmit_confirmOrder(Restaurant & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MenuWidget::transmit_cancelOrder()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void MenuWidget::transmit_adminView()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
