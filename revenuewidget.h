#ifndef REVENUEWIDGET_H
#define REVENUEWIDGET_H

#include <QWidget>
#include "restaurant.h"
#include "databasehelper.h"
#include "menuwidget.h"

// linking usage of globals
extern std::vector<Restaurant*> Restaurants;

namespace Ui {
class RevenueWidget;
}

///
/// \class RevenueWidget.
/// \brief The RevenueWidget class
///
class RevenueWidget : public QWidget
{
    Q_OBJECT

public:
    explicit RevenueWidget(QWidget *parent = nullptr);
    ~RevenueWidget();

    ///
    /// \brief populateTableWidget
    ///
    void populateTableWidget();

    ///
    /// \brief getTotalRevenue
    /// \return
    ///
    double getTotalRevenue();

signals:
    void transmit_cancel();

private slots:
    ///
    /// \brief on_exitButton_pressed
    ///
    void on_exitButton_pressed();

private:
    Ui::RevenueWidget *ui;
};

#endif // REVENUEWIDGET_H
