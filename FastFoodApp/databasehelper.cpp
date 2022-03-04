#include "databasehelper.h"

DatabaseHelper::DatabaseHelper()
{
    QString databasePath = "restaurant_data.sqlite";
    database = QSqlDatabase::addDatabase("QSQLITE");
	database.setDatabaseName(databasePath);
	if(database.open())
	{
        qDebug() << "Opened database Successfully";
	}
	else
	{
        qDebug() << "Did not open database successfully";
	}

    sourceFile = "source_data1.txt";
} 


DatabaseHelper::~DatabaseHelper()
{
	database.close();
    database.removeDatabase("SQLITE");
}

void DatabaseHelper::setSourceFile(QString sourceFile)
{
    this->sourceFile = sourceFile;
}


void DatabaseHelper::populateRestaurants()
{
	QFile file(sourceFile);
    if(file.open(QIODevice::ReadOnly | QIODevice::Text))
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
                newMenu.addItem(Menu::Item(line,price));
                inputStream.skipWhiteSpace();
            }
            newResturant.setMenu(newMenu);
            newResturant.setDistances(listOfDistances);
            inputStream.skipWhiteSpace();

            //Adds resturant to general list of resturants
            Restaurant::list.push_back(newResturant);
        }

        file.close();
    }
}


void DatabaseHelper::createRestaurantTable()
{
    QSqlQuery query(database);
    query.exec("CREATE TABLE IF NOT EXISTS parent ( ID int PRIMARY KEY, Name varchar(255) )");

    query.exec("INSERT INTO parent VALUES ('0', 'Saddleback')");
    for (Restaurant& insert : Restaurant::list)
	{
        query.exec("INSERT INTO parent VALUES ("+ QString::number(insert.getID()) +", '"+
                                                insert.getName() +"')");
	}
}

void DatabaseHelper::createDistancesTable()
{ 
    QSqlQuery query(database);
    query.exec("CREATE TABLE IF NOT EXISTS distances ( ParentID int, ToID int, Distance numeric, UNIQUE('ParentID','ToID','Distance'))");
    query.exec("INSERT INTO distances VALUES ('0', '0', '0')");

    for (Restaurant& insert: Restaurant::list)
    {
        //Gets distance to saddleback.
        query.exec("INSERT INTO distances VALUES ("+ QString::number(insert.getID()) +
                                                  ", '0', "+
                                                  QString::number(insert.getDistance(0)) +")");
        //Gets distance to every restaurant.
        for(unsigned int index = 0; index < Restaurant::list.size(); index++)
        {
            query.exec("INSERT INTO distances VALUES ("+ QString::number(insert.getID()) +
                                                      ", "+ QString::number(Restaurant::list.at(index).getID()) +
                                                      ", "+ QString::number(insert.getDistance(index+1)) +")");
        }
    }
    
}


void DatabaseHelper::createMenuTable()
{
    QSqlQuery query(database);
    query.exec("CREATE TABLE IF NOT EXISTS menu ( ParentID int, Name varchar(255), Price numeric, UNIQUE('ParentID','Name','Price'))");
    for (Restaurant& insert: Restaurant::list)
    {
        Menu readMenu = insert.getMenu();
        for (unsigned int index = 0; index < readMenu.getItems()->size(); index++)
        {
            query.exec("INSERT INTO menu VALUES ("+ QString::number(insert.getID()) +
                       ", '"+ readMenu.getItems()->at(index).name +
                       "', "+ QString::number(readMenu.getItems()->at(index).price)  +")");
        }
    }
}

