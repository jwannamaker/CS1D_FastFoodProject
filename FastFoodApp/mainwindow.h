#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QObject>
#include <QStackedWidget>
#include "restaurantwidget.h"
#include "mainmenuwidget.h"
#include "login.h"
//#include "header.h"

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
    RestaurantWidget* restaurantPage;
};

#endif // MAINWINDOW_H
