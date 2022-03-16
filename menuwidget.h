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
    explicit MenuWidget(const Restaurant& currentRestaurant, QWidget *parent = nullptr);
    ~MenuWidget();

    ///
    /// \brief getCurrentRestuarant
    /// \return
    ///
    Restaurant getCurrentRestuarant() const;

    ///
    /// \brief updateOrderTotal
    ///
    void updateOrderTotal();

    ///
    /// \brief updateTableWidget
    ///
    void updateTableWidget();

signals:
    void transmit_confirmOrder(Restaurant);
    void transmit_cancelOrder();
    void transmit_addToOrder(Menu::Item);

private slots:
    void on_confirmButton_pressed();

    void on_cancelButton_pressed();

    void itemClicked();

private:
    const int MAX_COL = 5;

    Ui::MenuWidget *ui;

    //Creates a button for a menu item
    Button *createButton(Menu::Item item);

    //data members
    QVector<Button*> itemButtons;

    QVector<Menu::Item> orderedItems;

    //Current restaurant on the widget
    Restaurant currentRestaurant;
};

#endif // MENUWIDGET_H
