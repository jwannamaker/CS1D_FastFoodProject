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
    /// \brief Restaurant
    ///
    /// Default constructor. No arguments passed.
    ///
    Restaurant();

    ///
    /// \brief SetName
    /// \param name
    ///
    void SetName(QString name);

    ///
    /// \brief GetName
    /// \return
    ///
    QString GetName() const
    {
        return resturantName;
    }

    ///
    /// \brief SetID
    /// \param id
    ///
    void SetID(int id);

    ///
    /// \brief SetDistances
    /// \param dists
    ///
    void SetDistances(std::vector<double> dists);

    ///
    /// \brief GetDistance
    ///
    /// get the distance from the current restaurant to the specified restaurant
    /// \return
    ///
    double GetDistance(Restaurant);

    ///
    /// \brief SetMenu
    /// \param newMenu
    ///
    void SetMenu(Menu newMenu);

    ///
    /// \brief GetID
    /// \return
    ///
    int GetID() const {return resturantID;}

    ///
    /// \brief GetMenu
    /// \return
    ///
    Menu GetMenu() const {return menu;}
private:
    QString resturantName;
    int resturantID;
    std::vector<double> distancesToOthers;
    Menu menu;
};

#endif // RESTAURANT_H
