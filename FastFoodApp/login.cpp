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

bool Login::isValidUser()
{
    return validUser;
}


///
/// \brief Login::on_passwordlineEdit_returnPressed
///
/// User pressed enter key, validate the input using the database.
///
void Login::on_passwordlineEdit_returnPressed()
{
    // skipping authentication step for now

    this->
}


///
/// \brief Login::on_logInButton_pressed
///
/// User pressed the "Log In" button, validate the input based on the database.
///
void Login::on_logInButton_pressed()
{
    // bring user to the main menu widget
}

///
/// \brief Login::on_clearButton_pressed
///
/// User pressed the "Clear" button, clear all line edits.
///
void Login::on_clearButton_pressed()
{
    ui->usernameLineEdit->clear();
    ui->passwordlineEdit->clear();
}

