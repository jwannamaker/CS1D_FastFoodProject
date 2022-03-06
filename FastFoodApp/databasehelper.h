#ifndef DATABASE_H
#define DATABASE_H

#include <QtSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QFile>
#include "restaurant.h"
#include "menu.h"


///
/// \class Database
/// \brief The Database class
/// Manages a connection to the database (.sqlite)
///
class DatabaseHelper
{
public:
    ///
    /// \brief DatabaseHelper
    /// No Arg Constructor.
    ///
    DatabaseHelper();

    ~DatabaseHelper();

    ///
    /// \brief setSourceFile
    /// This function allows one to specify the *.txt where program data is being
    /// parsed from.
    /// \param QString filePath
    ///
    void setSourceFile(QString);

    ///
    /// \brief populateRestaurants
    /// This method parses the sourceFile (default value is "source_data1.txt"), and
    /// stores the relevant data into Restaurant::list, which is a static vector
    /// containing every Restaurant instance.
    ///
    void populateRestaurants();

    void loadRestaurantsFromDatabase();

    ///
    /// \brief createRestaurantTable
    /// This method creates and populates a table in the database ("restaurant_data.sqlite")
    ///
    void createRestaurantTable();

    ///
    /// \brief createDistancesTable
    ///
    void createDistancesTable();

    ///
    /// \brief createMenuTable
    ///
    void createMenuTable();

private:
    QSqlDatabase database;
    QString sourceFile;
};


#endif // DATABASE_H
