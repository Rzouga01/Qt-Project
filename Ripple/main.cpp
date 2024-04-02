#include "mainwindow.h"
#include <QApplication>
#include <QtWidgets>
#include <QUiLoader>


#include "connection.h"




int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setWindowIcon(QIcon("../Resources/Logo/icon ripple.png"));

    MainWindow w;
    Connection con;

    if (con.createconnect()) {
        w.show();
    }

    return a.exec();
}
