///
/// \file menu.h.
///

#ifndef MENU_H
#define MENU_H
#include <QString>

///
/// \brief The Menu class
///
/// A class to wrap interactions with a vector containing all of the items
/// a menu can have, such as editing a menu item, creating or deleting a
/// menu item, placing an order, getting the sum for that order, and more.
///
///
class Menu
{
public:
    ///
    /// \brief The Item class
    ///
    /// Represents any single memu item. Attributes include a name and a price.
    ///
    class Item
    {
    public:
        Item();
        Item(QString name, double price) : name{name}, price{price} {}

        QString getName() const
        {
            return name;
        }

        void setName(QString name)
        {
            this->name = name;
        }

        double getPrice() const
        {
            return price;
        }

        void setPrice(double price)
        {
            this->price = price;
        }
        int getQuantity() const
        {
            return quantity;
        }
        void setQuantity(int quantity)
        {
            this->quantity = quantity;
        }

    private:
        QString name;
        double price;
        int quantity;
    };

    ///
    /// \brief Menu
    ///
    /// Default constructor for the Menu class. No arguments passed.
    ///
    Menu();

    ///
    /// \brief addItem
    ///
    /// Inserts the passed value into the current instance of Menu.
    /// \param newItem an Item to be inserted to the Menu.
    ///
    void addItem(const Item& newItem);

    ///
    /// \brief editItem
    ///
    /// Functionality to edit an item of a menu.
    void editItem();

    ///
    /// \brief getItems
    ///
    /// Returns a pointer to the list of menu items.
    /// \return Pointer to this instance's vector containing all the menu's items.
    ///
    std::vector<Item> getItems();

    //take in the name of an item. If the item exists it will return the price,
    //else it will return 0.00
    double getItemPrice(QString item);

    //takes in the name of an item. If the item exists it will return the quantity
    //else it will return 0
    int getItemQuantity(QString item);

private:
    ///
    /// \brief items
    ///
    /// A vector containing all of the items a menu has.
    ///
    std::vector<Item> items;
};

#endif // MENU_H
