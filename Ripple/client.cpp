#include "client.h"
#include "ui_client.h"
#include "connection.h"
#include <QMessageBox>
#include <QtDebug>
#include <QDate>

Client::Client(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Client)
{
    ui->setupUi(this);


}

Client::~Client()
{
    delete ui;
}
Client::Client()
{
    id=-1;
	email = "";
	first_name = "";
	last_name = "";
    phone_number = "";
	adress = "";
    dob =QDate::currentDate();
}

Client::Client(QString email, QString first_name, QString last_name, QString phone_number, QString adress, QDate dob)
{
	this->email = email;
	this->first_name = first_name;
	this->last_name = last_name;
	this->phone_number = phone_number;
	this->adress = adress;
	this->dob = dob;
}

void Client::CreateClient()
{

    QSqlQuery qry;

    qry.prepare("INSERT INTO CLIENTS (EMAIL, FIRST_NAME, LAST_NAME, ADRESS, PHONE_NUMBER, DOB) VALUES ( :email, :first_name, :last_name,  :adress, :phone_number, :dob)");

    qry.bindValue(":email", this->email);
    qry.bindValue(":first_name", this->first_name);
    qry.bindValue(":last_name", this->last_name);
    qry.bindValue(":phone_number", this->phone_number);
    qry.bindValue(":adress", this->adress);
    qry.bindValue(":dob", this->dob);

    if (qry.exec())
    {

        qDebug() << "Client saved successfully."<<"Data:"<<
            "\nEmail :"<<this->id <<
            "\nFirst Name :"<< this->first_name <<
            "\nLast Name :"<<this->last_name <<
            "\nPhone Number :"<<this->phone_number <<
            "\nAdress :"<<this->adress <<
            "\nDate of Birth :"<<this->dob.toString();
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
    if(qry.exec())
    {
        QMessageBox::critical(this, tr("Deleted"), tr("Deleted"));
    }
    else{
        qDebug() << "Error executing query:" << qry.lastError().text();
        QMessageBox::critical(this, tr("Error"), qry.lastError().text());

    }

}

void Client::ReadClient()
{
    QSqlQuery qry;
    qry.prepare("SELECT * FROM CLIENTS");
    if(qry.exec())
    {
        while(qry.next())
        {
            qDebug() << "Client ID :"<<qry.value(0).toInt() <<
                "\nEmail :"<<qry.value(1).toString() <<
                "\nFirst Name :"<<qry.value(2).toString() <<
                "\nLast Name :"<<qry.value(3).toString() <<
                "\nPhone Number :"<<qry.value(4).toString() <<
                "\nAdress :"<<qry.value(5).toString() <<
                "\nDate of Birth :"<<qry.value(6).toDate();
            qDebug() << "---------------------------------------";
        }
    }
    else
    {
        qDebug() << "Error executing query:" << qry.lastError().text();
    }
}


