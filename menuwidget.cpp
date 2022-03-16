#include "menuwidget.h"
#include "QTableWidget"

MenuWidget::MenuWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MenuWidget)
{
    ui->setupUi(this);
    ui->subtotalLineEdit->setText(QString::number(0.00));
    ui->subtotalLineEdit->setAlignment(Qt::AlignmentFlag::AlignRight);

}

MenuWidget::MenuWidget(const Restaurant& currentRestaurant, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MenuWidget)
{
    //Save the restaurant passed in to menu widget class member
    this->currentRestaurant = currentRestaurant;
    //Initialize members
    subTotal = 0;
    menuItemsAdded = 0;
    std::vector<Menu::Item> menuItems = currentRestaurant.getMenu().getItems();

    ui->setupUi(this);

    //Create the menu item buttons
    for (size_t i = 0; i < menuItems.size(); ++i)
        itemButtons.append(createButton(menuItems[i], SLOT(itemClicked())));

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

void MenuWidget::on_confirmButton_pressed()
{
    // go through listWidget and update restuarant's revenue with total from order

    emit transmit_confirmOrder(std::vector<Menu::Item>());
}


void MenuWidget::on_editButton_pressed()
{

}


void MenuWidget::on_cancelButton_pressed()
{
    emit transmit_cancelOrder();
}

void MenuWidget::itemClicked()
{
    Button *clickedButton = qobject_cast<Button *>(sender());

    //Once item is clicked a order is started, Ordered
    //items are stored in this vector
    std::vector<Menu::Item> currentItems;
    qDebug() << "Menu button Clicked: " << clickedButton->getTopText()->text();

    //Create an item with the menu item text to place in table
    QString menuItemText = clickedButton->getTopText()->text();
    QTableWidgetItem *menuItem = new QTableWidgetItem(menuItemText);

    //Create a Item to add to the current Items vector
    //OrderItem orderItem(menuItemText, 0);
    Menu::Item orderItem(menuItemText, 0);

    //Check if a menu item is in the table
    QList<QTableWidgetItem *> items = ui->tableWidget_menuItems->findItems(menuItemText, Qt::MatchExactly);

    //If the menu item table is not in the table, add it to the table
    if (items.size() == 0)
    {
        //Add order to vector, increment quantity, and display to table
        order.push_back(orderItem);
        order[menuItemsAdded].incrementQuantity();
        QString s = QString::number(order[menuItemsAdded].getQuantity());
        QTableWidgetItem *itemQuantity = new QTableWidgetItem(s);
        ui->tableWidget_menuItems->setItem(menuItemsAdded, 0, menuItem);
        ui->tableWidget_menuItems->setItem(menuItemsAdded, 1, itemQuantity);

        //Create a button to delete ordered food item
        deleteItemButtons.append(createButton(orderItem, SLOT(deleteItemClicked())));
        QHBoxLayout *l = new QHBoxLayout();
        l->addWidget(deleteItemButtons[menuItemsAdded]);
        QWidget *w = new QWidget();
        w->setLayout(l);
        ui->tableWidget_menuItems->setCellWidget(menuItemsAdded,2, w);

        //update subtotal get item price
        subTotal += currentRestaurant.getMenu().getItemPrice(menuItemText);
        QString valueAsString = QString::number(subTotal);
        ui->subtotalLineEdit->setText(valueAsString);

        //menu item added. Increment
        menuItemsAdded++;
    }
    //Else if menu item is already in the table, increment quantity and update subtotal
    else
    {
        int menuIndex  = GetMenuItemIndex(menuItemText);

        //If menu is valid continute
        if( menuIndex != -1)
        {
            order[menuIndex].incrementQuantity();

            //Set item quantity to table
            QString s = QString::number(order[menuIndex].getQuantity());
            QTableWidgetItem *itemQuantity = new QTableWidgetItem(s);
            ui->tableWidget_menuItems->setItem(menuIndex, 1, itemQuantity);

            //Update and display subtotal
            subTotal += currentRestaurant.getMenu().getItemPrice(menuItemText);
            QString valueAsString = QString::number(subTotal);
            ui->subtotalLineEdit->setText(valueAsString);
        }
        else
        {
            qDebug() << "An error has occured";
        }

    }

}

Button *MenuWidget::createButton(Menu::Item item, const char *member)
{
    Button *button = new Button(item, item.getName());
    connect(button, SIGNAL(clicked()), this, member);
    return button;
}

//Button *MenuWidget::createDeleteButton(const char *member)
//{
    //Button *button = new Button("Delete", "Item");
    //connect(button, SIGNAL(clicked()), this, member);
    //return button;
//}

Restaurant MenuWidget::GetCurrentRestuarant()
{
    return currentRestaurant;
}

int MenuWidget::GetMenuItemIndex(QString itemName)
{
    for (int i = 0; i < MAX_MENU_ITEMS; i++)
    {
        if(order[i].getName() == itemName)
        {
            return i;
        }
    }

    qDebug() << "Item doesn't exist";
    return -1;
}

void MenuWidget::deleteItemClicked()
{
    Button *clickedButton = qobject_cast<Button *>(sender());

    int menuIndex = GetMenuItemIndex(clickedButton->getItemName());

    if( menuIndex != -1)
    {
        if (order[menuIndex].getQuantity() != 0)
        {
            order[menuIndex].decrementQuantity();

            //Set item quantity to table
            QString s = QString::number(order[menuIndex].getQuantity());
            QTableWidgetItem *itemQuantity = new QTableWidgetItem(s);
            ui->tableWidget_menuItems->setItem(menuIndex, 1, itemQuantity);

            //Update and display subtotal
            subTotal -= currentRestaurant.getMenu().getItemPrice(clickedButton->getItemName());
            QString valueAsString = QString::number(subTotal);
            ui->subtotalLineEdit->setText(valueAsString);
        }
        else
        {
            qDebug() <<"working on this";
            //delete item from the table completely
        }


    }
    else
    {
        qDebug() << "something silly happened!";
    }


}



