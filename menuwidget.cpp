#include "menuwidget.h"
#include "QTableWidget"

MenuWidget::MenuWidget(const Restaurant& currentRestaurant, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MenuWidget)
{
    ui->setupUi(this);
    ui->totalLineEdit->setAlignment(Qt::AlignmentFlag::AlignRight);
    ui->tableWidget_orderItems->setColumnCount(4);
    ui->tableWidget_orderItems->setHorizontalHeaderItem(0, new QTableWidgetItem("Item"));
    ui->tableWidget_orderItems->setHorizontalHeaderItem(1, new QTableWidgetItem("Quantity"));
    ui->tableWidget_orderItems->setHorizontalHeaderItem(2, new QTableWidgetItem("Subtotal"));
    ui->tableWidget_orderItems->setHorizontalHeaderItem(3, new QTableWidgetItem("Delete"));

    //Save the restaurant passed in to menu widget class member
    this->currentRestaurant = currentRestaurant;

    //Create the menu item buttons
    std::vector<Menu::Item> menuItems = currentRestaurant.getMenu().getItems();
    for (size_t i = 0; i < menuItems.size(); ++i)
        itemButtons.append(createButton(menuItems[i]));

    //Create Grid for menu item icons
    QGridLayout *mainLayout = new QGridLayout(ui->scrollArea_menu);
    mainLayout->setSizeConstraint(QLayout::SetFixedSize);

    //Add menu items to window
    int row = 0;
    int col = 0;

    for (size_t i = 0; i < menuItems.size(); i++)
    {
        mainLayout->addWidget(itemButtons[i], row, col);
        col++;

        if (col >= MAX_ITEMS_COLS)
        {
            row++;
            col = 0;
        }
    }
}

MenuWidget::~MenuWidget()
{
    delete ui;
}

//
void MenuWidget::updateOrderTotal()
{
    double grandTotal = 0;

    for (Menu::Item item : orderedItems)
        grandTotal += item.getPrice() * item.getQuantity();

    ui->totalLineEdit->setText(QString::number(grandTotal));
}

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

//        QPixmap deleteButton = QPixmap(":images/delete_icon.png");
//        ui->tableWidget_orderItems->setItem(index, 3, new QTableWidgetItem(QIcon(deleteButton), "Delete"));
    }
    updateOrderTotal();
}

void MenuWidget::on_confirmButton_pressed()
{
    updateTableWidget();
    currentRestaurant.addRevenue(ui->totalLineEdit->text().toDouble());
    emit transmit_confirmOrder(currentRestaurant);
}

void MenuWidget::on_cancelButton_pressed()
{
    // make sure that the quantity of each item is reverted back to 0
    emit transmit_cancelOrder();
}

void MenuWidget::itemClicked()
{
    //Get the tile clicked and send to restaurant menu
    Button *clickedButton = qobject_cast<Button *>(sender());
    orderedItems.push_back(clickedButton->getItem());
    updateTableWidget();
}

Button *MenuWidget::createButton(Menu::Item item)
{
    Button *button = new Button(item);
    connect(button, SIGNAL(clicked()), this, SLOT(itemClicked()));
    return button;
}

Restaurant MenuWidget::getCurrentRestuarant() const
{
    return currentRestaurant;
}




