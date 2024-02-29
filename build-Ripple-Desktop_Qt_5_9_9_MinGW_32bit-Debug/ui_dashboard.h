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
#include <QtWidgets/QTableWidget>
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
    QPushButton *add;
    QPushButton *del;
    QPushButton *update;
    QPushButton *pdf;
    QPushButton *sort;
    QListWidget *readBox;
    QFrame *stats;
    QFrame *addFeature;
    QLineEdit *searchBar;
    QTableWidget *tableWidget;
    QWidget *page_2;
    QListWidget *readBox_2;
    QLineEdit *searchBar_2;
    QFrame *stats_2;
    QFrame *addFeature_2;
    QFrame *featureBar_2;
    QPushButton *add_2;
    QPushButton *del_2;
    QPushButton *update_2;
    QPushButton *pdf_2;
    QPushButton *sort_2;
    QTableWidget *tableClient;
    QWidget *page_3;
    QFrame *addFeature_3;
    QFrame *stats_3;
    QListWidget *readBox_3;
    QLineEdit *searchBar_3;
    QFrame *featureBar_3;
    QPushButton *add_3;
    QPushButton *del_3;
    QPushButton *update_3;
    QPushButton *pdf_3;
    QPushButton *sort_3;
    QTableWidget *tableWidget_3;
    QWidget *page_4;
    QListWidget *readBox_4;
    QLineEdit *searchBar_4;
    QFrame *stats_4;
    QFrame *addFeature_4;
    QFrame *featureBar_4;
    QPushButton *add_4;
    QPushButton *del_4;
    QPushButton *update_4;
    QPushButton *pdf_4;
    QPushButton *sort_4;
    QTableWidget *tableWidget_4;
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
"#sort ,\n"
"#add_2,\n"
"#del_2,\n"
"#pdf_2,\n"
"#update_2,\n"
"#sort_2,\n"
"#add_3,\n"
"#del_3,\n"
"#pdf_3,\n"
"#update_3,\n"
"#sort_3,\n"
"#add_4,\n"
"#del_4,\n"
"#pdf_4,\n"
"#update_4,"
                        "\n"
"#sort_4{\n"
"    border: none; /* Remove default button border */\n"
"    background-color: transparent; /* Make the background transparent */\n"
"}\n"
"\n"
"/* Set styles for the icons */\n"
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
"    image: url(../Resources/Icons/sort.png); /* Set the icon for the sort butto"
                        "n */\n"
"}\n"
"\n"
""));
        frame = new QFrame(Dashboard);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(0, 0, 1200, 650));
        frame->setStyleSheet(QStringLiteral(""));
        frame->setFrameShape(QFrame::NoFrame);
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
        featureBar->setFrameShape(QFrame::NoFrame);
        add = new QPushButton(featureBar);
        add->setObjectName(QStringLiteral("add"));
        add->setGeometry(QRect(30, 10, 41, 41));
        add->setCursor(QCursor(Qt::PointingHandCursor));
        QIcon icon;
        icon.addFile(QStringLiteral("../Resources/Icons/add.png"), QSize(), QIcon::Normal, QIcon::Off);
        add->setIcon(icon);
        add->setIconSize(QSize(60, 60));
        del = new QPushButton(featureBar);
        del->setObjectName(QStringLiteral("del"));
        del->setGeometry(QRect(130, 10, 41, 41));
        del->setCursor(QCursor(Qt::PointingHandCursor));
        QIcon icon1;
        icon1.addFile(QStringLiteral("../Resources/Icons/delete.png"), QSize(), QIcon::Normal, QIcon::Off);
        del->setIcon(icon1);
        del->setIconSize(QSize(40, 40));
        update = new QPushButton(featureBar);
        update->setObjectName(QStringLiteral("update"));
        update->setGeometry(QRect(330, 10, 41, 41));
        update->setCursor(QCursor(Qt::PointingHandCursor));
        QIcon icon2;
        icon2.addFile(QStringLiteral("../Resources/Icons/update.png"), QSize(), QIcon::Normal, QIcon::Off);
        update->setIcon(icon2);
        update->setIconSize(QSize(60, 60));
        pdf = new QPushButton(featureBar);
        pdf->setObjectName(QStringLiteral("pdf"));
        pdf->setGeometry(QRect(430, 10, 41, 41));
        pdf->setCursor(QCursor(Qt::PointingHandCursor));
        QIcon icon3;
        icon3.addFile(QStringLiteral("../Resources/Icons/pdf.png"), QSize(), QIcon::Normal, QIcon::Off);
        pdf->setIcon(icon3);
        pdf->setIconSize(QSize(50, 50));
        sort = new QPushButton(featureBar);
        sort->setObjectName(QStringLiteral("sort"));
        sort->setGeometry(QRect(230, 10, 41, 41));
        sort->setCursor(QCursor(Qt::PointingHandCursor));
        QIcon icon4;
        icon4.addFile(QStringLiteral("../Resources/Icons/sort.png"), QSize(), QIcon::Normal, QIcon::Off);
        sort->setIcon(icon4);
        sort->setIconSize(QSize(50, 50));
        readBox = new QListWidget(page);
        readBox->setObjectName(QStringLiteral("readBox"));
        readBox->setGeometry(QRect(400, 90, 501, 371));
        stats = new QFrame(page);
        stats->setObjectName(QStringLiteral("stats"));
        stats->setGeometry(QRect(10, 230, 371, 231));
        stats->setFrameShape(QFrame::NoFrame);
        addFeature = new QFrame(page);
        addFeature->setObjectName(QStringLiteral("addFeature"));
        addFeature->setGeometry(QRect(10, 10, 371, 201));
        addFeature->setFrameShape(QFrame::NoFrame);
        searchBar = new QLineEdit(page);
        searchBar->setObjectName(QStringLiteral("searchBar"));
        searchBar->setGeometry(QRect(620, 120, 241, 41));
        searchBar->setStyleSheet(QStringLiteral(""));
        searchBar->setClearButtonEnabled(true);
        tableWidget = new QTableWidget(page);
        if (tableWidget->columnCount() < 8)
            tableWidget->setColumnCount(8);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(7, __qtablewidgetitem7);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(400, 170, 501, 261));
        QFont font;
        font.setFamily(QStringLiteral("JetBrains Mono"));
        font.setPointSize(10);
        tableWidget->setFont(font);
        tableWidget->setShowGrid(true);
        tableWidget->setSortingEnabled(true);
        tableWidget->horizontalHeader()->setCascadingSectionResizes(true);
        tableWidget->horizontalHeader()->setDefaultSectionSize(62);
        tableWidget->horizontalHeader()->setMinimumSectionSize(50);
        tableWidget->verticalHeader()->setVisible(false);
        tableWidget->verticalHeader()->setDefaultSectionSize(10);
        tableWidget->verticalHeader()->setHighlightSections(false);
        tableWidget->verticalHeader()->setMinimumSectionSize(10);
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
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
        stats_2->setFrameShape(QFrame::NoFrame);
        addFeature_2 = new QFrame(page_2);
        addFeature_2->setObjectName(QStringLiteral("addFeature_2"));
        addFeature_2->setGeometry(QRect(10, 10, 371, 201));
        addFeature_2->setFrameShape(QFrame::NoFrame);
        featureBar_2 = new QFrame(page_2);
        featureBar_2->setObjectName(QStringLiteral("featureBar_2"));
        featureBar_2->setGeometry(QRect(400, 10, 501, 61));
        featureBar_2->setStyleSheet(QStringLiteral(""));
        featureBar_2->setFrameShape(QFrame::NoFrame);
        add_2 = new QPushButton(featureBar_2);
        add_2->setObjectName(QStringLiteral("add_2"));
        add_2->setGeometry(QRect(30, 10, 41, 41));
        add_2->setCursor(QCursor(Qt::PointingHandCursor));
        add_2->setIcon(icon);
        add_2->setIconSize(QSize(60, 60));
        del_2 = new QPushButton(featureBar_2);
        del_2->setObjectName(QStringLiteral("del_2"));
        del_2->setGeometry(QRect(130, 10, 41, 41));
        del_2->setCursor(QCursor(Qt::PointingHandCursor));
        del_2->setIcon(icon1);
        del_2->setIconSize(QSize(40, 40));
        update_2 = new QPushButton(featureBar_2);
        update_2->setObjectName(QStringLiteral("update_2"));
        update_2->setGeometry(QRect(330, 10, 41, 41));
        update_2->setCursor(QCursor(Qt::PointingHandCursor));
        update_2->setIcon(icon2);
        update_2->setIconSize(QSize(60, 60));
        pdf_2 = new QPushButton(featureBar_2);
        pdf_2->setObjectName(QStringLiteral("pdf_2"));
        pdf_2->setGeometry(QRect(430, 10, 41, 41));
        pdf_2->setCursor(QCursor(Qt::PointingHandCursor));
        pdf_2->setIcon(icon3);
        pdf_2->setIconSize(QSize(50, 50));
        sort_2 = new QPushButton(featureBar_2);
        sort_2->setObjectName(QStringLiteral("sort_2"));
        sort_2->setGeometry(QRect(230, 10, 41, 41));
        sort_2->setCursor(QCursor(Qt::PointingHandCursor));
        sort_2->setIcon(icon4);
        sort_2->setIconSize(QSize(50, 50));
        tableClient = new QTableWidget(page_2);
        if (tableClient->columnCount() < 7)
            tableClient->setColumnCount(7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableClient->setHorizontalHeaderItem(0, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableClient->setHorizontalHeaderItem(1, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableClient->setHorizontalHeaderItem(2, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tableClient->setHorizontalHeaderItem(3, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        tableClient->setHorizontalHeaderItem(4, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        tableClient->setHorizontalHeaderItem(5, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        tableClient->setHorizontalHeaderItem(6, __qtablewidgetitem14);
        tableClient->setObjectName(QStringLiteral("tableClient"));
        tableClient->setGeometry(QRect(400, 170, 501, 261));
        tableClient->setFont(font);
        tableClient->setShowGrid(true);
        tableClient->setSortingEnabled(true);
        tableClient->horizontalHeader()->setDefaultSectionSize(62);
        tableClient->horizontalHeader()->setMinimumSectionSize(50);
        tableClient->verticalHeader()->setVisible(false);
        tableClient->verticalHeader()->setDefaultSectionSize(10);
        tableClient->verticalHeader()->setHighlightSections(false);
        tableClient->verticalHeader()->setMinimumSectionSize(10);
        stackedWidget->addWidget(page_2);
        page_3 = new QWidget();
        page_3->setObjectName(QStringLiteral("page_3"));
        addFeature_3 = new QFrame(page_3);
        addFeature_3->setObjectName(QStringLiteral("addFeature_3"));
        addFeature_3->setGeometry(QRect(10, 10, 371, 201));
        addFeature_3->setFrameShape(QFrame::NoFrame);
        stats_3 = new QFrame(page_3);
        stats_3->setObjectName(QStringLiteral("stats_3"));
        stats_3->setGeometry(QRect(10, 230, 371, 231));
        stats_3->setFrameShape(QFrame::NoFrame);
        readBox_3 = new QListWidget(page_3);
        readBox_3->setObjectName(QStringLiteral("readBox_3"));
        readBox_3->setGeometry(QRect(400, 90, 501, 371));
        searchBar_3 = new QLineEdit(page_3);
        searchBar_3->setObjectName(QStringLiteral("searchBar_3"));
        searchBar_3->setGeometry(QRect(620, 120, 241, 41));
        searchBar_3->setStyleSheet(QStringLiteral(""));
        searchBar_3->setClearButtonEnabled(true);
        featureBar_3 = new QFrame(page_3);
        featureBar_3->setObjectName(QStringLiteral("featureBar_3"));
        featureBar_3->setGeometry(QRect(400, 10, 501, 61));
        featureBar_3->setStyleSheet(QStringLiteral(""));
        featureBar_3->setFrameShape(QFrame::NoFrame);
        add_3 = new QPushButton(featureBar_3);
        add_3->setObjectName(QStringLiteral("add_3"));
        add_3->setGeometry(QRect(30, 10, 41, 41));
        add_3->setCursor(QCursor(Qt::PointingHandCursor));
        add_3->setIcon(icon);
        add_3->setIconSize(QSize(60, 60));
        del_3 = new QPushButton(featureBar_3);
        del_3->setObjectName(QStringLiteral("del_3"));
        del_3->setGeometry(QRect(130, 10, 41, 41));
        del_3->setCursor(QCursor(Qt::PointingHandCursor));
        del_3->setIcon(icon1);
        del_3->setIconSize(QSize(40, 40));
        update_3 = new QPushButton(featureBar_3);
        update_3->setObjectName(QStringLiteral("update_3"));
        update_3->setGeometry(QRect(330, 10, 41, 41));
        update_3->setCursor(QCursor(Qt::PointingHandCursor));
        update_3->setIcon(icon2);
        update_3->setIconSize(QSize(60, 60));
        pdf_3 = new QPushButton(featureBar_3);
        pdf_3->setObjectName(QStringLiteral("pdf_3"));
        pdf_3->setGeometry(QRect(430, 10, 41, 41));
        pdf_3->setCursor(QCursor(Qt::PointingHandCursor));
        pdf_3->setIcon(icon3);
        pdf_3->setIconSize(QSize(50, 50));
        sort_3 = new QPushButton(featureBar_3);
        sort_3->setObjectName(QStringLiteral("sort_3"));
        sort_3->setGeometry(QRect(230, 10, 41, 41));
        sort_3->setCursor(QCursor(Qt::PointingHandCursor));
        sort_3->setIcon(icon4);
        sort_3->setIconSize(QSize(50, 50));
        tableWidget_3 = new QTableWidget(page_3);
        if (tableWidget_3->columnCount() < 8)
            tableWidget_3->setColumnCount(8);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        tableWidget_3->setHorizontalHeaderItem(0, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        tableWidget_3->setHorizontalHeaderItem(1, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        tableWidget_3->setHorizontalHeaderItem(2, __qtablewidgetitem17);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        tableWidget_3->setHorizontalHeaderItem(3, __qtablewidgetitem18);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        tableWidget_3->setHorizontalHeaderItem(4, __qtablewidgetitem19);
        QTableWidgetItem *__qtablewidgetitem20 = new QTableWidgetItem();
        tableWidget_3->setHorizontalHeaderItem(5, __qtablewidgetitem20);
        QTableWidgetItem *__qtablewidgetitem21 = new QTableWidgetItem();
        tableWidget_3->setHorizontalHeaderItem(6, __qtablewidgetitem21);
        QTableWidgetItem *__qtablewidgetitem22 = new QTableWidgetItem();
        tableWidget_3->setHorizontalHeaderItem(7, __qtablewidgetitem22);
        tableWidget_3->setObjectName(QStringLiteral("tableWidget_3"));
        tableWidget_3->setGeometry(QRect(400, 170, 501, 261));
        tableWidget_3->setFont(font);
        tableWidget_3->setShowGrid(true);
        tableWidget_3->setSortingEnabled(true);
        tableWidget_3->horizontalHeader()->setDefaultSectionSize(62);
        tableWidget_3->horizontalHeader()->setMinimumSectionSize(50);
        tableWidget_3->verticalHeader()->setVisible(false);
        tableWidget_3->verticalHeader()->setDefaultSectionSize(10);
        tableWidget_3->verticalHeader()->setHighlightSections(false);
        tableWidget_3->verticalHeader()->setMinimumSectionSize(10);
        stackedWidget->addWidget(page_3);
        page_4 = new QWidget();
        page_4->setObjectName(QStringLiteral("page_4"));
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
        stats_4->setFrameShape(QFrame::NoFrame);
        addFeature_4 = new QFrame(page_4);
        addFeature_4->setObjectName(QStringLiteral("addFeature_4"));
        addFeature_4->setGeometry(QRect(10, 10, 371, 201));
        addFeature_4->setFrameShape(QFrame::NoFrame);
        featureBar_4 = new QFrame(page_4);
        featureBar_4->setObjectName(QStringLiteral("featureBar_4"));
        featureBar_4->setGeometry(QRect(400, 10, 501, 61));
        featureBar_4->setStyleSheet(QStringLiteral(""));
        featureBar_4->setFrameShape(QFrame::NoFrame);
        add_4 = new QPushButton(featureBar_4);
        add_4->setObjectName(QStringLiteral("add_4"));
        add_4->setGeometry(QRect(30, 10, 41, 41));
        add_4->setCursor(QCursor(Qt::PointingHandCursor));
        add_4->setIcon(icon);
        add_4->setIconSize(QSize(60, 60));
        del_4 = new QPushButton(featureBar_4);
        del_4->setObjectName(QStringLiteral("del_4"));
        del_4->setGeometry(QRect(130, 10, 41, 41));
        del_4->setCursor(QCursor(Qt::PointingHandCursor));
        del_4->setIcon(icon1);
        del_4->setIconSize(QSize(40, 40));
        update_4 = new QPushButton(featureBar_4);
        update_4->setObjectName(QStringLiteral("update_4"));
        update_4->setGeometry(QRect(330, 10, 41, 41));
        update_4->setCursor(QCursor(Qt::PointingHandCursor));
        update_4->setIcon(icon2);
        update_4->setIconSize(QSize(60, 60));
        pdf_4 = new QPushButton(featureBar_4);
        pdf_4->setObjectName(QStringLiteral("pdf_4"));
        pdf_4->setGeometry(QRect(430, 10, 41, 41));
        pdf_4->setCursor(QCursor(Qt::PointingHandCursor));
        pdf_4->setIcon(icon3);
        pdf_4->setIconSize(QSize(50, 50));
        sort_4 = new QPushButton(featureBar_4);
        sort_4->setObjectName(QStringLiteral("sort_4"));
        sort_4->setGeometry(QRect(230, 10, 41, 41));
        sort_4->setCursor(QCursor(Qt::PointingHandCursor));
        sort_4->setIcon(icon4);
        sort_4->setIconSize(QSize(50, 50));
        tableWidget_4 = new QTableWidget(page_4);
        if (tableWidget_4->columnCount() < 6)
            tableWidget_4->setColumnCount(6);
        QTableWidgetItem *__qtablewidgetitem23 = new QTableWidgetItem();
        tableWidget_4->setHorizontalHeaderItem(0, __qtablewidgetitem23);
        QTableWidgetItem *__qtablewidgetitem24 = new QTableWidgetItem();
        tableWidget_4->setHorizontalHeaderItem(1, __qtablewidgetitem24);
        QTableWidgetItem *__qtablewidgetitem25 = new QTableWidgetItem();
        tableWidget_4->setHorizontalHeaderItem(2, __qtablewidgetitem25);
        QTableWidgetItem *__qtablewidgetitem26 = new QTableWidgetItem();
        tableWidget_4->setHorizontalHeaderItem(3, __qtablewidgetitem26);
        QTableWidgetItem *__qtablewidgetitem27 = new QTableWidgetItem();
        tableWidget_4->setHorizontalHeaderItem(4, __qtablewidgetitem27);
        QTableWidgetItem *__qtablewidgetitem28 = new QTableWidgetItem();
        tableWidget_4->setHorizontalHeaderItem(5, __qtablewidgetitem28);
        tableWidget_4->setObjectName(QStringLiteral("tableWidget_4"));
        tableWidget_4->setGeometry(QRect(400, 170, 501, 261));
        tableWidget_4->setFont(font);
        tableWidget_4->setShowGrid(true);
        tableWidget_4->setSortingEnabled(true);
        tableWidget_4->horizontalHeader()->setDefaultSectionSize(62);
        tableWidget_4->horizontalHeader()->setMinimumSectionSize(50);
        tableWidget_4->verticalHeader()->setVisible(false);
        tableWidget_4->verticalHeader()->setDefaultSectionSize(10);
        tableWidget_4->verticalHeader()->setHighlightSections(false);
        tableWidget_4->verticalHeader()->setMinimumSectionSize(10);
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

        stackedWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(Dashboard);
    } // setupUi

    void retranslateUi(QDialog *Dashboard)
    {
        Dashboard->setWindowTitle(QApplication::translate("Dashboard", "Dashboard", Q_NULLPTR));
        role->setPlaceholderText(QApplication::translate("Dashboard", "Role", Q_NULLPTR));
        logo->setText(QString());
        helloBar->setPlaceholderText(QApplication::translate("Dashboard", "Hello,First Name Last Name", Q_NULLPTR));
        add->setText(QString());
        del->setText(QString());
        update->setText(QString());
        pdf->setText(QString());
        sort->setText(QString());
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("Dashboard", " ID", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("Dashboard", "Email", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("Dashboard", "Role", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("Dashboard", "First Name", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("Dashboard", "Last Name", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("Dashboard", "Phone Number", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QApplication::translate("Dashboard", "Address", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QApplication::translate("Dashboard", "Date Of Birth", Q_NULLPTR));
        add_2->setText(QString());
        del_2->setText(QString());
        update_2->setText(QString());
        pdf_2->setText(QString());
        sort_2->setText(QString());
        QTableWidgetItem *___qtablewidgetitem8 = tableClient->horizontalHeaderItem(0);
        ___qtablewidgetitem8->setText(QApplication::translate("Dashboard", " ID", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem9 = tableClient->horizontalHeaderItem(1);
        ___qtablewidgetitem9->setText(QApplication::translate("Dashboard", "Email", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem10 = tableClient->horizontalHeaderItem(2);
        ___qtablewidgetitem10->setText(QApplication::translate("Dashboard", "First Name", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem11 = tableClient->horizontalHeaderItem(3);
        ___qtablewidgetitem11->setText(QApplication::translate("Dashboard", "Last Name", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem12 = tableClient->horizontalHeaderItem(4);
        ___qtablewidgetitem12->setText(QApplication::translate("Dashboard", "Address", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem13 = tableClient->horizontalHeaderItem(5);
        ___qtablewidgetitem13->setText(QApplication::translate("Dashboard", "Phone Number", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem14 = tableClient->horizontalHeaderItem(6);
        ___qtablewidgetitem14->setText(QApplication::translate("Dashboard", "Date Of Birth", Q_NULLPTR));
        add_3->setText(QString());
        del_3->setText(QString());
        update_3->setText(QString());
        pdf_3->setText(QString());
        sort_3->setText(QString());
        QTableWidgetItem *___qtablewidgetitem15 = tableWidget_3->horizontalHeaderItem(0);
        ___qtablewidgetitem15->setText(QApplication::translate("Dashboard", " ID", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem16 = tableWidget_3->horizontalHeaderItem(1);
        ___qtablewidgetitem16->setText(QApplication::translate("Dashboard", "User ID", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem17 = tableWidget_3->horizontalHeaderItem(2);
        ___qtablewidgetitem17->setText(QApplication::translate("Dashboard", "Client ID", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem18 = tableWidget_3->horizontalHeaderItem(3);
        ___qtablewidgetitem18->setText(QApplication::translate("Dashboard", "Premium Amount", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem19 = tableWidget_3->horizontalHeaderItem(4);
        ___qtablewidgetitem19->setText(QApplication::translate("Dashboard", "Effective Date", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem20 = tableWidget_3->horizontalHeaderItem(5);
        ___qtablewidgetitem20->setText(QApplication::translate("Dashboard", "Expiration Date", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem21 = tableWidget_3->horizontalHeaderItem(6);
        ___qtablewidgetitem21->setText(QApplication::translate("Dashboard", "Payment Status", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem22 = tableWidget_3->horizontalHeaderItem(7);
        ___qtablewidgetitem22->setText(QApplication::translate("Dashboard", "Type", Q_NULLPTR));
        add_4->setText(QString());
        del_4->setText(QString());
        update_4->setText(QString());
        pdf_4->setText(QString());
        sort_4->setText(QString());
        QTableWidgetItem *___qtablewidgetitem23 = tableWidget_4->horizontalHeaderItem(0);
        ___qtablewidgetitem23->setText(QApplication::translate("Dashboard", " ID", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem24 = tableWidget_4->horizontalHeaderItem(1);
        ___qtablewidgetitem24->setText(QApplication::translate("Dashboard", "Client ID", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem25 = tableWidget_4->horizontalHeaderItem(2);
        ___qtablewidgetitem25->setText(QApplication::translate("Dashboard", "Type", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem26 = tableWidget_4->horizontalHeaderItem(3);
        ___qtablewidgetitem26->setText(QApplication::translate("Dashboard", "Damage", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem27 = tableWidget_4->horizontalHeaderItem(4);
        ___qtablewidgetitem27->setText(QApplication::translate("Dashboard", "Date", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem28 = tableWidget_4->horizontalHeaderItem(5);
        ___qtablewidgetitem28->setText(QApplication::translate("Dashboard", "Location", Q_NULLPTR));
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
