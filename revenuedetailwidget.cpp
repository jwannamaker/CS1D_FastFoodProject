#include "revenuedetailwidget.h"
#include "ui_revenuedetailwidget.h"

///
/// \brief RevenueDetailWidget::RevenueDetailWidget
/// \param parent
///
RevenueDetailWidget::RevenueDetailWidget(Restaurant& currentRestaurant, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RevenueDetailWidget)
{
    ui->setupUi(this);
    ui->tableWidget->setHorizontalHeaderItem(0, new QTableWidgetItem("Item"));
    ui->tableWidget->setHorizontalHeaderItem(0, new QTableWidgetItem("Unit Price"));
    ui->tableWidget->setHorizontalHeaderItem(0, new QTableWidgetItem("Quantity Ordered"));
    ui->tableWidget->setHorizontalHeaderItem(0, new QTableWidgetItem("Customer"));
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    this->currentRestaurant = currentRestaurant;
    populateTable();
}

///
/// \brief RevenueDetailWidget::~RevenueDetailWidget
///
RevenueDetailWidget::~RevenueDetailWidget()
{
    delete ui;
}

///
/// \brief RevenueDetailWidget::setRevenueLabel
/// \param revenueString
///
void RevenueDetailWidget::setRevenueLabel(const QString &revenueString)
{
    ui->lineEdit_total->setText(revenueString);
}

///
/// \brief RevenueDetailWidget::populateTable
///
void RevenueDetailWidget::populateTable()
{
    ui->tableWidget->setRowCount(currentRestaurant.getMenuSize());

    for (size_t i = 0; i < currentRestaurant.getMenuSize(); i++)
    {
        QTa
    }
}

///
/// \brief RevenueDetailWidget::on_exitButton_clicked
///
void RevenueDetailWidget::on_exitButton_clicked()
{
    emit transmit_exit();
}

