#include "mainwindow.h"
#include <QApplication>
#include <QObject>

// global variables
Customer CurrentUser;
DatabaseHelper Database;
std::vector<Restaurant> RestaurantList;
Restaurant NULL_RESTAURANT = Restaurant();
Item NULL_ITEM = Item();

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Q_INIT_RESOURCE(resource);

    MainWindow mainWindow;
    mainWindow.show();
    return app.exec();
}
