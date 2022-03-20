#include "databasehelper.h"

std::vector<Restaurant> globalRestaurantList;

DatabaseHelper::DatabaseHelper()
{
    database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("restaurant_data.sqlite");

    if(database.open())
        qDebug() << "Opened database Successfully";
    else
        qDebug() << "Did not open database successfully";
}

DatabaseHelper::~DatabaseHelper()
{
    database.close();
    database.removeDatabase("SQLITE");
}

void DatabaseHelper::populateRestaurants()
{
    QFile file(":data/source_data1.txt");
    std::vector<Restaurant> restaurantList;

    if(file.open(QIODevice::ReadOnly))
    {
        QTextStream inputStream(&file);
        QString line;
        int id;
        double distance,price;
        int numOfMenuItems,numOfResturantDists;
        Restaurant newRestaurant;

        while(!inputStream.atEnd())
        {
            Menu newMenu;

            //Gets name of the resturant
            line = inputStream.readLine();
            newRestaurant.setName(line.mid(30));

            //Gets ID of the resturant
            line = inputStream.readLine();
            newRestaurant.setID(line.remove(QRegularExpression("\\D+")).toInt());

            //Gets number of resturant locations.
            line = inputStream.readLine();
            numOfResturantDists = line.remove(QRegularExpression("\\D+")).toInt();

            std::vector<double> listOfDistances(numOfResturantDists+1,0.0);
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
                newMenu.addItem(Menu::Item(line,price));
                inputStream.skipWhiteSpace();
            }
            newRestaurant.setMenu(newMenu);
            newRestaurant.setDistances(listOfDistances);
            inputStream.skipWhiteSpace();

            //Adds resturant to general list of resturants
            restaurantList.push_back(newRestaurant);
        }
        file.close();
    }
    globalRestaurantList.resize(restaurantList.size());
    globalRestaurantList = std::vector<Restaurant>(restaurantList);
}

void DatabaseHelper::loadRestaurantsFromDatabase()
{
    //This function will populate the static restaurant vector.
    //Note: Ignore id 0 of table parent when inserting restaurants into the
    //vector since it isn't technically a restaurant.
}

bool DatabaseHelper::authenticateUser(Customer& user)
{
    QSqlQuery query(database);

    //If the users table hasn't been added yet to the database, it will add it and insert a generic login
    if(query.exec("CREATE TABLE IF NOT EXISTS users ( Username varchar(255) UNIQUE, Password varchar(255), IsAdmin bool )"))
    {
        query.exec("INSERT INTO users VALUES ('username', 'password', 1)");
        query.exec("INSERT INTO users VALUES ('nonadmin', 'password', 0)");
    }

    if(query.exec("SELECT * FROM users"))
        while(query.next())
            if(query.value(0).toString() == user.getUsername() && query.value(1).toString() == user.getPassword())
            {
                user.setAdmin(query.value(2).toBool());
                return true;
            }

    return false;
}

void DatabaseHelper::updateRestaurantDistances(const Restaurant& newRestaurant)
{

    //Iterates through already existing restaurants and adds the distance to new restaurant
    for(Restaurant& oldRestaurant : globalRestaurantList)
    {
        oldRestaurant.setDistanceAt(newRestaurant.getID(),newRestaurant.getDistance(oldRestaurant.getID()));
    }
}

void DatabaseHelper::addRestaurants(QString filename)
{
    QFile file(filename);

    if(file.open(QIODevice::ReadOnly))
    {
        QTextStream inputStream(&file);
        QString line;
        int id;
        double distance,price;
        int numOfMenuItems,numOfResturantDists;
        Restaurant newRestaurant;

        while(!inputStream.atEnd())
        {
            Menu newMenu;

            //Gets name of the resturant
            line = inputStream.readLine();
            newRestaurant.setName(line.mid(30));

            //Gets ID of the resturant
            line = inputStream.readLine();
            newRestaurant.setID(line.remove(QRegularExpression("\\D+")).toInt());

            //Gets number of resturant locations.
            line = inputStream.readLine();
            numOfResturantDists = line.remove(QRegularExpression("\\D+")).toInt();

            std::vector<double> listOfDistances(numOfResturantDists+1,0.0);
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
                newMenu.addItem(Menu::Item(line,price));
                inputStream.skipWhiteSpace();
            }
            newRestaurant.setMenu(newMenu);
            newRestaurant.setDistances(listOfDistances);
            inputStream.skipWhiteSpace();

            //Adds resturant to general list of resturants
            updateRestaurantDistances(newRestaurant);
            globalRestaurantList.push_back(newRestaurant);
        }
        file.close();
    }
}

void DatabaseHelper::createRestaurantTable()
{
    QSqlQuery query(database);
    query.exec("CREATE TABLE IF NOT EXISTS parent ( ID int PRIMARY KEY, Name varchar(255) )");

    //Inserts Saddleback as Restaurant index[0]
    query.exec("INSERT INTO parent VALUES ('0', 'Saddleback')");
    for (const Restaurant& insert : globalRestaurantList)
    {
        //Inserts Restaurants and their corresponding IDs
        query.exec("INSERT INTO parent VALUES (" + QString::number(insert.getID()) + ", '" +
                                                insert.getName() + "')");
    }
}

void DatabaseHelper::createDistancesTable()
{
    QSqlQuery query(database);
    query.exec("CREATE TABLE IF NOT EXISTS distances ( ParentID int, ToID int, Distance numeric, UNIQUE('ParentID', 'ToID', 'Distance'))");

    for (const Restaurant& insert : globalRestaurantList)
    {
        //Gets distance to saddleback.
        query.exec("INSERT INTO distances VALUES ("+ QString::number(insert.getID()) +
                                                  ", '0', "+
                                                  QString::number(insert.getDistance(0)) +")");
        //Gets distance to every restaurant.
        for(unsigned int index = 0; index < globalRestaurantList.size(); index++)
        {
            query.exec("INSERT INTO distances VALUES (" + QString::number(insert.getID()) + ", " +
                                                      QString::number(globalRestaurantList.at(index).getID()) + ", " +
                                                      QString::number(insert.getDistance(index+1)) + ")");
        }
    }
}

void DatabaseHelper::createMenuTable()
{
    QSqlQuery query(database);
    query.exec("CREATE TABLE IF NOT EXISTS menu ( ParentID int, Name varchar(255), Price numeric, UNIQUE('ParentID', 'Name', 'Price'))");

    for (const Restaurant& insert : globalRestaurantList)
    {
        Menu readMenu = insert.getMenu();
        for (unsigned int index = 0; index < readMenu.getItems().size(); index++)
        {
            //Inserts the menu items for each corresponding restaurant
            query.exec("INSERT INTO menu VALUES ("+ QString::number(insert.getID()) +
                       ", '"+ readMenu.getItems().at(index).getName() +
                       "', "+ QString::number(readMenu.getItems().at(index).getPrice()) +")");
        }
    }
}
