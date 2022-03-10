/********************************************************************************
** Form generated from reading UI file 'menuwidget.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MENUWIDGET_H
#define UI_MENUWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
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
    QListView *listView;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *subtotalLineEdit;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer;
    QPushButton *confirmButton;
    QPushButton *editButton;
    QPushButton *cancelButton;
    QWidget *viewWidget;

    void setupUi(QWidget *MenuWidget)
    {
        if (MenuWidget->objectName().isEmpty())
            MenuWidget->setObjectName(QString::fromUtf8("MenuWidget"));
        MenuWidget->resize(751, 496);
        gridLayout_2 = new QGridLayout(MenuWidget);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label_2 = new QLabel(MenuWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout_2->addWidget(label_2);

        listView = new QListView(MenuWidget);
        listView->setObjectName(QString::fromUtf8("listView"));

        verticalLayout_2->addWidget(listView);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(MenuWidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        subtotalLineEdit = new QLineEdit(MenuWidget);
        subtotalLineEdit->setObjectName(QString::fromUtf8("subtotalLineEdit"));
        subtotalLineEdit->setReadOnly(true);

        horizontalLayout->addWidget(subtotalLineEdit);


        verticalLayout_2->addLayout(horizontalLayout);


        verticalLayout_3->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer);

        confirmButton = new QPushButton(MenuWidget);
        confirmButton->setObjectName(QString::fromUtf8("confirmButton"));

        verticalLayout->addWidget(confirmButton);

        editButton = new QPushButton(MenuWidget);
        editButton->setObjectName(QString::fromUtf8("editButton"));

        verticalLayout->addWidget(editButton);

        cancelButton = new QPushButton(MenuWidget);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));

        verticalLayout->addWidget(cancelButton);


        verticalLayout_3->addLayout(verticalLayout);


        gridLayout_2->addLayout(verticalLayout_3, 0, 0, 1, 1);

        viewWidget = new QWidget(MenuWidget);
        viewWidget->setObjectName(QString::fromUtf8("viewWidget"));
        viewWidget->setMinimumSize(QSize(550, 0));

        gridLayout_2->addWidget(viewWidget, 0, 1, 1, 1);


        retranslateUi(MenuWidget);

        QMetaObject::connectSlotsByName(MenuWidget);
    } // setupUi

    void retranslateUi(QWidget *MenuWidget)
    {
        MenuWidget->setWindowTitle(QCoreApplication::translate("MenuWidget", "Form", nullptr));
        label_2->setText(QCoreApplication::translate("MenuWidget", "Order Summary", nullptr));
        label->setText(QCoreApplication::translate("MenuWidget", "Subtotal", nullptr));
        confirmButton->setText(QCoreApplication::translate("MenuWidget", "Confirm Order", nullptr));
        editButton->setText(QCoreApplication::translate("MenuWidget", "Edit Order", nullptr));
        cancelButton->setText(QCoreApplication::translate("MenuWidget", "Cancel Order", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MenuWidget: public Ui_MenuWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MENUWIDGET_H
