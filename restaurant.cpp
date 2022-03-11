#include "restaurant.h"

// Allocating the memory for a vector of Restaurant objects
std::vector<Restaurant> Restaurant::list = std::vector<Restaurant>();

Restaurant::Restaurant()
{
    Restaurant::list.push_back(*this);
}

Restaurant::Restaurant(int ID, QString name)
{
    this->ID = ID;
    this->name = name;
    Restaurant::list.push_back(*this);
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
    if(int(distances.size()) <= other.getID())
        return other.getDistance(ID);
    else
        return distances.at(other.getID());
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
