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
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFormLayout>
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
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *lineEdit_menuItem;
    QLabel *label_2;
    QDoubleSpinBox *doubleSpinBox_itemPrice;
    QSpacerItem *verticalSpacer_2;
    QPushButton *addItemButton;
    QPushButton *pushButton_delete;
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
        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label = new QLabel(AdminWidget);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        lineEdit_menuItem = new QLineEdit(AdminWidget);
        lineEdit_menuItem->setObjectName(QString::fromUtf8("lineEdit_menuItem"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lineEdit_menuItem->sizePolicy().hasHeightForWidth());
        lineEdit_menuItem->setSizePolicy(sizePolicy);

        formLayout->setWidget(0, QFormLayout::FieldRole, lineEdit_menuItem);

        label_2 = new QLabel(AdminWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        doubleSpinBox_itemPrice = new QDoubleSpinBox(AdminWidget);
        doubleSpinBox_itemPrice->setObjectName(QString::fromUtf8("doubleSpinBox_itemPrice"));

        formLayout->setWidget(1, QFormLayout::FieldRole, doubleSpinBox_itemPrice);


        verticalLayout->addLayout(formLayout);

        verticalSpacer_2 = new QSpacerItem(20, 30, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer_2);

        addItemButton = new QPushButton(AdminWidget);
        addItemButton->setObjectName(QString::fromUtf8("addItemButton"));

        verticalLayout->addWidget(addItemButton);

        pushButton_delete = new QPushButton(AdminWidget);
        pushButton_delete->setObjectName(QString::fromUtf8("pushButton_delete"));

        verticalLayout->addWidget(pushButton_delete);

        saveButton = new QPushButton(AdminWidget);
        saveButton->setObjectName(QString::fromUtf8("saveButton"));

        verticalLayout->addWidget(saveButton);

        exitButton = new QPushButton(AdminWidget);
        exitButton->setObjectName(QString::fromUtf8("exitButton"));

        verticalLayout->addWidget(exitButton);


        horizontalLayout->addLayout(verticalLayout);

        tableWidget = new QTableWidget(AdminWidget);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setFrameShape(QFrame::NoFrame);
        tableWidget->setFrameShadow(QFrame::Plain);
        tableWidget->setLineWidth(0);
        tableWidget->setEditTriggers(QAbstractItemView::CurrentChanged|QAbstractItemView::DoubleClicked|QAbstractItemView::SelectedClicked);
        tableWidget->setTabKeyNavigation(false);
        tableWidget->setProperty("showDropIndicator", QVariant(false));
        tableWidget->setDragDropOverwriteMode(false);
        tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
        tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableWidget->setShowGrid(false);
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
        pushButton_delete->setText(QCoreApplication::translate("AdminWidget", "Delete", nullptr));
        saveButton->setText(QCoreApplication::translate("AdminWidget", "Save", nullptr));
        exitButton->setText(QCoreApplication::translate("AdminWidget", "Exit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AdminWidget: public Ui_AdminWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINWIDGET_H
