/****************************************************************************
** Meta object code from reading C++ file 'button.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../button.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'button.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Button_t {
    const uint offsetsAndSize[20];
    char stringdata0[149];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_Button_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_Button_t qt_meta_stringdata_Button = {
    {
QT_MOC_LITERAL(0, 6), // "Button"
QT_MOC_LITERAL(7, 26), // "transmit_restaurantClicked"
QT_MOC_LITERAL(34, 0), // ""
QT_MOC_LITERAL(35, 11), // "Restaurant&"
QT_MOC_LITERAL(47, 26), // "transmit_restaurantChecked"
QT_MOC_LITERAL(74, 20), // "transmit_itemClicked"
QT_MOC_LITERAL(95, 5), // "Item&"
QT_MOC_LITERAL(101, 17), // "restaurantClicked"
QT_MOC_LITERAL(119, 17), // "restaurantChecked"
QT_MOC_LITERAL(137, 11) // "itemClicked"

    },
    "Button\0transmit_restaurantClicked\0\0"
    "Restaurant&\0transmit_restaurantChecked\0"
    "transmit_itemClicked\0Item&\0restaurantClicked\0"
    "restaurantChecked\0itemClicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Button[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   50,    2, 0x06,    1 /* Public */,
       4,    1,   53,    2, 0x06,    3 /* Public */,
       5,    1,   56,    2, 0x06,    5 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       7,    0,   59,    2, 0x0a,    7 /* Public */,
       8,    0,   60,    2, 0x0a,    8 /* Public */,
       9,    0,   61,    2, 0x0a,    9 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 6,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Button::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Button *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->transmit_restaurantClicked((*reinterpret_cast< Restaurant(*)>(_a[1]))); break;
        case 1: _t->transmit_restaurantChecked((*reinterpret_cast< Restaurant(*)>(_a[1]))); break;
        case 2: _t->transmit_itemClicked((*reinterpret_cast< Item(*)>(_a[1]))); break;
        case 3: _t->restaurantClicked(); break;
        case 4: _t->restaurantChecked(); break;
        case 5: _t->itemClicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Button::*)(Restaurant & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Button::transmit_restaurantClicked)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Button::*)(Restaurant & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Button::transmit_restaurantChecked)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Button::*)(Item & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Button::transmit_itemClicked)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject Button::staticMetaObject = { {
    QMetaObject::SuperData::link<QPushButton::staticMetaObject>(),
    qt_meta_stringdata_Button.offsetsAndSize,
    qt_meta_data_Button,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_Button_t
, QtPrivate::TypeAndForceComplete<Button, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<Restaurant &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<Restaurant &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<Item &, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *Button::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Button::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Button.stringdata0))
        return static_cast<void*>(this);
    return QPushButton::qt_metacast(_clname);
}

int Button::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QPushButton::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void Button::transmit_restaurantClicked(Restaurant & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Button::transmit_restaurantChecked(Restaurant & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Button::transmit_itemClicked(Item & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
