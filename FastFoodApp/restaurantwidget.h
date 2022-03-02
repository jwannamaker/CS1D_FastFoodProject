#ifndef RESTAURANTWIDGET_H
#define RESTAURANTWIDGET_H

#include <QWidget>

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

private:
    Ui::RestaurantWidget *ui;
};

#endif // RESTAURANTWIDGET_H
