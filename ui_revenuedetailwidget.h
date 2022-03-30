/********************************************************************************
** Form generated from reading UI file 'revenuedetailwidget.ui'
**
** Created by: Qt User Interface Compiler version 6.2.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REVENUEDETAILWIDGET_H
#define UI_REVENUEDETAILWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RevenueDetailWidget
{
public:
    QGridLayout *gridLayout;
    QTableWidget *tableWidget;
    QPushButton *exitButton;
    QLabel *label;
    QLineEdit *lineEdit_total;
    QSpacerItem *horizontalSpacer;

    void setupUi(QWidget *RevenueDetailWidget)
    {
        if (RevenueDetailWidget->objectName().isEmpty())
            RevenueDetailWidget->setObjectName(QString::fromUtf8("RevenueDetailWidget"));
        RevenueDetailWidget->resize(752, 471);
        gridLayout = new QGridLayout(RevenueDetailWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        tableWidget = new QTableWidget(RevenueDetailWidget);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setFrameShape(QFrame::NoFrame);
        tableWidget->setFrameShadow(QFrame::Plain);
        tableWidget->setLineWidth(0);
        tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableWidget->setGridStyle(Qt::NoPen);
        tableWidget->setCornerButtonEnabled(false);
        tableWidget->verticalHeader()->setVisible(false);
        tableWidget->verticalHeader()->setHighlightSections(false);

        gridLayout->addWidget(tableWidget, 0, 0, 1, 4);

        exitButton = new QPushButton(RevenueDetailWidget);
        exitButton->setObjectName(QString::fromUtf8("exitButton"));

        gridLayout->addWidget(exitButton, 1, 0, 1, 1);

        label = new QLabel(RevenueDetailWidget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 1, 2, 1, 1);

        lineEdit_total = new QLineEdit(RevenueDetailWidget);
        lineEdit_total->setObjectName(QString::fromUtf8("lineEdit_total"));
        lineEdit_total->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEdit_total->setReadOnly(true);

        gridLayout->addWidget(lineEdit_total, 1, 3, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 1, 1, 1);


        retranslateUi(RevenueDetailWidget);

        QMetaObject::connectSlotsByName(RevenueDetailWidget);
    } // setupUi

    void retranslateUi(QWidget *RevenueDetailWidget)
    {
        RevenueDetailWidget->setWindowTitle(QCoreApplication::translate("RevenueDetailWidget", "Form", nullptr));
        exitButton->setText(QCoreApplication::translate("RevenueDetailWidget", "Exit", nullptr));
        label->setText(QCoreApplication::translate("RevenueDetailWidget", "Total", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RevenueDetailWidget: public Ui_RevenueDetailWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REVENUEDETAILWIDGET_H
