/****************************************************************************
** Meta object code from reading C++ file 'restaurantwidget.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../restaurantwidget.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'restaurantwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_RestaurantWidget_t {
    const uint offsetsAndSize[26];
    char stringdata0[245];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_RestaurantWidget_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_RestaurantWidget_t qt_meta_stringdata_RestaurantWidget = {
    {
QT_MOC_LITERAL(0, 16), // "RestaurantWidget"
QT_MOC_LITERAL(17, 15), // "transmit_cancel"
QT_MOC_LITERAL(33, 0), // ""
QT_MOC_LITERAL(34, 21), // "transmit_viewRestMenu"
QT_MOC_LITERAL(56, 11), // "Restaurant&"
QT_MOC_LITERAL(68, 4), // "rest"
QT_MOC_LITERAL(73, 19), // "addRestaurantToTrip"
QT_MOC_LITERAL(93, 22), // "addRestaurantsFromFile"
QT_MOC_LITERAL(116, 24), // "on_confirmButton_pressed"
QT_MOC_LITERAL(141, 23), // "on_cancelButton_pressed"
QT_MOC_LITERAL(165, 25), // "recieve_restaurantClicked"
QT_MOC_LITERAL(191, 47), // "on_comboBox_initialLocation_c..."
QT_MOC_LITERAL(239, 5) // "index"

    },
    "RestaurantWidget\0transmit_cancel\0\0"
    "transmit_viewRestMenu\0Restaurant&\0"
    "rest\0addRestaurantToTrip\0"
    "addRestaurantsFromFile\0on_confirmButton_pressed\0"
    "on_cancelButton_pressed\0"
    "recieve_restaurantClicked\0"
    "on_comboBox_initialLocation_currentIndexChanged\0"
    "index"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_RestaurantWidget[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   62,    2, 0x06,    1 /* Public */,
       3,    1,   63,    2, 0x06,    2 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       6,    1,   66,    2, 0x0a,    4 /* Public */,
       7,    0,   69,    2, 0x0a,    6 /* Public */,
       8,    0,   70,    2, 0x08,    7 /* Private */,
       9,    0,   71,    2, 0x08,    8 /* Private */,
      10,    1,   72,    2, 0x08,    9 /* Private */,
      11,    1,   75,    2, 0x08,   11 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    5,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    2,
    QMetaType::Void, QMetaType::Int,   12,

       0        // eod
};

void RestaurantWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<RestaurantWidget *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->transmit_cancel(); break;
        case 1: _t->transmit_viewRestMenu((*reinterpret_cast< Restaurant(*)>(_a[1]))); break;
        case 2: _t->addRestaurantToTrip((*reinterpret_cast< Restaurant(*)>(_a[1]))); break;
        case 3: _t->addRestaurantsFromFile(); break;
        case 4: _t->on_confirmButton_pressed(); break;
        case 5: _t->on_cancelButton_pressed(); break;
        case 6: _t->recieve_restaurantClicked((*reinterpret_cast< Restaurant(*)>(_a[1]))); break;
        case 7: _t->on_comboBox_initialLocation_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (RestaurantWidget::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&RestaurantWidget::transmit_cancel)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (RestaurantWidget::*)(Restaurant & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&RestaurantWidget::transmit_viewRestMenu)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject RestaurantWidget::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_RestaurantWidget.offsetsAndSize,
    qt_meta_data_RestaurantWidget,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_RestaurantWidget_t
, QtPrivate::TypeAndForceComplete<RestaurantWidget, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<Restaurant &, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<Restaurant &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<Restaurant &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>


>,
    nullptr
} };


const QMetaObject *RestaurantWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RestaurantWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_RestaurantWidget.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int RestaurantWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void RestaurantWidget::transmit_cancel()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void RestaurantWidget::transmit_viewRestMenu(Restaurant & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
