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
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
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
    // initializing contents of the tree
    for(unsigned int index = 0; index < RestaurantList.size(); index++)
    {
        ui->tableWidget->setItem(index, 0, new QTableWidgetItem(RestaurantList[index].getName()));
        ui->tableWidget->setItem(index, 1, new QTableWidgetItem("$" + QString::number(RestaurantList[index].getRevenue(), 'f', 2)));
        ui->tableWidget->item(index, 1)->setTextAlignment(Qt::AlignRight);
    }
}

///
/// \brief RevenueWidget::createDetailWidget
/// \return
///
void RevenueWidget::populateDetailedTable(Restaurant currentRestaurant)
{
    qDebug() << "detailed revenue for " << currentRestaurant.getName();
    ui->detailedTable->setColumnCount(5);
    ui->detailedTable->setHorizontalHeaderItem(0, new QTableWidgetItem("Customer"));
    ui->detailedTable->setHorizontalHeaderItem(1, new QTableWidgetItem("Item"));
    ui->detailedTable->setHorizontalHeaderItem(2, new QTableWidgetItem("Price"));
    ui->detailedTable->setHorizontalHeaderItem(3, new QTableWidgetItem("Quantity"));
    ui->detailedTable->setHorizontalHeaderItem(4, new QTableWidgetItem("Subtotal"));

    ui->detailedTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->detailedTable->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->detailedTable->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    OrderList orders = currentRestaurant.getOrderList();
    for (size_t i = 0; i < orders.size(); i++)
    {
        ui->detailedTable->insertRow(i);
        for (size_t j = 0; j < orders[i].second.size(); j++)
        {
            qDebug() << "adding order to detailed table";
            ui->detailedTable->setItem(i, 0, new QTableWidgetItem(orders[i].first.getUsername()));
            ui->detailedTable->setItem(i, 1, new QTableWidgetItem(orders[i].second[j].getName()));
            ui->detailedTable->setItem(i, 2, new QTableWidgetItem("$" + QString::number(orders[i].second[j].getPrice(), 'f', 2)));
            ui->detailedTable->item(i, 2)->setTextAlignment(Qt::AlignRight);
            ui->detailedTable->setItem(i, 3, new QTableWidgetItem(QString::number(orders[i].second[j].getQuantity())));
            ui->detailedTable->item(i, 3)->setTextAlignment(Qt::AlignRight);
            ui->detailedTable->setItem(i, 4, new QTableWidgetItem("$" + QString::number(orders[i].second[j].getPrice() * orders[i].second[j].getQuantity(), 'f', 2)));
            ui->detailedTable->item(i, 4)->setTextAlignment(Qt::AlignRight);
        }
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
    emit transmit_exit();
}

///
/// \brief RevenueWidget::on_tableWidget_itemSelectionChanged
///
void RevenueWidget::on_tableWidget_itemSelectionChanged()
{
    QModelIndex index = ui->tableWidget->currentIndex();
    ui->detailedTable->clear();
    populateDetailedTable(RestaurantList[index.row()]);
}

