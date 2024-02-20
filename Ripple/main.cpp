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
    Client c;
    Employee e;
    contract ct;
    accident ac;
    Connection con;
    Dashboard dash;


    con.createconnect();


    w.show();
    dash.show();


    return a.exec();
}
