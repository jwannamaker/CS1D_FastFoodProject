#include "menuwidget.h"

MenuWidget::MenuWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MenuWidget)
{
    ui->setupUi(this);
}

MenuWidget::MenuWidget(const Restaurant &currentRestaurant, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MenuWidget)
{

    std::vector<Menu::Item> menuItems = currentRestaurant.getMenu().getItems();
    qDebug() << "Menu items size" << menuItems.size();

    ui->setupUi(this);
    //Create the restaurant buttons
    for (size_t i = 0; i < menuItems.size(); ++i)
        menuButtons.append(createButton(menuItems[i], SLOT(menuClicked())));

    //Create Grid for restaurant icons
    QGridLayout *mainLayout = new QGridLayout(ui->scrollArea_menu);
    mainLayout->setSizeConstraint(QLayout::SetFixedSize);

    //Add restaurants to window
    int row = 0;
    int col = 0;

    for (size_t i = 0; i < menuItems.size(); i++)
    {
        mainLayout->addWidget(menuButtons[i], row, col);
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

}


void MenuWidget::on_editButton_pressed()
{

}


void MenuWidget::on_cancelButton_pressed()
{
    emit transmit_cancelOrder();
}

void MenuWidget:: menuClicked()
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


