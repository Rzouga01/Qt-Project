#include "contract.h"
#include "ui_contract.h"
#include <QtDebug>
#include <QDate>
#include <QMessageBox>
#include <QSqlError>
#include <QTableWidgetItem>
contract::contract(QWidget* parent) :
    QDialog(parent),
    ui(new Ui::contract),
    tableContract(nullptr),
    stackedContract(nullptr)
{
    ui->setupUi(this);
    EFFECTIVE_DATE = QDate::currentDate();
    EXPIRATION_DATE = QDate::currentDate();
}

contract::contract(QTableWidget* tableWidget, QStackedWidget* stackedWidget, QWidget* parent)
    : QDialog(parent), ui(new Ui::contract), tableContract(tableWidget), stackedContract(stackedWidget)
{
    ui->setupUi(this);
    EFFECTIVE_DATE = QDate::currentDate();
    EXPIRATION_DATE = QDate::currentDate();
}


void contract::setStackedWidget(QStackedWidget* stackedWidget) {
    stackedContract = stackedWidget;
}

void contract::setTableWidget(QTableWidget* tableWidget)
{
    tableContract = tableWidget;
}

contract::~contract()
{
    delete ui;
}


//Constructeur paramété
contract::contract(int USER_ID, int CLIENT_ID, int PREMIUM_AMOUNT, QDate EFFECTIVE_DATE, QDate EXPIRATION_DATE, int PAYMENT_STATUS, QString TYPE) {
    this->USER_ID = USER_ID;
    this->CLIENT_ID = CLIENT_ID;
    this->PREMIUM_AMOUNT = PREMIUM_AMOUNT;
    this->EFFECTIVE_DATE = EFFECTIVE_DATE;
    this->EXPIRATION_DATE = EXPIRATION_DATE;
    this->PAYMENT_STATUS = PAYMENT_STATUS;
    this->TYPE = TYPE;
}
contract::contract() {
    CONTRACT_ID = -1;
    USER_ID = 0;
    CLIENT_ID = 0;
    PREMIUM_AMOUNT = 0;
    EFFECTIVE_DATE = QDate::currentDate();
    EXPIRATION_DATE = QDate::currentDate();
    PAYMENT_STATUS = 0;
    TYPE = "";


}



//fonction ajouter
bool contract::CreateContract(int USER_ID, int CLIENT_ID, int PREMIUM_AMOUNT, QDate EFFECTIVE_DATE, QDate EXPIRATION_DATE, int PAYMENT_STATUS, QString TYPE) {
    QSqlQuery query;

    query.prepare("INSERT INTO CONTRACTS(USER_ID,CLIENT_ID,PREMIUM_AMOUNT,EFFECTIVE_DATE,EXPIRATION_DATE,PAYMENT_STATUS,TYPE) values( :USER_ID, :CLIENT_ID, :PREMIUM_AMOUNT, :EFFECTIVE_DATE, :EXPIRATION_DATE, :PAYMENT_STATUS, :TYPE)");

    query.bindValue(":USER_ID", USER_ID);
    query.bindValue(":CLIENT_ID", CLIENT_ID);
    query.bindValue(":PREMIUM_AMOUNT", PREMIUM_AMOUNT);
    query.bindValue(":EFFECTIVE_DATE", EFFECTIVE_DATE);
    query.bindValue(":EXPIRATION_DATE", EXPIRATION_DATE);
    query.bindValue(":PAYMENT_STATUS", PAYMENT_STATUS);
    query.bindValue(":TYPE", TYPE);

    if (query.exec()) {
        qDebug() << "Contract saved successfuly ." << "Data :" <<
            "\nuser_id :" << USER_ID <<
            "\nclient_id :" << CLIENT_ID <<
            "\npremium_amount :" << PREMIUM_AMOUNT <<
            "\neffective_date :" << EFFECTIVE_DATE.toString("yyyy-MM-dd") <<
            "\nexpiration_date :" << EXPIRATION_DATE.toString("yyyy-MM-dd") <<
            "\npayment_status :" << PAYMENT_STATUS <<
            "\ntype :" << TYPE;
        return true;
    }
    else {
        qDebug() << "Error Creating Contract query:" << query.lastError().text();
        QMessageBox::critical(this, tr("Error"), query.lastError().text());
        return false;
    }
}


// fonction supprimer
bool contract::DeleteContract(int id) {
    QSqlQuery query;
    query.prepare("SELECT * FROM CONTRACTS WHERE CONTRACT_ID = :id ");
    query.bindValue(":id", id);

    if (query.exec()) {
        if (query.next()) {
            QSqlQuery deleteQuery;
            deleteQuery.prepare("DELETE FROM CONTRACTS WHERE CONTRACT_ID = :id ");
            deleteQuery.bindValue(":id", id);

            if (deleteQuery.exec()) {
                qDebug() << "Contract found. Deleting process ...";
                return true;
            }
            else {
                qDebug() << "Error executing delete query:" << deleteQuery.lastError().text();
                return false;
            }
        }
        else {
            qDebug() << "Contract not found.";
            return false;
        }
    }
    else {
        qDebug() << "Error executing query:" << query.lastError().text();
        return false;
    }
}


//fonction lire
void contract::ReadContract() {
    if (tableContract == nullptr) {
        qDebug() << "Error : tableContract is null";
        return;
    }

    tableContract->clearContents();
    tableContract->setRowCount(0);

    QSqlQuery query;
    query.prepare("SELECT * FROM CONTRACTS");
    if (query.exec()) {
        while (query.next()) {
            int row = tableContract->rowCount();
            tableContract->insertRow(row);

            tableContract->setItem(row, 0, new QTableWidgetItem(query.value(0).toString()));
            tableContract->setItem(row, 1, new QTableWidgetItem(query.value(1).toString()));
            tableContract->setItem(row, 2, new QTableWidgetItem(query.value(2).toString()));
            tableContract->setItem(row, 3, new QTableWidgetItem(query.value(3).toString()));
            tableContract->setItem(row, 4, new QTableWidgetItem(query.value(4).toDate().toString()));
            tableContract->setItem(row, 5, new QTableWidgetItem(query.value(5).toDate().toString()));
            tableContract->setItem(row, 6, new QTableWidgetItem(query.value(6).toString()));
            tableContract->setItem(row, 7, new QTableWidgetItem(query.value(7).toString()));
        }
        tableContract->repaint();
    }
    else {
        qDebug() << "Error executing query:" << query.lastError().text();
    }
}


//fonction modifier
bool contract::UpdateContract(int contractID, int USER_ID, int CLIENT_ID, int PREMIUM_AMOUNT, QDate EFFECTIVE_DATE, QDate EXPIRATION_DATE, int PAYMENT_STATUS, QString TYPE) {
    QSqlQuery query;
    query.prepare("SELECT * FROM CONTRACTS WHERE CONTRACT_ID = :id");
    query.bindValue(":id", contractID);

    if (query.exec()) {
        if (query.next()) {
            QSqlQuery updateQuery;
            updateQuery.prepare("UPDATE CONTRACTS SET USER_ID = :USER_ID, CLIENT_ID = :CLIENT_ID, PREMIUM_AMOUNT = :PREMIUM_AMOUNT, EFFECTIVE_DATE = :EFFECTIVE_DATE, EXPIRATION_DATE = :EXPIRATION_DATE, PAYMENT_STATUS = :PAYMENT_STATUS, TYPE = :TYPE WHERE CONTRACT_ID = :id");
            updateQuery.bindValue(":id", contractID);
            updateQuery.bindValue(":USER_ID", USER_ID);
            updateQuery.bindValue(":CLIENT_ID", CLIENT_ID);
            updateQuery.bindValue(":PREMIUM_AMOUNT", PREMIUM_AMOUNT);
            updateQuery.bindValue(":EFFECTIVE_DATE", EFFECTIVE_DATE.toString("yyyy-MM-dd"));
            updateQuery.bindValue(":EXPIRATION_DATE", EXPIRATION_DATE.toString("yyyy-MM-dd"));
            updateQuery.bindValue(":PAYMENT_STATUS", PAYMENT_STATUS);
            updateQuery.bindValue(":TYPE", TYPE);

            if (updateQuery.exec()) {
                qDebug() << "Contract Updated successfully ." << "Data :" <<
                    "\nuser_id :" << USER_ID <<
                    "\nclient_id :" << CLIENT_ID <<
                    "\npremium_amount :" << PREMIUM_AMOUNT <<
                    "\neffective_date :" << EFFECTIVE_DATE.toString("yyyy-MM-dd") <<
                    "\nexpiration_date:" << EXPIRATION_DATE.toString("yyyy-MM-dd") <<
                    "\npayment_status :" << PAYMENT_STATUS <<
                    "\ntype :" << TYPE;
                return true;
            }
            else {
                qDebug() << "Error executing update query :" << updateQuery.lastError().text();
                QMessageBox::critical(nullptr, tr("Error"), updateQuery.lastError().text());
                return false;
            }
        }
        else {
            QMessageBox::critical(nullptr, tr("Error"), tr("Contract not found"));
            return false;
        }
    }
    else {
        qDebug() << "Error executing select query:" << query.lastError().text();
        QMessageBox::critical(nullptr, tr("Error"), query.lastError().text());
        return false;
    }
}

bool contract::searchContract(int id) {
    QSqlQuery query;
    query.prepare("SELECT * FROM CONTRACTS WHERE CONTRACT_ID = :id");
    query.bindValue(":id", id);

    if (query.exec()) {
        if (query.next()) {
            // Contrat trouvé, récupérer les données
            int USER_ID = query.value("USER_ID").toInt();
            int CLIENT_ID = query.value("CLIENT_ID").toInt();
            int PREMIUM_AMOUNT = query.value("PREMIUM_AMOUNT").toInt();
            QDate EFFECTIVE_DATE = query.value("EFFECTIVE_DATE").toDate();
            QDate EXPIRATION_DATE = query.value("EXPIRATION_DATE").toDate();
            int PAYMENT_STATUS = query.value("PAYMENT_STATUS").toInt();
            QString TYPE = query.value("TYPE").toString();

            // Afficher les données du contrat (vous pouvez faire d'autres actions ici)
            qDebug() << "Contract found:" <<
                "\nContract ID: " << CONTRACT_ID <<
                "\nUser ID: " << USER_ID <<
                "\nClient ID: " << CLIENT_ID <<
                "\nPremium Amount: " << PREMIUM_AMOUNT <<
                "\nEffective Date: " << EFFECTIVE_DATE <<
                "\nExpiration Date: " << EXPIRATION_DATE <<
                "\nPayment Status: " << PAYMENT_STATUS <<
                "\nType: " << TYPE;

            return true; // Succès, contrat trouvé
        }
        else {
            qDebug() << "Contract with ID" << CONTRACT_ID << "not found";
            return false; // Le contrat n'existe pas dans la base de données
        }
    }
    else {
        qDebug() << "Error executing search query:" << query.lastError().text();
        return false; // Erreur lors de l'exécution de la requête
    }
}



/*
contract::contract(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::contract)
{
    ui->setupUi(this);
}
*/


