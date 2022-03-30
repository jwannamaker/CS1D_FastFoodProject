#include "databasehelper.h"

///
/// \brief DatabaseHelper::DatabaseHelper
///
DatabaseHelper::DatabaseHelper()
{
    database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("restaurant_data.sqlite");

    if (database.open())
        qDebug() << "Database connection success";
    else
        qDebug() << "Database connection fail";
}

///
/// \brief DatabaseHelper::~DatabaseHelper
///
DatabaseHelper::~DatabaseHelper()
{
    database.close();
    database.removeDatabase("SQLITE");
}

///
/// \brief DatabaseHelper::authenticateUser
///
void DatabaseHelper::authenticateUser()
{
    QSqlQuery query(database);

    //If the users table hasn't been added yet to the database, it will add it and insert a generic login
    if(query.exec("CREATE TABLE users ( Username varchar(255) UNIQUE, Password varchar(255), IsAdmin bool )"))
    {
        query.exec("INSERT INTO users VALUES ('username', 'password', 0)");
        query.exec("INSERT INTO users VALUES ('admin', 'password', 1)");
        query.exec("INSERT INTO users VALUES ('guest', 'password', 0)");
    }

    if(query.exec("SELECT * FROM users"))
        while(query.next())
            if(query.value(0).toString() == CurrentUser.getUsername() && query.value(1).toString() == CurrentUser.getPassword())
            {
                qDebug() << "user is valid";
                CurrentUser.setValid(true);
                CurrentUser.setAdmin(query.value(2).toBool());
            }
}

///
/// \brief updateRestaurantDistances
/// This method updates the distance vectors of the given restaurant.
///
void DatabaseHelper::updateRestaurantDistances(const Restaurant& newRestaurant)
{
    //Iterates through already existing restaurants and adds the distance to new restaurant
    for(Restaurant& oldRestaurant : RestaurantList)
    {
        oldRestaurant.setDistanceAt(newRestaurant.getID(),newRestaurant.getDistance(oldRestaurant.getID()));
    }
}

///
/// \brief DatabaseHelper::addRestaurants
/// \param filename
///
void DatabaseHelper::addRestaurants(QString filename)
{
    QFile file(filename);
    if(file.open(QIODevice::ReadOnly))
    {
        QTextStream inputStream(&file);
        QString line;
        int id;
        double distance;
        double price;
        int numOfMenuItems;
        int numOfResturantDists;
        Restaurant newResturant;

        while(!inputStream.atEnd())
        {
            Menu newMenu;

            //Gets name of the resturant
            line = inputStream.readLine();
            newResturant.setName(line.mid(30));

            //Gets ID of the resturant
            line = inputStream.readLine();
            newResturant.setID(line.remove(QRegularExpression("\\D+")).toInt());

            //Gets number of resturant locations.
            line = inputStream.readLine();
            numOfResturantDists = line.remove(QRegularExpression("\\D+")).toInt();

            std::vector<double> listOfDistances(numOfResturantDists + 1, 0.0);
            for(int index = 1; index <= numOfResturantDists; index++) //Repeat based on the number of resturant locations.
            {
                //Places distances into vector
                inputStream >> id >> distance;
                listOfDistances[index] = distance;
            }
            inputStream.skipWhiteSpace();

            //Sets index[0] of list to dist to saddleback.
            line = inputStream.readLine();
            listOfDistances[0] = line.remove(QRegularExpression("\\s\\D+")).toDouble();

            //Gets number of menu items.
            line = inputStream.readLine();
            numOfMenuItems = line.remove(QRegularExpression("\\D+")).toInt();
            for(int index = 0; index < numOfMenuItems; index++) //Repeat based on the number of menu items.
            {
                //Adds items to the menu
                line = inputStream.readLine();
                inputStream >> price;
                newMenu.push_back(Item(line, price));
                inputStream.skipWhiteSpace();
            }
            newResturant.setMenu(newMenu);
            newResturant.setDistances(listOfDistances);
            inputStream.skipWhiteSpace();

            qDebug() << "new restaurant added: " << newResturant.getName();

            //Adds resturant to general list of resturants
            updateRestaurantDistances(newResturant);
            RestaurantList.push_back(newResturant);
        }
        file.close();
    }
}

///
/// \brief DatabaseHelper::loadRestaurantsFromDatabase
///
void DatabaseHelper::loadRestaurantsFromDatabase()
{
    QSqlQuery queryParent(database);
    QSqlQuery queryDistances(database);
    QSqlQuery queryMenu(database);
    QSqlQuery queryOrder(database);

    if(queryParent.exec("SELECT * FROM parent"))
    {
        while(queryParent.next())
        {
            int restaurantID = queryParent.value(0).toInt();

            if(restaurantID != 0)
            {
                Restaurant newResturant(restaurantID,queryParent.value(1).toString());

                //Fetches distance information for this specific restaurant
                if(queryDistances.exec("SELECT * FROM distances WHERE ParentID = " + QString::number(restaurantID)))
                {
                    //Inserts the distances for the restaurant to other restaurants
                    while(queryDistances.next())
                    {
                        newResturant.setDistanceAt(queryDistances.value(1).toInt(),queryDistances.value(2).toDouble());
                    }
                }

                //Fetches menu item information for this specific restaurant
                if(queryMenu.exec("SELECT * FROM menu WHERE ParentID = " + QString::number(restaurantID)))
                {
                    //Inserts the data about the menu item names/prices for the restaurant
                    while(queryMenu.next())
                    {
                        newResturant.addMenuItem(Item(queryMenu.value(1).toString(), queryMenu.value(2).toDouble()));
                    }
                }

                //Fetches history of orders for this specific restaurant (May not work)
                if(queryOrder.exec("SELECT * FROM orders WHERE ParentID = " + QString::number(restaurantID)))
                {
                    //Places all unique customer usernames into the QVector
                    QVector<QString> customers;
                    while(queryOrder.next())
                    {
                        if(!customers.contains(queryOrder.value(1).toString()))
                        {
                            customers.push_back(queryOrder.value(1).toString());
                        }
                    }

                    //Generate a new order list for this restaurant based on each individual user
                    OrderList newOrderList;
                    for(int index = 0; index < customers.size(); index++)
                    {
                        if(queryOrder.exec("SELECT * FROM orders WHERE ParentID = " + QString::number(restaurantID) +
                                           " AND Username = '" + customers[index] + "'"))
                        {
                            std::vector<Item> orderItems;

                            //Inserts all of the items into the order
                            while(queryOrder.next())
                            {
                                Item newItem(queryOrder.value(2).toString(),queryOrder.value(4).toDouble());
                                newItem.setQuantity(queryOrder.value(3).toInt());

                                orderItems.push_back(newItem);
                            }

                            //Generates order pair and pushes to newOrderList
                            newOrderList.push_back(Order(Customer(customers[index],"unknown"),orderItems));
                        }
                    }

                    //Places all the history of orders into the restaurant and updates revenue
                    newResturant.setOrderList(newOrderList);
                    newResturant.updateRevenue();
                }

                //Inserts new restaurant into the global vector
                //qDebug() << "new restaurant added: " << newResturant.getName();
                RestaurantList.push_back(newResturant);
            }
        }
    }
}

///
/// \brief DatabaseHelper::createRestaurantTable
///
void DatabaseHelper::createRestaurantTable()
{
    QSqlQuery query(database);
    query.exec("CREATE TABLE IF NOT EXISTS parent ( ID int PRIMARY KEY, Name varchar(255) )");

    //Delete contents of parent table
    //query.exec("DELETE FROM parent");

    //Inserts Saddleback as Restaurant index[0]
    query.exec("INSERT INTO parent VALUES ('0', 'Saddleback')");
    for (Restaurant insert : RestaurantList)
        //Inserts Restaurants and their corresponding IDs
        query.exec("INSERT INTO parent VALUES (" + QString::number(insert.getID()) + ", '" +
                                                insert.getName() + "')");
}

///
/// \brief DatabaseHelper::createDistancesTable
///
void DatabaseHelper::createDistancesTable()
{
    QSqlQuery query(database);
    query.exec("CREATE TABLE IF NOT EXISTS distances ( ParentID int, ToID int, Distance numeric, UNIQUE('ParentID', 'ToID', 'Distance'))");

    //Delete contents of distances table
    //query.exec("DELETE FROM distances");

    for (Restaurant insert : RestaurantList)
    {
        //Gets distance to saddleback.
        query.exec("INSERT INTO distances VALUES ("+ QString::number(insert.getID()) +
                                                  ", '0', "+
                                                  QString::number(insert.getDistance(0)) +")");
        //Gets distance to every restaurant.
        for(unsigned int index = 0; index < RestaurantList.size(); index++)
        {
            query.exec("INSERT INTO distances VALUES (" + QString::number(insert.getID()) + ", " +
                                                      QString::number(RestaurantList[index].getID()) + ", " +
                                                      QString::number(insert.getDistance(index + 1)) + ")");
        }
    }
}

///
/// \brief DatabaseHelper::createMenuTable
///
void DatabaseHelper::createMenuTable()
{
    QSqlQuery query(database);
    query.exec("CREATE TABLE IF NOT EXISTS menu ( ParentID int, Name varchar(255), Price numeric, UNIQUE('ParentID', 'Name', 'Price'))");

    //Delete contents of menu table
    query.exec("DELETE FROM menu");

    //Adds contents to menu table
    for (Restaurant insert : RestaurantList)
        for (int index = 0; index < insert.getMenuSize(); index++)
            //Inserts the menu items for each corresponding restaurant
            query.exec("INSERT INTO menu VALUES ("+ QString::number(insert.getID()) +
                       ", '"+ insert.getMenuItem(index).getName() +
                       "', "+ QString::number(insert.getMenuItem(index).getPrice()) +")");
}

///
/// \brief createOrderTable
/// This method creates and populates a table in the database ("restaurant_data.sqlite")
///
void DatabaseHelper::createOrderTable()
{
    QSqlQuery query(database);
    query.exec("CREATE TABLE IF NOT EXISTS orders ( ParentID int, Username varchar(255), Itemname varchar(255), Quantity int, Price numeric )");

    //Delete contents of orders table
    query.exec("DELETE FROM orders");


    //Iterates through each restaurant in the global vector
    for (const Restaurant& insert : RestaurantList)
    {
        //Gets each order from the restaurant
        for(const Order& order : insert.getOrderList())
        {
            //Iterates through the menu items of a corresponding order.
            for(const Item& item : order.second)
            {
                //Inserts the items for each order
                query.exec("INSERT INTO orders VALUES ("+ QString::number(insert.getID()) +
                           ", '"+ order.first.getUsername() +
                           "', '"+ item.getName() +
                           "', " + QString::number(item.getQuantity()) +
                           ", " + QString::number(item.getPrice()) + ")");
            }
        }
    }
}
