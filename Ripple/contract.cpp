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
    tableContract(nullptr)
{
    ui->setupUi(this);
    EFFECTIVE_DATE = QDate::currentDate();
    EXPIRATION_DATE = QDate::currentDate();
}

contract::contract(QTableWidget *tableWidget, QWidget *parent)
    : QDialog(parent), ui(new Ui::contract), tableContract(tableWidget)
{
    ui->setupUi(this);
    EFFECTIVE_DATE = QDate::currentDate();
    EXPIRATION_DATE = QDate::currentDate();
}

void contract::setTableWidget(QTableWidget *tableWidget)
{
    tableContract = tableWidget;
}

contract::~contract()
{
    delete ui;
}


//Constructeur paramété
contract::contract(int USER_ID,int CLIENT_ID,int PREMIUM_AMOUNT,QDate EFFECTIVE_DATE,QDate EXPIRATION_DATE,int PAYMENT_STATUS,QString TYPE){
    this->USER_ID=USER_ID;
    this->CLIENT_ID=CLIENT_ID;
    this->PREMIUM_AMOUNT=PREMIUM_AMOUNT;
    this->EFFECTIVE_DATE=EFFECTIVE_DATE;
    this->EXPIRATION_DATE=EXPIRATION_DATE;
    this->PAYMENT_STATUS=PAYMENT_STATUS;
    this->TYPE=TYPE;
}
contract::contract(){
    CONTRACT_ID=-1;
    USER_ID=0;
    CLIENT_ID=0;
    PREMIUM_AMOUNT=0;
    EFFECTIVE_DATE=QDate::currentDate();
    EXPIRATION_DATE=QDate::currentDate();
    PAYMENT_STATUS=0;
    TYPE="";


}



//fonction ajouter
void contract::ajouter(int USER_ID, int CLIENT_ID, int PREMIUM_AMOUNT, QDate EFFECTIVE_DATE, QDate EXPIRATION_DATE, int PAYMENT_STATUS, QString TYPE){
    QSqlQuery query;

    query.prepare("INSERT INTO CONTRACTS(USER_ID,CLIENT_ID,PREMIUM_AMOUNT,EFFECTIVE_DATE,EXPIRATION_DATE,PAYMENT_STATUS,TYPE) values( :USER_ID, :CLIENT_ID, :PREMIUM_AMOUNT, :EFFECTIVE_DATE, :EXPIRATION_DATE, :PAYMENT_STATUS, :TYPE)");

    query.bindValue(":USER_ID",USER_ID);
    query.bindValue(":CLIENT_ID",CLIENT_ID);
    query.bindValue(":PREMIUM_AMOUNT",PREMIUM_AMOUNT);
    query.bindValue(":EFFECTIVE_DATE",EFFECTIVE_DATE);
    query.bindValue(":EXPIRATION_DATE",EXPIRATION_DATE);
    query.bindValue(":PAYMENT_STATUS",PAYMENT_STATUS);
    query.bindValue(":TYPE",TYPE);

    if(query.exec()){

        qDebug() << "Contract saved successfuly ." << "Data :" <<
                    "\nuser_id :" << USER_ID <<
                    "\nclient_id :" << CLIENT_ID <<
                    "\npremium_amount :" << PREMIUM_AMOUNT <<
                    "\neffective_date :" << EFFECTIVE_DATE.toString("yyyy-MM-dd") <<
                    "\nexpiration_date :" <<EXPIRATION_DATE.toString("yyyy-MM-dd") <<
                    "\npayment_status :" << PAYMENT_STATUS <<
                    "\ntype :" <<TYPE ;

    }else{
        qDebug() << "Error Creating Contract query:" << query.lastError().text();
        QMessageBox::critical(this, tr("Error"), query.lastError().text());
    }

}

// fonction supprimer
void contract::supprimer(int id){
    QSqlQuery query;
    query.prepare("DELETE FROM CONTRACTS WHERE CONTRACT_ID = :id ");
    query.bindValue(":id",id);

    if(query.exec()){

        if(query.next()){
            query.prepare("DELETE FROM CONTRACTS WHERE CONTRACT_ID = :id ");
            query.bindValue(":id",id);

                if(query.exec()){
                    qDebug() << "Contract found .Deleting process ...";
                }else{
                    qDebug() << "Error executing query:" << query.lastError().text();
                    QMessageBox::critical(this, tr("Error"), query.lastError().text());
                }
        }else{
            qDebug() << "Client not found.";
            return;
        }
    }else{
        qDebug() << "Error executing query:" << query.lastError().text();
        QMessageBox::critical(this, tr("Error"), query.lastError().text());
        return;
    }
}

//fonction lire
void contract::lire(){
    if(tableContract == nullptr){
        qDebug() << "Error : tableContract is null";
        return;
    }

    tableContract->clearContents();
    tableContract->setRowCount(0);

    QSqlQuery query ;
    query.prepare("SELECT * FROM CONTRACTS");
    if(query.exec()){
        while (query.next()) {
            int row = tableContract->rowCount();
            tableContract->insertRow(row);

            tableContract->setItem(row,0,new QTableWidgetItem(query.value(0).toInt()));
            tableContract->setItem(row,1,new QTableWidgetItem(query.value(1).toInt()));
            tableContract->setItem(row,2,new QTableWidgetItem(query.value(2).toInt()));
            tableContract->setItem(row,3,new QTableWidgetItem(query.value(3).toInt()));
            tableContract->setItem(row,4,new QTableWidgetItem(query.value(4).toDate().toString()));
            tableContract->setItem(row,5,new QTableWidgetItem(query.value(5).toDate().toString()));
            tableContract->setItem(row,6,new QTableWidgetItem(query.value(6).toInt()));
            tableContract->setItem(row,7,new QTableWidgetItem(query.value(7).toString()));
        }
        tableContract->repaint();
    }else{
        qDebug() << "Error executing query:" << query.lastError().text();
    }
}


//fonction modifier
void contract::modifier(int contractID, int USER_ID, int CLIENT_ID,int PREMIUM_AMOUNT, QDate EFFECTIVE_DATE, QDate EXPIRATION_DATE, int PAYMENT_STATUS, QString TYPE){
        QSqlQuery query ;
        query.prepare("SELECT * FROM CONTRACTS WHERE CONTRACT_ID = :id");
        query.bindValue(":id",contractID);

        if(query.exec()){
            if(query.next()){
                query.prepare("UPDATE CONTRACTS SET user_id = :USER_ID, client_id = :CLIENT_ID, premium_amount = :PREMIUM_AMOUNT, effective_date = :TO_DATE(:dob, 'YYYY-MM-DD'), expiration_date = :TO_DATE(:dob, 'YYYY-MM-DD'), payment_status = :PAYMENT_STATUS, type:TYPE WHERE CONTRACT_ID = :id");
                query.bindValue(":id",contractID);
                query.bindValue(":user_id",USER_ID);
                query.bindValue("client_id",CLIENT_ID);
                query.bindValue("premium_amount",PREMIUM_AMOUNT);
                query.bindValue("effective_date",EFFECTIVE_DATE);
                query.bindValue("expiration_date",EXPIRATION_DATE);
                query.bindValue("payment_status",PAYMENT_STATUS);
                query.bindValue("type",TYPE);

                if(query.exec())
                {
                    qDebug() << "Contract Updated successfuly ." << "Data :" <<
                              "\nuser_id :" << USER_ID <<
                              "\nclient_id :" <<CLIENT_ID<<
                              "\npremium_amount :" <<PREMIUM_AMOUNT<<
                              "\neffective_date :" <<EFFECTIVE_DATE.toString("yyyy-MM-dd") <<
                              "\nexpiration_date:" <<EXPIRATION_DATE.toString("yyyy-MM-dd")<<
                              "\npayment_status :" <<PAYMENT_STATUS<<
                              "\ntype :" <<TYPE ;
                }else{
                    qDebug() << "Error executing update query :" << query.lastError().text();
                    QMessageBox::critical(nullptr, tr("Error"), query.lastError().text());

               }
            }else{
                QMessageBox::critical(nullptr, tr("Error"), tr("contract not found"));
            }


        }else{
            qDebug() << "Error executing select query:" << query.lastError().text();
            QMessageBox::critical(nullptr, tr("Error"), query.lastError().text());
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


