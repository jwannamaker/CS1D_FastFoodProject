/********************************************************************************
** Form generated from reading UI file 'restaurantwidget.ui'
**
** Created by: Qt User Interface Compiler version 6.2.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RESTAURANTWIDGET_H
#define UI_RESTAURANTWIDGET_H

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

class Ui_RestaurantWidget
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QListView *listView;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLineEdit *initialLocationLineEdit;
    QSpacerItem *verticalSpacer;
    QPushButton *confirmButton;
    QPushButton *cancelButton;
    QWidget *RestaurantViewWidget;

    void setupUi(QWidget *RestaurantWidget)
    {
        if (RestaurantWidget->objectName().isEmpty())
            RestaurantWidget->setObjectName(QString::fromUtf8("RestaurantWidget"));
        RestaurantWidget->resize(639, 479);
        gridLayout = new QGridLayout(RestaurantWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(RestaurantWidget);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        listView = new QListView(RestaurantWidget);
        listView->setObjectName(QString::fromUtf8("listView"));
        listView->setEditTriggers(QAbstractItemView::NoEditTriggers);

        verticalLayout->addWidget(listView);


        verticalLayout_2->addLayout(verticalLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_2 = new QLabel(RestaurantWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        initialLocationLineEdit = new QLineEdit(RestaurantWidget);
        initialLocationLineEdit->setObjectName(QString::fromUtf8("initialLocationLineEdit"));
        initialLocationLineEdit->setReadOnly(true);

        horizontalLayout->addWidget(initialLocationLineEdit);


        verticalLayout_2->addLayout(horizontalLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_2->addItem(verticalSpacer);

        confirmButton = new QPushButton(RestaurantWidget);
        confirmButton->setObjectName(QString::fromUtf8("confirmButton"));

        verticalLayout_2->addWidget(confirmButton);

        cancelButton = new QPushButton(RestaurantWidget);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));

        verticalLayout_2->addWidget(cancelButton);


        gridLayout->addLayout(verticalLayout_2, 0, 0, 2, 2);

        RestaurantViewWidget = new QWidget(RestaurantWidget);
        RestaurantViewWidget->setObjectName(QString::fromUtf8("RestaurantViewWidget"));
        RestaurantViewWidget->setMinimumSize(QSize(550, 0));

        gridLayout->addWidget(RestaurantViewWidget, 0, 2, 2, 1);


        retranslateUi(RestaurantWidget);

        QMetaObject::connectSlotsByName(RestaurantWidget);
    } // setupUi

    void retranslateUi(QWidget *RestaurantWidget)
    {
        RestaurantWidget->setWindowTitle(QCoreApplication::translate("RestaurantWidget", "Form", nullptr));
        label->setText(QCoreApplication::translate("RestaurantWidget", "Visited Restaurants", nullptr));
        label_2->setText(QCoreApplication::translate("RestaurantWidget", "Starting From", nullptr));
        confirmButton->setText(QCoreApplication::translate("RestaurantWidget", "Confirm Trip", nullptr));
        cancelButton->setText(QCoreApplication::translate("RestaurantWidget", "Cancel Trip", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RestaurantWidget: public Ui_RestaurantWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RESTAURANTWIDGET_H
