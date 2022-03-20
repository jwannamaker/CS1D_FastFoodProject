#include "databasehelper.h"

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

/*
void DatabaseHelper::populateRestaurants()
{
    QFile file(":data/source_data1.txt");
    if(file.open(QIODevice::ReadOnly))
    {
        QTextStream inputStream(&file);
        QString line;
        int index = 0;
        int ID = 0;
        double distance = 0;
        double price = 0;

        while(!inputStream.atEnd())
        {
            Restaurant::list.resize(index + 1);
            Restaurant::list.push_back(Restaurant());

            line = inputStream.readLine();//Gets name of the resturant
            Restaurant::list.at(index).setName(line.mid(30));

            line = inputStream.readLine();//Gets ID of the resturant
            Restaurant::list.at(index).setID(line.remove(QRegularExpression("\\D+")).toInt());

            //Gets number of resturant locations.
            line = inputStream.readLine();
            int numRestaurants = line.remove(QRegularExpression("\\D+")).toInt();

            std::vector<double> distances(numRestaurants + 1, 0.0);
            for(unsigned int index = 1; index <= distances.size(); index++) //Repeat based on the number of resturant locations.
            {
                inputStream >> ID >> distance;
                Restaurant::list.at(index).addDistance(ID + 1, distance);
            }
            inputStream.skipWhiteSpace();

            line = inputStream.readLine();//Sets index[0] of distances list to distance to saddleback.
            Restaurant::list.at(index).addDistance(0, line.remove(QRegularExpression("\\s\\D+")).toDouble());

            line = inputStream.readLine();//Gets number of menu items.
            for(int index = 0; index < line.remove(QRegularExpression("\\D+")).toInt(); index++) //Repeat based on the number of menu items.
            {
                //Adds items to the menu
                line = inputStream.readLine();
                inputStream >> price;
                Restaurant::list.at(index).addMenuItem(new Item(line,price));
                inputStream.skipWhiteSpace();
            }
            inputStream.skipWhiteSpace();

            index++;
        }
        file.close();
    }
}
*/


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
            //Gets name of the resturant
            line = inputStream.readLine();
            newRestaurant.setName(line.mid(30));

            //Gets ID of the resturant
            line = inputStream.readLine();
            newRestaurant.setID(line.remove(QRegularExpression("\\D+")).toInt());

            //Gets number of resturant locations.
            line = inputStream.readLine();
            numOfResturantDists = line.remove(QRegularExpression("\\D+")).toInt();
            for(int index = 1; index <= numOfResturantDists; index++) //Repeat based on the number of resturant locations.
            {
                //Places distances into vector
                inputStream >> id >> distance;
                newRestaurant.addDistance(id + 1, distance);
            }
            inputStream.skipWhiteSpace();

            //Sets index[0] of list to dist to saddleback.
            line = inputStream.readLine();
            newRestaurant.addDistance(0, line.remove(QRegularExpression("\\s\\D+")).toDouble());

            //Gets number of menu items.
            line = inputStream.readLine();
            numOfMenuItems = line.remove(QRegularExpression("\\D+")).toInt();
            for(int index = 0; index < numOfMenuItems; index++) //Repeat based on the number of menu items.
            {
                //Adds items to the menu
                line = inputStream.readLine();
                inputStream >> price;
                newRestaurant.addMenuItem(new Item(line, price));
                inputStream.skipWhiteSpace();
            }
            inputStream.skipWhiteSpace();

            //Adds resturant to general list of resturants
            restaurantList.push_back(newRestaurant);
        }
        file.close();
    }

    Restaurant::list = restaurantList;
}


void DatabaseHelper::loadRestaurantsFromDatabase()
{
    //This function will populate the static restaurant vector.
    //Note: Ignore id 0 of table parent when inserting restaurants into the
    //vector since it isn't technically a restaurant.
}

bool DatabaseHelper::authenticateUser(Customer user)
{
    QSqlQuery query(database);

    //If the users table hasn't been added yet to the database, it will add it and insert a generic login
    if(query.exec("CREATE TABLE IF NOT EXISTS users ( Username varchar(255) UNIQUE, Password varchar(255) )"))
        query.exec("INSERT INTO users VALUES ('username', 'password')");

    if(query.exec("SELECT * FROM users"))
        while(query.next())
            if(query.value(0).toString() == user.getUsername() && query.value(1).toString() == user.getPassword())
                return true;

    return false;
}

void DatabaseHelper::createRestaurantTable()
{
    QSqlQuery query(database);
    query.exec("CREATE TABLE IF NOT EXISTS parent ( ID int PRIMARY KEY, Name varchar(255) )");

    //Inserts Saddleback as Restaurant index[0]
    query.exec("INSERT INTO parent VALUES ('0', 'Saddleback')");
    for (const Restaurant& insert : Restaurant::list)
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

    for (const Restaurant& insert : Restaurant::list)
    {
        //Gets distance to saddleback.
        query.exec("INSERT INTO distances VALUES ("+ QString::number(insert.getID()) +
                                                  ", '0', "+
                                                  QString::number(insert.getDistance(0)) +")");
        //Gets distance to every restaurant.
        for(unsigned int index = 0; index < Restaurant::list.size(); index++)
        {
            query.exec("INSERT INTO distances VALUES (" + QString::number(insert.getID()) + ", " +
                                                      QString::number(Restaurant::list.at(index).getID()) + ", " +
                                                      QString::number(insert.getDistance(index+1)) + ")");
        }
    }
}

void DatabaseHelper::createMenuTable()
{
    QSqlQuery query(database);
    query.exec("CREATE TABLE IF NOT EXISTS menu ( ParentID int, Name varchar(255), Price numeric, UNIQUE('ParentID', 'Name', 'Price'))");

    for (Restaurant insert : Restaurant::list)
    {
        for (int index = 0; index < insert.getMenuSize(); index++)
        {
            //Inserts the menu items for each corresponding restaurant
            query.exec("INSERT INTO menu VALUES ("+ QString::number(insert.getID()) +
                       ", '"+ insert.getMenuItem(index)->getName() +
                       "', "+ QString::number(insert.getMenuItem(index)->getPrice()) +")");
        }
    }
}
