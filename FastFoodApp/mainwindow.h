#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QObject>
#include "restaurantwidget.h"
#include "mainmenuwidget.h"
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
    void recieve_loginAttempt(const bool& valid);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
