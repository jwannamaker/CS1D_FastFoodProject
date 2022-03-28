#ifndef REVENUEDETAILWIDGET_H
#define REVENUEDETAILWIDGET_H

#include <QWidget>
#include "restaurant.h"

// linking global variables
extern std::vector<Restaurant> RestaurantList;

namespace Ui {
class RevenueDetailWidget;
}

///
/// \brief The RevenueDetailWidget class
///
class RevenueDetailWidget : public QWidget
{
    Q_OBJECT

public:
    ///
    /// \brief RevenueDetailWidget
    /// \param currentRestaurant
    /// \param parent
    ///
    explicit RevenueDetailWidget(Restaurant& currentRestaurant, QWidget *parent = nullptr);
    ~RevenueDetailWidget();

    ///
    /// \brief setRevenueLabel
    /// \param revenueString
    ///
    void setRevenueLabel(const QString& revenueString);

    ///
    /// \brief populateTable
    ///
    void populateTable();

signals:
    ///
    /// \brief transmit_exit
    ///
    void transmit_exit();

private slots:
    ///
    /// \brief on_exitButton_clicked
    ///
    void on_exitButton_clicked();

private:
    Ui::RevenueDetailWidget *ui;
    Restaurant& currentRestaurant;
};

#endif // REVENUEDETAILWIDGET_H
