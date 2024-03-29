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
	void onComboboxIndexChanged(int index);
	Employee* getEmployeeDataById(int id);
	void onSearchTextChanged(const QString& text);
	void displayEmployeeStats(int employeeID);
	void onEmployeeSelectStatsChanged(const QString& employeeName);
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
	//------------------------------------------------------------------------------------------------------------------
public:
	Ui::Dashboard* ui;
	MainWindow mainWindowRef;
};

#endif // DASHBOARD_H
