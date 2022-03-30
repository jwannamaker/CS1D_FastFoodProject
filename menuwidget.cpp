#include "menuwidget.h"

///
/// \brief MenuWidget::MenuWidget
/// \param inputRestaurant
/// \param parent
///
MenuWidget::MenuWidget(Restaurant& inputRestaurant, std::vector<Item>& currentOrder, QWidget *parent) :
    QWidget(parent), ui(new Ui::MenuWidget), orderedItems(currentOrder), currentRestaurant(inputRestaurant)
{
    qDebug() << "menu widget constructor";
    ui->setupUi(this);
    ui->tableWidget_orderItems->setColumnCount(4);
    ui->tableWidget_orderItems->setHorizontalHeaderItem(0, new QTableWidgetItem("Item"));
    ui->tableWidget_orderItems->setHorizontalHeaderItem(1, new QTableWidgetItem("Quantity"));
    ui->tableWidget_orderItems->setHorizontalHeaderItem(2, new QTableWidgetItem("Price"));
    ui->tableWidget_orderItems->setHorizontalHeaderItem(3, new QTableWidgetItem("Remove Item"));
    ui->tableWidget_orderItems->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    //Create Grid for menu item icons
    buttonLayout = new QGridLayout(ui->scrollArea_menu);

    //ui->editButton->setHidden(CurrentUser.isAdmin());
    createButtons();
    updateTableWidget();
    updateOrderTotal();
    qDebug() << "end of menu widget constructor";
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
    qDebug() << "creating item buttons";
    //Create the menu item buttons
    for (int i = 0; i < currentRestaurant.getMenuSize(); ++i)
    {
        qDebug() << "creating new item button for " << currentRestaurant.getMenuItem(i).getName();
        itemButtons.push_back(createButton(currentRestaurant.getMenuItem(i)));
    }

    //Add menu items to window
    int row = 0;
    int col = 0;

    for (unsigned int i = 0; i < itemButtons.size(); i++)
    {
        qDebug() << "adding button to layout";
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
        grandTotal += orderedItems[i].getPrice() * orderedItems[i].getQuantity();
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
        QHBoxLayout *layout = new QHBoxLayout();
        layout->addWidget(deleteItemButtons[index]);
        QWidget *widget = new QWidget();
        widget->setLayout(layout);
        ui->tableWidget_orderItems->setCellWidget(index, 3, deleteItemButtons[index]);
    }
}

///
/// \brief MenuWidget::on_confirmButton_pressed
///
void MenuWidget::on_confirmButton_pressed()
{
    updateTableWidget();
    updateOrderTotal();

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
    QList<QTableWidgetItem *> items = ui->tableWidget_orderItems->findItems(item.getName(), Qt::MatchExactly);

    if (items.size() == 0)
    {
        orderedItems.push_back(item);
        int menuIndex  = getMenuItemIndex(item.getName());
        orderedItems[menuIndex].incrementQuantity();
        deleteItemButtons.append(createDeleteButton(item, SLOT(deleteItemClicked())));
        updateTableWidget();
        updateOrderTotal();
    }
    else
    {
        int menuIndex  = getMenuItemIndex(item.getName());
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

///
/// \brief MenuWidget::deleteItemClicked
///
void MenuWidget::deleteItemClicked()
{
    Button *clickedButton = qobject_cast<Button *>(sender());

    int menuIndex = getMenuItemIndex(clickedButton->getItem().getName());

    if( menuIndex != -1)
    {
        if (orderedItems[menuIndex].getQuantity() == 1)
        {
            orderedItems[menuIndex].decrementQuantity();
            orderedItems.erase(orderedItems.begin() + menuIndex);
            deleteItemButtons.erase(deleteItemButtons.begin() + menuIndex);
        }
        else
        {
            orderedItems[menuIndex].decrementQuantity();
        }
        updateTableWidget();
        updateOrderTotal();
    }
}

///
/// \brief MenuWidget::createButton
/// \param item
/// \return
///
Button *MenuWidget::createButton(Item item)
{
    Button *button = new Button(currentRestaurant, item, this);
    QObject::connect(button,
                     SIGNAL(transmit_itemClicked(Item&)),
                     this,
                     SLOT(recieve_itemClicked(Item&)));
    return button;
}

///
/// \brief MenuWidget::createDeleteButton
/// \param item
/// \param member
/// \return
///
Button *MenuWidget::createDeleteButton(Item& item)
{
    Button *button = new Button(item);
    connect(button,
            SIGNAL(clicked()),
            this,
            SLOT(deleteItemClicked());
    return button;
}

///
/// \brief MenuWidget::getMenuItemIndex
/// \param itemName
/// \return
///
int MenuWidget::getMenuItemIndex(QString itemName)
{
    for (int i = 0; i < currentRestaurant.getMenuSize(); i++)
        if(orderedItems[i].getName() == itemName)
            return i;

    qDebug() << "Item doesn't exist";
    return -1;
}

///
/// \brief MenuWidget::on_editButton_pressed
///
void MenuWidget::on_editButton_pressed()
{
    emit transmit_adminView();
}

