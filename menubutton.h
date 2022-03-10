#ifndef MENUBUTTON_H
#define MENUBUTTON_H

#include <QPushButton>
#include "restaurant.h"
#include "restaurantbutton.h"

class MenuButton : public QPushButton
{

    Q_OBJECT
    public:

        explicit MenuButton(const Item &item, QWidget *parent = nullptr);
        QSize sizeHint() const override;

    private:

};

#endif // MENUBUTTON_H
