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
    for (int i = 0; i < currentRestaurant.getMenuSize(); ++i)
        itemButtons.push_back(createButton(currentRestaurant.getMenuItem(i)));

    //Create Grid for menu item icons
    buttonLayout = new QGridLayout(ui->scrollArea_menu);

    //Add menu items to window
    int row = 0;
    int col = 0;

    for (int i = 0; i < currentRestaurant.getMenuSize(); i++)
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

    for (size_t i = 0; i < orderedItems.size(); i++)
    {
        grandTotal += orderedItems[i].getPrice() * orderedItems[i].getQuantity();
    }

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
        QString s = QString::number(orderedItems[index].getQuantity());
        QTableWidgetItem* itemQuantity = new QTableWidgetItem(s);
        ui->tableWidget_orderItems->setItem(index, 1, itemQuantity);
        // should it be unit price or actual price?
        QTableWidgetItem* itemPrice = new QTableWidgetItem(QString::number(orderedItems[index].getPrice()));
        ui->tableWidget_orderItems->setItem(index, 2, itemPrice);
        ui->tableWidget_orderItems->item(index, 2)->setTextAlignment(Qt::AlignRight);
        //set delete button
        QHBoxLayout *l = new QHBoxLayout();
        l->addWidget(deleteItemButtons[index]);
        QWidget *w = new QWidget();
        w->setLayout(l);
        ui->tableWidget_orderItems->setCellWidget(index,3, w);

    }
}

///
/// \brief MenuWidget::on_confirmButton_pressed
///
void MenuWidget::on_confirmButton_pressed()
{

    if(orderedItems.size() != 0)
    {
        qDebug() << "ayu";
        updateTableWidget();
        updateOrderTotal();
        currentRestaurant.addRevenue(ui->totalLineEdit->text().toDouble());
        emit transmit_confirmOrder(currentRestaurant);
    }
    else
    {
        qDebug() << "Nothing has been ordered silly!";
    }

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
    QList<QTableWidgetItem *> items = ui->tableWidget_orderItems->findItems(item.getName(), Qt::MatchExactly);

    if (items.size() == 0)
    {
        orderedItems.push_back(item);
        int menuIndex  = GetMenuItemIndex(item.getName());
        orderedItems[menuIndex].incrementQuantity();
        deleteItemButtons.append(createDeleteButton(item,SLOT (deleteItemClicked())));
        updateTableWidget();
        updateOrderTotal();
    }
    else
    {
        int menuIndex  = GetMenuItemIndex(item.getName());
        //If menu is valid continute
        if( menuIndex != -1)
        {
            orderedItems[menuIndex].incrementQuantity();
            updateTableWidget();
            updateOrderTotal();
        }
        else
            qDebug() << "An error has occured";
    }

}

void MenuWidget::deleteItemClicked()
{
    Button *clickedButton = qobject_cast<Button *>(sender());

    int menuIndex = GetMenuItemIndex(clickedButton->getItem().getName());

    if( menuIndex != -1)
    {
        if (orderedItems[menuIndex].getQuantity() == 1)
        {
            qDebug() <<"working on this";
            orderedItems[menuIndex].decrementQuantity();
            orderedItems.erase(orderedItems.begin() + menuIndex);
            deleteItemButtons.erase(deleteItemButtons.begin() + menuIndex);
            updateTableWidget();
            updateOrderTotal();
        }
        else
        {
            orderedItems[menuIndex].decrementQuantity();
            updateTableWidget();
            updateOrderTotal();
        }

    }
    else
        qDebug() << "something silly happened!";
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

Button *MenuWidget::createDeleteButton(Item& item, const char *member)
{
    Button *button = new Button(item);
    connect(button, SIGNAL(clicked()), this, member);
    return button;

}

int MenuWidget::GetMenuItemIndex(QString itemName)
{
    for (int i = 0; i < currentRestaurant.getMenuSize(); i++)
        if(orderedItems[i].getName() == itemName) return i;

    qDebug() << "Item doesn't exist";
    return -1;
}


