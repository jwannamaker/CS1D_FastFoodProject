#include "customer.h"
#include "databasehelper.h"

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

QString Customer::getUsername() const
{
    return username;
}

QString Customer::getPassword() const
{
    return password;
}
