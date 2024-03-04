#include "contract.h"
#include "ui_contract.h"
#include <QtDebug>
#include <QDate>
#include <QMessageBox>
#include <QSqlError>
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
bool contract::ajouter(){
    QSqlQuery query;


    //prepare() prend la requete en paramétre pour la préparer a l'exécution.
    query.prepare("INSERT INTO CONTRACTS(USER_ID,CLIENT_ID,PREMIUM_AMOUNT,EFFECTIVE_DATE,EXPIRATION_DATE,PAYMENT_STATUS,TYPE) values( :USER_ID, :CLIENT_ID, :PREMIUM_AMOUNT, :EFFECTIVE_DATE, :EXPIRATION_DATE, :PAYMENT_STATUS, :TYPE)");

    //création des variables liées
    query.bindValue(":USER_ID",USER_ID);
    query.bindValue(":CLIENT_ID",CLIENT_ID);
    query.bindValue(":PREMIUM_AMOUNT",PREMIUM_AMOUNT);
    query.bindValue(":EFFECTIVE_DATE",EFFECTIVE_DATE);
    query.bindValue(":EXPIRATION_DATE",EXPIRATION_DATE);
    query.bindValue(":PAYMENT_STATUS",PAYMENT_STATUS);
    query.bindValue(":TYPE",TYPE);

    //exec() envoie la requete pour l'executer
    return query.exec();

}


//fonction supprimer
bool contract:: supprimer(int id){
    QSqlQuery query;
    query.prepare("DELETE FROM CONTRACTS WHERE CONTRACT_ID = :id ");
    query.bindValue(":id",id);
    return query.exec();
}

//fonction lire
void contract::lire(){
    QSqlQuery query;
    query.prepare("SELECT * FROM CONTRACTS");
    if(query.exec())
    {
        while (query.next())
        {
            qDebug() << "Contract ID :"<<query.value(0).toInt() <<"\nUser ID :"<<query.value(1).toInt() <<"\nClient ID :"<<query.value(2).toInt() <<"\nPremium Amount :"<<query.value(3).toInt() <<"\nEffective Date :"<<query.value(4).toDate() <<"\nExpiration Date :"<<query.value(5).toDate() <<"\nPayment Status :"<<query.value(6).toInt()<<"\nType :"<<query.value(7).toString();
            qDebug() << "---------------------------------------";
        }
    }
    else
    {
            qDebug() << "Error executing query:" << query.lastError().text();
    }
}




contract::contract(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::contract)
{
    ui->setupUi(this);
}

contract::~contract()
{
    delete ui;
}
