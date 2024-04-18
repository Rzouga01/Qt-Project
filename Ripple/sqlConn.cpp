#include "sqlConn.h"
#include <QtDebug>

sqlConn::sqlConn()
{

}

bool sqlConn::createconnect() {
    bool test = false;
    db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("ripple");
    db.setUserName("ripple");
    db.setPassword("ripple");

    if (db.open()) {
        qDebug() << "Database connected successfully.";
        test = true;
    } else {
        qDebug() << "Error connecting to database:" << db.lastError().text();
    }

    return test;
}

void sqlConn::closeconnect() {
    db.close();
}


