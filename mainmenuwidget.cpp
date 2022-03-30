#include "mainmenuwidget.h"
#include "ui_mainmenuwidget.h"

///
/// \brief MainMenuWidget::MainMenuWidget
/// \param parent
///
MainMenuWidget::MainMenuWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainMenuWidget)
{
    ui->setupUi(this);
    QGraphicsScene* mainMenuScene = new QGraphicsScene();
    mainMenuScene->addPixmap(QPixmap(":images/03.jpg"));
    ui->graphicsView->setScene(mainMenuScene);
    ui->graphicsView->setBaseSize(250, 250);
    ui->graphicsView->show();

    // checking current user info for menu options
    ui->welcomeLabel->setText("Welcome, " + CurrentUser.getUsername());
    ui->adminButton->setHidden(!CurrentUser.isAdmin());
}

///
/// \brief MainMenuWidget::~MainMenuWidget
///
MainMenuWidget::~MainMenuWidget()
{
    delete ui;
}

///
/// \brief MainMenuWidget::on_logOutButton_pressed
///
void MainMenuWidget::on_logOutButton_pressed()
{
    emit transmit_logout();
}

///
/// \brief MainMenuWidget::on_restaurantsButton_pressed
///
void MainMenuWidget::on_restaurantsButton_pressed()
{
    emit transmit_restaurantView();
}

///
/// \brief MainMenuWidget::on_revenueButton_pressed
///
void MainMenuWidget::on_revenueButton_pressed()
{
    emit transmit_revenueView();
}

///
/// \brief MainMenuWidget::on_adminButton_pressed
///
void MainMenuWidget::on_adminButton_pressed()
{
    emit transmit_adminView();
}

