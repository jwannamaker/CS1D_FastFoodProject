#include "restaurantwidget.h"

RestaurantWidget::RestaurantWidget(const std::vector<Restaurant>& restaurantList, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RestaurantWidget)
{
    ui->setupUi(this);
    ui->initialLocationLineEdit->setText("Saddleback");

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

    emit transmit_viewRestMenu(Restaurant::list.at(3));
}

Button *RestaurantWidget::createButton(Restaurant rest, const char *member)
{
    Button *button = new Button(rest);
    connect(button, SIGNAL(clicked()), this, member);
    return button;
}



