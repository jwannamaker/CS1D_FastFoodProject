#include "mainwindow.h"
#include <QApplication>
#include <QObject>

// global variables
Customer CurrentUser = Customer();
DatabaseHelper Database = DatabaseHelper();
std::vector<Restaurant> Restaurants = std::vector<Restaurant>();

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Q_INIT_RESOURCE(resource);

    MainWindow mainWindow;
    mainWindow.show();
    return app.exec();
}
