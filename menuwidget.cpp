#include "menuwidget.h"

///
/// \brief MenuWidget::MenuWidget
/// \param inputRestaurant
/// \param parent
///
MenuWidget::MenuWidget(Restaurant& inputRestaurant, QWidget *parent) :
    QWidget(parent), ui(new Ui::MenuWidget), currentRestaurant(inputRestaurant)
{
    ui->setupUi(this);
    ui->tableWidget_orderItems->setColumnCount(4);
    ui->tableWidget_orderItems->setHorizontalHeaderItem(0, new QTableWidgetItem("Item"));
    ui->tableWidget_orderItems->setHorizontalHeaderItem(1, new QTableWidgetItem("Quantity"));
    ui->tableWidget_orderItems->setHorizontalHeaderItem(2, new QTableWidgetItem("Subtotal"));
    ui->tableWidget_orderItems->setHorizontalHeaderItem(3, new QTableWidgetItem("Delete"));

    createButtons();
    updateTableWidget();
    updateOrderTotal();
}

///
/// \brief MenuWidget::~MenuWidget
///
MenuWidget::~MenuWidget()
{
    delete ui;
}

///
/// \brief MenuWidget::createButtons
///
void MenuWidget::createButtons()
{
    //Create the menu item buttons
    for (unsigned int i = 0; i < currentRestaurant.getMenuSize(); ++i)
        itemButtons.push_back(createButton(currentRestaurant.getMenuItem(i)));

    //Create Grid for menu item icons
    buttonLayout = new QGridLayout(ui->scrollArea_menu);

    //Add menu items to window
    int row = 0;
    int col = 0;

    for (unsigned int i = 0; i < currentRestaurant.getMenuSize(); i++)
    {
        buttonLayout->addWidget(itemButtons[i], row, col);
        col++;

        if (col >= MAX_COL)
        {
            row++;
            col = 0;
        }
    }
}

///
/// \brief MenuWidget::updateOrderTotal
///
void MenuWidget::updateOrderTotal()
{
    double grandTotal = 0;
    for (Item& item : orderedItems)
        grandTotal += item.getPrice() * item.getQuantity();
    ui->totalLineEdit->setText(QString::number(grandTotal));
}

///
/// \brief MenuWidget::updateTableWidget
///
void MenuWidget::updateTableWidget()
{
    ui->tableWidget_orderItems->setRowCount(orderedItems.size());
    for (unsigned int index = 0; index < orderedItems.size(); index++)
    {
        QTableWidgetItem* itemName = new QTableWidgetItem(orderedItems[index].getName());
        ui->tableWidget_orderItems->setItem(index, 0, itemName);
        QTableWidgetItem* itemQuantity = new QTableWidgetItem(orderedItems[index].getQuantity());
        ui->tableWidget_orderItems->setItem(index, 1, itemQuantity);
        // should it be unit price or actual price?
        QTableWidgetItem* itemPrice = new QTableWidgetItem(QString::number(orderedItems[index].getPrice()));
        ui->tableWidget_orderItems->setItem(index, 2, itemPrice);
        ui->tableWidget_orderItems->item(index, 2)->setTextAlignment(Qt::AlignRight);
        QPixmap deleteButton = QPixmap(":images/trashbin_icon.png");
        ui->tableWidget_orderItems->setItem(index, 3, new QTableWidgetItem(QIcon(deleteButton), "Delete"));
    }
}

///
/// \brief MenuWidget::on_confirmButton_pressed
///
void MenuWidget::on_confirmButton_pressed()
{
    updateTableWidget();
    updateOrderTotal();
    currentRestaurant.addRevenue(ui->totalLineEdit->text().toDouble());
    emit transmit_confirmOrder(currentRestaurant);
}

///
/// \brief MenuWidget::on_cancelButton_pressed
///
void MenuWidget::on_cancelButton_pressed()
{
    currentRestaurant.setRevenue(0);
    emit transmit_cancelOrder();
}

///
/// \brief MenuWidget::recieve_itemClicked
/// \param item
///
void MenuWidget::recieve_itemClicked(Item& item)
{
    orderedItems.push_back(item);
    updateTableWidget();
    updateOrderTotal();
}

///
/// \brief MenuWidget::createButton
/// \param item
/// \return
///
Button *MenuWidget::createButton(Item& item)
{
    Button *button = new Button(currentRestaurant, item, this);
    QObject::connect(button,
                     SIGNAL(transmit_itemClicked(Item&)),
                     this,
                     SLOT(recieve_itemClicked(Item&)));
    return button;
}



