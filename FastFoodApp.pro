QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    button.cpp \
    customer.cpp \
    databasehelper.cpp \
    login.cpp \
    main.cpp \
    mainmenuwidget.cpp \
    mainwindow.cpp \
    menu.cpp \
    menuwidget.cpp \
    restaurant.cpp \
    restaurantwidget.cpp

HEADERS += \
    button.h \
    customer.h \
    databasehelper.h \
    login.h \
    mainmenuwidget.h \
    mainwindow.h \
    menu.h \
    menuwidget.h \
    restaurant.h \
    restaurantwidget.h

FORMS += \
    login.ui \
    mainmenuwidget.ui \
    mainwindow.ui \
    menuwidget.ui \
    restaurantwidget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource.qrc
