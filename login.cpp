#include "login.h"
#include "ui_login.h"
#include "mainmenuwidget.h"
#include "mainwindow.h"

Login::Login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
}

Login::~Login()
{
    delete ui;
}

///
/// \brief Login::on_logInButton_pressed
///
/// User pressed the "Log In" button, validate the input based on the database.
///
void Login::on_logInButton_pressed()
{
    DatabaseHelper dbHelper;
    Customer newUser = Customer(ui->usernameLineEdit->text(), ui->passwordLineEdit->text());

    if (dbHelper.authenticateUser(newUser))
        emit transmit_validUser(newUser);
    else
        emit transmit_invalidUser();
}

///
/// \brief Login::on_clearButton_pressed
///
/// User pressed the "Clear" button, clear all line edits.
///
void Login::on_clearButton_pressed()
{
    ui->usernameLineEdit->clear();
    ui->passwordLineEdit->clear();
}

