#include "restaurant.h"

Restaurant::Restaurant()
{
    //Restuarant::list.push_back(this);
}

Restaurant::Restaurant(int ID, QString name)
 {
    this->ID = ID;
    this->name = name;
    //Restaurant::list.push_back(this);
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

// allocating the memory
std::vector<Restaurant> Restaurant::list;
