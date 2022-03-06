#include "restaurantbutton.h"


RestaurantButton::RestaurantButton(const QString &text, QWidget *parent)
    : QToolButton(parent)
{
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
    setText(text);
}

QSize RestaurantButton::sizeHint() const
{
    QSize size = QToolButton::sizeHint();
    size.rheight() += TILE_SIZE;
    size.rwidth() = qMax(size.width(), size.height());
    return size;
}
