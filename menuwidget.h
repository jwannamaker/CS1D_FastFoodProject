#ifndef MENUWIDGET_H
#define MENUWIDGET_H

#include <QWidget>
#include <QTableWidget>
#include <QTableWidgetItem>
#include "button.h"
#include "restaurant.h"
#include "menu.h"
#include "ui_menuwidget.h"
#include "menu.h"
#include "button.h"
#include "restaurantwidget.h"

const int MAX_ITEMS_COLS = 5;

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

signals:
    void transmit_confirmOrder(Restaurant);
    void transmit_cancelOrder();

private slots:
    void on_confirmButton_pressed();

    void on_cancelButton_pressed();

    void itemClicked();

private:
    const int MAX_COL = 5;

    Ui::MenuWidget *ui;

    //Creates a button for a menu item
    Button *createButton(Menu::Item item, const char *member);

    //data members
    QVector<Button*> itemButtons;

    //Current restaurant on the widget
    Restaurant currentRestaurant;

    //Keeps track of the subtotatl when user is ordering food
    double subTotal;

    int menuItemsAdded;

};

#endif // MENUWIDGET_H
