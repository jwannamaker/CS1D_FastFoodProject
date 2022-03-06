///
/// \file restaurant.h.
///

#ifndef RESTAURANT_H
#define RESTAURANT_H
#include <vector>
#include "menu.h"

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
    /// \brief list
    ///
    /// Static member of Restaurant, contains every Restuarant object created
    /// throughout the program.
    ///
    static std::vector<Restaurant> list;

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
    /// \return
    ///
    QString getName() const;

    ///
    /// \brief setID
    /// \param id
    ///
    void setID(int ID);

    ///
    /// \brief getID
    /// \return
    ///
    int getID() const;

    ///
    /// \brief setDistances
    /// \param dists
    ///
    void setDistances(std::vector<double> distances);

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
    /// \return
    ///
    double getDistance(int otherID) const;

    ///
    /// \brief setMenu
    /// \param newMenu
    ///
    void setMenu(Menu menu);


    ///
    /// \brief getMenu
    /// \return
    ///
    Menu getMenu() const;
private:
    int ID;
    QString name;
    std::vector<double> distances;
    Menu menu;
    double totalRevenue;
};

#endif // RESTAURANT_H
