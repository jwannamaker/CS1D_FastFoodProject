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
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QComboBox *comboBox_restaurant;
    QSpacerItem *verticalSpacer;
    QPushButton *addItemButton;
    QPushButton *saveButton;
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

        addItemButton = new QPushButton(AdminWidget);
        addItemButton->setObjectName(QString::fromUtf8("addItemButton"));

        verticalLayout->addWidget(addItemButton);

        saveButton = new QPushButton(AdminWidget);
        saveButton->setObjectName(QString::fromUtf8("saveButton"));

        verticalLayout->addWidget(saveButton);

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
        addItemButton->setText(QCoreApplication::translate("AdminWidget", "Add Item", nullptr));
        saveButton->setText(QCoreApplication::translate("AdminWidget", "Save Changes", nullptr));
        exitButton->setText(QCoreApplication::translate("AdminWidget", "Exit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AdminWidget: public Ui_AdminWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINWIDGET_H
