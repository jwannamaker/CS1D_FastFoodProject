#ifndef MENUWIDGET_H
#define MENUWIDGET_H

#include <QWidget>
#include "button.h"
#include "restaurant.h"
#include "menu.h"
#include "ui_menuwidget.h"
#include "menu.h"
#include "button.h"
#include "restaurantwidget.h"

//Max menu items displayed per column
const int MAX_ITEMS_COLS = 4;

//Most unique menu items you can order (temp)
const int MAX_MENU_ITEMS = 8;

namespace Ui {
class MenuWidget;
}

class MenuWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MenuWidget(QWidget *parent = nullptr);
    explicit MenuWidget(const Restaurant& currentRestaurant, QWidget *parent = nullptr);
    ~MenuWidget();

    Restaurant GetCurrentRestuarant();
    int GetMenuItemIndex(QString itemName);

signals:
    void transmit_confirmOrder(std::vector<Menu::Item> order);
    void transmit_cancelOrder();

private slots:
    void on_confirmButton_pressed();

    void on_editButton_pressed();

    void on_cancelButton_pressed();

    void itemClicked();

    void deleteItemClicked();

private:
    const int MAX_COL = 5;

    Ui::MenuWidget *ui;

    //Creates a button for a menu item
    Button *createButton(Menu::Item item, const char *member);

    //data members
    QVector<Button*> itemButtons;

    //
    QVector<Button*> deleteItemButtons;

    //Current restaurant on the widget
    Restaurant currentRestaurant;

    //Keeps track of the subtotatl when user is ordering food
    double subTotal;

    //Keeps track of the menu items added.
    int menuItemsAdded;

    //Stores all the items ordered
    std::vector<Menu::Item> order;

};

#endif // MENUWIDGET_H
