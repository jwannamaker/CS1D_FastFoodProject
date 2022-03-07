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

const int TILE_SIZE = 100;

class Button : public QPushButton
{
    Q_OBJECT
public:
    explicit Button(const QString &text1, const QString text2, const QString &iconFilePath, QWidget *parent = nullptr);

    QSize sizeHint() const override;
private:
    QLabel *textLine1;
    QLabel *textLine2;
};

#endif // BUTTON_H
