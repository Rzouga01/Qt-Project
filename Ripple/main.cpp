#include "mainwindow.h"
#include <QApplication>
#include "client.h"
#include "employee.h"
#include "accident.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    Client c;
    Employee e;
    accident ac;
    e.show();
    c.show();
    ac.show();
    w.show();


    return a.exec();
}
