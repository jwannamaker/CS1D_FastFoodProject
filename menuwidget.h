#ifndef MENUWIDGET_H
#define MENUWIDGET_H
#include <QWidget>
#include <QTableWidget>
#include <QTableWidgetItem>
#include "button.h"
#include "customer.h"
#include "restaurant.h"
#include "ui_menuwidget.h"

// linking globals
extern Customer CurrentUser;
extern std::vector<Restaurant> RestaurantList;

namespace Ui {
class MenuWidget;
}

///
/// \class MenuWidget.
/// \brief The MenuWidget class
///
class MenuWidget : public QWidget
{
    Q_OBJECT

public:
    ///
    /// \brief MenuWidget
    /// \param currentRestaurant
    /// \param parent
    ///
    explicit MenuWidget(Restaurant& currentRestaurant, QWidget *parent = nullptr);
    ~MenuWidget();

    ///
    /// \brief createButtons
    ///
    void createButtons();

    ///
    /// \brief updateOrderTotal
    ///
    void updateOrderTotal();

    ///
    /// \brief updateTableWidget
    ///
    void updateTableWidget();

    ///
    /// \brief GetMenuItemIndex
    /// \param itemName
    /// \return
    ///
    int GetMenuItemIndex(QString itemName);

signals:
    ///
    /// \brief transmit_confirmOrder
    ///
    void transmit_confirmOrder(Restaurant&);

    ///
    /// \brief transmit_cancelOrder
    ///
    void transmit_cancelOrder();

private slots:
    ///
    /// \brief on_confirmButton_pressed
    ///
    void on_confirmButton_pressed();

    ///
    /// \brief on_cancelButton_pressed
    ///
    void on_cancelButton_pressed();

    ///
    /// \brief itemClicked
    ///
    void recieve_itemClicked(Item&);

    ///
    /// \brief deleteItemClicked
    ///
    void deleteItemClicked();

private:
    const int MAX_COL = 5;

    Ui::MenuWidget *ui;
    Button *createButton(Item& item); //Creates a button for a menu item
    Button *createDeleteButton(Item& item, const char *member);

    QGridLayout* buttonLayout;
    QVector<Button*> itemButtons;//data members
    QVector<Button*> deleteItemButtons;
    std::vector<Item> orderedItems;
    Restaurant& currentRestaurant; //Current restaurant on the widget
};

#endif // MENUWIDGET_H
