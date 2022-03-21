#include "customer.h"

Customer::Customer()
{
    username = "username";
    password = "password";
    admin   = false;
}

Customer::Customer(QString username, QString password)
{
    this->username = username;
    this->password = password;
}

bool Customer::isAdmin() const
{
    return admin;
}

void Customer::setAdmin(bool admin)
{
    this->admin = admin;
}

bool Customer::isValid() const
{
    return valid;
}

void Customer::setValid(bool valid)
{
    this->valid = valid;
}

QString Customer::getUsername() const
{
    return username;
}

QString Customer::getPassword() const
{
    return password;
}
