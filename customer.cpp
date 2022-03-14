#include "customer.h"
#include "databasehelper.h"

Customer::Customer()
{
    username = "username";
    password = "password";
}

Customer::Customer(QString username, QString password)
{
    this->username = username;
    this->password = password;
}


bool Customer::isAdmin()
{
    DatabaseHelper dbHelper;
    return dbHelper.authenticateUser(*this);
}

QString Customer::getUsername() const
{
    return username;
}

QString Customer::getPassword() const
{
    return password;
}
