#include "customer.h"
#include "databasehelper.h"

Customer::Customer()
{

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
