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

    QObject::connect(this,
                     SIGNAL(transmit_validUser(bool)),
                     parent,
                     SLOT(parent->recieve_loginAttempt(bool)));
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
    // skipping authentication step for now
    on_logInButton_pressed();
}

///
/// \brief Login::on_logInButton_pressed
///
/// User pressed the "Log In" button, validate the input based on the database.
///
void Login::on_logInButton_pressed()
{
    // bring user to the main menu widget, skipping authentication for now
    this->validUser = true;


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
    ui->passwordlineEdit->clear();
}

