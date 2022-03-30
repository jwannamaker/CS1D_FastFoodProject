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
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
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
    QFrame *frame;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *lineEdit_itemName;
    QLabel *label_2;
    QDoubleSpinBox *doubleSpinBox_itemPrice;
    QSpacerItem *verticalSpacer_3;
    QPushButton *addButton;
    QPushButton *saveButton;
    QPushButton *deleteButton;
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
        comboBox_restaurant->setFrame(false);

        verticalLayout->addWidget(comboBox_restaurant);

        frame = new QFrame(AdminWidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        formLayout = new QFormLayout(frame);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label = new QLabel(frame);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        lineEdit_itemName = new QLineEdit(frame);
        lineEdit_itemName->setObjectName(QString::fromUtf8("lineEdit_itemName"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lineEdit_itemName->sizePolicy().hasHeightForWidth());
        lineEdit_itemName->setSizePolicy(sizePolicy1);

        formLayout->setWidget(0, QFormLayout::FieldRole, lineEdit_itemName);

        label_2 = new QLabel(frame);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        doubleSpinBox_itemPrice = new QDoubleSpinBox(frame);
        doubleSpinBox_itemPrice->setObjectName(QString::fromUtf8("doubleSpinBox_itemPrice"));

        formLayout->setWidget(1, QFormLayout::FieldRole, doubleSpinBox_itemPrice);


        verticalLayout->addWidget(frame);

        verticalSpacer_3 = new QSpacerItem(20, 30, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_3);

        addButton = new QPushButton(AdminWidget);
        addButton->setObjectName(QString::fromUtf8("addButton"));

        verticalLayout->addWidget(addButton);

        saveButton = new QPushButton(AdminWidget);
        saveButton->setObjectName(QString::fromUtf8("saveButton"));
        saveButton->setFlat(false);

        verticalLayout->addWidget(saveButton);

        deleteButton = new QPushButton(AdminWidget);
        deleteButton->setObjectName(QString::fromUtf8("deleteButton"));

        verticalLayout->addWidget(deleteButton);

        exitButton = new QPushButton(AdminWidget);
        exitButton->setObjectName(QString::fromUtf8("exitButton"));

        verticalLayout->addWidget(exitButton);


        horizontalLayout->addLayout(verticalLayout);

        tableWidget = new QTableWidget(AdminWidget);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setFrameShape(QFrame::NoFrame);
        tableWidget->setFrameShadow(QFrame::Plain);
        tableWidget->setLineWidth(0);
        tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
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
        comboBox_restaurant->setCurrentText(QString());
        comboBox_restaurant->setPlaceholderText(QString());
        label->setText(QCoreApplication::translate("AdminWidget", "Name", nullptr));
        label_2->setText(QCoreApplication::translate("AdminWidget", "Price", nullptr));
        addButton->setText(QCoreApplication::translate("AdminWidget", "Add", nullptr));
        saveButton->setText(QCoreApplication::translate("AdminWidget", "Save", nullptr));
        deleteButton->setText(QCoreApplication::translate("AdminWidget", "Delete", nullptr));
        exitButton->setText(QCoreApplication::translate("AdminWidget", "Exit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AdminWidget: public Ui_AdminWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINWIDGET_H
