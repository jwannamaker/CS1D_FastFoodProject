#include "adminwidget.h"
#include "ui_adminwidget.h"

///
/// \brief AdminWidget::AdminWidget
/// \param parent
///
AdminWidget::AdminWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AdminWidget)
{
    ui->setupUi(this);
    ui->tableWidget->setColumnCount(2);
    ui->tableWidget->setHorizontalHeaderItem(0, new QTableWidgetItem("Name"));
    ui->tableWidget->setHorizontalHeaderItem(1, new QTableWidgetItem("Price"));
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    populateComboBox();
    updateTableWidget();
}

///
/// \brief AdminWidget::~AdminWidget
///
AdminWidget::~AdminWidget()
{
    delete ui;
}

///
/// \brief AdminWidget::populateComboBox
///
void AdminWidget::populateComboBox()
{
    //Add restaurants to combo box
    for (size_t i = 0; i < RestaurantList.size(); ++i)
        ui->comboBox_restaurant->addItem(RestaurantList[i].getName());
}

///
/// \brief AdminWidget::updateTableWidget
///
void AdminWidget::updateTableWidget()
{
    ui->tableWidget->setRowCount(RestaurantList[currentID].getMenuSize());

    // initializing contents of the table
    for(size_t index = 0; index < RestaurantList[currentID].getMenuSize(); index++)
    {
        QTableWidgetItem* itemName = new QTableWidgetItem(RestaurantList[currentID].getMenuItem(index).getName());
        ui->tableWidget->setItem(index, 0, itemName);
        QTableWidgetItem* unitPrice = new QTableWidgetItem(QString::number(RestaurantList[currentID].getMenuItem(index).getPrice(), 'f', 2));
        ui->tableWidget->setItem(index, 1, unitPrice);
        ui->tableWidget->item(index, 1)->setTextAlignment(Qt::AlignRight);
    }
}

///
/// \brief AdminWidget::on_exitButton_pressed
///
void AdminWidget::on_exitButton_pressed()
{
    emit transmit_cancel();
}

///
/// \brief AdminWidget::on_comboBox_restaurant_currentIndexChanged
/// \param index
///
void AdminWidget::on_comboBox_restaurant_currentIndexChanged(int index)
{
    currentID = index;
    updateTableWidget();
}

///
/// \brief AdminWidget::on_saveButton_pressed
///
void AdminWidget::on_saveButton_pressed()
{

}

///
/// \brief AdminWidget::on_addItemButton_pressed
///
void AdminWidget::on_addItemButton_pressed()
{

}

