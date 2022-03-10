#include "button.h"

Button::Button(const QString &top, const QString& bottom, QWidget *parent)
    : QPushButton(parent)
{
    setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);
    topText = new QLabel(top);
    bottomText = new QLabel(bottom);
    setImage(QPixmap(":images/food_image.png"));
}

Button::Button(const Restaurant& rest, QWidget* parent)
    : QPushButton(parent)
{
    setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);
    topText = new QLabel(rest.getName());
    bottomText = new QLabel(QString::number(rest.getDistance(0)) + " miles away");
    this->setImage(QPixmap(":images/food_icon.png"));
}

Button::Button(const Menu::Item& item, QWidget* parent)
    : QPushButton(parent)
{
    setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);
    topText = new QLabel(item.name);
    bottomText = new QLabel(QString::number(item.price));
    this->setImage(QPixmap(":images/rest_menu_icon.png"));
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
    size.rwidth() = qMax(size.width(), size.height());
    return size;
}

QLabel *Button::getTopText() const
{
    return topText;
}
