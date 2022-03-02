#include "mainwindow.h"
#include <QApplication>
#include <QObject>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow mainWindow;
    Login login;

    QObject::connect(&login,
                     SIGNAL(transmit_validUser(bool)),
                     &mainWindow,
                     SLOT(recieve_loginAttempt(bool)));

    mainWindow.show();
    return a.exec();
}
