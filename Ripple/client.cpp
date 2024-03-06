#include "client.h"

#include "ui_client.h"
#include "connection.h"

#include <QMessageBox>
#include <QtDebug>
#include <QDate>
#include <QSqlQuery>
#include <QTableWidgetItem>


Client::Client(QWidget* parent) :
    QDialog(parent),
    id(-1),
    email(""),
    first_name(""),
    last_name(""),
    phone_number(""),
    address(""),
    dob(QDate::currentDate()),
    ui(new Ui::Client),
    tableClient(nullptr)
{
    ui->setupUi(this);


}

Client::Client(const Client& other)
{
    this->id = other.id;
    this->email = other.email;
    this->first_name = other.first_name;
    this->last_name = other.last_name;
    this->phone_number = other.phone_number;
    this->address = other.address;
    this->dob = other.dob;
}

Client::Client(QTableWidget *tableWidget, QWidget *parent)
    : QDialog(parent), ui(new Ui::Client), tableClient(tableWidget)

{
    ui->setupUi(this);
}


void Client::setTableWidget(QTableWidget *tableWidget)

{
    tableClient = tableWidget;
}


Client::~Client()
{
    delete ui;
}


Client::Client()
{
    id = -1;
    email = "";
    first_name = "";
    last_name = "";
    phone_number = "";
    address = "";
    dob = QDate::currentDate();
}

Client::Client(const QString& email, const QString& first_name, const QString& last_name, const QString& phone_number, const QString& address, const QDate& dob)
{
    this->email = email;
    this->first_name = first_name;
    this->last_name = last_name;
    this->phone_number = phone_number;
    this->address = address;
    this->dob = dob;
}


void Client::CreateClient()
{
    QSqlQuery qry;
    qry.prepare("INSERT INTO CLIENTS (EMAIL, FIRST_NAME, LAST_NAME, ADDRESS, PHONE_NUMBER, DOB) VALUES (:email, :first_name, :last_name, :address, :phone_number, :dob)");
    qry.bindValue(":email", this->email);
    qry.bindValue(":first_name", this->first_name);
    qry.bindValue(":last_name", this->last_name);
    qry.bindValue(":phone_number", this->phone_number);
    qry.bindValue(":address", this->address);
    qry.bindValue(":dob", this->dob);

    if (qry.exec())
    {
        // Retrieve the ID of the last inserted record

        qDebug() << "Client saved successfully." << "Data:" <<
            "\nEmail :" << this->email <<
            "\nFirst Name :" << this->first_name <<
            "\nLast Name :" << this->last_name <<
            "\nPhone Number :" << this->phone_number <<
            "\nAddress :" << this->address <<
            "\nDate of Birth :" << this->dob.toString();
    }
    else
    {
        qDebug() << "Error Creating Client query:" << qry.lastError().text();
        QMessageBox::critical(this, tr("Error"), qry.lastError().text());
    }
}

void Client::CreateClient(QString email,QString first_name,QString last_name,QString phone_number,QString address,QDate dob)
{
    QSqlQuery qry;
    qry.prepare("INSERT INTO CLIENTS (EMAIL, FIRST_NAME, LAST_NAME, ADDRESS, PHONE_NUMBER, DOB) VALUES (:email, :first_name, :last_name, :address, :phone_number, :dob)");
    qry.bindValue(":email", email);
    qry.bindValue(":first_name", first_name);
    qry.bindValue(":last_name", last_name);
    qry.bindValue(":phone_number", phone_number);
    qry.bindValue(":address", address);
    qry.bindValue(":dob", dob);

    if (qry.exec())
    {

        qDebug() << "Client saved successfully." << "Data:" <<
            "\nEmail :" << email <<
            "\nFirst Name :" << first_name <<
            "\nLast Name :" << last_name <<
            "\nPhone Number :" << phone_number <<
            "\nAddress :" << address <<
            "\nDate of Birth :" << dob.toString();
    }
    else
    {
        qDebug() << "Error Creating Client query:" << qry.lastError().text();
        QMessageBox::critical(this, tr("Error"), qry.lastError().text());
    }
}




void Client::DeleteClient(int id)
{
    QSqlQuery qry;
    qry.prepare("DELETE FROM CLIENTS WHERE CLIENT_ID = :id");
    qry.bindValue(":id", id);
    if (qry.exec())
    {
        QMessageBox::critical(this, tr("Deleted"), tr("Deleted"));
    }
    else
    {
        qDebug() << "Error executing query:" << qry.lastError().text();
        QMessageBox::critical(this, tr("Error"), qry.lastError().text());
    }
}


void Client::ReadClient()
{
    if (tableClient == nullptr) {
        qDebug() << "Error: tableClient is null";
        return;
    }

    tableClient->clearContents();
    tableClient->setRowCount(0); 

    QSqlQuery qry;
    qry.prepare("SELECT * FROM CLIENTS");
    if (qry.exec())
    {
        while (qry.next())
        {
            int row = tableClient->rowCount();
            tableClient->insertRow(row);

            tableClient->setItem(row, 0, new QTableWidgetItem(qry.value(0).toString()));
            tableClient->setItem(row, 1, new QTableWidgetItem(qry.value(1).toString()));
            tableClient->setItem(row, 2, new QTableWidgetItem(qry.value(2).toString()));
            tableClient->setItem(row, 3, new QTableWidgetItem(qry.value(3).toString()));
            tableClient->setItem(row, 4, new QTableWidgetItem(qry.value(4).toString()));
            tableClient->setItem(row, 5, new QTableWidgetItem(qry.value(5).toString()));
            tableClient->setItem(row, 6, new QTableWidgetItem(qry.value(6).toDate().toString()));
        }
        tableClient->repaint();
    }
    else
    {
        qDebug() << "Error executing query:" << qry.lastError().text();
    }
}



void Client::UpdateClient(int clientID, const Client& NewClient)
{
    QSqlQuery qry;

    qry.prepare("SELECT * FROM CLIENTS WHERE CLIENT_ID = :id");
    qry.bindValue(":id", clientID);

    if (qry.exec())
    {
        if (qry.next())
        {
            qry.prepare("UPDATE CLIENTS SET EMAIL = :email, FIRST_NAME = :first_name, LAST_NAME = :last_name, ADDRESS = :address, PHONE_NUMBER = :phone_number, DOB = TO_DATE(:dob, 'YYYY-MM-DD') WHERE CLIENT_ID = :id");
            qry.bindValue(":id", clientID);
            qry.bindValue(":email", NewClient.getEmail());
            qry.bindValue(":first_name", NewClient.getFirstName());
            qry.bindValue(":last_name", NewClient.getLastName());
            qry.bindValue(":phone_number", NewClient.getPhoneNumber());
            qry.bindValue(":address", NewClient.getAddress());
            qry.bindValue(":dob", NewClient.getDob().toString("yyyy-MM-dd")); // Ensure the date format matches 'YYYY-MM-DD'

            if (qry.exec())
            {
                qDebug() << "Client Updated successfully." << "Data:" <<
                    "\nEmail :" << NewClient.getEmail() <<
                    "\nFirst Name :" << NewClient.getFirstName() <<
                    "\nLast Name :" << NewClient.getLastName() <<
                    "\nPhone Number :" << NewClient.getPhoneNumber() <<
                    "\nAddress :" << NewClient.getAddress() <<
                    "\nDate of Birth :" << NewClient.getDob().toString(Qt::ISODate);
            }
            else
            {
                qDebug() << "Error executing update query:" << qry.lastError().text();
                QMessageBox::critical(this, tr("Error"), qry.lastError().text());
            }
        }
        else
        {
            QMessageBox::critical(this, tr("Error"), tr("Client not found"));
        }
    }
    else
    {
        qDebug() << "Error executing select query:" << qry.lastError().text();
        QMessageBox::critical(this, tr("Error"), qry.lastError().text());
    }
}

void Client::UpdateClient(int clientID, QString email, QString first_name, QString last_name, QString phone_number, QString address, QDate dob)
{
    QSqlQuery qry;

    qry.prepare("SELECT * FROM CLIENTS WHERE CLIENT_ID = :id");
    qry.bindValue(":id", clientID);

    if (qry.exec())
    {
        if (qry.next())
        {
            qry.prepare("UPDATE CLIENTS SET EMAIL = :email, FIRST_NAME = :first_name, LAST_NAME = :last_name, ADDRESS = :address, PHONE_NUMBER = :phone_number, DOB = TO_DATE(:dob, 'YYYY-MM-DD') WHERE CLIENT_ID = :id");
            qry.bindValue(":id", clientID);
            qry.bindValue(":email", email);
            qry.bindValue(":first_name", first_name);
            qry.bindValue(":last_name", last_name);
            qry.bindValue(":phone_number", phone_number);
            qry.bindValue(":address", address);
            qry.bindValue(":dob", dob.toString("yyyy-MM-dd")); // Convert QDate to string in the 'YYYY-MM-DD' format

            if (qry.exec())
            {
                qDebug() << "Client Updated successfully." << "Data:" <<
                    "\nEmail :" << email <<
                    "\nFirst Name :" << first_name <<
                    "\nLast Name :" << last_name <<
                    "\nPhone Number :" << phone_number <<
                    "\nAddress :" << address <<
                    "\nDate of Birth :" << dob.toString("yyyy-MM-dd");
            }
            else
            {
                qDebug() << "Error executing update query:" << qry.lastError().text();
                QMessageBox::critical(nullptr, tr("Error"), qry.lastError().text()); // As this is not part of a QDialog, pass nullptr
            }
        }
        else
        {
            QMessageBox::critical(nullptr, tr("Error"), tr("Client not found")); // As this is not part of a QDialog, pass nullptr
        }
    }
    else
    {
        qDebug() << "Error executing select query:" << qry.lastError().text();
        QMessageBox::critical(nullptr, tr("Error"), qry.lastError().text()); // As this is not part of a QDialog, pass nullptr
    }
}

