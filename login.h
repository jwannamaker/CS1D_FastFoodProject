#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include "customer.h"
#include "databasehelper.h"

namespace Ui {
class Login;
}

///
/// \class Login
///
/// \brief The Login class
///
/// A widget for the login page of the app.
///
class Login : public QWidget
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);

    ~Login();

signals:
    void transmit_validUser(Customer newUser);
    void transmit_invalidUser();

public slots:
    void on_logInButton_pressed();

    void on_clearButton_pressed();

private:
    Ui::Login*  ui;
};

#endif // LOGIN_H
