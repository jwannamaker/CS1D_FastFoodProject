#include "restaurantwidget.h"

RestaurantWidget::RestaurantWidget(std::vector<Restaurant>& restaurantList, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RestaurantWidget)
{
    ui->setupUi(this);

    visitedRestaurants = QVector<Restaurant>();
    setInitialRestaurant(restaurantList.at(0));
    ui->tableWidget_tripRestaurants->setColumnCount(3);
    ui->tableWidget_tripRestaurants->setHorizontalHeaderItem(0, new QTableWidgetItem("Name"));
    ui->tableWidget_tripRestaurants->setHorizontalHeaderItem(1, new QTableWidgetItem("Distance"));
    ui->tableWidget_tripRestaurants->setHorizontalHeaderItem(2, new QTableWidgetItem("Subtotal"));

    //Create the restaurant buttons
    for (size_t i = 0; i < restaurantList.size(); ++i)
        restaurantButtons.append(createButton(&restaurantList[i]));

    //Create Grid for restaurant icons
    QGridLayout *mainLayout = new QGridLayout(ui->scrollArea_restaurants);
    mainLayout->setSizeConstraint(QLayout::SetFixedSize);

    //Add restaurants to window
    int row = 0;
    int col = 0;

    for (size_t i = 0; i < restaurantList.size(); i++)
    {
        mainLayout->addWidget(restaurantButtons[i], row, col);
        col++;

        if (col >= MAX_COL)
        {
            row++;
            col = 0;
        }
    }
}

RestaurantWidget::~RestaurantWidget()
{
    delete ui;
}

void RestaurantWidget::addRestaurantToTrip(Restaurant rest)
{
    visitedRestaurants.push_back(rest);
    updateTableWidget();
}

void RestaurantWidget::setInitialRestaurant(Restaurant initial)
{
    this->initialRestaurant = initial;
    ui->initialLocationLineEdit->setText(initialRestaurant.getName());
}

void RestaurantWidget::updateTableWidget()
{
    ui->tableWidget_tripRestaurants->setRowCount(visitedRestaurants.size());
    for (unsigned int index = 0; index < visitedRestaurants.size(); index++)
    {
        QTableWidgetItem* restaurantName = new QTableWidgetItem(visitedRestaurants[index].getName());
        ui->tableWidget_tripRestaurants->setItem(index, 0, restaurantName);
        QTableWidgetItem* restaurantDistance = new QTableWidgetItem(QString::number(visitedRestaurants[index].getDistance(initialRestaurant.getID())));
        ui->tableWidget_tripRestaurants->setItem(index, 1, restaurantDistance);
        ui->tableWidget_tripRestaurants->item(index, 1)->setTextAlignment(Qt::AlignRight);
        QTableWidgetItem* restaurantSubtotal = new QTableWidgetItem(QString::number(visitedRestaurants[index].getRevenue()));
        ui->tableWidget_tripRestaurants->setItem(index, 2, restaurantSubtotal);
        ui->tableWidget_tripRestaurants->item(index, 2)->setTextAlignment(Qt::AlignRight);
    }
    // update the distance traveled
}

///
/// \brief RestaurantWidget::on_confirmButton_pressed
///
/// User pressed the "Confirm Trip" button meaning
///     1. The contents of ui->listView must be traversed and saved to the Customer's history,
///        the Restaurants' history, and the database.
///     2. The index of MainWindow->ui->stackedWidget->setCurrentIndex(1) to return back to the
///        main menu page
///     3. The contents of ui->listView must be cleared, and anything else from the last trip
///        must be reset
///
void RestaurantWidget::on_confirmButton_pressed()
{
// A quick cancel/confirm popup, could be expanded on later include a brief summary of their trip
//    QDialog confirmTrip = QDialog("Are you sure?");
//    confirmTrip.set("Are you sure?");
//    confirmTrip.setModal(true);
//    confirmTrip.setWindowTitle("Confirm");
//    confirmTrip.show();


    emit transmit_cancel();
}

///
/// \brief RestaurantWidget::on_cancelButton_pressed
///
/// User pressed "Cancel Trip." Clear all fields, the QListView, etc.
///
void RestaurantWidget::on_cancelButton_pressed()
{
    emit transmit_cancel();
}

void RestaurantWidget::recieve_restaurantClicked(Restaurant* rest)
{
    qDebug() << "Restaurant clicked: " << rest->getName() << "\n";
    emit transmit_viewRestMenu(*rest);
}

Button *RestaurantWidget::createButton(Restaurant* rest)
{
    Button *button = new Button(rest, this);
    QObject::connect(button, SIGNAL(transmit_restaurantClicked(Restaurant*)), this, SLOT(recieve_restaurantClicked(Restaurant*)));
    return button;
}


