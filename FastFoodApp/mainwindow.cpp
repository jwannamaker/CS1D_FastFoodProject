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

    ui->stackedWidget->setCurrentWidget(ui->loginPage);
}

MainWindow::~MainWindow()
{
    delete ui;
}
