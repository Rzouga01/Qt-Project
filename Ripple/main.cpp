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
#include "mailer.h"




int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setWindowIcon(QIcon("../Resources/Logo/icon ripple.png"));

    MainWindow w;
    Connection con;
    Dashboard dash;



   



  w.show();


    return a.exec();
}
