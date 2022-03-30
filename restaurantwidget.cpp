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
    ui->tableWidget_tripRestaurants->setColumnCount(2);
    ui->tableWidget_tripRestaurants->setHorizontalHeaderItem(0, new QTableWidgetItem("Name"));
    ui->tableWidget_tripRestaurants->setHorizontalHeaderItem(1, new QTableWidgetItem("Distance"));

    ui->tableWidget_tripRestaurants->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    populateComboBox();

    //Initialize Grid for restaurant icons
    buttonLayout = new QGridLayout(ui->scrollArea_restaurants);
    createButtons();
    //
}

///
/// \brief RestaurantWidget::~RestaurantWidget
///
RestaurantWidget::~RestaurantWidget()
{
    delete ui;
}

///
/// \brief RestaurantWidget::populateComboBox
///
void RestaurantWidget::populateComboBox()
{
    //Clears combo box
    ui->comboBox_initialLocation->clear();
    //Add restaurants to combo box
    ui->comboBox_initialLocation->addItem("Saddleback");
    for (size_t i = 0; i < RestaurantList.size(); ++i)
        ui->comboBox_initialLocation->addItem(RestaurantList[i].getName());
}

///
/// \brief RestaurantWidget::setInitialID
/// \param initialID
///
void RestaurantWidget::setInitialID(int initialID)
{
    this->initialID = initialID;
    for (int i = 0; i < restaurantButtons.size(); i++)
        restaurantButtons[i]->setDistanceShown(initialID);
}

///
/// \brief RestaurantWidget::createButtons
///
void RestaurantWidget::createButtons()
{
    QVector<Button*> newButtons;

    if(adminAddButton != nullptr)
    {
        delete adminAddButton;
        adminAddButton = nullptr;
    }

    for (size_t i = 0; i < RestaurantList.size(); i++)
    {
        bool isChecked = false;
        for(Button* old : restaurantButtons)
        {
            if(old->getRestaurant().getID() == RestaurantList[i].getID())
            {
                isChecked = old->isChecked();
            }
        }

        newButtons.push_back(createButton(RestaurantList[i],isChecked));
    }

    restaurantButtons.clear();
    restaurantButtons = newButtons;

    updateButtonSequence();

    //Checks if the restaurant list already added the new restaurants
    if (CurrentUser.isAdmin() && RestaurantList.size() < 11)
        createAddButton();

    addButtonsToLayout();
}

///
/// \brief RestaurantWidget::addRestaurantsFromFile
///
void RestaurantWidget::addRestaurantsFromFile()
{
    Database.addRestaurants(":data/source_data2.txt");
    createButtons();
    populateComboBox();
}

///
/// \brief RestaurantWidget::addButtonsToLayout
///
void RestaurantWidget::addButtonsToLayout()
{
    int row = 0;
    int col = 0;

    for (unsigned int i = 0; i < restaurantButtons.size() + 1; i++)
    {
        if (i < restaurantButtons.size())
            buttonLayout->addWidget(restaurantButtons[i], row, col);

        if (adminAddButton)
            buttonLayout->addWidget(adminAddButton, row, col);

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
void RestaurantWidget::addRestaurantToTrip(Restaurant& rest,bool checked)
{
    if(checked)
    {
        visitedRestaurants.push_back(rest);
    }
    else
    {
        for(unsigned int index = 0; index < visitedRestaurants.size(); index++)
        {
            if(visitedRestaurants[index].getID() == rest.getID())
            {
                visitedRestaurants.removeAt(index);
            }
        }
    }

    optimizeRestaurantDistance();
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
//        QTableWidgetItem* restaurantSubtotal = new QTableWidgetItem(QString::number(visitedRestaurants[index].getRevenue())); // may need to create method for getting the total for the last confirmed order
//        ui->tableWidget_tripRestaurants->setItem(index, 2, restaurantSubtotal);
//        ui->tableWidget_tripRestaurants->item(index, 2)->setTextAlignment(Qt::AlignRight);
    }
}

///
/// \brief RestaurantWidget::updateTripDistance
///
void RestaurantWidget::updateTripDistance()
{
    double totalDistance = 0;

    if (visitedRestaurants.size() > 0)
    {
        totalDistance += visitedRestaurants[0].getDistance(ui->comboBox_initialLocation->currentIndex());
        for (unsigned int i = 0; i < visitedRestaurants.size() - 1; i++)
            totalDistance += visitedRestaurants[i].getDistance(visitedRestaurants[i + 1]);
    }

    ui->totalDistanceLineEdit->setText(QString::number(totalDistance));
}

///
/// \brief RestaurantWidget::optimizeRestaurantDistance
///
void RestaurantWidget::optimizeRestaurantDistance()
{
    QVector<Restaurant> newRestaurants = visitedRestaurants;
    int currentRestaurantID = initialID;
    visitedRestaurants.clear();

    //Searches for optimial route from the inital restaurant
    while(newRestaurants.size() > 0)
    {
        //Switches index0 to closest restaurant to the current.
        for(int index = 1; index < newRestaurants.size(); index++)
        {
            if(newRestaurants[index].getDistance(currentRestaurantID) < newRestaurants[0].getDistance(currentRestaurantID))
            {
                newRestaurants.swapItemsAt(0, index);
            }
        }

        //Switch current restaurant the closest one, and push it to the visitedRestaurants vector
        //Repeats until every restaurant has been added back to the visitedRestaurants vector
        currentRestaurantID = newRestaurants[0].getID();
        visitedRestaurants.push_back(newRestaurants[0]);
        newRestaurants.removeFirst();
    }
}

///
/// \brief RestaurantWidget::compareDistance
/// \param a
/// \param b
/// \return
///
bool RestaurantWidget::compareDistance(Button* a, Button* b)
{
    return a->getRestaurant().getDistance(initialID) < b->getRestaurant().getDistance(initialID);
}

///
/// \brief RestaurantWidget::updateRestaurantSequence
///
void RestaurantWidget::updateButtonSequence()
{
    std::sort(restaurantButtons.begin(), restaurantButtons.end(), std::bind(&RestaurantWidget::compareDistance, this, std::placeholders::_1, std::placeholders::_2));
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

void RestaurantWidget::recieve_restaurantChecked(Restaurant &rest)
{
    qDebug() << "restaurant checked: " << rest.getName();
}

///
/// \brief RestaurantWidget::createButton
/// \param rest
/// \return
///
Button *RestaurantWidget::createButton(Restaurant& rest, bool checked)
{
    Button *button = new Button(rest, initialID, this);
    button->setChecked(checked);
    QObject::connect(button,
                     SIGNAL(transmit_restaurantClicked(Restaurant&)),
                     this,
                     SLOT(recieve_restaurantClicked(Restaurant&)));
    QObject::connect(button,
                     SIGNAL(transmit_restaurantChecked(Restaurant&,bool)),
                     this,
                     SLOT(addRestaurantToTrip(Restaurant&,bool)));
    return button;
}

///
/// \brief RestaurantWidget::createAddButton
/// \return
///
void RestaurantWidget::createAddButton()
{
    adminAddButton = new Button("Add Restaurants");
    QObject::connect(adminAddButton,
                     SIGNAL(clicked()),
                     this,
                     SLOT(addRestaurantsFromFile()));
}

///
/// \brief RestaurantWidget::on_comboBox_initialLocation_currentIndexChanged
/// \param index
///
void RestaurantWidget::on_comboBox_initialLocation_currentIndexChanged(int index)
{
    //Index would be -1 on reset or clear
    if(index != -1)
    {
        qDebug() << "current index: " << index;
        setInitialID(index);
        optimizeRestaurantDistance();
        updateTableWidget();
        updateTripDistance();
        updateButtonSequence();
        addButtonsToLayout();
    }
}
