#include "client.h"

#include "ui_client.h"
#include "connection.h"

#include <QMessageBox>
#include <QtDebug>
#include <QDate>
#include <QSqlQuery>
#include <QTableWidgetItem>
#include <QTableWidget>
#include <Qpushbutton>


Client::Client(QWidget* parent) :
    QDialog(parent),
    dob(QDate::currentDate()),
    ui(new Ui::Client),
    tableClient(nullptr),
    stackedClient(nullptr)
{
    ui->setupUi(this);


}

Client::Client(QTableWidget *tableWidget, QStackedWidget* stackedWidget ,QWidget *parent)
    : QDialog(parent), ui(new Ui::Client), tableClient(tableWidget), stackedClient(stackedWidget)

{
    ui->setupUi(this);
}
void Client::setStackedWidget(QStackedWidget* stackedWidget)
{
	stackedClient = stackedWidget;
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


bool Client::CreateClient()
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
        return true;
    }
    else
    {
        qDebug() << "Error Creating Client query:" << qry.lastError().text();
        QMessageBox::critical(this, tr("Error"), qry.lastError().text());
        return false;
    }
}

bool Client::CreateClient(QString email,QString first_name,QString last_name,QString phone_number,QString address,QDate dob)
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
        return true;
    }
    else
    {
        qDebug() << "Error Creating Client query:" << qry.lastError().text();
        QMessageBox::critical(this, tr("Error"), qry.lastError().text());
        return false;
    }
}




bool Client::DeleteClient(int id)
{
    QSqlQuery qry;
    qry.prepare("SELECT * FROM CLIENTS WHERE CLIENT_ID = :id");
    qry.bindValue(":id", id);

    if (qry.exec())
    {
        if (qry.next())
        {
            qry.prepare("DELETE FROM CLIENTS WHERE CLIENT_ID = :id");
            qry.bindValue(":id", id);
            if (qry.exec())
            {
                qDebug() << "Client found. Deleting...";
                return true;
            }
            else
            {
                qDebug() << "Error executing query:" << qry.lastError().text();
                QMessageBox::critical(this, tr("Error"), qry.lastError().text());
                return false;
            }
        }
        else
        {
            qDebug() << "Client not found.";
            return false;
        }
    }
    else
    {
        qDebug() << "Error executing query:" << qry.lastError().text();
        QMessageBox::critical(this, tr("Error"), qry.lastError().text());
        return false;
    }
}


/*void Client::ReadClient() {
    if (tableClient == nullptr) {
        qDebug() << "Error: tableClient is null";
        return;
    }

    if (stackedClient == nullptr) {
        qDebug() << "Error: stackedClient is null";
        return;
    }

    tableClient->clearContents();
    tableClient->setRowCount(0);

    QSqlQuery qry;
    qry.prepare("SELECT * FROM CLIENTS");
    if (qry.exec()) {
        while (qry.next()) {
            int row = tableClient->rowCount();
            tableClient->insertRow(row);

            // Set data items for each column
            for (int col = 0; col < 6; ++col) {
                QTableWidgetItem* item = new QTableWidgetItem(qry.value(col).toString());
                tableClient->setItem(row, col, item);
            }


            QTableWidgetItem* dateItem = new QTableWidgetItem(qry.value(6).toDate().toString());
            tableClient->setItem(row, 6, dateItem);


            QPushButton* deleteButton = new QPushButton("Delete");
            connect(deleteButton, &QPushButton::clicked, [this, row]() {
                int clientId = tableClient->item(row, 0)->text().toInt();
                stackedClient->setCurrentIndex(2); 
                });
            tableClient->setCellWidget(row, 7, deleteButton); 

            // Add update button
            QPushButton* updateButton = new QPushButton("Update");
            connect(updateButton, &QPushButton::clicked, [this, row]() {
                // Handle the update button click event here
                // You may want to open a dialog for updating client information
                });
            tableClient->setCellWidget(row, 8, updateButton); 
        }
    }
    else {
        qDebug() << "Error executing query:" << qry.lastError().text();
    }
}*/


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


            tableClient->setRowHeight(row, 50);
            tableClient->setFont(QFont("Helvetica", 10));
            tableClient->setColumnWidth(0, 10);//ID
            tableClient->setColumnWidth(1, 150);//EMAIL
            tableClient->setColumnWidth(2, 50);//FIRST NAME
            tableClient->setColumnWidth(3, 50);//LAST NAME
            tableClient->setColumnWidth(4, 150);//ADDRESS
            tableClient->setColumnWidth(5, 75);//PHONE NUMBER
            tableClient->setColumnWidth(6, 50);//DOB
            tableClient->setColumnWidth(7, 15);//DELETE BUTTON
            tableClient->setColumnWidth(8, 16);//UPDATE BUTTON

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


/*void Client::ReadClient()
{
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

            // Set data items for each column
            for (int col = 0; col < 6; ++col)
            {
                QTableWidgetItem* item = new QTableWidgetItem(qry.value(col).toString());
                tableClient->setItem(row, col, item);
            }

            // Set date
            QTableWidgetItem* dateItem = new QTableWidgetItem(qry.value(6).toDate().toString());
            tableClient->setItem(row, 6, dateItem);

            // Add delete button
            QPushButton* deleteButton = new QPushButton("Delete");
            connect(deleteButton, &QPushButton::clicked, [this, row]() {
                int clientId = tableClient->item(row, 0)->text().toInt();
                QMessageBox::StandardButton reply;
                reply = QMessageBox::question(this, "Delete", "Are you sure you want to delete this client?", QMessageBox::Yes | QMessageBox::No);
                if (reply == QMessageBox::Yes)
                {
                    if (DeleteClient(clientId))
                    {
                        tableClient->removeRow(row);
                    }
                }
                });
            tableClient->setCellWidget(row, 7, deleteButton); // Assuming delete button is in column 7

            // Add update button
            QPushButton* updateButton = new QPushButton("Update");
            connect(updateButton, &QPushButton::clicked, [this, row]() {
                // Handle the update button click event here
                // You may want to open a dialog for updating client information
                });
            tableClient->setCellWidget(row, 8, updateButton); // Assuming update button is in column 8
        }
    }
    else
    {
        qDebug() << "Error executing query:" << qry.lastError().text();
    }
}*/





bool Client::UpdateClient(int clientID, const Client& NewClient)
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
                return true;
            }
            else
            {
                qDebug() << "Error executing update query:" << qry.lastError().text();
                QMessageBox::critical(this, tr("Error"), qry.lastError().text());
                return false;
            }
        }
        else
        {
            QMessageBox::critical(this, tr("Error"), tr("Client not found"));
            return false;
        }
    }
    else
    {
        qDebug() << "Error executing select query:" << qry.lastError().text();
        QMessageBox::critical(this, tr("Error"), qry.lastError().text());
        return false;
    }
}

bool Client::UpdateClient(int clientID, QString email, QString first_name, QString last_name, QString phone_number, QString address, QDate dob)
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
                return true;
            }
            else
            {
                qDebug() << "Error executing update query:" << qry.lastError().text();
                QMessageBox::critical(nullptr, tr("Error"), qry.lastError().text()); // As this is not part of a QDialog, pass nullptr
                return false;
            }
        }
        else
        {
            return false;
        }
    }
    else
    {
        qDebug() << "Error executing select query:" << qry.lastError().text();
        QMessageBox::critical(nullptr, tr("Error"), qry.lastError().text()); // As this is not part of a QDialog, pass nullptr
        return false;
    }
}

