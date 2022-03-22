#ifndef RESTAURANTWIDGET_H
#define RESTAURANTWIDGET_H

#include <QObject>
#include <QWidget>
#include <QGridLayout>
#include <QLineEdit>
#include <QDialog>
#include <QTableWidgetItem>
#include <QTableWidget>
#include "restaurant.h"
#include "button.h"
#include "databasehelper.h"
#include "ui_restaurantwidget.h"
#include "menuwidget.h"

QT_BEGIN_NAMESPACE
class QLineEdit;
QT_END_NAMESPACE

class Button;

namespace Ui {
class RestaurantWidget;
}

class RestaurantWidget : public QWidget
{
    Q_OBJECT

public:
    explicit RestaurantWidget(const std::vector<Restaurant>& restaurantList, QWidget *parent = nullptr);
    ~RestaurantWidget();

    //Function takes restaurant name input and checks if the restaurant
    //is on restaurantListCopy
    Restaurant findRestaurant(QString restName);

    ///
    /// \brief getTripDistance
    ///
    /// Calculates the distance this Customer has traveled so far by traversing the
    /// list of restaurants in the listWidget.
    /// \return Double indicating the total miles in a Customer's trip.
    ///
    double getTripDistance(std::vector<Restaurant>& visitedList) const;

    ///
    /// \brief addRestaurantToTrip
    /// \param rest
    ///
    void addRestaurantToTrip(Restaurant rest);

    ///
    /// \brief updateTableWidget
    ///
    void updateTableWidget();

    ///
    /// \brief setInitialRestaurant
    /// \param initial
    ///
    void setInitialRestaurant(Restaurant initial);

signals:
    void transmit_cancel();
    void transmit_viewRestMenu(Restaurant rest);

private slots:
    void on_confirmButton_pressed();

    void on_cancelButton_pressed();

    void restaurantClicked();

private:
    //Number of restaurnts per row
    const int MAX_COL = 5;

    Ui::RestaurantWidget *ui;

    // the starting location
    Restaurant initialRestaurant;

    //Creates a button for restaurant
    Button *createButton(Restaurant rest, const char *member);

    // restaurants in the trip
    QVector<Restaurant> visitedRestaurants;

    //data members
    QVector<Button*> restaurantButtons;
};



#endif // RESTAURANTWIDGET_H
