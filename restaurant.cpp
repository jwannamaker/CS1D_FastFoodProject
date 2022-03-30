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

    for (unsigned int otherID = 0; otherID < RestaurantList.size(); otherID++)
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
/// \param orderItems
///
void Restaurant::addOrder(std::vector<Item> orderItems)
{
    Order newOrder = Order(CurrentUser, orderItems);
    orders.push_back(newOrder);
    updateRevenue();
}

///
/// \brief Restaurant::getLastOrder
/// \return
///
std::vector<Item> &Restaurant::getCurrentOrder()
{
    // find if the current user has an order
    for (int i = 0; i < orders.size(); i++)
        if (orders[i].first == CurrentUser)
            return orders[i].second;

    // if no order is found, create a new one with CurrentUser and return it
    addOrder();
    return orders.end()->second;
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
    for (unsigned int order = 0; order < orders.size(); order++)
        for (unsigned int item = 0; item < orders[order].second.size(); item++)
        {
            Item currentItem = orders[order].second[item];
            addRevenue(currentItem.getPrice() * currentItem.getQuantity());
        }
}

///
/// \brief Restaurant::getRevenue
/// \return
///
double Restaurant::getRevenue() const
{
    return revenue;
}

///
/// \brief setDistanceAt
/// \param otherID
/// \param otherDistance
///
void Restaurant::setDistanceAt(unsigned int index, double distance)
{
    while(distances.size() <= index)
    {
        distances.push_back(0.0);
    }
    distances[index] = distance;
}

void Restaurant::RemoveMenuItem(int index)
{
    menu.erase(menu.begin() + index);
}

///
/// \brief getOrderList
/// \return
///
OrderList Restaurant::getOrderList() const
{
    return orders;
}

///
/// \brief setOrderList
/// \param newOrderList
///
void Restaurant::setOrderList(OrderList newOrderList)
{
    this->orders = newOrderList;
}
