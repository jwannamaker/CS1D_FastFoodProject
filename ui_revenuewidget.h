/********************************************************************************
** Form generated from reading UI file 'revenuewidget.ui'
**
** Created by: Qt User Interface Compiler version 6.2.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REVENUEWIDGET_H
#define UI_REVENUEWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RevenueWidget
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *exitButton;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLineEdit *totalRevenueLineEdit;
    QTreeWidget *treeWidget;

    void setupUi(QWidget *RevenueWidget)
    {
        if (RevenueWidget->objectName().isEmpty())
            RevenueWidget->setObjectName(QString::fromUtf8("RevenueWidget"));
        RevenueWidget->resize(787, 552);
        gridLayout = new QGridLayout(RevenueWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        exitButton = new QPushButton(RevenueWidget);
        exitButton->setObjectName(QString::fromUtf8("exitButton"));

        horizontalLayout->addWidget(exitButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label = new QLabel(RevenueWidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_2->addWidget(label);

        totalRevenueLineEdit = new QLineEdit(RevenueWidget);
        totalRevenueLineEdit->setObjectName(QString::fromUtf8("totalRevenueLineEdit"));
        totalRevenueLineEdit->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        totalRevenueLineEdit->setReadOnly(true);

        horizontalLayout_2->addWidget(totalRevenueLineEdit);


        horizontalLayout->addLayout(horizontalLayout_2);


        gridLayout->addLayout(horizontalLayout, 1, 0, 1, 1);

        treeWidget = new QTreeWidget(RevenueWidget);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QString::fromUtf8("1"));
        treeWidget->setHeaderItem(__qtreewidgetitem);
        treeWidget->setObjectName(QString::fromUtf8("treeWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(treeWidget->sizePolicy().hasHeightForWidth());
        treeWidget->setSizePolicy(sizePolicy);
        treeWidget->setFrameShape(QFrame::NoFrame);
        treeWidget->setFrameShadow(QFrame::Plain);
        treeWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        treeWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        treeWidget->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        treeWidget->setAutoScroll(false);
        treeWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        treeWidget->setProperty("showDropIndicator", QVariant(false));
        treeWidget->setDragDropOverwriteMode(false);
        treeWidget->setSelectionMode(QAbstractItemView::SingleSelection);
        treeWidget->setSelectionBehavior(QAbstractItemView::SelectRows);

        gridLayout->addWidget(treeWidget, 0, 0, 1, 1);


        retranslateUi(RevenueWidget);

        QMetaObject::connectSlotsByName(RevenueWidget);
    } // setupUi

    void retranslateUi(QWidget *RevenueWidget)
    {
        RevenueWidget->setWindowTitle(QCoreApplication::translate("RevenueWidget", "Form", nullptr));
        exitButton->setText(QCoreApplication::translate("RevenueWidget", "Exit", nullptr));
        label->setText(QCoreApplication::translate("RevenueWidget", "Total Revenue", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RevenueWidget: public Ui_RevenueWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REVENUEWIDGET_H
