#ifndef DATABASE_H
#define DATABASE_H

#include <QFile>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QtSql>
#include "customer.h"
#include "restaurant.h"

// linking globals
extern Customer CurrentUser;
extern std::vector<Restaurant> RestaurantList;

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
    /// \brief authenticateUser
    ///
    void authenticateUser();

    ///
    /// \brief updateRestaurantDistances
    /// This method updates the distance vectors of the given restaurant.
    ///
    void updateRestaurantDistances(const Restaurant& newRestaurant);

    ///
    /// \brief addRestaurants
    /// This method parses the source file specified by filename, and stores the relevant
    /// data into the global vector of restaurants.
    ///
    void addRestaurants(QString filename = ":data/source_data1.txt");

    ///
    /// \brief loadRestaurantsFromDatabase
    ///
    void loadRestaurantsFromDatabase();

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

    ///
    /// \brief createOrderTable
    /// This method creates and populates a table in the database ("restaurant_data.sqlite")
    ///
    void createOrderTable();
private:
    QSqlDatabase database;
};

#endif // DATABASE_H
