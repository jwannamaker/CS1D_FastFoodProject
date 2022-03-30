#include "adminwidget.h"
#include "ui_adminwidget.h"
#include <QMessageBox>

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
    for(int index = 0; index < RestaurantList[currentID].getMenuSize(); index++)
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


///
/// \brief AdminWidget::on_addItemButton_pressed
///
void AdminWidget::on_addItemButton_pressed()
{
    if(ui->lineEdit_menuItem->text().isEmpty())
    {
        QMessageBox::information(this, "Tip", "You must enter a name for the item");
    }
    else
    {
        Item item(ui->lineEdit_menuItem->text(), ui->doubleSpinBox_itemPrice->value());
        RestaurantList[currentID].addMenuItem(item);
        updateTableWidget();
    }

}

void AdminWidget::on_pushButton_delete_pressed()
{
    //Look for selected rows and remove the items selected
    QModelIndexList indexList = ui->tableWidget->selectionModel()->selectedIndexes();

    if(indexList.size() > 0)
    {
        foreach (QModelIndex index, indexList)
        {
            if(RestaurantList[currentID].getMenuSize() > 0)
                RestaurantList[currentID].RemoveMenuItem(index.row());

        }
        updateTableWidget();
    }
    else
        QMessageBox::information(this, "Tip", "You must select an item to delete");


}


void AdminWidget::on_pushButton_editPrice_pressed()
{

    QModelIndexList indexList = ui->tableWidget->selectionModel()->selectedIndexes();

    if(indexList.size() > 0)
    {
        //Open dialog window
        QMessageBox msgBox;
        QDoubleSpinBox* b = new QDoubleSpinBox();
        //set the spin box to selected item price for admin qol
        b->setValue(RestaurantList[currentID].getMenuItem(indexList[0].row()).getPrice());

        if (msgBox.layout())
          msgBox.layout()->addWidget(b);
        msgBox.setText("Enter the price you want.");
        msgBox.exec();

        //Look for selected rows and edit the price of the selected item
        foreach (QModelIndex index, indexList)
            RestaurantList[currentID].getMenuItem(index.row()).setPrice(b->value());

        updateTableWidget();
    }
    else
    {
        QMessageBox::information(this, "Tip", "You must select an item to edit the price");
    }


}

