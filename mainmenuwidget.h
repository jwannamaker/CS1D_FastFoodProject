#ifndef MAINMENUWIDGET_H
#define MAINMENUWIDGET_H

#include <QWidget>
#include <QPixmap>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include "customer.h"

extern Customer CurrentUser;

namespace Ui {
class MainMenuWidget;
}

///
/// \class MainMenuWidget
///
/// \brief The MainMenuWidget class
/// A widget for the main menu of the app. Forms the basis for
/// all interactions with the Fast Food Planner.
///
class MainMenuWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MainMenuWidget(QWidget *parent = nullptr);
    ~MainMenuWidget();

signals:
    void transmit_logout();
    void transmit_restaurantView();
    void transmit_revenueView();

private slots:
    void on_logOutButton_pressed();

    void on_restaurantsButton_pressed();

    void on_revenueButton_pressed();

private:
    Ui::MainMenuWidget*     ui;
};

#endif // MAINMENUWIDGET_H
