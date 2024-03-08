#include "dashboard.h"
#include "ui_dashboard.h"

#include <QApplication>
#include <QtWidgets>
#include <QUiLoader>
#include "mainwindow.h"
#include "connection.h"
#include "client.h"

Dashboard::Dashboard(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dashboard)
{
    ui->setupUi(this);
    Client MasterClient(ui->tableClient, ui->StackedClient, this);

    Connection con;
    if(!con.createconnect()) {
        qDebug() << "Not Connected";
    } else {
        MasterClient.ReadClient();
        update();
    }
}

void Dashboard::update() {

   QIcon addIcon("../Resources/Icons/add.png");
   QIcon deleteIcon("../Resources/Icons/delete.png");
   QIcon updateIcon("../Resources/Icons/update.png");
   QIcon sortIcon("../Resources/Icons/sort.png");
   QIcon pdfIcon("../Resources/Icons/pdf.png");

    ui->add->setIcon(addIcon);
    ui->del->setIcon(deleteIcon);
    ui->update->setIcon(updateIcon);
    ui->sort->setIcon(sortIcon);
    ui->pdf->setIcon(pdfIcon);

    QObject::connect(ui->add, &QPushButton::clicked, this, &Dashboard::onAddClicked);
    QObject::connect(ui->del, &QPushButton::clicked, this, &Dashboard::onDeleteClicked);
    QObject::connect(ui->update, &QPushButton::clicked, this, &Dashboard::onUpdateClicked);
    QObject::connect(ui->sort, &QPushButton::clicked, this, &Dashboard::onSortClicked);
    QObject::connect(ui->pdf, &QPushButton::clicked, this, &Dashboard::onPdfClicked);

    //Dashboard Nav Buttons
    QObject::connect(ui->employees, &QPushButton::clicked, this, [this](){ ui->stackedWidget->setCurrentIndex(0); });
    QObject::connect(ui->clients, &QPushButton::clicked, this, [this](){ ui->stackedWidget->setCurrentIndex(1); });
    QObject::connect(ui->contracts, &QPushButton::clicked, this, [this](){ ui->stackedWidget->setCurrentIndex(2); });
    QObject::connect(ui->accidents, &QPushButton::clicked, this, [this](){ ui->stackedWidget->setCurrentIndex(3); });
    QObject::connect(ui->logoutButton, &QPushButton::clicked, this, &Dashboard::onLogoutButtonClicked);

    //Client
    ClientDashboardConnectUi();


}


void Dashboard::onLogoutButtonClicked() {
    close();
    mainWindowRef.show();
}



//Client

void Dashboard::ClientDashboardConnectUi()
{
    Client MasterClient(ui->tableClient, ui->StackedClient, this);

    

    QObject::connect(ui->sortClient, &QPushButton::clicked, this, &Dashboard::onSortClickedClient);
    QObject::connect(ui->pdfClient, &QPushButton::clicked, this, &Dashboard::onPdfClickedClient);


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
    switch(index) {
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
    Client MasterClient(ui->tableClient,ui->StackedClient, this);


    if (ui->ClientCreateEmail->text().isEmpty() ||
        ui->ClientCreateFirstName->text().isEmpty() ||
        ui->ClientCreateLastName->text().isEmpty() ||
        ui->ClientCreatePhoneNumber->text().isEmpty() ||
        ui->ClientCreateAddress->text().isEmpty() ||
        ui->ClientCreateDob->date().isNull()) {

        QMessageBox::critical(this, tr("Error"), tr("Please fill in all fields"),QMessageBox::Ok, QMessageBox::Ok);

        clearInputFieldsCreateClient();
    } else {
        // Validate phone number
        QString phoneNumber = ui->ClientCreatePhoneNumber->text();
        bool validPhoneNumber = phoneNumber.length() == 8 && phoneNumber.toInt(&validPhoneNumber) && validPhoneNumber;

        // Validate email
        QString email = ui->ClientCreateEmail->text();
        bool validEmail = email.contains("@") && email.contains(".");

        bool validDob = ui->ClientCreateDob->date().isValid() && ui->ClientCreateDob->date() <= QDate::currentDate();

        if (!validPhoneNumber) {
            QMessageBox::critical(this, tr("Error"), tr("Please enter a valid 8-digit phone number"),QMessageBox::Ok, QMessageBox::Ok);
        } else if (!validEmail) {
            QMessageBox::critical(this, tr("Error"), tr("Please enter a valid email address"),QMessageBox::Ok, QMessageBox::Ok);
        }
        else if (!validDob) {
            QMessageBox::critical(this, tr("Error"), tr("Please enter a valid date of birth"), QMessageBox::Ok, QMessageBox::Ok);
        }
        else {

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


        if (ui->ClientUpdateEmail->text().isEmpty() ||
            ui->ClientUpdateFirstName->text().isEmpty() ||
            ui->ClientUpdateLastName->text().isEmpty() ||
            ui->ClientUpdatePhoneNumber->text().isEmpty() ||
            ui->ClientUpdateAddress->text().isEmpty() ||
            ui->ClientUpdateDob->date().isNull()) {

            QMessageBox::critical(this, tr("Error"), tr("Please fill in all fields"),QMessageBox::Ok, QMessageBox::Ok);

            clearInputFieldsUpdateClient();
        } else {
            // Validate ID
            QString id = ui->ClientUpdateID->text();
            bool validId = id.toInt(&validId) && validId;

            // Validate phone number
            QString phoneNumber = ui->ClientUpdatePhoneNumber->text();
            bool validPhoneNumber = phoneNumber.length() == 8 && phoneNumber.toInt(&validPhoneNumber) && validPhoneNumber;

            // Validate email
            QString email = ui->ClientUpdateEmail->text();
            bool validEmail = email.contains("@") && email.contains(".");
            bool validDob = ui->ClientUpdateDob->date().isValid() && ui->ClientUpdateDob->date() <= QDate::currentDate();

            if (!validPhoneNumber) {
                QMessageBox::critical(this, tr("Error"), tr("Please enter a valid 8-digit phone number"),QMessageBox::Ok, QMessageBox::Ok);
            } else if (!validEmail) {
                QMessageBox::critical(this, tr("Error"), tr("Please enter a valid email address"),QMessageBox::Ok, QMessageBox::Ok);

            }
            else if (!validId) {
                QMessageBox::critical(this, tr("Error"), tr("Please enter a valid ID"),QMessageBox::Ok, QMessageBox::Ok);
            }
            else if (!validDob) {
				QMessageBox::critical(this, tr("Error"), tr("Please enter a valid date of birth"),QMessageBox::Ok, QMessageBox::Ok);
			}
            else {
                QMessageBox::StandardButton reply;
                reply = QMessageBox::question(this, "Update Client", "Are you sure you want to update this client?",
                                              QMessageBox::Yes|QMessageBox::No);
                if (reply == QMessageBox::Yes) {


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
            else
            {
                clearInputFieldsUpdateClient();
                return;
            }
        }
        }

    }


void Dashboard::onDeleteClickedClient() {
    Client MasterClient(ui->tableClient,ui->StackedClient, this);

    if (ui->ClientDeleteID->text().isEmpty()) {
        QMessageBox::critical(this, tr("Error"), tr("Please fill in all fields"),QMessageBox::Ok, QMessageBox::Ok);
    } else {
        // Validate ID
        QString id = ui->ClientDeleteID->text();
        bool validId = id.toInt(&validId) && validId;

        if (!validId) {
            QMessageBox::critical(this, tr("Error"), tr("Please enter a valid ID"),QMessageBox::Ok, QMessageBox::Ok);
        } else {

            QMessageBox::StandardButton reply;
            reply = QMessageBox::question(this, "Delete Client", "Are you sure you want to delete this client?", QMessageBox::Yes|QMessageBox::No);
            if (reply == QMessageBox::No) {
                clearInputFieldsDeleteClient();
                return;
            }
            else{

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
        }}
}

void Dashboard::onAddCancelClickedClient()
{
    clearInputFieldsCreateClient();
}

void Dashboard::onUpdateCancelClickedClient()
{
    	clearInputFieldsUpdateClient();
    
}

void Dashboard::onDeleteCancelClickedClient()
{
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

}

void Dashboard::onPdfClickedClient() {
}

//----------------------------------------------------------------





void Dashboard::onAddClicked() {
    // Handle add button click
}

void Dashboard::onDeleteClicked() {
    // Handle delete button click
}

void Dashboard::onUpdateClicked() {
    // Handle update button click
}

void Dashboard::onSortClicked() {
    // Handle sort button click
}

void Dashboard::onPdfClicked() {
    // Handle pdf button click
}

Dashboard::~Dashboard() {
    delete ui;
}


