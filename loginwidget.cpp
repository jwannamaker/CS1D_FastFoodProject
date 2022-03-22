#include "loginwidget.h"
#include "ui_loginwidget.h"

LoginWidget::LoginWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LoginWidget)
{
    ui->setupUi(this);
}

LoginWidget::~LoginWidget()
{
    delete ui;
}

///
/// \brief Login::on_logInButton_pressed
///
/// User pressed the "Log In" button, validate the input based on the database.
///
void LoginWidget::on_logInButton_pressed()
{
    Customer newUser = Customer(ui->usernameLineEdit->text(), ui->passwordLineEdit->text());
    Database.authenticateUser(newUser);

    if (newUser.isValid())
        emit transmit_validUser(newUser);
    else
        emit transmit_invalidUser();
}

///
/// \brief Login::on_clearButton_pressed
///
/// User pressed the "Clear" button, clear all line edits.
///
void LoginWidget::on_clearButton_pressed()
{
    ui->usernameLineEdit->clear();
    ui->passwordLineEdit->clear();
}