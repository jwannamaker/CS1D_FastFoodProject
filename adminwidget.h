#ifndef ADMINWIDGET_H
#define ADMINWIDGET_H

#include <QWidget>
#include <QTableWidget>
#include <QTableWidgetItem>
#include "databasehelper.h"
#include "restaurant.h"
#include "button.h"

// linking global variables
extern DatabaseHelper Database;
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
    explicit AdminWidget(QWidget *parent = nullptr);
    ~AdminWidget();

    ///
    /// \brief populateComboBox
    ///
    void populateComboBox();

    ///
    /// \brief updateTableWidget
    ///
    void updateTableWidget();

    ///
    /// \brief saveMenu
    ///
    void saveMenu();

signals:
    ///
    /// \brief transmit_cancel
    ///
    void transmit_cancel();

private slots:
    ///
    /// \brief on_exitButton_pressed
    ///
    void on_exitButton_pressed();

    ///
    /// \brief on_comboBox_restaurant_currentIndexChanged
    /// \param index
    ///
    void on_comboBox_restaurant_currentIndexChanged(int index);

    ///
    /// \brief on_saveButton_pressed
    ///
    /// Takes the contents of the table widget, creates a new menu according
    /// to the admin's new specification, and sets the appropriate restaurant's
    /// menu to match.
    ///
    void on_saveButton_pressed();

    ///
    /// \brief on_deleteButton_pressed
    ///
    void on_deleteButton_pressed();

    ///
    /// \brief on_addButton_pressed
    ///
    void on_addButton_pressed();

    ///
    /// \brief on_tableWidget_itemSelectionChanged
    ///
    void on_tableWidget_itemSelectionChanged();

private:
    Ui::AdminWidget *ui;
    int currentID;
};

#endif // ADMINWIDGET_H
