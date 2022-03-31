///
/// \file item.h
/// \author Johnny Wannamaker
///
#ifndef ITEM_H
#define ITEM_H
#include <QString>

///
/// \brief The Item class
///
/// Represents any single memu/order item. Attributes include a name, a unit price,
/// and a quantity.
///
class Item
{
public:
    ///
    /// \brief Item
    ///
    Item();

    ///
    /// \brief Item
    /// \param name
    /// \param price
    ///
    Item(QString name, double price);

    ///
    /// \brief getName
    /// \return
    ///
    QString getName() const;

    ///
    /// \brief setName
    /// \param name
    ///
    void setName(QString name);

    ///
    /// \brief getPrice
    /// \return
    ///
    double getPrice() const;

    ///
    /// \brief setPrice
    /// \param price
    ///
    void setPrice(double price);

    ///
    /// \brief getQuantity
    /// \return
    ///
    int getQuantity() const;

    ///
    /// \brief setQuantity
    /// \param quantity
    ///
    void setQuantity(int quantity);

    ///
    /// \brief incrementQuantity
    ///
    void incrementQuantity();

    ///
    /// \brief decrementQuantity
    ///
    void decrementQuantity();

private:
    QString     name;
    double      price;
    int         quantity;
};

#endif // ITEM_H

