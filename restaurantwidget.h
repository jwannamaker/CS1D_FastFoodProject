#ifndef RESTAURANTWIDGET_H
#define RESTAURANTWIDGET_H

#include <QObject>
#include <QWidget>
#include <QGridLayout>
#include <QLineEdit>
#include <QDialog>
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

    //Creates a button for restaurant
    Button *createButton(Restaurant rest, const char *member);

    //data members
    QVector<Button*> restaurantButtons;
};



#endif // RESTAURANTWIDGET_H
