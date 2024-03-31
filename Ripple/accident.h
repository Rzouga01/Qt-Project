#ifndef ACCIDENT_H
#define ACCIDENT_H
#include<QString>
#include<QSqlQuery>
#include<QDate>
#include<QSqlQueryModel>
#include <QDialog>
#include <QTableWidget>
#include <QStackedWidget>
#include <QtCore>
#include <QtWidgets>
#include <QtGui>
#include <QChart>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QValueAxis>
#include <QtCharts/QChart>


namespace Ui {
class accident;
}

class accident : public QDialog
{
    Q_OBJECT
private:
    int damage;
    QString type;
    QString location;
    QDate date;
    int acc_id;
    int client_id;

public:
    explicit accident(QWidget *parent = nullptr);
    explicit accident(QTableWidget*tablewidget,QWidget *parent = nullptr);

    // CONSTRUCTEUR

    ~accident();
    accident();
    accident(QString type  ,int damage ,QDate date,QString location,int client_id  );

    //GETTERS

    int getAcc_id(){return acc_id;}
    QString getType(){return type;}
    int getDamage(){return damage;}
    QDate getDate(){return date;}
    QString getLocation(){return location;}
    int getClient_id(){return client_id;}

    // SETTERS
    void setAcc_id(int ac_id){acc_id=ac_id;}
    void setType(QString T){type=T;}
    void setDamage(int DA){damage = DA;}
    void setDate(QDate D){date = D;}
    void setLocation(QString L){location = L;}
    void setClient_id(int c_id){client_id=c_id;}



    // FONCTIONALITES DE BASE

    bool create(QString type  ,int damage ,QDate date,QString location,int client_id );
    void accidentRead();
    void update( int acc_id,QString type,int damage,QDate date,QString location,int client_id);
    bool Delete(int);
    void setTableWidget(QTableWidget *tableWidget);
    void setStackedWidget(QStackedWidget *stackedWidget);
    void accidentstatsByDamage();
    void searchAccident(const QString& search);
    void AccidenttoPdf(const QString& filePath);
    void sortAccidentByDamage(bool ascendingOrder);
    QSqlQuery rechercherall();
signals:
    void deleteAccidentRequested(int Acc_id);
    void updateAccidentRequested(int Acc_id);


private:
    Ui::accident *ui;
    QTableWidget * tableAccident;

};


#endif // ACCIDENT_H
