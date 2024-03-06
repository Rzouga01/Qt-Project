/********************************************************************************
** Form generated from reading UI file 'contract.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONTRACT_H
#define UI_CONTRACT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_contract
{
public:
    QFrame *frame;
    QTextEdit *helloBar;
    QListWidget *readBox;
    QLineEdit *searchBar;
    QFrame *featureBar;
    QFrame *stats;
    QFrame *addFeature;

    void setupUi(QDialog *contract)
    {
        if (contract->objectName().isEmpty())
            contract->setObjectName("contract");
        contract->resize(1200, 650);
        contract->setStyleSheet(QString::fromUtf8("#contract{\n"
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
        frame = new QFrame(contract);
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
        helloBar = new QTextEdit(frame);
        helloBar->setObjectName("helloBar");
        helloBar->setGeometry(QRect(120, 40, 221, 91));
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

        retranslateUi(contract);

        QMetaObject::connectSlotsByName(contract);
    } // setupUi

    void retranslateUi(QDialog *contract)
    {
        contract->setWindowTitle(QCoreApplication::translate("contract", "Contract Manager", nullptr));
    } // retranslateUi

};

namespace Ui {
    class contract: public Ui_contract {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONTRACT_H
