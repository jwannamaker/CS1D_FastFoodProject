/********************************************************************************
** Form generated from reading UI file 'mainmenuwidget.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINMENUWIDGET_H
#define UI_MAINMENUWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainMenuWidget
{
public:
    QGridLayout *gridLayout;
    QGraphicsView *graphicsView;
    QVBoxLayout *verticalLayout;
    QLabel *welcomeLabel;
    QSpacerItem *verticalSpacer;
    QPushButton *restaurantsButton;
    QPushButton *orderHistoryButton;
    QPushButton *logOutButton;

    void setupUi(QWidget *MainMenuWidget)
    {
        if (MainMenuWidget->objectName().isEmpty())
            MainMenuWidget->setObjectName(QString::fromUtf8("MainMenuWidget"));
        MainMenuWidget->resize(756, 522);
        gridLayout = new QGridLayout(MainMenuWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        graphicsView = new QGraphicsView(MainMenuWidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));

        gridLayout->addWidget(graphicsView, 0, 0, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        welcomeLabel = new QLabel(MainMenuWidget);
        welcomeLabel->setObjectName(QString::fromUtf8("welcomeLabel"));

        verticalLayout->addWidget(welcomeLabel);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        restaurantsButton = new QPushButton(MainMenuWidget);
        restaurantsButton->setObjectName(QString::fromUtf8("restaurantsButton"));

        verticalLayout->addWidget(restaurantsButton);

        orderHistoryButton = new QPushButton(MainMenuWidget);
        orderHistoryButton->setObjectName(QString::fromUtf8("orderHistoryButton"));

        verticalLayout->addWidget(orderHistoryButton);

        logOutButton = new QPushButton(MainMenuWidget);
        logOutButton->setObjectName(QString::fromUtf8("logOutButton"));

        verticalLayout->addWidget(logOutButton);


        gridLayout->addLayout(verticalLayout, 0, 1, 1, 1);


        retranslateUi(MainMenuWidget);

        QMetaObject::connectSlotsByName(MainMenuWidget);
    } // setupUi

    void retranslateUi(QWidget *MainMenuWidget)
    {
        MainMenuWidget->setWindowTitle(QCoreApplication::translate("MainMenuWidget", "Form", nullptr));
        welcomeLabel->setText(QCoreApplication::translate("MainMenuWidget", "Welcome, Guest", nullptr));
        restaurantsButton->setText(QCoreApplication::translate("MainMenuWidget", "Restaurants", nullptr));
        orderHistoryButton->setText(QCoreApplication::translate("MainMenuWidget", "Order History", nullptr));
        logOutButton->setText(QCoreApplication::translate("MainMenuWidget", "Log Out", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainMenuWidget: public Ui_MainMenuWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINMENUWIDGET_H
