#include "menu.h"

Menu::Menu()
{

}

void Menu::addItem(const Item& newItem)
{
    items.push_back(newItem);
}

void Menu::editItem()
{
	// TODO Define how to edit a menu item
}

std::vector<Menu::Item>* Menu::getItems()
{
	std::vector<Item>* pItems = &this->items;
    return pItems;
}
