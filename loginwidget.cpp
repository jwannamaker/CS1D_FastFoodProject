#include "loginwidget.h"

///
/// \brief LoginWidget::LoginWidget
/// \param parent
///
LoginWidget::LoginWidget(QWidget *parent) :
    QWidget(parent), ui(new Ui::LoginWidget)
{
    ui->setupUi(this);
}

///
/// \brief LoginWidget::~LoginWidget
///
LoginWidget::~LoginWidget()
{
    delete ui;
}

///
/// \brief LoginWidget::on_LoginWidgetButton_pressed
///
/// User pressed the "Log In" button, validate the input based on the database.
///
void LoginWidget::on_logInButton_pressed()
{
    CurrentUser = Customer(ui->usernameLineEdit->text(), ui->passwordLineEdit->text());
    Database.authenticateUser();

    if (CurrentUser.isValid())
        emit transmit_validUser();
    on_clearButton_pressed();
}

///
/// \brief LoginWidget::on_clearButton_pressed
///
/// User pressed the "Clear" button, clear all line edits.
///
void LoginWidget::on_clearButton_pressed()
{
    ui->usernameLineEdit->clear();
    ui->passwordLineEdit->clear();
}

