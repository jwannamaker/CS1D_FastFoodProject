#ifndef REVENUEWIDGET_H
#define REVENUEWIDGET_H

#include <QWidget>
#include "restaurant.h"
#include "databasehelper.h"
#include "menuwidget.h"

namespace Ui {
class RevenueWidget;
}

class RevenueWidget : public QWidget
{
    Q_OBJECT

public:
    explicit RevenueWidget(QWidget *parent = nullptr);
    ~RevenueWidget();
    double getTotalRevenue();

signals:
    void transmit_cancel();

private slots:
    void on_exitButton_pressed();

private:
    Ui::RevenueWidget *ui;
};

#endif // REVENUEWIDGET_H
