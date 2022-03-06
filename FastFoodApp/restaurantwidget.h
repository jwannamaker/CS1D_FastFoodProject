#ifndef RESTAURANTWIDGET_H
#define RESTAURANTWIDGET_H

#include <QObject>
#include <QWidget>
#include <QGridLayout>
#include <QLineEdit>
#include <QDialog>
#include "restaurant.h"
#include "restaurantbutton.h"
#include "databasehelper.h"
#include "ui_restaurantwidget.h"

//Number of restaurnts per row
const int MAX_COLZ = 5;

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
    explicit RestaurantWidget(QWidget *parent = nullptr);
    ~RestaurantWidget();

signals:
    void transmit_cancel();

private slots:
    void on_confirmButton_pressed();

    void on_cancelButton_pressed();

    void restaurantClicked();

private:
    Ui::RestaurantWidget *ui;

    //Creates a button for restaurant
    RestaurantButton *createButton(const QString &text, const char *member);

    //data members
    QVector<RestaurantButton*> restaurantButtons;
};

#endif // RESTAURANTWIDGET_H
