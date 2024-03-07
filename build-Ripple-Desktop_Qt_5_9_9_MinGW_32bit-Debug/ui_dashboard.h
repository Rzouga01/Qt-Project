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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPlainTextEdit>
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
    QListWidget *readBoxClient;
    QLineEdit *searchBarClient;
    QFrame *CrudClient;
    QStackedWidget *StackedClient;
    QWidget *CreateClientPage;
    QFrame *CreateClient;
    QLineEdit *ClientCreateEmail;
    QLineEdit *ClientCreateFirstName;
    QLineEdit *ClientCreateLastName;
    QDateEdit *ClientCreateDob;
    QLineEdit *ClientCreateAddress;
    QLineEdit *ClientCreatePhoneNumber;
    QPushButton *ClientCreateButton;
    QPushButton *ClientCreateCancel;
    QPlainTextEdit *ClientCreateEmailLine;
    QPlainTextEdit *ClientCreateFirstNameLine;
    QPlainTextEdit *ClientCreateLastNameLine;
    QPlainTextEdit *ClientCreateAddressLine;
    QPlainTextEdit *ClientCreatePhoneNumberLine;
    QPlainTextEdit *ClientCreateDobLine;
    QWidget *UpdateClientPage;
    QFrame *UpdateClient;
    QLineEdit *ClientUpdateID;
    QLineEdit *ClientUpdateEmail;
    QLineEdit *ClientUpdateFirstName;
    QLineEdit *ClientUpdateLastName;
    QDateEdit *ClientUpdateDob;
    QLineEdit *ClientUpdateAddress;
    QLineEdit *ClientUpdatePhoneNumber;
    QPushButton *ClientUpdateButton;
    QPushButton *ClientUpdateCancel;
    QPlainTextEdit *ClientUpdateIDLine;
    QPlainTextEdit *ClientUpdateEmailLine;
    QPlainTextEdit *ClientUpdateFirstNameLine;
    QPlainTextEdit *ClientUpdateLastNameLine;
    QPlainTextEdit *ClientUpdateAddressLine;
    QPlainTextEdit *ClientUpdatePhoneNumberLine;
    QPlainTextEdit *ClientUpdateDobLine;
    QWidget *DeleteClientPage;
    QFrame *DeleteClient;
    QLineEdit *ClientDeleteID;
    QPushButton *ClientDeleteButton;
    QPushButton *ClientDeleteCancel;
    QPlainTextEdit *ClientDeleteIDLine;
    QFrame *statsClient;
    QFrame *featureBarClient;
    QPushButton *deleteClient;
    QPushButton *updateClient;
    QPushButton *pdfClient;
    QPushButton *sortClient;
    QPushButton *addClient;
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
    QListWidget *readAccident;
    QLineEdit *searchAccident;
    QFrame *CrudAccident;
    QStackedWidget *StackedAccident;
    QWidget *CreateAccident;
    QFrame *FrameCreateAccident;
    QLabel *AccidentCreateTypeline;
    QLineEdit *AccidentCreateType;
    QLineEdit *AccidentCreateDamage;
    QLineEdit *AccidentCreateDate;
    QLineEdit *AccidentCreateLocation;
    QLabel *AccidentCreateDamageline;
    QLabel *AccidentCreateDateline;
    QLabel *AccidentCreateLocationline;
    QLabel *AccidentCreateClientIDline;
    QLabel *AccidentCreateIDline;
    QLineEdit *AccidentCreateID;
    QPushButton *AccidentSubmit;
    QPushButton *AccidentCancel;
    QComboBox *AccidentCreateClientID;
    QWidget *DeleteAccident;
    QFrame *FrameCreateAccident_2;
    QLabel *AccidentDeleteIDline;
    QLineEdit *AccidentDeleteID;
    QPushButton *AccidentDelete;
    QWidget *UpdateAccident;
    QFrame *frame_3;
    QLabel *AccidentUpdateIDline;
    QLabel *AccidentUpdateClientIDline;
    QLabel *AccidentUpdateTypeline;
    QLabel *AccidentUpdateDamageline;
    QLabel *AccidentUpdateDateline;
    QLabel *AccidentUpdateLocationline;
    QLineEdit *AccidentUpdateID;
    QLineEdit *AccidentUpdateType;
    QLineEdit *AccidentUpdateDamage;
    QLineEdit *AccidentUpdateDate;
    QLineEdit *AccidentUpdateLocation;
    QPushButton *AccidentUpdate;
    QComboBox *AccidentUpdateClientID;
    QFrame *StatsAccident;
    QFrame *featureBarAccident;
    QPushButton *AddAccident;
    QPushButton *DeleteAccident_2;
    QPushButton *UpdateAccident_2;
    QPushButton *PdfAccident;
    QPushButton *SortAccident;
    QTableWidget *tableAccident;
    QPushButton *employees;
    QPushButton *clients;
    QPushButton *contracts;
    QPushButton *accidents;
    QPushButton *logoutButton;

    void setupUi(QDialog *Dashboard)
    {
        if (Dashboard->objectName().isEmpty())
            Dashboard->setObjectName(QStringLiteral("Dashboard"));
        Dashboard->resize(1500, 800);
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
"    background-color: #A"
                        "7C34E;\n"
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
"\n"
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
"#searchBar {\n"
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
"        border-"
                        "radius:15px;\n"
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
"\n"
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
"#add_3,\n"
"#del_3,\n"
"#pdf_3,\n"
"#update_3,\n"
"#sort_3,\n"
"#add_4,\n"
"#del_4,\n"
"#pdf_4,\n"
"#update_4,\n"
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
""
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
        frame->setGeometry(QRect(0, -1, 1500, 800));
        frame->setStyleSheet(QStringLiteral(""));
        frame->setFrameShape(QFrame::NoFrame);
        role = new QLineEdit(frame);
        role->setObjectName(QStringLiteral("role"));
        role->setGeometry(QRect(1160, 10, 281, 91));
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
        stackedWidget->setGeometry(QRect(330, 120, 1141, 841));
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
        icon.addFile(QStringLiteral("../../../../.designer/Resources/Icons/add.png"), QSize(), QIcon::Normal, QIcon::Off);
        add->setIcon(icon);
        add->setIconSize(QSize(60, 60));
        del = new QPushButton(featureBar);
        del->setObjectName(QStringLiteral("del"));
        del->setGeometry(QRect(130, 10, 41, 41));
        del->setCursor(QCursor(Qt::PointingHandCursor));
        QIcon icon1;
        icon1.addFile(QStringLiteral("../../../../.designer/Resources/Icons/delete.png"), QSize(), QIcon::Normal, QIcon::Off);
        del->setIcon(icon1);
        del->setIconSize(QSize(40, 40));
        update = new QPushButton(featureBar);
        update->setObjectName(QStringLiteral("update"));
        update->setGeometry(QRect(330, 10, 41, 41));
        update->setCursor(QCursor(Qt::PointingHandCursor));
        QIcon icon2;
        icon2.addFile(QStringLiteral("../../../../.designer/Resources/Icons/update.png"), QSize(), QIcon::Normal, QIcon::Off);
        update->setIcon(icon2);
        update->setIconSize(QSize(60, 60));
        pdf = new QPushButton(featureBar);
        pdf->setObjectName(QStringLiteral("pdf"));
        pdf->setGeometry(QRect(430, 10, 41, 41));
        pdf->setCursor(QCursor(Qt::PointingHandCursor));
        QIcon icon3;
        icon3.addFile(QStringLiteral("../../../../.designer/Resources/Icons/pdf.png"), QSize(), QIcon::Normal, QIcon::Off);
        pdf->setIcon(icon3);
        pdf->setIconSize(QSize(50, 50));
        sort = new QPushButton(featureBar);
        sort->setObjectName(QStringLiteral("sort"));
        sort->setGeometry(QRect(230, 10, 41, 41));
        sort->setCursor(QCursor(Qt::PointingHandCursor));
        QIcon icon4;
        icon4.addFile(QStringLiteral("../../../../.designer/Resources/Icons/sort.png"), QSize(), QIcon::Normal, QIcon::Off);
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
        page_2->setStyleSheet(QLatin1String("\n"
"#featureBarClient {\n"
"    background-color: white;\n"
"    border-radius: 25px;\n"
"}\n"
"\n"
"#CrudClient,#CreateClient,#UpdateClient,#DeleteClient {\n"
"    background-color: #A7C34E;\n"
"    border-radius: 25px;\n"
"}\n"
"\n"
"#statsClient {\n"
"    background-color: #A7C34E;\n"
"    border-radius: 25px;\n"
"}\n"
"\n"
"#readBoxClient{\n"
"    border: none;\n"
"    background-color: #A7C34E;\n"
"    border-radius: 25px;\n"
"}\n"
"\n"
"#searchBarClient{\n"
"     background-color: white;\n"
" border-radius: 20px;\n"
"}\n"
"\n"
"#addClient,\n"
"#deleteClient,\n"
"#pdfClient,\n"
"#updateClient,\n"
"#sortClient{\n"
"border: none;\n"
"    background-color: transparent;\n"
"\n"
"}\n"
"\n"
"\n"
"\n"
"\n"
"/*Create*/\n"
"\n"
"#ClientCreateEmailLine,\n"
"#ClientCreateFirstNameLine,\n"
"#ClientCreateLastNameLine,\n"
"#ClientCreateAddressLine,\n"
"#ClientCreatePhoneNumberLine,\n"
"#ClientCreateDobLine {\n"
"    background-color: #A7C34E;\n"
"    font-family: \"helvetica\";\n"
"    font-size: 14px;\n"
"    color: "
                        "white;\n"
"    font-style: bold;\n"
"}\n"
"\n"
"\n"
"#ClientCreateEmail,\n"
"#ClientCreateFirstName,\n"
"#ClientCreateLastName,\n"
"#ClientCreateAddress,\n"
"#ClientCreatePhoneNumber,\n"
"#ClientCreateDob {\n"
"    background-color: #171717;\n"
"    font-family: \"helvetica\";\n"
"    font-size: 14px;\n"
"    color: white;\n"
"    font-style: bold;\n"
"	border:none;\n"
"	border-radius:15px;\n"
"}\n"
"\n"
"\n"
"\n"
"/*Read*/\n"
"#tableClient {\n"
"    border-radius: 10px;\n"
"    border-collapse: collapse;\n"
"    width: 100%;\n"
"}\n"
"\n"
"#tableClient th,\n"
"#tableClient td {\n"
"    border: 1px solid #ddd; \n"
"    padding: 8px;\n"
"    text-align: left;\n"
"}\n"
"\n"
"#tableClient td {\n"
"color:black;\n"
"}\n"
"\n"
"/*Update*/\n"
"\n"
"#ClientUpdateIDLine,\n"
"#ClientUpdateEmailLine,\n"
"#ClientUpdateFirstNameLine,\n"
"#ClientUpdateLastNameLine,\n"
"#ClientUpdateAddressLine,\n"
"#ClientUpdatePhoneNumberLine,\n"
"#ClientUpdateDobLine {\n"
"    background-color: #A7C34E;\n"
"    font-family: \"helvetica\";"
                        "\n"
"    font-size: 14px;\n"
"    color: white;\n"
"    font-style: bold;\n"
"}\n"
"\n"
"#ClientUpdateID,\n"
"#ClientUpdateEmail,\n"
"#ClientUpdateFirstName,\n"
"#ClientUpdateLastName,\n"
"#ClientUpdateAddress,\n"
"#ClientUpdatePhoneNumber,\n"
"#ClientUpdateDob {\n"
"    background-color: #171717;\n"
"    font-family: \"helvetica\";\n"
"    font-size: 14px;\n"
"    color: white;\n"
"    font-style: bold;\n"
"	border:none;\n"
"	border-radius:15px;\n"
"}\n"
"\n"
"/*Delete*/\n"
"\n"
"\n"
"#ClientDeleteIDLine\n"
" {\n"
"    background-color: #A7C34E;\n"
"    font-family: \"helvetica\";\n"
"    font-size: 14px;\n"
"    color: white;\n"
"    font-style: bold;\n"
"}\n"
"\n"
"#ClientDeleteID\n"
" {\n"
"    background-color: #171717;\n"
"    font-family: \"helvetica\";\n"
"    font-size: 14px;\n"
"    color: white;\n"
"    font-style: bold;\n"
"	border:none;\n"
"	border-radius:15px;\n"
"}"));
        readBoxClient = new QListWidget(page_2);
        readBoxClient->setObjectName(QStringLiteral("readBoxClient"));
        readBoxClient->setGeometry(QRect(420, 100, 711, 561));
        searchBarClient = new QLineEdit(page_2);
        searchBarClient->setObjectName(QStringLiteral("searchBarClient"));
        searchBarClient->setGeometry(QRect(720, 120, 391, 41));
        searchBarClient->setStyleSheet(QStringLiteral(""));
        searchBarClient->setClearButtonEnabled(true);
        CrudClient = new QFrame(page_2);
        CrudClient->setObjectName(QStringLiteral("CrudClient"));
        CrudClient->setGeometry(QRect(10, 230, 371, 431));
        CrudClient->setFrameShape(QFrame::NoFrame);
        StackedClient = new QStackedWidget(CrudClient);
        StackedClient->setObjectName(QStringLiteral("StackedClient"));
        StackedClient->setGeometry(QRect(-20, 0, 391, 431));
        CreateClientPage = new QWidget();
        CreateClientPage->setObjectName(QStringLiteral("CreateClientPage"));
        CreateClient = new QFrame(CreateClientPage);
        CreateClient->setObjectName(QStringLiteral("CreateClient"));
        CreateClient->setGeometry(QRect(20, 0, 371, 431));
        CreateClient->setFrameShape(QFrame::StyledPanel);
        CreateClient->setFrameShadow(QFrame::Raised);
        ClientCreateEmail = new QLineEdit(CreateClient);
        ClientCreateEmail->setObjectName(QStringLiteral("ClientCreateEmail"));
        ClientCreateEmail->setGeometry(QRect(190, 50, 151, 31));
        ClientCreateFirstName = new QLineEdit(CreateClient);
        ClientCreateFirstName->setObjectName(QStringLiteral("ClientCreateFirstName"));
        ClientCreateFirstName->setGeometry(QRect(190, 100, 151, 31));
        ClientCreateLastName = new QLineEdit(CreateClient);
        ClientCreateLastName->setObjectName(QStringLiteral("ClientCreateLastName"));
        ClientCreateLastName->setGeometry(QRect(190, 150, 151, 31));
        ClientCreateDob = new QDateEdit(CreateClient);
        ClientCreateDob->setObjectName(QStringLiteral("ClientCreateDob"));
        ClientCreateDob->setGeometry(QRect(190, 300, 151, 31));
        ClientCreateAddress = new QLineEdit(CreateClient);
        ClientCreateAddress->setObjectName(QStringLiteral("ClientCreateAddress"));
        ClientCreateAddress->setGeometry(QRect(190, 200, 151, 31));
        ClientCreatePhoneNumber = new QLineEdit(CreateClient);
        ClientCreatePhoneNumber->setObjectName(QStringLiteral("ClientCreatePhoneNumber"));
        ClientCreatePhoneNumber->setGeometry(QRect(190, 250, 151, 31));
        ClientCreateButton = new QPushButton(CreateClient);
        ClientCreateButton->setObjectName(QStringLiteral("ClientCreateButton"));
        ClientCreateButton->setGeometry(QRect(60, 380, 80, 24));
        ClientCreateCancel = new QPushButton(CreateClient);
        ClientCreateCancel->setObjectName(QStringLiteral("ClientCreateCancel"));
        ClientCreateCancel->setGeometry(QRect(230, 380, 80, 24));
        ClientCreateEmailLine = new QPlainTextEdit(CreateClient);
        ClientCreateEmailLine->setObjectName(QStringLiteral("ClientCreateEmailLine"));
        ClientCreateEmailLine->setGeometry(QRect(50, 50, 104, 31));
        ClientCreateEmailLine->setTextInteractionFlags(Qt::NoTextInteraction);
        ClientCreateFirstNameLine = new QPlainTextEdit(CreateClient);
        ClientCreateFirstNameLine->setObjectName(QStringLiteral("ClientCreateFirstNameLine"));
        ClientCreateFirstNameLine->setGeometry(QRect(50, 100, 104, 31));
        ClientCreateFirstNameLine->setTextInteractionFlags(Qt::NoTextInteraction);
        ClientCreateLastNameLine = new QPlainTextEdit(CreateClient);
        ClientCreateLastNameLine->setObjectName(QStringLiteral("ClientCreateLastNameLine"));
        ClientCreateLastNameLine->setGeometry(QRect(50, 150, 104, 31));
        ClientCreateLastNameLine->setTextInteractionFlags(Qt::NoTextInteraction);
        ClientCreateAddressLine = new QPlainTextEdit(CreateClient);
        ClientCreateAddressLine->setObjectName(QStringLiteral("ClientCreateAddressLine"));
        ClientCreateAddressLine->setGeometry(QRect(50, 200, 104, 31));
        ClientCreateAddressLine->setTextInteractionFlags(Qt::NoTextInteraction);
        ClientCreatePhoneNumberLine = new QPlainTextEdit(CreateClient);
        ClientCreatePhoneNumberLine->setObjectName(QStringLiteral("ClientCreatePhoneNumberLine"));
        ClientCreatePhoneNumberLine->setGeometry(QRect(50, 250, 104, 31));
        ClientCreatePhoneNumberLine->setTextInteractionFlags(Qt::NoTextInteraction);
        ClientCreateDobLine = new QPlainTextEdit(CreateClient);
        ClientCreateDobLine->setObjectName(QStringLiteral("ClientCreateDobLine"));
        ClientCreateDobLine->setGeometry(QRect(50, 300, 104, 31));
        ClientCreateDobLine->setTextInteractionFlags(Qt::NoTextInteraction);
        StackedClient->addWidget(CreateClientPage);
        UpdateClientPage = new QWidget();
        UpdateClientPage->setObjectName(QStringLiteral("UpdateClientPage"));
        UpdateClient = new QFrame(UpdateClientPage);
        UpdateClient->setObjectName(QStringLiteral("UpdateClient"));
        UpdateClient->setGeometry(QRect(20, 0, 371, 431));
        UpdateClient->setFrameShape(QFrame::StyledPanel);
        UpdateClient->setFrameShadow(QFrame::Raised);
        ClientUpdateID = new QLineEdit(UpdateClient);
        ClientUpdateID->setObjectName(QStringLiteral("ClientUpdateID"));
        ClientUpdateID->setGeometry(QRect(190, 30, 151, 31));
        ClientUpdateEmail = new QLineEdit(UpdateClient);
        ClientUpdateEmail->setObjectName(QStringLiteral("ClientUpdateEmail"));
        ClientUpdateEmail->setGeometry(QRect(190, 80, 151, 31));
        ClientUpdateFirstName = new QLineEdit(UpdateClient);
        ClientUpdateFirstName->setObjectName(QStringLiteral("ClientUpdateFirstName"));
        ClientUpdateFirstName->setGeometry(QRect(190, 130, 151, 31));
        ClientUpdateLastName = new QLineEdit(UpdateClient);
        ClientUpdateLastName->setObjectName(QStringLiteral("ClientUpdateLastName"));
        ClientUpdateLastName->setGeometry(QRect(190, 180, 151, 31));
        ClientUpdateDob = new QDateEdit(UpdateClient);
        ClientUpdateDob->setObjectName(QStringLiteral("ClientUpdateDob"));
        ClientUpdateDob->setGeometry(QRect(190, 330, 151, 31));
        ClientUpdateAddress = new QLineEdit(UpdateClient);
        ClientUpdateAddress->setObjectName(QStringLiteral("ClientUpdateAddress"));
        ClientUpdateAddress->setGeometry(QRect(190, 230, 151, 31));
        ClientUpdatePhoneNumber = new QLineEdit(UpdateClient);
        ClientUpdatePhoneNumber->setObjectName(QStringLiteral("ClientUpdatePhoneNumber"));
        ClientUpdatePhoneNumber->setGeometry(QRect(190, 280, 151, 31));
        ClientUpdateButton = new QPushButton(UpdateClient);
        ClientUpdateButton->setObjectName(QStringLiteral("ClientUpdateButton"));
        ClientUpdateButton->setGeometry(QRect(60, 380, 80, 24));
        ClientUpdateCancel = new QPushButton(UpdateClient);
        ClientUpdateCancel->setObjectName(QStringLiteral("ClientUpdateCancel"));
        ClientUpdateCancel->setGeometry(QRect(230, 380, 80, 24));
        ClientUpdateIDLine = new QPlainTextEdit(UpdateClient);
        ClientUpdateIDLine->setObjectName(QStringLiteral("ClientUpdateIDLine"));
        ClientUpdateIDLine->setGeometry(QRect(50, 30, 104, 31));
        ClientUpdateIDLine->setTextInteractionFlags(Qt::NoTextInteraction);
        ClientUpdateEmailLine = new QPlainTextEdit(UpdateClient);
        ClientUpdateEmailLine->setObjectName(QStringLiteral("ClientUpdateEmailLine"));
        ClientUpdateEmailLine->setGeometry(QRect(50, 80, 104, 31));
        ClientUpdateEmailLine->setTextInteractionFlags(Qt::NoTextInteraction);
        ClientUpdateFirstNameLine = new QPlainTextEdit(UpdateClient);
        ClientUpdateFirstNameLine->setObjectName(QStringLiteral("ClientUpdateFirstNameLine"));
        ClientUpdateFirstNameLine->setGeometry(QRect(50, 130, 104, 31));
        ClientUpdateFirstNameLine->setTextInteractionFlags(Qt::NoTextInteraction);
        ClientUpdateLastNameLine = new QPlainTextEdit(UpdateClient);
        ClientUpdateLastNameLine->setObjectName(QStringLiteral("ClientUpdateLastNameLine"));
        ClientUpdateLastNameLine->setGeometry(QRect(50, 180, 104, 31));
        ClientUpdateLastNameLine->setTextInteractionFlags(Qt::NoTextInteraction);
        ClientUpdateAddressLine = new QPlainTextEdit(UpdateClient);
        ClientUpdateAddressLine->setObjectName(QStringLiteral("ClientUpdateAddressLine"));
        ClientUpdateAddressLine->setGeometry(QRect(50, 230, 104, 31));
        ClientUpdateAddressLine->setTextInteractionFlags(Qt::NoTextInteraction);
        ClientUpdatePhoneNumberLine = new QPlainTextEdit(UpdateClient);
        ClientUpdatePhoneNumberLine->setObjectName(QStringLiteral("ClientUpdatePhoneNumberLine"));
        ClientUpdatePhoneNumberLine->setGeometry(QRect(50, 280, 104, 31));
        ClientUpdatePhoneNumberLine->setTextInteractionFlags(Qt::NoTextInteraction);
        ClientUpdateDobLine = new QPlainTextEdit(UpdateClient);
        ClientUpdateDobLine->setObjectName(QStringLiteral("ClientUpdateDobLine"));
        ClientUpdateDobLine->setGeometry(QRect(50, 330, 104, 31));
        ClientUpdateDobLine->setTextInteractionFlags(Qt::NoTextInteraction);
        StackedClient->addWidget(UpdateClientPage);
        DeleteClientPage = new QWidget();
        DeleteClientPage->setObjectName(QStringLiteral("DeleteClientPage"));
        DeleteClient = new QFrame(DeleteClientPage);
        DeleteClient->setObjectName(QStringLiteral("DeleteClient"));
        DeleteClient->setGeometry(QRect(20, 0, 371, 431));
        DeleteClient->setFrameShape(QFrame::StyledPanel);
        DeleteClient->setFrameShadow(QFrame::Raised);
        ClientDeleteID = new QLineEdit(DeleteClient);
        ClientDeleteID->setObjectName(QStringLiteral("ClientDeleteID"));
        ClientDeleteID->setGeometry(QRect(190, 30, 151, 31));
        ClientDeleteButton = new QPushButton(DeleteClient);
        ClientDeleteButton->setObjectName(QStringLiteral("ClientDeleteButton"));
        ClientDeleteButton->setGeometry(QRect(60, 380, 80, 24));
        ClientDeleteCancel = new QPushButton(DeleteClient);
        ClientDeleteCancel->setObjectName(QStringLiteral("ClientDeleteCancel"));
        ClientDeleteCancel->setGeometry(QRect(230, 380, 80, 24));
        ClientDeleteIDLine = new QPlainTextEdit(DeleteClient);
        ClientDeleteIDLine->setObjectName(QStringLiteral("ClientDeleteIDLine"));
        ClientDeleteIDLine->setGeometry(QRect(50, 30, 104, 31));
        ClientDeleteIDLine->setTextInteractionFlags(Qt::NoTextInteraction);
        StackedClient->addWidget(DeleteClientPage);
        statsClient = new QFrame(page_2);
        statsClient->setObjectName(QStringLiteral("statsClient"));
        statsClient->setGeometry(QRect(10, 10, 371, 201));
        statsClient->setFrameShape(QFrame::NoFrame);
        featureBarClient = new QFrame(page_2);
        featureBarClient->setObjectName(QStringLiteral("featureBarClient"));
        featureBarClient->setGeometry(QRect(620, 20, 501, 61));
        featureBarClient->setStyleSheet(QStringLiteral(""));
        featureBarClient->setFrameShape(QFrame::NoFrame);
        deleteClient = new QPushButton(featureBarClient);
        deleteClient->setObjectName(QStringLiteral("deleteClient"));
        deleteClient->setGeometry(QRect(130, 10, 41, 41));
        deleteClient->setCursor(QCursor(Qt::PointingHandCursor));
        QIcon icon5;
        icon5.addFile(QStringLiteral("../Resources/Icons/delete.png"), QSize(), QIcon::Normal, QIcon::Off);
        deleteClient->setIcon(icon5);
        deleteClient->setIconSize(QSize(40, 40));
        updateClient = new QPushButton(featureBarClient);
        updateClient->setObjectName(QStringLiteral("updateClient"));
        updateClient->setGeometry(QRect(330, 10, 41, 41));
        updateClient->setCursor(QCursor(Qt::PointingHandCursor));
        QIcon icon6;
        icon6.addFile(QStringLiteral("../Resources/Icons/update.png"), QSize(), QIcon::Normal, QIcon::Off);
        updateClient->setIcon(icon6);
        updateClient->setIconSize(QSize(60, 60));
        pdfClient = new QPushButton(featureBarClient);
        pdfClient->setObjectName(QStringLiteral("pdfClient"));
        pdfClient->setGeometry(QRect(430, 10, 41, 41));
        pdfClient->setCursor(QCursor(Qt::PointingHandCursor));
        QIcon icon7;
        icon7.addFile(QStringLiteral("../Resources/Icons/pdf.png"), QSize(), QIcon::Normal, QIcon::Off);
        pdfClient->setIcon(icon7);
        pdfClient->setIconSize(QSize(50, 50));
        sortClient = new QPushButton(featureBarClient);
        sortClient->setObjectName(QStringLiteral("sortClient"));
        sortClient->setGeometry(QRect(230, 10, 41, 41));
        sortClient->setCursor(QCursor(Qt::PointingHandCursor));
        QIcon icon8;
        icon8.addFile(QStringLiteral("../Resources/Icons/sort.png"), QSize(), QIcon::Normal, QIcon::Off);
        sortClient->setIcon(icon8);
        sortClient->setIconSize(QSize(50, 50));
        addClient = new QPushButton(featureBarClient);
        addClient->setObjectName(QStringLiteral("addClient"));
        addClient->setGeometry(QRect(30, 10, 41, 41));
        addClient->setCursor(QCursor(Qt::PointingHandCursor));
        QIcon icon9;
        icon9.addFile(QStringLiteral("../Resources/Icons/add.png"), QSize(), QIcon::Normal, QIcon::Off);
        addClient->setIcon(icon9);
        addClient->setIconSize(QSize(60, 60));
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
        tableClient->setGeometry(QRect(430, 180, 681, 461));
        tableClient->setFont(font);
        tableClient->setAutoFillBackground(false);
        tableClient->setShowGrid(true);
        tableClient->setSortingEnabled(true);
        tableClient->horizontalHeader()->setDefaultSectionSize(66);
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
        page_4->setStyleSheet(QLatin1String("/* Apply styles to the featureBar_4 */\n"
"#CrudAccident {\n"
"    background-color: white;\n"
"    border-radius: 25px;\n"
"}\n"
"\n"
"/* Apply styles to the addFeature_4 */\n"
"#CrudAccident {\n"
"    background-color: #A7C34E;\n"
"    border-radius: 25px;\n"
"}\n"
"\n"
"/* Apply styles to the stats_4 */\n"
"#StatsAccident {\n"
"    background-color: #A7C34E;\n"
"    border-radius: 25px;\n"
"}\n"
"\n"
"/* Apply styles to the readBox_4 */\n"
"#readAccident {\n"
"    border: none;\n"
"    background-color: #A7C34E;\n"
"    border-radius: 25px;\n"
"}\n"
"\n"
"/* Apply styles to the searchBar_4 */\n"
"#searchAccident {\n"
"      background-color: white;\n"
"\n"
"}"));
        readAccident = new QListWidget(page_4);
        readAccident->setObjectName(QStringLiteral("readAccident"));
        readAccident->setGeometry(QRect(520, 110, 591, 541));
        searchAccident = new QLineEdit(page_4);
        searchAccident->setObjectName(QStringLiteral("searchAccident"));
        searchAccident->setGeometry(QRect(560, 140, 531, 41));
        searchAccident->setStyleSheet(QStringLiteral(""));
        searchAccident->setClearButtonEnabled(true);
        CrudAccident = new QFrame(page_4);
        CrudAccident->setObjectName(QStringLiteral("CrudAccident"));
        CrudAccident->setGeometry(QRect(30, 290, 471, 371));
        CrudAccident->setFrameShape(QFrame::NoFrame);
        StackedAccident = new QStackedWidget(CrudAccident);
        StackedAccident->setObjectName(QStringLiteral("StackedAccident"));
        StackedAccident->setGeometry(QRect(10, 20, 441, 341));
        CreateAccident = new QWidget();
        CreateAccident->setObjectName(QStringLiteral("CreateAccident"));
        FrameCreateAccident = new QFrame(CreateAccident);
        FrameCreateAccident->setObjectName(QStringLiteral("FrameCreateAccident"));
        FrameCreateAccident->setGeometry(QRect(0, 0, 451, 361));
        FrameCreateAccident->setFrameShape(QFrame::StyledPanel);
        FrameCreateAccident->setFrameShadow(QFrame::Raised);
        AccidentCreateTypeline = new QLabel(FrameCreateAccident);
        AccidentCreateTypeline->setObjectName(QStringLiteral("AccidentCreateTypeline"));
        AccidentCreateTypeline->setGeometry(QRect(60, 140, 56, 16));
        AccidentCreateTypeline->setStyleSheet(QLatin1String("QLabel{\n"
"color:white\n"
"}\n"
""));
        AccidentCreateType = new QLineEdit(FrameCreateAccident);
        AccidentCreateType->setObjectName(QStringLiteral("AccidentCreateType"));
        AccidentCreateType->setGeometry(QRect(190, 140, 113, 22));
        AccidentCreateDamage = new QLineEdit(FrameCreateAccident);
        AccidentCreateDamage->setObjectName(QStringLiteral("AccidentCreateDamage"));
        AccidentCreateDamage->setGeometry(QRect(190, 190, 113, 22));
        AccidentCreateDate = new QLineEdit(FrameCreateAccident);
        AccidentCreateDate->setObjectName(QStringLiteral("AccidentCreateDate"));
        AccidentCreateDate->setGeometry(QRect(190, 240, 113, 22));
        AccidentCreateLocation = new QLineEdit(FrameCreateAccident);
        AccidentCreateLocation->setObjectName(QStringLiteral("AccidentCreateLocation"));
        AccidentCreateLocation->setGeometry(QRect(190, 290, 113, 22));
        AccidentCreateDamageline = new QLabel(FrameCreateAccident);
        AccidentCreateDamageline->setObjectName(QStringLiteral("AccidentCreateDamageline"));
        AccidentCreateDamageline->setGeometry(QRect(60, 190, 56, 16));
        AccidentCreateDamageline->setStyleSheet(QLatin1String("QLabel{\n"
"color:white\n"
"}"));
        AccidentCreateDateline = new QLabel(FrameCreateAccident);
        AccidentCreateDateline->setObjectName(QStringLiteral("AccidentCreateDateline"));
        AccidentCreateDateline->setGeometry(QRect(60, 240, 56, 16));
        AccidentCreateDateline->setStyleSheet(QLatin1String("QLabel{\n"
"color:white\n"
"}"));
        AccidentCreateLocationline = new QLabel(FrameCreateAccident);
        AccidentCreateLocationline->setObjectName(QStringLiteral("AccidentCreateLocationline"));
        AccidentCreateLocationline->setGeometry(QRect(60, 290, 56, 16));
        AccidentCreateLocationline->setStyleSheet(QLatin1String("QLabel{\n"
"color:white\n"
"}"));
        AccidentCreateClientIDline = new QLabel(FrameCreateAccident);
        AccidentCreateClientIDline->setObjectName(QStringLiteral("AccidentCreateClientIDline"));
        AccidentCreateClientIDline->setGeometry(QRect(60, 100, 56, 16));
        AccidentCreateClientIDline->setStyleSheet(QLatin1String("QLabel \n"
"{color:white\n"
"}"));
        AccidentCreateIDline = new QLabel(FrameCreateAccident);
        AccidentCreateIDline->setObjectName(QStringLiteral("AccidentCreateIDline"));
        AccidentCreateIDline->setGeometry(QRect(60, 60, 56, 16));
        AccidentCreateIDline->setStyleSheet(QLatin1String("QLabel\n"
"{\n"
"color:white;\n"
"}"));
        AccidentCreateID = new QLineEdit(FrameCreateAccident);
        AccidentCreateID->setObjectName(QStringLiteral("AccidentCreateID"));
        AccidentCreateID->setGeometry(QRect(190, 60, 113, 22));
        AccidentSubmit = new QPushButton(FrameCreateAccident);
        AccidentSubmit->setObjectName(QStringLiteral("AccidentSubmit"));
        AccidentSubmit->setGeometry(QRect(362, 260, 71, 21));
        AccidentCancel = new QPushButton(FrameCreateAccident);
        AccidentCancel->setObjectName(QStringLiteral("AccidentCancel"));
        AccidentCancel->setGeometry(QRect(360, 290, 71, 21));
        AccidentCreateClientID = new QComboBox(FrameCreateAccident);
        AccidentCreateClientID->setObjectName(QStringLiteral("AccidentCreateClientID"));
        AccidentCreateClientID->setGeometry(QRect(190, 100, 113, 22));
        StackedAccident->addWidget(CreateAccident);
        DeleteAccident = new QWidget();
        DeleteAccident->setObjectName(QStringLiteral("DeleteAccident"));
        FrameCreateAccident_2 = new QFrame(DeleteAccident);
        FrameCreateAccident_2->setObjectName(QStringLiteral("FrameCreateAccident_2"));
        FrameCreateAccident_2->setGeometry(QRect(-1, -1, 451, 351));
        FrameCreateAccident_2->setFrameShape(QFrame::StyledPanel);
        FrameCreateAccident_2->setFrameShadow(QFrame::Raised);
        AccidentDeleteIDline = new QLabel(FrameCreateAccident_2);
        AccidentDeleteIDline->setObjectName(QStringLiteral("AccidentDeleteIDline"));
        AccidentDeleteIDline->setGeometry(QRect(50, 50, 56, 16));
        AccidentDeleteIDline->setStyleSheet(QLatin1String("QLabel{\n"
"color:white\n"
"}"));
        AccidentDeleteID = new QLineEdit(FrameCreateAccident_2);
        AccidentDeleteID->setObjectName(QStringLiteral("AccidentDeleteID"));
        AccidentDeleteID->setGeometry(QRect(110, 50, 113, 22));
        AccidentDelete = new QPushButton(FrameCreateAccident_2);
        AccidentDelete->setObjectName(QStringLiteral("AccidentDelete"));
        AccidentDelete->setGeometry(QRect(310, 50, 93, 28));
        StackedAccident->addWidget(DeleteAccident);
        UpdateAccident = new QWidget();
        UpdateAccident->setObjectName(QStringLiteral("UpdateAccident"));
        frame_3 = new QFrame(UpdateAccident);
        frame_3->setObjectName(QStringLiteral("frame_3"));
        frame_3->setGeometry(QRect(0, -1, 441, 341));
        frame_3->setStyleSheet(QStringLiteral(""));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        AccidentUpdateIDline = new QLabel(frame_3);
        AccidentUpdateIDline->setObjectName(QStringLiteral("AccidentUpdateIDline"));
        AccidentUpdateIDline->setGeometry(QRect(60, 40, 56, 16));
        AccidentUpdateIDline->setStyleSheet(QLatin1String("QLabel{\n"
"color:white\n"
"}"));
        AccidentUpdateClientIDline = new QLabel(frame_3);
        AccidentUpdateClientIDline->setObjectName(QStringLiteral("AccidentUpdateClientIDline"));
        AccidentUpdateClientIDline->setGeometry(QRect(60, 80, 56, 16));
        AccidentUpdateClientIDline->setStyleSheet(QLatin1String("QLabel{\n"
"color:white\n"
"}"));
        AccidentUpdateTypeline = new QLabel(frame_3);
        AccidentUpdateTypeline->setObjectName(QStringLiteral("AccidentUpdateTypeline"));
        AccidentUpdateTypeline->setGeometry(QRect(60, 120, 56, 16));
        AccidentUpdateTypeline->setStyleSheet(QLatin1String("QLabel{\n"
"color:white\n"
"}"));
        AccidentUpdateDamageline = new QLabel(frame_3);
        AccidentUpdateDamageline->setObjectName(QStringLiteral("AccidentUpdateDamageline"));
        AccidentUpdateDamageline->setGeometry(QRect(60, 160, 56, 16));
        AccidentUpdateDamageline->setStyleSheet(QLatin1String("QLabel{\n"
"color:white\n"
"}"));
        AccidentUpdateDateline = new QLabel(frame_3);
        AccidentUpdateDateline->setObjectName(QStringLiteral("AccidentUpdateDateline"));
        AccidentUpdateDateline->setGeometry(QRect(60, 200, 56, 16));
        AccidentUpdateDateline->setStyleSheet(QLatin1String("QLabel{\n"
"color:white\n"
"}"));
        AccidentUpdateLocationline = new QLabel(frame_3);
        AccidentUpdateLocationline->setObjectName(QStringLiteral("AccidentUpdateLocationline"));
        AccidentUpdateLocationline->setGeometry(QRect(60, 240, 56, 16));
        AccidentUpdateLocationline->setStyleSheet(QLatin1String("QLabel{\n"
"color:white\n"
"}"));
        AccidentUpdateID = new QLineEdit(frame_3);
        AccidentUpdateID->setObjectName(QStringLiteral("AccidentUpdateID"));
        AccidentUpdateID->setGeometry(QRect(160, 40, 113, 22));
        AccidentUpdateType = new QLineEdit(frame_3);
        AccidentUpdateType->setObjectName(QStringLiteral("AccidentUpdateType"));
        AccidentUpdateType->setGeometry(QRect(160, 120, 113, 22));
        AccidentUpdateDamage = new QLineEdit(frame_3);
        AccidentUpdateDamage->setObjectName(QStringLiteral("AccidentUpdateDamage"));
        AccidentUpdateDamage->setGeometry(QRect(160, 160, 113, 22));
        AccidentUpdateDate = new QLineEdit(frame_3);
        AccidentUpdateDate->setObjectName(QStringLiteral("AccidentUpdateDate"));
        AccidentUpdateDate->setGeometry(QRect(160, 200, 113, 22));
        AccidentUpdateLocation = new QLineEdit(frame_3);
        AccidentUpdateLocation->setObjectName(QStringLiteral("AccidentUpdateLocation"));
        AccidentUpdateLocation->setGeometry(QRect(160, 240, 113, 22));
        AccidentUpdate = new QPushButton(frame_3);
        AccidentUpdate->setObjectName(QStringLiteral("AccidentUpdate"));
        AccidentUpdate->setGeometry(QRect(330, 260, 93, 28));
        AccidentUpdateClientID = new QComboBox(frame_3);
        AccidentUpdateClientID->setObjectName(QStringLiteral("AccidentUpdateClientID"));
        AccidentUpdateClientID->setGeometry(QRect(160, 80, 113, 22));
        StackedAccident->addWidget(UpdateAccident);
        StatsAccident = new QFrame(page_4);
        StatsAccident->setObjectName(QStringLiteral("StatsAccident"));
        StatsAccident->setGeometry(QRect(10, 10, 481, 251));
        StatsAccident->setFrameShape(QFrame::NoFrame);
        featureBarAccident = new QFrame(page_4);
        featureBarAccident->setObjectName(QStringLiteral("featureBarAccident"));
        featureBarAccident->setGeometry(QRect(620, 30, 501, 61));
        featureBarAccident->setStyleSheet(QStringLiteral(""));
        featureBarAccident->setFrameShape(QFrame::NoFrame);
        AddAccident = new QPushButton(featureBarAccident);
        AddAccident->setObjectName(QStringLiteral("AddAccident"));
        AddAccident->setGeometry(QRect(30, 10, 41, 41));
        AddAccident->setCursor(QCursor(Qt::PointingHandCursor));
        AddAccident->setIcon(icon9);
        AddAccident->setIconSize(QSize(60, 60));
        DeleteAccident_2 = new QPushButton(featureBarAccident);
        DeleteAccident_2->setObjectName(QStringLiteral("DeleteAccident_2"));
        DeleteAccident_2->setGeometry(QRect(130, 10, 41, 41));
        DeleteAccident_2->setCursor(QCursor(Qt::PointingHandCursor));
        DeleteAccident_2->setIcon(icon5);
        DeleteAccident_2->setIconSize(QSize(40, 40));
        UpdateAccident_2 = new QPushButton(featureBarAccident);
        UpdateAccident_2->setObjectName(QStringLiteral("UpdateAccident_2"));
        UpdateAccident_2->setGeometry(QRect(330, 10, 41, 41));
        UpdateAccident_2->setCursor(QCursor(Qt::PointingHandCursor));
        UpdateAccident_2->setIcon(icon6);
        UpdateAccident_2->setIconSize(QSize(60, 60));
        PdfAccident = new QPushButton(featureBarAccident);
        PdfAccident->setObjectName(QStringLiteral("PdfAccident"));
        PdfAccident->setGeometry(QRect(430, 10, 41, 41));
        PdfAccident->setCursor(QCursor(Qt::PointingHandCursor));
        PdfAccident->setIcon(icon7);
        PdfAccident->setIconSize(QSize(50, 50));
        SortAccident = new QPushButton(featureBarAccident);
        SortAccident->setObjectName(QStringLiteral("SortAccident"));
        SortAccident->setGeometry(QRect(230, 10, 41, 41));
        SortAccident->setCursor(QCursor(Qt::PointingHandCursor));
        SortAccident->setIcon(icon8);
        SortAccident->setIconSize(QSize(50, 50));
        tableAccident = new QTableWidget(page_4);
        if (tableAccident->columnCount() < 6)
            tableAccident->setColumnCount(6);
        QTableWidgetItem *__qtablewidgetitem23 = new QTableWidgetItem();
        tableAccident->setHorizontalHeaderItem(0, __qtablewidgetitem23);
        QTableWidgetItem *__qtablewidgetitem24 = new QTableWidgetItem();
        tableAccident->setHorizontalHeaderItem(1, __qtablewidgetitem24);
        QTableWidgetItem *__qtablewidgetitem25 = new QTableWidgetItem();
        tableAccident->setHorizontalHeaderItem(2, __qtablewidgetitem25);
        QTableWidgetItem *__qtablewidgetitem26 = new QTableWidgetItem();
        tableAccident->setHorizontalHeaderItem(3, __qtablewidgetitem26);
        QTableWidgetItem *__qtablewidgetitem27 = new QTableWidgetItem();
        tableAccident->setHorizontalHeaderItem(4, __qtablewidgetitem27);
        QTableWidgetItem *__qtablewidgetitem28 = new QTableWidgetItem();
        tableAccident->setHorizontalHeaderItem(5, __qtablewidgetitem28);
        tableAccident->setObjectName(QStringLiteral("tableAccident"));
        tableAccident->setGeometry(QRect(540, 210, 551, 431));
        tableAccident->setFont(font);
        tableAccident->setShowGrid(true);
        tableAccident->setSortingEnabled(true);
        tableAccident->horizontalHeader()->setDefaultSectionSize(62);
        tableAccident->horizontalHeader()->setMinimumSectionSize(50);
        tableAccident->verticalHeader()->setVisible(false);
        tableAccident->verticalHeader()->setDefaultSectionSize(10);
        tableAccident->verticalHeader()->setHighlightSections(false);
        tableAccident->verticalHeader()->setMinimumSectionSize(10);
        stackedWidget->addWidget(page_4);
        employees = new QPushButton(frame);
        employees->setObjectName(QStringLiteral("employees"));
        employees->setGeometry(QRect(50, 210, 200, 50));
        employees->setCursor(QCursor(Qt::PointingHandCursor));
        clients = new QPushButton(frame);
        clients->setObjectName(QStringLiteral("clients"));
        clients->setGeometry(QRect(50, 310, 200, 50));
        clients->setCursor(QCursor(Qt::PointingHandCursor));
        contracts = new QPushButton(frame);
        contracts->setObjectName(QStringLiteral("contracts"));
        contracts->setGeometry(QRect(50, 410, 200, 50));
        contracts->setCursor(QCursor(Qt::PointingHandCursor));
        accidents = new QPushButton(frame);
        accidents->setObjectName(QStringLiteral("accidents"));
        accidents->setGeometry(QRect(50, 510, 200, 50));
        accidents->setCursor(QCursor(Qt::PointingHandCursor));
        logoutButton = new QPushButton(frame);
        logoutButton->setObjectName(QStringLiteral("logoutButton"));
        logoutButton->setGeometry(QRect(50, 610, 200, 50));
        logoutButton->setCursor(QCursor(Qt::PointingHandCursor));
        logoutButton->setAutoFillBackground(false);
        logoutButton->setStyleSheet(QStringLiteral(""));
        QIcon icon10;
        icon10.addFile(QStringLiteral("../Resources/Icons/logout.png"), QSize(), QIcon::Normal, QIcon::Off);
        logoutButton->setIcon(icon10);
        logoutButton->setIconSize(QSize(20, 20));

        retranslateUi(Dashboard);

        stackedWidget->setCurrentIndex(3);
        StackedClient->setCurrentIndex(2);
        StackedAccident->setCurrentIndex(0);


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
        ClientCreateEmail->setPlaceholderText(QString());
        ClientCreateButton->setText(QApplication::translate("Dashboard", "Create Client", Q_NULLPTR));
        ClientCreateCancel->setText(QApplication::translate("Dashboard", "Cancel", Q_NULLPTR));
        ClientCreateEmailLine->setPlainText(QApplication::translate("Dashboard", "Email", Q_NULLPTR));
        ClientCreateFirstNameLine->setPlainText(QApplication::translate("Dashboard", "First Name", Q_NULLPTR));
        ClientCreateLastNameLine->setPlainText(QApplication::translate("Dashboard", "Last Name", Q_NULLPTR));
        ClientCreateAddressLine->setPlainText(QApplication::translate("Dashboard", "Address", Q_NULLPTR));
        ClientCreatePhoneNumberLine->setPlainText(QApplication::translate("Dashboard", "Phone Number", Q_NULLPTR));
        ClientCreateDobLine->setPlainText(QApplication::translate("Dashboard", "Date Of Birth", Q_NULLPTR));
        ClientUpdateButton->setText(QApplication::translate("Dashboard", "Update Client", Q_NULLPTR));
        ClientUpdateCancel->setText(QApplication::translate("Dashboard", "Cancel", Q_NULLPTR));
        ClientUpdateIDLine->setPlainText(QApplication::translate("Dashboard", "ID", Q_NULLPTR));
        ClientUpdateEmailLine->setPlainText(QApplication::translate("Dashboard", "Email", Q_NULLPTR));
        ClientUpdateFirstNameLine->setPlainText(QApplication::translate("Dashboard", "First Name", Q_NULLPTR));
        ClientUpdateLastNameLine->setPlainText(QApplication::translate("Dashboard", "Last Name", Q_NULLPTR));
        ClientUpdateAddressLine->setPlainText(QApplication::translate("Dashboard", "Address", Q_NULLPTR));
        ClientUpdatePhoneNumberLine->setPlainText(QApplication::translate("Dashboard", "Phone Number", Q_NULLPTR));
        ClientUpdateDobLine->setPlainText(QApplication::translate("Dashboard", "Date Of Birth", Q_NULLPTR));
        ClientDeleteButton->setText(QApplication::translate("Dashboard", "Delete Client", Q_NULLPTR));
        ClientDeleteCancel->setText(QApplication::translate("Dashboard", "Cancel", Q_NULLPTR));
        ClientDeleteIDLine->setPlainText(QApplication::translate("Dashboard", "ID", Q_NULLPTR));
        deleteClient->setText(QString());
        updateClient->setText(QString());
        pdfClient->setText(QString());
        sortClient->setText(QString());
        addClient->setText(QString());
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
        AccidentCreateTypeline->setText(QApplication::translate("Dashboard", "Type", Q_NULLPTR));
        AccidentCreateDamageline->setText(QApplication::translate("Dashboard", "Damage", Q_NULLPTR));
        AccidentCreateDateline->setText(QApplication::translate("Dashboard", "Date", Q_NULLPTR));
        AccidentCreateLocationline->setText(QApplication::translate("Dashboard", "Location", Q_NULLPTR));
        AccidentCreateClientIDline->setText(QApplication::translate("Dashboard", "Client ID", Q_NULLPTR));
        AccidentCreateIDline->setText(QApplication::translate("Dashboard", "ID", Q_NULLPTR));
        AccidentSubmit->setText(QApplication::translate("Dashboard", "SUBMIT", Q_NULLPTR));
        AccidentCancel->setText(QApplication::translate("Dashboard", "CANCEL", Q_NULLPTR));
        AccidentDeleteIDline->setText(QApplication::translate("Dashboard", "ID", Q_NULLPTR));
        AccidentDelete->setText(QApplication::translate("Dashboard", "delete", Q_NULLPTR));
        AccidentUpdateIDline->setText(QApplication::translate("Dashboard", "ID", Q_NULLPTR));
        AccidentUpdateClientIDline->setText(QApplication::translate("Dashboard", "Client_ID", Q_NULLPTR));
        AccidentUpdateTypeline->setText(QApplication::translate("Dashboard", "Type", Q_NULLPTR));
        AccidentUpdateDamageline->setText(QApplication::translate("Dashboard", "Damage", Q_NULLPTR));
        AccidentUpdateDateline->setText(QApplication::translate("Dashboard", "date", Q_NULLPTR));
        AccidentUpdateLocationline->setText(QApplication::translate("Dashboard", "location", Q_NULLPTR));
        AccidentUpdate->setText(QApplication::translate("Dashboard", "update", Q_NULLPTR));
        AddAccident->setText(QString());
        DeleteAccident_2->setText(QString());
        UpdateAccident_2->setText(QString());
        PdfAccident->setText(QString());
        SortAccident->setText(QString());
        QTableWidgetItem *___qtablewidgetitem23 = tableAccident->horizontalHeaderItem(0);
        ___qtablewidgetitem23->setText(QApplication::translate("Dashboard", " ID", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem24 = tableAccident->horizontalHeaderItem(1);
        ___qtablewidgetitem24->setText(QApplication::translate("Dashboard", "Client ID", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem25 = tableAccident->horizontalHeaderItem(2);
        ___qtablewidgetitem25->setText(QApplication::translate("Dashboard", "Type", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem26 = tableAccident->horizontalHeaderItem(3);
        ___qtablewidgetitem26->setText(QApplication::translate("Dashboard", "Damage", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem27 = tableAccident->horizontalHeaderItem(4);
        ___qtablewidgetitem27->setText(QApplication::translate("Dashboard", "Date", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem28 = tableAccident->horizontalHeaderItem(5);
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
