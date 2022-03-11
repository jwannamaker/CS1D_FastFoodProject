#ifndef REVENUEWIDGET_H
#define REVENUEWIDGET_H

#include <QWidget>

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
    void on_BacktoMain_pressed();

private:
    Ui::RevenueWidget *ui;
};

#endif // REVENUEWIDGET_H
