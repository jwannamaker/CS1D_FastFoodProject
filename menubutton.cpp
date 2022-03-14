#include "menubutton.h"

MenuButton::MenuButton(const Item& item, QWidget *parent)
{
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
    setText(item.name);
}

QSize MenuButton::sizeHint() const
{
    QSize size = QPushButton::sizeHint();
    size.rheight() += TILE_SIZE;
    size.rwidth() = qMax(size.width(), size.height());
    return size;
}
