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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Client
{
public:
    QHBoxLayout *horizontalLayout;
    QWidget *leftMenu;
    QPushButton *pushButton;
    QWidget *mainMenu;

    void setupUi(QDialog *Client)
    {
        if (Client->objectName().isEmpty())
            Client->setObjectName("Client");
        Client->resize(650, 450);
        Client->setStyleSheet(QString::fromUtf8("*{\n"
"background-color:black\n"
"\n"
"}\n"
"\n"
"\n"
"#leftMenu{\n"
"background-color:#89b54c;\n"
"}\n"
"\n"
"#mainMenu {\n"
"background-color:#000000;\n"
"}"));
        horizontalLayout = new QHBoxLayout(Client);
        horizontalLayout->setObjectName("horizontalLayout");
        leftMenu = new QWidget(Client);
        leftMenu->setObjectName("leftMenu");
        pushButton = new QPushButton(leftMenu);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(40, 30, 80, 24));

        horizontalLayout->addWidget(leftMenu);

        mainMenu = new QWidget(Client);
        mainMenu->setObjectName("mainMenu");

        horizontalLayout->addWidget(mainMenu);


        retranslateUi(Client);

        QMetaObject::connectSlotsByName(Client);
    } // setupUi

    void retranslateUi(QDialog *Client)
    {
        Client->setWindowTitle(QCoreApplication::translate("Client", "Dialog", nullptr));
        pushButton->setText(QCoreApplication::translate("Client", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Client: public Ui_Client {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENT_H
