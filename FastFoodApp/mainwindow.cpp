#include <QDebug>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "login.h"
#include "restaurant.h"
#include "databasehelper.h"
#include "restaurantwidget.h"
#include "mainmenuwidget.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // initially opens to loginPage
    stackedWidget = new QStackedWidget;

    // initializing login page
    loginPage = new Login();
    stackedWidget->addWidget(loginPage);
    QObject::connect(loginPage,
                     SIGNAL(transmit_validUser(bool)),
                     this,
                     SLOT(recieve_loginAttempt(bool)));

    // initializing main menu page
    mainMenuPage = new MainMenuWidget();
    stackedWidget->addWidget(mainMenuPage);
    QObject::connect(mainMenuPage,
                     SIGNAL(transmit_logout()),
                     this,
                     SLOT(recieve_logout()));
    QObject::connect(mainMenuPage,
                     SIGNAL(transmit_restaurantView()),
                     this,
                     SLOT(recieve_restaurantView()));

    // initializing restaurant page
    restaurantPage = new RestaurantWidget();
    stackedWidget->addWidget(restaurantPage);
    QObject::connect(restaurantPage,
                     SIGNAL(transmit_cancel()),
                     this,
                     SLOT(recieve_mainMenu()));

    // by default, opens to the login page first
    stackedWidget->setCurrentWidget(loginPage);
    setCentralWidget(stackedWidget);

    //std::vector<Restaurant> restaurants;
    // testing populating global restaurants vector
    //Restaurant::list.push_back(Restaurant(0, "Please Work")); //Would this push two of the same resturant instances?
    DatabaseHelper dbHelper;
    dbHelper.populateRestaurants();
    dbHelper.createRestaurantTable();
    dbHelper.createMenuTable();
    dbHelper.createDistancesTable();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::recieve_loginAttempt(bool valid)
{
    if (valid)
        stackedWidget->setCurrentWidget(mainMenuPage);
    loginPage->on_clearButton_pressed();
}

void MainWindow::recieve_logout()
{
    stackedWidget->setCurrentWidget(loginPage);
}


// may need to adjust this so that a new restaurant page instance is created each time it is displayed,
// and include in its constructor the customer/user data such as the location they're starting from
// or indicate if that lineEdit can be edited or not, etc.
void MainWindow::recieve_restaurantView()
{
    stackedWidget->setCurrentWidget(restaurantPage);
}


void MainWindow::recieve_mainMenu()
{
    stackedWidget->setCurrentWidget(mainMenuPage);
}
