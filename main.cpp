#include "mainwindow.h"
#include <QApplication>
#include <QObject>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Q_INIT_RESOURCE(resource);

    DatabaseHelper dbHelper;
    dbHelper.populateRestaurants();

    MainWindow mainWindow;
    mainWindow.show();
    return app.exec();
}
