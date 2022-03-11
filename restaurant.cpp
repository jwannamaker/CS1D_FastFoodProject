#include "restaurant.h"

// Allocating the memory for a vector of Restaurant objects
//DatabaseHelper dbHelper = DatabaseHelper();
//std::vector<Restaurant> Restaurant::list = dbHelper.populateRestaurants();

Restaurant::Restaurant()
{
//    Restaurant::list.push_back(*this);
    this->revenue = 0.0;
}

Restaurant::Restaurant(int ID, QString name)
{
    this->ID = ID;
    this->name = name;
    this->revenue = 0.0;
//    Restaurant::list.push_back(*this);
}

void Restaurant::setName(QString name)
{
   this->name = name;
}

void Restaurant::setID(int ID)
{
   this->ID = ID;
}

void Restaurant::setDistances(std::vector<double> distances)
{
   this->distances = distances;
}

double Restaurant::getDistance(const Restaurant& other) const
{
    double distance;
    if(int(distances.size()) <= other.getID())
    {
        distance = other.getDistance(this->ID);
    }
    else
    {
        distance = distances.at(other.getID());
    }
    return distance;
}

double Restaurant::getDistance(int otherID) const
{
    //Warning: This method can only be called if the vector of distances of the current
    //restaurant includes the distance to the other restaurant.
    return distances.at(otherID);
}

void Restaurant::setMenu(Menu menu)
{
    this->menu = menu;
}

int Restaurant::getID() const
{
    return ID;
}

Menu Restaurant::getMenu() const
{
    return menu;
}

QString Restaurant::getName() const
{
   return name;
}

void Restaurant::setRevenue(double revenue)
{
    this->revenue = revenue;
}

double Restaurant::getRevenue() const
{
    return revenue;
}
