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
    explicit Button(Restaurant rest, QWidget *parent = nullptr);
    explicit Button(Menu::Item item, QWidget *parent = nullptr);
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
    /// \brief setRestaurant
    /// \param rest
    ///
    void setRestaurant(const Restaurant& rest);

    ///
    /// \brief getRestaurant
    /// \return
    ///
    Restaurant getRestaurant() const;

    ///
    /// \brief getItem
    /// \return
    ///
    Menu::Item getItem() const;

private:
    const Restaurant*     restaurant;
    const Menu::Item*     menuItem;
    QLabel*               topText;
    QLabel*               bottomText;
};

#endif
