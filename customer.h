///
/// \file customer.h.
///

#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <QString>

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
    Customer(const QString& username, const QString& password);

    ///
    /// \brief isAdmin.
    ///
    /// Determines if the current user is logged in as an admin or not.
    /// \return True if the current user is an Admin, otherwise False.
    ///
    bool isAdmin() const;

    ///
    /// \brief setAdmin
    /// \param admin
    ///
    void setAdmin(bool admin);

    ///
    /// \brief isValid
    /// \return
    ///
    bool isValid() const;

    ///
    /// \brief setValid
    /// \param valid
    ///
    void setValid(bool valid);

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

    ///
    /// \brief operator ==
    /// \param other
    /// \return
    ///
    bool operator==(Customer other);

private:
    QString     username;
    QString     password;
    bool        valid;
    bool        admin;
};

#endif // CUSTOMER_H