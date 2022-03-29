QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    adminwidget.cpp \
    button.cpp \
    customer.cpp \
    databasehelper.cpp \
    item.cpp \
    loginwidget.cpp \
    main.cpp \
    mainmenuwidget.cpp \
    mainwindow.cpp \
    menuwidget.cpp \
    restaurant.cpp \
    restaurantwidget.cpp \
    revenuewidget.cpp

HEADERS += \
    adminwidget.h \
    button.h \
    customer.h \
    databasehelper.h \
    item.h \
    loginwidget.h \
    mainmenuwidget.h \
    mainwindow.h \
    menuwidget.h \
    restaurant.h \
    restaurantwidget.h \
    revenuewidget.h

FORMS += \
    adminwidget.ui \
    loginwidget.ui \
    mainmenuwidget.ui \
    mainwindow.ui \
    menuwidget.ui \
    restaurantwidget.ui \
    revenuewidget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource.qrc
