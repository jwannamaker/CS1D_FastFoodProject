#include "customer.h"

///
/// \brief Customer::Customer
///
Customer::Customer()
{
    username = "username";
    password = "password";
}

///
/// \brief Customer::Customer
/// \param username
/// \param password
///
Customer::Customer(const QString& username, const QString& password)
{
    this->username = username;
    this->password = password;
}

///
/// \brief Customer::isAdmin
/// \return
///
bool Customer::isAdmin() const
{
    return admin;
}

///
/// \brief Customer::setAdmin
/// \param admin
///
void Customer::setAdmin(bool admin)
{
    this->admin = admin;
}

///
/// \brief Customer::isValid
/// \return
///
bool Customer::isValid() const
{
    return valid;
}

///
/// \brief Customer::setValid
/// \param valid
///
void Customer::setValid(bool valid)
{
    this->valid = valid;
}

///
/// \brief Customer::getUsername
/// \return
///
QString Customer::getUsername() const
{
    return username;
}

///
/// \brief Customer::getPassword
/// \return
///
QString Customer::getPassword() const
{
    return password;
}

///
/// \brief Customer::operator ==
/// \param other
/// \return
///
bool Customer::operator==(Customer other)
{
    return username == other.getUsername() && password == other.getPassword() &&
           valid == other.isValid() && admin == other.isAdmin();
}