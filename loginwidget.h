#ifndef LOGINWIDGET_H
#define LOGINWIDGET_H
#include <QWidget>
#include "ui_loginwidget.h"
#include "customer.h"
#include "databasehelper.h"

// linking globals
extern Customer CurrentUser;
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
    ///
    /// \brief LoginWidget
    /// \param parent
    ///
    explicit LoginWidget(QWidget *parent = nullptr);

    ~LoginWidget();

signals:
    ///
    /// \brief transmit_validUser
    ///
    void transmit_validUser();

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