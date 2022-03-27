/********************************************************************************
** Form generated from reading UI file 'adminwidget.ui'
**
** Created by: Qt User Interface Compiler version 6.2.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINWIDGET_H
#define UI_ADMINWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AdminWidget
{
public:
    QVBoxLayout *verticalLayout;
    QTableWidget *tableWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *exitButton;
    QSpacerItem *horizontalSpacer;
    QComboBox *comboBox_restaurant;

    void setupUi(QWidget *AdminWidget)
    {
        if (AdminWidget->objectName().isEmpty())
            AdminWidget->setObjectName(QString::fromUtf8("AdminWidget"));
        AdminWidget->resize(744, 482);
        verticalLayout = new QVBoxLayout(AdminWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        tableWidget = new QTableWidget(AdminWidget);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));

        verticalLayout->addWidget(tableWidget);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        exitButton = new QPushButton(AdminWidget);
        exitButton->setObjectName(QString::fromUtf8("exitButton"));

        horizontalLayout->addWidget(exitButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        comboBox_restaurant = new QComboBox(AdminWidget);
        comboBox_restaurant->setObjectName(QString::fromUtf8("comboBox_restaurant"));

        horizontalLayout->addWidget(comboBox_restaurant);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(AdminWidget);

        QMetaObject::connectSlotsByName(AdminWidget);
    } // setupUi

    void retranslateUi(QWidget *AdminWidget)
    {
        AdminWidget->setWindowTitle(QCoreApplication::translate("AdminWidget", "Form", nullptr));
        exitButton->setText(QCoreApplication::translate("AdminWidget", "Exit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AdminWidget: public Ui_AdminWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINWIDGET_H
