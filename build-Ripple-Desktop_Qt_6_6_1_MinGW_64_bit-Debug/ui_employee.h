/********************************************************************************
** Form generated from reading UI file 'employee.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EMPLOYEE_H
#define UI_EMPLOYEE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_Employee
{
public:
    QFrame *frame;
    QLabel *logo;
    QLineEdit *role;
    QTextEdit *helloBar;
    QListWidget *readBox;
    QLineEdit *searchBar;
    QFrame *featureBar;
    QFrame *stats;
    QFrame *addFeature;

    void setupUi(QDialog *Employee)
    {
        if (Employee->objectName().isEmpty())
            Employee->setObjectName("Employee");
        Employee->resize(1200, 650);
        Employee->setStyleSheet(QString::fromUtf8("#Employee{\n"
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
        frame = new QFrame(Employee);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(0, 0, 1200, 650));
        frame->setStyleSheet(QString::fromUtf8("#featureBar{\n"
"background-color:white;\n"
"border-radius:25px;\n"
"}\n"
"#addFeature{\n"
"background-color:#A7C34E;\n"
"border-radius:25px;\n"
"}\n"
"\n"
"#stats{\n"
"background-color:#A7C34E;\n"
"border-radius:25px;\n"
"}"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        logo = new QLabel(frame);
        logo->setObjectName("logo");
        logo->setGeometry(QRect(10, 30, 111, 101));
        logo->setPixmap(QPixmap(QString::fromUtf8("../Resources/Logo/icon ripple.png")));
        logo->setScaledContents(true);
        role = new QLineEdit(frame);
        role->setObjectName("role");
        role->setGeometry(QRect(890, 40, 281, 91));
        role->setCursor(QCursor(Qt::ArrowCursor));
        role->setReadOnly(true);
        helloBar = new QTextEdit(frame);
        helloBar->setObjectName("helloBar");
        helloBar->setGeometry(QRect(120, 40, 291, 91));
        helloBar->setTextInteractionFlags(Qt::NoTextInteraction);
        readBox = new QListWidget(frame);
        readBox->setObjectName("readBox");
        readBox->setGeometry(QRect(640, 220, 541, 411));
        searchBar = new QLineEdit(frame);
        searchBar->setObjectName("searchBar");
        searchBar->setGeometry(QRect(880, 250, 241, 41));
        searchBar->setStyleSheet(QString::fromUtf8("#searchBar{\n"
"border-radius:10px;\n"
"}"));
        searchBar->setClearButtonEnabled(true);
        featureBar = new QFrame(frame);
        featureBar->setObjectName("featureBar");
        featureBar->setGeometry(QRect(640, 149, 541, 61));
        featureBar->setStyleSheet(QString::fromUtf8(""));
        featureBar->setFrameShape(QFrame::StyledPanel);
        featureBar->setFrameShadow(QFrame::Raised);
        stats = new QFrame(frame);
        stats->setObjectName("stats");
        stats->setGeometry(QRect(20, 400, 601, 231));
        stats->setFrameShape(QFrame::StyledPanel);
        stats->setFrameShadow(QFrame::Raised);
        addFeature = new QFrame(frame);
        addFeature->setObjectName("addFeature");
        addFeature->setGeometry(QRect(20, 149, 601, 231));
        addFeature->setFrameShape(QFrame::StyledPanel);
        addFeature->setFrameShadow(QFrame::Raised);

        retranslateUi(Employee);

        QMetaObject::connectSlotsByName(Employee);
    } // setupUi

    void retranslateUi(QDialog *Employee)
    {
        Employee->setWindowTitle(QCoreApplication::translate("Employee", "Employee Manager", nullptr));
        logo->setText(QString());
        role->setPlaceholderText(QCoreApplication::translate("Employee", "Role", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Employee: public Ui_Employee {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EMPLOYEE_H
