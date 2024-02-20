/********************************************************************************
** Form generated from reading UI file 'menu.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MENU_H
#define UI_MENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
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
            Menu->setObjectName(QStringLiteral("Menu"));
        Menu->resize(1200, 650);
        frame = new QFrame(Menu);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(0, 0, 1200, 650));
        frame->setStyleSheet(QLatin1String("QFrame {\n"
"          border: 2px solid black;\n"
"          background-color:#171717;\n"
"          border-radius: 10px;\n"
"      }\n"
"    "));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        sideMenuFrame = new QFrame(Menu);
        sideMenuFrame->setObjectName(QStringLiteral("sideMenuFrame"));
        sideMenuFrame->setGeometry(QRect(0, 0, 200, 650));
        sideMenuFrame->setStyleSheet(QLatin1String("QFrame {\n"
"          background-color: #A7C34E;\n"
"          border-radius: 10px;\n"
"      }\n"
"    "));
        sideMenuFrame->setFrameShape(QFrame::StyledPanel);
        sideMenuFrame->setFrameShadow(QFrame::Raised);
        logoutButton = new QPushButton(Menu);
        logoutButton->setObjectName(QStringLiteral("logoutButton"));
        logoutButton->setGeometry(QRect(10, 579, 161, 61));
        QIcon icon;
        icon.addFile(QStringLiteral("../Resources/Icons/logout.png"), QSize(), QIcon::Normal, QIcon::Off);
        logoutButton->setIcon(icon);

        retranslateUi(Menu);

        QMetaObject::connectSlotsByName(Menu);
    } // setupUi

    void retranslateUi(QDialog *Menu)
    {
        Menu->setWindowTitle(QApplication::translate("Menu", "Dialog", Q_NULLPTR));
        logoutButton->setText(QApplication::translate("Menu", "Logout", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Menu: public Ui_Menu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MENU_H
