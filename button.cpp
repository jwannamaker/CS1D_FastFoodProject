#include "button.h"

Button::Button(const QString &top, const QString& bottom, const QString &iconFilePath, QWidget *parent)
    : QPushButton(parent)
{
    setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);

    topText = new QLabel(top);
    bottomText = new QLabel(bottom);

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(topText, Qt::AlignmentFlag(Qt::AlignHCenter));
    layout->addWidget(bottomText, Qt::AlignmentFlag(Qt::AlignHCenter));
    this->setIcon(QPixmap(iconFilePath));
    this->setIconSize(QSize(40, 40));
    this->setLayout(layout);
}

Button::Button(const Restaurant& rest, QWidget* parent)
    : QPushButton(parent)
{

}

QSize Button::sizeHint() const
{
    QSize size = QPushButton::sizeHint();
    size.rheight() += TILE_SIZE;
    size.rwidth() = qMax(size.width(), size.height());
    return size;
}
