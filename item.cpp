#include "item.h"

///
/// \brief Item::Item
///
Item::Item()
{
    name = "default";
    price = 0.0;
    quantity = 0;
}

///
/// \brief Item::Item
/// \param name
/// \param price
///
Item::Item(QString name, double price)
{
    this->name = name;
    this->price = price;
    this->quantity = 0;
}

///
/// \brief Item::getName
/// \return
///
QString Item::getName() const
{
    return name;
}

///
/// \brief Item::setName
/// \param name
///
void Item::setName(QString name)
{
    this->name = name;
}

///
/// \brief Item::getPrice
/// \return
///
double Item::getPrice() const
{
    return price;
}

///
/// \brief Item::setPrice
/// \param price
///
void Item::setPrice(double price)
{
    this->price = price;
}

///
/// \brief Item::getQuantity
/// \return
///
int Item::getQuantity() const
{
    return quantity;
}

///
/// \brief Item::setQuantity
/// \param quantity
///
void Item::setQuantity(int quantity)
{
    this->quantity = quantity;
}

///
/// \brief Item::incrementQuantity
///
void Item::incrementQuantity()
{
    quantity++;
}

///
/// \brief Item::decrementQuantity
///
void Item::decrementQuantity()
{
    quantity--;
}