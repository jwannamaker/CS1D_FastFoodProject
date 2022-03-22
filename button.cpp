#include "button.h"

Button::Button(const QString &top, const QString& bottom, QWidget *parent)
    : QPushButton(parent)
{
    setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);
    topText = new QLabel(top);
    bottomText = new QLabel(bottom);
    setImage(QPixmap(":images/plus_icon.png"));
}

Button::Button(Restaurant* rest, int initialID, QWidget* parent)
    : QPushButton(parent)
{
    restaurant = rest;
    menuItem = nullptr;
    setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);
    topText = new QLabel(rest->getName());
    bottomText = new QLabel(QString::number(rest->getDistance(initialID)) + " miles away");
    this->setImage(QPixmap(":images/food_icon.png"));
    QObject::connect(this,
                     SIGNAL(clicked()),
                     this,
                     SLOT(restaurantClicked()));
}

Button::Button(Restaurant* rest, Item* item, QWidget* parent)
    : QPushButton(parent)
{
    restaurant = rest;
    menuItem = item;
    setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);
    topText = new QLabel(item->getName());
    bottomText = new QLabel(QString::number(item->getPrice()));
    this->setImage(QPixmap(":images/rest_menu_icon.png"));

    QObject::connect(this,
                     SIGNAL(clicked()),
                     this,
                     SLOT(itemClicked()));
}

void Button::setImage(QPixmap image)
{
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(topText, Qt::AlignmentFlag(Qt::AlignHCenter));
    layout->addWidget(bottomText, Qt::AlignmentFlag(Qt::AlignHCenter));
    this->setIcon(image);
    this->setIconSize(QSize(40, 40));
    this->setLayout(layout);
}

QSize Button::sizeHint() const
{
    QSize size = QPushButton::sizeHint();
    size.rheight() += TILE_SIZE;
    size.rwidth() += qMax(size.width(), size.height());
    return size;
}

Restaurant* Button::getRestaurant()
{
    return restaurant;
}

Item* Button::getItem()
{
    return menuItem;
}

void Button::restaurantClicked()
{
    emit transmit_restaurantClicked(restaurant);
}

void Button::itemClicked()
{
    emit transmit_itemClicked(menuItem);
}