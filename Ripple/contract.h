#ifndef CONTRACT_H
#define CONTRACT_H
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDialog>
#include <QDate>

namespace Ui {
class contract;
}

class contract : public QDialog
{
    Q_OBJECT
    int CONTRACT_ID;
    int USER_ID;
    int CLIENT_ID;
    int PREMIUM_AMOUNT;
    QDate EFFECTIVE_DATE;
    QDate EXPIRATION_DATE;
    int PAYMENT_STATUS;
    QString TYPE;

public:
    explicit contract(QWidget *parent = nullptr);
    ~contract();
    //Constructeurs
    contract();
    contract(int,int,int,QDate,QDate,int,QString );

   //Getters
    int getCONTRACT_ID(){return CONTRACT_ID;}
    int getUSER_ID(){return USER_ID;}
    int getCLIENT_ID(){return CLIENT_ID;}
    int getPREMIUM_AMOUNT(){return PREMIUM_AMOUNT;}
    QDate getEFFECTIVE_DATE(){return EFFECTIVE_DATE;}
    QDate getEXPIRATION_DATE(){return EXPIRATION_DATE;}
    int getPAYMENT_STATUS(){return PAYMENT_STATUS;}
    QString getTYPE(){return TYPE;}

    //Setters
    void setCONTRACT_ID(int CONTRACT_ID ){this -> CONTRACT_ID = CONTRACT_ID;}
    void setUSER_ID(int USER_ID){this->USER_ID = USER_ID;}
    void setCLIENT_ID(int CLIENT_ID){this->CLIENT_ID = CLIENT_ID;}
    void setPREMIUM_AMOUNT(int PREMIUM_AMOUNT){this->PREMIUM_AMOUNT=PREMIUM_AMOUNT;}
    void setEFFECTIVE_DATE(QDate EFFECTIVE_DATE){this->EFFECTIVE_DATE = EFFECTIVE_DATE;}
    void setEXPIRATION_DATE(QDate EXPIRATION_DATE){this->EXPIRATION_DATE = EXPIRATION_DATE;}
    void setPAYMENT_STATUS(int PAYMENT_STATUS){this->PAYMENT_STATUS=PAYMENT_STATUS;}
    void setTYPE(QString T){TYPE=T;}

    //Fonctionnalités de Base relatives a l'entités contrat
    bool ajouter();
    bool supprimer();
    bool lire();
    bool modifier();




private:
    Ui::contract *ui;
};

#endif // CONTRACT_H
