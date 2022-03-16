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
    explicit Button(const Restaurant& rest, QWidget *parent = nullptr);
    explicit Button(const Menu::Item& item, QString itemName, QWidget *parent = nullptr);
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

    QLabel *getTopText() const;

private:
    QLabel*     topText;
    QLabel*     bottomText;
    QString itemName;
};

#endif // BUTTON_H
