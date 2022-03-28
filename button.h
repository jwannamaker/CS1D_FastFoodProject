#ifndef BUTTON_H
#define BUTTON_H

#include <QAbstractButton>
#include <QPushButton>
#include <QLabel>
#include <QIcon>
#include <QPixmap>
#include <QLayout>
#include <QCheckBox>
#include <QVBoxLayout>
#include <QLayoutItem>
#include <QObject>
#include <QSize>
#include "restaurant.h"

// linking globals
extern Restaurant NULL_RESTAURANT;
extern Item NULL_ITEM;

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
    /// \param topText
    /// \param bottomText
    /// \param parent
    ///
    explicit Button(const QString &topText = " ", const QString &bottomText = " ", QWidget *parent = nullptr);

    ///
    /// \brief Button
    /// \param rest
    /// \param initialID
    /// \param parent
    ///
    explicit Button(Restaurant& rest, int initialID, QWidget *parent = nullptr);

    ///
    /// \brief Button
    /// \param rest
    /// \param item
    /// \param parent
    ///
    explicit Button(Restaurant& rest, Item& item, QWidget *parent = nullptr);

    ///
    /// \brief setLayout
    /// \param image
    ///
    explicit Button(Item& item, QWidget* parent = nullptr);
    void setLayout(QPixmap image);


    ///
    /// \brief setDistanceTo
    /// \param otherID
    ///
    void setDistanceShown(int otherID);

    ///
    /// \brief sizeHint
    /// \return
    ///
    QSize sizeHint() const override;

    ///
    /// \brief getRestaurant
    /// \return
    ///
    Restaurant& getRestaurant();

    ///
    /// \brief getItem
    /// \return
    ///
    Item& getItem();

    ///
    /// \brief isChecked
    /// \return
    ///
    bool isChecked();

    ///
    /// \brief isChecked
    /// \return
    ///
    void setChecked(bool checked);

signals:
    ///
    /// \brief transmit_restaurantClicked
    ///
    void transmit_restaurantClicked(Restaurant&);

    ///
    /// \brief transmit_restaurantChecked
    ///
    void transmit_restaurantChecked(Restaurant&, bool);

    ///
    /// \brief transmit_itemClicked
    ///
    void transmit_itemClicked(Item&);

public slots:
    ///
    /// \brief restaurantClicked
    ///
    void restaurantClicked();

    ///
    /// \brief restaurantChecked
    ///
    void restaurantChecked();

    ///
    /// \brief itemClicked
    ///
    void itemClicked();

private:
    const int TILE_SIZE = 60;
    Restaurant&           restaurant;
    Item&                 menuItem;
    QVBoxLayout*          layout;
    QCheckBox*            checkBox;
    QLabel*               topText;
    QLabel*               bottomText;
};

#endif // BUTTON_H
