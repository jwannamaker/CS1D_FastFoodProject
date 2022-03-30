#ifndef ADMINWIDGET_H
#define ADMINWIDGET_H

#include <QWidget>
#include <QTableWidget>
#include <QTableWidgetItem>
#include "restaurant.h"
#include "button.h"

// linking global variables
extern std::vector<Restaurant> RestaurantList;

namespace Ui {
class AdminWidget;
}

///
/// \brief The AdminWidget class
///
class AdminWidget : public QWidget
{
    Q_OBJECT

public:
    ///
    /// \brief AdminWidget
    /// \param parent
    ///
    explicit AdminWidget(Restaurant& currentRestaurant, Menu originalMenu, QWidget *parent = nullptr);
    ~AdminWidget();

    ///
    /// \brief updateTableWidget
    ///
    void updateTableWidget();

    //Button *createDeleteButton(Item& item, const char *member);

signals:
    ///
    /// \brief transmit_cancel
    ///
    void transmit_cancel();

    ///
    /// \brief transmit_submitChanges
    ///
    void transmit_submitChanges();

private slots:
    ///
    /// \brief on_exitButton_pressed
    ///
    void on_exitButton_pressed();

    ///
    /// \brief on_saveButton_pressed
    ///
    /// Takes the contents of the table widget, creates a new menu according
    /// to the admin's new specification, and sets the appropriate restaurant's
    /// menu to match.
    ///
    void on_saveButton_pressed();

    ///
    /// \brief on_addItemButton_pressed
    ///
    void on_addItemButton_pressed();

    ///
    /// \brief on_pushButton_delete_pressed
    ///
    void on_pushButton_delete_pressed();

    ///
    /// \brief updateEditFields
    ///
    void updateEditFields();

private:
    Ui::AdminWidget *ui;
    Restaurant& currentRestaurant;
    Menu menu;
};

#endif // ADMINWIDGET_H
