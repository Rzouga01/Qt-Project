#ifndef DASHBOARD_H
#define DASHBOARD_H

#include <QDialog>
#include <QApplication>
#include <QtWidgets>
#include <QUiLoader>
#include "mainwindow.h"
#include <QTableWidget>
#include <QTableWidgetItem>


namespace Ui {
    class Dashboard;
}

class Dashboard : public QDialog
{
    Q_OBJECT

public:
    explicit Dashboard(QWidget *parent = nullptr);
    ~Dashboard();

    void update();
    void onLogoutButtonClicked();


    //Client
    void onAddClickedClient();
    void onDeleteClickedClient();
    void onUpdateClickedClient();
    void onSortClickedClient();
    void onPdfClickedClient();
    void clearInputFields();

    void onAddCancelClickedClient();
    void onUpdateCancelClickedClient();
    void onDeleteCancelClickedClient();



    //------------------------------------


    void onAddClicked();
    void onDeleteClicked();
    void onUpdateClicked();
    void onSortClicked();
    void onPdfClicked();

public:
    Ui::Dashboard *ui;
    MainWindow mainWindowRef;

};

#endif // DASHBOARD_H
