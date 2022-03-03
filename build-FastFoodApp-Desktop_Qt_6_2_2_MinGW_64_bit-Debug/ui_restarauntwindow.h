/********************************************************************************
** Form generated from reading UI file 'restarauntwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RESTARAUNTWINDOW_H
#define UI_RESTARAUNTWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <QMainWindow>
#include "tileview.h"
#include "tripview.h"

QT_BEGIN_NAMESPACE

class Ui_RestarauntWindow
{
public:
    QWidget *centralwidget;
    QWidget *widget;
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    TripView *listView;
    QHBoxLayout *horizontalLayout;
    QPushButton *confirmTripButton;
    QPushButton *editTripButton;
    TileView *RestaurantTiles;
    QMenuBar *menubar;
    QButtonGroup *buttonGroup;

    void setupUi(QMainWindow *RestarauntWindow)
    {
        if (RestarauntWindow->objectName().isEmpty())
            RestarauntWindow->setObjectName(QString::fromUtf8("RestarauntWindow"));
        RestarauntWindow->resize(800, 600);
        centralwidget = new QWidget(RestarauntWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(10, 0, 781, 551));
        gridLayout_2 = new QGridLayout(widget);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(229, 0));

        verticalLayout->addWidget(label);

        listView = new TripView(widget);
        listView->setObjectName(QString::fromUtf8("listView"));
        listView->setMinimumSize(QSize(229, 0));

        verticalLayout->addWidget(listView);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        confirmTripButton = new QPushButton(widget);
        buttonGroup = new QButtonGroup(RestarauntWindow);
        buttonGroup->setObjectName(QString::fromUtf8("buttonGroup"));
        buttonGroup->addButton(confirmTripButton);
        confirmTripButton->setObjectName(QString::fromUtf8("confirmTripButton"));
        confirmTripButton->setMinimumSize(QSize(111, 0));

        horizontalLayout->addWidget(confirmTripButton);

        editTripButton = new QPushButton(widget);
        buttonGroup->addButton(editTripButton);
        editTripButton->setObjectName(QString::fromUtf8("editTripButton"));
        editTripButton->setMinimumSize(QSize(111, 0));

        horizontalLayout->addWidget(editTripButton);


        verticalLayout->addLayout(horizontalLayout);


        gridLayout_2->addLayout(verticalLayout, 0, 0, 1, 1);

        RestaurantTiles = new TileView(widget);
        RestaurantTiles->setObjectName(QString::fromUtf8("RestaurantTiles"));
        RestaurantTiles->setMinimumSize(QSize(500, 0));

        gridLayout_2->addWidget(RestaurantTiles, 0, 1, 1, 1);

        menubar = new QMenuBar(RestarauntWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 20));

        retranslateUi(RestarauntWindow);

        QMetaObject::connectSlotsByName(RestarauntWindow);
    } // setupUi

    void retranslateUi(QMainWindow *RestarauntWindow)
    {
        RestarauntWindow->setWindowTitle(QCoreApplication::translate("RestarauntWindow", "MainMenu", nullptr));
        label->setText(QCoreApplication::translate("RestarauntWindow", "Visited Restaurants", nullptr));
        confirmTripButton->setText(QCoreApplication::translate("RestarauntWindow", "Confirm Trip", nullptr));
        editTripButton->setText(QCoreApplication::translate("RestarauntWindow", "Edit Trip", nullptr));
    } // retranslateUi

};

namespace Ui {
class RestarauntWindow: public Ui_Resprivate slots:
        void on_confirmTripButton_pressed();
        RetarauntWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RESTARAUNTWINDOW_H
