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
    ui->treeWidget->setHeaderHidden(true);
    ui->tableWidget->setColumnCount(2);
    populateTree();
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
void RevenueWidget::populateTree()
{
    // initializing contents of the tree
    for(unsigned int index = 0; index < RestaurantList.size(); index++)
    {
        QTreeWidgetItem* level = new QTreeWidgetItem();
        QTreeWidgetItem* child = new QTreeWidgetItem();
        QWidget* table = createDetailWidget(RestaurantList[index]);

        level->setText(0, RestaurantList[index].getName());
        level->setText(1, "$" + QString::number(RestaurantList[index].getRevenue(), 'f', 2));

        level->addChild(child);

        if (RestaurantList[index].getRevenue() <= 0)
            ui->treeWidget->setItemWidget(child, 0, table);
        ui->treeWidget->addTopLevelItem(level);
    }
}

///
/// \brief RevenueWidget::createDetailWidget
/// \return
///
QTableWidget *RevenueWidget::createDetailWidget(Restaurant &currentRestaurant)
{
    QTableWidget* table = new QTableWidget();
    table->setColumnCount(5);
    table->setHorizontalHeaderItem(0, new QTableWidgetItem("Customer"));
    table->setHorizontalHeaderItem(1, new QTableWidgetItem("Item"));
    table->setHorizontalHeaderItem(2, new QTableWidgetItem("Unit Price"));
    table->setHorizontalHeaderItem(3, new QTableWidgetItem("Quantity Ordered"));
    table->setHorizontalHeaderItem(4, new QTableWidgetItem("Subtotal"));
    table->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    table->verticalHeader()->setHidden(true);
    table->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    table->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    table->setEditTriggers(QAbstractItemView::NoEditTriggers);

    for (int i = 0; i < currentRestaurant.getOrderCount(); i++)
    {
        Order currentOrder = currentRestaurant.getOrder(i);
        for (size_t j = 0; j < currentOrder.second.size(); j++)
        {
            table->setItem(i, 0, new QTableWidgetItem(currentOrder.first.getUsername()));
            table->setItem(i, 1, new QTableWidgetItem(currentOrder.second[j].getName()));
            table->setItem(i, 2, new QTableWidgetItem(QString::number(currentOrder.second[j].getPrice(), 'f', 2)));
            table->setItem(i, 3, new QTableWidgetItem(QString::number(currentOrder.second[j].getQuantity())));
            table->setItem(i, 4, new QTableWidgetItem(QString::number(currentOrder.second[j].getPrice() * currentOrder.second[j].getQuantity(), 'f', 2)));
        }
    }

    return table;
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

