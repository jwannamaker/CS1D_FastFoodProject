#include "revenuewidget.h"
#include "ui_revenuewidget.h"

RevenueWidget::RevenueWidget(const std::vector<Restaurant>& list, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RevenueWidget)
{
    ui->setupUi(this);
    ui->tableWidget->setColumnCount(2);
    ui->tableWidget->setRowCount(list.size());
    ui->tableWidget->setHorizontalHeaderItem(0, new QTableWidgetItem("Restaurant Name"));
    ui->tableWidget->setHorizontalHeaderItem(1, new QTableWidgetItem("Revenue"));


    // initializing contents of the table
    for(unsigned int index = 0; index < list.size(); index++)
    {
        QTableWidgetItem* restaurantName = new QTableWidgetItem(list[index].getName());
        ui->tableWidget->setItem(index, 0, restaurantName);
        QTableWidgetItem* restaurantRevenue = new QTableWidgetItem("$" + QString::number(list[index].getRevenue(),'f',2));
        ui->tableWidget->setItem(index, 1, restaurantRevenue);
        ui->tableWidget->item(index, 1)->setTextAlignment(Qt::AlignRight);
    }

    // generating the value for total revenue
    ui->totalRevenueLineEdit->setText("$" + QString::number(getTotalRevenue(), 'f', 2));
}

RevenueWidget::~RevenueWidget()
{
    delete ui;
}

double RevenueWidget::getTotalRevenue()
{
    double total = 0;
    for (Restaurant rest : Restaurant::list)
    {
        total += rest.getRevenue();
    }
    return total;
}

void RevenueWidget::on_exitButton_pressed()
{
    emit transmit_cancel();
}

