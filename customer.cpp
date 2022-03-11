#include "customer.h"

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
    return DatabaseHelper::authenticateUser(this);
}
