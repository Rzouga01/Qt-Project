#include "mainwindow.h"
#include <QApplication>
#include "client.h"
#include "employee.h"
#include "contract.h"
#include "accident.h"
#include "connection.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    Client c;
    Employee e;
    contract ct;
    accident ac;

    e.show();
    ac.show();
    ct.show();
    c.show();
    w.show();


    return a.exec();
}
