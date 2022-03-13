#include "menuwidget.h"

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
    //Get the tile clicked and send to restaurant menu
    Button *clickedButton = qobject_cast<Button *>(sender());
    qDebug() << "Menu button Clicked: " << clickedButton->text();
}

Button *MenuWidget::createButton(Menu::Item item, const char *member)
{
    Button *button = new Button(item);
    connect(button, SIGNAL(clicked()), this, member);
    return button;
}




