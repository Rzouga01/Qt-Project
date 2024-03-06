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
    Client client(ui->tableClient, this);
    Connection con;

    if(!con.createconnect())
    {
        qDebug() << "Not Connected";
    }
    else
    {
        client.ReadClient();
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
    QObject::connect(ui->addClient, &QPushButton::clicked, this, [this]() { ui->StackedClient->setCurrentIndex(0); });
    QObject::connect(ui->updateClient, &QPushButton::clicked, this, [this]() { ui->StackedClient->setCurrentIndex(1); });
    QObject::connect(ui->deleteClient, &QPushButton::clicked, this, [this]() { ui->StackedClient->setCurrentIndex(2); });

    QObject::connect(ui->ClientCreateButton, &QPushButton::clicked, this, &Dashboard::onAddClickedClient);
    QObject::connect(ui->ClientUpdateButton, &QPushButton::clicked, this, &Dashboard::onUpdateClickedClient);



    this->repaint();
}


void Dashboard::onLogoutButtonClicked() {
    close();
    mainWindowRef.show();
}



//Client
void Dashboard::onAddClickedClient() {
    Client readClient(ui->tableClient, this);

    // Check if any of the input fields are empty or null
    if (ui->ClientCreateEmail->text().isEmpty() ||
        ui->ClientCreateFirstName->text().isEmpty() ||
        ui->ClientCreateLastName->text().isEmpty() ||
        ui->ClientCreatePhoneNumber->text().isEmpty() ||
        ui->ClientCreateAddress->text().isEmpty() ||
        ui->ClientCreateDob->date().isNull()) {

        // Display an error message to the user
        QMessageBox::critical(this, tr("Error"), tr("Please fill in all fields"),QMessageBox::Ok, QMessageBox::Ok);

        // Clear all input fields
        clearInputFields();
    } else {
        // Validate phone number
        QString phoneNumber = ui->ClientCreatePhoneNumber->text();
        bool validPhoneNumber = phoneNumber.length() == 8 && phoneNumber.toInt(&validPhoneNumber) && validPhoneNumber;

        // Validate email
        QString email = ui->ClientCreateEmail->text();
        bool validEmail = email.contains("@") && email.contains(".");

        if (!validPhoneNumber) {
            QMessageBox::critical(this, tr("Error"), tr("Please enter a valid 8-digit phone number"),QMessageBox::Ok, QMessageBox::Ok);
        } else if (!validEmail) {
            QMessageBox::critical(this, tr("Error"), tr("Please enter a valid email address"),QMessageBox::Ok, QMessageBox::Ok);
        } else {
            // All input fields are valid, proceed with creating the client
            Client client(ui->ClientCreateEmail->text(),
                          ui->ClientCreateFirstName->text(),
                          ui->ClientCreateLastName->text(),
                          ui->ClientCreatePhoneNumber->text(),
                          ui->ClientCreateAddress->text(),
                          ui->ClientCreateDob->date());

            client.CreateClient();
            readClient.ReadClient();

            clearInputFields();
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


void Dashboard::onDeleteClickedClient() {

}

void Dashboard::onUpdateClickedClient() {

}

void Dashboard::onSortClickedClient() {

}

void Dashboard::onPdfClickedClient() {
}







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


