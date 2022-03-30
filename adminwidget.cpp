#include "adminwidget.h"
#include "ui_adminwidget.h"
#include <QMessageBox>

///
/// \brief AdminWidget::AdminWidget
/// \param parent
///
AdminWidget::AdminWidget(Restaurant& currentRestaurant, Menu menu, QWidget *parent) :
    QWidget(parent), ui(new Ui::AdminWidget), currentRestaurant(currentRestaurant)

{
    ui->setupUi(this);
    ui->tableWidget->setColumnCount(2);
    ui->tableWidget->setHorizontalHeaderItem(0, new QTableWidgetItem("Name"));
    ui->tableWidget->setHorizontalHeaderItem(1, new QTableWidgetItem("Price"));
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    this->menu = menu;
    updateTableWidget();
    QObject::connect(ui->tableWidget,
                     SIGNAL(selectionChanged(const QItemSelection&, const QItemSelection&)),
                     this,
                     SLOT(updateEditFields()));
    QObject::connect(ui->tableWidget,
                     SIGNAL(clicked(QModelIndex)),
                     this,
                     SLOT(updateEditFields()));
    QObject::connect(ui->tableWidget,
                     SIGNAL(doubleClicked(QModelIndex)),
                     this,
                     SLOT(updateEditFields()));
}

///
/// \brief AdminWidget::~AdminWidget
///
AdminWidget::~AdminWidget()
{
    delete ui;
}

///
/// \brief AdminWidget::updateTableWidget
///
void AdminWidget::updateTableWidget()
{
    ui->tableWidget->setRowCount(menu.size());

    // initializing contents of the table
    for(size_t index = 0; index < menu.size(); index++)
    {
        ui->tableWidget->setItem(index, 0, new QTableWidgetItem(menu[index].getName()));
        ui->tableWidget->currentItem()->setFlags(Qt::NoItemFlags);
        ui->tableWidget->setItem(index, 1, new QTableWidgetItem(QString::number(menu[index].getPrice(), 'f', 2)));
        ui->tableWidget->item(index, 1)->setTextAlignment(Qt::AlignRight);
    }
}

///
/// \brief AdminWidget::on_exitButton_pressed
///
void AdminWidget::on_exitButton_pressed()
{
    emit transmit_cancel();
}

///
/// \brief AdminWidget::on_addItemButton_pressed
///
void AdminWidget::on_addItemButton_pressed()
{
    if(ui->lineEdit_menuItem->text().isEmpty())
    {
        QMessageBox::information(this, "Tip", "You must enter a name for the item");
    }
    else
    {
        ui->tableWidget->insertRow(ui->tableWidget->rowCount() + 1);
        ui->tableWidget->setItem(ui->tableWidget->rowCount(), 0, new QTableWidgetItem(ui->lineEdit_menuItem->text()));
        ui->tableWidget->setItem(ui->tableWidget->rowCount(), 1, new QTableWidgetItem(ui->doubleSpinBox_itemPrice->value()));
    }
    ui->lineEdit_menuItem->selectAll();
}

///
/// \brief AdminWidget::on_pushButton_delete_pressed
///
void AdminWidget::on_pushButton_delete_pressed()
{
    ui->tableWidget->removeRow(ui->tableWidget->currentRow());
}

///
/// \brief AdminWidget::updateEditFields
///
void AdminWidget::updateEditFields()
{
    QModelIndex index = ui->tableWidget->currentIndex();
    QVariant currentName = QVariant::fromValue(index.siblingAtColumn(0).data(Qt::DisplayRole));
    QVariant currentPrice = QVariant::fromValue(index.siblingAtColumn(1).data(Qt::DisplayRole));
    ui->lineEdit_menuItem->setText(currentName.toString());
    ui->doubleSpinBox_itemPrice->setValue(currentPrice.toDouble());
}

///
/// \brief AdminWidget::on_saveButton_pressed
///
void AdminWidget::on_saveButton_pressed()
{

}

