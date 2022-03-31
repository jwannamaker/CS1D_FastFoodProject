/// 
/// \file adminwidget.h
/// \brief 
/// 
/// \author Johnny Wannamaker
/// 
#ifndef ADMINWIDGET_H
#define ADMINWIDGET_H

#include <QWidget>
#include <QTableWidget>
#include <QTableWidgetItem>
#include "databasehelper.h"
#include "restaurant.h"
#include "button.h"

// linking global variables
extern DatabaseHelper Database;
extern std::vector<Restaurant> RestaurantList;

namespace Ui {
class AdminWidget;
}

/// \class AdminWidget
/// \authors Dante Vasquez, Johnny Wannamaker
/// \brief This class provides the ability to interact with the administrative
/// features of the application.
class AdminWidget : public QWidget
{
    Q_OBJECT

public:
    ///
    /// \brief AdminWidget
    /// \param parent
    ///
    explicit AdminWidget(QWidget *parent = nullptr);

    /// 
    /// \brief Destroy the Admin Widget object.
    /// 
    /// 
    ~AdminWidget();

    ///
    /// \brief populateComboBox
    ///
    void populateComboBox();

    ///
    /// \brief updateTableWidget
    ///
    void updateTableWidget();

    ///
    /// \brief saveMenu
    ///
    void saveMenu();

signals:
    ///
    /// \brief transmit_cancel
    ///
    void transmit_cancel();

private slots:
    ///
    /// \brief on_exitButton_pressed
    ///
    void on_exitButton_pressed();

    ///
    /// \brief on_comboBox_restaurant_currentIndexChanged
    /// \param index
    ///
    void on_comboBox_restaurant_currentIndexChanged(int index);

    ///
    /// \brief on_saveButton_pressed
    ///
    void on_saveButton_pressed();

    ///
    /// \brief on_deleteButton_pressed
    ///
    void on_deleteButton_pressed();

    ///
    /// \brief on_addButton_pressed
    ///
    void on_addButton_pressed();

    ///
    /// \brief on_tableWidget_itemSelectionChanged
    ///
    void on_tableWidget_itemSelectionChanged();

private:
    /// \memberof AdminWidget
    Ui::AdminWidget *ui;    

    /// \memberof AdminWidget
    int currentID;
};

#endif // ADMINWIDGET_H
