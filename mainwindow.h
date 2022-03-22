#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDebug>
#include <QMainWindow>
#include <QPushButton>
#include <QObject>
#include <QStackedWidget>
#include "loginwidget.h"
#include "mainmenuwidget.h"
#include "menuwidget.h"
#include "restaurantwidget.h"
#include "revenuewidget.h"

// linking globals
extern Customer CurrentUser;
extern std::vector<Restaurant> Restaurants;
extern DatabaseHelper Database;

namespace Ui {
class MainWindow;
}

///
/// \class MainWindow.
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
    void recieve_loginSuccess(Customer newUser);

    ///
    /// \brief recieve_loginFail
    ///
    void recieve_loginFail();

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
    /// \param Restaurant rest
    ///
    void recieve_addRestaurantToTrip(Restaurant rest);

    ///
    /// \brief recieve_mainMenu
    ///
    void recieve_mainMenu();

    ///
    /// \brief recieve_viewMenu
    /// \param Restaurant rest
    ///
    void recieve_viewMenu(Restaurant* rest);

    ///
    /// \brief recieve_viewRevenue
    ///
    void recieve_revenueView();

private:
    Ui::MainWindow*     ui;
    QStackedWidget*     stackedWidget;
    LoginWidget*        loginPage;
    MainMenuWidget*     mainMenuPage;
    MenuWidget*         menuPage;
    RestaurantWidget*   restaurantPage;
    RevenueWidget*      revenuePage;
};

#endif // MAINWINDOW_H
