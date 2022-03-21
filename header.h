#ifndef HEADER_H
#define HEADER_H
#include <vector>
#include "customer.h"
#include "databasehelper.h"
#include "restaurant.h"

// forward declarations in order to use as globals
//class Customer;
//class DatabaseHelper;
//class Restaurant;

// global variables
Customer CurrentUser = Customer();
DatabaseHelper Database = DatabaseHelper();
std::vector<Restaurant*> Restaurants = std::vector<Restaurant*>();

#endif // HEADER_H
