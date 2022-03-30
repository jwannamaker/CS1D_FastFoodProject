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
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RevenueWidget
{
public:
    QGridLayout *gridLayout;
    QTableWidget *tableWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *exitButton;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLineEdit *totalRevenueLineEdit;
    QTableWidget *detailedTable;

    void setupUi(QWidget *RevenueWidget)
    {
        if (RevenueWidget->objectName().isEmpty())
            RevenueWidget->setObjectName(QString::fromUtf8("RevenueWidget"));
        RevenueWidget->resize(787, 552);
        gridLayout = new QGridLayout(RevenueWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        tableWidget = new QTableWidget(RevenueWidget);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tableWidget->sizePolicy().hasHeightForWidth());
        tableWidget->setSizePolicy(sizePolicy);
        tableWidget->setFrameShape(QFrame::NoFrame);
        tableWidget->setFrameShadow(QFrame::Plain);
        tableWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableWidget->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        tableWidget->setAutoScroll(false);
        tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableWidget->setProperty("showDropIndicator", QVariant(false));
        tableWidget->setDragDropOverwriteMode(false);
        tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
        tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableWidget->setShowGrid(false);
        tableWidget->setGridStyle(Qt::SolidLine);
        tableWidget->setCornerButtonEnabled(false);
        tableWidget->setColumnCount(0);
        tableWidget->horizontalHeader()->setVisible(true);
        tableWidget->horizontalHeader()->setDefaultSectionSize(300);
        tableWidget->horizontalHeader()->setStretchLastSection(true);
        tableWidget->verticalHeader()->setVisible(false);
        tableWidget->verticalHeader()->setDefaultSectionSize(37);
        tableWidget->verticalHeader()->setHighlightSections(true);

        gridLayout->addWidget(tableWidget, 0, 0, 1, 1);

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

        detailedTable = new QTableWidget(RevenueWidget);
        detailedTable->setObjectName(QString::fromUtf8("detailedTable"));
        detailedTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
        detailedTable->setProperty("showDropIndicator", QVariant(false));
        detailedTable->setDragDropOverwriteMode(false);
        detailedTable->setSelectionMode(QAbstractItemView::NoSelection);
        detailedTable->setSelectionBehavior(QAbstractItemView::SelectRows);
        detailedTable->setShowGrid(false);
        detailedTable->setGridStyle(Qt::NoPen);
        detailedTable->verticalHeader()->setVisible(false);

        gridLayout->addWidget(detailedTable, 0, 1, 1, 1);


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
