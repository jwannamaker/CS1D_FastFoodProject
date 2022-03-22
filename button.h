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
#include <QDebug>
#include "restaurant.h"

///
/// \class Button.
/// \brief The Button class
///
class Button : public QPushButton
{
    Q_OBJECT
public:
    ///
    /// \brief Button
    /// \param rest
    /// \param initialID
    /// \param parent
    ///
    explicit Button(Restaurant* rest, int initialID, QWidget *parent = nullptr);

    ///
    /// \brief Button
    /// \param rest
    /// \param item
    /// \param parent
    ///
    explicit Button(Restaurant* rest, Item* item, QWidget *parent = nullptr);

    ///
    /// \brief Button
    /// \param topText
    /// \param bottomText
    /// \param parent
    ///
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
    Item* getItem();

signals:
    ///
    /// \brief transmit_restaurantClicked
    ///
    void transmit_restaurantClicked(Restaurant*);

    ///
    /// \brief transmit_itemClicked
    ///
    void transmit_itemClicked(Item*);

public slots:
    void restaurantClicked();
    void itemClicked();

private:
    const int TILE_SIZE = 100;
    Restaurant*           restaurant;
    Item*           menuItem;
    QLabel*               topText;
    QLabel*               bottomText;
};

#endif // BUTTON_H
