#ifndef LOGINWIDGET_H
#define LOGINWIDGET_H
#include <QWidget>
#include "customer.h"
#include "databasehelper.h"

// linking global
extern DatabaseHelper Database;

namespace Ui {
class LoginWidget;
}

///
/// \class LoginWidget
///
/// \brief The LoginWidget class
///
/// A widget for the login page of the app.
///
class LoginWidget : public QWidget
{
    Q_OBJECT

public:
    explicit LoginWidget(QWidget *parent = nullptr);

    ~LoginWidget();

signals:
    void transmit_validUser(Customer newUser);
    void transmit_invalidUser();

public slots:
    ///
    /// \brief on_logInButton_pressed
    ///
    void on_logInButton_pressed();

    ///
    /// \brief on_clearButton_pressed
    ///
    void on_clearButton_pressed();

private:
    Ui::LoginWidget*  ui;
};

#endif // LOGINWIDGET_H
