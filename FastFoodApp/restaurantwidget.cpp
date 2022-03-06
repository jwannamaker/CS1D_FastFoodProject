#include "restaurantwidget.h"


RestaurantWidget::RestaurantWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RestaurantWidget)
{
    ui->setupUi(this);
    ui->initialLocationLineEdit->setText("Saddleback");

    //Get a vector of restaurants from the data base
    DatabaseHelper dbHelper;
    std::vector<Restaurant> restaurantList = dbHelper.populateRestaurants();
    dbHelper.createRestaurantTable(restaurantList);
    dbHelper.createMenuTable(restaurantList);
    dbHelper.createDistancesTable(restaurantList);

    //Create the restaurant buttons
    for (size_t i = 0; i < restaurantList.size(); ++i)
        restaurantButtons.append(createButton(restaurantList[i].getName(), SLOT(restaurantClicked())));

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

        if (col >= MAX_COLZ)
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

    QTextStream dprint(stdout);
    //Get the tile clicked and send to restaurnt menu
    RestaurantButton *clickedButton = qobject_cast<RestaurantButton *>(sender());
    QString restName = clickedButton->text();
    dprint << "Restaurant clicked: " << restName << "\n";

}

RestaurantButton *RestaurantWidget::createButton(const QString &text, const char *member)
{
    RestaurantButton *button = new RestaurantButton(text);
    connect(button, SIGNAL(clicked()), this, member);
    return button;
}



