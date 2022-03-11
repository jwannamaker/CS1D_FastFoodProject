#ifndef DATABASE_H
#define DATABASE_H

#include <QtSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QFile>
#include "restaurant.h"
#include "customer.h"
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
    /// \brief populateRestaurants
    /// This method parses the sourceFile (default value is "source_data1.txt"), and
    /// stores the relevant data into a vector of restaurants containing every Restaurant
    /// instance. The vector is then returned.
    ///
    void populateRestaurants();

    ///
    /// \brief loadRestaurantsFromDatabase
    ///
    void loadRestaurantsFromDatabase();

    ///
    /// \brief AuthenticateUser
    /// \param user
    /// \return bool
    ///
    bool authenticateUser(Customer user);

    ///
    /// \brief createRestaurantTable
    /// This method creates and populates a table in the database ("restaurant_data.sqlite")
    ///
    void createRestaurantTable();

    ///
    /// \brief createDistancesTable
    /// This method creates and populates a table in the database ("restaurant_data.sqlite")
    ///
    void createDistancesTable();

    ///
    /// \brief createMenuTable
    /// This method creates and populates a table in the database ("restaurant_data.sqlite")
    ///
    void createMenuTable();

private:
    QSqlDatabase database;
};

#endif // DATABASE_H
