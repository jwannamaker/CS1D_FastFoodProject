#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDebug>
#include <QMainWindow>
#include <QPushButton>
#include <QObject>
#include <QStackedWidget>
#include "databasehelper.h"
#include "customer.h"
#include "loginwidget.h"
#include "mainmenuwidget.h"
#include "restaurantwidget.h"
#include "menuwidget.h"
#include "revenuewidget.h"
#include "adminwidget.h"

// linking gloabals
extern Customer CurrentUser;
extern DatabaseHelper Database;
extern std::vector<Restaurant> RestaurantList;

namespace Ui {
class MainWindow;
}

///
/// \class MainWindow
/// \brief The MainWindow class
///
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    ///
    /// \brief initializeNewUser
    ///
    void initializeNewUser();

    ///
    /// \brief initializeMainMenu
    ///
    void initializeMainMenu();

public slots:
    ///
    /// \brief recieve_loginSuccess
    /// \param newUser
    ///
    void recieve_loginSuccess();

    ///
    /// \brief recieve_logout
    /// Switches the top widget of the stacked widget to the login widget
    ///
    void recieve_logout();

    ///
    /// \brief recieve_restaurantView
    ///
    void recieve_restaurantView();

    ///
    /// \brief recieve_addRestaurantToTrip
    ///
    void recieve_addRestaurantToTrip(Restaurant&);

    ///
    /// \brief recieve_mainMenu
    ///
    void recieve_mainMenu();

    ///
    /// \brief recieve_viewMenu
    /// \param Restaurant rest
    ///
    void recieve_viewMenu(Restaurant& rest);

    ///
    /// \brief recieve_viewRevenue
    ///
    void recieve_revenueView();

    ///
    /// \brief recieve_adminView
    ///
    void recieve_adminView();

private:
    Customer            currentUser;
    Ui::MainWindow*     ui;
    QStackedWidget*     stackedWidget;
    LoginWidget*        loginPage;
    MainMenuWidget*     mainMenuPage;
    MenuWidget*         menuPage;
    RestaurantWidget*   restaurantPage;
    RevenueWidget*      revenuePage;
    AdminWidget*        adminPage;
};

#endif // MAINWINDOW_H
