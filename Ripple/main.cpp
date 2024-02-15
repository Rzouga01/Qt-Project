#include "mainwindow.h"
#include <QApplication>
#include "client.h"
#include "employee.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    Client c;
    Employee e;
    e.show();
    c.show();
    w.show();


    return a.exec();
}
