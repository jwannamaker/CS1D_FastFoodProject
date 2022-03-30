#ifndef REVENUEWIDGET_H
#define REVENUEWIDGET_H
#include <QWidget>
#include <QHeaderView>
#include <QLayout>
#include <QHBoxLayout>
#include <QLayoutItem>
#include <QTableWidget>
#include <QTableWidgetItem>
#include "restaurantwidget.h"
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
    /// \brief populateTable
    ///
    void populateTable();

    ///
    /// \brief createDetailWidget
    /// \return
    ///
    QTableWidget* createDetailWidget(Restaurant&);

    ///
    /// \brief getTotalRevenue
    ///
    void populateTotalRevenue();

signals:
    ///
    /// \brief transmit_exit
    ///
    void transmit_exit();

private slots:
    ///
    /// \brief on_exitButton_pressed
    ///
    void on_exitButton_pressed();

    ///
    /// \brief on_tableWidget_itemSelectionChanged
    ///
    void on_tableWidget_itemSelectionChanged();

private:
    Ui::RevenueWidget *ui;

};

#endif // REVENUEWIDGET_H