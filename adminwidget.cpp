/// 
/// \file adminwidget.cpp
/// \brief Implementation of the AdminWidget interface.
/// 
/// \authors Dante Vasquez, Johnny Wannamaker
/// 
#include "adminwidget.h"
#include "ui_adminwidget.h"

///
/// \brief AdminWidget::AdminWidget
/// \param parent
///
AdminWidget::AdminWidget(QWidget *parent) : QWidget(parent),
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
    // Add restaurants to combo box
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
    for (int index = 0; index < RestaurantList[currentID].getMenuSize(); index++)
    {
        QTableWidgetItem *itemName = new QTableWidgetItem(RestaurantList[currentID].getMenuItem(index).getName());
        ui->tableWidget->setItem(index, 0, itemName);
        QTableWidgetItem *unitPrice = new QTableWidgetItem(QString::number(RestaurantList[currentID].getMenuItem(index).getPrice(), 'f', 2));
        ui->tableWidget->setItem(index, 1, unitPrice);
        ui->tableWidget->item(index, 1)->setTextAlignment(Qt::AlignRight);
    }
}

///
/// \brief AdminWidget::saveMenu
///
void AdminWidget::saveMenu()
{
    Menu newMenu;
    for (int i = 0; i < ui->tableWidget->rowCount(); i++)
    {
        QString itemName = ui->tableWidget->item(i, 0)->text();
        double itemPrice = ui->tableWidget->item(i, 1)->text().toDouble();
        newMenu.push_back(Item(itemName, itemPrice));
    }
    RestaurantList[currentID].setMenu(newMenu);
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
    QString itemName = ui->lineEdit_itemName->text();
    QString itemPrice = QString::number(ui->doubleSpinBox_itemPrice->value(), 'f', 2);
    ui->tableWidget->item(ui->tableWidget->currentRow(), 0)->setText(itemName);
    ui->tableWidget->item(ui->tableWidget->currentRow(), 1)->setText(itemPrice);

    saveMenu();
    updateTableWidget();
}

///
/// \brief AdminWidget::on_deleteButton_pressed
///
void AdminWidget::on_deleteButton_pressed()
{
    ui->tableWidget->removeRow(ui->tableWidget->currentRow());
}

///
/// \brief AdminWidget::on_addButton_pressed
///
void AdminWidget::on_addButton_pressed()
{
    QModelIndex currentIndex = ui->tableWidget->currentIndex();
    ui->tableWidget->insertRow(currentIndex.row() + 1);
    ui->tableWidget->setItem(currentIndex.row() + 1, 0, new QTableWidgetItem("New Item"));
    ui->tableWidget->setItem(currentIndex.row() + 1, 1, new QTableWidgetItem("0.00"));
    ui->tableWidget->item(currentIndex.row() + 1, 1)->setTextAlignment(Qt::AlignRight);
}

///
/// \brief AdminWidget::on_tableWidget_itemSelectionChanged
///
void AdminWidget::on_tableWidget_itemSelectionChanged()
{
    QModelIndex currentIndex = ui->tableWidget->currentIndex();
    QString itemName = ui->tableWidget->item(currentIndex.row(), 0)->text();
    QString itemPrice = ui->tableWidget->item(currentIndex.row(), 1)->text();
    ui->lineEdit_itemName->setText(itemName);
    ui->doubleSpinBox_itemPrice->setValue(itemPrice.toDouble());
}
