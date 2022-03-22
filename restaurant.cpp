#include "restaurant.h"

Restaurant::Restaurant()
{
    menu = Menu();
    orders = OrderList();
}

Restaurant::Restaurant(int ID, QString name)
{
    this->ID = ID;
    this->name = name;
}

void Restaurant::setName(QString name)
{
   this->name = name;
}

QString Restaurant::getName() const
{
   return name;
}

void Restaurant::setID(int ID)
{
   this->ID = ID;
}

int Restaurant::getID() const
{
    return ID;
}

void Restaurant::setDistances(const std::vector<double>& distances)
{
   this->distances = distances;
}

void Restaurant::addDistance(int otherID, double distance)
{
    distances.insert(distances.begin() + otherID, distance);
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

void Restaurant::addMenuItem(Item newItem)
{
    menu.push_back(newItem);
}

int Restaurant::getMenuSize() const
{
    return menu.size();
}

Item& Restaurant::getMenuItem(int index)
{
    // warning: must pass a valid index
    return menu.at(index);
}

void Restaurant::setRevenue(double revenue)
{
    this->revenue = revenue;
}

void Restaurant::addRevenue(double revenue)
{
    this->revenue += revenue;
}

double Restaurant::getRevenue() const
{
    return revenue;
}