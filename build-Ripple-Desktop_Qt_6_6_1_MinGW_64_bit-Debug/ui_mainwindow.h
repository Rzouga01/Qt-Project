/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QFrame *LoginPage;
    QLabel *logo;
    QLineEdit *email;
    QLineEdit *password;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1200, 650);
        MainWindow->setStyleSheet(QString::fromUtf8("#MainWindow {\n"
"    /* Add any styles for MainWindow if needed */\n"
"}\n"
"\n"
"#LoginPage {\n"
"    background-color: #171717;\n"
"    display: block;\n"
"    text-align: center;\n"
"  \n"
"}\n"
"\n"
"#email, #password {\n"
"    border-radius: 25px;\n"
"    background-color: white;\n"
"    font-size: 30px;\n"
"    margin: 0 auto; \n"
"    display: block; \n"
"color:#171717;\n"
"\n"
"\n"
"}"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        LoginPage = new QFrame(centralwidget);
        LoginPage->setObjectName("LoginPage");
        LoginPage->setGeometry(QRect(0, 0, 1200, 650));
        LoginPage->setFrameShape(QFrame::StyledPanel);
        LoginPage->setFrameShadow(QFrame::Raised);
        logo = new QLabel(LoginPage);
        logo->setObjectName("logo");
        logo->setGeometry(QRect(490, 30, 241, 231));
        logo->setPixmap(QPixmap(QString::fromUtf8("../Resources/Logo/icon ripple.png")));
        logo->setScaledContents(true);
        email = new QLineEdit(LoginPage);
        email->setObjectName("email");
        email->setGeometry(QRect(360, 330, 501, 70));
        password = new QLineEdit(LoginPage);
        password->setObjectName("password");
        password->setGeometry(QRect(360, 440, 501, 70));
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        logo->setText(QString());
        email->setPlaceholderText(QCoreApplication::translate("MainWindow", "Email", nullptr));
        password->setPlaceholderText(QCoreApplication::translate("MainWindow", "Password", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
