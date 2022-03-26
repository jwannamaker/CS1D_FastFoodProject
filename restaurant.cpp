#include "restaurant.h"

///
/// \brief Restaurant::Restaurant
///
Restaurant::Restaurant()
{
    ID = 0;
    name = "empty";
    distances = std::vector<double>();
    menu = Menu();
    orders = OrderList();
    revenue = 0;
}

///
/// \brief Restaurant::Restaurant
/// \param ID
/// \param name
///
Restaurant::Restaurant(int ID, QString name)
{
    this->ID = ID;
    this->name = name;
    distances = std::vector<double>();
    menu = Menu();
    orders = OrderList();
    revenue = 0;
}

///
/// \brief Restaurant::setName
/// \param name
///
void Restaurant::setName(QString name)
{
   this->name = name;
}

///
/// \brief Restaurant::getName
/// \return
///
QString Restaurant::getName() const
{
   return name;
}

///
/// \brief Restaurant::setID
/// \param ID
///
void Restaurant::setID(int ID)
{
   this->ID = ID;
}

///
/// \brief Restaurant::getID
/// \return
///
int Restaurant::getID() const
{
    return ID;
}

///
/// \brief Restaurant::setDistances
/// \param distances
///
void Restaurant::setDistances(const std::vector<double>& distances)
{
   this->distances = distances;
}

///
/// \brief Restaurant::addDistance
/// \param otherID
/// \param distance
///
void Restaurant::addDistance(int otherID, double distance)
{
    distances.insert(distances.begin() + otherID, distance);
}

///
/// \brief Restaurant::getDistance
/// \param other
/// \return
///
double Restaurant::getDistance(const Restaurant& other) const
{
    if(int(distances.size()) <= other.getID())
        return other.getDistance(ID);
    else
        return distances.at(other.getID());
}

///
/// \brief Restaurant::getDistance
/// \param otherID
/// \return
///
double Restaurant::getDistance(int otherID) const
{
    //Warning: This method can only be called if the vector of distances of the current
    //restaurant includes the distance to the other restaurant.
    assert(otherID <= distances.size());
    return distances.at(otherID);
}

///
/// \brief Restaurant::getShortestDistanceID
/// \return
///
int Restaurant::getShortestDistanceID() const
{
    double shortestDistance = 100;
    int shortestID = -1;

    for (int otherID = 0; otherID < RestaurantList.size(); otherID++)
        if (getDistance(otherID) < shortestDistance)
        {
            shortestDistance = getDistance(otherID);
            shortestID = otherID;
        }

    return shortestID;
}

///
/// \brief Restaurant::getClosestRestaurant
/// \return
///
Restaurant &Restaurant::getClosestRestaurant()
{
    return RestaurantList[getShortestDistanceID()];
}

///
/// \brief Restaurant::setMenu
/// \param menu
///
void Restaurant::setMenu(Menu menu)
{
    this->menu = menu;
}

///
/// \brief Restaurant::addMenuItem
/// \param newItem
///
void Restaurant::addMenuItem(Item newItem)
{
    menu.push_back(newItem);
}

///
/// \brief Restaurant::getMenuSize
/// \return
///
int Restaurant::getMenuSize() const
{
    return menu.size();
}

///
/// \brief Restaurant::getMenuItem
/// \param index
/// \return
///
Item& Restaurant::getMenuItem(int index)
{
    // warning: must pass a valid index
    return menu.at(index);
}

///
/// \brief Restaurant::addOrder
/// \param newOrder
///
void Restaurant::addOrder(std::vector<Item> newOrder)
{
    orders.push_back(newOrder);
    updateRevenue();
}

///
/// \brief Restaurant::setRevenue
/// \param revenue
///
void Restaurant::setRevenue(double revenue)
{
    this->revenue = revenue;
}

///
/// \brief Restaurant::addRevenue
/// \param revenue
///
void Restaurant::addRevenue(double revenue)
{
    this->revenue += revenue;
}

///
/// \brief Restaurant::updateRevenue
///
void Restaurant::updateRevenue()
{
    for (int i = 0; i < orders.size(); i++)
        for (int j = 0; j < orders[i].size(); j++)
            revenue += orders[i][j].getPrice() * orders[i][j].getQuantity();
}

///
/// \brief Restaurant::getRevenue
/// \return
///
double Restaurant::getRevenue() const
{
    return revenue;
}
