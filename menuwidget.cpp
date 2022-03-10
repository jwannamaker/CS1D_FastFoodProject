#include "menuwidget.h"
#include "ui_menuwidget.h"

MenuWidget::MenuWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MenuWidget)
{
    ui->setupUi(this);
    ui->subtotalLineEdit->setText(QString::number(0.00));
    ui->subtotalLineEdit->setAlignment(Qt::AlignmentFlag::AlignRight);
}

MenuWidget::MenuWidget(const std::vector<Menu::Item>& itemList, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MenuWidget)
{
    ui->setupUi(this);

    //Create the buttons
    for (Menu::Item item : itemList)
        itemButtons.append(createButton(item, SLOT(itemClicked())));

    //Create Grid for item icons
    QGridLayout *mainLayout = new QGridLayout(ui->scrollArea_menu);
    mainLayout->setSizeConstraint(QLayout::SetFixedSize);

    //Add items to window
    int row = 0;
    int col = 0;

    for (size_t i = 0; i < itemList.size(); i++)
    {
        mainLayout->addWidget(itemButtons[i], row, col);
        col++;

        if (col >= MAX_COL)
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
    qDebug() << "Item Clicked";

    ui->listWidget->addItem(clickedButton->getTopText().text());
}

Button *MenuWidget::createButton(Menu::Item item, const char *member)
{
    Button *button = new Button(item);
    connect(button, SIGNAL(clicked()), this, member);
    return button;
}




