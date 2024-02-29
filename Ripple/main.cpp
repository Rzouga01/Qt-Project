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
    Client c("email", "first_name", "last_name", "12345678", "adress", QDate::currentDate());
    Employee e;
    contract ct;
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
