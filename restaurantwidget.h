#ifndef RESTAURANTWIDGET_H
#define RESTAURANTWIDGET_H

#include <QObject>
#include <QWidget>
#include <QGridLayout>
#include <QLineEdit>
#include <QDialog>
#include <QTableWidgetItem>
#include <QTableWidget>
#include <QDialog>
#include "ui_restaurantwidget.h"
#include "button.h"
#include "customer.h"
#include "restaurant.h"
#include "databasehelper.h"

// linking globals
extern Customer CurrentUser;
extern DatabaseHelper Database;
extern std::vector<Restaurant> RestaurantList;

QT_BEGIN_NAMESPACE
class QLineEdit;
QT_END_NAMESPACE

namespace Ui {
class RestaurantWidget;
}

///
/// \class RestaurantWidget.
/// \brief The RestaurantWidget class
///
class RestaurantWidget : public QWidget
{
    Q_OBJECT

public:
    ///
    /// \brief RestaurantWidget
    /// \param parent
    ///
    explicit RestaurantWidget(QWidget *parent = nullptr);
    ~RestaurantWidget();

    ///
    /// \brief populateComboBox
    ///
    void populateComboBox();

    ///
    /// \brief setInitialRestaurant
    /// \param initial
    ///
    void setInitialID(int initialID);

    ///
    /// \brief createButtons
    ///
    void createButtons();

    ///
    /// \brief addButtonsToLayout
    ///
    void addButtonsToLayout();

    ///
    /// \brief addCheckboxToLayout
    ///
    void addCheckboxToLayout();

    ///
    /// \brief updateTableWidget
    ///
    void updateTableWidget();

    ///
    /// \brief updateTripDistance
    ///
    /// Calculates the distance this Customer has traveled so far by traversing the
    /// list of restaurants in the listWidget.
    /// \return Double indicating the total miles in a Customer's trip.
    ///
    void updateTripDistance();

    ///
    /// \brief optimizeRestaurantDistance
    ///
    void optimizeRestaurantDistance();

    ///
    /// \brief compareDistance
    /// \param a
    /// \param b
    /// \return
    ///
    bool compareDistance(Button* a, Button* b);

    ///
    /// \brief updateRestaurantSequence
    ///
    void updateButtonSequence();

signals:
    ///
    /// \brief transmit_cancel
    ///
    void transmit_cancel();

    ///
    /// \brief transmit_viewRestMenu
    /// \param rest
    ///
    void transmit_viewRestMenu(Restaurant& rest);

public slots:
    ///
    /// \brief addRestaurantToTrip
    /// \param rest
    ///
    void addRestaurantToTrip(Restaurant& rest);

    ///
    /// \brief addRestaurantsFromFile
    ///
    void addRestaurantsFromFile();

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
    /// \brief recieve_restaurantClicked
    ///
    void recieve_restaurantClicked(Restaurant&);

    ///
    /// \brief recieve_restaurantChecked
    ///
    void recieve_restaurantChecked(Restaurant&);

    ///
    /// \brief on_comboBox_initialLocation_currentIndexChanged
    /// \param index
    ///
    void on_comboBox_initialLocation_currentIndexChanged(int index);

private:
    ///
    /// \brief createButton
    /// \param rest
    /// \return
    ///
    Button *createButton(Restaurant& rest);

    ///
    /// \brief createAddButton
    /// \return
    ///
    void createAddButton();

    Ui::RestaurantWidget *ui;
    int initialID = 0;   // ID of the initial restaurant for the current trip
    const int MAX_COL = 5;  //Number of restaurant buttons per row
    QGridLayout* buttonLayout; // layout for the buttons
    QVector<Restaurant> visitedRestaurants; // restaurants in the trip
    QVector<Button*> restaurantButtons; // buttons for each restaurant available to visit
    Button* adminAddButton = nullptr; // the admin button to add restaurants from source_data2.txt
};



#endif // RESTAURANTWIDGET_H
