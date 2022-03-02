/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QWidget>
#include "login.h"
#include "mainmenuwidget.h"
#include "restaurantwidget.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QStackedWidget *stackedWidget;
    Login *loginPage;
    MainMenuWidget *mainMenuPage;
    RestaurantWidget *restaurantsPage;
    QWidget *orderHistoryPage;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        loginPage = new Login();
        loginPage->setObjectName(QString::fromUtf8("loginPage"));
        stackedWidget->addWidget(loginPage);
        mainMenuPage = new MainMenuWidget();
        mainMenuPage->setObjectName(QString::fromUtf8("mainMenuPage"));
        stackedWidget->addWidget(mainMenuPage);
        restaurantsPage = new RestaurantWidget();
        restaurantsPage->setObjectName(QString::fromUtf8("restaurantsPage"));
        stackedWidget->addWidget(restaurantsPage);
        orderHistoryPage = new QWidget();
        orderHistoryPage->setObjectName(QString::fromUtf8("orderHistoryPage"));
        stackedWidget->addWidget(orderHistoryPage);

        gridLayout->addWidget(stackedWidget, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Fast Food Planner", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
