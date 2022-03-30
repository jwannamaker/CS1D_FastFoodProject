/****************************************************************************
** Meta object code from reading C++ file 'mainmenuwidget.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../mainmenuwidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainmenuwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainMenuWidget_t {
    const uint offsetsAndSize[16];
    char stringdata0[155];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_MainMenuWidget_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_MainMenuWidget_t qt_meta_stringdata_MainMenuWidget = {
    {
QT_MOC_LITERAL(0, 14), // "MainMenuWidget"
QT_MOC_LITERAL(15, 15), // "transmit_logout"
QT_MOC_LITERAL(31, 0), // ""
QT_MOC_LITERAL(32, 23), // "transmit_restaurantView"
QT_MOC_LITERAL(56, 20), // "transmit_revenueView"
QT_MOC_LITERAL(77, 23), // "on_logOutButton_pressed"
QT_MOC_LITERAL(101, 28), // "on_restaurantsButton_pressed"
QT_MOC_LITERAL(130, 24) // "on_revenueButton_pressed"

    },
    "MainMenuWidget\0transmit_logout\0\0"
    "transmit_restaurantView\0transmit_revenueView\0"
    "on_logOutButton_pressed\0"
    "on_restaurantsButton_pressed\0"
    "on_revenueButton_pressed"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainMenuWidget[] = {

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
       1,    0,   50,    2, 0x06,    1 /* Public */,
       3,    0,   51,    2, 0x06,    2 /* Public */,
       4,    0,   52,    2, 0x06,    3 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       5,    0,   53,    2, 0x08,    4 /* Private */,
       6,    0,   54,    2, 0x08,    5 /* Private */,
       7,    0,   55,    2, 0x08,    6 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainMenuWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainMenuWidget *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->transmit_logout(); break;
        case 1: _t->transmit_restaurantView(); break;
        case 2: _t->transmit_revenueView(); break;
        case 3: _t->on_logOutButton_pressed(); break;
        case 4: _t->on_restaurantsButton_pressed(); break;
        case 5: _t->on_revenueButton_pressed(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MainMenuWidget::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainMenuWidget::transmit_logout)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (MainMenuWidget::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainMenuWidget::transmit_restaurantView)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (MainMenuWidget::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainMenuWidget::transmit_revenueView)) {
                *result = 2;
                return;
            }
        }
    }
    (void)_a;
}

const QMetaObject MainMenuWidget::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_MainMenuWidget.offsetsAndSize,
    qt_meta_data_MainMenuWidget,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_MainMenuWidget_t
, QtPrivate::TypeAndForceComplete<MainMenuWidget, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *MainMenuWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainMenuWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainMenuWidget.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int MainMenuWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
void MainMenuWidget::transmit_logout()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void MainMenuWidget::transmit_restaurantView()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void MainMenuWidget::transmit_revenueView()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
