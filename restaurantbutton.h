#ifndef RESTAURANTBUTTON_H
#define RESTAURANTBUTTON_H

#include <QToolButton>
#include <QObject>

const int TILE_SIZE = 50;

class RestaurantButton : public QToolButton
{
    Q_OBJECT
public:
    explicit RestaurantButton(const QString &text, QWidget *parent = nullptr);

    QSize sizeHint() const override;
};

#endif // RESTAURANTBUTTON_H
