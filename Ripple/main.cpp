#include "mainwindow.h"
#include <QApplication>
#include <QtWidgets>
#include <QUiLoader>

#include "chatbot.h"
#include "connection.h"




int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setWindowIcon(QIcon("../Resources/Logo/icon ripple.png"));

    MainWindow w;
    Connection con;
    chatbot c;
    

    if (con.createconnect()) {
        w.show();
        //c.show();
    }

    return a.exec();
}
