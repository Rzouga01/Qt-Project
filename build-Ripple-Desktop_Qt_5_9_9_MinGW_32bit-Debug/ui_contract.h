/********************************************************************************
** Form generated from reading UI file 'contract.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONTRACT_H
#define UI_CONTRACT_H

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

class Ui_contract
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

    void setupUi(QDialog *contract)
    {
        if (contract->objectName().isEmpty())
            contract->setObjectName(QStringLiteral("contract"));
        contract->resize(1200, 650);
        contract->setStyleSheet(QLatin1String("#contract{\n"
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
        helloBar->setGeometry(QRect(120, 40, 221, 91));
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

        retranslateUi(contract);

        QMetaObject::connectSlotsByName(contract);
    } // setupUi

    void retranslateUi(QDialog *contract)
    {
        contract->setWindowTitle(QApplication::translate("contract", "Contract Manager", Q_NULLPTR));
        logo->setText(QString());
        role->setPlaceholderText(QApplication::translate("contract", "Role", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class contract: public Ui_contract {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONTRACT_H
