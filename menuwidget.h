#ifndef MENUWIDGET_H
#define MENUWIDGET_H

#include <QWidget>
#include "restaurant.h"
#include "menu.h"
#include "menubutton.h"
#include "ui_menuwidget.h"
#include "menu.h"

const int MAX_ITEMS_COLS = 2;

namespace Ui {
class MenuWidget;
}

class MenuWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MenuWidget(QWidget *parent = nullptr);
    explicit MenuWidget(const Restaurant& currentRestaurant, QWidget *parent = nullptr);
    ~MenuWidget();

signals:
    void transmit_confirmOrder();
    void transmit_cancelOrder();

private slots:
    void on_confirmButton_pressed();

    void on_editButton_pressed();

    void on_cancelButton_pressed();

    void menuClicked();

private:

    MenuButton *createButton(Item item, const char *member);

    Ui::MenuWidget *ui;
    QVector<MenuButton*> menuButtons;
};

#endif // MENUWIDGET_H
