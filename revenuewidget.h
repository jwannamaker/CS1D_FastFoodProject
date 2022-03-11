#ifndef REVENUEWIDGET_H
#define REVENUEWIDGET_H

#include <QWidget>
#include "restaurant.h"
#include <vector>

namespace Ui {
class RevenueWidget;
}

class RevenueWidget : public QWidget
{
    Q_OBJECT

public:
    explicit RevenueWidget(std::vector<Restaurant> list, QWidget *parent = nullptr);
    ~RevenueWidget();

signals:
    void transmit_exitRevenue();

private slots:
    void on_exitButton_clicked();

private:
    Ui::RevenueWidget *ui;
};

#endif // REVENUEWIDGET_H
