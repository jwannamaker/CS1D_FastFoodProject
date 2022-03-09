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

const int TILE_SIZE = 100;

class Button : public QPushButton
{
    Q_OBJECT
public:
    explicit Button(const Restaurant& subject, QWidget *parent = nullptr);
    explicit Button(const Menu& subject, QWidget *parent = nullptr);
    explicit Button(const QString &topText, const QString &bottomText, const QString &iconFilePath, QWidget *parent = nullptr);

    ///
    /// \brief setImage
    /// \param image
    ///
    void setImage(QPixmap image);

    QSize sizeHint() const override;
private:
    QPixmap *image;
    QLabel *topText;
    QLabel *bottomText;
};

#endif // BUTTON_H
