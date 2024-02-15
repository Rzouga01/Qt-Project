#include "mainwindow.h"
#include <QApplication>
#include "client.h"
#include "employee.h"
#include "contract.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    Client c;
    Employee e;
    contract ct;
    e.show();
    c.show();
    ct.show();
    w.show();


    return a.exec();
}
