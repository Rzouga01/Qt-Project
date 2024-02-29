/********************************************************************************
** Form generated from reading UI file 'dashboard.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DASHBOARD_H
#define UI_DASHBOARD_H

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
    QPushButton *add;
    QPushButton *del;
    QPushButton *pdf;
    QPushButton *update;
    QPushButton *sort;
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
            Dashboard->setObjectName(QStringLiteral("Dashboard"));
        Dashboard->resize(1200, 650);
        Dashboard->setStyleSheet(QLatin1String("QFrame {\n"
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
"\n"
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
"\n"
"\n"
"}\n"
"\n"
"/* Apply styles to the featureBar_4 */\n"
"#featureBar_4 {\n"
"    background-color: white;\n"
"    border-radius: 25px;\n"
"}\n"
"\n"
"/* Apply styles to the addFeature_4 */\n"
"#addFeature_4"
                        " {\n"
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
"\n"
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
"}\n"
"\n"
"/* Apply styles to the searchBar */\n"
"#sear"
                        "chBar {\n"
"    background-color: white;\n"
"\n"
"}\n"
"#logoutButton,\n"
"#employees,\n"
"#clients,\n"
"#contracts,\n"
"#accidents {\n"
"    font-size: 15px;\n"
"    font-weight: bold;\n"
"    color: white; /* Set the default text color */\n"
"        background-color: #444444;;\n"
"        border-radius:15px;\n"
"\n"
"}\n"
"\n"
"\n"
"#logoutButton:hover,\n"
"#employees:hover,\n"
"#contracts:hover,\n"
"#clients:hover,\n"
"#accidents:hover {\n"
"    background-color: #333; /* Darker color on hover */\n"
"}\n"
"\n"
"#searchBar {\n"
"    border-radius: 20px;\n"
"}\n"
"\n"
"#searchBar_2 {\n"
"    border-radius: 20px;\n"
"}\n"
"\n"
"#searchBar_3 {\n"
"    border-radius: 20px;\n"
"}\n"
"\n"
"#searchBar_4 {\n"
"    border-radius: 20px;\n"
"}\n"
"\n"
"/* Apply styles to the add button */\n"
"#add,\n"
"#del,\n"
"#pdf,\n"
"#update,\n"
"#sort {\n"
"    border: none; /* Remove default button border */\n"
"    background-color: transparent; /* Make the background transparent */\n"
"}\n"
"\n"
"/* Set styles for the icons *"
                        "/\n"
"#add::icon,\n"
"#del::icon,\n"
"#pdf::icon,\n"
"#update::icon,\n"
"#sort::icon {\n"
"    padding: 0; /* Remove padding */\n"
"    width: 40px; /* Set icon width */\n"
"    height: 40px; /* Set icon height */\n"
"}\n"
"\n"
"/* Set icons for the buttons */\n"
"#add::icon {\n"
"    image: url(../Resources/Icons/add.png); /* Set the icon for the add button */\n"
"}\n"
"\n"
"#del::icon {\n"
"    image: url(../Resources/Icons/delete.png); /* Set the icon for the delete button */\n"
"}\n"
"\n"
"#pdf::icon {\n"
"    image: url(../Resources/Icons/pdf.png); /* Set the icon for the PDF button */\n"
"}\n"
"\n"
"#update::icon {\n"
"    image: url(../Resources/Icons/update.png); /* Set the icon for the update button */\n"
"}\n"
"\n"
"#sort::icon {\n"
"    image: url(../Resources/Icons/sort.png); /* Set the icon for the sort button */\n"
"}\n"
"\n"
""));
        frame = new QFrame(Dashboard);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(0, 0, 1200, 650));
        frame->setStyleSheet(QStringLiteral(""));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        role = new QLineEdit(frame);
        role->setObjectName(QStringLiteral("role"));
        role->setGeometry(QRect(880, 30, 281, 91));
        role->setCursor(QCursor(Qt::ArrowCursor));
        role->setReadOnly(true);
        logo = new QLabel(frame);
        logo->setObjectName(QStringLiteral("logo"));
        logo->setGeometry(QRect(20, 20, 111, 101));
        logo->setPixmap(QPixmap(QString::fromUtf8("../Resources/Logo/icon ripple.png")));
        logo->setScaledContents(true);
        helloBar = new QTextEdit(frame);
        helloBar->setObjectName(QStringLiteral("helloBar"));
        helloBar->setGeometry(QRect(130, 30, 311, 91));
        helloBar->setTextInteractionFlags(Qt::NoTextInteraction);
        stackedWidget = new QStackedWidget(frame);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setGeometry(QRect(260, 150, 911, 481));
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        featureBar = new QFrame(page);
        featureBar->setObjectName(QStringLiteral("featureBar"));
        featureBar->setGeometry(QRect(400, 10, 501, 61));
        featureBar->setStyleSheet(QStringLiteral(""));
        featureBar->setFrameShape(QFrame::StyledPanel);
        featureBar->setFrameShadow(QFrame::Raised);
        readBox = new QListWidget(page);
        readBox->setObjectName(QStringLiteral("readBox"));
        readBox->setGeometry(QRect(400, 90, 501, 371));
        stats = new QFrame(page);
        stats->setObjectName(QStringLiteral("stats"));
        stats->setGeometry(QRect(10, 230, 371, 231));
        stats->setFrameShape(QFrame::StyledPanel);
        stats->setFrameShadow(QFrame::Raised);
        addFeature = new QFrame(page);
        addFeature->setObjectName(QStringLiteral("addFeature"));
        addFeature->setGeometry(QRect(10, 10, 371, 201));
        addFeature->setFrameShape(QFrame::StyledPanel);
        addFeature->setFrameShadow(QFrame::Raised);
        searchBar = new QLineEdit(page);
        searchBar->setObjectName(QStringLiteral("searchBar"));
        searchBar->setGeometry(QRect(620, 120, 241, 41));
        searchBar->setStyleSheet(QStringLiteral(""));
        searchBar->setClearButtonEnabled(true);
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        featureBar_2 = new QFrame(page_2);
        featureBar_2->setObjectName(QStringLiteral("featureBar_2"));
        featureBar_2->setGeometry(QRect(400, 10, 501, 61));
        featureBar_2->setStyleSheet(QStringLiteral(""));
        featureBar_2->setFrameShape(QFrame::StyledPanel);
        featureBar_2->setFrameShadow(QFrame::Raised);
        readBox_2 = new QListWidget(page_2);
        readBox_2->setObjectName(QStringLiteral("readBox_2"));
        readBox_2->setGeometry(QRect(400, 90, 501, 371));
        searchBar_2 = new QLineEdit(page_2);
        searchBar_2->setObjectName(QStringLiteral("searchBar_2"));
        searchBar_2->setGeometry(QRect(620, 120, 241, 41));
        searchBar_2->setStyleSheet(QStringLiteral(""));
        searchBar_2->setClearButtonEnabled(true);
        stats_2 = new QFrame(page_2);
        stats_2->setObjectName(QStringLiteral("stats_2"));
        stats_2->setGeometry(QRect(10, 230, 371, 231));
        stats_2->setFrameShape(QFrame::StyledPanel);
        stats_2->setFrameShadow(QFrame::Raised);
        addFeature_2 = new QFrame(page_2);
        addFeature_2->setObjectName(QStringLiteral("addFeature_2"));
        addFeature_2->setGeometry(QRect(10, 10, 371, 201));
        addFeature_2->setFrameShape(QFrame::StyledPanel);
        addFeature_2->setFrameShadow(QFrame::Raised);
        stackedWidget->addWidget(page_2);
        page_3 = new QWidget();
        page_3->setObjectName(QStringLiteral("page_3"));
        addFeature_3 = new QFrame(page_3);
        addFeature_3->setObjectName(QStringLiteral("addFeature_3"));
        addFeature_3->setGeometry(QRect(10, 10, 371, 201));
        addFeature_3->setFrameShape(QFrame::StyledPanel);
        addFeature_3->setFrameShadow(QFrame::Raised);
        stats_3 = new QFrame(page_3);
        stats_3->setObjectName(QStringLiteral("stats_3"));
        stats_3->setGeometry(QRect(10, 230, 371, 231));
        stats_3->setFrameShape(QFrame::StyledPanel);
        stats_3->setFrameShadow(QFrame::Raised);
        featureBar_3 = new QFrame(page_3);
        featureBar_3->setObjectName(QStringLiteral("featureBar_3"));
        featureBar_3->setGeometry(QRect(400, 10, 501, 61));
        featureBar_3->setStyleSheet(QStringLiteral(""));
        featureBar_3->setFrameShape(QFrame::StyledPanel);
        featureBar_3->setFrameShadow(QFrame::Raised);
        readBox_3 = new QListWidget(page_3);
        readBox_3->setObjectName(QStringLiteral("readBox_3"));
        readBox_3->setGeometry(QRect(400, 90, 501, 371));
        searchBar_3 = new QLineEdit(page_3);
        searchBar_3->setObjectName(QStringLiteral("searchBar_3"));
        searchBar_3->setGeometry(QRect(620, 120, 241, 41));
        searchBar_3->setStyleSheet(QStringLiteral(""));
        searchBar_3->setClearButtonEnabled(true);
        stackedWidget->addWidget(page_3);
        page_4 = new QWidget();
        page_4->setObjectName(QStringLiteral("page_4"));
        featureBar_4 = new QFrame(page_4);
        featureBar_4->setObjectName(QStringLiteral("featureBar_4"));
        featureBar_4->setGeometry(QRect(400, 10, 501, 61));
        featureBar_4->setStyleSheet(QStringLiteral(""));
        featureBar_4->setFrameShape(QFrame::StyledPanel);
        featureBar_4->setFrameShadow(QFrame::Raised);
        add = new QPushButton(featureBar_4);
        add->setObjectName(QStringLiteral("add"));
        add->setGeometry(QRect(30, 10, 41, 41));
        add->setCursor(QCursor(Qt::PointingHandCursor));
        QIcon icon;
        icon.addFile(QStringLiteral("../Resources/Icons/add.png"), QSize(), QIcon::Normal, QIcon::Off);
        add->setIcon(icon);
        add->setIconSize(QSize(60, 60));
        del = new QPushButton(featureBar_4);
        del->setObjectName(QStringLiteral("del"));
        del->setGeometry(QRect(130, 10, 41, 41));
        del->setCursor(QCursor(Qt::PointingHandCursor));
        QIcon icon1;
        icon1.addFile(QStringLiteral("../Resources/Icons/delete.png"), QSize(), QIcon::Normal, QIcon::Off);
        del->setIcon(icon1);
        del->setIconSize(QSize(40, 40));
        pdf = new QPushButton(featureBar_4);
        pdf->setObjectName(QStringLiteral("pdf"));
        pdf->setGeometry(QRect(420, 10, 41, 41));
        pdf->setCursor(QCursor(Qt::PointingHandCursor));
        QIcon icon2;
        icon2.addFile(QStringLiteral("../Resources/Icons/pdf.png"), QSize(), QIcon::Normal, QIcon::Off);
        pdf->setIcon(icon2);
        pdf->setIconSize(QSize(50, 50));
        update = new QPushButton(featureBar_4);
        update->setObjectName(QStringLiteral("update"));
        update->setGeometry(QRect(320, 10, 41, 41));
        update->setCursor(QCursor(Qt::PointingHandCursor));
        QIcon icon3;
        icon3.addFile(QStringLiteral("../Resources/Icons/update.png"), QSize(), QIcon::Normal, QIcon::Off);
        update->setIcon(icon3);
        update->setIconSize(QSize(60, 60));
        sort = new QPushButton(featureBar_4);
        sort->setObjectName(QStringLiteral("sort"));
        sort->setGeometry(QRect(220, 10, 41, 41));
        sort->setCursor(QCursor(Qt::PointingHandCursor));
        QIcon icon4;
        icon4.addFile(QStringLiteral("../Resources/Icons/sort.png"), QSize(), QIcon::Normal, QIcon::Off);
        sort->setIcon(icon4);
        sort->setIconSize(QSize(50, 50));
        readBox_4 = new QListWidget(page_4);
        readBox_4->setObjectName(QStringLiteral("readBox_4"));
        readBox_4->setGeometry(QRect(400, 90, 501, 371));
        searchBar_4 = new QLineEdit(page_4);
        searchBar_4->setObjectName(QStringLiteral("searchBar_4"));
        searchBar_4->setGeometry(QRect(620, 120, 241, 41));
        searchBar_4->setStyleSheet(QStringLiteral(""));
        searchBar_4->setClearButtonEnabled(true);
        stats_4 = new QFrame(page_4);
        stats_4->setObjectName(QStringLiteral("stats_4"));
        stats_4->setGeometry(QRect(10, 230, 371, 231));
        stats_4->setFrameShape(QFrame::StyledPanel);
        stats_4->setFrameShadow(QFrame::Raised);
        addFeature_4 = new QFrame(page_4);
        addFeature_4->setObjectName(QStringLiteral("addFeature_4"));
        addFeature_4->setGeometry(QRect(10, 10, 371, 201));
        addFeature_4->setFrameShape(QFrame::StyledPanel);
        addFeature_4->setFrameShadow(QFrame::Raised);
        stackedWidget->addWidget(page_4);
        employees = new QPushButton(frame);
        employees->setObjectName(QStringLiteral("employees"));
        employees->setGeometry(QRect(30, 175, 200, 50));
        employees->setCursor(QCursor(Qt::PointingHandCursor));
        clients = new QPushButton(frame);
        clients->setObjectName(QStringLiteral("clients"));
        clients->setGeometry(QRect(30, 275, 200, 50));
        clients->setCursor(QCursor(Qt::PointingHandCursor));
        contracts = new QPushButton(frame);
        contracts->setObjectName(QStringLiteral("contracts"));
        contracts->setGeometry(QRect(30, 375, 200, 50));
        contracts->setCursor(QCursor(Qt::PointingHandCursor));
        accidents = new QPushButton(frame);
        accidents->setObjectName(QStringLiteral("accidents"));
        accidents->setGeometry(QRect(30, 475, 200, 50));
        accidents->setCursor(QCursor(Qt::PointingHandCursor));
        logoutButton = new QPushButton(frame);
        logoutButton->setObjectName(QStringLiteral("logoutButton"));
        logoutButton->setGeometry(QRect(30, 575, 200, 50));
        logoutButton->setCursor(QCursor(Qt::PointingHandCursor));
        logoutButton->setAutoFillBackground(false);
        logoutButton->setStyleSheet(QStringLiteral(""));
        QIcon icon5;
        icon5.addFile(QStringLiteral("../Resources/Icons/logout.png"), QSize(), QIcon::Normal, QIcon::Off);
        logoutButton->setIcon(icon5);
        logoutButton->setIconSize(QSize(20, 20));

        retranslateUi(Dashboard);

        stackedWidget->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(Dashboard);
    } // setupUi

    void retranslateUi(QDialog *Dashboard)
    {
        Dashboard->setWindowTitle(QApplication::translate("Dashboard", "Dialog", Q_NULLPTR));
        role->setPlaceholderText(QApplication::translate("Dashboard", "Role", Q_NULLPTR));
        logo->setText(QString());
        helloBar->setPlaceholderText(QApplication::translate("Dashboard", "Hello,First Name Last Name", Q_NULLPTR));
        add->setText(QString());
        del->setText(QString());
        pdf->setText(QString());
        update->setText(QString());
        sort->setText(QString());
        employees->setText(QApplication::translate("Dashboard", "Employees", Q_NULLPTR));
        clients->setText(QApplication::translate("Dashboard", "Clients", Q_NULLPTR));
        contracts->setText(QApplication::translate("Dashboard", "Contrats", Q_NULLPTR));
        accidents->setText(QApplication::translate("Dashboard", "Accidents", Q_NULLPTR));
        logoutButton->setText(QApplication::translate("Dashboard", "Logout", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Dashboard: public Ui_Dashboard {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DASHBOARD_H
