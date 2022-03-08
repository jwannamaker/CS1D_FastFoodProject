#include "menuwidget.h"
#include "ui_menuwidget.h"

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
    ui->setupUi(this);


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

