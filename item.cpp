#include "item.h"

Item::Item()
{
    name = "default";
    price = 0.0;
    quantity = 0;
}

Item::Item(QString name, double price)
{
    this->name = name;
    this->price = price;
    this->quantity = 0;
}

QString Item::getName() const
{
    return name;
}

void Item::setName(QString name)
{
    this->name = name;
}

double Item::getPrice() const
{
    return price;
}

void Item::setPrice(double price)
{
    this->price = price;
}

int Item::getQuantity() const
{
    return quantity;
}

void Item::setQuantity(int quantity)
{
    this->quantity = quantity;
}

void Item::incrementQuantity()
{
    quantity++;
}

void Item::decrementQuantity()
{
    quantity--;
}
