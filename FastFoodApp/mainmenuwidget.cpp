#include "mainmenuwidget.h"
#include "ui_mainmenuwidget.h"
#include "mainwindow.h"
#include "restaurantwidget.h"
#include "login.h"

MainMenuWidget::MainMenuWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainMenuWidget)
{
    ui->setupUi(this);
}

MainMenuWidget::~MainMenuWidget()
{
    delete ui;
}

void MainMenuWidget::on_logOutButton_pressed()
{
    // switch the top widget on the stacked widget to the login widget
    emit transmit_logout();
}


void MainMenuWidget::on_orderHistoryButton_pressed()
{

}

void MainMenuWidget::on_restaurantsButton_pressed()
{
    emit transmit_restaurantView();
}