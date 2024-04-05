#ifndef SQLCONN_H
#define SQLCONN_H
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

class sqlConn
{
    QSqlDatabase db;
public:
    sqlConn();
    bool createconnect();
    void closeconnect();
};

#endif // SQLCONN_H
