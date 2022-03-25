#include "button.h"

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
    setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);
    topText = new QLabel(item.getName());
    bottomText = new QLabel(QString::number(item.getPrice()));
    setLayout(QPixmap(":images/rest_menu_icon.png"));

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
    layout->addWidget(topText, Qt::AlignmentFlag(Qt::AlignHCenter));
    layout->addWidget(bottomText, Qt::AlignmentFlag(Qt::AlignHCenter));
    layout->setSpacing(10);
    setIcon(image);
    setIconSize(QSize(50, 50));
    QPushButton::setLayout(layout);
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
/// \brief Button::restaurantClicked
///
void Button::restaurantClicked()
{
    emit transmit_restaurantClicked(restaurant);
}

///
/// \brief Button::itemClicked
///
void Button::itemClicked()
{
    emit transmit_itemClicked(menuItem);
}