#ifndef DASHBOARD_H
#define DASHBOARD_H

#include <QDialog>
#include <QApplication>
#include <QtWidgets>
#include <QUiLoader>
#include "accidentdetector.h"
#include "mainwindow.h"
#include <QTableWidget>
#include <QTableWidgetItem>
#include "employee.h"
#include "employeesrfid.h"

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
    void showPageForRole(int role);
    void createSession(Employee* employee);
    //------------------------------------------------------------------------------------------------------------------
    // Client
    void onAddClickedClient();
    void onDeleteClickedClient();
    void onUpdateClickedClient();
    void onSortClickedClient();
    void onPdfClickedClient();
    void clearInputFieldsCreateClient();
    void clearInputFieldsUpdateClient();
    void clearInputFieldsDeleteClient();
    void clearInputFields();
    void onAddCancelClickedClient();
    void onUpdateCancelClickedClient();
    void onDeleteCancelClickedClient();
    void ClientDashboardConnectUi();
    void onSearchIdClient();
    void onQRCodeClickClient();
    void onStatByAge();
    void onStackedClientIndexChanged(int index);
    void openDeletePage(int clientId);
    void sendEmailWithQRCode(const QString& recipientEmail, const QString& clientData, const QString& firstName, const QString& lastName);
    void fillComboBoxClient();
    void UpdateClientByClick();
    //***********************************************************
    // Employee
    void onAddEmployeeClicked();
    void onDeleteEmployeeClicked();
    void onUpdateEmployeeClicked();
    void onSortEmployeeClicked();
    void onPdfEmployeeClicked();
    void onCancelClickedEmp_C();
    void onCancelClickedEmp_U();
    void onCancelClickedEmp_D();
    void clearInputFieldsEmployee();
    void EmployeeDashboardConnectUi();
    void openUpdateForm();
    QString mapRoleToString(int role);
    int  mapRoleToNumber(const QString& roleText);
    void onComboboxIndexChanged(int index);
    Employee* getEmployeeDataById(int id);
    void onSearchTextChanged(const QString& text);
    void displayEmployeeStats(int employeeID);
    void onEmployeeSelectStatsChanged(const QString& employeeName);
    void clearEmployeeStats();
    void displayGeneralStats();
    void openChatBox();
	void openEmployeesPresenceLog();
    //***********************************************************
    //Contract
    void onAddClickedContract();
    void onDeleteClickedContract();
    void onUpdateClickedContract();
    void onSortClickedContract();
    void onPdfClickedContract();
    void clearInputFieldsCreateContract();
    void clearInputFieldsUpdateContract();
    void clearInputFieldsDeleteContract();
    void clearInputFieldsContract();
    void onAddCancelClickedContract();
    void onUpdateCancelClickedContract();
    void onDeleteCancelClickedContract();
    void ContractDashboardConnectUi();
    void onStackedContractIndexChanged(int index);
    void openDelPage(int contractId);
    void onSearchIdContract(QString searched);
    void onStatByPremiumAmount();
    void onExcelClickedContract();
    void checkContractDates();
    void sendNotification(int id);
    //***********************************************************
    //Accident
    void onAddClickedAccident();
    void onDeleteClickedAccident();
    void onUpdateClickedAccident();
    void onSortClickedAccident();
    void onPdfClickedAccient();
    void clearInputFieldsAccidentDelete();
    void clearInputFieldsAccidentUpdate();
    void clearInputFieldsAccidentCreate();
    void onAddCancelClickedAccident();
    void onUpdateCancelClickedAccident();
    void onDeleteCancelClickedAccident();
    void AccidentDashboardConnectUi();
    void openDeletePageaccident(int acc_id);
    void onAccidentSearchTextChanged(const QString& searchText);
    void onHistoriqueAccidentclicked();
    void onstatsClickedAccident();
    void showMapAccident();
    void populateLocationComboBox();
    void populateClientComboBox();
    //***********************************************************
    //Arduino
    void printSerialMonitor();
    //RFID
    void startRFID();
    void handleEmployeeCheckedIn(int employeeId);
    //Accident Detector
    void startAccidentDetector();
    //------------------------------------------------------------------------------------------------------------------
private slots:
    void readAccidentData();
    void saveLogToFile(int employeeId, const QString& checkInTime);
    void onScanRFIDClicked();
    void processRFIDDataForCreation();
   
public:
    Ui::Dashboard* ui;
    MainWindow* mainWindowRef;
    Employee *user;
    QSystemTrayIcon* trayIcon;
    EmployeesRFID* empRFID;
    AccidentDetector* accidentDetector;
    QFile logFile;
    bool creatingEmployee = false;
    QString m_scannedUID;
};

#endif // DASHBOARD_H
