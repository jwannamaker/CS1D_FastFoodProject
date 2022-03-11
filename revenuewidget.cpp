#include "revenuewidget.h"
#include "ui_revenuewidget.h"

RevenueWidget::RevenueWidget(std::vector<Restaurant> list,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RevenueWidget)
{
    ui->setupUi(this);
    double total;
    ui->tableWidget->setColumnCount(2);
    ui->tableWidget->setRowCount(list.size());

    total = 0;

    for(unsigned int index = 0; index < list.size(); index++)
    {
        QTableWidgetItem* restaurantName = new QTableWidgetItem(list[index].getName());
        ui->tableWidget->setItem(index,0,restaurantName);
        QTableWidgetItem* restaurantRevenue = new QTableWidgetItem("$" + QString::number(list[index].getRevenue(),'f',2));
        ui->tableWidget->setItem(index,1,restaurantRevenue);

        total += list[index].getRevenue();
    }
    ui->totalRevenueLineEdit->setText("$" + QString::number(total,'f',2));
}

RevenueWidget::~RevenueWidget()
{
    delete ui;
}

void RevenueWidget::on_exitButton_clicked()
{
    emit transmit_exitRevenue();
}

