#include "revenuewidget.h"
#include "ui_revenuewidget.h"

RevenueWidget::RevenueWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RevenueWidget)
{
    ui->setupUi(this);
}

RevenueWidget::~RevenueWidget()
{
    delete ui;
}
