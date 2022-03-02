#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "login.h"
#include "restaurantwidget.h"
#include "mainmenuwidget.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // initially opens to loginPage
    ui->stackedWidget->setCurrentWidget(ui->loginPage);

    QObject::connect(ui->loginPage,
                     SIGNAL(ui->loginPage->transmit_validUser(bool)),
                     this,
                     SLOT(this->recieve_loginAttempt(bool)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::recieve_loginAttempt(const bool& valid)
{
    if (valid)
        ui->stackedWidget->setCurrentWidget(ui->mainMenuPage);
    ui->stackedWidget->show();
}
