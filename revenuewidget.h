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

private:
    Ui::RevenueWidget *ui;
};

#endif // REVENUEWIDGET_H
