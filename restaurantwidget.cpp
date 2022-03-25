#include "restaurantwidget.h"

///
/// \brief RestaurantWidget::RestaurantWidget
/// \param parent
///
RestaurantWidget::RestaurantWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RestaurantWidget)
{
    ui->setupUi(this);
    ui->tableWidget_tripRestaurants->setColumnCount(3);
    ui->tableWidget_tripRestaurants->setHorizontalHeaderItem(0, new QTableWidgetItem("Name"));
    ui->tableWidget_tripRestaurants->setHorizontalHeaderItem(1, new QTableWidgetItem("Distance"));
    ui->tableWidget_tripRestaurants->setHorizontalHeaderItem(2, new QTableWidgetItem("Order Total"));

    setInitialID(0);

    //Initialize Grid for restaurant icons
    buttonLayout = new QGridLayout(ui->scrollArea_restaurants);
    createButtons();
}

///
/// \brief RestaurantWidget::~RestaurantWidget
///
RestaurantWidget::~RestaurantWidget()
{
    delete ui;
}

///
/// \brief RestaurantWidget::setInitialID
/// \param initialID
///
void RestaurantWidget::setInitialID(int initialID)
{
    this->initialID = initialID;

}

///
/// \brief RestaurantWidget::createButtons
///
void RestaurantWidget::createButtons()
{
    for (size_t i = 0; i < RestaurantList.size(); i++)
        restaurantButtons.push_back(createButton(RestaurantList[i]));

    if (CurrentUser.isAdmin())
        qDebug() << "create Add Restaurants button";


    int row = 0;
    int col = 0;

    for (unsigned int i = 0; i < restaurantButtons.size(); i++)
    {
        buttonLayout->addWidget(restaurantButtons[i], row, col);
        col++;

        if (col >= MAX_COL)
        {
            row++;
            col = 0;
        }
    }
}

///
/// \brief RestaurantWidget::addRestaurantToTrip
/// \param rest
///
void RestaurantWidget::addRestaurantToTrip(Restaurant& rest)
{
    visitedRestaurants.push_back(rest);
    updateTableWidget();
    updateTripDistance();
}

///
/// \brief RestaurantWidget::updateTableWidget
///
void RestaurantWidget::updateTableWidget()
{
    ui->tableWidget_tripRestaurants->setRowCount(visitedRestaurants.size());
    for (unsigned int index = 0; index < visitedRestaurants.size(); index++)
    {
        QTableWidgetItem* restaurantName = new QTableWidgetItem(visitedRestaurants[index].getName());
        ui->tableWidget_tripRestaurants->setItem(index, 0, restaurantName);
        QTableWidgetItem* restaurantDistance = new QTableWidgetItem(QString::number(visitedRestaurants[index].getDistance(initialID)));
        ui->tableWidget_tripRestaurants->setItem(index, 1, restaurantDistance);
        ui->tableWidget_tripRestaurants->item(index, 1)->setTextAlignment(Qt::AlignRight);
        QTableWidgetItem* restaurantSubtotal = new QTableWidgetItem(QString::number(visitedRestaurants[index].getRevenue())); // may need to create method for getting the total for the last confirmed order
        ui->tableWidget_tripRestaurants->setItem(index, 2, restaurantSubtotal);
        ui->tableWidget_tripRestaurants->item(index, 2)->setTextAlignment(Qt::AlignRight);
    }
}

///
/// \brief RestaurantWidget::updateTripDistance
///
void RestaurantWidget::updateTripDistance()
{
    double totalDistance = 0;
    for (unsigned int i = 0; i < visitedRestaurants.size() - 1; i++)
        totalDistance += visitedRestaurants[i].getDistance(visitedRestaurants[i + 1]);
    ui->totalDistanceLineEdit->setText(QString::number(totalDistance));
}

///
/// \brief RestaurantWidget::on_confirmButton_pressed
///
/// User pressed the "Confirm Trip" button
///
void RestaurantWidget::on_confirmButton_pressed()
{
    // confirm the trip

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

///
/// \brief RestaurantWidget::recieve_restaurantClicked
/// \param rest
///
void RestaurantWidget::recieve_restaurantClicked(Restaurant& rest)
{
    qDebug() << "Restaurant clicked: " << rest.getName();
    emit transmit_viewRestMenu(rest);
}

///
/// \brief RestaurantWidget::createButton
/// \param rest
/// \return
///
Button *RestaurantWidget::createButton(Restaurant& rest)
{
    Button *button = new Button(rest, initialID, this);
    QObject::connect(button,
                     SIGNAL(transmit_restaurantClicked(Restaurant&)),
                     this,
                     SLOT(recieve_restaurantClicked(Restaurant&)));
    return button;
}


