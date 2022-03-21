#include "restaurantwidget.h"

RestaurantWidget::RestaurantWidget(const std::vector<Restaurant>& restaurantList, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RestaurantWidget)
{
    ui->setupUi(this);
    restVec = restaurantList;

    //Create Grid for restaurant icons
    mainLayout = new QGridLayout(ui->scrollArea_restaurants);
    mainLayout->setSizeConstraint(QLayout::SetFixedSize);

    //Add restaurants to combo box
    ui->comboBox_restaurants->addItem("Saddleback");
    for (size_t i = 0; i < restaurantList.size(); ++i)
        ui->comboBox_restaurants->addItem(restaurantList[i].getName());

}

RestaurantWidget::~RestaurantWidget()
{
    delete ui;
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
    Button *button = new Button(rest, findRestaurant(ui->comboBox_restaurants->currentText()));
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
    Restaurant temp(-1,"error");
    return temp;
}

void RestaurantWidget::on_comboBox_restaurants_currentTextChanged(const QString &arg1)
{
    if(arg1 == "Saddleback")
    {
        Restaurant temp(9999, "Saddleback");
        updateButtons(temp);
    }
    else
    {
        Restaurant temp = findRestaurant(arg1);
        updateButtons(temp);
    }

}

void RestaurantWidget::updateButtons(Restaurant rest)
{
    //Remove Button widgets if there are any present
    for (int i = 0; i < restaurantButtons.size(); i++)
        mainLayout->removeWidget(restaurantButtons[i]);

    //clear the vector of restaurant buttons
    restaurantButtons.clear();

    std::vector restList = restVec;
    Restaurant temp = rest;

    size_t i,j;
    //if restaurant is saddleback
    if(rest.getID() == 9999)
    {
        for(i = 0; i < (restList.size()-1); i++)
        {
            for(j = 0; j < (restList.size()-i-1); j++)
            {
                if(restList[j].getDistance(0)>restList[j+1].getDistance(0))
                {
                    temp = restList[j];
                    restList[j] = restList[j+1];
                    restList[j+1] = temp;
                }
            }
         }
    }
    else
    {
        for(i = 0; i < (restList.size()-1); i++)
        {
            for(j = 0; j < (restList.size()-i-1); j++)
            {
                if(restList[j].getDistance(rest)>restList[j+1].getDistance(rest))
                {
                    temp = restList[j];
                    restList[j] = restList[j+1];
                    restList[j+1] = temp;
                }
            }
         }
    }

    //Add new restauant button widgets
    for (size_t i = 0; i < restList.size(); ++i)
        restaurantButtons.append(createButton(restList[i], SLOT(restaurantClicked())));

    int row = 0;
    int col = 0;
    for (int i = 0; i < restaurantButtons.size(); i++)
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


