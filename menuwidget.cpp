#include "menuwidget.h"
#include "QTableWidget"

MenuWidget::MenuWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MenuWidget)
{
    ui->setupUi(this);
    ui->subtotalLineEdit->setText(QString::number(0.00));
    ui->subtotalLineEdit->setAlignment(Qt::AlignmentFlag::AlignRight);
    ui->tableWidget_menuItems->setColumnCount(2);
    ui->tableWidget_menuItems->setRowCount(8);

}

MenuWidget::MenuWidget(const Restaurant& currentRestaurant, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MenuWidget)
{
    //Save the restaurant passed in to menu widget class member
    this->currentRestaurant = currentRestaurant;

    //ui->tableWidget_menuItems->setColumnCount(3);

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
    //keeps track of row where menu item is added
    int row = 1;
    //Get the tile clicked and send to restaurant menu
    Button *clickedButton = qobject_cast<Button *>(sender());
    qDebug() << "Menu button Clicked: " << clickedButton->getTopText()->text();

    QString menuItemText = clickedButton->getTopText()->text();
    QTableWidgetItem *menuItem = new QTableWidgetItem(menuItemText);
    QList<QTableWidgetItem *> items = ui->tableWidget_menuItems->findItems(menuItemText, Qt::MatchExactly);
    ui->tableWidget_menuItems->setColumnCount(3);


    if (items.size() == 0)
    {
        //ui->table_menuItems->addItem(menuItem);
        ui->tableWidget_menuItems->setRowCount(menuItemsAdded + 1);
        ui->tableWidget_menuItems->setItem(menuItemsAdded, 0, menuItem);
        menuItemsAdded++;

        //update subtotal get item price
        subTotal += currentRestaurant.getMenu().getItemPrice(menuItemText);
        QString valueAsString = QString::number(subTotal);
        ui->subtotalLineEdit->setText(valueAsString);
    }
    else
    {
        //update quantity of item selected
        subTotal += currentRestaurant.getMenu().getItemPrice(menuItemText);
        QString valueAsString = QString::number(subTotal);
        ui->subtotalLineEdit->setText(valueAsString);
        qDebug() << "Menu item already added, updating quantity";
    }

}

Button *MenuWidget::createButton(Menu::Item item, const char *member)
{
    Button *button = new Button(item);
    connect(button, SIGNAL(clicked()), this, member);
    return button;
}

Restaurant MenuWidget::GetCurrentRestuarant()
{
    return currentRestaurant;
}




