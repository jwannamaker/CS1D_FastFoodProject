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
    /// \brief SetName
    /// \param name
    ///
    void setName(QString name);

    ///
    /// \brief GetName
    /// \return
    ///
    QString getName() const;

    ///
    /// \brief SetID
    /// \param id
    ///
    void setID(int ID);

    ///
    /// \brief GetID
    /// \return
    ///
    int getID() const;

    ///
    /// \brief SetDistances
    /// \param dists
    ///
    void setDistances(std::vector<double> distances);

    ///
    /// \brief GetDistance
    ///
    /// get the distance from the current restaurant to the specified restaurant
    /// \return
    ///
    double getDistance(const Restaurant& other) const;

    ///
    /// \brief SetMenu
    /// \param newMenu
    ///
    void setMenu(Menu menu);


    ///
    /// \brief GetMenu
    /// \return
    ///
    Menu getMenu() const;
private:
    QString name;
    int ID;
    std::vector<double> distances;
    Menu menu;
};

// allocating the memory 
std::vector<Restaurant> Restaurant::list;

#endif // RESTAURANT_H
