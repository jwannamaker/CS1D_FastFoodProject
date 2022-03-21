///
/// \file restaurant.h.
///

#ifndef RESTAURANT_H
#define RESTAURANT_H
#include <QVector>
#include <QDebug>
#include "item.h"

// type aliases
using Menu = std::vector<Item*>;
using OrderList = std::vector<std::vector<Item*>>;

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
    /// \return double containg
    ///
    double getDistance(int otherID) const;

    ///
    /// \brief setMenu
    /// \param newMenu
    ///
    void setMenu(Menu menu);

    ///
    /// \brief addMenuItem
    /// \param newItem
    ///
    void addMenuItem(Item* newItem);

    ///
    /// \brief getMenuSize
    /// \return
    ///
    int getMenuSize() const;

    ///
    /// \brief getMenuItem
    /// \param index
    /// \return
    ///
    Item* getMenuItem(int index);

    ///
    /// \brief saveOrder
    /// \param newOrder
    ///
    void addOrder(std::vector<Item*> newOrder);

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
    /// \brief getRevenue
    /// \return
    ///
    double getRevenue() const;

    void setDistanceAt(unsigned int index, double distance);

private:
    int                 ID;
    QString             name;
    std::vector<double> distances;
    Menu                menu;
    OrderList           orders;
    double              revenue;
};

#endif // RESTAURANT_H
