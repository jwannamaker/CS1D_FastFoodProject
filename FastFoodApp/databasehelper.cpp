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
    if(file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QTextStream inputStream(&file);
        QString line;
        int id;
        double distance,price;
        int numOfMenuItems,numOfResturantDists;
        Restaurant newResturant;
        //Menu newMenu;
        //std::vector<double> listOfDistances;
        //Item newItem;


        while(!inputStream.atEnd())
        {
            line = inputStream.readLine();
            newResturant.setName(line.mid(30)); //Gets name of the resturant

            line = inputStream.readLine();
            newResturant.setID(line.remove(QRegularExpression("\\D+")).toInt()); //Sets number of resturant

            line = inputStream.readLine();
            numOfResturantDists = line.remove(QRegularExpression("\\D+")).toInt(); //Gets number of resturant locations.
            //listOfDistances.reserve(numOfResturantDists+1);
            for(int index = 1; index <= numOfResturantDists; index++) //Repeat based on the number of resturant locations.
            {
                inputStream >> id >> distance;
                //listOfDistances[index] = distance;
            }
            inputStream.skipWhiteSpace();

            line = inputStream.readLine();
            //listOfDistances[0] = line.remove(QRegularExpression("\\s\\D+")).toDouble(); //Sets index0 of list to dist to saddleback.

            line = inputStream.readLine();
            numOfMenuItems = line.remove(QRegularExpression("\\D+")).toInt(); //Gets number of menu items.
            for(int index = 0; index < numOfMenuItems; index++) //Repeat based on the number of menu items.
            {
                line = inputStream.readLine();
                inputStream >> price;
                //newItem.name = line;
                //newItem.price = price;
                //newMenu.addItem(newItem);
                inputStream.skipWhiteSpace();
            }
            //newResturant.setMenu(newMenu);
            //newResturant.setDistances(listOfDistances);
            inputStream.skipWhiteSpace();

            Restaurant::list.push_back(newResturant); //Adds resturant to general list of resturants
        }

        file.close();
    }
}


void DatabaseHelper::createRestaurantTable()
{
    QSqlQuery query(database);
    query.exec("CREATE TABLE IF NOT EXISTS parent ( ID int PRIMARY KEY, Name varchar(255) )");

	for (Restaurant insert : Restaurant::list)
	{
        query.exec("INSERT INTO parent VALUES ("+ QString::number(insert.getID()) +", '"+
                                                insert.getName() +"')");
	}
}

void DatabaseHelper::createDistancesTable()
{
    /* 
    QSqlQuery query(database);
    query.exec(CREATE TABLE IF NOT EXISTS distances (ParentID int FOREIGN KEY, ToID int, Distance double));

    for (Restaurant insert: Restaurant::list)
    {
        //Gets distance to saddleback.
        query.exec("INSERT INTO distances VALUES ("+ QString::number(insert.getID()) +
                                                  ", '0', "+
                                                  QString::number(insert.getDistance(Restaurant::list[0])) +")");
        //Gets distance to every restaurant.
        for(int index = 0; index < Restaurant::list.size(); index++) 
        {
            query.exec("INSERT INTO distances VALUES ("+ QString::number(insert.getID()) +
                                                      ", "+ QString::number(Restaurant::list[index].getID()) +
                                                      ", "+ QString::number(insert.getDistance(Restaurant::list[index])) +")");
        }
    }
    
    */
}

/*
void DatabaseHelper::createMenuTable()
{

    QSqlQuery query(database);
    query.exec("CREATE TABLE IF NOT EXISTS menu ( ParentID int FOREIGN KEY, Name varchar(255), Price double )");

    for (int index = 0; index < restaurants.size(); index++)
    {
        Menu readMenu = restaurants[index].GetMenu();
        for (int index2 = 0; index2++ < readMenu.size(); index2++)
        {
            query.exec("INSERT INTO menu VALUES ("+ restaurants[index].getID() +", '"+ readMenu.getItems()->at(index2).name +"', "+ QString::number(readMenu.getItems()->at(index2).price)  +")");
        }
    }
}
*/
