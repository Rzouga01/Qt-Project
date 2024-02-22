/********************************************************************************
** Form generated from reading UI file 'dashboard.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DASHBOARD_H
#define UI_DASHBOARD_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dashboard
{
public:
    QFrame *frame;
    QLineEdit *role;
    QLabel *logo;
    QTextEdit *helloBar;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QFrame *featureBar;
    QListWidget *readBox;
    QFrame *stats;
    QFrame *addFeature;
    QLineEdit *searchBar;
    QWidget *page_2;
    QFrame *featureBar_2;
    QListWidget *readBox_2;
    QLineEdit *searchBar_2;
    QFrame *stats_2;
    QFrame *addFeature_2;
    QWidget *page_3;
    QFrame *addFeature_3;
    QFrame *stats_3;
    QFrame *featureBar_3;
    QListWidget *readBox_3;
    QLineEdit *searchBar_3;
    QWidget *page_4;
    QFrame *featureBar_4;
    QListWidget *readBox_4;
    QLineEdit *searchBar_4;
    QFrame *stats_4;
    QFrame *addFeature_4;
    QPushButton *employees;
    QPushButton *clients;
    QPushButton *contracts;
    QPushButton *accidents;
    QPushButton *logoutButton;

    void setupUi(QDialog *Dashboard)
    {
        if (Dashboard->objectName().isEmpty())
            Dashboard->setObjectName("Dashboard");
        Dashboard->resize(1200, 650);
        Dashboard->setStyleSheet(QString::fromUtf8("QFrame {\n"
"         background-color:#171717;\n"
"        border:none;\n"
"     }\n"
"\n"
"#Dashboard\n"
"{\n"
"background-color: #171717;\n"
"}\n"
"\n"
"#helloBar{\n"
"border: none;\n"
"background-color:#171717;\n"
"font-size:30px;\n"
"color:white;\n"
"font-family:\"helvetica\"\n"
"\n"
"\n"
"}\n"
"\n"
"#role{\n"
"font-size:30px;\n"
"background-color:#171717;\n"
"color:white;\n"
"border:none;\n"
"font-family:\"helvetica\"\n"
"}\n"
"\n"
"\n"
"#stackedWidget\n"
"{\n"
"background-color: #171717;\n"
"}\n"
"\n"
"/* Apply styles to the featureBar_2 */\n"
"#featureBar_2 {\n"
"    background-color: white;\n"
"    border-radius: 25px;\n"
"}\n"
"\n"
"/* Apply styles to the addFeature_2 */\n"
"#addFeature_2 {\n"
"    background-color: #A7C34E;\n"
"    border-radius: 25px;\n"
"}\n"
"\n"
"/* Apply styles to the stats_2 */\n"
"#stats_2 {\n"
"    background-color: #A7C34E;\n"
"    border-radius: 25px;\n"
"}\n"
"\n"
"/* Apply styles to the readBox_2 */\n"
"#readBox_2 {\n"
"    border: none;\n"
"    background-color: #A7C34E"
                        ";\n"
"    border-radius: 25px;\n"
"}\n"
"\n"
"/* Apply styles to the searchBar_2 */\n"
"#searchBar_2 {\n"
"     background-color: white;\n"
" border-radius: 25px;\n"
"\n"
"}\n"
"\n"
"/* Apply styles to the featureBar_3 */\n"
"#featureBar_3 {\n"
"    background-color: white;\n"
"    border-radius: 25px;\n"
"}\n"
"\n"
"/* Apply styles to the addFeature_3 */\n"
"#addFeature_3 {\n"
"    background-color: #A7C34E;\n"
"    border-radius: 25px;\n"
"}\n"
"\n"
"/* Apply styles to the stats_3 */\n"
"#stats_3 {\n"
"    background-color: #A7C34E;\n"
"    border-radius: 25px;\n"
"}\n"
"\n"
"/* Apply styles to the readBox_3 */\n"
"#readBox_3 {\n"
"    border: none;\n"
"    background-color: #A7C34E;\n"
"    border-radius: 25px;\n"
"}\n"
"\n"
"/* Apply styles to the searchBar_3 */\n"
"#searchBar_3 {\n"
"    background-color: white;\n"
"  border-radius: 25px;\n"
"}\n"
"\n"
"/* Apply styles to the featureBar_4 */\n"
"#featureBar_4 {\n"
"    background-color: white;\n"
"    border-radius: 25px;\n"
"}\n"
"\n"
"/* Apply styles to"
                        " the addFeature_4 */\n"
"#addFeature_4 {\n"
"    background-color: #A7C34E;\n"
"    border-radius: 25px;\n"
"}\n"
"\n"
"/* Apply styles to the stats_4 */\n"
"#stats_4 {\n"
"    background-color: #A7C34E;\n"
"    border-radius: 25px;\n"
"}\n"
"\n"
"/* Apply styles to the readBox_4 */\n"
"#readBox_4 {\n"
"    border: none;\n"
"    background-color: #A7C34E;\n"
"    border-radius: 25px;\n"
"}\n"
"\n"
"/* Apply styles to the searchBar_4 */\n"
"#searchBar_4 {\n"
"      background-color: white;\n"
"  border-radius: 25px;\n"
"}\n"
"\n"
"\n"
"#featureBar {\n"
"    background-color: white;\n"
"    border-radius: 25px;\n"
"}\n"
"\n"
"/* Apply styles to the addFeature */\n"
"#addFeature {\n"
"    background-color: #A7C34E;\n"
"    border-radius: 25px;\n"
"}\n"
"\n"
"/* Apply styles to the stats */\n"
"#stats {\n"
"    background-color: #A7C34E;\n"
"    border-radius: 25px;\n"
"}\n"
"\n"
"/* Apply styles to the readBox */\n"
"#readBox {\n"
"    border: none;\n"
"    background-color: #A7C34E;\n"
"    border-radius: 25px;\n"
""
                        "}\n"
"\n"
"/* Apply styles to the searchBar */\n"
"#searchBar {\n"
"    background-color: white;\n"
" border-radius: 25px;\n"
"}\n"
"#logoutButton,\n"
"#employees,\n"
"#clients,\n"
"#contracts,\n"
"#accidents {\n"
"    font-size: 15px;\n"
"    font-weight: bold;\n"
"    color: white; /* Set the default text color */\n"
"	background-color: #444444;;\n"
"	border-radius:15px;\n"
"\n"
"	\n"
"\n"
"}\n"
"#logoutButton:hover,\n"
"#employees:hover,\n"
"#contracts:hover,\n"
"#clients:hover,\n"
"#accidents:hover {\n"
"    background-color: #333; /* Darker color on hover */\n"
"    color: #fff; /* Text color changes to white on hover */\n"
"    \n"
"   \n"
"}\n"
""));
        frame = new QFrame(Dashboard);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(0, 0, 1200, 650));
        frame->setStyleSheet(QString::fromUtf8(""));
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
        helloBar->setGeometry(QRect(130, 30, 311, 91));
        helloBar->setTextInteractionFlags(Qt::NoTextInteraction);
        stackedWidget = new QStackedWidget(frame);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setGeometry(QRect(260, 150, 911, 481));
        page = new QWidget();
        page->setObjectName("page");
        featureBar = new QFrame(page);
        featureBar->setObjectName("featureBar");
        featureBar->setGeometry(QRect(400, 10, 501, 61));
        featureBar->setStyleSheet(QString::fromUtf8(""));
        featureBar->setFrameShape(QFrame::StyledPanel);
        featureBar->setFrameShadow(QFrame::Raised);
        readBox = new QListWidget(page);
        readBox->setObjectName("readBox");
        readBox->setGeometry(QRect(400, 90, 501, 371));
        stats = new QFrame(page);
        stats->setObjectName("stats");
        stats->setGeometry(QRect(10, 230, 371, 231));
        stats->setFrameShape(QFrame::StyledPanel);
        stats->setFrameShadow(QFrame::Raised);
        addFeature = new QFrame(page);
        addFeature->setObjectName("addFeature");
        addFeature->setGeometry(QRect(10, 10, 371, 201));
        addFeature->setFrameShape(QFrame::StyledPanel);
        addFeature->setFrameShadow(QFrame::Raised);
        searchBar = new QLineEdit(page);
        searchBar->setObjectName("searchBar");
        searchBar->setGeometry(QRect(620, 120, 241, 41));
        searchBar->setStyleSheet(QString::fromUtf8("#searchBar{\n"
"border-radius:10px;\n"
"}"));
        searchBar->setClearButtonEnabled(true);
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName("page_2");
        featureBar_2 = new QFrame(page_2);
        featureBar_2->setObjectName("featureBar_2");
        featureBar_2->setGeometry(QRect(400, 10, 501, 61));
        featureBar_2->setStyleSheet(QString::fromUtf8(""));
        featureBar_2->setFrameShape(QFrame::StyledPanel);
        featureBar_2->setFrameShadow(QFrame::Raised);
        readBox_2 = new QListWidget(page_2);
        readBox_2->setObjectName("readBox_2");
        readBox_2->setGeometry(QRect(400, 90, 501, 371));
        searchBar_2 = new QLineEdit(page_2);
        searchBar_2->setObjectName("searchBar_2");
        searchBar_2->setGeometry(QRect(620, 120, 241, 41));
        searchBar_2->setStyleSheet(QString::fromUtf8("#searchBar{\n"
"border-radius:10px;\n"
"}"));
        searchBar_2->setClearButtonEnabled(true);
        stats_2 = new QFrame(page_2);
        stats_2->setObjectName("stats_2");
        stats_2->setGeometry(QRect(10, 230, 371, 231));
        stats_2->setFrameShape(QFrame::StyledPanel);
        stats_2->setFrameShadow(QFrame::Raised);
        addFeature_2 = new QFrame(page_2);
        addFeature_2->setObjectName("addFeature_2");
        addFeature_2->setGeometry(QRect(10, 10, 371, 201));
        addFeature_2->setFrameShape(QFrame::StyledPanel);
        addFeature_2->setFrameShadow(QFrame::Raised);
        stackedWidget->addWidget(page_2);
        page_3 = new QWidget();
        page_3->setObjectName("page_3");
        addFeature_3 = new QFrame(page_3);
        addFeature_3->setObjectName("addFeature_3");
        addFeature_3->setGeometry(QRect(10, 10, 371, 201));
        addFeature_3->setFrameShape(QFrame::StyledPanel);
        addFeature_3->setFrameShadow(QFrame::Raised);
        stats_3 = new QFrame(page_3);
        stats_3->setObjectName("stats_3");
        stats_3->setGeometry(QRect(10, 230, 371, 231));
        stats_3->setFrameShape(QFrame::StyledPanel);
        stats_3->setFrameShadow(QFrame::Raised);
        featureBar_3 = new QFrame(page_3);
        featureBar_3->setObjectName("featureBar_3");
        featureBar_3->setGeometry(QRect(400, 10, 501, 61));
        featureBar_3->setStyleSheet(QString::fromUtf8(""));
        featureBar_3->setFrameShape(QFrame::StyledPanel);
        featureBar_3->setFrameShadow(QFrame::Raised);
        readBox_3 = new QListWidget(page_3);
        readBox_3->setObjectName("readBox_3");
        readBox_3->setGeometry(QRect(400, 90, 501, 371));
        searchBar_3 = new QLineEdit(page_3);
        searchBar_3->setObjectName("searchBar_3");
        searchBar_3->setGeometry(QRect(620, 120, 241, 41));
        searchBar_3->setStyleSheet(QString::fromUtf8("#searchBar{\n"
"border-radius:10px;\n"
"}"));
        searchBar_3->setClearButtonEnabled(true);
        stackedWidget->addWidget(page_3);
        page_4 = new QWidget();
        page_4->setObjectName("page_4");
        featureBar_4 = new QFrame(page_4);
        featureBar_4->setObjectName("featureBar_4");
        featureBar_4->setGeometry(QRect(400, 10, 501, 61));
        featureBar_4->setStyleSheet(QString::fromUtf8(""));
        featureBar_4->setFrameShape(QFrame::StyledPanel);
        featureBar_4->setFrameShadow(QFrame::Raised);
        readBox_4 = new QListWidget(page_4);
        readBox_4->setObjectName("readBox_4");
        readBox_4->setGeometry(QRect(400, 90, 501, 371));
        searchBar_4 = new QLineEdit(page_4);
        searchBar_4->setObjectName("searchBar_4");
        searchBar_4->setGeometry(QRect(620, 120, 241, 41));
        searchBar_4->setStyleSheet(QString::fromUtf8("#searchBar{\n"
"border-radius:10px;\n"
"}"));
        searchBar_4->setClearButtonEnabled(true);
        stats_4 = new QFrame(page_4);
        stats_4->setObjectName("stats_4");
        stats_4->setGeometry(QRect(10, 230, 371, 231));
        stats_4->setFrameShape(QFrame::StyledPanel);
        stats_4->setFrameShadow(QFrame::Raised);
        addFeature_4 = new QFrame(page_4);
        addFeature_4->setObjectName("addFeature_4");
        addFeature_4->setGeometry(QRect(10, 10, 371, 201));
        addFeature_4->setFrameShape(QFrame::StyledPanel);
        addFeature_4->setFrameShadow(QFrame::Raised);
        stackedWidget->addWidget(page_4);
        employees = new QPushButton(frame);
        employees->setObjectName("employees");
        employees->setGeometry(QRect(30, 175, 200, 50));
        clients = new QPushButton(frame);
        clients->setObjectName("clients");
        clients->setGeometry(QRect(30, 275, 200, 50));
        contracts = new QPushButton(frame);
        contracts->setObjectName("contracts");
        contracts->setGeometry(QRect(30, 375, 200, 50));
        accidents = new QPushButton(frame);
        accidents->setObjectName("accidents");
        accidents->setGeometry(QRect(30, 475, 200, 50));
        logoutButton = new QPushButton(frame);
        logoutButton->setObjectName("logoutButton");
        logoutButton->setGeometry(QRect(30, 575, 200, 50));
        logoutButton->setAutoFillBackground(false);
        logoutButton->setStyleSheet(QString::fromUtf8(""));
        QIcon icon;
        icon.addFile(QString::fromUtf8("../Resources/Icons/logout.png"), QSize(), QIcon::Normal, QIcon::Off);
        logoutButton->setIcon(icon);
        logoutButton->setIconSize(QSize(20, 20));

        retranslateUi(Dashboard);

        stackedWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(Dashboard);
    } // setupUi

    void retranslateUi(QDialog *Dashboard)
    {
        Dashboard->setWindowTitle(QCoreApplication::translate("Dashboard", "Dialog", nullptr));
        role->setPlaceholderText(QCoreApplication::translate("Dashboard", "Role", nullptr));
        logo->setText(QString());
        helloBar->setPlaceholderText(QCoreApplication::translate("Dashboard", "Hello,                    First Name Last Name", nullptr));
        employees->setText(QCoreApplication::translate("Dashboard", "Employees", nullptr));
        clients->setText(QCoreApplication::translate("Dashboard", "Clients", nullptr));
        contracts->setText(QCoreApplication::translate("Dashboard", "Contrats", nullptr));
        accidents->setText(QCoreApplication::translate("Dashboard", "Accidents", nullptr));
        logoutButton->setText(QCoreApplication::translate("Dashboard", "Logout", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dashboard: public Ui_Dashboard {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DASHBOARD_H
