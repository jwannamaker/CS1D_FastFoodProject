#include "revenuewidget.h"
#include "ui_revenuewidget.h"

///
/// \brief RevenueWidget::RevenueWidget
/// \param parent
///
RevenueWidget::RevenueWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RevenueWidget)
{
    ui->setupUi(this);
    ui->tableWidget->setColumnCount(2);
    ui->tableWidget->setHorizontalHeaderItem(0, new QTableWidgetItem("Restaurant"));
    ui->tableWidget->setHorizontalHeaderItem(1, new QTableWidgetItem("Revenue"));
    populateTable();
    populateTotalRevenue();
}

///
/// \brief RevenueWidget::~RevenueWidget
///
RevenueWidget::~RevenueWidget()
{
    delete ui;
}

///
/// \brief RevenueWidget::populateTable
///
void RevenueWidget::populateTable()
{
    ui->tableWidget->setRowCount(RestaurantList.size());

    // initializing contents of the table
    for(unsigned int index = 0; index < RestaurantList.size(); index++)
    {
        QTableWidgetItem* restaurantName = new QTableWidgetItem(RestaurantList[index].getName());
        ui->tableWidget->setItem(index, 0, restaurantName);
        QTableWidgetItem* restaurantRevenue = new QTableWidgetItem("$" + QString::number(RestaurantList[index].getRevenue(),'f',2));
        ui->tableWidget->setItem(index, 1, restaurantRevenue);
        ui->tableWidget->item(index, 1)->setTextAlignment(Qt::AlignRight);
    }
}

///
/// \brief RevenueWidget::populateTotalRevenue
///
void RevenueWidget::populateTotalRevenue()
{
    double total = 0;
    for (Restaurant rest : RestaurantList)
        total += rest.getRevenue();
    ui->totalRevenueLineEdit->setText("$" + QString::number(total, 'f', 2));
}

///
/// \brief RevenueWidget::on_exitButton_pressed
///
void RevenueWidget::on_exitButton_pressed()
{
    emit transmit_cancel();
}

