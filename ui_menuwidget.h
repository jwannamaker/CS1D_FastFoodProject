/********************************************************************************
** Form generated from reading UI file 'menuwidget.ui'
**
** Created by: Qt User Interface Compiler version 6.2.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MENUWIDGET_H
#define UI_MENUWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MenuWidget
{
public:
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QTableWidget *tableWidget_orderItems;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *totalLineEdit;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer;
    QPushButton *editButton;
    QPushButton *confirmButton;
    QPushButton *cancelButton;
    QScrollArea *scrollArea_menu;
    QWidget *scrollAreaWidgetContents;

    void setupUi(QWidget *MenuWidget)
    {
        if (MenuWidget->objectName().isEmpty())
            MenuWidget->setObjectName(QString::fromUtf8("MenuWidget"));
        MenuWidget->resize(830, 496);
        gridLayout_2 = new QGridLayout(MenuWidget);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label_2 = new QLabel(MenuWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout_2->addWidget(label_2);

        tableWidget_orderItems = new QTableWidget(MenuWidget);
        tableWidget_orderItems->setObjectName(QString::fromUtf8("tableWidget_orderItems"));
        tableWidget_orderItems->setFrameShape(QFrame::NoFrame);
        tableWidget_orderItems->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableWidget_orderItems->setSelectionMode(QAbstractItemView::NoSelection);
        tableWidget_orderItems->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableWidget_orderItems->verticalHeader()->setVisible(false);

        verticalLayout_2->addWidget(tableWidget_orderItems);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(MenuWidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        totalLineEdit = new QLineEdit(MenuWidget);
        totalLineEdit->setObjectName(QString::fromUtf8("totalLineEdit"));
        totalLineEdit->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        totalLineEdit->setReadOnly(true);

        horizontalLayout->addWidget(totalLineEdit);


        verticalLayout_2->addLayout(horizontalLayout);


        verticalLayout_3->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalSpacer = new QSpacerItem(247, 40, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer);

        editButton = new QPushButton(MenuWidget);
        editButton->setObjectName(QString::fromUtf8("editButton"));

        verticalLayout->addWidget(editButton);

        confirmButton = new QPushButton(MenuWidget);
        confirmButton->setObjectName(QString::fromUtf8("confirmButton"));

        verticalLayout->addWidget(confirmButton);

        cancelButton = new QPushButton(MenuWidget);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));

        verticalLayout->addWidget(cancelButton);


        verticalLayout_3->addLayout(verticalLayout);


        gridLayout_2->addLayout(verticalLayout_3, 0, 0, 1, 1);

        scrollArea_menu = new QScrollArea(MenuWidget);
        scrollArea_menu->setObjectName(QString::fromUtf8("scrollArea_menu"));
        scrollArea_menu->setMinimumSize(QSize(550, 0));
        scrollArea_menu->setFrameShape(QFrame::NoFrame);
        scrollArea_menu->setFrameShadow(QFrame::Plain);
        scrollArea_menu->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        scrollArea_menu->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        scrollArea_menu->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        scrollArea_menu->setWidgetResizable(true);
        scrollArea_menu->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 550, 482));
        scrollArea_menu->setWidget(scrollAreaWidgetContents);

        gridLayout_2->addWidget(scrollArea_menu, 0, 1, 1, 1);


        retranslateUi(MenuWidget);

        QMetaObject::connectSlotsByName(MenuWidget);
    } // setupUi

    void retranslateUi(QWidget *MenuWidget)
    {
        MenuWidget->setWindowTitle(QCoreApplication::translate("MenuWidget", "Form", nullptr));
        label_2->setText(QCoreApplication::translate("MenuWidget", "Order Summary", nullptr));
        label->setText(QCoreApplication::translate("MenuWidget", "Total", nullptr));
        editButton->setText(QCoreApplication::translate("MenuWidget", "Edit Menu", nullptr));
        confirmButton->setText(QCoreApplication::translate("MenuWidget", "Confirm Order", nullptr));
        cancelButton->setText(QCoreApplication::translate("MenuWidget", "Cancel Order", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MenuWidget: public Ui_MenuWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MENUWIDGET_H
