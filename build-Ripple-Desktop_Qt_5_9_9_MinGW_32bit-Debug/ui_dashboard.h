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
    QFrame *CrudContract;
    QStackedWidget *StackContract;
    QWidget *page_5;
    QFrame *CreateContract;
    QLineEdit *LineEditExpirationDate;
    QLineEdit *LineEditContractId;
    QLineEdit *LineEditUserId;
    QLineEdit *LineEditClientId;
    QLineEdit *LineEditPremiumAmount;
    QLineEdit *lineEdit_8;
    QLineEdit *LineEditPaymentstatus;
    QLabel *LabelUserId;
    QLabel *LabelClientId;
    QLabel *LabelPremiumAmount;
    QLabel *LabelEffectiveDate;
    QLabel *LabelExpirationDate;
    QLabel *LabelPaymentStatus;
    QLabel *LabelType;
    QPushButton *CancelContract;
    QPushButton *CreateContractButton;
    QWidget *page_6;
    QFrame *DeleteContract;
    QLabel *LabelContractId;
    QLineEdit *LineEditContractID;
    QPushButton *pushButtonCancel;
    QPushButton *pushButtonDelete;
    QListWidget *readBoxContract;
    QLineEdit *searchBarContract;
    QFrame *featureBarContract;
    QPushButton *addContract;
    QPushButton *delContract;
    QPushButton *updateContract;
    QPushButton *pdfContract;
    QPushButton *sortContract;
    QTableWidget *tableWidgetContract;
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
"\n"
"\n"
"/* Apply styles to the featureBar_4 */\n"
"#featureBar_4 {\n"
"    background-color: white;\n"
"    border-radius: 25px;\n"
"}\n"
"\n"
"/* Apply styles to the addFeature_4 */\n"
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
"    background"
                        "-color: #A7C34E;\n"
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
"        border-rad"
                        "ius:15px;\n"
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
"\n"
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
"\n"
"/* Set icons for the buttons */\n"
"#add::ic"
                        "on {\n"
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
        if (tableClient->columnCount() < 9)
            tableClient->setColumnCount(9);
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
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        tableClient->setHorizontalHeaderItem(7, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        tableClient->setHorizontalHeaderItem(8, __qtablewidgetitem16);
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
        page_3->setStyleSheet(QLatin1String("/* Apply styles to the featureBarContract */\n"
"#featureBarContract {\n"
"    background-color: white;\n"
"    border-radius: 25px;\n"
"}\n"
"\n"
"/* Apply styles to the addContract */\n"
"#CrudContract {\n"
"    background-color: #A7C34E;\n"
"    border-radius: 25px;\n"
"}\n"
"\n"
"/* Apply styles to the statsContract */\n"
"#statsContract {\n"
"    background-color: #A7C34E;\n"
"    border-radius: 25px;\n"
"}\n"
"\n"
"/* Apply styles to the readBoxContract */\n"
"#readBoxContract {\n"
"    border: none;\n"
"    background-color: #A7C34E;\n"
"    border-radius: 25px;\n"
"}\n"
"\n"
"/* Apply styles to the searchBarContract */\n"
"#searchBarContract {\n"
"    background-color: white;\n"
"\n"
"\n"
"}\n"
"\n"
"\n"
"#searchBarContract {\n"
"    border-radius: 20px;\n"
"}\n"
"\n"
"#CreateContract{\n"
"	background-color: #A7C34E;\n"
"    border-radius: 25px;\n"
"}\n"
"\n"
"#DeleteContract{\n"
"		background-color: #A7C34E;\n"
"   	    border-radius: 25px;\n"
"}"));
        CrudContract = new QFrame(page_3);
        CrudContract->setObjectName(QStringLiteral("CrudContract"));
        CrudContract->setGeometry(QRect(10, 10, 371, 641));
        CrudContract->setFrameShape(QFrame::NoFrame);
        StackContract = new QStackedWidget(CrudContract);
        StackContract->setObjectName(QStringLiteral("StackContract"));
        StackContract->setGeometry(QRect(0, 0, 371, 641));
        page_5 = new QWidget();
        page_5->setObjectName(QStringLiteral("page_5"));
        CreateContract = new QFrame(page_5);
        CreateContract->setObjectName(QStringLiteral("CreateContract"));
        CreateContract->setGeometry(QRect(10, 10, 351, 621));
        CreateContract->setFrameShape(QFrame::StyledPanel);
        CreateContract->setFrameShadow(QFrame::Raised);
        LineEditExpirationDate = new QLineEdit(CreateContract);
        LineEditExpirationDate->setObjectName(QStringLiteral("LineEditExpirationDate"));
        LineEditExpirationDate->setGeometry(QRect(220, 50, 113, 24));
        LineEditContractId = new QLineEdit(CreateContract);
        LineEditContractId->setObjectName(QStringLiteral("LineEditContractId"));
        LineEditContractId->setGeometry(QRect(220, 120, 113, 24));
        LineEditUserId = new QLineEdit(CreateContract);
        LineEditUserId->setObjectName(QStringLiteral("LineEditUserId"));
        LineEditUserId->setGeometry(QRect(230, 190, 113, 24));
        LineEditClientId = new QLineEdit(CreateContract);
        LineEditClientId->setObjectName(QStringLiteral("LineEditClientId"));
        LineEditClientId->setGeometry(QRect(220, 270, 113, 24));
        LineEditPremiumAmount = new QLineEdit(CreateContract);
        LineEditPremiumAmount->setObjectName(QStringLiteral("LineEditPremiumAmount"));
        LineEditPremiumAmount->setGeometry(QRect(230, 340, 113, 24));
        lineEdit_8 = new QLineEdit(CreateContract);
        lineEdit_8->setObjectName(QStringLiteral("lineEdit_8"));
        lineEdit_8->setGeometry(QRect(220, 410, 113, 24));
        LineEditPaymentstatus = new QLineEdit(CreateContract);
        LineEditPaymentstatus->setObjectName(QStringLiteral("LineEditPaymentstatus"));
        LineEditPaymentstatus->setGeometry(QRect(220, 480, 113, 24));
        LabelUserId = new QLabel(CreateContract);
        LabelUserId->setObjectName(QStringLiteral("LabelUserId"));
        LabelUserId->setGeometry(QRect(50, 50, 51, 21));
        LabelClientId = new QLabel(CreateContract);
        LabelClientId->setObjectName(QStringLiteral("LabelClientId"));
        LabelClientId->setGeometry(QRect(40, 120, 71, 16));
        LabelPremiumAmount = new QLabel(CreateContract);
        LabelPremiumAmount->setObjectName(QStringLiteral("LabelPremiumAmount"));
        LabelPremiumAmount->setGeometry(QRect(30, 200, 121, 21));
        LabelEffectiveDate = new QLabel(CreateContract);
        LabelEffectiveDate->setObjectName(QStringLiteral("LabelEffectiveDate"));
        LabelEffectiveDate->setGeometry(QRect(40, 270, 121, 21));
        LabelExpirationDate = new QLabel(CreateContract);
        LabelExpirationDate->setObjectName(QStringLiteral("LabelExpirationDate"));
        LabelExpirationDate->setGeometry(QRect(40, 340, 121, 16));
        LabelPaymentStatus = new QLabel(CreateContract);
        LabelPaymentStatus->setObjectName(QStringLiteral("LabelPaymentStatus"));
        LabelPaymentStatus->setGeometry(QRect(40, 410, 121, 16));
        LabelType = new QLabel(CreateContract);
        LabelType->setObjectName(QStringLiteral("LabelType"));
        LabelType->setGeometry(QRect(50, 490, 56, 16));
        CancelContract = new QPushButton(CreateContract);
        CancelContract->setObjectName(QStringLiteral("CancelContract"));
        CancelContract->setGeometry(QRect(240, 550, 80, 25));
        CreateContractButton = new QPushButton(CreateContract);
        CreateContractButton->setObjectName(QStringLiteral("CreateContractButton"));
        CreateContractButton->setGeometry(QRect(30, 550, 101, 25));
        StackContract->addWidget(page_5);
        page_6 = new QWidget();
        page_6->setObjectName(QStringLiteral("page_6"));
        DeleteContract = new QFrame(page_6);
        DeleteContract->setObjectName(QStringLiteral("DeleteContract"));
        DeleteContract->setGeometry(QRect(10, 0, 351, 671));
        DeleteContract->setFrameShape(QFrame::StyledPanel);
        DeleteContract->setFrameShadow(QFrame::Raised);
        LabelContractId = new QLabel(DeleteContract);
        LabelContractId->setObjectName(QStringLiteral("LabelContractId"));
        LabelContractId->setGeometry(QRect(40, 50, 71, 21));
        LineEditContractID = new QLineEdit(DeleteContract);
        LineEditContractID->setObjectName(QStringLiteral("LineEditContractID"));
        LineEditContractID->setGeometry(QRect(210, 40, 113, 24));
        pushButtonCancel = new QPushButton(DeleteContract);
        pushButtonCancel->setObjectName(QStringLiteral("pushButtonCancel"));
        pushButtonCancel->setGeometry(QRect(240, 490, 80, 25));
        pushButtonDelete = new QPushButton(DeleteContract);
        pushButtonDelete->setObjectName(QStringLiteral("pushButtonDelete"));
        pushButtonDelete->setGeometry(QRect(50, 490, 80, 25));
        StackContract->addWidget(page_6);
        readBoxContract = new QListWidget(page_3);
        readBoxContract->setObjectName(QStringLiteral("readBoxContract"));
        readBoxContract->setGeometry(QRect(390, 80, 741, 581));
        searchBarContract = new QLineEdit(page_3);
        searchBarContract->setObjectName(QStringLiteral("searchBarContract"));
        searchBarContract->setGeometry(QRect(780, 120, 331, 41));
        searchBarContract->setStyleSheet(QStringLiteral(""));
        searchBarContract->setClearButtonEnabled(true);
        featureBarContract = new QFrame(page_3);
        featureBarContract->setObjectName(QStringLiteral("featureBarContract"));
        featureBarContract->setGeometry(QRect(620, 10, 501, 61));
        featureBarContract->setStyleSheet(QStringLiteral(""));
        featureBarContract->setFrameShape(QFrame::NoFrame);
        addContract = new QPushButton(featureBarContract);
        addContract->setObjectName(QStringLiteral("addContract"));
        addContract->setGeometry(QRect(30, 10, 41, 41));
        addContract->setCursor(QCursor(Qt::PointingHandCursor));
        addContract->setIcon(icon);
        addContract->setIconSize(QSize(60, 60));
        delContract = new QPushButton(featureBarContract);
        delContract->setObjectName(QStringLiteral("delContract"));
        delContract->setGeometry(QRect(130, 10, 41, 41));
        delContract->setCursor(QCursor(Qt::PointingHandCursor));
        delContract->setIcon(icon1);
        delContract->setIconSize(QSize(40, 40));
        updateContract = new QPushButton(featureBarContract);
        updateContract->setObjectName(QStringLiteral("updateContract"));
        updateContract->setGeometry(QRect(330, 10, 41, 41));
        updateContract->setCursor(QCursor(Qt::PointingHandCursor));
        updateContract->setIcon(icon2);
        updateContract->setIconSize(QSize(60, 60));
        pdfContract = new QPushButton(featureBarContract);
        pdfContract->setObjectName(QStringLiteral("pdfContract"));
        pdfContract->setGeometry(QRect(430, 10, 41, 41));
        pdfContract->setCursor(QCursor(Qt::PointingHandCursor));
        pdfContract->setIcon(icon3);
        pdfContract->setIconSize(QSize(50, 50));
        sortContract = new QPushButton(featureBarContract);
        sortContract->setObjectName(QStringLiteral("sortContract"));
        sortContract->setGeometry(QRect(230, 10, 41, 41));
        sortContract->setCursor(QCursor(Qt::PointingHandCursor));
        sortContract->setIcon(icon4);
        sortContract->setIconSize(QSize(50, 50));
        tableWidgetContract = new QTableWidget(page_3);
        if (tableWidgetContract->columnCount() < 8)
            tableWidgetContract->setColumnCount(8);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        tableWidgetContract->setHorizontalHeaderItem(0, __qtablewidgetitem17);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        tableWidgetContract->setHorizontalHeaderItem(1, __qtablewidgetitem18);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        tableWidgetContract->setHorizontalHeaderItem(2, __qtablewidgetitem19);
        QTableWidgetItem *__qtablewidgetitem20 = new QTableWidgetItem();
        tableWidgetContract->setHorizontalHeaderItem(3, __qtablewidgetitem20);
        QTableWidgetItem *__qtablewidgetitem21 = new QTableWidgetItem();
        tableWidgetContract->setHorizontalHeaderItem(4, __qtablewidgetitem21);
        QTableWidgetItem *__qtablewidgetitem22 = new QTableWidgetItem();
        tableWidgetContract->setHorizontalHeaderItem(5, __qtablewidgetitem22);
        QTableWidgetItem *__qtablewidgetitem23 = new QTableWidgetItem();
        tableWidgetContract->setHorizontalHeaderItem(6, __qtablewidgetitem23);
        QTableWidgetItem *__qtablewidgetitem24 = new QTableWidgetItem();
        tableWidgetContract->setHorizontalHeaderItem(7, __qtablewidgetitem24);
        tableWidgetContract->setObjectName(QStringLiteral("tableWidgetContract"));
        tableWidgetContract->setGeometry(QRect(400, 190, 721, 381));
        tableWidgetContract->setFont(font);
        tableWidgetContract->setShowGrid(true);
        tableWidgetContract->setSortingEnabled(true);
        tableWidgetContract->horizontalHeader()->setDefaultSectionSize(62);
        tableWidgetContract->horizontalHeader()->setMinimumSectionSize(50);
        tableWidgetContract->verticalHeader()->setVisible(false);
        tableWidgetContract->verticalHeader()->setDefaultSectionSize(10);
        tableWidgetContract->verticalHeader()->setHighlightSections(false);
        tableWidgetContract->verticalHeader()->setMinimumSectionSize(10);
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
        QTableWidgetItem *__qtablewidgetitem25 = new QTableWidgetItem();
        tableWidget_4->setHorizontalHeaderItem(0, __qtablewidgetitem25);
        QTableWidgetItem *__qtablewidgetitem26 = new QTableWidgetItem();
        tableWidget_4->setHorizontalHeaderItem(1, __qtablewidgetitem26);
        QTableWidgetItem *__qtablewidgetitem27 = new QTableWidgetItem();
        tableWidget_4->setHorizontalHeaderItem(2, __qtablewidgetitem27);
        QTableWidgetItem *__qtablewidgetitem28 = new QTableWidgetItem();
        tableWidget_4->setHorizontalHeaderItem(3, __qtablewidgetitem28);
        QTableWidgetItem *__qtablewidgetitem29 = new QTableWidgetItem();
        tableWidget_4->setHorizontalHeaderItem(4, __qtablewidgetitem29);
        QTableWidgetItem *__qtablewidgetitem30 = new QTableWidgetItem();
        tableWidget_4->setHorizontalHeaderItem(5, __qtablewidgetitem30);
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

        stackedWidget->setCurrentIndex(1);
        StackedClient->setCurrentIndex(1);
        StackContract->setCurrentIndex(0);


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
        QTableWidgetItem *___qtablewidgetitem15 = tableClient->horizontalHeaderItem(7);
        ___qtablewidgetitem15->setText(QApplication::translate("Dashboard", "Delete", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem16 = tableClient->horizontalHeaderItem(8);
        ___qtablewidgetitem16->setText(QApplication::translate("Dashboard", "Update", Q_NULLPTR));
        LabelUserId->setText(QApplication::translate("Dashboard", "USER_ID", Q_NULLPTR));
        LabelClientId->setText(QApplication::translate("Dashboard", "CLIENT_ID", Q_NULLPTR));
        LabelPremiumAmount->setText(QApplication::translate("Dashboard", "PREMIUM_AMOUNT", Q_NULLPTR));
        LabelEffectiveDate->setText(QApplication::translate("Dashboard", "EFFECTIVE_DATE", Q_NULLPTR));
        LabelExpirationDate->setText(QApplication::translate("Dashboard", "EXPIRATION_DATE", Q_NULLPTR));
        LabelPaymentStatus->setText(QApplication::translate("Dashboard", "PAYMENT_STATUS", Q_NULLPTR));
        LabelType->setText(QApplication::translate("Dashboard", "TYPE", Q_NULLPTR));
        CancelContract->setText(QApplication::translate("Dashboard", "Cancel", Q_NULLPTR));
        CreateContractButton->setText(QApplication::translate("Dashboard", "Create Contract", Q_NULLPTR));
        LabelContractId->setText(QApplication::translate("Dashboard", "Contract_Id", Q_NULLPTR));
        pushButtonCancel->setText(QApplication::translate("Dashboard", "Cancel", Q_NULLPTR));
        pushButtonDelete->setText(QApplication::translate("Dashboard", "PushButton", Q_NULLPTR));
        addContract->setText(QString());
        delContract->setText(QString());
        updateContract->setText(QString());
        pdfContract->setText(QString());
        sortContract->setText(QString());
        QTableWidgetItem *___qtablewidgetitem17 = tableWidgetContract->horizontalHeaderItem(0);
        ___qtablewidgetitem17->setText(QApplication::translate("Dashboard", " ID", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem18 = tableWidgetContract->horizontalHeaderItem(1);
        ___qtablewidgetitem18->setText(QApplication::translate("Dashboard", "User ID", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem19 = tableWidgetContract->horizontalHeaderItem(2);
        ___qtablewidgetitem19->setText(QApplication::translate("Dashboard", "Client ID", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem20 = tableWidgetContract->horizontalHeaderItem(3);
        ___qtablewidgetitem20->setText(QApplication::translate("Dashboard", "Premium Amount", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem21 = tableWidgetContract->horizontalHeaderItem(4);
        ___qtablewidgetitem21->setText(QApplication::translate("Dashboard", "Effective Date", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem22 = tableWidgetContract->horizontalHeaderItem(5);
        ___qtablewidgetitem22->setText(QApplication::translate("Dashboard", "Expiration Date", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem23 = tableWidgetContract->horizontalHeaderItem(6);
        ___qtablewidgetitem23->setText(QApplication::translate("Dashboard", "Payment Status", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem24 = tableWidgetContract->horizontalHeaderItem(7);
        ___qtablewidgetitem24->setText(QApplication::translate("Dashboard", "Type", Q_NULLPTR));
        add_4->setText(QString());
        del_4->setText(QString());
        update_4->setText(QString());
        pdf_4->setText(QString());
        sort_4->setText(QString());
        QTableWidgetItem *___qtablewidgetitem25 = tableWidget_4->horizontalHeaderItem(0);
        ___qtablewidgetitem25->setText(QApplication::translate("Dashboard", " ID", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem26 = tableWidget_4->horizontalHeaderItem(1);
        ___qtablewidgetitem26->setText(QApplication::translate("Dashboard", "Client ID", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem27 = tableWidget_4->horizontalHeaderItem(2);
        ___qtablewidgetitem27->setText(QApplication::translate("Dashboard", "Type", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem28 = tableWidget_4->horizontalHeaderItem(3);
        ___qtablewidgetitem28->setText(QApplication::translate("Dashboard", "Damage", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem29 = tableWidget_4->horizontalHeaderItem(4);
        ___qtablewidgetitem29->setText(QApplication::translate("Dashboard", "Date", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem30 = tableWidget_4->horizontalHeaderItem(5);
        ___qtablewidgetitem30->setText(QApplication::translate("Dashboard", "Location", Q_NULLPTR));
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
