#include "mainwindow.h"
#include <QApplication>
#include <QtWidgets>
#include <QUiLoader>

#include "client.h"
#include "employee.h"
#include "contract.h"
#include "accident.h"
#include "connection.h"
#include "dashboard.h"




int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;
    Client c("email", "first_name", "last_name", "12345678", "address", QDate::currentDate());
    Employee e("email", "password", 0, "first_name", "last_name", "12345678", "address", QDate::currentDate());
    contract ct(1,1,100,QDate::currentDate(),QDate::currentDate(),0,"test");
    accident ac;
    Connection con;
    Dashboard dash;


    if(!con.createconnect())
    {
        qDebug() << "Not Connected";
    }
    else
    {
        dash.show();
    };
    return a.exec();
}
