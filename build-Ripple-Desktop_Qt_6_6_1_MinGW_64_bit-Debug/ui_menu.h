/********************************************************************************
** Form generated from reading UI file 'menu.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MENU_H
#define UI_MENU_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Menu
{
public:
    QFrame *frame;
    QFrame *sideMenuFrame;
    QPushButton *logoutButton;

    void setupUi(QDialog *Menu)
    {
        if (Menu->objectName().isEmpty())
            Menu->setObjectName("Menu");
        Menu->resize(1200, 650);
        frame = new QFrame(Menu);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(0, 0, 1200, 650));
        frame->setStyleSheet(QString::fromUtf8("QFrame {\n"
"          border: 2px solid black;\n"
"          background-color:#171717;\n"
"          border-radius: 10px;\n"
"      }\n"
"    "));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        sideMenuFrame = new QFrame(Menu);
        sideMenuFrame->setObjectName("sideMenuFrame");
        sideMenuFrame->setGeometry(QRect(0, 0, 200, 650));
        sideMenuFrame->setStyleSheet(QString::fromUtf8("QFrame {\n"
"          background-color: #A7C34E;\n"
"          border-radius: 10px;\n"
"      }\n"
"    "));
        sideMenuFrame->setFrameShape(QFrame::StyledPanel);
        sideMenuFrame->setFrameShadow(QFrame::Raised);
        logoutButton = new QPushButton(Menu);
        logoutButton->setObjectName("logoutButton");
        logoutButton->setGeometry(QRect(10, 579, 161, 61));
        QIcon icon;
        icon.addFile(QString::fromUtf8("../Resources/Icons/logout.png"), QSize(), QIcon::Normal, QIcon::Off);
        logoutButton->setIcon(icon);

        retranslateUi(Menu);

        QMetaObject::connectSlotsByName(Menu);
    } // setupUi

    void retranslateUi(QDialog *Menu)
    {
        Menu->setWindowTitle(QCoreApplication::translate("Menu", "Dialog", nullptr));
        logoutButton->setText(QCoreApplication::translate("Menu", "Logout", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Menu: public Ui_Menu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MENU_H
