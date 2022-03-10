#include "restaurantbutton.h"

RestaurantButton::RestaurantButton(const QString &text1, const QString text2, const QString &iconFilePath, QWidget *parent)
    : QPushButton(parent)
{
    setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);

    textLine1 = new QLabel(text1);
    textLine2 = new QLabel(text2);

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(textLine1);
    layout->addWidget(textLine2);
    this->setLayout(layout);
    this->setIcon(QPixmap(iconFilePath));
}

QSize RestaurantButton::sizeHint() const
{
    QSize size = QPushButton::sizeHint();
    size.rheight() += TILE_SIZE;
    size.rwidth() = qMax(size.width(), size.height());
    return size;
}

QLabel* RestaurantButton:: getRestaurantName()
{
    return textLine1;
}
