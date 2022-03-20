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

namespace Ui {
class MenuWidget;
}

class MenuWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MenuWidget(Restaurant& currentRestaurant, QWidget *parent = nullptr);
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

    ///
    /// \brief createButtonLayout
    ///
    void createButtonLayout();

signals:
    void transmit_confirmOrder(Restaurant*);
    void transmit_cancelOrder();

private slots:
    void on_confirmButton_pressed();

    void on_cancelButton_pressed();

    void recieve_itemClicked();

private:
    const int MAX_COL = 5;

    Ui::MenuWidget *ui;
    Button *createButton(Menu::Item* item); //Creates a button for a menu item
    QVector<Button*> itemButtons;//data members
    QVector<Menu::Item*> orderedItems;
    Restaurant* currentRestaurant; //Current restaurant on the widget
};

#endif // MENUWIDGET_H
