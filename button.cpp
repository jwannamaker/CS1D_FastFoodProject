#include "button.h"

Button::Button(const QString &top, const QString& bottom, QWidget *parent)
    : QPushButton(parent)
{
    setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);
    topText = new QLabel(top);
    bottomText = new QLabel(bottom);
    setImage(QPixmap(":images/food_image.png"));
}

Button::Button(Restaurant rest, QWidget* parent)
    : QPushButton(parent)
{
    restaurant = new Restaurant(rest);
    menuItem = nullptr;
    setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);
    topText = new QLabel(rest.getName());
    bottomText = new QLabel(QString::number(rest.getDistance(0)) + " miles away");
    this->setImage(QPixmap(":images/food_icon.png"));
}

Button::Button(Menu::Item item, QWidget* parent)
    : QPushButton(parent)
{
    restaurant = nullptr;
    menuItem = new Menu::Item(item);
    setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);
    topText = new QLabel(item.getName());
    bottomText = new QLabel(QString::number(item.getPrice()));
    this->setImage(QPixmap(":images/rest_menu_icon.png"));
}

Button::~Button()
{
    if(restaurant != nullptr)
    {
        delete restaurant;
    }
    if(menuItem != nullptr)
    {
        delete menuItem;
    }
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

void Button::setRestaurant(const Restaurant& rest)
{
    restaurant = &rest;
}

const Restaurant& Button::getRestaurant() const
{
    return *restaurant;
}

const Menu::Item& Button::getItem() const
{
    return *menuItem;
}
