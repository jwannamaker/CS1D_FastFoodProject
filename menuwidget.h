#ifndef MENUWIDGET_H
#define MENUWIDGET_H

#include <QWidget>
#include "restaurant.h"
#include "menu.h"

namespace Ui {
class MenuWidget;
}

class MenuWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MenuWidget(QWidget *parent = nullptr);
    explicit MenuWidget(const Restaurant& currentRestaurant, QWidget *parent = nullptr);
    ~MenuWidget();

signals:
    void transmit_confirmOrder();
    void transmit_cancelOrder();

private slots:
    void on_confirmButton_pressed();

    void on_editButton_pressed();

    void on_cancelButton_pressed();

private:
    Ui::MenuWidget *ui;
};

#endif // MENUWIDGET_H
