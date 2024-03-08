#include "dashboard.h"
#include "ui_dashboard.h"

#include <QApplication>
#include <QtWidgets>
#include <QUiLoader>
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
<<<<<<< Updated upstream
    ui->setupUi(this);
    Client MasterClient(ui->tableClient, ui->StackedClient, this);

    Connection con;
    if(!con.createconnect()) {
        qDebug() << "Not Connected";
    } else {
        MasterClient.ReadClient();
        update();
    }
=======
	ui->setupUi(this);
	Client MasterClient(ui->tableClient, this);
	Employee Emp(ui->tableEmployee, this);
	Connection con;
	if (!con.createconnect()) {
		qDebug() << "Not Connected";
	}
	else {
		MasterClient.ReadClient();
		Emp.readEmployee();
		openUpdateForm();
		update();
	}
>>>>>>> Stashed changes
}

void Dashboard::update() {

	//Dashboard Nav Buttons
	QObject::connect(ui->employees, &QPushButton::clicked, this, [this]() { ui->stackedWidget->setCurrentIndex(0); });
	QObject::connect(ui->clients, &QPushButton::clicked, this, [this]() { ui->stackedWidget->setCurrentIndex(1); });
	QObject::connect(ui->contracts, &QPushButton::clicked, this, [this]() { ui->stackedWidget->setCurrentIndex(2); });
	QObject::connect(ui->accidents, &QPushButton::clicked, this, [this]() { ui->stackedWidget->setCurrentIndex(3); });
	QObject::connect(ui->logoutButton, &QPushButton::clicked, this, &Dashboard::onLogoutButtonClicked);

	//Client
	ClientDashboardConnectUi();
	//Employee
	EmployeeDashboardConnectUi();


}


void Dashboard::onLogoutButtonClicked() {
	close();
	mainWindowRef.show();
}



//Client

void Dashboard::ClientDashboardConnectUi()
{
<<<<<<< Updated upstream
    Client MasterClient(ui->tableClient, ui->StackedClient, this);

    

    QObject::connect(ui->sortClient, &QPushButton::clicked, this, &Dashboard::onSortClickedClient);
    QObject::connect(ui->pdfClient, &QPushButton::clicked, this, &Dashboard::onPdfClickedClient);


    QObject::connect(ui->addClient, &QPushButton::clicked, this, [this]() { ui->StackedClient->setCurrentIndex(0); });
    QObject::connect(ui->updateClient, &QPushButton::clicked, this, [this]() { ui->StackedClient->setCurrentIndex(1); });
    QObject::connect(ui->deleteClient, &QPushButton::clicked, this, [this]() { ui->StackedClient->setCurrentIndex(2); });
=======
	QObject::connect(ui->addClient, &QPushButton::clicked, this, [this]() { ui->StackedClient->setCurrentIndex(0); });
	QObject::connect(ui->updateClient, &QPushButton::clicked, this, [this]() { ui->StackedClient->setCurrentIndex(1); });
	QObject::connect(ui->deleteClient, &QPushButton::clicked, this, [this]() { ui->StackedClient->setCurrentIndex(2); });
>>>>>>> Stashed changes

	QObject::connect(ui->ClientCreateButton, &QPushButton::clicked, this, &Dashboard::onAddClickedClient);
	QObject::connect(ui->ClientUpdateButton, &QPushButton::clicked, this, &Dashboard::onUpdateClickedClient);
	QObject::connect(ui->ClientDeleteButton, &QPushButton::clicked, this, &Dashboard::onDeleteClickedClient);

	QObject::connect(ui->ClientCreateCancel, &QPushButton::clicked, this, &Dashboard::onAddCancelClickedClient);
	QObject::connect(ui->ClientUpdateCancel, &QPushButton::clicked, this, &Dashboard::onUpdateCancelClickedClient);
	QObject::connect(ui->ClientDeleteCancel, &QPushButton::clicked, this, &Dashboard::onDeleteCancelClickedClient);

<<<<<<< Updated upstream
    connect(&MasterClient, &Client::deleteClientRequested, this, &Dashboard::openDeletePage);

    ui->StackedClient->setCurrentIndex(0);
=======
	ui->StackedClient->setCurrentIndex(0);
>>>>>>> Stashed changes

	// Client stacked widget button background color change according to current index
	//QObject::connect(ui->StackedClient, &QStackedWidget::currentChanged, this, &Dashboard::onStackedClientIndexChanged);


}

void Dashboard::openDeletePage(int clientId) {
    // Open the delete page in the stacked client widget
    ui->StackedClient->setCurrentIndex(2); // Assuming the index of the delete page is 2

    // Fill the input field with the client ID
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
<<<<<<< Updated upstream
    Client MasterClient(ui->tableClient,ui->StackedClient, this);
=======
	Client MasterClient(ui->tableClient, this);
>>>>>>> Stashed changes


	if (ui->ClientCreateEmail->text().isEmpty() ||
		ui->ClientCreateFirstName->text().isEmpty() ||
		ui->ClientCreateLastName->text().isEmpty() ||
		ui->ClientCreatePhoneNumber->text().isEmpty() ||
		ui->ClientCreateAddress->text().isEmpty() ||
		ui->ClientCreateDob->date().isNull()) {

		QMessageBox::critical(this, tr("Error"), tr("Please fill in all fields"), QMessageBox::Ok, QMessageBox::Ok);

<<<<<<< Updated upstream
        clearInputFieldsCreateClient();
    } else {
        // Validate phone number
        QString phoneNumber = ui->ClientCreatePhoneNumber->text();
        bool validPhoneNumber = phoneNumber.length() == 8 && phoneNumber.toInt(&validPhoneNumber) && validPhoneNumber;
=======
		clearInputFields();
	}
	else {
		// Validate phone number
		QString phoneNumber = ui->ClientCreatePhoneNumber->text();
		bool validPhoneNumber = phoneNumber.length() == 8 && phoneNumber.toInt(&validPhoneNumber) && validPhoneNumber;
>>>>>>> Stashed changes

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

<<<<<<< Updated upstream
            if(MasterClient.CreateClient(ui->ClientCreateEmail->text(),
                                ui->ClientCreateFirstName->text(),
                                ui->ClientCreateLastName->text(),
                                ui->ClientCreatePhoneNumber->text(),
                                ui->ClientCreateAddress->text(),
                                ui->ClientCreateDob->date()))
            {            MasterClient.ReadClient();

            clearInputFieldsCreateClient();

            QMessageBox::information(this, tr("Success"), tr("Client created successfully"),QMessageBox::Ok, QMessageBox::Ok);
            }
            else
            {
				QMessageBox::critical(this, tr("Error"), tr("Client not created"),QMessageBox::Ok, QMessageBox::Ok);
			}
        }
    }
}


void Dashboard::onUpdateClickedClient() {
    Client MasterClient(ui->tableClient, ui->StackedClient ,this);
=======
			MasterClient.CreateClient(ui->ClientCreateEmail->text(),
				ui->ClientCreateFirstName->text(),
				ui->ClientCreateLastName->text(),
				ui->ClientCreatePhoneNumber->text(),
				ui->ClientCreateAddress->text(),
				ui->ClientCreateDob->date());
			MasterClient.ReadClient();

			clearInputFields();

			QMessageBox::information(this, tr("Success"), tr("Client created successfully"), QMessageBox::Ok, QMessageBox::Ok);
		}
	}
}

void Dashboard::clearInputFields() {
	ui->ClientCreateEmail->clear();
	ui->ClientCreateFirstName->clear();
	ui->ClientCreateLastName->clear();
	ui->ClientCreatePhoneNumber->clear();
	ui->ClientCreateAddress->clear();
	ui->ClientCreateDob->setDate(QDate());
}

void Dashboard::onUpdateClickedClient() {
	Client MasterClient(ui->tableClient, this);
>>>>>>> Stashed changes


	if (ui->ClientUpdateEmail->text().isEmpty() ||
		ui->ClientUpdateFirstName->text().isEmpty() ||
		ui->ClientUpdateLastName->text().isEmpty() ||
		ui->ClientUpdatePhoneNumber->text().isEmpty() ||
		ui->ClientUpdateAddress->text().isEmpty() ||
		ui->ClientUpdateDob->date().isNull()) {

		QMessageBox::critical(this, tr("Error"), tr("Please fill in all fields"), QMessageBox::Ok, QMessageBox::Ok);

<<<<<<< Updated upstream
            clearInputFieldsUpdateClient();
        } else {
            // Validate ID
            QString id = ui->ClientUpdateID->text();
            bool validId = id.toInt(&validId) && validId;
=======
		clearInputFields();
	}
	else {
		// Validate ID
		QString id = ui->ClientUpdateID->text();
		bool validId = id.toInt(&validId) && validId;
>>>>>>> Stashed changes

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

<<<<<<< Updated upstream
                if (MasterClient.UpdateClient(id.toInt(), ui->ClientUpdateEmail->text(),
                    ui->ClientUpdateFirstName->text(),
                    ui->ClientUpdateLastName->text(),
                    ui->ClientUpdatePhoneNumber->text(),
                    ui->ClientUpdateAddress->text(),
                    ui->ClientUpdateDob->date()))
                {
                    MasterClient.ReadClient();

                    clearInputFieldsUpdateClient();

                    QMessageBox::information(this, tr("Success"), tr("Client Updated successfully"), QMessageBox::Ok, QMessageBox::Ok);
                }
                else
                {
					QMessageBox::critical(this, tr("Error"), tr("Client not found"), QMessageBox::Ok, QMessageBox::Ok);
				}
            }
        }
    }


void Dashboard::onDeleteClickedClient() {
    Client MasterClient(ui->tableClient,ui->StackedClient, this);
=======
			MasterClient.UpdateClient(id.toInt(), ui->ClientUpdateEmail->text(),
				ui->ClientUpdateFirstName->text(),
				ui->ClientUpdateLastName->text(),
				ui->ClientUpdatePhoneNumber->text(),
				ui->ClientUpdateAddress->text(),
				ui->ClientUpdateDob->date());
			MasterClient.ReadClient();

			clearInputFields();

			QMessageBox::information(this, tr("Success"), tr("Client Updated successfully"), QMessageBox::Ok, QMessageBox::Ok);
		}
	}
}


void Dashboard::onDeleteClickedClient() {
	Client MasterClient(ui->tableClient, this);
>>>>>>> Stashed changes

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

<<<<<<< Updated upstream
            if (MasterClient.DeleteClient(id.toInt()))

            {
                MasterClient.ReadClient();
                clearInputFieldsDeleteClient();
                QMessageBox::information(this, tr("Success"), tr("Client Deleted successfully"), QMessageBox::Ok, QMessageBox::Ok);
            }
            else
            {
				QMessageBox::critical(this, tr("Error"), tr("Client not found"), QMessageBox::Ok, QMessageBox::Ok);
			}

        }
    }
=======
			MasterClient.DeleteClient(id.toInt());
			MasterClient.ReadClient();

			clearInputFields();

			QMessageBox::information(this, tr("Success"), tr("Client Deleted successfully"), QMessageBox::Ok, QMessageBox::Ok);
		}
	}
>>>>>>> Stashed changes
}

void Dashboard::onAddCancelClickedClient()
{
<<<<<<< Updated upstream
    clearInputFieldsCreate();
=======
	clearInputFields();
>>>>>>> Stashed changes
}

void Dashboard::onUpdateCancelClickedClient()
{
<<<<<<< Updated upstream
    	clearInputFieldsUpdate();
    
}

void Dashboard::onDeleteCancelClickedClient()
{
    clearInputFieldsDelete();
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

=======
	ui->ClientUpdateID->clear();
	ui->ClientUpdateEmail->clear();
	ui->ClientUpdateFirstName->clear();
	ui->ClientUpdateLastName->clear();
	ui->ClientUpdatePhoneNumber->clear();
	ui->ClientUpdateAddress->clear();
	ui->ClientUpdateDob->setDate(QDate());
}

void Dashboard::onDeleteCancelClickedClient()
{
	ui->ClientDeleteID->clear();
}
>>>>>>> Stashed changes


void Dashboard::onSortClickedClient() {

}

void Dashboard::onPdfClickedClient() {
}

//----------------------------------------------------------------
//Employee
void Dashboard::EmployeeDashboardConnectUi()
{
	QObject::connect(ui->addEmployee, &QPushButton::clicked, this, [this]() {ui->CrudEmployee->setCurrentIndex(0); });
	QObject::connect(ui->updateEmployee, &QPushButton::clicked, this, [this]() { ui->CrudEmployee->setCurrentIndex(1); });
	QObject::connect(ui->deleteEmployee, &QPushButton::clicked, this, [this]() {ui->CrudEmployee->setCurrentIndex(2); });

	QObject::connect(ui->EmployeeCreateBtn, &QPushButton::clicked, this, &Dashboard::onAddEmployeeClicked);
	QObject::connect(ui->EmployeeUpdateBtn, &QPushButton::clicked, this, &Dashboard::onUpdateEmployeeClicked);
	QObject::connect(ui->EmployeeDeleteBtn, &QPushButton::clicked, this, &Dashboard::onDeleteEmployeeClicked);


	QObject::connect(ui->EmployeeCancelBtn_C, &QPushButton::clicked, this, &Dashboard::onAddCancelClickedClient);


	ui->CrudEmployee->setCurrentIndex(0);

}

int mapRoleToNumber(const QString& roleText)
{
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

	ui->tableEmployee->setStyleSheet("QTableWidget { color: white; font-family: \"Helvetica\"; }"
		"QTableWidget QTableWidget::item { min-height: 100px; }");

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
		clearInputFields();
	}
	else if (!email.contains('@') || !email.contains('.')) {
		QMessageBox::critical(this, tr("Error"), tr("Please enter a valid email address"), QMessageBox::Ok, QMessageBox::Ok);
	}
	else if (password.length() < 8) {
		QMessageBox::critical(this, tr("Error"), tr("Password must be at least 8 characters long"), QMessageBox::Ok, QMessageBox::Ok);
	}
	else if (phoneNumber.length() != 8 || !phoneNumber.toInt()) {
		QMessageBox::critical(this, tr("Error"), tr("Please enter a valid 8-digit phone number"), QMessageBox::Ok, QMessageBox::Ok);
	}
	else if (!firstName.contains(QRegularExpression("^[a-zA-Z]+$")) || !lastName.contains(QRegularExpression("^[a-zA-Z]+$"))) {
		QMessageBox::critical(this, tr("Error"), tr("Please enter valid first and last names"), QMessageBox::Ok, QMessageBox::Ok);
	}
	else {
		emp.createEmployee(email, password, role, firstName, lastName, phoneNumber, address, dob);
		emp.readEmployee();

		clearInputFields();

		QMessageBox::information(this, tr("Success"), tr("Employee created successfully"), QMessageBox::Ok, QMessageBox::Ok);
	}
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
		emp.readEmployee();
		QMessageBox::information(this, "Success", "Employee  updated successfully.");
	}
	else {
		QMessageBox::critical(this, "Error", "Failed to update employee .");
	}
}



void Dashboard::onDeleteEmployeeClicked() {

	QString selectedId = ui->EmployeeSelectID_D->currentText();

	if (!selectedId.isEmpty()) {

		int idToDelete = selectedId.toInt();

		
		Employee e(ui->tableEmployee);
		if (e.deleteEmployee(idToDelete)) {
		
			openUpdateForm();
			
			QMessageBox::information(this, "Success", "Employee  deleted successfully.");
		}
		else {
			
			QMessageBox::critical(this, "Error", "Failed to delete employee .");
		}
	}
}


void Dashboard::onSortEmployeeClicked() {

}

void Dashboard::onPdfEmployeeClicked() {

}
void Dashboard::onCancelClickedEmp_C()
{
	clearInputFields();
}
void Dashboard::openUpdateForm() {
	if (ui->EmployeeSelectID_U) {
		Employee e(ui->tableEmployee);
		QStringList ids = e.getAllEmployeeIDs();
		ui->EmployeeSelectID_U->clear();
		ui->EmployeeSelectID_U->addItems(ids);
		
		QObject::connect(ui->EmployeeSelectID_U, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &Dashboard::onComboboxIndexChanged);

	}
	else {
		qDebug() << "Error choosing update.";
	}

	if (ui->EmployeeSelectID_D) {
		Employee e(ui->tableEmployee);
		QStringList ids = e.getAllEmployeeIDs();
		ui->EmployeeSelectID_D->clear();
		ui->EmployeeSelectID_D->addItems(ids);
	}
	else {
		qDebug() << "Error choosing delete.";
	}
}






void Dashboard::onComboboxIndexChanged(int index) {
	if (index >= 0) {
		QString selectedId = ui->EmployeeSelectID_U->itemText(index);
		Employee* employeeData = getEmployeeDataById(selectedId.toInt());
		if (employeeData) {

			ui->EmployeeEmail_U->setText(employeeData->getEmail());
			ui->EmployeePassword_U->setText(employeeData->getPassword());
			ui->EmployeeRole_U->setCurrentIndex(employeeData->getRole());
			ui->EmployeeFirstName_U->setText(employeeData->getFirstName());
			ui->EmployeeLastName_U->setText(employeeData->getLastName());
			ui->EmployeePhoneNumber_U->setText(employeeData->getPhoneNumber());
			ui->EmployeeAddress_U->setText(employeeData->getAddress());
			ui->EmployeeDob_U->setDate(employeeData->getDOB());

			delete employeeData;
		}
		else {
			qDebug() << "Error: Unable to retrieve employee data.";
		}
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

//------------------------
Dashboard::~Dashboard() {
	delete ui;
}


