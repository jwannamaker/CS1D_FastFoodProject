#include "revenuewidget.h"
#include "ui_revenuewidget.h"

<<<<<<< Updated upstream
RevenueWidget::RevenueWidget(QWidget *parent) :
=======
RevenueWidget::RevenueWidget(std::vector<Restaurant> list, QWidget *parent) :
>>>>>>> Stashed changes
    QWidget(parent),
    ui(new Ui::RevenueWidget)
{
    ui->setupUi(this);
<<<<<<< Updated upstream


=======
    ui->tableWidget->setColumnCount(2);
    ui->tableWidget->setRowCount(list.size());

    for(unsigned int index = 0; index < list.size(); index++)
    {
        QTableWidgetItem* restaurantName = new QTableWidgetItem(list[index].getName());
        ui->tableWidget->setItem(index, 0, restaurantName);
        QTableWidgetItem* restaurantRevenue = new QTableWidgetItem("$" + QString::number(list[index].getRevenue(),'f',2));
        ui->tableWidget->setItem(index, 1, restaurantRevenue);
        ui->tableWidget->item(index, 1)->setTextAlignment(Qt::AlignRight);
    }
    ui->totalRevenueLineEdit->setText("$" + QString::number(getTotalRevenue(), 'f', 2));
>>>>>>> Stashed changes
}

RevenueWidget::~RevenueWidget()
{
    delete ui;
}

<<<<<<< Updated upstream
void RevenueWidget::on_BacktoMain_pressed()
=======
double RevenueWidget::getTotalRevenue()
{
    double total = 0;
    for (Restaurant rest : Restaurant::list)
    {
        total += rest.getRevenue();
    }
    return total;
}

void RevenueWidget::on_exitButton_clicked()
>>>>>>> Stashed changes
{
    emit transmit_cancel();
}

