#include "accident.h"
#include "ui_accident.h"
#include <QMessageBox>
#include <QtDebug>
#include <QDate>
#include <QSqlQuery>
#include <QTableWidgetItem>
#include <QTableWidget>
#include <QSqlError>




accident::accident(QWidget* parent) :
    QDialog(parent),
    ui(new Ui::accident),
    tableAccident(nullptr)
{

    ui->setupUi(this);


}
accident::accident(QTableWidget* tablewidget, QWidget* parent) :
    QDialog(parent), ui(new Ui::accident), tableAccident(tablewidget) {
    ui->setupUi(this);
}


void accident::setTableWidget(QTableWidget* tableWidget)

{
    tableAccident = tableWidget;
}

accident::~accident()
{
    delete ui;
}

accident::accident()
{
    acc_id = -1;
    type = "";
    damage = 0;
    date = QDate::currentDate();
    location = "";
    client_id = -1;


}

accident::accident(QString type, int damage, QDate date, QString location, int client_id)
{

    this->type = type;
    this->damage = damage;
    this->date = date;
    this->location = location;
    this->client_id = client_id;
}

bool accident::create(QString type, int damage, QDate date, QString location, int client_id)
{
    QSqlQuery query;

    query.prepare("INSERT INTO ACCIDENTS (TYPE,DAMAGE,ACCIDENT_DATE,LOCATION,CLIENT_ID) VALUES (:type, :damage,:date,:location,:client_id)");

    query.bindValue(":type", type);
    query.bindValue(":damage", damage);
    query.bindValue(":date", date);
    query.bindValue(":location", location);
    query.bindValue(":client_id", client_id);

    if (query.exec())
    {

        qDebug() << "Accident saved successfully." << "Data:" <<
            "\ntype :" << type <<
            "\ndamage :" << damage <<
            "\ndate :" << date.toString("yyyy-MM-dd") <<
            "\nlocation :" << location <<
            "\nclient_id :" << client_id;

        return true;
    }
    else
    {
        qDebug() << "Error Creating Accident query:" << query.lastError().text();
        QMessageBox::critical(this, tr("Error"), query.lastError().text());
        return false;
    }
}

/*
 QSqlQueryModel* accident::read()
{

  QSqlQueryModel* model=new QSqlQueryModel();

   model->setQuery("SELECT * FROM ACCIDENTS");

  return  model;
}*/

void accident::accidentRead()
{
    if (tableAccident == nullptr) {
        qDebug() << "Error: tableClient is null";
        return;
    }

    tableAccident->clearContents();
    tableAccident->setRowCount(0);

    QSqlQuery qry;
    qry.prepare("SELECT * FROM ACCIDENTS");
    if (qry.exec())
    {
        while (qry.next())
        {
            int row = tableAccident->rowCount();
            tableAccident->insertRow(row);

            tableAccident->setItem(row, 0, new QTableWidgetItem(qry.value(0).toString()));
            tableAccident->setItem(row, 1, new QTableWidgetItem(qry.value(1).toString()));
            tableAccident->setItem(row, 2, new QTableWidgetItem(qry.value(2).toString()));
            tableAccident->setItem(row, 3, new QTableWidgetItem(qry.value(3).toString()));
            tableAccident->setItem(row, 4, new QTableWidgetItem(qry.value(4).toString()));
            tableAccident->setItem(row, 5, new QTableWidgetItem(qry.value(5).toString()));
            tableAccident->setItem(row, 6, new QTableWidgetItem(qry.value(6).toDate().toString()));
        }
        tableAccident->repaint();
    }
    else
    {
        qDebug() << "Error executing query:" << qry.lastError().text();
    }
}


bool accident::Delete(int id) {
    QSqlQuery qry;
    qry.prepare("DELETE FROM ACCIDENTS WHERE ACCIDENT_ID = :acc_id");
    qry.bindValue(":acc_id", id);

    if (qry.exec()) {
        if (qry.numRowsAffected() > 0) {
            qDebug() << "Accident found and deleted.";
            return true;
        }
        else {
            qDebug() << "Accident not found.";
            return false;
        }
    }
    else {
        qDebug() << "Error executing query:" << qry.lastError().text();
        return false;
    }
}

void accident::update(int acc_id, QString type, int damage, QDate date, QString location, int client_id) {
    QSqlQuery query;
    query.prepare("SELECT * FROM ACCIDENTS WHERE ACCIDENT_ID = :acc_id");
    query.bindValue(":acc_id", acc_id);

    if (query.exec()) {
        qDebug() << "test";
        if (query.next()) {
            query.prepare("UPDATE ACCIDENTS SET TYPE=:type,DAMAGE=:damage,ACCIDENT_DATE=:date,LOCATION=:location,CLIENT_ID=:client_id WHERE ACCIDENT_ID=:acc_id");
            query.bindValue(":acc_id", acc_id);
            query.bindValue(":type", type);
            query.bindValue(":damage", damage);
            query.bindValue(":date", date);
            query.bindValue(":location", location);
            query.bindValue(":client_id", client_id);

            if (query.exec())
            {
                qDebug() << "Contract Updated successfuly ." << "Data :" <<
                    "\nacc_id :" << acc_id <<
                    "\ntype :" << type <<
                    "\ndamage :" << damage <<
                    "\ndate :" << date.toString("yyyy-MM-dd") <<
                    "\nlocation :" << location <<
                    "\nclient_id :" << client_id;

            }
            else {
                qDebug() << "Error executing update query :" << query.lastError().text();
                QMessageBox::critical(nullptr, tr("Error"), query.lastError().text());

            }
        }
        else {
            QMessageBox::critical(nullptr, tr("Error"), tr("accident not found"));
        }


    }
    else {
        qDebug() << "Error executing select query:" << query.lastError().text();
        QMessageBox::critical(nullptr, tr("Error"), query.lastError().text());
    }
    /*  qDebug() << "Contract Updated successfuly ." << "Data :" <<
                "\nacc_id :" << acc_id <<
                  "\ntype :" <<type <<
               "\ndamage :" <<damage<<
                "\ndate :" <<date.toString("yyyy-MM-dd") <<
                "\nlocation :" <<location<<
                  "\nclient_id :" <<client_id;
      QSqlQuery query ;
      query.prepare("UPDATE ACCIDENTS SET TYPE=:type, DAMAGE =:damage,ACCIDENT_DATE= :accident_date,LOCATION= :location, CLIENT_ID= :client_id WHERE ACCIDENT_ID= :id");
      query.bindValue(":id",acc_id);
      query.bindValue(":type",type);
      query.bindValue(":damage",damage);
      query.bindValue(":accident_date",date.toString("yyyy-MM-dd"));
      query.bindValue(":location",location);
      query.bindValue(":client_id",client_id);
      query.exec();*/
}


