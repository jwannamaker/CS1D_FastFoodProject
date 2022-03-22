#include "restaurantwidget.h"

RestaurantWidget::RestaurantWidget(const std::vector<Restaurant>& restaurantList, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RestaurantWidget)
{
    ui->setupUi(this);
    DatabaseHelper dbhelper;
    dbhelper.populateRestaurants();
    setInitialRestaurant(Restaurant::list[0]);

    ui->tableWidget_tripRestaurants->setColumnCount(2);
    ui->tableWidget_tripRestaurants->setHorizontalHeaderItem(0, new QTableWidgetItem("Name"));
    ui->tableWidget_tripRestaurants->setHorizontalHeaderItem(1, new QTableWidgetItem("Distance"));
    //ui->tableWidget_tripRestaurants->setHorizontalHeaderItem(0, new QTableWidgetItem("Subtotal"));

    //Create the restaurant buttons
    for (size_t i = 0; i < restaurantList.size(); ++i)
        restaurantButtons.append(createButton(restaurantList[i], SLOT(restaurantClicked())));

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
//        QTableWidgetItem* restaurantSubtotal = new QTableWidgetItem(QString::number(0.00));
//        ui->tableWidget_tripRestaurants->setItem(index, 2, restaurantSubtotal);
    }
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

void RestaurantWidget::restaurantClicked()
{
    //Get the tile clicked and send to restaurant menu
    Button *clickedButton = qobject_cast<Button *>(sender());
    qDebug() << "Restaurant Clicked";
    qDebug() << clickedButton->getTopText()->text();

    Restaurant temp = findRestaurant(clickedButton->getTopText()->text());
    emit transmit_viewRestMenu(temp);
}

Button *RestaurantWidget::createButton(Restaurant rest, const char *member)
{
    Button *button = new Button(rest);
    connect(button, SIGNAL(clicked()), this, member);
    return button;
}

Restaurant RestaurantWidget::findRestaurant(QString restName)
{
    for (size_t i = 0; i < Restaurant::list.size(); i++)

    {
        if (restName == Restaurant::list[i].getName())
        {
            return Restaurant::list[i];
        }
    }

    qDebug() << "Restaurant not found \n";
    Restaurant temp;

    return temp;
}

double RestaurantWidget::getTripDistance(std::vector<Restaurant>& visitedList) const
{
	double totalDistance = 0;
	
	for(int i = 0; i < visitedList.size() - 1; ++i)
	{
		totalDistance += visitedList[i].getDistance(visitedList[i+1]);
	}
	
	return totalDistance;
}
