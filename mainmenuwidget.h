///
/// \file mainmenuwidget.h
/// \author Johnny Wannamaker
///
#ifndef MAINMENUWIDGET_H
#define MAINMENUWIDGET_H

#include <QWidget>
#include <QPixmap>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include "customer.h"

// linking global variable
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
    ///
    /// \brief MainMenuWidget
    /// \param parent
    ///
    explicit MainMenuWidget(QWidget *parent = nullptr);
    ~MainMenuWidget();

signals:
    ///
    /// \brief transmit_logout
    ///
    void transmit_logout();

    ///
    /// \brief transmit_restaurantView
    ///
    void transmit_restaurantView();

    ///
    /// \brief transmit_revenueView
    ///
    void transmit_revenueView();

    ///
    /// \brief transmit_adminView
    ///
    void transmit_adminView();

private slots:
    ///
    /// \brief on_logOutButton_pressed
    ///
    void on_logOutButton_pressed();

    ///
    /// \brief on_restaurantsButton_pressed
    ///
    void on_restaurantsButton_pressed();

    ///
    /// \brief on_revenueButton_pressed
    ///
    void on_revenueButton_pressed();

    ///
    /// \brief on_adminButton_pressed
    ///
    void on_adminButton_pressed();

private:
    Ui::MainMenuWidget*     ui;
};

#endif // MAINMENUWIDGET_H
