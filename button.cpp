#include "button.h"

///
/// \brief Button::Button
/// \param item
/// \param parent
///
Button::Button(Item& item, QWidget* parent)
    : QPushButton(parent), restaurant(NULL_RESTAURANT), menuItem(item)
{
    setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);
    topText = new QLabel("");
    bottomText = new QLabel("");
    setLayout(QPixmap(":images/trashbin_icon.png"));
    checkBox->setHidden(true);

    QObject::connect(this,
                     SIGNAL(clicked()),
                     parent,
                     SLOT(deleteClicked()));
}

///
/// \brief Button::Button
/// \param top
/// \param bottom
/// \param parent
///
Button::Button(const QString &top, const QString& bottom, QWidget *parent)
    : QPushButton(parent), restaurant(NULL_RESTAURANT), menuItem(NULL_ITEM)
{
    setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);
    topText = new QLabel(top);
    bottomText = new QLabel(bottom);
    setLayout(QPixmap(":images/plus_icon.png"));
    checkBox->setHidden(true);

    QObject::connect(this,
                     SIGNAL(clicked(bool)),
                     this,
                     SLOT(addClicked()));
}

///
/// \brief Button::Button
/// \param rest
/// \param initialID
/// \param parent
///
Button::Button(Restaurant& rest, int initialID, QWidget* parent)
    : QPushButton(parent), restaurant(rest), menuItem(NULL_ITEM)
{
    setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);
    topText = new QLabel(rest.getName());
    bottomText = new QLabel(QString::number(rest.getDistance(initialID)) + " miles away");
    setLayout(QPixmap(":images/food_icon.png"));

    QObject::connect(this,
                     SIGNAL(clicked()),
                     this,
                     SLOT(restaurantClicked()));
    QObject::connect(checkBox,
                     SIGNAL(stateChanged(int)),
                     this,
                     SLOT(restaurantChecked()));
}

///
/// \brief Button::Button
/// \param rest
/// \param item
/// \param parent
///
Button::Button(Restaurant& rest, Item& item, QWidget* parent)
    : QPushButton(parent), restaurant(rest), menuItem(item)
{
    setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    topText = new QLabel(item.getName());
    bottomText = new QLabel(QString::number(item.getPrice()));
    setLayout(QPixmap(":images/rest_menu_icon.png"));
    checkBox->setHidden(true);

    QObject::connect(this,
                     SIGNAL(clicked()),
                     this,
                     SLOT(itemClicked()));
}

///
/// \brief Button::setLayout
/// \param image
///
void Button::setLayout(QPixmap image)
{
    layout = new QVBoxLayout;
    checkBox = new QCheckBox();
    layout->addWidget(checkBox, Qt::AlignmentFlag(Qt::AlignHCenter));
    layout->addWidget(topText, Qt::AlignmentFlag(Qt::AlignHCenter));
    layout->addWidget(bottomText, Qt::AlignmentFlag(Qt::AlignHCenter));

    layout->setSpacing(10);
    setIcon(image);
    setIconSize(QSize(40, 40));
    QPushButton::setLayout(layout);
}

///
/// \brief Button::setDistanceShown
/// \param otherID
///
void Button::setDistanceShown(int otherID)
{
    bottomText->setText(QString::number(restaurant.getDistance(otherID)) + " miles away");
    layout->update();
}

///
/// \brief Button::sizeHint
/// \return
///
QSize Button::sizeHint() const
{
    QSize size = QPushButton::sizeHint();
    size.rheight() += TILE_SIZE;
    size.rwidth() += qMax(size.width(), size.height());
    return size;
}

///
/// \brief Button::getRestaurant
/// \return
///
Restaurant& Button::getRestaurant()
{
    return restaurant;
}

///
/// \brief Button::getItem
/// \return
///
Item& Button::getItem()
{
    return menuItem;
}

///
/// \brief Button::isChecked
/// \return
///
bool Button::isChecked()
{
    return checkBox->isChecked();
}

///
/// \brief Button::restaurantClicked
///
void Button::restaurantClicked()
{
//    checkBox->setChecked(true);
    emit transmit_restaurantClicked(restaurant);
}

///
/// \brief Button::restaurantChecked
///
void Button::restaurantChecked()
{
    emit transmit_restaurantChecked(restaurant);
}

///
/// \brief Button::itemClicked
///
void Button::itemClicked()
{
    emit transmit_itemClicked(menuItem);
}

///
/// \brief Button::addClicked
///
void Button::addClicked()
{
    hide();
}
