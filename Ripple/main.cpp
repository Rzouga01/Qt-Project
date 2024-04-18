#include "mainwindow.h"
#include <QApplication>
#include <QtWidgets>
#include <QUiLoader>
#include "map.h"
#include "chatbot.h"
#include "sqlConn.h"




int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setWindowIcon(QIcon("../Resources/Logo/icon ripple.png"));
    map p;
    MainWindow w;
    sqlConn con;
    chatbot bot;
    

    if (con.createconnect()) {
        w.show();
        p.show();
        //bot.show();
    }

    return a.exec();
}
