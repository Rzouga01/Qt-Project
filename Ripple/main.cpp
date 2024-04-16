#include "mainwindow.h"
#include <QApplication>
#include <QtWidgets>
#include <QUiLoader>

#include "chatbot.h"
#include "sqlConn.h"




int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setWindowIcon(QIcon("../Resources/Logo/icon ripple.png"));

    MainWindow w;
    sqlConn con;
    chatbot bot;
    

    if (con.createconnect()) {
        //w.show();
        bot.show();
    }

    return a.exec();
}
