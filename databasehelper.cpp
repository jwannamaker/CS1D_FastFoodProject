#include "databasehelper.h"
#include "header.h"

// linking usage of globals
extern std::vector<Restaurant*> Restaurants;

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

void DatabaseHelper::loadRestaurantsFromDatabase()
{
    //This function will populate the static restaurant vector.
    //Note: Ignore id 0 of table parent when inserting restaurants into the
    //vector since it isn't technically a restaurant.
}

void DatabaseHelper::authenticateUser(Customer& user)
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
                user.setValid(true);
                user.setAdmin(query.value(2).toBool());
            }
}

void DatabaseHelper::updateRestaurantDistances(const Restaurant& newRestaurant)
{

}

void DatabaseHelper::addRestaurants(QString filename)
{
    QFile file(filename);
    if(file.open(QIODevice::ReadOnly))
    {
        QTextStream inputStream(&file);
        while(!inputStream.atEnd())
        {
            QString name = inputStream.readLine().mid(30);
            int     ID   = inputStream.readLine().remove(QRegularExpression("\\D+")).toInt();
            Restaurant* newRestaurant = new Restaurant(ID, name);

            std::vector<double> distances = std::vector<double>();
            distances.resize(inputStream.readLine().remove(QRegularExpression("\\D+")).toInt() + 1);
            for(unsigned int index = 1; index <= distances.size(); index++)
                inputStream >> ID >> distances[index];

            inputStream.skipWhiteSpace();
            distances[0] = inputStream.readLine().remove(QRegularExpression("\\s\\D+")).toDouble();

            int menuSize = inputStream.readLine().remove(QRegularExpression("\\D+")).toInt();
            for(int index = 0; index < menuSize; index++)
            {
                QString *item, *price;
                inputStream.readLineInto(item);
                inputStream.readLineInto(price);
                newRestaurant->addMenuItem(new Item(*item, price->toDouble()));
            }
            inputStream.skipWhiteSpace();

            Restaurants.push_back(newRestaurant);
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
    for (const Restaurant* insert : Restaurants)
        //Inserts Restaurants and their corresponding IDs
        query.exec("INSERT INTO parent VALUES (" + QString::number(insert->getID()) + ", '" +
                                                insert->getName() + "')");
}

void DatabaseHelper::createDistancesTable()
{
    QSqlQuery query(database);
    query.exec("CREATE TABLE IF NOT EXISTS distances ( ParentID int, ToID int, Distance numeric, UNIQUE('ParentID', 'ToID', 'Distance'))");

    for (const Restaurant* insert : Restaurants)
    {
        //Gets distance to saddleback.
        query.exec("INSERT INTO distances VALUES ("+ QString::number(insert->getID()) +
                                                  ", '0', "+
                                                  QString::number(insert->getDistance(0)) +")");
        //Gets distance to every restaurant.
        for(unsigned int index = 0; index < Restaurants.size(); index++)
        {
            query.exec("INSERT INTO distances VALUES (" + QString::number(insert->getID()) + ", " +
                                                      QString::number(Restaurants[index]->getID()) + ", " +
                                                      QString::number(insert->getDistance(index + 1)) + ")");
        }
    }
}

void DatabaseHelper::createMenuTable()
{
    QSqlQuery query(database);
    query.exec("CREATE TABLE IF NOT EXISTS menu ( ParentID int, Name varchar(255), Price numeric, UNIQUE('ParentID', 'Name', 'Price'))");

    for (Restaurant* insert : Restaurants)
        for (int index = 0; index < insert->getMenuSize(); index++)
            //Inserts the menu items for each corresponding restaurant
            query.exec("INSERT INTO menu VALUES ("+ QString::number(insert->getID()) +
                       ", '"+ insert->getMenuItem(index)->getName() +
                       "', "+ QString::number(insert->getMenuItem(index)->getPrice()) +")");
}
