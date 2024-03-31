/********************************************************************************
** Form generated from reading UI file 'client.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
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
    QLineEdit *role;
    QLabel *logo;
    QTextEdit *helloBar;
    QFrame *addFeatureEmployee;
    QFrame *statsEmployee;
    QListWidget *readBoxEmployee;
    QFrame *featureBarEmployee;
    QLineEdit *searchBarEmployee;

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
"*{font: \"Helvetica\" bold;\n"
"}\n"
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
"\n"
"\n"
"\n"
"#stackedWidget{\n"
"background-color:#171717;\n"
"\n"
"}\n"
""));
        frame = new QFrame(Client);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(0, 0, 1200, 650));
        frame->setStyleSheet(QString::fromUtf8("#featureBarClient,#featureBarEmployee{\n"
"background-color:white;\n"
"border-radius:25px;\n"
"}\n"
"#addFeatureClient,#addFeatureEmployee{\n"
"background-color:#A7C34E;\n"
"border-radius:25px;\n"
"}\n"
"\n"
"#statsClient,#statsEmployee{\n"
"background-color:#A7C34E;\n"
"border-radius:25px;\n"
"}\n"
"\n"
"#readBoxClient,#readBoxEmployee{\n"
"border:none;\n"
"background-color:#A7C34E;\n"
"border-radius:25px;\n"
"\n"
"}\n"
"\n"
"#searchBarClient,#searchBarEmployee{\n"
"background-color:white;\n"
"\n"
"}\n"
"\n"
""));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        role = new QLineEdit(frame);
        role->setObjectName("role");
        role->setGeometry(QRect(880, 30, 281, 91));
        role->setCursor(QCursor(Qt::ArrowCursor));
        role->setReadOnly(true);
        logo = new QLabel(frame);
        logo->setObjectName("logo");
        logo->setGeometry(QRect(20, 20, 111, 101));
        logo->setPixmap(QPixmap(QString::fromUtf8("../Resources/Logo/icon ripple.png")));
        logo->setScaledContents(true);
        helloBar = new QTextEdit(frame);
        helloBar->setObjectName("helloBar");
        helloBar->setGeometry(QRect(140, 30, 311, 91));
        helloBar->setTextInteractionFlags(Qt::NoTextInteraction);
        addFeatureEmployee = new QFrame(frame);
        addFeatureEmployee->setObjectName("addFeatureEmployee");
        addFeatureEmployee->setGeometry(QRect(20, 149, 601, 231));
        addFeatureEmployee->setFrameShape(QFrame::StyledPanel);
        addFeatureEmployee->setFrameShadow(QFrame::Raised);
        statsEmployee = new QFrame(frame);
        statsEmployee->setObjectName("statsEmployee");
        statsEmployee->setGeometry(QRect(20, 400, 601, 231));
        statsEmployee->setFrameShape(QFrame::StyledPanel);
        statsEmployee->setFrameShadow(QFrame::Raised);
        readBoxEmployee = new QListWidget(frame);
        readBoxEmployee->setObjectName("readBoxEmployee");
        readBoxEmployee->setGeometry(QRect(640, 220, 541, 411));
        featureBarEmployee = new QFrame(frame);
        featureBarEmployee->setObjectName("featureBarEmployee");
        featureBarEmployee->setGeometry(QRect(640, 150, 541, 61));
        featureBarEmployee->setStyleSheet(QString::fromUtf8(""));
        featureBarEmployee->setFrameShape(QFrame::StyledPanel);
        featureBarEmployee->setFrameShadow(QFrame::Raised);
        searchBarEmployee = new QLineEdit(frame);
        searchBarEmployee->setObjectName("searchBarEmployee");
        searchBarEmployee->setGeometry(QRect(910, 260, 241, 41));
        searchBarEmployee->setStyleSheet(QString::fromUtf8("#searchBar{\n"
"border-radius:10px;\n"
"}"));
        searchBarEmployee->setClearButtonEnabled(true);

        retranslateUi(Client);

        QMetaObject::connectSlotsByName(Client);
    } // setupUi

    void retranslateUi(QDialog *Client)
    {
        Client->setWindowTitle(QCoreApplication::translate("Client", "Client Manager", nullptr));
        role->setPlaceholderText(QCoreApplication::translate("Client", "Role", nullptr));
        logo->setText(QString());
        helloBar->setPlaceholderText(QCoreApplication::translate("Client", "Hello,                    First Name Last Name", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Client: public Ui_Client {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENT_H
