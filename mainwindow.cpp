#include "mainwindow.h"
#include "ui_mainwindow.h"

///
/// \brief MainWindow::MainWindow
/// \param parent
///
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

///
/// \brief MainWindow::~MainWindow
///
MainWindow::~MainWindow()
{
    Database.createRestaurantTable();
    Database.createDistancesTable();
    Database.createMenuTable();
    Database.createOrderTable();
    delete ui;
}

///
/// \brief MainWindow::initializeNewUser
///
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

///
/// \brief MainWindow::initializeMainMenu
///
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
    QObject::connect(mainMenuPage,
                     SIGNAL(transmit_adminView()),
                     this,
                     SLOT(recieve_adminView()));
    stackedWidget->setCurrentWidget(mainMenuPage);
}

///
/// \brief MainWindow::recieve_loginSuccess
///
void MainWindow::recieve_loginSuccess()
{
    loginPage->on_clearButton_pressed();
    initializeMainMenu();
}

///
/// \brief MainWindow::recieve_logout
///
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

///
/// \brief MainWindow::recieve_addRestaurantToTrip
/// \param rest
///
void MainWindow::recieve_addRestaurantToTrip(Restaurant& rest)
{
    stackedWidget->setCurrentWidget(restaurantPage);
}

///
/// \brief MainWindow::recieve_mainMenu
///
void MainWindow::recieve_mainMenu()
{
    initializeMainMenu();
}

///
/// \brief MainWindow::recieve_viewMenu
/// \param rest
///
void MainWindow::recieve_viewMenu(Restaurant& rest)
{
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
    QObject::connect(menuPage,
                     SIGNAL(transmit_editMenu()),
                     this,
                     SLOT(recieve_adminView()));
    stackedWidget->setCurrentWidget(menuPage);
}

///
/// \brief MainWindow::recieve_revenueView
///
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

///
/// \brief MainWindow::recieve_adminView
///
void MainWindow::recieve_adminView()
{
    adminPage = new AdminWidget();
    stackedWidget->addWidget(adminPage);
    QObject::connect(adminPage,
                     SIGNAL(transmit_cancel()),
                     this,
                     SLOT(recieve_mainMenu()));
    stackedWidget->setCurrentWidget(adminPage);
}
