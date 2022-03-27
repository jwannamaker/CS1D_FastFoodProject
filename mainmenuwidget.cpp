#include "mainmenuwidget.h"
#include "ui_mainmenuwidget.h"

MainMenuWidget::MainMenuWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainMenuWidget)
{
    ui->setupUi(this);
    QGraphicsScene* mainMenuScene = new QGraphicsScene();
    mainMenuScene->addPixmap(QPixmap(":images/rest_menu_icon.png"));
    ui->graphicsView->setScene(mainMenuScene);
    ui->graphicsView->setBaseSize(250, 250);
    ui->graphicsView->show();

    ui->welcomeLabel->setText("Welcome, " + CurrentUser.getUsername());
}

MainMenuWidget::~MainMenuWidget()
{
    delete ui;
}

void MainMenuWidget::on_logOutButton_pressed()
{
    emit transmit_logout();
}

void MainMenuWidget::on_restaurantsButton_pressed()
{
    emit transmit_restaurantView();
}

void MainMenuWidget::on_revenueButton_pressed()
{
    emit transmit_revenueView();
}

