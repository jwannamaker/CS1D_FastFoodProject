#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "restaurantwidget.h"
#include "mainmenuwidget.h"
#include "menuwidget.h"
#include "loginwidget.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(1000, 600);

    Database.loadRestaurantsFromDatabase();
    if(RestaurantList.size() <= 0)
    {
        qDebug() << "Loading from .txt file";
        Database.addRestaurants();
    }

    // initializes the stacked widget with loginPage the first view
    stackedWidget = new QStackedWidget;
    setCentralWidget(stackedWidget);
    initializeNewUser();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initializeNewUser()
{
    // initializing login page
    loginPage = new LoginWidget();
    stackedWidget->addWidget(loginPage);
    QObject::connect(loginPage,
                     SIGNAL(transmit_validUser()),
                     this,
                     SLOT(recieve_loginSuccess()));
    stackedWidget->setCurrentWidget(loginPage);
}

void MainWindow::initializeMainMenu()
{
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
    stackedWidget->setCurrentWidget(mainMenuPage);
}

void MainWindow::recieve_loginSuccess()
{
    loginPage->on_clearButton_pressed();
    initializeMainMenu();
}

void MainWindow::recieve_logout()
{
    stackedWidget->setCurrentWidget(loginPage);
}

// new instance of restaurant widget is created upon calling of this method
// so that most updated version of Restaurant::list is used
void MainWindow::recieve_restaurantView()
{
    // initializing restaurant page
    restaurantPage = new RestaurantWidget();
    stackedWidget->addWidget(restaurantPage);
    QObject::connect(restaurantPage,
                     SIGNAL(transmit_cancel()),
                     this,
                     SLOT(recieve_mainMenu()));
    QObject::connect(restaurantPage,
                     SIGNAL(transmit_viewRestMenu(Restaurant&)),
                     this,
                     SLOT(recieve_viewMenu(Restaurant&)));
    stackedWidget->setCurrentWidget(restaurantPage);
}

void MainWindow::recieve_addRestaurantToTrip(Restaurant& rest)
{
    restaurantPage->addRestaurantToTrip(rest);
    stackedWidget->setCurrentWidget(restaurantPage);
}

void MainWindow::recieve_mainMenu()
{
    initializeMainMenu();
}

void MainWindow::recieve_viewMenu(Restaurant& rest)
{
    // initializing menu page
    qDebug() << "recieve_viewMenu has been called for " << rest.getName() << "\n";

    menuPage = new MenuWidget(rest);
    stackedWidget->addWidget(menuPage);
    QObject::connect(menuPage,
                     SIGNAL(transmit_cancelOrder()),
                     this,
                     SLOT(recieve_restaurantView()));
    QObject::connect(menuPage,
                     SIGNAL(transmit_confirmOrder(Restaurant&)),
                     this,
                     SLOT(recieve_addRestaurantToTrip(Restaurant&)));
    stackedWidget->setCurrentWidget(menuPage);
}

void MainWindow::recieve_revenueView()
{
    // initializing the revenue page
    revenuePage = new RevenueWidget();
    stackedWidget->addWidget(revenuePage);
    QObject::connect(revenuePage,
                     SIGNAL(transmit_cancel()),
                     this,
                     SLOT(recieve_mainMenu()));
    stackedWidget->setCurrentWidget(revenuePage);
}
