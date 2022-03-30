/********************************************************************************
** Form generated from reading UI file 'adminwidget.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINWIDGET_H
#define UI_ADMINWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AdminWidget
{
public:
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QComboBox *comboBox_restaurant;
    QSpacerItem *verticalSpacer;
    QLabel *label;
    QLineEdit *lineEdit_menuItem;
    QLabel *label_2;
    QDoubleSpinBox *doubleSpinBox_itemPrice;
    QPushButton *addItemButton;
    QSpacerItem *verticalSpacer_2;
    QPushButton *pushButton_delete;
    QPushButton *pushButton_editPrice;
    QSpacerItem *verticalSpacer_3;
    QPushButton *exitButton;
    QTableWidget *tableWidget;

    void setupUi(QWidget *AdminWidget)
    {
        if (AdminWidget->objectName().isEmpty())
            AdminWidget->setObjectName(QString::fromUtf8("AdminWidget"));
        AdminWidget->resize(744, 482);
        horizontalLayout = new QHBoxLayout(AdminWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        comboBox_restaurant = new QComboBox(AdminWidget);
        comboBox_restaurant->setObjectName(QString::fromUtf8("comboBox_restaurant"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(comboBox_restaurant->sizePolicy().hasHeightForWidth());
        comboBox_restaurant->setSizePolicy(sizePolicy);
        comboBox_restaurant->setMinimumSize(QSize(70, 0));

        verticalLayout->addWidget(comboBox_restaurant);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        label = new QLabel(AdminWidget);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        lineEdit_menuItem = new QLineEdit(AdminWidget);
        lineEdit_menuItem->setObjectName(QString::fromUtf8("lineEdit_menuItem"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lineEdit_menuItem->sizePolicy().hasHeightForWidth());
        lineEdit_menuItem->setSizePolicy(sizePolicy1);

        verticalLayout->addWidget(lineEdit_menuItem);

        label_2 = new QLabel(AdminWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout->addWidget(label_2);

        doubleSpinBox_itemPrice = new QDoubleSpinBox(AdminWidget);
        doubleSpinBox_itemPrice->setObjectName(QString::fromUtf8("doubleSpinBox_itemPrice"));

        verticalLayout->addWidget(doubleSpinBox_itemPrice);

        addItemButton = new QPushButton(AdminWidget);
        addItemButton->setObjectName(QString::fromUtf8("addItemButton"));

        verticalLayout->addWidget(addItemButton);

        verticalSpacer_2 = new QSpacerItem(20, 30, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer_2);

        pushButton_delete = new QPushButton(AdminWidget);
        pushButton_delete->setObjectName(QString::fromUtf8("pushButton_delete"));

        verticalLayout->addWidget(pushButton_delete);

        pushButton_editPrice = new QPushButton(AdminWidget);
        pushButton_editPrice->setObjectName(QString::fromUtf8("pushButton_editPrice"));

        verticalLayout->addWidget(pushButton_editPrice);

        verticalSpacer_3 = new QSpacerItem(20, 30, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer_3);

        exitButton = new QPushButton(AdminWidget);
        exitButton->setObjectName(QString::fromUtf8("exitButton"));

        verticalLayout->addWidget(exitButton);


        horizontalLayout->addLayout(verticalLayout);

        tableWidget = new QTableWidget(AdminWidget);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setEditTriggers(QAbstractItemView::DoubleClicked|QAbstractItemView::SelectedClicked);
        tableWidget->setTabKeyNavigation(false);
        tableWidget->setDragDropOverwriteMode(false);
        tableWidget->setSelectionMode(QAbstractItemView::ContiguousSelection);
        tableWidget->setGridStyle(Qt::NoPen);
        tableWidget->verticalHeader()->setVisible(false);

        horizontalLayout->addWidget(tableWidget);


        retranslateUi(AdminWidget);

        QMetaObject::connectSlotsByName(AdminWidget);
    } // setupUi

    void retranslateUi(QWidget *AdminWidget)
    {
        AdminWidget->setWindowTitle(QCoreApplication::translate("AdminWidget", "Form", nullptr));
        label->setText(QCoreApplication::translate("AdminWidget", "Name", nullptr));
        label_2->setText(QCoreApplication::translate("AdminWidget", "Price", nullptr));
        addItemButton->setText(QCoreApplication::translate("AdminWidget", "Add Item", nullptr));
        pushButton_delete->setText(QCoreApplication::translate("AdminWidget", "Delete Item", nullptr));
        pushButton_editPrice->setText(QCoreApplication::translate("AdminWidget", "Edit Price", nullptr));
        exitButton->setText(QCoreApplication::translate("AdminWidget", "Exit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AdminWidget: public Ui_AdminWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINWIDGET_H
