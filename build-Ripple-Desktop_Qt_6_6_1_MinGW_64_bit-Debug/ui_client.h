/********************************************************************************
** Form generated from reading UI file 'client.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLIENT_H
#define UI_CLIENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_Client
{
public:
    QFrame *frame;
    QLabel *label;
    QLineEdit *role;
    QTextEdit *helloBar;
    QListWidget *readBox;
    QLineEdit *searchBar;
    QLabel *searchIcon;

    void setupUi(QDialog *Client)
    {
        if (Client->objectName().isEmpty())
            Client->setObjectName("Client");
        Client->resize(1200, 650);
        Client->setStyleSheet(QString::fromUtf8("#Client{\n"
"background-color:#171717;\n"
"\n"
"}\n"
"\n"
"\n"
"#helloBar{\n"
"border: none;\n"
"background-color:#171717;\n"
"font-size:30px;\n"
"color:white;\n"
"\n"
"\n"
"}\n"
"\n"
"#role{\n"
"font-size:30px;\n"
"background-color:#171717;\n"
"color:white;\n"
"border:none;\n"
"}\n"
"\n"
"\n"
"#readBox{\n"
"border:none;\n"
"background-color:#A7C34E;\n"
"border-radius:25px;\n"
"\n"
"}\n"
"\n"
"#searchBar{\n"
"background-color:white;\n"
"\n"
"}\n"
""));
        frame = new QFrame(Client);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(0, 0, 1200, 650));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        label = new QLabel(frame);
        label->setObjectName("label");
        label->setGeometry(QRect(40, 30, 111, 101));
        label->setPixmap(QPixmap(QString::fromUtf8("../Resources/Logo/icon ripple.png")));
        label->setScaledContents(true);
        role = new QLineEdit(frame);
        role->setObjectName("role");
        role->setGeometry(QRect(910, 40, 161, 71));
        role->setReadOnly(true);
        helloBar = new QTextEdit(frame);
        helloBar->setObjectName("helloBar");
        helloBar->setGeometry(QRect(150, 40, 221, 91));
        readBox = new QListWidget(frame);
        readBox->setObjectName("readBox");
        readBox->setGeometry(QRect(520, 220, 641, 381));
        searchBar = new QLineEdit(frame);
        searchBar->setObjectName("searchBar");
        searchBar->setGeometry(QRect(710, 240, 391, 51));
        searchIcon = new QLabel(frame);
        searchIcon->setObjectName("searchIcon");
        searchIcon->setGeometry(QRect(560, 260, 71, 21));

        retranslateUi(Client);

        QMetaObject::connectSlotsByName(Client);
    } // setupUi

    void retranslateUi(QDialog *Client)
    {
        Client->setWindowTitle(QCoreApplication::translate("Client", "Dialog", nullptr));
        label->setText(QString());
        role->setPlaceholderText(QCoreApplication::translate("Client", "Role", nullptr));
        searchIcon->setText(QCoreApplication::translate("Client", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Client: public Ui_Client {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENT_H
