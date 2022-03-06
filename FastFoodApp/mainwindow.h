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

signals:

public slots:
    void recieve_loginAttempt(bool valid);
    void recieve_logout();
    void recieve_restaurantView();
    void recieve_mainMenu();

private:
    Ui::MainWindow *ui;
    QStackedWidget *stackedWidget;
    Login* loginPage;
    MainMenuWidget* mainMenuPage;
    MenuWidget* menuPage;
    RestaurantWidget* restaurantPage;
};

#endif // MAINWINDOW_H
