#include "restaurantwidget.h"

RestaurantWidget::RestaurantWidget(const Customer& user, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RestaurantWidget),
    mainLayout(nullptr)
{
    ui->setupUi(this);
    setInitialRestaurant(globalRestaurantList[0]);

    ui->tableWidget_tripRestaurants->setColumnCount(2);
    ui->tableWidget_tripRestaurants->setHorizontalHeaderItem(0, new QTableWidgetItem("Name"));
    ui->tableWidget_tripRestaurants->setHorizontalHeaderItem(1, new QTableWidgetItem("Distance"));
    //ui->tableWidget_tripRestaurants->setHorizontalHeaderItem(0, new QTableWidgetItem("Subtotal"));

    updateRestaurantButtons(globalRestaurantList, user.isAdmin());
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
    emit transmit_viewRestMenu(clickedButton->getRestaurant());
}

void RestaurantWidget::addRestaurants()
{
    DatabaseHelper dbhelper;
    dbhelper.addRestaurants(":data/source_data2.txt");
    updateRestaurantButtons(globalRestaurantList,false);
}

Button *RestaurantWidget::createButton(Restaurant rest, const char *member)
{
    Button *button = new Button(rest);
    connect(button, SIGNAL(clicked()), this, member);
    return button;
}

Restaurant RestaurantWidget::findRestaurant(QString restName)
{
    for (size_t i = 0; i < globalRestaurantList.size(); i++)

    {
        if (restName == globalRestaurantList[i].getName())
        {
            return globalRestaurantList[i];
        }
    }

    qDebug() << "Restaurant not found \n";
    Restaurant temp;

    return temp;
}

void RestaurantWidget::updateRestaurantButtons(const std::vector<Restaurant>& restaurantList, bool isAdmin)
{
    //Create Grid for restaurant icons
    if(mainLayout != nullptr)
    {
        restaurantButtons.clear();
        delete mainLayout;
    }
    mainLayout = new QGridLayout(ui->scrollArea_restaurants);
    mainLayout->setSizeConstraint(QLayout::SetFixedSize);

    //Create the restaurant buttons
    for (size_t i = 0; i < restaurantList.size(); ++i)
        restaurantButtons.append(createButton(restaurantList[i], SLOT(restaurantClicked())));


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

    //If the user is an admin, then the add restaurants button will be displayed
    if(isAdmin)
    {
        Button *adminAddButton = new Button("Add Restaurant","from source_data2.txt");
        connect(adminAddButton, SIGNAL(clicked()), this, SLOT(addRestaurants()));
        restaurantButtons.append(adminAddButton);
        mainLayout->addWidget(adminAddButton,row,col);
    }
}


