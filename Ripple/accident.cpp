#include "accident.h"
#include "ui_accident.h"



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

bool accident::create()
{
QSqlQuery query;

query.prepare("INSERT INTO ACCIDENTS (TYPE,DAMAGE,ACCIDENT_DATE,LOCATION,CLIENT_ID) VALUES (:type, :damage,:date,:location,:client_id)");

query.bindValue(":type",type);
query.bindValue(":damage",damage );
query.bindValue(":date",date );
query.bindValue(":location", location );
query.bindValue(":client_id", client_id);

  return query.exec();
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


