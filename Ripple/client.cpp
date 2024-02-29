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
	email = "";
	first_name = "";
	last_name = "";
    phone_number = 0;
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
        QMessageBox::critical(this, tr("Save"), tr("Saved"));
    }
    else
    {
        qDebug() << "Error executing query:" << qry.lastError().text();
        QMessageBox::critical(this, tr("Error"), qry.lastError().text());
    }
}
