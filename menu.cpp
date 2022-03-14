#include "menu.h"

Menu::Menu()
{
    items = std::vector<Menu::Item>();
}

void Menu::addItem(const Item& newItem)
{
    items.push_back(newItem);
}

void Menu::editItem()
{
	// TODO Define how to edit a menu item
}

std::vector<Menu::Item> Menu::getItems()
{
    return items;
}

double Menu::getItemPrice(QString item)
{
    for (size_t i = 0; i < items.size(); i++)
    {
        if( items[i].getName() == item)
        {
            return items[i].getPrice();
        }
    }

    qDebug("Menu item not found");
    return 0.00;
}
