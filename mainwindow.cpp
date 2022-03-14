#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "restaurantwidget.h"
#include "mainmenuwidget.h"
#include "menuwidget.h"
#include "login.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // initializing connection to database
    dbHelper = DatabaseHelper();
    dbHelper.populateRestaurants();

    // initially opens to loginPage
    stackedWidget = new QStackedWidget;
    initializeNewUser();

    // by default, opens to the login page first
    stackedWidget->setCurrentWidget(loginPage);
    setCentralWidget(stackedWidget);

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
    QObject::connect(mainMenuPage,
                     SIGNAL(transmit_revenueView()),
                     this,
                     SLOT(recieve_revenueView()));

    // initializing restaurant page
    restaurantPage = new RestaurantWidget(Restaurant::list);
    stackedWidget->addWidget(restaurantPage);
    QObject::connect(restaurantPage,
                     SIGNAL(transmit_cancel()),
                     this,
                     SLOT(recieve_mainMenu()));
    QObject::connect(restaurantPage,
                     SIGNAL(transmit_viewRestMenu(Restaurant)),
                     this,
                     SLOT(recieve_viewMenu(Restaurant)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initializeNewUser()
{
    // initializing login page
    loginPage = new Login();
    stackedWidget->addWidget(loginPage);
    QObject::connect(loginPage,
                     SIGNAL(transmit_validUser(Customer)),
                     this,
                     SLOT(recieve_loginSuccess(Customer)));
}

void MainWindow::recieve_loginSuccess(Customer newUser)
{
    stackedWidget->setCurrentWidget(mainMenuPage);
    user = newUser;
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

void MainWindow::recieve_addRestaurantToTrip(Restaurant rest)
{
    restaurantPage->addRestaurantToTrip(rest);
    stackedWidget->setCurrentWidget(restaurantPage);
}

void MainWindow::recieve_mainMenu()
{
    stackedWidget->setCurrentWidget(mainMenuPage);
}

void MainWindow::recieve_viewMenu(Restaurant rest)
{
    // initializing menu page
    menuPage = new MenuWidget(rest);
    stackedWidget->addWidget(menuPage);
    QObject::connect(menuPage,
                     SIGNAL(transmit_cancelOrder()),
                     this,
                     SLOT(recieve_restaurantView()));
    QObject::connect(menuPage,
                     SIGNAL(transmit_confirmOrder(Restaurant)),
                     this,
                     SLOT(recieve_addRestaurantToTrip(Restaurant)));
    stackedWidget->setCurrentWidget(menuPage);
}

void MainWindow::recieve_revenueView()
{
    // initializing the revenue page
    revenuePage = new RevenueWidget(Restaurant::list);
    stackedWidget->addWidget(revenuePage);
    QObject::connect(revenuePage,
                     SIGNAL(transmit_cancel()),
                     this,
                     SLOT(recieve_mainMenu()));
    stackedWidget->setCurrentWidget(revenuePage);
}
