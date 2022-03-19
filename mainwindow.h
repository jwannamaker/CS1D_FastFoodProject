#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDebug>
#include <QMainWindow>
#include <QPushButton>
#include <QObject>
#include <QStackedWidget>
#include "databasehelper.h"
#include "restaurantwidget.h"
#include "mainmenuwidget.h"
#include "menuwidget.h"
#include "revenuewidget.h"
#include "login.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void initializeNewUser();
    void initializeMainMenu();

public slots:
    ///
    /// \brief recieve_loginSuccess
    /// \param newUser
    ///
    void recieve_loginSuccess(const Customer& newUser);

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
    void recieve_addRestaurantToTrip(Restaurant);

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

private:
    Customer            currentUser;
    Ui::MainWindow*     ui;
    QStackedWidget*     stackedWidget;
    Login*              loginPage;
    MainMenuWidget*     mainMenuPage;
    MenuWidget*         menuPage;
    RestaurantWidget*   restaurantPage;
    RevenueWidget*      revenuePage;
};

#endif // MAINWINDOW_H
