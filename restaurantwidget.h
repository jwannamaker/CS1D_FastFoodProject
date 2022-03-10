#ifndef RESTAURANTWIDGET_H
#define RESTAURANTWIDGET_H

#include <QObject>
#include <QWidget>
#include <QGridLayout>
#include <QLineEdit>
#include <QDialog>
#include "restaurant.h"
#include "menu.h"
#include "button.h"
#include "databasehelper.h"
#include "ui_restaurantwidget.h"

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
