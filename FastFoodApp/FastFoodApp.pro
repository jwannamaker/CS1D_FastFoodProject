QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    database.cpp \
    login.cpp \
    main.cpp \
    mainmenuwidget.cpp \
    mainwindow.cpp \
    restaurantwidget.cpp

HEADERS += \
    database.h \
    login.h \
    mainmenuwidget.h \
    mainwindow.h \
    restaurantwidget.h

FORMS += \
    login.ui \
    mainmenuwidget.ui \
    mainwindow.ui \
    restaurantwidget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
