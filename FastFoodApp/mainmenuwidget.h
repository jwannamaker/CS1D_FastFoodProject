#ifndef MAINMENUWIDGET_H
#define MAINMENUWIDGET_H

#include <QWidget>

namespace Ui {
class MainMenuWidget;
}

class MainMenuWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MainMenuWidget(QWidget *parent = nullptr);
    ~MainMenuWidget();

signals:
    void transmit_logout();
    void transmit_restaurantView();

private slots:
    void on_logOutButton_pressed();

    void on_orderHistoryButton_pressed();

    void on_restaurantsButton_pressed();

private:
    Ui::MainMenuWidget *ui;
};

#endif // MAINMENUWIDGET_H
