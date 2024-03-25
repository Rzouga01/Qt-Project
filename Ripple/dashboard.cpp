#include "dashboard.h"
#include "ui_dashboard.h"
#include <QApplication>
#include <QtWidgets>
#include <QUiLoader>
#include <QFileDialog>
#include "mainwindow.h"
#include "connection.h"
#include "client.h"
#include "employee.h"
#include "accident.h"
#include "contract.h"

Dashboard::Dashboard(QWidget* parent) :
	QDialog(parent),
	ui(new Ui::Dashboard)
{
	ui->setupUi(this);
	Client MasterClient(ui->tableClient, this);
	accident MasterAccident(ui->tableAccident, this);
	contract MasterContract(ui->tableContract, ui->StackContract, this);
	Employee Emp(ui->tableEmployee, this);
	Connection con;
	if (!con.createconnect()) {
		qDebug() << "Not Connected";
	}
	else {
		Emp.readEmployee();
		MasterClient.ReadClient();
		MasterAccident.accidentRead();
		MasterContract.ReadContract();
		openUpdateForm();
		update();
	}
}

void Dashboard::update() {
	// Dashboard Nav Buttons
	QObject::connect(ui->employees, &QPushButton::clicked, this, [this]() { ui->stackedWidget->setCurrentIndex(0); });
	QObject::connect(ui->clients, &QPushButton::clicked, this, [this]() { ui->stackedWidget->setCurrentIndex(1); });
	QObject::connect(ui->contracts, &QPushButton::clicked, this, [this]() { ui->stackedWidget->setCurrentIndex(2); });
	QObject::connect(ui->accidents, &QPushButton::clicked, this, [this]() { ui->stackedWidget->setCurrentIndex(3); });
	QObject::connect(ui->logoutButton, &QPushButton::clicked, this, &Dashboard::onLogoutButtonClicked);

	// Client
	ClientDashboardConnectUi();
	// Employee
	EmployeeDashboardConnectUi();
	// Contract
	ContractDashboardConnectUi();
	// Accident
	AccidentDashboardConnectUi();
}

void Dashboard::onLogoutButtonClicked() {
	close();
	mainWindowRef.show();
}
//--------------------------------------------------------------------------------------------------------------------------------
// Client
void Dashboard::ClientDashboardConnectUi() {
	Client MasterClient(ui->tableClient, ui->StackedClient, this);

    QObject::connect(ui->sortClient, &QPushButton::clicked, this, &Dashboard::onSortClickedClient);
	QObject::connect(ui->pdfClient, &QPushButton::clicked, this, &Dashboard::onPdfClickedClient);
	QObject::connect(ui->searchBarClient, &QLineEdit::textChanged, this, &Dashboard::onSearchIdClient);





	QObject::connect(ui->addClient, &QPushButton::clicked, this, [this]() { ui->StackedClient->setCurrentIndex(0); });
	QObject::connect(ui->updateClient, &QPushButton::clicked, this, [this]() { ui->StackedClient->setCurrentIndex(1); });
	QObject::connect(ui->deleteClient, &QPushButton::clicked, this, [this]() { ui->StackedClient->setCurrentIndex(2); });

    QObject::connect(ui->ClientCreateButton, &QPushButton::clicked, this, &Dashboard::onAddClickedClient);
	QObject::connect(ui->ClientUpdateButton, &QPushButton::clicked, this, &Dashboard::onUpdateClickedClient);
	QObject::connect(ui->ClientDeleteButton, &QPushButton::clicked, this, &Dashboard::onDeleteClickedClient);

	QObject::connect(ui->ClientCreateCancel, &QPushButton::clicked, this, &Dashboard::onAddCancelClickedClient);
	QObject::connect(ui->ClientUpdateCancel, &QPushButton::clicked, this, &Dashboard::onUpdateCancelClickedClient);
	QObject::connect(ui->ClientDeleteCancel, &QPushButton::clicked, this, &Dashboard::onDeleteCancelClickedClient);





	connect(&MasterClient, &Client::deleteClientRequested, this, &Dashboard::openDeletePage);

	ui->StackedClient->setCurrentIndex(0);
}

void Dashboard::openDeletePage(int clientId) {
	ui->StackedClient->setCurrentIndex(2);
	ui->ClientDeleteID->setText(QString::number(clientId));
}

void Dashboard::onStackedClientIndexChanged(int index) {
	switch (index) {
	case 0:
		ui->addClient->setStyleSheet("background-color: #D3D3D3;");
		ui->updateClient->setStyleSheet("background-color: transparent;");
		ui->deleteClient->setStyleSheet("background-color: transparent;");
		break;
	case 1:
		ui->addClient->setStyleSheet("background-color: transparent;");
		ui->updateClient->setStyleSheet("background-color: #D3D3D3;");
		ui->deleteClient->setStyleSheet("background-color: transparent;");
		break;
	case 2:
		ui->addClient->setStyleSheet("background-color: transparent;");
		ui->updateClient->setStyleSheet("background-color: transparent;");
		ui->deleteClient->setStyleSheet("background-color: #D3D3D3;");
		break;
	default:
		ui->addClient->setStyleSheet("background-color: transparent;");
		ui->updateClient->setStyleSheet("background-color: transparent;");
		ui->deleteClient->setStyleSheet("background-color: transparent;");
		break;
	}
}

void Dashboard::onAddClickedClient() {
	Client MasterClient(ui->tableClient, ui->StackedClient, this);

	if (ui->ClientCreateEmail->text().isEmpty() ||
		ui->ClientCreateFirstName->text().isEmpty() ||
		ui->ClientCreateLastName->text().isEmpty() ||
		ui->ClientCreatePhoneNumber->text().isEmpty() ||
		ui->ClientCreateAddress->text().isEmpty() ||
		ui->ClientCreateDob->date().isNull()) {

		QMessageBox::critical(this, tr("Error"), tr("Please fill in all fields"), QMessageBox::Ok, QMessageBox::Ok);

		clearInputFieldsCreateClient();
	}
	else {
		// Validate phone number
		QString phoneNumber = ui->ClientCreatePhoneNumber->text();
		bool validPhoneNumber = phoneNumber.length() == 8 && phoneNumber.toInt(&validPhoneNumber) && validPhoneNumber;

		// Validate email
		QString email = ui->ClientCreateEmail->text();
		bool validEmail = email.contains("@") && email.contains(".");

		if (!validPhoneNumber) {
			QMessageBox::critical(this, tr("Error"), tr("Please enter a valid 8-digit phone number"), QMessageBox::Ok, QMessageBox::Ok);
		}
		else if (!validEmail) {
			QMessageBox::critical(this, tr("Error"), tr("Please enter a valid email address"), QMessageBox::Ok, QMessageBox::Ok);
		}
		else {
			if (MasterClient.CreateClient(ui->ClientCreateEmail->text(),
				ui->ClientCreateFirstName->text(),
				ui->ClientCreateLastName->text(),
				ui->ClientCreatePhoneNumber->text(),
				ui->ClientCreateAddress->text(),
				ui->ClientCreateDob->date())) {
				MasterClient.ReadClient();
				clearInputFieldsCreateClient();
				QMessageBox::information(this, tr("Success"), tr("Client created successfully"), QMessageBox::Ok, QMessageBox::Ok);
			}
			else {
				QMessageBox::critical(this, tr("Error"), tr("Client not created"), QMessageBox::Ok, QMessageBox::Ok);
			}
		}
	}
}

void Dashboard::onUpdateClickedClient() {
	Client MasterClient(ui->tableClient, ui->StackedClient, this);

	if (ui->ClientUpdateEmail->text().isEmpty() ||
		ui->ClientUpdateFirstName->text().isEmpty() ||
		ui->ClientUpdateLastName->text().isEmpty() ||
		ui->ClientUpdatePhoneNumber->text().isEmpty() ||
		ui->ClientUpdateAddress->text().isEmpty() ||
		ui->ClientUpdateDob->date().isNull()) {

		QMessageBox::critical(this, tr("Error"), tr("Please fill in all fields"), QMessageBox::Ok, QMessageBox::Ok);

		clearInputFieldsUpdateClient();
	}
	else {
		// Validate ID
		QString id = ui->ClientUpdateID->text();
		bool validId = id.toInt(&validId) && validId;

		// Validate phone number
		QString phoneNumber = ui->ClientUpdatePhoneNumber->text();
		bool validPhoneNumber = phoneNumber.length() == 8 && phoneNumber.toInt(&validPhoneNumber) && validPhoneNumber;

		// Validate email
		QString email = ui->ClientUpdateEmail->text();
		bool validEmail = email.contains("@") && email.contains(".");

		if (!validPhoneNumber) {
			QMessageBox::critical(this, tr("Error"), tr("Please enter a valid 8-digit phone number"), QMessageBox::Ok, QMessageBox::Ok);
		}
		else if (!validEmail) {
			QMessageBox::critical(this, tr("Error"), tr("Please enter a valid email address"), QMessageBox::Ok, QMessageBox::Ok);
		}
		else if (!validId) {
			QMessageBox::critical(this, tr("Error"), tr("Please enter a valid ID"), QMessageBox::Ok, QMessageBox::Ok);
		}
		else {
			if (MasterClient.UpdateClient(id.toInt(), ui->ClientUpdateEmail->text(),
				ui->ClientUpdateFirstName->text(),
				ui->ClientUpdateLastName->text(),
				ui->ClientUpdatePhoneNumber->text(),
				ui->ClientUpdateAddress->text(),
				ui->ClientUpdateDob->date())) {
				MasterClient.ReadClient();
				clearInputFieldsUpdateClient();
				QMessageBox::information(this, tr("Success"), tr("Client Updated successfully"), QMessageBox::Ok, QMessageBox::Ok);
			}
			else {
				QMessageBox::critical(this, tr("Error"), tr("Client not found"), QMessageBox::Ok, QMessageBox::Ok);
			}
		}
	}
}

void Dashboard::onDeleteClickedClient() {
	Client MasterClient(ui->tableClient, ui->StackedClient, this);

	if (ui->ClientDeleteID->text().isEmpty()) {
		QMessageBox::critical(this, tr("Error"), tr("Please fill in all fields"), QMessageBox::Ok, QMessageBox::Ok);
	}
	else {
		// Validate ID
		QString id = ui->ClientDeleteID->text();
		bool validId = id.toInt(&validId) && validId;

		if (!validId) {
			QMessageBox::critical(this, tr("Error"), tr("Please enter a valid ID"), QMessageBox::Ok, QMessageBox::Ok);
		}
		else {
			if (MasterClient.DeleteClient(id.toInt())) {
				MasterClient.ReadClient();
				clearInputFieldsDeleteClient();
				QMessageBox::information(this, tr("Success"), tr("Client Deleted successfully"), QMessageBox::Ok, QMessageBox::Ok);
			}
			else {
				QMessageBox::critical(this, tr("Error"), tr("Client not found"), QMessageBox::Ok, QMessageBox::Ok);
			}
		}
	}
}

void Dashboard::onAddCancelClickedClient() {
	clearInputFieldsCreateClient();
}

void Dashboard::onUpdateCancelClickedClient() {
	clearInputFieldsUpdateClient();
}

void Dashboard::onDeleteCancelClickedClient() {
	clearInputFieldsDeleteClient();
}

void Dashboard::clearInputFieldsCreateClient() {
	ui->ClientCreateEmail->clear();
	ui->ClientCreateFirstName->clear();
	ui->ClientCreateLastName->clear();
	ui->ClientCreatePhoneNumber->clear();
	ui->ClientCreateAddress->clear();
	ui->ClientCreateDob->setDate(QDate());
}

void Dashboard::clearInputFieldsUpdateClient() {
	ui->ClientUpdateID->clear();
	ui->ClientUpdateEmail->clear();
	ui->ClientUpdateFirstName->clear();
	ui->ClientUpdateLastName->clear();
	ui->ClientUpdatePhoneNumber->clear();
	ui->ClientUpdateAddress->clear();
	ui->ClientUpdateDob->setDate(QDate());
}

void Dashboard::clearInputFieldsDeleteClient() {
	ui->ClientDeleteID->clear();
}




void Dashboard::onSortClickedClient() {
	static bool isSorted = false;

	Client MasterClient(ui->tableClient, this);
	MasterClient.sortClientFirstName(isSorted); // Pass the sorting order parameter

	isSorted = !isSorted; // Toggle the sorting order for the next call
}


void Dashboard::onPdfClickedClient() {
	QString filePath = QFileDialog::getSaveFileName(this, tr("Save PDF"), "", "PDF Files (*.pdf)");
	if (!filePath.isEmpty()) {
		Client MasterClient(ui->tableClient,this);
		MasterClient.toPdf(filePath);
	}
}


void Dashboard::onSearchIdClient(QString searched) {
	Client MasterClient(ui->tableClient, this);
	QString id = ui->searchBarClient->text();
	MasterClient.searchClientID(id);
}

/*
void Dashboard::onStatByAge() {
	Client MasterClient(ui->tableClient, this);
	MasterClient.statsByAge();
}*/




//********************************************************************************************************************
// Employee
void Dashboard::EmployeeDashboardConnectUi() {
	QObject::connect(ui->addEmployee, &QPushButton::clicked, this, [this]() { ui->CrudEmployee->setCurrentIndex(0); });
	QObject::connect(ui->updateEmployee, &QPushButton::clicked, this, [this]() { ui->CrudEmployee->setCurrentIndex(1); });
	QObject::connect(ui->deleteEmployee, &QPushButton::clicked, this, [this]() { ui->CrudEmployee->setCurrentIndex(2); });

	QObject::connect(ui->EmployeeCreateBtn, &QPushButton::clicked, this, &Dashboard::onAddEmployeeClicked);
	QObject::connect(ui->EmployeeUpdateBtn, &QPushButton::clicked, this, &Dashboard::onUpdateEmployeeClicked);
	QObject::connect(ui->EmployeeDeleteBtn, &QPushButton::clicked, this, &Dashboard::onDeleteEmployeeClicked);

	QObject::connect(ui->EmployeeCancelBtn_C, &QPushButton::clicked, this, &Dashboard::onCancelClickedEmp_C);

	QObject::connect(ui->sortEmployee, &QPushButton::clicked, this, &Dashboard::onSortEmployeeClicked);
	QObject::connect(ui->pdfEmployee, &QPushButton::clicked, this, &Dashboard::onPdfEmployeeClicked);
	QObject::connect(ui->searchBarEmployee, &QLineEdit::textChanged, this, &Dashboard::onSearchTextChanged);

	ui->CrudEmployee->setCurrentIndex(0);
}

int mapRoleToNumber(const QString& roleText) {
	if (roleText == "Role 1")
		return 0;
	else if (roleText == "Role 2")
		return 1;
	else if (roleText == "Role 3")
		return 2;
	else
		return -1;
}

void Dashboard::onAddEmployeeClicked() {
	Employee emp(ui->tableEmployee, this);

	QString email = ui->EmployeeEmail_C->text();
	QString password = ui->EmployeePassword_C->text();
	QString roleText = ui->EmployeeRole_C->currentText();
	QString firstName = ui->EmployeeFirstName_C->text();
	QString lastName = ui->EmployeeLastName_C->text();
	QString phoneNumber = ui->EmployeePhoneNumber_C->text();
	QString address = ui->EmployeeAddress_C->text();
	QDate dob = ui->EmployeeDob_C->date();

	int role = mapRoleToNumber(roleText);

	if (email.isEmpty() || password.isEmpty() || roleText.isEmpty() || firstName.isEmpty() ||
		lastName.isEmpty() || phoneNumber.isEmpty() || address.isEmpty() || dob.isNull()) {
		QMessageBox::critical(this, tr("Error"), tr("Please fill in all fields"), QMessageBox::Ok, QMessageBox::Ok);
		return;
	}

	if (!email.contains('@') || !email.contains('.')) {
		QMessageBox::critical(this, tr("Error"), tr("Please enter a valid email address"), QMessageBox::Ok, QMessageBox::Ok);
		return;
	}

	if (password.length() < 8) {
		QMessageBox::critical(this, tr("Error"), tr("Password must be at least 8 characters long"), QMessageBox::Ok, QMessageBox::Ok);
		return;
	}

	if (phoneNumber.length() != 8 || !phoneNumber.toInt()) {
		QMessageBox::critical(this, tr("Error"), tr("Please enter a valid 8-digit phone number"), QMessageBox::Ok, QMessageBox::Ok);
		return;
	}

	if (!firstName.contains(QRegularExpression("^[a-zA-Z]+$")) || !lastName.contains(QRegularExpression("^[a-zA-Z]+$"))) {
		QMessageBox::critical(this, tr("Error"), tr("Please enter valid first and last names"), QMessageBox::Ok, QMessageBox::Ok);
		return;
	}

	emp.createEmployee(email, password, role, firstName, lastName, phoneNumber, address, dob);

	emp.readEmployee();

	openUpdateForm();

	QMessageBox::information(this, tr("Success"), tr("Employee created successfully"), QMessageBox::Ok, QMessageBox::Ok);
}

void Dashboard::onUpdateEmployeeClicked() {
	int selectedId = ui->EmployeeSelectID_U->currentText().toInt();

	QString email = ui->EmployeeEmail_U->text();
	QString password = ui->EmployeePassword_U->text();
	int role = ui->EmployeeRole_U->currentIndex();
	QString firstName = ui->EmployeeFirstName_U->text();
	QString lastName = ui->EmployeeLastName_U->text();
	QString phoneNumber = ui->EmployeePhoneNumber_U->text();
	QString address = ui->EmployeeAddress_U->text();
	QDate dob = ui->EmployeeDob_U->date();

	if (email.isEmpty() || password.isEmpty() || firstName.isEmpty() || lastName.isEmpty() ||
		phoneNumber.isEmpty() || address.isEmpty() || dob.isNull()) {
		QMessageBox::critical(this, tr("Error"), tr("Please fill in all fields"), QMessageBox::Ok, QMessageBox::Ok);
		return;
	}

	if (!email.contains('@') || !email.contains('.')) {
		QMessageBox::critical(this, tr("Error"), tr("Please enter a valid email address"), QMessageBox::Ok, QMessageBox::Ok);
		return;
	}

	if (password.length() < 8) {
		QMessageBox::critical(this, tr("Error"), tr("Password must be at least 8 characters long"), QMessageBox::Ok, QMessageBox::Ok);
		return;
	}

	if (phoneNumber.length() != 8 || !phoneNumber.toInt()) {
		QMessageBox::critical(this, tr("Error"), tr("Please enter a valid 8-digit phone number"), QMessageBox::Ok, QMessageBox::Ok);
		return;
	}

	if (!firstName.contains(QRegularExpression("^[a-zA-Z]+$")) || !lastName.contains(QRegularExpression("^[a-zA-Z]+$"))) {
		QMessageBox::critical(this, tr("Error"), tr("Please enter valid first and last names"), QMessageBox::Ok, QMessageBox::Ok);
		return;
	}

	Employee emp;

	if (emp.updateEmployee(selectedId, email, password, role, firstName, lastName, phoneNumber, address, dob)) {
		Employee emp(ui->tableEmployee);
		emp.readEmployee();
		openUpdateForm();

		QMessageBox::information(this, "Success", "Employee updated successfully.");
	}
	else {
		QMessageBox::critical(this, "Error", "Failed to update employee.");
	}
}

void Dashboard::onDeleteEmployeeClicked() {
	QString selectedId = ui->EmployeeSelectID_D->currentText();

	if (!selectedId.isEmpty()) {
		int idToDelete = selectedId.toInt();

		Employee e(ui->tableEmployee);
		if (e.deleteEmployee(idToDelete)) {
			e.readEmployee();

			openUpdateForm();

			QMessageBox::information(this, "Success", "Employee deleted successfully.");
		}
		else {
			QMessageBox::critical(this, "Error", "Failed to delete employee.");
		}
	}
}

void Dashboard::openUpdateForm() {
	if (ui->EmployeeSelectID_U) {
		Employee e(ui->tableEmployee);
		QStringList ids = e.getAllEmployeeIDs();
		ids.prepend("");

		ui->EmployeeSelectID_U->clear();
		ui->EmployeeSelectID_U->addItems(ids);

		ui->EmployeeSelectID_U->setCurrentIndex(0);

		QObject::connect(ui->EmployeeSelectID_U, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &Dashboard::onComboboxIndexChanged);
	}
	else {
		qDebug() << "Error choosing update.";
	}

	if (ui->EmployeeSelectID_D) {
		Employee e(ui->tableEmployee);
		QStringList ids = e.getAllEmployeeIDs();
		ids.prepend("");

		ui->EmployeeSelectID_D->clear();
		ui->EmployeeSelectID_D->addItems(ids);

		ui->EmployeeSelectID_D->setCurrentIndex(0);
	}
	else {
		qDebug() << "Error choosing delete.";
	}

	// Clear role and birthday combo boxes initially
	ui->EmployeeRole_U->clear();
	ui->EmployeeDob_U->setDate(QDate());
}

void Dashboard::onComboboxIndexChanged(int index) {
	if (index >= 0) {
		QString selectedId = ui->EmployeeSelectID_U->itemText(index);
		Employee* employeeData = getEmployeeDataById(selectedId.toInt());
		if (employeeData) {

			ui->EmployeeEmail_U->setText(employeeData->getEmail());
			ui->EmployeePassword_U->setText(employeeData->getPassword());


			ui->EmployeeRole_U->clear();
			ui->EmployeeRole_U->addItem("Role 1");
			ui->EmployeeRole_U->addItem("Role 2");
			ui->EmployeeRole_U->addItem("Role 3");
			

			ui->EmployeeRole_U->setCurrentIndex(employeeData->getRole());

			ui->EmployeeDob_U->setDate(employeeData->getDOB());

			ui->EmployeeFirstName_U->setText(employeeData->getFirstName());
			ui->EmployeeLastName_U->setText(employeeData->getLastName());
			ui->EmployeePhoneNumber_U->setText(employeeData->getPhoneNumber());
			ui->EmployeeAddress_U->setText(employeeData->getAddress());

			delete employeeData;
		}
		else {
			ui->EmployeeEmail_U->clear();
			ui->EmployeePassword_U->clear();
			ui->EmployeeRole_U->clear();
			ui->EmployeeDob_U->setDate(QDate(2000, 1, 1));
			ui->EmployeeFirstName_U->clear();
			ui->EmployeeLastName_U->clear();
			ui->EmployeePhoneNumber_U->clear();
			ui->EmployeeAddress_U->clear();
			qDebug() << "Error: Unable to retrieve employee data.";
		}
	}
	else {

		ui->EmployeeEmail_U->clear();
		ui->EmployeePassword_U->clear();
		ui->EmployeeRole_U->clear();
		ui->EmployeeDob_U->setDate(QDate(2000, 1, 1));
		ui->EmployeeFirstName_U->clear();
		ui->EmployeeLastName_U->clear();
		ui->EmployeePhoneNumber_U->clear();
		ui->EmployeeAddress_U->clear();
	}
}

Employee* Dashboard::getEmployeeDataById(int id) {
	QSqlQuery query;
	query.prepare("SELECT * FROM EMPLOYEES WHERE USER_ID = ?");
	query.bindValue(0, id);
	if (query.exec() && query.next()) {
		Employee* data = new Employee(
			query.value("email").toString(),
			query.value("password").toString(),
			query.value("role").toInt(),
			query.value("first_name").toString(),
			query.value("last_name").toString(),
			query.value("phone_number").toString(),
			query.value("address").toString(),
			query.value("dob").toDate()
		);
		return data;
	}
	else {
		qDebug() << "Error: Unable to retrieve employee data. Error details:" << query.lastError().text();
		return nullptr;
	}

}

void Dashboard::clearInputFieldsEmployee() {
	ui->EmployeeEmail_C->clear();
	ui->EmployeePassword_C->clear();
	ui->EmployeeRole_C->setCurrentIndex(0);
	ui->EmployeeFirstName_C->clear();
	ui->EmployeeLastName_C->clear();
	ui->EmployeePhoneNumber_C->clear();
	ui->EmployeeAddress_C->clear();
	ui->EmployeeDob_C->setDate(QDate(2000, 1, 1));
}

void Dashboard::onCancelClickedEmp_C() {
	clearInputFieldsEmployee();
}

void Dashboard::onSortEmployeeClicked() {
	static bool isSorted = false;

	if (!isSorted) {
		Employee emp(ui->tableEmployee);
		emp.sortEmployeesByAge();
		isSorted = true;
	}
	else {
		Employee emp(ui->tableEmployee);
		emp.readEmployee();
		isSorted = false;
	}
}

void Dashboard::onPdfEmployeeClicked() {
	QString filePath = QFileDialog::getSaveFileName(this, tr("Save PDF"), "", "PDF Files (*.pdf)");
	if (!filePath.isEmpty()) {
		Employee emp(ui->tableEmployee);
		emp.ExportEmployeesToPdf(filePath);
	}
}

void Dashboard::onSearchTextChanged(const QString& searchText) {
	Employee emp(ui->tableEmployee);
	emp.searchEmployee(searchText);
}

//********************************************************************************************************************
// Contract
void Dashboard::ContractDashboardConnectUi() {
	contract MasterContract(ui->tableContract, ui->StackContract, this);


	//QObject::connect(ui->sortContract,&QPushButton::clicked,this,&Dashboard::onSortClickedContract);
	//QObject::connect(ui->pdfContract ,&QPushButton::clicked,this,&Dashboard::onPdfClickedContract);


	QObject::connect(ui->addContract, &QPushButton::clicked, this, [this]() {ui->StackContract->setCurrentIndex(0); });
	QObject::connect(ui->updateContract, &QPushButton::clicked, this, [this]() {ui->StackContract->setCurrentIndex(2); });
	QObject::connect(ui->deleteContract, &QPushButton::clicked, this, [this]() {ui->StackContract->setCurrentIndex(1); });


	QObject::connect(ui->CreateContractButton, &QPushButton::clicked, this, &Dashboard::onAddClickedContract);
	QObject::connect(ui->UpdateContractButton, &QPushButton::clicked, this, &Dashboard::onUpdateClickedContract);
	QObject::connect(ui->DeleteContractButton, &QPushButton::clicked, this, &Dashboard::onDeleteClickedContract);





	ui->StackContract->setCurrentIndex(0);



}

void Dashboard::openDelPage(int contractId) {

	ui->StackContract->setCurrentIndex(2);

	ui->LineEditContractID->setText(QString::number(contractId));
}

void Dashboard::onStackedContractIndexChanged(int index) {
	switch (index) {
	case 0:
		ui->addContract->setStyleSheet("background-color: #D3D3D3;");
		ui->updateContract->setStyleSheet("background-color: transparent;");
		ui->deleteContract->setStyleSheet("background-color: transparent;");
		break;

	case 1:
		ui->addContract->setStyleSheet("background-color: transparent;");
		ui->UpdateContract->setStyleSheet("background-color: #D3D3D3;");
		ui->deleteContract->setStyleSheet("background-color: transparent;");
		break;

	case 2:
		ui->addContract->setStyleSheet("background-color: transparent;");
		ui->UpdateContract->setStyleSheet("background-color: transparent;");
		ui->deleteContract->setStyleSheet("background-color: #D3D3D3;");
		break;

	default:
		ui->addContract->setStyleSheet("background-color: transparent;");
		ui->updateContract->setStyleSheet("background-color: transparent;");
		ui->deleteContract->setStyleSheet("background-color: transparent;");
		break;


	}
}

void Dashboard::onAddClickedContract() {
	contract MasterContract(ui->tableContract, ui->StackContract, this);

	QString clientIdStr = ui->LineEditClientIdContract->text();
	QString userIdStr = ui->LineEditUserIdContract->text();
	QString premiumAmountStr = ui->LineEditPremiumAmountContract->text();
	QDate effectiveDate = ui->dateEditEffectiveDateContract->date();
	QDate expirationDate = ui->dateEditExpirationDateContract->date();
	QString paymentStatusStr = ui->LineEditPaymentstatusContract->text();
	QString type = ui->lineEditTypeContract->text();

	// Vérifier si les champs obligatoires ne sont pas vides
	if (clientIdStr.isEmpty() || userIdStr.isEmpty() ||
		premiumAmountStr.isEmpty() || paymentStatusStr.isEmpty() ||
		effectiveDate.isNull() || expirationDate.isNull()) {

		QMessageBox::critical(this, tr("Error"), tr("Please fill in all fields"), QMessageBox::Ok);
		clearInputFieldsCreateContract();
		return;
	}

	// Convertir les valeurs saisies en types appropriés
	int clientId = clientIdStr.toInt();
	int userId = userIdStr.toInt();
	int premiumAmount = premiumAmountStr.toInt();
	int paymentStatus = paymentStatusStr.toInt();

	// Vérifier si les champs numériques sont valides
	if (clientId <= 0 || userId <= 0 || premiumAmount <= 0 || (paymentStatus != 0 && paymentStatus != 1)) {
		QMessageBox::critical(this, tr("Error"), tr("Invalid input for numeric fields or payment status"), QMessageBox::Ok);
		clearInputFieldsCreateContract();
		return;
	}

	// Appeler la fonction CreateContract avec les valeurs extraites
	if (MasterContract.CreateContract(userId, clientId, premiumAmount, effectiveDate, expirationDate, paymentStatus, type)) {
		MasterContract.ReadContract();
		clearInputFieldsCreateContract();
		QMessageBox::information(this, tr("Success"), tr("Contract created successfully"), QMessageBox::Ok);
	}
	else {
		QMessageBox::critical(this, tr("Error"), tr("Contract not created"), QMessageBox::Ok);
	}
}

void Dashboard::clearInputFieldsContract() {
	ui->LineEditUserIdContract->clear();
	ui->LineEditClientIdContract->clear();
	ui->LineEditPremiumAmountContract->clear();
	ui->dateEditEffectiveDateContract->setDate(QDate());
	ui->dateEditExpirationDateContract->setDate(QDate());
	ui->LineEditPaymentstatusContract->clear();
	ui->lineEditTypeContract->clear();
}

void Dashboard::onUpdateClickedContract() {
	contract MasterContract(ui->tableContract, ui->StackContract, this);

	int contractId = ui->lineEditContractIDUpdate->text().toInt();
	QString userIdStr = ui->LineEditUserIdContractUpdate->text().trimmed();
	QString clientIdStr = ui->LineEditClientIdContractUpdate->text().trimmed();
	QString premiumAmountStr = ui->LineEditPremiumAmountContractUpdate->text().trimmed();
	QDate effectiveDate = ui->dateEditEffectiveDateContractUpdate->date();
	QDate expirationDate = ui->dateEditExpirationDateContractUpdate->date();
	QString paymentStatusStr = ui->LineEditPaymentstatusContractUpdate->text().trimmed();
	QString type = ui->lineEditTypeContractUpdate->text().trimmed();

	if (userIdStr.isEmpty() || clientIdStr.isEmpty() || premiumAmountStr.isEmpty() || paymentStatusStr.isEmpty() || type.isEmpty()) {
		QMessageBox::critical(this, tr("Error"), tr("Please fill in all fields"), QMessageBox::Ok);
		clearInputFieldsUpdateContract();
		return;
	}

	bool conversionOk;
	int userId = userIdStr.toInt(&conversionOk);
	int clientId = clientIdStr.toInt(&conversionOk);
	int premiumAmount = premiumAmountStr.toInt(&conversionOk);
	int paymentStatus = paymentStatusStr.toInt(&conversionOk);

	if (!conversionOk || contractId <= 0 || userId <= 0 || clientId <= 0 || premiumAmount <= 0 || (paymentStatus != 0 && paymentStatus != 1)) {
		QMessageBox::critical(this, tr("Error"), tr("Invalid input for numeric fields or payment status"), QMessageBox::Ok);
		clearInputFieldsUpdateContract();
		return;
	}

	if (!effectiveDate.isValid() || !expirationDate.isValid()) {
		QMessageBox::critical(this, tr("Error"), tr("Invalid date format"), QMessageBox::Ok);
		clearInputFieldsUpdateContract();
		return;
	}

	if (effectiveDate > expirationDate) {
		QMessageBox::critical(this, tr("Error"), tr("Effective date cannot be greater than expiration date"), QMessageBox::Ok);
		clearInputFieldsUpdateContract();
		return;
	}

	if (MasterContract.UpdateContract(contractId, userId, clientId, premiumAmount, effectiveDate, expirationDate, paymentStatus, type)) {
		MasterContract.ReadContract();
		clearInputFieldsUpdateContract();
		QMessageBox::information(this, tr("Success"), tr("Contract updated successfully"), QMessageBox::Ok);
	}
	else {
		QMessageBox::critical(this, tr("Error"), tr("Contract not updated"), QMessageBox::Ok);
	}
}

void Dashboard::onDeleteClickedContract() {
	contract MasterContract(ui->tableContract, ui->StackContract, this);
	if (ui->LineEditContractID->text().isEmpty()) {
		QMessageBox::critical(this, tr("Error"), tr("Please fill in all fields"), QMessageBox::Ok, QMessageBox::Ok);
	}
	else {
		QString id = ui->LineEditContractID->text();
		bool ValidId = id.toInt(&ValidId) && ValidId;

		if (!ValidId) {
			QMessageBox::critical(this, tr("Error"), tr("Please enter a valid ID"), QMessageBox::Ok, QMessageBox::Ok);
		}
		else {
			if (MasterContract.DeleteContract(id.toInt())) {
				MasterContract.ReadContract();
				clearInputFieldsContract();
				QMessageBox::information(this, tr("Success"), tr("Contract Deleted successfully"), QMessageBox::Ok, QMessageBox::Ok);
			}
			else {
				QMessageBox::information(this, tr("Error"), tr("Contract Not found"), QMessageBox::Ok, QMessageBox::Ok);
			}
		}
	}
}

void Dashboard::onAddCancelClickedContract() {
	clearInputFieldsCreateContract();
}

void Dashboard::onUpdateCancelClickedContract() {
	clearInputFieldsUpdateContract();
}

void Dashboard::onDeleteCancelClickedContract() {
	clearInputFieldsDeleteContract();
}

void Dashboard::clearInputFieldsCreateContract() {
	ui->LineEditUserIdContract->clear();
	ui->LineEditClientIdContract->clear();
	ui->LineEditPremiumAmountContract->clear();
	ui->dateEditEffectiveDateContract->setDate(QDate());
	ui->dateEditExpirationDateContract->setDate(QDate());
	ui->LineEditPaymentstatusContract->clear();
	ui->lineEditTypeContract->clear();
}

void Dashboard::clearInputFieldsUpdateContract() {
	ui->LineEditUserIdContractUpdate->clear();
	ui->LineEditClientIdContractUpdate->clear();
	ui->LineEditPremiumAmountContractUpdate->clear();
	ui->dateEditEffectiveDateContractUpdate->setDate(QDate());
	ui->dateEditExpirationDateContractUpdate->setDate(QDate());
	ui->LineEditPaymentstatusContractUpdate->clear();
	ui->lineEditTypeContractUpdate->clear();

}

void Dashboard::clearInputFieldsDeleteContract() {
	ui->LineEditContractID->clear();
}
//********************************************************************************************************************
//Accident
void Dashboard::AccidentDashboardConnectUi()
{
	accident MasterAccident(ui->tableAccident, this);



	QObject::connect(ui->sortAccident, &QPushButton::clicked, this, &Dashboard::onSortClickedAccident);
	QObject::connect(ui->pdfAccident, &QPushButton::clicked, this, &Dashboard::onPdfClickedAccient);


	QObject::connect(ui->addAccident, &QPushButton::clicked, this, [this]() { ui->StackedAccident->setCurrentIndex(0); });
	QObject::connect(ui->updateAccident, &QPushButton::clicked, this, [this]() { ui->StackedAccident->setCurrentIndex(2); });
	QObject::connect(ui->deleteAccident, &QPushButton::clicked, this, [this]() { ui->StackedAccident->setCurrentIndex(1); });

	QObject::connect(ui->AccidentSubmit, &QPushButton::clicked, this, &Dashboard::onAddClickedAccident);
	QObject::connect(ui->AccidentUpdate, &QPushButton::clicked, this, &Dashboard::onUpdateClickedAccident);
	QObject::connect(ui->AccidentDelete, &QPushButton::clicked, this, &Dashboard::onDeleteClickedAccident);

	QObject::connect(ui->AccidentCancel, &QPushButton::clicked, this, &Dashboard::onAddCancelClickedAccident);

	QSqlQuery query;

	if (!query.exec("SELECT * FROM CLIENTS")) {
		qDebug() << "Error executing query:" << query.lastError().text();
		return;
	}

	int rowCount = 0;  // Counter to track the number of rows fetched
	while (query.next()) {
		QString clientName = query.value(2).toString();
		QVariant clientId = query.value(0).toInt();

		qDebug() << "Adding item:" << clientName << "ID:" << clientId;

		ui->AccidentCreateClientID->addItem(clientName, clientId);
		ui->AccidentUpdateClientID->addItem(clientName, clientId);

		rowCount++;
	}

	qDebug() << "Total rows fetched:" << rowCount;

	ui->StackedAccident->setCurrentIndex(0);
}

void Dashboard::onAddCancelClickedAccident() {
	clearInputFieldsAccidentCreate();
}

void Dashboard::onSortClickedAccident() {}

void Dashboard::onPdfClickedAccient() {}

void Dashboard::clearInputFieldsAccidentDelete() {
	ui->AccidentDeleteID->clear();
}

void Dashboard::clearInputFieldsAccidentCreate() {
	ui->AccidentCreateType->clear();
	ui->AccidentCreateDamage->clear();
	ui->AccidentCreateDate->clear();
	ui->AccidentCreateLocation->clear();
}

void Dashboard::clearInputFieldsAccidentUpdate() {
	ui->AccidentUpdateID->clear();
	ui->AccidentUpdateType->clear();
	ui->AccidentUpdateDamage->clear();
	ui->AccidentUpdateDate->clear();
	ui->AccidentUpdateLocation->clear();
}

void Dashboard::onDeleteClickedAccident() {
	accident MasterAccident(ui->tableAccident, this);

	if (ui->AccidentDeleteID->text().isEmpty()) {
		QMessageBox::critical(this, tr("Error"), tr("Please fill in all fields"));
	}
	else {
		QString id = ui->AccidentDeleteID->text();
		if (MasterAccident.Delete(id.toInt())) {
			MasterAccident.accidentRead();
			clearInputFieldsAccidentDelete();
			QMessageBox::information(this, tr("Success"), tr("Accident deleted successfully"));
		}
		else {
			QMessageBox::critical(this, tr("Error"), tr("Accident not found"));
		}
	}
}

void Dashboard::onAddClickedAccident() {
	accident MasterAccident(ui->tableAccident, this);


	if (ui->AccidentCreateType->text().isEmpty() ||
		ui->AccidentCreateDamage->text().isEmpty() ||
		ui->AccidentCreateDate->date().isNull() ||
		ui->AccidentCreateClientID->currentData().isNull() ||
		ui->AccidentCreateLocation->text().isEmpty())

	{

		QMessageBox::critical(this, tr("Error"), tr("Please fill in all fields"), QMessageBox::Ok, QMessageBox::Ok);

		clearInputFieldsAccidentCreate();
	}
	else {

		if (MasterAccident.create(
			ui->AccidentCreateType->text(),
			ui->AccidentCreateDamage->text().toInt(),
			ui->AccidentCreateDate->date(),
			ui->AccidentCreateLocation->text(),
			ui->AccidentCreateClientID->currentData().toInt()))
		{
			MasterAccident.accidentRead();

			clearInputFieldsAccidentCreate();

			QMessageBox::information(this, tr("Success"), tr("Accident created successfully"), QMessageBox::Ok, QMessageBox::Ok);
		}
		else
		{
			QMessageBox::critical(this, tr("Error"), tr("accident not created"), QMessageBox::Ok, QMessageBox::Ok);
		}
	}
}

void Dashboard::onUpdateClickedAccident() {
	accident MasterAccident(ui->tableAccident, this);


	if (
		ui->AccidentUpdateType->text().isEmpty() ||
		ui->AccidentUpdateDamage->text().isEmpty() ||
		ui->AccidentUpdateDate->text().isEmpty() ||
		ui->AccidentUpdateLocation->text().isEmpty() ||
		ui->AccidentUpdateClientID->currentData().isNull()) {

		QMessageBox::critical(this, tr("Error"), tr("Please fill in all fields"), QMessageBox::Ok, QMessageBox::Ok);

		clearInputFieldsAccidentUpdate();
	}
	else {
		// Validate ID
		QString id = ui->AccidentUpdateID->text();
		bool validId = id.toInt(&validId) && validId;


		if (!validId) {
			QMessageBox::critical(this, tr("Error"), tr("Please enter a valid ID"), QMessageBox::Ok, QMessageBox::Ok);
		}
		else {

			MasterAccident.update(id.toInt(),
				ui->AccidentUpdateType->text(),
				ui->AccidentUpdateDamage->text().toInt(),
				ui->AccidentUpdateDate->date(),
				ui->AccidentUpdateLocation->text(),
				ui->AccidentUpdateClientID->currentData().toInt());

			MasterAccident.accidentRead();

			clearInputFieldsAccidentUpdate();

			QMessageBox::information(this, tr("Success"), tr("Accident Updated successfully"), QMessageBox::Ok, QMessageBox::Ok);

		}
	}
}
//--------------------------------------------------------------------------------------------------------------------------------
Dashboard::~Dashboard() {
	delete ui;
}
