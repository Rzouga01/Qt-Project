/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
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
    QSlider *themeSlider;
    QPlainTextEdit *dark_theme;
    QPlainTextEdit *light_theme;
    QPushButton *loginButton;
    QCheckBox *rememberMe;

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
"    background-color: #171717; /* Default dark background color */\n"
"}\n"
"\n"
"\n"
""));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        LoginPage = new QFrame(centralwidget);
        LoginPage->setObjectName("LoginPage");
        LoginPage->setGeometry(QRect(-11, 0, 1211, 650));
        LoginPage->setStyleSheet(QString::fromUtf8("#email, #password {\n"
"    border-radius: 25px;\n"
"    background-color: white;\n"
"    font-size: 30px;\n"
"    margin: 0 auto; \n"
"    color: #171717;\n"
"}\n"
"\n"
"#dark_theme,#light_theme{\n"
"border:none;\n"
"background-color:rgba(0, 0, 0, 0);\n"
"color:white;\n"
"}\n"
"QCheckBox {\n"
"    color: white; \n"
"}\n"
"\n"
"QCheckBox::indicator {\n"
"    background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(167, 195, 78, 255), stop:1 rgba(90, 143, 54, 255));\n"
"    border-radius: 10px;\n"
"}\n"
"\n"
"QCheckBox::indicator:checked {\n"
"    background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(167, 195, 78, 255), stop:1 rgba(90, 143, 54, 255));\n"
"    border: 2px solid white; \n"
"}\n"
"\n"
"QCheckBox::indicator:hover {\n"
"    background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(167, 195, 78, 255), stop:1 rgba(70, 123, 54, 255));\n"
"}\n"
"\n"
"\n"
"\n"
""));
        LoginPage->setFrameShape(QFrame::StyledPanel);
        LoginPage->setFrameShadow(QFrame::Raised);
        logo = new QLabel(LoginPage);
        logo->setObjectName("logo");
        logo->setGeometry(QRect(510, 20, 211, 201));
        logo->setPixmap(QPixmap(QString::fromUtf8("../Resources/Logo/icon ripple.png")));
        logo->setScaledContents(true);
        email = new QLineEdit(LoginPage);
        email->setObjectName("email");
        email->setGeometry(QRect(360, 330, 501, 70));
        QFont font;
        font.setFamilies({QString::fromUtf8("Open Sans")});
        email->setFont(font);
        password = new QLineEdit(LoginPage);
        password->setObjectName("password");
        password->setGeometry(QRect(360, 420, 501, 70));
        password->setFont(font);
        password->setEchoMode(QLineEdit::Password);
        themeSlider = new QSlider(LoginPage);
        themeSlider->setObjectName("themeSlider");
        themeSlider->setGeometry(QRect(80, 520, 111, 71));
        themeSlider->setMouseTracking(true);
        themeSlider->setStyleSheet(QString::fromUtf8(""));
        themeSlider->setMaximum(1);
        themeSlider->setOrientation(Qt::Horizontal);
        themeSlider->setInvertedControls(false);
        dark_theme = new QPlainTextEdit(LoginPage);
        dark_theme->setObjectName("dark_theme");
        dark_theme->setGeometry(QRect(70, 600, 71, 41));
        dark_theme->setReadOnly(true);
        light_theme = new QPlainTextEdit(LoginPage);
        light_theme->setObjectName("light_theme");
        light_theme->setGeometry(QRect(170, 600, 91, 61));
        light_theme->setReadOnly(true);
        loginButton = new QPushButton(LoginPage);
        loginButton->setObjectName("loginButton");
        loginButton->setGeometry(QRect(490, 550, 231, 41));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Open Sans")});
        font1.setPointSize(14);
        font1.setBold(false);
        loginButton->setFont(font1);
        loginButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"        background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(167, 195, 78, 255), stop:1 rgba(90, 143, 54, 255));\n"
"        border-radius: 10px;\n"
"        color: white;\n"
"     }\n"
"     QPushButton:hover {\n"
"        background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(167, 195, 78, 255), stop:1 rgba(70, 123, 54, 255));\n"
"     }\n"
"     "));
        rememberMe = new QCheckBox(LoginPage);
        rememberMe->setObjectName("rememberMe");
        rememberMe->setGeometry(QRect(420, 500, 301, 31));
        rememberMe->setFont(font);
        rememberMe->setTristate(true);
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Login Page", nullptr));
        logo->setText(QString());
        email->setPlaceholderText(QCoreApplication::translate("MainWindow", "Email", nullptr));
        password->setPlaceholderText(QCoreApplication::translate("MainWindow", "Password", nullptr));
        dark_theme->setPlainText(QCoreApplication::translate("MainWindow", "Dark\n"
"", nullptr));
        light_theme->setPlainText(QCoreApplication::translate("MainWindow", "Light\n"
"", nullptr));
        loginButton->setText(QCoreApplication::translate("MainWindow", "Login", nullptr));
        rememberMe->setText(QCoreApplication::translate("MainWindow", "Remember me", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
