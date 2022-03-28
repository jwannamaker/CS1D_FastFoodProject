#ifndef REVENUEWIDGET_H
#define REVENUEWIDGET_H
#include <QWidget>
#include "restaurant.h"

// linking globals
extern std::vector<Restaurant> RestaurantList;

namespace Ui {
class RevenueWidget;
}

///
/// \class RevenueWidget
/// \brief The RevenueWidget class
///
class RevenueWidget : public QWidget
{
    Q_OBJECT

public:
    ///
    /// \brief RevenueWidget
    /// \param parent
    ///
    explicit RevenueWidget(QWidget *parent = nullptr);
    ~RevenueWidget();

    ///
    /// \brief populateTableWidget
    ///
    void populateTable();

    ///
    /// \brief getTotalRevenue
    ///
    void populateTotalRevenue();

signals:
    ///
    /// \brief transmit_cancel
    ///
    void transmit_cancel();

    ///
    /// \brief transmit_detailedRevenue
    ///
    void transmit_detailedRevenue(Restaurant&);

private slots:
    ///
    /// \brief on_exitButton_pressed
    ///
    void on_exitButton_pressed();

    ///
    /// \brief openDetailedView
    ///
    void openDetailedView();

private:
    Ui::RevenueWidget *ui;

};

#endif // REVENUEWIDGET_H
