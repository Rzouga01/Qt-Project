/********************************************************************************
** Form generated from reading UI file 'accident.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ACCIDENT_H
#define UI_ACCIDENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_accident
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

    void setupUi(QDialog *accident)
    {
        if (accident->objectName().isEmpty())
            accident->setObjectName(QStringLiteral("accident"));
        accident->resize(1200, 650);
        accident->setStyleSheet(QLatin1String("#accident{\n"
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
        frame = new QFrame(accident);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(0, 0, 1200, 650));
        frame->setStyleSheet(QLatin1String("#featureBar{\n"
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
        logo->setObjectName(QStringLiteral("logo"));
        logo->setGeometry(QRect(10, 30, 111, 101));
        logo->setPixmap(QPixmap(QString::fromUtf8("../Resources/Logo/icon ripple.png")));
        logo->setScaledContents(true);
        role = new QLineEdit(frame);
        role->setObjectName(QStringLiteral("role"));
        role->setGeometry(QRect(890, 40, 281, 91));
        role->setCursor(QCursor(Qt::ArrowCursor));
        role->setReadOnly(true);
        helloBar = new QTextEdit(frame);
        helloBar->setObjectName(QStringLiteral("helloBar"));
        helloBar->setGeometry(QRect(120, 40, 311, 91));
        helloBar->setTextInteractionFlags(Qt::NoTextInteraction);
        readBox = new QListWidget(frame);
        readBox->setObjectName(QStringLiteral("readBox"));
        readBox->setGeometry(QRect(640, 220, 541, 411));
        searchBar = new QLineEdit(frame);
        searchBar->setObjectName(QStringLiteral("searchBar"));
        searchBar->setGeometry(QRect(880, 250, 241, 41));
        searchBar->setStyleSheet(QLatin1String("#searchBar{\n"
"border-radius:10px;\n"
"}"));
        searchBar->setClearButtonEnabled(true);
        featureBar = new QFrame(frame);
        featureBar->setObjectName(QStringLiteral("featureBar"));
        featureBar->setGeometry(QRect(640, 149, 541, 61));
        featureBar->setStyleSheet(QStringLiteral(""));
        featureBar->setFrameShape(QFrame::StyledPanel);
        featureBar->setFrameShadow(QFrame::Raised);
        stats = new QFrame(frame);
        stats->setObjectName(QStringLiteral("stats"));
        stats->setGeometry(QRect(20, 400, 601, 231));
        stats->setFrameShape(QFrame::StyledPanel);
        stats->setFrameShadow(QFrame::Raised);
        addFeature = new QFrame(frame);
        addFeature->setObjectName(QStringLiteral("addFeature"));
        addFeature->setGeometry(QRect(20, 149, 601, 231));
        addFeature->setFrameShape(QFrame::StyledPanel);
        addFeature->setFrameShadow(QFrame::Raised);

        retranslateUi(accident);

        QMetaObject::connectSlotsByName(accident);
    } // setupUi

    void retranslateUi(QDialog *accident)
    {
        accident->setWindowTitle(QApplication::translate("accident", "accident Manager", Q_NULLPTR));
        logo->setText(QString());
        role->setPlaceholderText(QApplication::translate("accident", "Role", Q_NULLPTR));
        helloBar->setPlaceholderText(QApplication::translate("accident", "Hello,                    First Name Last Name", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class accident: public Ui_accident {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ACCIDENT_H
