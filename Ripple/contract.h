#ifndef CONTRACT_H
#define CONTRACT_H
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDialog>
#include <QDate>
#include <QTableWidget>
#include <QStackedWidget>

namespace Ui {
    class contract;
}

class contract : public QDialog
{
    Q_OBJECT
private:
    int CONTRACT_ID;
    int USER_ID;
    int CLIENT_ID;
    int PREMIUM_AMOUNT;
    QDate EFFECTIVE_DATE;
    QDate EXPIRATION_DATE;
    int PAYMENT_STATUS;
    QString TYPE;



public:
    explicit contract(QWidget* parent = nullptr);
    explicit contract(QTableWidget* tableWidget, QStackedWidget* stackedWidget, QWidget* parent = nullptr);
    ~contract();
    //Constructeurs
    contract();
    contract(const int USER_ID, const int CLIENT_ID, const int PREMIUM_AMOUNT, const QDate EFFECTIVE_DATE, const QDate EXPIRATION_DATE, const int PAYMENT_STATUS, const QString TYPE);





    //Getters
    int getCONTRACT_ID() { return CONTRACT_ID; }
    int getUSER_ID() { return USER_ID; }
    int getCLIENT_ID() { return CLIENT_ID; }
    int getPREMIUM_AMOUNT() { return PREMIUM_AMOUNT; }
    QDate getEFFECTIVE_DATE() { return EFFECTIVE_DATE; }
    QDate getEXPIRATION_DATE() { return EXPIRATION_DATE; }
    int getPAYMENT_STATUS() { return PAYMENT_STATUS; }
    QString getTYPE() { return TYPE; }

    //Setters
    void setCONTRACT_ID(int CONTRACT_ID) { this->CONTRACT_ID = CONTRACT_ID; }
    void setUSER_ID(int USER_ID) { this->USER_ID = USER_ID; }
    void setCLIENT_ID(int CLIENT_ID) { this->CLIENT_ID = CLIENT_ID; }
    void setPREMIUM_AMOUNT(int PREMIUM_AMOUNT) { this->PREMIUM_AMOUNT = PREMIUM_AMOUNT; }
    void setEFFECTIVE_DATE(QDate EFFECTIVE_DATE) { this->EFFECTIVE_DATE = EFFECTIVE_DATE; }
    void setEXPIRATION_DATE(QDate EXPIRATION_DATE) { this->EXPIRATION_DATE = EXPIRATION_DATE; }
    void setPAYMENT_STATUS(int PAYMENT_STATUS) { this->PAYMENT_STATUS = PAYMENT_STATUS; }
    void setTYPE(QString T) { TYPE = T; }

    //Fonctionnalités de Base relatives a l'entités contrat
    bool CreateContract(int USER_ID, int CLIENT_ID, int PREMIUM_AMOUNT, QDate EFFECTIVE_DATE, QDate EXPIRATION_DATE, int PAYMENT_STATUS, QString TYPE);
    bool DeleteContract(int id);
    void ReadContract();
    bool UpdateContract(int contractID, int USER_ID, int CLIENT_ID, int PREMIUM_AMOUNT, QDate EFFECTIVE_DATE, QDate EXPIRATION_DATE, int PAYMENT_STATUS, QString TYPE);
    void sortContractsByPremium(bool ascendingOrder);
    void searchContract(QString id);
    void toPdf(const QString& filePath);
    void statsByPremiumAmount();
    void exportToExcel(int clientId, const QString& filePath);
    void notifyContractExpiration(const QDate& expirationDate);

    void setTableWidget(QTableWidget* tableWidget);
    void setStackedWidget(QStackedWidget* stackedWidget);

signals:
    void deleteContractRequested(int contractId);
    void updateContractRequested(int contractId);





private:
    Ui::contract* ui;
    QTableWidget* tableContract;
    QStackedWidget* stackedContract;

};

#endif // CONTRACT_H
