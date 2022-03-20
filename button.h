#ifndef BUTTON_H
#define BUTTON_H

#include <QAbstractButton>
#include <QPushButton>
#include <QLabel>
#include <QIcon>
#include <QPixmap>
#include <QLayout>
#include <QVBoxLayout>
#include <QLayoutItem>
#include <QObject>
#include <QSize>
#include "restaurant.h"
#include "menu.h"

const int TILE_SIZE = 50;

class Button : public QPushButton
{
    Q_OBJECT
public:
    explicit Button(Restaurant* rest, QWidget *parent = nullptr);
    explicit Button(Restaurant* rest, Menu::Item* item, QWidget *parent = nullptr);
    explicit Button(const QString &topText, const QString &bottomText, QWidget *parent = nullptr);

    ///
    /// \brief setImage
    /// \param image
    ///
    void setImage(QPixmap image);

    ///
    /// \brief sizeHint
    /// \return
    ///
    QSize sizeHint() const override;

    ///
    /// \brief getRestaurant
    /// \return
    ///
    Restaurant* getRestaurant();

    ///
    /// \brief getItem
    /// \return
    ///
    Menu::Item* getItem();

signals:
    void transmit_restaurantClicked(Restaurant*);
    void transmit_itemClicked(Menu::Item*);

public slots:
    void restaurantClicked();
    void itemClicked();

private:
    Restaurant*           restaurant;
    Menu::Item*           menuItem;
    QLabel*               topText;
    QLabel*               bottomText;
};

#endif // BUTTON_H
