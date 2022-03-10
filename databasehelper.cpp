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
                newMenu.addItem(Item(line,price));
                inputStream.skipWhiteSpace();
            }
            newResturant.setMenu(newMenu);
            newResturant.setDistances(listOfDistances);
            inputStream.skipWhiteSpace();

            //Adds resturant to general list of resturants
            restaurantList.push_back(newResturant);
        }
        file.close();
    }
    Restaurant::list.resize(10);
    Restaurant::list = std::vector<Restaurant>(restaurantList);
}

void DatabaseHelper::loadRestaurantsFromDatabase()
{
    //This function will populate the static restaurant vector.
    //Note: Ignore id 0 of table parent when inserting restaurants into the
    //vector since it isn't technically a restaurant.
}

bool DatabaseHelper::AuthenticateUser(QString username, QString password)
{
    bool validUser = false;
    QSqlQuery query(database);

    //If the users table hasn't been added yet to the database, it will add it and insert a generic login
    if(query.exec("CREATE TABLE IF NOT EXISTS users ( Username varchar(255), Password varchar(255), UNIQUE('Username') )"))
    {
        //Generic login information: username, password.
        query.exec("INSERT INTO users VALUES ('username', 'password')");
    }

    if(query.exec("SELECT Username, Password FROM users"))
    {
        while(query.next() && !validUser)
        {
            if(query.value(0).toString() == username && query.value(1).toString() == password)
            {
                validUser = true;
            }
        }
    }

    return validUser;
}

void DatabaseHelper::createRestaurantTable(const std::vector<Restaurant> &restaurantList)
{
    QSqlQuery query(database);
    query.exec("CREATE TABLE IF NOT EXISTS parent ( ID int PRIMARY KEY, Name varchar(255) )");

    //Inserts Saddleback as Restaurant index[0]
    query.exec("INSERT INTO parent VALUES ('0', 'Saddleback')");
    for (const Restaurant& insert : restaurantList)
    {
        //Inserts Restaurants and their corresponding IDs
        query.exec("INSERT INTO parent VALUES ("+ QString::number(insert.getID()) +", '"+
                                                insert.getName() +"')");
    }
}

void DatabaseHelper::createDistancesTable(const std::vector<Restaurant> &restaurantList)
{
    QSqlQuery query(database);
    query.exec("CREATE TABLE IF NOT EXISTS distances ( ParentID int, ToID int, Distance numeric, UNIQUE('ParentID','ToID','Distance'))");

    for (const Restaurant& insert : restaurantList)
    {
        //Gets distance to saddleback.
        query.exec("INSERT INTO distances VALUES ("+ QString::number(insert.getID()) +
                                                  ", '0', "+
                                                  QString::number(insert.getDistance(0)) +")");
        //Gets distance to every restaurant.
        for(unsigned int index = 0; index < restaurantList.size(); index++)
        {
            query.exec("INSERT INTO distances VALUES ("+ QString::number(insert.getID()) +
                                                      ", "+ QString::number(restaurantList.at(index).getID()) +
                                                      ", "+ QString::number(insert.getDistance(index+1)) +")");
        }
    }
}

void DatabaseHelper::createMenuTable(const std::vector<Restaurant> &restaurantList)
{
    QSqlQuery query(database);
    query.exec("CREATE TABLE IF NOT EXISTS menu ( ParentID int, Name varchar(255), Price numeric, UNIQUE('ParentID','Name','Price'))");

    for (const Restaurant& insert: restaurantList)
    {
        Menu readMenu = insert.getMenu();
        for (unsigned int index = 0; index < readMenu.getItems().size(); index++)
        {
            //Inserts the menu items for each corresponding restaurant
            query.exec("INSERT INTO menu VALUES ("+ QString::number(insert.getID()) +
                       ", '"+ readMenu.getItems()->at(index).getName() +
                       "', "+ QString::number(readMenu.getItems()->at(index).getPrice())  +")");
        }
    }
}
