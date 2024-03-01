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
    ui(new Ui::Client),
    tableClient(nullptr){
    ui->setupUi(this);
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

Client::Client(QString email, QString first_name, QString last_name, QString phone_number, QString address, QDate dob)
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
        qDebug() << "Client saved successfully." << "Data:" <<
            "\nEmail :" << this->id <<
            "\nFirst Name :" << this->first_name <<
            "\nLast Name :" << this->last_name <<
            "\nPhone Number :" << this->phone_number <<
            "\nAddress :" << this->address <<
            "\nDate of Birth :" << this->dob.toString();
    }
    else
    {
        qDebug() << "Error Creating Client query:" << qry.lastError().text();
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


void Client::UpdateClient(Client NewClient)
{
    QSqlQuery qry;

    qry.prepare("UPDATE CLIENTS SET EMAIL = :email, FIRST_NAME = :first_name, LAST_NAME = :last_name, ADDRESS = :address, PHONE_NUMBER = :phone_number, DOB = :dob WHERE CLIENT_ID = :id");
    qry.bindValue(":id", NewClient.id);
    qry.bindValue(":email", NewClient.email);
    qry.bindValue(":first_name", NewClient.first_name);
    qry.bindValue(":last_name", NewClient.last_name);
    qry.bindValue(":phone_number", NewClient.phone_number);
    qry.bindValue(":address", NewClient.address);
    qry.bindValue(":dob", NewClient.dob);

    if (qry.exec())
    {
        qDebug() <<"Client Updated successfully." << "Data:" <<
            "\nEmail :" << NewClient.id <<
            "\nFirst Name :" << NewClient.first_name <<
            "\nLast Name :" << NewClient.last_name <<
            "\nPhone Number :" << NewClient.phone_number <<
            "\nAddress :" << NewClient.address <<
            "\nDate of Birth :" << NewClient.dob.toString();
    }
    else
    {
        qDebug() << "Error executing query:" << qry.lastError().text();
        QMessageBox::critical(this, tr("Error"), qry.lastError().text());
    }

}
