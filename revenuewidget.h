#ifndef REVENUEWIDGET_H
#define REVENUEWIDGET_H
#include <QWidget>
#include <QHeaderView>
#include <QLayout>
#include <QHBoxLayout>
#include <QLayoutItem>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QTreeWidget>
#include <QTreeWidgetItem>
#include <QDataWidgetMapper>
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
    /// \brief populateTree
    ///
    void populateTree();

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

private:
    Ui::RevenueWidget *ui;

};

#endif // REVENUEWIDGET_H
