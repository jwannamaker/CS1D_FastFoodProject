#include "login.h"
#include "ui_login.h"
#include "mainmenuwidget.h"
#include "mainwindow.h"

Login::Login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
    this->validUser = false;
}

Login::~Login()
{
    delete ui;
}

///
/// \brief Login::on_passwordlineEdit_returnPressed
///
/// User pressed enter key, validate the input using the database.
///
void Login::on_passwordlineEdit_returnPressed()
{
    on_logInButton_pressed();
}

///
/// \brief Login::on_logInButton_pressed
///
/// User pressed the "Log In" button, validate the input based on the database.
///
void Login::on_logInButton_pressed()
{
    // TODO: Add a table into restaurant_data.sqlite called "User Data" or the like, and create the functionality
    // to authenticate a username and password pair based on the contents of that table
    this->validUser = (ui->usernameLineEdit->text() == QString("username") && ui->passwordLineEdit->text() == QString("password"));

    emit transmit_validUser(this->validUser);
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

