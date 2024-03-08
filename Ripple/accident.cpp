#include "accident.h"
#include "ui_accident.h"
#include <QMessageBox>
#include <QtDebug>
#include <QDate>
#include <QSqlQuery>
#include <QTableWidgetItem>
#include <QTableWidget>
#include <QSqlError>




accident::accident(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::accident)
{

    ui->setupUi(this);

}

accident::~accident()
{
    delete ui;
}

accident::accident()
{
acc_id=-1;
type="";
damage=0;
date=QDate::currentDate();
location ="";
client_id=-1;


}

accident::accident(QString type  ,int damage ,QDate date,QString location,int client_id  )
{

    this->type=type;
    this-> damage=damage;
    this->date=date;
    this->location=location;
    this->client_id=client_id;
}

bool accident::create(QString type  ,int damage ,QDate date,QString location,int client_id )
{
QSqlQuery query;

query.prepare("INSERT INTO ACCIDENTS (TYPE,DAMAGE,ACCIDENT_DATE,LOCATION,CLIENT_ID) VALUES (:type, :damage,:date,:location,:client_id)");

query.bindValue(":type",type);
query.bindValue(":damage",damage );
query.bindValue(":date",date );
query.bindValue(":location", location );
query.bindValue(":client_id", client_id);

if (query.exec())
{

    qDebug() << "Accident saved successfully." << "Data:" <<
                "\ntype :" << type <<
                "\ndamage :" << damage <<
                "\ndate :" << date.toString("yyyy-MM-dd") <<
                "\nlocation :" << location <<
                 "\nclient_id :" << client_id ;

    return true;
}
else
{
    qDebug() << "Error Creating Accident query:" << query.lastError().text();
    QMessageBox::critical(this, tr("Error"), query.lastError().text());
    return false;
}
}


QSqlQueryModel* accident::read()
{

  QSqlQueryModel* model=new QSqlQueryModel();

   model->setQuery("SELECT * FROM ACCIDENTS");




  return  model;
}
bool accident::Delete(int id)
    {
        QSqlQuery query;
              query.prepare("delete from ACCIDENTS where ACCIDENT_ID=:acc_id");
              query.bindValue(":acc_id", id);
              return query.exec();
    }


