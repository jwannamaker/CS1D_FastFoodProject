#ifndef MENUWIDGET_H
#define MENUWIDGET_H

#include <QWidget>
#include "button.h"
#include "restaurant.h"
#include "menu.h"

namespace Ui {
class MenuWidget;
}

class MenuWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MenuWidget(QWidget *parent = nullptr);
    explicit MenuWidget(const std::vector<Menu::Item>& itemList, QWidget *parent = nullptr);
    ~MenuWidget();

signals:
    void transmit_confirmOrder(std::vector<Menu::Item>);
    void transmit_cancelOrder();

private slots:
    void on_confirmButton_pressed();

    void on_editButton_pressed();

    void on_cancelButton_pressed();

     void itemClicked();

private:
    const int MAX_COL = 5;

    Ui::MenuWidget *ui;

    //Creates a button for a menu item
    Button *createButton(Menu::Item item, const char *member);

    //data members
    QVector<Button*> itemButtons;
};

#endif // MENUWIDGET_H
