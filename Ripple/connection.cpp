#include "connection.h"
#include <QtDebug>

Connection::Connection()
{

}

bool Connection::createconnect() {
    bool test = false;
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
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
