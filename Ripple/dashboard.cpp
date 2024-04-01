#include "dashboard.h"
#include "ui_dashboard.h"
#include <QApplication>
#include <QtWidgets>
#include <QUiLoader>
#include <QFileDialog>
#include <QtCharts>
#include <QtDebug>
#include "mainwindow.h"
#include "connection.h"
#include "client.h"
#include "employee.h"
#include "accident.h"
#include "contract.h"
#include "mailer.h"
#include "chatbot.h"
#include <QCoreApplication>
#include <QDebug>
#include <QTcpSocket>
#include <QFile>
#include <QTextStream>
#include <QSslSocket>
#include <QtCore/QProcessEnvironment>

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
	QObject::connect(ui->pieChartClient, &QPushButton::clicked, this, &Dashboard::onStatByAge);





	QObject::connect(ui->addClient, &QPushButton::clicked, this, [this]() { ui->StackedClient->setCurrentIndex(0); });
	QObject::connect(ui->updateClient, &QPushButton::clicked, this, [this]() { ui->StackedClient->setCurrentIndex(1); });
	QObject::connect(ui->deleteClient, &QPushButton::clicked, this, [this]() { ui->StackedClient->setCurrentIndex(2); });

	QObject::connect(ui->ClientCreateButton, &QPushButton::clicked, this, &Dashboard::onAddClickedClient);
	QObject::connect(ui->ClientUpdateButton, &QPushButton::clicked, this, &Dashboard::onUpdateClickedClient);
	QObject::connect(ui->ClientDeleteButton, &QPushButton::clicked, this, &Dashboard::onDeleteClickedClient);

	QObject::connect(ui->ClientCreateCancel, &QPushButton::clicked, this, &Dashboard::onAddCancelClickedClient);
	QObject::connect(ui->ClientUpdateCancel, &QPushButton::clicked, this, &Dashboard::onUpdateCancelClickedClient);
	QObject::connect(ui->ClientDeleteCancel, &QPushButton::clicked, this, &Dashboard::onDeleteCancelClickedClient);
	QObject::connect(ui->QRCodeClientGenerate, &QPushButton::clicked, this, &Dashboard::onQRCodeClickClient);
	QObject::connect(ui->QRCodeClientCancel, &QPushButton::clicked, this, [this]() {ui->QRCodeClientCombo->setCurrentIndex(0);ui->QRCodeClientInput->clear();});

	connect(&MasterClient, &Client::deleteClientRequested, this, &Dashboard::openDeletePage);

    ui->SearchComboClient->addItem("ID", "CLIENT_ID");
    ui->SearchComboClient->addItem("First Name", "FIRST_NAME");
    ui->SearchComboClient->addItem("Last Name", "LAST_NAME");
    ui->SearchComboClient->addItem("Email", "EMAIL");
    ui->SearchComboClient->addItem("Phone Number", "PHONE_NUMBER");
    ui->SearchComboClient->addItem("Address", "ADDRESS");

	fillComboBoxClient();
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

		QMessageBox::critical(this, tr("Error"), tr("Please fill in all fields"), QMessageBox::Ok);
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
			QMessageBox::critical(this, tr("Error"), tr("Please enter a valid 8-digit phone number"), QMessageBox::Ok);
		}
		else if (!validEmail) {
			QMessageBox::critical(this, tr("Error"), tr("Please enter a valid email address"), QMessageBox::Ok);
		}
		else {
			if (MasterClient.CreateClient(ui->ClientCreateEmail->text(),
				ui->ClientCreateFirstName->text(),
				ui->ClientCreateLastName->text(),
				ui->ClientCreatePhoneNumber->text(),
				ui->ClientCreateAddress->text(),
				ui->ClientCreateDob->date())) {

				QString firstName = ui->ClientCreateFirstName->text();
				QString lastName = ui->ClientCreateLastName->text();
				QString phoneNumber = ui->ClientCreatePhoneNumber->text();
				QString address = ui->ClientCreateAddress->text();
				QString dob = ui->ClientCreateDob->date().toString("yyyy-MM-dd");

				QString clientData = "\nEmail: " + email + "\nFirst Name: " + firstName +
					"\nLast Name: " + lastName + "\nPhone Number: " + phoneNumber +
					"\nAddress: " + address + "\nDate of Birth: " + dob;

				sendEmailWithQRCode(email, clientData, firstName, lastName);


                    MasterClient.ReadClient();
                    clearInputFieldsCreateClient();
                    fillComboBoxClient();


				QMessageBox::information(this, tr("Success"), tr("Client created successfully"), QMessageBox::Ok);

			}
			else {
				QMessageBox::critical(this, tr("Error"), tr("Client not created"), QMessageBox::Ok);
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
				fillComboBoxClient();
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
				fillComboBoxClient();
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
		Client MasterClient(ui->tableClient, this);
		MasterClient.toPdf(filePath);
	}
}

void Dashboard::onSearchIdClient() {
    Client MasterClient(ui->tableClient, this);
    QString search = ui->searchBarClient->text();
    QString searchBy = ui->SearchComboClient->currentData().toString();
    MasterClient.searchClientID(search, searchBy);

}

void Dashboard::onStatByAge() {
	Client MasterClient(ui->tableClient, this);
	MasterClient.statsByAge();
}

void Dashboard::onQRCodeClickClient()
{
	Client MasterClient;

	QString querySQL;
	if (ui->QRCodeClientCombo->currentIndex() == 0 && ui->QRCodeClientInput->text().isEmpty()) {
		QMessageBox::critical(this, tr("Error"), tr("Please fill an option"), QMessageBox::Ok);
		return;
	}

	int idCombo = ui->QRCodeClientCombo->currentData().toInt();
	int idInput = ui->QRCodeClientInput->text().toInt();

	if (ui->QRCodeClientCombo->currentIndex() != 0 && ui->QRCodeClientInput->text().isEmpty()) {
		querySQL = "SELECT * FROM CLIENTS WHERE CLIENT_ID=" + QString::number(idCombo);
		ui->QRCodeClientCombo->setCurrentIndex(0);
	}

	if (ui->QRCodeClientCombo->currentIndex() == 0 && !ui->QRCodeClientInput->text().isEmpty()) {
		querySQL = "SELECT * FROM CLIENTS WHERE CLIENT_ID=" + QString::number(idInput);
		ui->QRCodeClientInput->clear();
	}

	if (ui->QRCodeClientCombo->currentIndex() != 0 && !ui->QRCodeClientInput->text().isEmpty()) {
		querySQL = "SELECT * FROM CLIENTS WHERE CLIENT_ID=" + QString::number(idCombo);
		ui->QRCodeClientInput->clear();
		ui->QRCodeClientCombo->setCurrentIndex(0);
	}

	qDebug() << "Query SQL:" << querySQL; // Debug output to check the SQL query

	QSqlQuery query;
	query.prepare(querySQL);
	if (query.exec()) {
		if (query.next()) {
			QString id = query.value(0).toString();
			QString email = query.value(1).toString();
			QString firstName = query.value(2).toString();
			QString lastName = query.value(3).toString();
			QString address = query.value(4).toString();
			QString phoneNumber = query.value(5).toString();
			QString dob = query.value(6).toString();

			QString data = "ID: " + id + "\nEmail: " + email + "\nFirst Name: " + firstName +
				"\nLast Name: " + lastName + "\nPhone Number: " + phoneNumber +
				"\nAddress: " + address + "\nDate of Birth: " + dob;

			qDebug() << "QR Code Data:" << data; // Debug output to check the QR code data

			MasterClient.generateQRCode(data);
		}
		else {
			QMessageBox::critical(this, tr("Error"), tr("Client not found"), QMessageBox::Ok);
		}
	}
	else {
		QMessageBox::critical(this, tr("Error"), tr("Query failed: %1").arg(query.lastError().text()), QMessageBox::Ok);
	}
}

void Dashboard::sendEmailWithQRCode(const QString& recipientEmail, const QString& clientData, const QString& firstName, const QString& lastName)
{
    // Email credentials
    const QString emailRipple = "ripple.insurance123@gmail.com";
    const QString passwordRipple = QProcessEnvironment::systemEnvironment().value("RIPPLE_EMAIL_PASSWORD");

    // Check if the password environment variable is set
    if (passwordRipple.isEmpty()) {
        qWarning() << "Password environment variable (RIPPLE_EMAIL_PASSWORD) is not set.";
        return;
    }

    Client masterClient;

    // Get QR code image data
    QByteArray imageData = masterClient.getQRCodeData(clientData);
    if (imageData.isEmpty()) {
        qWarning() << "Failed to get QR code image data.";
        return;
    }

    QSslSocket socket;
    socket.connectToHostEncrypted("smtp.gmail.com", 465); // Gmail SMTP server and port (SSL)
    if (!socket.waitForConnected()) {
        qWarning() << "Failed to connect to SMTP server";
        return;
    }

    socket.waitForEncrypted(); // Wait for the SSL/TLS handshake to complete
    qDebug() << "Connected to SMTP server.";

    // Send EHLO command to initiate SMTP session
    socket.write("EHLO localhost\r\n");
    socket.waitForBytesWritten();

    // Authenticate with email credentials
    socket.write("AUTH LOGIN\r\n");
    socket.waitForBytesWritten();
    socket.waitForReadyRead();
    socket.write(QByteArray().append(emailRipple.toUtf8()).toBase64() + "\r\n");
    socket.waitForBytesWritten();
    socket.waitForReadyRead();
    socket.write(QByteArray().append(passwordRipple.toUtf8()).toBase64() + "\r\n");
    socket.waitForBytesWritten();
    socket.waitForReadyRead();

    // Send email with attachment
    socket.write("MAIL FROM:<" + emailRipple.toUtf8() + ">\r\n");
    socket.waitForBytesWritten();
    socket.waitForReadyRead();
    socket.write("RCPT TO:<" + recipientEmail.toUtf8() + ">\r\n");
    socket.waitForBytesWritten();
    socket.waitForReadyRead();
    socket.write("DATA\r\n");
    socket.waitForBytesWritten();
    socket.waitForReadyRead();

    // Email headers and body
    socket.write("Subject: Your Ripple Insurance Account Has Been Created\r\n");
    socket.write("From: " + emailRipple.toUtf8() + "\r\n");
    socket.write("To: " + recipientEmail.toUtf8() + "\r\n");
    socket.write("Content-Type: multipart/mixed; boundary=boundary1\r\n");
    socket.write("\r\n");
    socket.write("--boundary1\r\n");
    socket.write("Content-Type: text/html\r\n\r\n");
    socket.write("<p style=\"font-family: Arial, sans-serif; font-size: 14px; color: #333333;\">Hello " + firstName.toHtmlEscaped().toUtf8() + " " + lastName.toHtmlEscaped().toUtf8() + "</p>");
    socket.write("Please find your QR code with your Information attached to this Email.\r\n");
    socket.write("\r\n");

    // Attach QR code image data
    socket.write("--boundary1\r\n");
    socket.write("Content-Type: image/png\r\n");
    socket.write("Content-Disposition: attachment; filename=qr_code.png\r\n");
    socket.write("Content-Transfer-Encoding: base64\r\n\r\n");
    socket.write(imageData.toBase64());
    socket.write("\r\n");

    // End email data
    socket.write("--boundary1--\r\n");
    socket.write(".\r\n");
    socket.waitForBytesWritten();
    socket.waitForReadyRead();

    // Quit SMTP session
    socket.write("QUIT\r\n");
    socket.waitForBytesWritten();
    socket.waitForReadyRead();

    socket.close();
    qDebug() << "Email with attachment sent successfully!";
}






void Dashboard::fillComboBoxClient()
{
	QSqlQuery query;


	if (!query.exec("SELECT * FROM CLIENTS")) {
		qDebug() << "Error executing query:" << query.lastError().text();
		return;
	}
	else {

		ui->QRCodeClientCombo->clear();
		ui->QRCodeClientCombo->addItem("Select Client", 0);
		while (query.next()) {
			QString clientName = query.value(2).toString();
			QVariant clientId = query.value(0).toInt();
			ui->QRCodeClientCombo->addItem(clientName, clientId);
		}
	}
}



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
	QObject::connect(ui->chatEmployee, &QPushButton::clicked, this, &Dashboard::openChatBox);

	Employee employee;

	QStringList employeeNames = employee.getEmployeeNames();
	ui->EmployeeSelectStats->addItems(employeeNames);

	QObject::connect(ui->EmployeeSelectStats, QOverload<int>::of(&QComboBox::currentIndexChanged),
		[=](int index) { this->onEmployeeSelectStatsChanged(ui->EmployeeSelectStats->currentText()); });


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

void Dashboard::displayEmployeeStats(int employeeID) {
	QChartView* employeeStatsView = findChild<QChartView*>("EmployeeStats");
	QLabel* employeeStatsLabel = findChild<QLabel*>("EmployeeStatsLabel");

	if (ui->EmployeeSelectStats->currentIndex() == 1) {
		qDebug() << "Displaying general statistics.";
		displayGeneralStats();
		return;
	}

	if (employeeID <= 0) {
		clearEmployeeStats();
		if (employeeStatsLabel) {
			employeeStatsLabel->setText("");
		}
		return;
	}

	Employee employee;

	QMap<QString, qreal> stats = employee.calculateEmployeeStats(employeeID);

	if (employeeStatsView) {
		employeeStatsView->setBackgroundBrush(QBrush(Qt::transparent));

		if (stats.isEmpty()) {
			qDebug() << "No statistics found for employee with ID:" << employeeID;

			clearEmployeeStats();

			if (employeeStatsLabel) {
				QString message = "This employee is probably new or hasn't recorded any statistics.\n"
					"Please work some hours and come back later.";
				employeeStatsLabel->setText(message);
			}
		}
		else {
			if (employeeStatsLabel) {
				employeeStatsLabel->setText("");
			}

			QString employeeName;
			QSqlQuery query;
			query.prepare("SELECT FIRST_NAME || ' ' || LAST_NAME AS full_name FROM employees WHERE USER_ID = ?");
			query.addBindValue(employeeID);

			if (!query.exec()) {
				qDebug() << "Error executing query:" << query.lastError().text();
			}
			else {
				if (query.next()) {
					employeeName = query.value("full_name").toString();
				}
			}
			QChart* chart = new QChart();
			chart->setBackgroundBrush(QBrush(Qt::transparent));
			QBarSeries* series = new QBarSeries();
			QBarSet* set = new QBarSet("Statistics");
			*set << stats.value("Total Days Worked")
				<< stats.value("Late Arrivals")
				<< stats.value("Early Departures")
				<< stats.value("Absenteeism Rate");
			series->append(set);
			chart->addSeries(series);
			chart->setTitle("Statistics for " + employeeName);
			chart->setAnimationOptions(QChart::AllAnimations);
			QBarCategoryAxis* xAxis = new QBarCategoryAxis();
			xAxis->append("Total Days Worked");
			xAxis->append("Late Arrivals");
			xAxis->append("Early Departures");
			xAxis->append("Absenteeism Rate");
			xAxis->setLabelsFont(QFont("Arial", 8));
			QValueAxis* yAxis = new QValueAxis();
			yAxis->setTitleText("Values");
			yAxis->setLabelsFont(QFont("Arial", 10));
			chart->addAxis(xAxis, Qt::AlignBottom);
			chart->addAxis(yAxis, Qt::AlignLeft);
			series->attachAxis(xAxis);
			series->attachAxis(yAxis);
			chart->legend()->setVisible(false);
			QChartView* chartView = new QChartView(chart);
			chartView->setRenderHint(QPainter::Antialiasing);
			chartView->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
			chartView->setMinimumSize(400, 200);
			chartView->setRubberBand(QChartView::RectangleRubberBand);
			chartView->setInteractive(true);
			employeeStatsView->setChart(chart);
		}
	}
}

void Dashboard::displayGeneralStats() {
	Employee employee;
	QMap<QString, qreal> generalStats = employee.calculateGeneralStats();

	QChartView* employeeStatsView = findChild<QChartView*>("EmployeeStats");
	QLabel* employeeStatsLabel = findChild<QLabel*>("EmployeeStatsLabel");

	clearEmployeeStats();

	if (employeeStatsView) {
		if (generalStats.isEmpty()) {
			qDebug() << "No general statistics found.";
			if (employeeStatsLabel) {
				QString message = "No general statistics available.";
				employeeStatsLabel->setText(message);
			}
		}
		else {
			if (employeeStatsLabel) {
				employeeStatsLabel->clear();
				QString totalEmployeesText = "Total Employees: " + QString::number(generalStats["Total Employees"]);
				employeeStatsLabel->setText(totalEmployeesText);
			}
			QChart* chart = new QChart();
			chart->setBackgroundBrush(QBrush(Qt::transparent));
			QPieSeries* series = new QPieSeries();
			for (auto it = generalStats.begin(); it != generalStats.end(); ++it) {
				QPieSlice* slice = series->append(it.key(), it.value());
				slice->setLabel(QString("%1: %2").arg(it.key()).arg(it.value()));
			}
			chart->addSeries(series);
			chart->setTitle("General Statistics");

			chart->setAnimationOptions(QChart::AllAnimations);
			connect(series, &QPieSeries::hovered, this, [=](QPieSlice* slice, bool state) {
				if (state) {
					slice->setExploded(true);
					slice->setLabelVisible(true);
				}
				else {
					slice->setExploded(false);
					slice->setLabelVisible(false);
				}
				});
			QChartView* chartView = new QChartView(chart);
			chartView->setRenderHint(QPainter::Antialiasing);
			chartView->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
			chartView->setMinimumSize(400, 200);
			employeeStatsView->setChart(chart);
		}
	}
}

void Dashboard::onEmployeeSelectStatsChanged(const QString& employeeName) {

	if (ui->EmployeeSelectStats->currentIndex() == 1) {
		qDebug() << "Displaying general statistics.";
		displayGeneralStats();
		return;
	}
	if (ui->EmployeeSelectStats->currentIndex() <= 0) {
		clearEmployeeStats();
		return;
	}
	Employee employee;

	int employeeId = employee.getEmployeeIdByName(employeeName);
	if (employeeId != -1) {

		displayEmployeeStats(employeeId);
	}
	else {
		qDebug() << "Error: Unable to retrieve employee ID for selected name.";
	}

}

void Dashboard::clearEmployeeStats()
{

	QChartView* employeeStatsView = findChild<QChartView*>("EmployeeStats");
	QLabel* employeeStatsLabel = findChild<QLabel*>("EmployeeStatsLabel");

	if (employeeStatsLabel) {
		employeeStatsLabel->clear();
	}
	if (employeeStatsView) {
		QChart* chart = employeeStatsView->chart();

		if (chart) {
			QList<QAbstractSeries*> seriesList = chart->series();
			for (QAbstractSeries* series : seriesList) {
				chart->removeSeries(series);
				delete series;
			}

			QList<QAbstractAxis*> axisList = chart->axes();
			for (QAbstractAxis* axis : axisList) {
				chart->removeAxis(axis);
				delete axis;
			}

			chart->setTitle("");
		}
	}
}

void Dashboard::openChatBox() {
    chatbot* chat = new chatbot(this);
    chat->show();
}


//********************************************************************************************************************
// Contract
void Dashboard::ContractDashboardConnectUi() {
	contract MasterContract(ui->tableContract, ui->StackContract, this);


	QObject::connect(ui->sortContract, &QPushButton::clicked, this, &Dashboard::onSortClickedContract);
	QObject::connect(ui->pdfContract, &QPushButton::clicked, this, &Dashboard::onPdfClickedContract);
	QObject::connect(ui->searchBarContract, &QLineEdit::textChanged, this, &Dashboard::onSearchIdContract);
	QObject::connect(ui->statsContract, &QPushButton::clicked, this, &Dashboard::onStatByPremiumAmount);
    //QObject::connect(ui->excelContract, &QPushButton::clicked, this, &Dashboard::onExcelClickedContract);


	QObject::connect(ui->addContract, &QPushButton::clicked, this, [this]() {ui->StackContract->setCurrentIndex(0); });
	QObject::connect(ui->updateContract, &QPushButton::clicked, this, [this]() {ui->StackContract->setCurrentIndex(2); });
	QObject::connect(ui->deleteContract, &QPushButton::clicked, this, [this]() {ui->StackContract->setCurrentIndex(1); });


	QObject::connect(ui->CreateContractButton, &QPushButton::clicked, this, &Dashboard::onAddClickedContract);
	QObject::connect(ui->UpdateContractButton, &QPushButton::clicked, this, &Dashboard::onUpdateClickedContract);
	QObject::connect(ui->DeleteContractButton, &QPushButton::clicked, this, &Dashboard::onDeleteClickedContract);

	QSqlQuery query;

	if (!query.exec("SELECT * FROM CLIENTS")) {
		qDebug() << "Error executing query:" << query.lastError().text();
		return;
	}
	// Counter to track the number of rows fetched
	while (query.next()) {
		QString clientName = query.value(2).toString();
		QVariant clientId = query.value(0).toInt();


		ui->comboBoxClientIDCreateContract->addItem(clientName, clientId);
		ui->comboBoxClientIDUpdateContract->addItem(clientName, clientId);

	}


	if (!query.exec("SELECT * FROM EMPLOYEES")) {
		qDebug() << "Error executing query:" << query.lastError().text();
		return;
	}
	// Counter to track the number of rows fetched
	while (query.next()) {
		QString UserName = query.value(2).toString(); // Supposons que le nom de l'employ� est � l'index 2
		QVariant UserId = query.value(0);

		ui->comboBoxUserIDCreateContract->addItem(UserName, UserId);
		ui->comboBoxUserIDUpdateContract->addItem(UserName, UserId);
	}





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

	QString premiumAmountStr = ui->LineEditPremiumAmountContract->text();
	QDate effectiveDate = ui->dateEditEffectiveDateContract->date();
	QDate expirationDate = ui->dateEditExpirationDateContract->date();
	QString paymentStatusStr = ui->LineEditPaymentstatusContract->text();
	QString type = ui->lineEditTypeContract->text().toLower();

	// R�cup�rer les valeurs s�lectionn�es dans les combobox pour le client ID et le user ID
	QVariant clientIdVar = ui->comboBoxClientIDCreateContract->currentData();
	QVariant userIdVar = ui->comboBoxUserIDCreateContract->currentData();

	// V�rifier si les champs obligatoires ne sont pas vides
	if (clientIdVar.isNull() || userIdVar.isNull() ||
		premiumAmountStr.isEmpty() || paymentStatusStr.isEmpty() ||
		effectiveDate.isNull() || expirationDate.isNull()) {

		QMessageBox::critical(this, tr("Error"), tr("Please fill in all fields"), QMessageBox::Ok);
		clearInputFieldsCreateContract();
		return;
	}

	// Convertir les valeurs saisies en types appropri�s
	int clientId = clientIdVar.toInt();
	int userId = userIdVar.toInt();
	int premiumAmount = premiumAmountStr.toInt();
	int paymentStatus = paymentStatusStr.toInt();

	// V�rifier si les champs num�riques sont valides
	if (clientId <= 0 || userId <= 0 || premiumAmount <= 0 || (paymentStatus != 0 && paymentStatus != 1)) {
		QMessageBox::critical(this, tr("Error"), tr("Invalid input for numeric fields or payment status"), QMessageBox::Ok);
		clearInputFieldsCreateContract();
		return;
	}

	// V�rifier si le type est parmi les valeurs autoris�es
	if (type != "house" && type != "car" && type != "life" && type != "all risk") {
		QMessageBox::critical(this, tr("Error"), tr("Invalid input for type. Please enter 'maison', 'voiture', 'vie', or 'tous risque'"), QMessageBox::Ok);
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
	ui->LineEditPremiumAmountContract->clear();
	ui->dateEditEffectiveDateContract->setDate(QDate());
	ui->dateEditExpirationDateContract->setDate(QDate());
	ui->LineEditPaymentstatusContract->clear();
	ui->lineEditTypeContract->clear();
}

void Dashboard::onUpdateClickedContract() {
	contract MasterContract(ui->tableContract, ui->StackContract, this);

	int contractId = ui->lineEditContractIDUpdate->text().toInt();
	QString premiumAmountStr = ui->LineEditPremiumAmountContractUpdate->text().trimmed();
	QDate effectiveDate = ui->dateEditEffectiveDateContractUpdate->date();
	QDate expirationDate = ui->dateEditExpirationDateContractUpdate->date();
	QString paymentStatusStr = ui->LineEditPaymentstatusContractUpdate->text().trimmed();
	QString type = ui->lineEditTypeContractUpdate->text().trimmed().toLower(); // Convertir en minuscules pour �tre insensible � la casse

	// Assurez-vous de r�cup�rer les valeurs s�lectionn�es dans les combobox pour le client ID et le user ID
	QVariant clientId = ui->comboBoxClientIDUpdateContract->currentData();
	QVariant userId = ui->comboBoxUserIDUpdateContract->currentData();

	// V�rifier si les champs obligatoires ne sont pas vides
	if (premiumAmountStr.isEmpty() || paymentStatusStr.isEmpty() || type.isEmpty()) {
		QMessageBox::critical(this, tr("Error"), tr("Please fill in all fields"), QMessageBox::Ok);
		clearInputFieldsUpdateContract();
		return;
	}

	bool conversionOk;
	int premiumAmount = premiumAmountStr.toInt(&conversionOk);
	int paymentStatus = paymentStatusStr.toInt(&conversionOk);

	if (!conversionOk || contractId <= 0 || premiumAmount <= 0 || (paymentStatus != 0 && paymentStatus != 1)) {
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

	// V�rifier si le type est parmi les valeurs autoris�es
	if (type != "house" && type != "car" && type != "life" && type != "all risk") {
		QMessageBox::critical(this, tr("Error"), tr("Invalid input for type. Please enter 'maison', 'voiture', 'vie', or 'tous risque'"), QMessageBox::Ok);
		clearInputFieldsUpdateContract();
		return;
	}

	if (MasterContract.UpdateContract(contractId, userId.toInt(), clientId.toInt(), premiumAmount, effectiveDate, expirationDate, paymentStatus, type)) {
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
	ui->LineEditPremiumAmountContract->clear();
	ui->dateEditEffectiveDateContract->setDate(QDate());
	ui->dateEditExpirationDateContract->setDate(QDate());
	ui->LineEditPaymentstatusContract->clear();
	ui->lineEditTypeContract->clear();
}

void Dashboard::clearInputFieldsUpdateContract() {
	ui->LineEditPremiumAmountContractUpdate->clear();
	ui->dateEditEffectiveDateContractUpdate->setDate(QDate());
	ui->dateEditExpirationDateContractUpdate->setDate(QDate());
	ui->LineEditPaymentstatusContractUpdate->clear();
	ui->lineEditTypeContractUpdate->clear();

}
void Dashboard::onSortClickedContract() {
	static bool isSorted = false;

	contract MasterContract(ui->tableContract, ui->StackContract, this);
	MasterContract.sortContractsByPremium(isSorted);

	isSorted = !isSorted;
}

void Dashboard::onSearchIdContract(QString searched) {
    contract MasterContract(ui->tableContract, ui->StackContract, this);
	QString id = ui->searchBarContract->text();
	MasterContract.searchContract(id); // Appel de la fonction searchContractID pour rechercher les contrats
}

void Dashboard::onStatByPremiumAmount() {
	contract MasterContract(ui->tableContract, ui->StackContract, this);
	MasterContract.statsByPremiumAmount(); // Appelle statsByPremiumAmount de la classe Contract
}

void Dashboard::onPdfClickedContract() {
	QString filePath = QFileDialog::getSaveFileName(this, tr("Save PDF"), "", "PDF Files (*.pdf)");
	if (!filePath.isEmpty()) {
        contract MasterContract(ui->tableContract, ui->StackContract, this);
		MasterContract.toPdf(filePath); // Appel de la fonction toPdf() de l'objet contract
	}
}

/*
void Dashboard::onExcelClickedContract() {
    // Demander à l'utilisateur de sélectionner un fichier pour enregistrer le fichier Excel
    QString filePath = QFileDialog::getSaveFileName(this, tr("Enregistrer en Excel"), "", "Fichiers Excel (*.xlsx)");
    if (!filePath.isEmpty()) {
        contract MasterContract(ui->tableContract, ui->StackContract, this);
        MasterContract.exportToExcel(filePath);
    }


}
*/

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
    QObject::connect(ui->searchAccident, &QLineEdit::textChanged, this, &Dashboard::onAccidentSearchTextChanged);
    QObject::connect(ui->statsAccident, &QPushButton::clicked, this, &Dashboard::onstatsClickedAccident);


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
 // Counter to track the number of rows fetched
	while (query.next()) {
		QString clientName = query.value(2).toString();
		QVariant clientId = query.value(0).toInt();
		ui->AccidentCreateClientID->addItem(clientName, clientId);
		ui->AccidentUpdateClientID->addItem(clientName, clientId);
	}

    ui->StackedAccident->setCurrentIndex(0);
}

void Dashboard::onAddCancelClickedAccident() {
	clearInputFieldsAccidentCreate();
}


void Dashboard::onPdfClickedAccient() {

	QString filePath = QFileDialog::getSaveFileName(this, tr("Save PDF"), "", "PDF Files (*.pdf)");
	if (!filePath.isEmpty()) {
		accident MasterAccident(ui->tableAccident, this); // Utilisation de 'accident' au lieu de 'Client'
		MasterAccident.AccidenttoPdf(filePath); // Appel de la fonction toPdf() de l'objet accident
	}
}


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
void Dashboard::onSortClickedAccident() {
	static bool isSorted = false;

	accident MasterAccident(ui->tableAccident, this);
	MasterAccident.sortAccidentByDamage(isSorted);

	isSorted = !isSorted;
}
void Dashboard::onAccidentSearchTextChanged(const QString& searchText) {
	accident MasterAccident(ui->tableAccident);
	MasterAccident.searchAccident(searchText);
}
void Dashboard::onstatsClickedAccident() {
    accident MasterAccident(ui->tableAccident,this);
    MasterAccident.accidentstatsByDamage();

}

/*void Dashboard::onHistoriqueAccidentclicked()

{

    QSqlQuery query = accident.rechercherall();

    if (query.exec())
    {

        QFile file("resultats.txt");
        if (file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append))
        {

            QTextStream out(&file);


            while (query.next())
            {
                out << "acc_id: " << query.value("acc_id").toInt() << "\n";
                out << "type " << query.value("type").toString() << "\n";
                out << "damage: " << query.value("damage").toString() << "\n";
                out << "date: " << query.value("date").toString() << "\n\n";
                out << "location: " << query.value("location").toString() << "\n\n";
                out << "client_id: " << query.value("client_id").toString() << "\n\n";


            }
            file.close();
        }
        else
        {
            qDebug() << "Erreur d'ouverture du fichier";
        }
    }
    else
    {
        qDebug() << "Erreur d'exécution de la requête : " << query.lastError().text();
    }
}
*/


//--------------------------------------------------------------------------------------------------------------------------------
Dashboard::~Dashboard() {
	delete ui;
}
