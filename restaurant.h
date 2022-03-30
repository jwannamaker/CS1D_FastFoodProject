///
/// \file restaurant.h.
///

#ifndef RESTAURANT_H
#define RESTAURANT_H
#include <QDebug>
#include "cassert"
#include "customer.h"
#include "item.h"

class Restaurant;

// linking globals
extern Customer CurrentUser;
extern std::vector<Restaurant> RestaurantList;

// type aliases
using Menu = std::vector<Item>;
using Order = std::pair<Customer, std::vector<Item>>;
using OrderList = std::vector<Order>;

///
/// \class Restaurant.
///
/// \brief The Restaurant class represents a restaurant somewhere in the
/// vicinity of Saddleback College.
///
class Restaurant
{
public:
    ///
    /// \brief Restaurant
    ///
    /// Default constructor. No arguments passed.
    ///
    Restaurant();

    ///
    /// \brief Restaurant
    /// \param id
    /// \param name
    /// Alt constructor.
    ///
    Restaurant(int ID, QString name);

    ///
    /// \brief setName
    /// \param name
    ///
    void setName(QString name);

    ///
    /// \brief getName
    /// \return QString
    ///
    QString getName() const;

    ///
    /// \brief setID
    /// \param id
    ///
    void setID(int ID);

    ///
    /// \brief getID
    /// \return int
    ///
    int getID() const;

    ///
    /// \brief setDistances
    /// \param distances
    ///
    void setDistances(const std::vector<double>& distances);

    ///
    /// \brief setDistanceAt
    /// \param otherID
    /// \param otherDistance
    ///
    void setDistanceAt(unsigned int otherID, double otherDistance);

    ///
    /// \brief addDistance
    /// \param otherID
    /// \param otherDistance
    ///
    void addDistance(int otherID, double otherDistance);

    ///
    /// \brief getDistance
    ///
    /// get the distance from the current restaurant to the specified restaurant
    /// \param other the other Restaurant top find distance between
    /// \return double representing miles to the other restaurant
    ///
    double getDistance(const Restaurant& other) const;

    ///
    /// \brief getDistance
    ///
    /// get the distance from the current restaurant to the specified restaurant id
    /// \return double containing
    ///
    double getDistance(int otherID) const;

    ///
    /// \brief getShortestDistanceID
    /// \return
    ///
    int getShortestDistanceID() const;

    ///
    /// \brief getClosestRestaurant
    /// \return
    ///
    Restaurant& getClosestRestaurant();

    ///
    /// \brief setMenu
    /// \param newMenu
    ///
    void setMenu(Menu menu);

    ///
    /// \brief addMenuItem
    /// \param newItem
    ///
    void addMenuItem(Item newItem);

    ///
    /// \brief getMenuSize
    /// \return
    ///
    int getMenuSize() const;

    ///
    /// \brief getMenu
    /// \return
    ///
    Menu getMenu() const;

    ///
    /// \brief getMenuItem
    /// \param index
    /// \return
    ///
    Item& getMenuItem(int index);

    ///
    /// \brief RemoveMenuItem
    /// \param index
    ///
    void removeMenuItem(int index);

    ///
    /// \brief addOrder
    /// \param newOrder
    ///
    void addOrder(std::vector<Item> orderItems);

    ///
    /// \brief getCurrentOrderSubtotal
    /// \return
    ///
    double getCurrentOrderSubtotal() const;

    ///
    /// \brief getOrder
    /// \param index
    /// \return
    ///
    Order& getOrder(int index);

    ///
    /// \brief getOrderCount
    /// \return
    ///
    int getOrderCount() const;

    ///
    /// \brief getLastOrder
    /// \return
    ///
    Order getLastOrder();

    ///
    /// \brief getOrderList
    /// \return
    ///
    OrderList getOrderList();

    ///
    /// \brief setOrderList
    ///
    void setOrderList(OrderList);

    ///
    /// \brief setRevenue
    /// \param revenue
    ///
    void setRevenue(double revenue);

    ///
    /// \brief addRevenue
    /// \param revenue
    ///
    void addRevenue(double revenue);

    ///
    /// \brief updateRevenue
    ///
    void updateRevenue();

    ///
    /// \brief getRevenue
    /// \return
    ///
    double getRevenue() const;

private:
    int                 ID;
    QString             name;
    std::vector<double> distances;
    Menu                menu;
    OrderList           orders;
    double              revenue;
};

#endif // RESTAURANT_H