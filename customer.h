///
/// \file customer.h.
///

#ifndef CUSTOMER_H
#define CUSTOMER_H
#include "restaurant.h"

///
/// \class Customer.
/// \brief The Customer class represents the current user of the Fast Food Fantasy App.
///
/// \details Supports the functionality to create a new trip, place an order at any restaurant,
/// and calculate the sum of that order. Also manages the current location, and what restuarants
/// have been visited already.
///
class Customer
{
public:
    ///
    /// \brief Customer
    ///
    /// Default Constructor. No arguments passed.
    ///
    Customer();

    ///
    /// \brief Customer
    ///
    /// Two arguments accepted for Customer constructor.
    /// \param username QString
    /// \param password QString
    ///
    Customer(QString username, QString password);

    ///
    /// \brief isAdmin.
    ///
    /// Determines if the current user is logged in as an admin or not.
    /// \return True if the current user is an Admin, otherwise False.
    ///
    bool isAdmin() const;

    void setAdmin(bool admin);

    ///
    /// \brief getUsername
    /// \return
    ///
    QString getUsername() const;

    ///
    /// \brief getPassword
    /// \return
    ///
    QString getPassword() const;

private:
    QString     username;
    QString     password;
    bool        admin;
};

#endif // CUSTOMER_H
