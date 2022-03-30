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
#include <QtWidgets/QComboBox>
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

class Ui_RestaurantWidget
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QComboBox *comboBox_initialLocation;
    QTableWidget *tableWidget_tripRestaurants;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QLineEdit *totalDistanceLineEdit;
    QSpacerItem *verticalSpacer;
    QPushButton *confirmButton;
    QPushButton *cancelButton;
    QScrollArea *scrollArea_restaurants;
    QWidget *scrollArea;

    void setupUi(QWidget *RestaurantWidget)
    {
        if (RestaurantWidget->objectName().isEmpty())
            RestaurantWidget->setObjectName(QString::fromUtf8("RestaurantWidget"));
        RestaurantWidget->resize(873, 479);
        gridLayout = new QGridLayout(RestaurantWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(5);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_2 = new QLabel(RestaurantWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);
        label_2->setMinimumSize(QSize(80, 0));

        horizontalLayout->addWidget(label_2);

        comboBox_initialLocation = new QComboBox(RestaurantWidget);
        comboBox_initialLocation->setObjectName(QString::fromUtf8("comboBox_initialLocation"));

        horizontalLayout->addWidget(comboBox_initialLocation);


        verticalLayout->addLayout(horizontalLayout);

        tableWidget_tripRestaurants = new QTableWidget(RestaurantWidget);
        tableWidget_tripRestaurants->setObjectName(QString::fromUtf8("tableWidget_tripRestaurants"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(tableWidget_tripRestaurants->sizePolicy().hasHeightForWidth());
        tableWidget_tripRestaurants->setSizePolicy(sizePolicy1);
        tableWidget_tripRestaurants->setMinimumSize(QSize(250, 0));
        tableWidget_tripRestaurants->setFrameShape(QFrame::NoFrame);
        tableWidget_tripRestaurants->setFrameShadow(QFrame::Plain);
        tableWidget_tripRestaurants->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableWidget_tripRestaurants->setProperty("showDropIndicator", QVariant(false));
        tableWidget_tripRestaurants->setDefaultDropAction(Qt::IgnoreAction);
        tableWidget_tripRestaurants->horizontalHeader()->setHighlightSections(false);
        tableWidget_tripRestaurants->horizontalHeader()->setStretchLastSection(true);
        tableWidget_tripRestaurants->verticalHeader()->setVisible(false);

        verticalLayout->addWidget(tableWidget_tripRestaurants);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_3 = new QLabel(RestaurantWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMinimumSize(QSize(80, 0));

        horizontalLayout_2->addWidget(label_3);

        totalDistanceLineEdit = new QLineEdit(RestaurantWidget);
        totalDistanceLineEdit->setObjectName(QString::fromUtf8("totalDistanceLineEdit"));
        totalDistanceLineEdit->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        totalDistanceLineEdit->setReadOnly(true);

        horizontalLayout_2->addWidget(totalDistanceLineEdit);


        verticalLayout->addLayout(horizontalLayout_2);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer);

        confirmButton = new QPushButton(RestaurantWidget);
        confirmButton->setObjectName(QString::fromUtf8("confirmButton"));

        verticalLayout->addWidget(confirmButton);

        cancelButton = new QPushButton(RestaurantWidget);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));

        verticalLayout->addWidget(cancelButton);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);

        scrollArea_restaurants = new QScrollArea(RestaurantWidget);
        scrollArea_restaurants->setObjectName(QString::fromUtf8("scrollArea_restaurants"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(scrollArea_restaurants->sizePolicy().hasHeightForWidth());
        scrollArea_restaurants->setSizePolicy(sizePolicy2);
        scrollArea_restaurants->setMinimumSize(QSize(600, 0));
        scrollArea_restaurants->setMaximumSize(QSize(600, 16777215));
        scrollArea_restaurants->setFrameShape(QFrame::NoFrame);
        scrollArea_restaurants->setFrameShadow(QFrame::Plain);
        scrollArea_restaurants->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        scrollArea_restaurants->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        scrollArea_restaurants->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        scrollArea_restaurants->setWidgetResizable(true);
        scrollArea = new QWidget();
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setGeometry(QRect(0, 0, 600, 465));
        scrollArea_restaurants->setWidget(scrollArea);

        gridLayout->addWidget(scrollArea_restaurants, 0, 1, 1, 1);


        retranslateUi(RestaurantWidget);

        QMetaObject::connectSlotsByName(RestaurantWidget);
    } // setupUi

    void retranslateUi(QWidget *RestaurantWidget)
    {
        RestaurantWidget->setWindowTitle(QCoreApplication::translate("RestaurantWidget", "Form", nullptr));
        label_2->setText(QCoreApplication::translate("RestaurantWidget", "Initial Location", nullptr));
        label_3->setText(QCoreApplication::translate("RestaurantWidget", "Total Distance ", nullptr));
        confirmButton->setText(QCoreApplication::translate("RestaurantWidget", "Confirm Trip", nullptr));
        cancelButton->setText(QCoreApplication::translate("RestaurantWidget", "Cancel Trip", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RestaurantWidget: public Ui_RestaurantWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RESTAURANTWIDGET_H
