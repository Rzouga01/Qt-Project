#ifndef DASHBOARD_H
#define DASHBOARD_H

#include <QDialog>
#include <QApplication>
#include <QtWidgets>
#include <QUiLoader>
#include "mainwindow.h"
#include <QTableWidget>
#include <QTableWidgetItem>
#include "employee.h"

namespace Ui {
    class Dashboard;
}

class Dashboard : public QDialog
{
    Q_OBJECT

public:
    explicit Dashboard(QWidget* parent = nullptr);
    ~Dashboard();

    void update();
    void onLogoutButtonClicked();

    // Client
    void onAddClickedClient();
    void onDeleteClickedClient();
    void onUpdateClickedClient();
    void onSortClickedClient();
    void onPdfClickedClient();
<<<<<<< Updated upstream



    void clearInputFieldsCreateClient();
    void clearInputFieldsUpdateClient();
    void clearInputFieldsDeleteClient();

=======
    void clearInputFields();
>>>>>>> Stashed changes
    void onAddCancelClickedClient();
    void onUpdateCancelClickedClient();
    void onDeleteCancelClickedClient();
    void ClientDashboardConnectUi();
    void onStackedClientIndexChanged(int index);

<<<<<<< Updated upstream
    void openDeletePage(int clientId);

=======
    // Employee
    void onAddEmployeeClicked();
    void onDeleteEmployeeClicked();
    void onUpdateEmployeeClicked();
    void onSortEmployeeClicked();
    void onPdfEmployeeClicked();
    void onCancelClickedEmp_C();
    void onCancelClickedEmp_U();
    void onCancelClickedEmp_D();
    void EmployeeDashboardConnectUi();
>>>>>>> Stashed changes

    void openUpdateForm();
    void onComboboxIndexChanged(int index);
    Employee* getEmployeeDataById(int id);

<<<<<<< Updated upstream
private:
    Ui::Dashboard *ui;
=======
public:
    Ui::Dashboard* ui;
>>>>>>> Stashed changes
    MainWindow mainWindowRef;

};

#endif // DASHBOARD_H
