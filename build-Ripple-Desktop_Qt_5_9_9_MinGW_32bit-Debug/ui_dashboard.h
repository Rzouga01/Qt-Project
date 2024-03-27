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
    QFrame *featureBarEmployee;
    QPushButton *addEmployee;
    QPushButton *deleteEmployee;
    QPushButton *updateEmployee;
    QPushButton *pdfEmployee;
    QPushButton *sortEmployee;
    QStackedWidget *CrudEmployee;
    QWidget *CreateEmployee;
    QLineEdit *EmployeeEmail_C;
    QPlainTextEdit *EmployeeLastNameText_C;
    QLineEdit *EmployeeAddress_C;
    QPlainTextEdit *EmployeeAddressText_C;
    QLineEdit *EmployeeFirstName_C;
    QLineEdit *EmployeePhoneNumber_C;
    QPushButton *EmployeeCreateBtn;
    QDateEdit *EmployeeDob_C;
    QLineEdit *EmployeeLastName_C;
    QPlainTextEdit *EmployeeEmailText_C;
    QPlainTextEdit *EmployeePhoneNumberText_C;
    QPlainTextEdit *EmployeeFirstNameText_C;
    QPlainTextEdit *EmployeeDobText_C;
    QComboBox *EmployeeRole_C;
    QPushButton *EmployeeCancelBtn_C;
    QPlainTextEdit *EmployeeRoleText_C;
    QLineEdit *EmployeePassword_C;
    QPlainTextEdit *EmployeePasswordText_C;
    QWidget *UpdateEmployee;
    QPlainTextEdit *EmployeeFirstNameText_U;
    QPlainTextEdit *EmployeePhoneNumberText_U;
    QLineEdit *EmployeeFirstName_U;
    QLineEdit *EmployeeLastName_U;
    QDateEdit *EmployeeDob_U;
    QPlainTextEdit *EmployeePasswordText_U;
    QLineEdit *EmployeePhoneNumber_U;
    QComboBox *EmployeeRole_U;
    QLineEdit *EmployeeEmail_U;
    QPlainTextEdit *EmployeeDobText_U;
    QPlainTextEdit *EmployeeRoleText_U;
    QPlainTextEdit *EmployeeAddressText_U;
    QPlainTextEdit *EmployeeEmailText_U;
    QPushButton *EmployeeUpdateBtn;
    QPlainTextEdit *EmployeeLastNameText_U;
    QLineEdit *EmployeePassword_U;
    QLineEdit *EmployeeAddress_U;
    QPushButton *EmployeeCancelBtn_U;
    QLineEdit *EmployeeSelectIDText_U;
    QComboBox *EmployeeSelectID_U;
    QWidget *DeleteEmployee;
    QPushButton *EmployeeDeleteBtn;
    QComboBox *EmployeeSelectID_D;
    QLineEdit *EmployeeSelectIDText_D;
    QPushButton *EmployeeCancelBtn_D;
    QListWidget *readBoxEmployee;
    QLineEdit *searchBarEmployee;
    QTableWidget *tableEmployee;
    QFrame *statsEmployee;
    QComboBox *EmployeeSelectStats;
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
    QFrame *QRCodeClient;
    QComboBox *QRCodeClientCombo;
    QLineEdit *QRCodeClientInput;
    QPlainTextEdit *QRCodeClientTitle;
    QPlainTextEdit *QRCodeClientLabel;
    QPushButton *QRCodeClientGenerate;
    QPushButton *QRCodeClientCancel;
    QFrame *featureBarClient;
    QPushButton *deleteClient;
    QPushButton *updateClient;
    QPushButton *pdfClient;
    QPushButton *sortClient;
    QPushButton *addClient;
    QPushButton *pieChartClient;
    QTableWidget *tableClient;
    QWidget *page_3;
    QFrame *CrudContract;
    QStackedWidget *StackContract;
    QWidget *page_5;
    QFrame *CreateContract;
    QLineEdit *LineEditUserIdContract;
    QLineEdit *LineEditClientIdContract;
    QLineEdit *LineEditPremiumAmountContract;
    QLineEdit *lineEditTypeContract;
    QLineEdit *LineEditPaymentstatusContract;
    QLabel *LabelUserIdContract;
    QLabel *LabelClientIdContract;
    QLabel *LabelPremiumAmountContract;
    QLabel *LabelEffectiveDateContract;
    QLabel *LabelExpirationDateContract;
    QLabel *LabelPaymentStatusContract;
    QLabel *LabelTypeContract;
    QPushButton *CancelCreateContract;
    QPushButton *CreateContractButton;
    QDateEdit *dateEditEffectiveDateContract;
    QDateEdit *dateEditExpirationDateContract;
    QWidget *page_6;
    QFrame *DeleteContract;
    QLabel *LabelContractId;
    QLineEdit *LineEditContractID;
    QPushButton *CancelDeleteContract;
    QPushButton *DeleteContractButton;
    QWidget *page_7;
    QFrame *UpdateContract;
    QPushButton *UpdateContractButton;
    QPushButton *CancelUpdateContract;
    QLabel *LabelUserIdContractUpdate;
    QLabel *LabelClientIdContractUpdate;
    QLabel *LabelPremiumAmountContractUpdate;
    QLabel *LabelEffectiveDateContractUpdate;
    QLabel *LabelExpirationDateContractUpdate;
    QLabel *LabelPaymentStatusContractUpdate;
    QLabel *LabelTypeContractUpdate;
    QLineEdit *LineEditUserIdContractUpdate;
    QLineEdit *LineEditClientIdContractUpdate;
    QDateEdit *dateEditEffectiveDateContractUpdate;
    QDateEdit *dateEditExpirationDateContractUpdate;
    QLineEdit *LineEditPaymentstatusContractUpdate;
    QLineEdit *lineEditTypeContractUpdate;
    QLineEdit *LineEditPremiumAmountContractUpdate;
    QLineEdit *lineEditContractIDUpdate;
    QLabel *labelContractIDUpdate;
    QListWidget *readBoxContract;
    QLineEdit *searchBarContract;
    QFrame *featureBarContract;
    QPushButton *addContract;
    QPushButton *deleteContract;
    QPushButton *updateContract;
    QPushButton *pdfContract;
    QPushButton *sortContract;
    QPushButton *excelContract;
    QTableWidget *tableContract;
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
    QLineEdit *AccidentCreateLocation;
    QLabel *AccidentCreateDamageline;
    QLabel *AccidentCreateDateline;
    QLabel *AccidentCreateLocationline;
    QLabel *AccidentCreateClientIDline;
    QPushButton *AccidentSubmit;
    QPushButton *AccidentCancel;
    QComboBox *AccidentCreateClientID;
    QDateEdit *AccidentCreateDate;
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
    QLineEdit *AccidentUpdateLocation;
    QPushButton *AccidentUpdate;
    QComboBox *AccidentUpdateClientID;
    QDateEdit *AccidentUpdateDate;
    QFrame *StatsAccident;
    QFrame *featureBarAccident;
    QPushButton *addAccident;
    QPushButton *deleteAccident;
    QPushButton *updateAccident;
    QPushButton *pdfAccident;
    QPushButton *sortAccident;
    QPushButton *historyAccident;
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
        Dashboard->resize(1500, 872);
        Dashboard->setStyleSheet(QLatin1String(" QFrame {\n"
"     background-color:#171717;\n"
"     border:none;\n"
"}\n"
" #Dashboard {\n"
"     background-color: #171717;\n"
"}\n"
" #helloBar{\n"
"     border: none;\n"
"     background-color:#171717;\n"
"     font-size:30px;\n"
"     color:white;\n"
"     font-family:\"helvetica\" \n"
"}\n"
" #role{\n"
"     font-size:30px;\n"
"     background-color:#171717;\n"
"     color:white;\n"
"     border:none;\n"
"     font-family:\"helvetica\" \n"
"}\n"
" #stackedWidget {\n"
"     background-color: #171717;\n"
"}\n"
"\n"
" #logoutButton, #employees, #clients, #contracts, #accidents {\n"
"     font-size: 15px;\n"
"     font-weight: bold;\n"
"     color: white;\n"
"     background-color: #444444;\n"
"    ;\n"
"     border-radius:15px;\n"
"}\n"
" #logoutButton:hover, #employees:hover, #contracts:hover, #clients:hover, #accidents:hover {\n"
"     background-color: #333;\n"
"\n"
"}\n"
" QMessageBox {\n"
"     background-color: #333333;\n"
"     border: none;\n"
"}\n"
" QMessageBox QLabel {\n"
"     color: #FFFFFF;\n"
""
                        "}\n"
" QTableWidget {\n"
"     background-color: #444444;\n"
"     border: 1px solid #444444;\n"
"     color: #E0E1E3;\n"
"     border-radius: 4px;\n"
"}\n"
" "));
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
        stackedWidget->setGeometry(QRect(260, 120, 1231, 841));
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        page->setStyleSheet(QLatin1String("/* Feature Bar */\n"
"#featureBarEmployee {\n"
"    background-color: white;\n"
"    border-radius: 25px;\n"
"}\n"
"\n"
"/* CRUD Buttons */\n"
"#CrudEmployee,\n"
"#CreateEmployee,\n"
"#UpdateEmployee,\n"
"#DeleteEmployee {\n"
"    background-color: #A7C34E;\n"
"    border-radius: 25px;\n"
"}\n"
"\n"
"/* Stats Box  */\n"
"#statsEmployee {\n"
"    background-color: #A7C34E;\n"
"    border-radius: 25px;\n"
"}\n"
"\n"
"/* Read Box */\n"
"#readBoxEmployee {\n"
"    border: none;\n"
"    background-color: #A7C34E;\n"
"    border-radius: 25px;\n"
"}\n"
"\n"
"/* Search Bar */\n"
"#searchBarEmployee {\n"
"    background-color: white;\n"
"    border-radius: 20px;\n"
"}\n"
"\n"
"/* Action Buttons */\n"
"#addEmployee,\n"
"#deleteEmployee,\n"
"#pdfEmployee,\n"
"#updateEmployee,\n"
"#sortEmployee {\n"
"    border: none;\n"
"    background-color: transparent;\n"
"}\n"
"\n"
"/* Header styling */\n"
"QHeaderView {\n"
"    background-color: #444444;\n"
"    border: 0;\n"
"    padding: 0;\n"
"    margin: 0;\n"
"    border-radius"
                        ": 0;\n"
"}\n"
"\n"
"/* Row hover styling */\n"
"QAbstractView:hover {\n"
"    border: 1px solid #444444;\n"
"    color: #E0E1E3;\n"
"}\n"
"\n"
"/* Selected row styling */\n"
"QAbstractView:selected {\n"
"    background: #444444;\n"
"    color: #E0E1E3;\n"
"}\n"
"\n"
"/* Corner button styling */\n"
"QTableCornerButton::section {\n"
"    background-color: #444444;\n"
"    border: 1px transparent #444444;\n"
"    border-radius: 0;\n"
"}\n"
"\n"
"/* Font size adjustment for table data */\n"
"QTableWidget QTableWidget {\n"
"    font-size: 10pt;\n"
"}\n"
"\n"
"/* Create and Update Combobox Items */\n"
"#EmployeeRole_C,\n"
"#EmployeeRole_U,\n"
"#EmployeeSelectID_U,\n"
"#EmployeeSelectID_D {\n"
"    background-color: #444444;\n"
"    font-family: \"Helvetica\";\n"
"    font-size: 12px;\n"
"    color: white;\n"
"    border: none;\n"
"    border-radius: 5px;\n"
"}\n"
"\n"
"#EmployeeRole_C QAbstractItemView,\n"
"#EmployeeRole_U QAbstractItemView,\n"
"#EmployeeSelectID_U QAbstractItemView,\n"
"#EmployeeSelectID_D QAbstrac"
                        "tItemView {\n"
"    color: white; \n"
"    background-color: #444444; \n"
"    selection-background-color: #A7C34E; \n"
"}\n"
"\n"
"/* Create and Update Text Inputs */\n"
"#EmployeeEmailText_C,\n"
"#EmployeePasswordText_C,\n"
"#EmployeeFirstNameText_C,\n"
"#EmployeeLastNameText_C,\n"
"#EmployeeAddressText_C,\n"
"#EmployeePhoneNumberText_C,\n"
"#EmployeeDobText_C,\n"
"#EmployeeRoleText_C,\n"
"#EmployeeSelectIDText_U,\n"
"#EmployeeEmailText_U,\n"
"#EmployeePasswordText_U,\n"
"#EmployeeFirstNameText_U,\n"
"#EmployeeLastNameText_U,\n"
"#EmployeeAddressText_U,\n"
"#EmployeePhoneNumberText_U,\n"
"#EmployeeDobText_U,\n"
"#EmployeeRoleText_U,\n"
"#EmployeeSelectIDText_D {\n"
"    border: none;\n"
"    background-color: transparent;\n"
"    font-family: \"Helvetica\";\n"
"    font-size: 14px;\n"
"    color: white;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"/* Create, Update, and Delete Buttons */\n"
"#EmployeeEmail_C,\n"
"#EmployeePassword_C,\n"
"#EmployeeFirstName_C,\n"
"#EmployeeLastName_C,\n"
"#EmployeeAddress_C,\n"
""
                        "#EmployeePhoneNumber_C,\n"
"#EmployeeDob_C,\n"
"#EmployeeRole_C,\n"
"#EmployeeSelectID_U,\n"
"#EmployeeEmail_U,\n"
"#EmployeePassword_U,\n"
"#EmployeeFirstName_U,\n"
"#EmployeeLastName_U,\n"
"#EmployeeAddress_U,\n"
"#EmployeePhoneNumber_U,\n"
"#EmployeeDob_U,\n"
"#EmployeeRole_U,\n"
"#EmployeeSelectID_D {\n"
"    background-color: #444444;\n"
"    font-family: \"Helvetica\";\n"
"    font-size: 14px;\n"
"    color: white;\n"
"    font-weight: bold;\n"
"    border: none;\n"
"    border-radius: 15px;\n"
"}\n"
"\n"
"/* Cancel and Create/Update/Delete Buttons */\n"
"#EmployeeCancelBtn_C,\n"
"#EmployeeCreateBtn,\n"
"#EmployeeCancelBtn_U,\n"
"#EmployeeUpdateBtn,\n"
"#EmployeeCancelBtn_D,\n"
"#EmployeeDeleteBtn {\n"
"    background-color: #444444;\n"
"    color: white;\n"
"    font-family: \"Helvetica\";\n"
"    font-size: 14px;\n"
"    font-weight: bold;\n"
"    border: none;\n"
"    border-radius: 15px;\n"
"    padding: 10px 20px;\n"
"    cursor: pointer;\n"
"    transition: background-color 0.3s ease;\n"
"}\n"
"\n"
""
                        "#EmployeeCancelBtn_C:hover,\n"
"#EmployeeCreateBtn:hover,\n"
"#EmployeeCancelBtn_U:hover,\n"
"#EmployeeUpdateBtn:hover,\n"
"#EmployeeCancelBtn_D:hover,\n"
"#EmployeeDeleteBtn:hover {\n"
"    background-color: #333333;\n"
"}\n"
"\n"
"/*Stats*/\n"
"#EmployeeSelectStats {\n"
"    background-color: #444444;\n"
"    border-radius: 5px;\n"
"    padding: 5px;\n"
"    color: #444444;\n"
"    font-size: 12px;\n"
"}"));
        featureBarEmployee = new QFrame(page);
        featureBarEmployee->setObjectName(QStringLiteral("featureBarEmployee"));
        featureBarEmployee->setGeometry(QRect(700, 20, 501, 61));
        featureBarEmployee->setStyleSheet(QStringLiteral(""));
        featureBarEmployee->setFrameShape(QFrame::NoFrame);
        addEmployee = new QPushButton(featureBarEmployee);
        addEmployee->setObjectName(QStringLiteral("addEmployee"));
        addEmployee->setGeometry(QRect(30, 10, 41, 41));
        addEmployee->setCursor(QCursor(Qt::PointingHandCursor));
        QIcon icon;
        icon.addFile(QStringLiteral("../Resources/Icons/add.png"), QSize(), QIcon::Normal, QIcon::Off);
        addEmployee->setIcon(icon);
        addEmployee->setIconSize(QSize(60, 60));
        deleteEmployee = new QPushButton(featureBarEmployee);
        deleteEmployee->setObjectName(QStringLiteral("deleteEmployee"));
        deleteEmployee->setGeometry(QRect(130, 10, 41, 41));
        deleteEmployee->setCursor(QCursor(Qt::PointingHandCursor));
        QIcon icon1;
        icon1.addFile(QStringLiteral("../Resources/Icons/delete.png"), QSize(), QIcon::Normal, QIcon::Off);
        deleteEmployee->setIcon(icon1);
        deleteEmployee->setIconSize(QSize(40, 40));
        updateEmployee = new QPushButton(featureBarEmployee);
        updateEmployee->setObjectName(QStringLiteral("updateEmployee"));
        updateEmployee->setGeometry(QRect(330, 10, 41, 41));
        updateEmployee->setCursor(QCursor(Qt::PointingHandCursor));
        QIcon icon2;
        icon2.addFile(QStringLiteral("../Resources/Icons/update.png"), QSize(), QIcon::Normal, QIcon::Off);
        updateEmployee->setIcon(icon2);
        updateEmployee->setIconSize(QSize(60, 60));
        pdfEmployee = new QPushButton(featureBarEmployee);
        pdfEmployee->setObjectName(QStringLiteral("pdfEmployee"));
        pdfEmployee->setGeometry(QRect(430, 10, 41, 41));
        pdfEmployee->setCursor(QCursor(Qt::PointingHandCursor));
        QIcon icon3;
        icon3.addFile(QStringLiteral("../Resources/Icons/pdf.png"), QSize(), QIcon::Normal, QIcon::Off);
        pdfEmployee->setIcon(icon3);
        pdfEmployee->setIconSize(QSize(50, 50));
        sortEmployee = new QPushButton(featureBarEmployee);
        sortEmployee->setObjectName(QStringLiteral("sortEmployee"));
        sortEmployee->setGeometry(QRect(230, 10, 41, 41));
        sortEmployee->setCursor(QCursor(Qt::PointingHandCursor));
        QIcon icon4;
        icon4.addFile(QStringLiteral("../Resources/Icons/sort.png"), QSize(), QIcon::Normal, QIcon::Off);
        sortEmployee->setIcon(icon4);
        sortEmployee->setIconSize(QSize(50, 50));
        CrudEmployee = new QStackedWidget(page);
        CrudEmployee->setObjectName(QStringLiteral("CrudEmployee"));
        CrudEmployee->setGeometry(QRect(10, 240, 421, 431));
        CrudEmployee->setFrameShape(QFrame::NoFrame);
        CreateEmployee = new QWidget();
        CreateEmployee->setObjectName(QStringLiteral("CreateEmployee"));
        EmployeeEmail_C = new QLineEdit(CreateEmployee);
        EmployeeEmail_C->setObjectName(QStringLiteral("EmployeeEmail_C"));
        EmployeeEmail_C->setGeometry(QRect(44, 65, 160, 30));
        EmployeeLastNameText_C = new QPlainTextEdit(CreateEmployee);
        EmployeeLastNameText_C->setObjectName(QStringLiteral("EmployeeLastNameText_C"));
        EmployeeLastNameText_C->setGeometry(QRect(284, 115, 104, 31));
        EmployeeLastNameText_C->setTextInteractionFlags(Qt::NoTextInteraction);
        EmployeeAddress_C = new QLineEdit(CreateEmployee);
        EmployeeAddress_C->setObjectName(QStringLiteral("EmployeeAddress_C"));
        EmployeeAddress_C->setGeometry(QRect(44, 225, 160, 30));
        EmployeeAddressText_C = new QPlainTextEdit(CreateEmployee);
        EmployeeAddressText_C->setObjectName(QStringLiteral("EmployeeAddressText_C"));
        EmployeeAddressText_C->setGeometry(QRect(84, 195, 104, 31));
        EmployeeAddressText_C->setTextInteractionFlags(Qt::NoTextInteraction);
        EmployeeFirstName_C = new QLineEdit(CreateEmployee);
        EmployeeFirstName_C->setObjectName(QStringLiteral("EmployeeFirstName_C"));
        EmployeeFirstName_C->setGeometry(QRect(44, 145, 160, 30));
        EmployeePhoneNumber_C = new QLineEdit(CreateEmployee);
        EmployeePhoneNumber_C->setObjectName(QStringLiteral("EmployeePhoneNumber_C"));
        EmployeePhoneNumber_C->setGeometry(QRect(244, 225, 160, 30));
        EmployeeCreateBtn = new QPushButton(CreateEmployee);
        EmployeeCreateBtn->setObjectName(QStringLiteral("EmployeeCreateBtn"));
        EmployeeCreateBtn->setGeometry(QRect(55, 355, 160, 40));
        EmployeeDob_C = new QDateEdit(CreateEmployee);
        EmployeeDob_C->setObjectName(QStringLiteral("EmployeeDob_C"));
        EmployeeDob_C->setGeometry(QRect(44, 305, 160, 30));
        EmployeeLastName_C = new QLineEdit(CreateEmployee);
        EmployeeLastName_C->setObjectName(QStringLiteral("EmployeeLastName_C"));
        EmployeeLastName_C->setGeometry(QRect(244, 145, 160, 30));
        EmployeeEmailText_C = new QPlainTextEdit(CreateEmployee);
        EmployeeEmailText_C->setObjectName(QStringLiteral("EmployeeEmailText_C"));
        EmployeeEmailText_C->setGeometry(QRect(98, 35, 61, 31));
        EmployeeEmailText_C->setTextInteractionFlags(Qt::NoTextInteraction);
        EmployeePhoneNumberText_C = new QPlainTextEdit(CreateEmployee);
        EmployeePhoneNumberText_C->setObjectName(QStringLiteral("EmployeePhoneNumberText_C"));
        EmployeePhoneNumberText_C->setGeometry(QRect(264, 195, 141, 31));
        EmployeePhoneNumberText_C->setTextInteractionFlags(Qt::NoTextInteraction);
        EmployeeFirstNameText_C = new QPlainTextEdit(CreateEmployee);
        EmployeeFirstNameText_C->setObjectName(QStringLiteral("EmployeeFirstNameText_C"));
        EmployeeFirstNameText_C->setGeometry(QRect(84, 115, 91, 31));
        EmployeeFirstNameText_C->setTextInteractionFlags(Qt::NoTextInteraction);
        EmployeeDobText_C = new QPlainTextEdit(CreateEmployee);
        EmployeeDobText_C->setObjectName(QStringLiteral("EmployeeDobText_C"));
        EmployeeDobText_C->setGeometry(QRect(84, 275, 104, 31));
        EmployeeDobText_C->setTextInteractionFlags(Qt::NoTextInteraction);
        EmployeeRole_C = new QComboBox(CreateEmployee);
        EmployeeRole_C->setObjectName(QStringLiteral("EmployeeRole_C"));
        EmployeeRole_C->setGeometry(QRect(244, 305, 160, 30));
        EmployeeCancelBtn_C = new QPushButton(CreateEmployee);
        EmployeeCancelBtn_C->setObjectName(QStringLiteral("EmployeeCancelBtn_C"));
        EmployeeCancelBtn_C->setGeometry(QRect(240, 355, 160, 40));
        EmployeeRoleText_C = new QPlainTextEdit(CreateEmployee);
        EmployeeRoleText_C->setObjectName(QStringLiteral("EmployeeRoleText_C"));
        EmployeeRoleText_C->setGeometry(QRect(304, 275, 104, 31));
        EmployeeRoleText_C->setTextInteractionFlags(Qt::NoTextInteraction);
        EmployeePassword_C = new QLineEdit(CreateEmployee);
        EmployeePassword_C->setObjectName(QStringLiteral("EmployeePassword_C"));
        EmployeePassword_C->setGeometry(QRect(244, 65, 160, 30));
        EmployeePasswordText_C = new QPlainTextEdit(CreateEmployee);
        EmployeePasswordText_C->setObjectName(QStringLiteral("EmployeePasswordText_C"));
        EmployeePasswordText_C->setGeometry(QRect(284, 35, 141, 31));
        EmployeePasswordText_C->setTextInteractionFlags(Qt::NoTextInteraction);
        CrudEmployee->addWidget(CreateEmployee);
        UpdateEmployee = new QWidget();
        UpdateEmployee->setObjectName(QStringLiteral("UpdateEmployee"));
        EmployeeFirstNameText_U = new QPlainTextEdit(UpdateEmployee);
        EmployeeFirstNameText_U->setObjectName(QStringLiteral("EmployeeFirstNameText_U"));
        EmployeeFirstNameText_U->setGeometry(QRect(79, 145, 91, 31));
        EmployeeFirstNameText_U->setTextInteractionFlags(Qt::NoTextInteraction);
        EmployeePhoneNumberText_U = new QPlainTextEdit(UpdateEmployee);
        EmployeePhoneNumberText_U->setObjectName(QStringLiteral("EmployeePhoneNumberText_U"));
        EmployeePhoneNumberText_U->setGeometry(QRect(259, 225, 141, 31));
        EmployeePhoneNumberText_U->setTextInteractionFlags(Qt::NoTextInteraction);
        EmployeeFirstName_U = new QLineEdit(UpdateEmployee);
        EmployeeFirstName_U->setObjectName(QStringLiteral("EmployeeFirstName_U"));
        EmployeeFirstName_U->setGeometry(QRect(39, 175, 160, 30));
        EmployeeLastName_U = new QLineEdit(UpdateEmployee);
        EmployeeLastName_U->setObjectName(QStringLiteral("EmployeeLastName_U"));
        EmployeeLastName_U->setGeometry(QRect(239, 175, 160, 30));
        EmployeeDob_U = new QDateEdit(UpdateEmployee);
        EmployeeDob_U->setObjectName(QStringLiteral("EmployeeDob_U"));
        EmployeeDob_U->setGeometry(QRect(39, 335, 160, 30));
        EmployeePasswordText_U = new QPlainTextEdit(UpdateEmployee);
        EmployeePasswordText_U->setObjectName(QStringLiteral("EmployeePasswordText_U"));
        EmployeePasswordText_U->setGeometry(QRect(279, 65, 141, 31));
        EmployeePasswordText_U->setTextInteractionFlags(Qt::NoTextInteraction);
        EmployeePhoneNumber_U = new QLineEdit(UpdateEmployee);
        EmployeePhoneNumber_U->setObjectName(QStringLiteral("EmployeePhoneNumber_U"));
        EmployeePhoneNumber_U->setGeometry(QRect(239, 255, 160, 30));
        EmployeeRole_U = new QComboBox(UpdateEmployee);
        EmployeeRole_U->setObjectName(QStringLiteral("EmployeeRole_U"));
        EmployeeRole_U->setGeometry(QRect(239, 335, 160, 30));
        EmployeeEmail_U = new QLineEdit(UpdateEmployee);
        EmployeeEmail_U->setObjectName(QStringLiteral("EmployeeEmail_U"));
        EmployeeEmail_U->setGeometry(QRect(39, 95, 160, 30));
        EmployeeDobText_U = new QPlainTextEdit(UpdateEmployee);
        EmployeeDobText_U->setObjectName(QStringLiteral("EmployeeDobText_U"));
        EmployeeDobText_U->setGeometry(QRect(79, 305, 104, 31));
        EmployeeDobText_U->setTextInteractionFlags(Qt::NoTextInteraction);
        EmployeeRoleText_U = new QPlainTextEdit(UpdateEmployee);
        EmployeeRoleText_U->setObjectName(QStringLiteral("EmployeeRoleText_U"));
        EmployeeRoleText_U->setGeometry(QRect(299, 305, 104, 31));
        EmployeeRoleText_U->setTextInteractionFlags(Qt::NoTextInteraction);
        EmployeeAddressText_U = new QPlainTextEdit(UpdateEmployee);
        EmployeeAddressText_U->setObjectName(QStringLiteral("EmployeeAddressText_U"));
        EmployeeAddressText_U->setGeometry(QRect(79, 225, 104, 31));
        EmployeeAddressText_U->setTextInteractionFlags(Qt::NoTextInteraction);
        EmployeeEmailText_U = new QPlainTextEdit(UpdateEmployee);
        EmployeeEmailText_U->setObjectName(QStringLiteral("EmployeeEmailText_U"));
        EmployeeEmailText_U->setGeometry(QRect(93, 65, 61, 31));
        EmployeeEmailText_U->setTextInteractionFlags(Qt::NoTextInteraction);
        EmployeeUpdateBtn = new QPushButton(UpdateEmployee);
        EmployeeUpdateBtn->setObjectName(QStringLiteral("EmployeeUpdateBtn"));
        EmployeeUpdateBtn->setGeometry(QRect(49, 385, 160, 40));
        EmployeeLastNameText_U = new QPlainTextEdit(UpdateEmployee);
        EmployeeLastNameText_U->setObjectName(QStringLiteral("EmployeeLastNameText_U"));
        EmployeeLastNameText_U->setGeometry(QRect(279, 145, 104, 31));
        EmployeeLastNameText_U->setTextInteractionFlags(Qt::NoTextInteraction);
        EmployeePassword_U = new QLineEdit(UpdateEmployee);
        EmployeePassword_U->setObjectName(QStringLiteral("EmployeePassword_U"));
        EmployeePassword_U->setGeometry(QRect(239, 95, 160, 30));
        EmployeeAddress_U = new QLineEdit(UpdateEmployee);
        EmployeeAddress_U->setObjectName(QStringLiteral("EmployeeAddress_U"));
        EmployeeAddress_U->setGeometry(QRect(39, 255, 160, 30));
        EmployeeCancelBtn_U = new QPushButton(UpdateEmployee);
        EmployeeCancelBtn_U->setObjectName(QStringLiteral("EmployeeCancelBtn_U"));
        EmployeeCancelBtn_U->setGeometry(QRect(249, 385, 160, 40));
        EmployeeSelectIDText_U = new QLineEdit(UpdateEmployee);
        EmployeeSelectIDText_U->setObjectName(QStringLiteral("EmployeeSelectIDText_U"));
        EmployeeSelectIDText_U->setGeometry(QRect(10, 30, 113, 24));
        EmployeeSelectID_U = new QComboBox(UpdateEmployee);
        EmployeeSelectID_U->setObjectName(QStringLiteral("EmployeeSelectID_U"));
        EmployeeSelectID_U->setGeometry(QRect(80, 30, 81, 31));
        CrudEmployee->addWidget(UpdateEmployee);
        DeleteEmployee = new QWidget();
        DeleteEmployee->setObjectName(QStringLiteral("DeleteEmployee"));
        EmployeeDeleteBtn = new QPushButton(DeleteEmployee);
        EmployeeDeleteBtn->setObjectName(QStringLiteral("EmployeeDeleteBtn"));
        EmployeeDeleteBtn->setGeometry(QRect(90, 210, 111, 51));
        EmployeeSelectID_D = new QComboBox(DeleteEmployee);
        EmployeeSelectID_D->setObjectName(QStringLiteral("EmployeeSelectID_D"));
        EmployeeSelectID_D->setGeometry(QRect(190, 140, 151, 31));
        EmployeeSelectIDText_D = new QLineEdit(DeleteEmployee);
        EmployeeSelectIDText_D->setObjectName(QStringLiteral("EmployeeSelectIDText_D"));
        EmployeeSelectIDText_D->setGeometry(QRect(60, 140, 113, 24));
        EmployeeCancelBtn_D = new QPushButton(DeleteEmployee);
        EmployeeCancelBtn_D->setObjectName(QStringLiteral("EmployeeCancelBtn_D"));
        EmployeeCancelBtn_D->setGeometry(QRect(260, 210, 111, 51));
        CrudEmployee->addWidget(DeleteEmployee);
        readBoxEmployee = new QListWidget(page);
        readBoxEmployee->setObjectName(QStringLiteral("readBoxEmployee"));
        readBoxEmployee->setGeometry(QRect(450, 110, 761, 560));
        searchBarEmployee = new QLineEdit(page);
        searchBarEmployee->setObjectName(QStringLiteral("searchBarEmployee"));
        searchBarEmployee->setGeometry(QRect(760, 170, 431, 41));
        searchBarEmployee->setStyleSheet(QStringLiteral(""));
        searchBarEmployee->setClearButtonEnabled(true);
        tableEmployee = new QTableWidget(page);
        if (tableEmployee->columnCount() < 9)
            tableEmployee->setColumnCount(9);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableEmployee->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableEmployee->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableEmployee->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableEmployee->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableEmployee->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableEmployee->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableEmployee->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableEmployee->setHorizontalHeaderItem(7, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableEmployee->setHorizontalHeaderItem(8, __qtablewidgetitem8);
        tableEmployee->setObjectName(QStringLiteral("tableEmployee"));
        tableEmployee->setGeometry(QRect(450, 230, 761, 391));
        QFont font;
        font.setFamily(QStringLiteral("JetBrains Mono"));
        font.setPointSize(10);
        tableEmployee->setFont(font);
        tableEmployee->setAutoFillBackground(false);
        tableEmployee->setStyleSheet(QStringLiteral(""));
        tableEmployee->setShowGrid(true);
        statsEmployee = new QFrame(page);
        statsEmployee->setObjectName(QStringLiteral("statsEmployee"));
        statsEmployee->setGeometry(QRect(10, 10, 431, 221));
        statsEmployee->setFrameShape(QFrame::NoFrame);
        EmployeeSelectStats = new QComboBox(statsEmployee);
        EmployeeSelectStats->setObjectName(QStringLiteral("EmployeeSelectStats"));
        EmployeeSelectStats->setGeometry(QRect(320, 10, 101, 21));
        stackedWidget->addWidget(page);
        readBoxEmployee->raise();
        featureBarEmployee->raise();
        CrudEmployee->raise();
        searchBarEmployee->raise();
        tableEmployee->raise();
        statsEmployee->raise();
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        page_2->setStyleSheet(QLatin1String(" #featureBarClient {\n"
"     background-color: white;\n"
"     border-radius: 25px;\n"
"}\n"
" #CrudClient,\n"
"#CreateClient,\n"
"#UpdateClient,\n"
"#DeleteClient {\n"
"     background-color: #A7C34E;\n"
"     border-radius: 25px;\n"
"}\n"
" #QRCodeClient {\n"
"     background-color: #A7C34E;\n"
"     border-radius: 25px;\n"
"}\n"
" #readBoxClient{\n"
"     border: none;\n"
"     background-color: #A7C34E;\n"
"     border-radius: 25px;\n"
"}\n"
" #searchBarClient{\n"
"     background-color: white;\n"
"     border-radius: 20px;\n"
"color:black;\n"
"}\n"
" #addClient, \n"
"#deleteClient,\n"
" #pdfClient, \n"
"#updateClient, \n"
"#sortClient,#pieChartClient{\n"
"     border: none;\n"
"     background-color: transparent;\n"
"}\n"
"/*Create*/\n"
" #ClientCreateEmailLine, \n"
"#ClientCreateFirstNameLine, \n"
"#ClientCreateLastNameLine, \n"
"#ClientCreateAddressLine,\n"
" #ClientCreatePhoneNumberLine,\n"
" #ClientCreateDobLine {\n"
"     background-color: #A7C34E;\n"
"     font-family: \"helvetica\";\n"
"     font-"
                        "size: 14px;\n"
"     color: white;\n"
"     font-style: bold;\n"
"}\n"
" #ClientCreateEmail, \n"
"#ClientCreateFirstName, \n"
"#ClientCreateLastName, \n"
"#ClientCreateAddress,\n"
" #ClientCreatePhoneNumber, \n"
"#ClientCreateDob {\n"
"     background-color: #171717;\n"
"     font-family: \"helvetica\";\n"
"     font-size: 14px;\n"
"     color: white;\n"
"     font-style: bold;\n"
"     border:none;\n"
"     border-radius:15px;\n"
"}\n"
"/*Read*/\n"
" #tableClient {\n"
"     border-radius: 10px;\n"
"     border-collapse: collapse;\n"
"     width: 100%;\n"
"}\n"
" #tableClient th, #tableClient td {\n"
"     border: 1px solid #ddd;\n"
"     padding: 8px;\n"
"     text-align: left;\n"
"}\n"
" #tableClient td {\n"
"     color:black;\n"
"}\n"
"/*Update*/\n"
" #ClientUpdateIDLine,\n"
" #ClientUpdateEmailLine, \n"
"#ClientUpdateFirstNameLine, \n"
"#ClientUpdateLastNameLine, \n"
"#ClientUpdateAddressLine, \n"
"#ClientUpdatePhoneNumberLine,\n"
" #ClientUpdateDobLine {\n"
"     background-color: #A7C34E;\n"
"     font-f"
                        "amily: \"helvetica\";\n"
"     font-size: 14px;\n"
"     color: white;\n"
"     font-style: bold;\n"
"}\n"
" #ClientUpdateID, \n"
"#ClientUpdateEmail, \n"
"#ClientUpdateFirstName, \n"
"#ClientUpdateLastName,\n"
" #ClientUpdateAddress, \n"
"#ClientUpdatePhoneNumber, \n"
"#ClientUpdateDob {\n"
"     background-color: #171717;\n"
"     font-family: \"helvetica\";\n"
"     font-size: 14px;\n"
"     color: white;\n"
"     font-style: bold;\n"
"     border:none;\n"
"     border-radius:15px;\n"
"}\n"
"/*Delete*/\n"
" #ClientDeleteIDLine {\n"
"     background-color: #A7C34E;\n"
"     font-family: \"helvetica\";\n"
"     font-size: 14px;\n"
"     color: white;\n"
"     font-style: bold;\n"
"}\n"
" #ClientDeleteID {\n"
"     background-color: #171717;\n"
"     font-family: \"helvetica\";\n"
"     font-size: 14px;\n"
"     color: white;\n"
"     font-style: bold;\n"
"     border:none;\n"
"     border-radius:15px;\n"
"}\n"
"\n"
"\n"
"\n"
"/*QR Code*/\n"
"\n"
"#QRCodeClientTitle{\n"
"background-color:transparent;\n"
"color"
                        ":black;\n"
"font:25px bold;\n"
"}\n"
"\n"
"#QRCodeClientLabel{\n"
"background-color:transparent;\n"
"font-family: \"helvetica\";\n"
" font-size: 14px;\n"
" color: white;\n"
" font-style: bold;\n"
"}\n"
"\n"
"#QRCodeClientInput{\n"
"	  background-color: #171717;\n"
"     font-family: \"helvetica\";\n"
"     font-size: 14px;\n"
"     color: white;\n"
"     font-style: bold;\n"
"     border:none;\n"
"     border-radius:15px;\n"
"\n"
"\n"
"}\n"
"\n"
"\n"
"\n"
" "));
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
        QRCodeClient = new QFrame(page_2);
        QRCodeClient->setObjectName(QStringLiteral("QRCodeClient"));
        QRCodeClient->setGeometry(QRect(10, 10, 371, 201));
        QRCodeClient->setFrameShape(QFrame::NoFrame);
        QRCodeClientCombo = new QComboBox(QRCodeClient);
        QRCodeClientCombo->setObjectName(QStringLiteral("QRCodeClientCombo"));
        QRCodeClientCombo->setGeometry(QRect(150, 100, 171, 24));
        QRCodeClientInput = new QLineEdit(QRCodeClient);
        QRCodeClientInput->setObjectName(QStringLiteral("QRCodeClientInput"));
        QRCodeClientInput->setGeometry(QRect(150, 60, 171, 24));
        QRCodeClientTitle = new QPlainTextEdit(QRCodeClient);
        QRCodeClientTitle->setObjectName(QStringLiteral("QRCodeClientTitle"));
        QRCodeClientTitle->setGeometry(QRect(130, 0, 141, 51));
        QRCodeClientLabel = new QPlainTextEdit(QRCodeClient);
        QRCodeClientLabel->setObjectName(QStringLiteral("QRCodeClientLabel"));
        QRCodeClientLabel->setGeometry(QRect(30, 80, 91, 31));
        QRCodeClientLabel->setReadOnly(true);
        QRCodeClientLabel->setTextInteractionFlags(Qt::NoTextInteraction);
        QRCodeClientGenerate = new QPushButton(QRCodeClient);
        QRCodeClientGenerate->setObjectName(QStringLiteral("QRCodeClientGenerate"));
        QRCodeClientGenerate->setGeometry(QRect(60, 160, 80, 24));
        QRCodeClientCancel = new QPushButton(QRCodeClient);
        QRCodeClientCancel->setObjectName(QStringLiteral("QRCodeClientCancel"));
        QRCodeClientCancel->setGeometry(QRect(200, 160, 80, 24));
        featureBarClient = new QFrame(page_2);
        featureBarClient->setObjectName(QStringLiteral("featureBarClient"));
        featureBarClient->setGeometry(QRect(420, 20, 701, 61));
        featureBarClient->setStyleSheet(QStringLiteral(""));
        featureBarClient->setFrameShape(QFrame::NoFrame);
        deleteClient = new QPushButton(featureBarClient);
        deleteClient->setObjectName(QStringLiteral("deleteClient"));
        deleteClient->setGeometry(QRect(175, 10, 41, 41));
        deleteClient->setCursor(QCursor(Qt::PointingHandCursor));
        deleteClient->setIcon(icon1);
        deleteClient->setIconSize(QSize(40, 40));
        updateClient = new QPushButton(featureBarClient);
        updateClient->setObjectName(QStringLiteral("updateClient"));
        updateClient->setGeometry(QRect(375, 10, 41, 41));
        updateClient->setCursor(QCursor(Qt::PointingHandCursor));
        updateClient->setIcon(icon2);
        updateClient->setIconSize(QSize(60, 60));
        pdfClient = new QPushButton(featureBarClient);
        pdfClient->setObjectName(QStringLiteral("pdfClient"));
        pdfClient->setGeometry(QRect(475, 10, 41, 41));
        pdfClient->setCursor(QCursor(Qt::PointingHandCursor));
        pdfClient->setIcon(icon3);
        pdfClient->setIconSize(QSize(50, 50));
        sortClient = new QPushButton(featureBarClient);
        sortClient->setObjectName(QStringLiteral("sortClient"));
        sortClient->setGeometry(QRect(275, 10, 41, 41));
        sortClient->setCursor(QCursor(Qt::PointingHandCursor));
        sortClient->setIcon(icon4);
        sortClient->setIconSize(QSize(50, 50));
        addClient = new QPushButton(featureBarClient);
        addClient->setObjectName(QStringLiteral("addClient"));
        addClient->setGeometry(QRect(75, 10, 41, 41));
        addClient->setCursor(QCursor(Qt::PointingHandCursor));
        addClient->setIcon(icon);
        addClient->setIconSize(QSize(60, 60));
        pieChartClient = new QPushButton(featureBarClient);
        pieChartClient->setObjectName(QStringLiteral("pieChartClient"));
        pieChartClient->setGeometry(QRect(575, 5, 51, 51));
        pieChartClient->setCursor(QCursor(Qt::PointingHandCursor));
        QIcon icon5;
        icon5.addFile(QStringLiteral("../Resources/Icons/piechart.png"), QSize(), QIcon::Normal, QIcon::Off);
        pieChartClient->setIcon(icon5);
        pieChartClient->setIconSize(QSize(50, 50));
        tableClient = new QTableWidget(page_2);
        if (tableClient->columnCount() < 7)
            tableClient->setColumnCount(7);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableClient->setHorizontalHeaderItem(0, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableClient->setHorizontalHeaderItem(1, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tableClient->setHorizontalHeaderItem(2, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        tableClient->setHorizontalHeaderItem(3, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        tableClient->setHorizontalHeaderItem(4, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        tableClient->setHorizontalHeaderItem(5, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        tableClient->setHorizontalHeaderItem(6, __qtablewidgetitem15);
        tableClient->setObjectName(QStringLiteral("tableClient"));
        tableClient->setGeometry(QRect(420, 180, 711, 441));
        tableClient->setFont(font);
        tableClient->setAutoFillBackground(false);
        tableClient->setShowGrid(true);
        tableClient->setSortingEnabled(true);
        tableClient->horizontalHeader()->setDefaultSectionSize(90);
        tableClient->horizontalHeader()->setMinimumSectionSize(50);
        tableClient->verticalHeader()->setVisible(false);
        tableClient->verticalHeader()->setDefaultSectionSize(20);
        tableClient->verticalHeader()->setHighlightSections(false);
        tableClient->verticalHeader()->setMinimumSectionSize(10);
        stackedWidget->addWidget(page_2);
        page_3 = new QWidget();
        page_3->setObjectName(QStringLiteral("page_3"));
        page_3->setStyleSheet(QLatin1String(" \n"
"/* Apply styles to the featureBarContract */\n"
" #featureBarContract {\n"
"     background-color: white;\n"
"     border-radius: 25px;\n"
"}\n"
"/* Apply styles to the addContract */\n"
" #CrudContract {\n"
"     background-color: #A7C34E;\n"
"     border-radius: 25px;\n"
"}\n"
"/* Apply styles to the statsContract */\n"
" #statsContract {\n"
"     background-color: #A7C34E;\n"
"     border-radius: 25px;\n"
"}\n"
"/* Apply styles to the readBoxContract */\n"
" #readBoxContract {\n"
"     border: none;\n"
"     background-color: #A7C34E;\n"
"     border-radius: 25px;\n"
"}\n"
"/* Apply styles to the searchBarContract */\n"
" #searchBarContract {\n"
"     background-color: white;\n"
"}\n"
" #searchBarContract {\n"
"     border-radius: 20px;\n"
"}\n"
" #CreateContract{\n"
"     background-color: #A7C34E;\n"
"     border-radius: 25px;\n"
"}\n"
" #DeleteContract{\n"
"     background-color: #A7C34E;\n"
"     border-radius: 25px;\n"
"}\n"
" #UpdateContract{\n"
"     background-color: #A7C34E;\n"
"     border-r"
                        "adius: 25px;\n"
"}\n"
"#addContract,\n"
"#deleteContract,\n"
"#pdfContract, \n"
"#updateContract, \n"
"#sortContract , \n"
"#excelContract{\n"
"     border: none;\n"
"     background-color: transparent;\n"
"}\n"
" "));
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
        LineEditUserIdContract = new QLineEdit(CreateContract);
        LineEditUserIdContract->setObjectName(QStringLiteral("LineEditUserIdContract"));
        LineEditUserIdContract->setGeometry(QRect(220, 50, 113, 24));
        LineEditClientIdContract = new QLineEdit(CreateContract);
        LineEditClientIdContract->setObjectName(QStringLiteral("LineEditClientIdContract"));
        LineEditClientIdContract->setGeometry(QRect(220, 100, 113, 24));
        LineEditPremiumAmountContract = new QLineEdit(CreateContract);
        LineEditPremiumAmountContract->setObjectName(QStringLiteral("LineEditPremiumAmountContract"));
        LineEditPremiumAmountContract->setGeometry(QRect(220, 160, 113, 24));
        lineEditTypeContract = new QLineEdit(CreateContract);
        lineEditTypeContract->setObjectName(QStringLiteral("lineEditTypeContract"));
        lineEditTypeContract->setGeometry(QRect(220, 380, 113, 24));
        lineEditTypeContract->setStyleSheet(QLatin1String("\n"
"									   #LineEditType {\n"
"									   background-color: transparent;\n"
"									   }\n"
"								   "));
        LineEditPaymentstatusContract = new QLineEdit(CreateContract);
        LineEditPaymentstatusContract->setObjectName(QStringLiteral("LineEditPaymentstatusContract"));
        LineEditPaymentstatusContract->setGeometry(QRect(220, 320, 113, 24));
        LabelUserIdContract = new QLabel(CreateContract);
        LabelUserIdContract->setObjectName(QStringLiteral("LabelUserIdContract"));
        LabelUserIdContract->setGeometry(QRect(50, 50, 51, 21));
        LabelUserIdContract->setStyleSheet(QLatin1String("\n"
"									   #LabelUserIdContract {\n"
"									   background-color: transparent;\n"
"									   }\n"
"								   "));
        LabelClientIdContract = new QLabel(CreateContract);
        LabelClientIdContract->setObjectName(QStringLiteral("LabelClientIdContract"));
        LabelClientIdContract->setGeometry(QRect(50, 110, 71, 16));
        LabelClientIdContract->setStyleSheet(QLatin1String("\n"
"									   #LabelClientIdContract {\n"
"									   background-color: transparent;\n"
"									   }\n"
"								   "));
        LabelPremiumAmountContract = new QLabel(CreateContract);
        LabelPremiumAmountContract->setObjectName(QStringLiteral("LabelPremiumAmountContract"));
        LabelPremiumAmountContract->setGeometry(QRect(50, 160, 121, 21));
        LabelPremiumAmountContract->setStyleSheet(QLatin1String("\n"
"									   #LabelPremiumAmountContract {\n"
"									   background-color: transparent;\n"
"									   }\n"
"								   "));
        LabelEffectiveDateContract = new QLabel(CreateContract);
        LabelEffectiveDateContract->setObjectName(QStringLiteral("LabelEffectiveDateContract"));
        LabelEffectiveDateContract->setGeometry(QRect(50, 210, 121, 21));
        LabelEffectiveDateContract->setStyleSheet(QLatin1String("\n"
"									   #LabelEffectiveDateContract {\n"
"									   background-color: transparent;\n"
"									   }\n"
"								   "));
        LabelExpirationDateContract = new QLabel(CreateContract);
        LabelExpirationDateContract->setObjectName(QStringLiteral("LabelExpirationDateContract"));
        LabelExpirationDateContract->setGeometry(QRect(50, 260, 121, 16));
        LabelExpirationDateContract->setStyleSheet(QLatin1String("\n"
"									   #LabelExpirationDateContract {\n"
"									   background-color: transparent;\n"
"									   }\n"
"								   "));
        LabelPaymentStatusContract = new QLabel(CreateContract);
        LabelPaymentStatusContract->setObjectName(QStringLiteral("LabelPaymentStatusContract"));
        LabelPaymentStatusContract->setGeometry(QRect(50, 320, 121, 16));
        LabelPaymentStatusContract->setStyleSheet(QLatin1String("\n"
"									   #LabelPaymentStatusContract {\n"
"									   background-color: transparent;\n"
"									   }\n"
"								   "));
        LabelTypeContract = new QLabel(CreateContract);
        LabelTypeContract->setObjectName(QStringLiteral("LabelTypeContract"));
        LabelTypeContract->setGeometry(QRect(50, 380, 56, 16));
        LabelTypeContract->setStyleSheet(QLatin1String("\n"
"									   #LabelTypeContract {\n"
"									   background-color: transparent;\n"
"									   }\n"
"								   "));
        CancelCreateContract = new QPushButton(CreateContract);
        CancelCreateContract->setObjectName(QStringLiteral("CancelCreateContract"));
        CancelCreateContract->setGeometry(QRect(240, 550, 80, 25));
        CreateContractButton = new QPushButton(CreateContract);
        CreateContractButton->setObjectName(QStringLiteral("CreateContractButton"));
        CreateContractButton->setGeometry(QRect(30, 550, 101, 25));
        dateEditEffectiveDateContract = new QDateEdit(CreateContract);
        dateEditEffectiveDateContract->setObjectName(QStringLiteral("dateEditEffectiveDateContract"));
        dateEditEffectiveDateContract->setGeometry(QRect(220, 210, 110, 25));
        dateEditExpirationDateContract = new QDateEdit(CreateContract);
        dateEditExpirationDateContract->setObjectName(QStringLiteral("dateEditExpirationDateContract"));
        dateEditExpirationDateContract->setGeometry(QRect(220, 260, 110, 25));
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
        LabelContractId->setGeometry(QRect(30, 50, 91, 21));
        LabelContractId->setStyleSheet(QLatin1String("\n"
"									   #LabelContractId {\n"
"									   background-color: transparent;\n"
"									   }\n"
"								   "));
        LineEditContractID = new QLineEdit(DeleteContract);
        LineEditContractID->setObjectName(QStringLiteral("LineEditContractID"));
        LineEditContractID->setGeometry(QRect(230, 50, 113, 24));
        CancelDeleteContract = new QPushButton(DeleteContract);
        CancelDeleteContract->setObjectName(QStringLiteral("CancelDeleteContract"));
        CancelDeleteContract->setGeometry(QRect(230, 530, 91, 31));
        DeleteContractButton = new QPushButton(DeleteContract);
        DeleteContractButton->setObjectName(QStringLiteral("DeleteContractButton"));
        DeleteContractButton->setGeometry(QRect(40, 530, 111, 31));
        StackContract->addWidget(page_6);
        page_7 = new QWidget();
        page_7->setObjectName(QStringLiteral("page_7"));
        UpdateContract = new QFrame(page_7);
        UpdateContract->setObjectName(QStringLiteral("UpdateContract"));
        UpdateContract->setGeometry(QRect(-1, 29, 371, 681));
        UpdateContract->setFrameShape(QFrame::StyledPanel);
        UpdateContract->setFrameShadow(QFrame::Raised);
        UpdateContractButton = new QPushButton(UpdateContract);
        UpdateContractButton->setObjectName(QStringLiteral("UpdateContractButton"));
        UpdateContractButton->setGeometry(QRect(40, 540, 111, 25));
        CancelUpdateContract = new QPushButton(UpdateContract);
        CancelUpdateContract->setObjectName(QStringLiteral("CancelUpdateContract"));
        CancelUpdateContract->setGeometry(QRect(260, 540, 80, 25));
        LabelUserIdContractUpdate = new QLabel(UpdateContract);
        LabelUserIdContractUpdate->setObjectName(QStringLiteral("LabelUserIdContractUpdate"));
        LabelUserIdContractUpdate->setGeometry(QRect(30, 100, 81, 21));
        LabelUserIdContractUpdate->setStyleSheet(QLatin1String("\n"
"									   #LabelUserIdContractUpdate {\n"
"									   background-color: transparent;\n"
"									   }\n"
"								   "));
        LabelClientIdContractUpdate = new QLabel(UpdateContract);
        LabelClientIdContractUpdate->setObjectName(QStringLiteral("LabelClientIdContractUpdate"));
        LabelClientIdContractUpdate->setGeometry(QRect(30, 160, 71, 16));
        LabelClientIdContractUpdate->setStyleSheet(QLatin1String("\n"
"									   #LabelClientIdContractUpdate {\n"
"									   background-color: transparent;\n"
"									   }\n"
"								   "));
        LabelPremiumAmountContractUpdate = new QLabel(UpdateContract);
        LabelPremiumAmountContractUpdate->setObjectName(QStringLiteral("LabelPremiumAmountContractUpdate"));
        LabelPremiumAmountContractUpdate->setGeometry(QRect(30, 210, 121, 21));
        LabelPremiumAmountContractUpdate->setStyleSheet(QLatin1String("\n"
"									   #LabelPremiumAmountContractUpdate {\n"
"									   background-color: transparent;\n"
"									   }\n"
"								   "));
        LabelEffectiveDateContractUpdate = new QLabel(UpdateContract);
        LabelEffectiveDateContractUpdate->setObjectName(QStringLiteral("LabelEffectiveDateContractUpdate"));
        LabelEffectiveDateContractUpdate->setGeometry(QRect(30, 270, 121, 21));
        LabelEffectiveDateContractUpdate->setStyleSheet(QLatin1String("\n"
"									   #LabelEffectiveDateContractUpdate{\n"
"									   background-color: transparent;\n"
"									   }\n"
"								   "));
        LabelExpirationDateContractUpdate = new QLabel(UpdateContract);
        LabelExpirationDateContractUpdate->setObjectName(QStringLiteral("LabelExpirationDateContractUpdate"));
        LabelExpirationDateContractUpdate->setGeometry(QRect(30, 330, 121, 16));
        LabelExpirationDateContractUpdate->setStyleSheet(QLatin1String("\n"
"									   #LabelExpirationDateContractUpdate {\n"
"									   background-color: transparent;\n"
"									   }\n"
"								   "));
        LabelPaymentStatusContractUpdate = new QLabel(UpdateContract);
        LabelPaymentStatusContractUpdate->setObjectName(QStringLiteral("LabelPaymentStatusContractUpdate"));
        LabelPaymentStatusContractUpdate->setGeometry(QRect(30, 390, 121, 16));
        LabelPaymentStatusContractUpdate->setStyleSheet(QLatin1String("\n"
"									   #LabelPaymentStatusContractUpdate {\n"
"									   background-color: transparent;\n"
"									   }\n"
"								   "));
        LabelTypeContractUpdate = new QLabel(UpdateContract);
        LabelTypeContractUpdate->setObjectName(QStringLiteral("LabelTypeContractUpdate"));
        LabelTypeContractUpdate->setGeometry(QRect(40, 450, 56, 16));
        LabelTypeContractUpdate->setStyleSheet(QLatin1String("\n"
"									   #LabelTypeContractUpdate {\n"
"									   background-color: transparent;\n"
"									   }\n"
"								   "));
        LineEditUserIdContractUpdate = new QLineEdit(UpdateContract);
        LineEditUserIdContractUpdate->setObjectName(QStringLiteral("LineEditUserIdContractUpdate"));
        LineEditUserIdContractUpdate->setGeometry(QRect(250, 90, 113, 24));
        LineEditClientIdContractUpdate = new QLineEdit(UpdateContract);
        LineEditClientIdContractUpdate->setObjectName(QStringLiteral("LineEditClientIdContractUpdate"));
        LineEditClientIdContractUpdate->setGeometry(QRect(250, 150, 113, 24));
        dateEditEffectiveDateContractUpdate = new QDateEdit(UpdateContract);
        dateEditEffectiveDateContractUpdate->setObjectName(QStringLiteral("dateEditEffectiveDateContractUpdate"));
        dateEditEffectiveDateContractUpdate->setGeometry(QRect(250, 270, 110, 25));
        dateEditExpirationDateContractUpdate = new QDateEdit(UpdateContract);
        dateEditExpirationDateContractUpdate->setObjectName(QStringLiteral("dateEditExpirationDateContractUpdate"));
        dateEditExpirationDateContractUpdate->setGeometry(QRect(250, 320, 110, 25));
        LineEditPaymentstatusContractUpdate = new QLineEdit(UpdateContract);
        LineEditPaymentstatusContractUpdate->setObjectName(QStringLiteral("LineEditPaymentstatusContractUpdate"));
        LineEditPaymentstatusContractUpdate->setGeometry(QRect(250, 390, 113, 24));
        lineEditTypeContractUpdate = new QLineEdit(UpdateContract);
        lineEditTypeContractUpdate->setObjectName(QStringLiteral("lineEditTypeContractUpdate"));
        lineEditTypeContractUpdate->setGeometry(QRect(250, 450, 113, 24));
        lineEditTypeContractUpdate->setStyleSheet(QLatin1String("\n"
"									   #LineEditType {\n"
"									   background-color: transparent;\n"
"									   }\n"
"								   "));
        LineEditPremiumAmountContractUpdate = new QLineEdit(UpdateContract);
        LineEditPremiumAmountContractUpdate->setObjectName(QStringLiteral("LineEditPremiumAmountContractUpdate"));
        LineEditPremiumAmountContractUpdate->setGeometry(QRect(250, 210, 113, 24));
        lineEditContractIDUpdate = new QLineEdit(UpdateContract);
        lineEditContractIDUpdate->setObjectName(QStringLiteral("lineEditContractIDUpdate"));
        lineEditContractIDUpdate->setGeometry(QRect(250, 40, 113, 24));
        labelContractIDUpdate = new QLabel(UpdateContract);
        labelContractIDUpdate->setObjectName(QStringLiteral("labelContractIDUpdate"));
        labelContractIDUpdate->setGeometry(QRect(30, 40, 81, 16));
        labelContractIDUpdate->setStyleSheet(QLatin1String("\n"
"									   #labelContractIDUpdate {\n"
"									   background-color: transparent;\n"
"									   }\n"
"								   "));
        StackContract->addWidget(page_7);
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
        featureBarContract->setGeometry(QRect(510, 10, 611, 61));
        featureBarContract->setStyleSheet(QStringLiteral(""));
        featureBarContract->setFrameShape(QFrame::NoFrame);
        addContract = new QPushButton(featureBarContract);
        addContract->setObjectName(QStringLiteral("addContract"));
        addContract->setGeometry(QRect(150, 10, 41, 41));
        addContract->setCursor(QCursor(Qt::PointingHandCursor));
        addContract->setStyleSheet(QStringLiteral(""));
        addContract->setIcon(icon);
        addContract->setIconSize(QSize(60, 60));
        deleteContract = new QPushButton(featureBarContract);
        deleteContract->setObjectName(QStringLiteral("deleteContract"));
        deleteContract->setGeometry(QRect(240, 10, 41, 41));
        deleteContract->setCursor(QCursor(Qt::PointingHandCursor));
        deleteContract->setStyleSheet(QStringLiteral(""));
        deleteContract->setIcon(icon1);
        deleteContract->setIconSize(QSize(40, 40));
        updateContract = new QPushButton(featureBarContract);
        updateContract->setObjectName(QStringLiteral("updateContract"));
        updateContract->setGeometry(QRect(430, 10, 41, 41));
        updateContract->setCursor(QCursor(Qt::PointingHandCursor));
        updateContract->setStyleSheet(QStringLiteral(""));
        updateContract->setIcon(icon2);
        updateContract->setIconSize(QSize(60, 60));
        pdfContract = new QPushButton(featureBarContract);
        pdfContract->setObjectName(QStringLiteral("pdfContract"));
        pdfContract->setGeometry(QRect(520, 10, 41, 41));
        pdfContract->setCursor(QCursor(Qt::PointingHandCursor));
        pdfContract->setStyleSheet(QStringLiteral(""));
        pdfContract->setIcon(icon3);
        pdfContract->setIconSize(QSize(50, 50));
        sortContract = new QPushButton(featureBarContract);
        sortContract->setObjectName(QStringLiteral("sortContract"));
        sortContract->setGeometry(QRect(330, 10, 41, 41));
        sortContract->setCursor(QCursor(Qt::PointingHandCursor));
        sortContract->setStyleSheet(QStringLiteral(""));
        sortContract->setIcon(icon4);
        sortContract->setIconSize(QSize(50, 50));
        excelContract = new QPushButton(featureBarContract);
        excelContract->setObjectName(QStringLiteral("excelContract"));
        excelContract->setGeometry(QRect(50, 10, 51, 41));
        excelContract->setCursor(QCursor(Qt::PointingHandCursor));
        excelContract->setStyleSheet(QStringLiteral(""));
        QIcon icon6;
        icon6.addFile(QStringLiteral("../Resources/Icons/excel.png"), QSize(), QIcon::Normal, QIcon::Off);
        excelContract->setIcon(icon6);
        excelContract->setIconSize(QSize(60, 60));
        tableContract = new QTableWidget(page_3);
        if (tableContract->columnCount() < 8)
            tableContract->setColumnCount(8);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        tableContract->setHorizontalHeaderItem(0, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        tableContract->setHorizontalHeaderItem(1, __qtablewidgetitem17);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        tableContract->setHorizontalHeaderItem(2, __qtablewidgetitem18);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        tableContract->setHorizontalHeaderItem(3, __qtablewidgetitem19);
        QTableWidgetItem *__qtablewidgetitem20 = new QTableWidgetItem();
        tableContract->setHorizontalHeaderItem(4, __qtablewidgetitem20);
        QTableWidgetItem *__qtablewidgetitem21 = new QTableWidgetItem();
        tableContract->setHorizontalHeaderItem(5, __qtablewidgetitem21);
        QTableWidgetItem *__qtablewidgetitem22 = new QTableWidgetItem();
        tableContract->setHorizontalHeaderItem(6, __qtablewidgetitem22);
        QTableWidgetItem *__qtablewidgetitem23 = new QTableWidgetItem();
        tableContract->setHorizontalHeaderItem(7, __qtablewidgetitem23);
        tableContract->setObjectName(QStringLiteral("tableContract"));
        tableContract->setGeometry(QRect(390, 200, 741, 381));
        tableContract->setFont(font);
        tableContract->setShowGrid(true);
        tableContract->setSortingEnabled(true);
        tableContract->horizontalHeader()->setDefaultSectionSize(104);
        tableContract->horizontalHeader()->setMinimumSectionSize(50);
        tableContract->verticalHeader()->setVisible(false);
        tableContract->verticalHeader()->setDefaultSectionSize(20);
        tableContract->verticalHeader()->setHighlightSections(false);
        tableContract->verticalHeader()->setMinimumSectionSize(10);
        stackedWidget->addWidget(page_3);
        page_4 = new QWidget();
        page_4->setObjectName(QStringLiteral("page_4"));
        page_4->setStyleSheet(QLatin1String(" #CrudAccident {\n"
"     background-color: white;\n"
"     border-radius: 25px;\n"
"}\n"
" #CrudAccident {\n"
"     background-color: #A7C34E;\n"
"     border-radius: 25px;\n"
"}\n"
" #StatsAccident {\n"
"     background-color: #A7C34E;\n"
"     border-radius: 25px;\n"
"}\n"
" #featureBarAccident {\n"
"     background-color: white;\n"
"     border-radius: 25px;\n"
"}\n"
" #readAccident {\n"
"     border: none;\n"
"     background-color: #A7C34E;\n"
"     border-radius: 25px;\n"
"}\n"
" #searchAccident {\n"
"     background-color: white;\n"
"     border-radius: 20px;\n"
"}\n"
"#addAccident,\n"
"#deleteAccident, \n"
"#pdfAccident, \n"
"#updateAccident,\n"
"#sortAccident,\n"
"#historyAccident {\n"
"     border: none;\n"
"     background-color: transparent;\n"
"}\n"
" "));
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
        AccidentCreateTypeline->setGeometry(QRect(58, 97, 56, 16));
        AccidentCreateTypeline->setStyleSheet(QLatin1String("\n"
"									   QLabel{\n"
"									   color:white\n"
"									   }\n"
"								   "));
        AccidentCreateType = new QLineEdit(FrameCreateAccident);
        AccidentCreateType->setObjectName(QStringLiteral("AccidentCreateType"));
        AccidentCreateType->setGeometry(QRect(188, 97, 113, 22));
        AccidentCreateDamage = new QLineEdit(FrameCreateAccident);
        AccidentCreateDamage->setObjectName(QStringLiteral("AccidentCreateDamage"));
        AccidentCreateDamage->setGeometry(QRect(188, 147, 113, 22));
        AccidentCreateLocation = new QLineEdit(FrameCreateAccident);
        AccidentCreateLocation->setObjectName(QStringLiteral("AccidentCreateLocation"));
        AccidentCreateLocation->setGeometry(QRect(188, 247, 113, 22));
        AccidentCreateDamageline = new QLabel(FrameCreateAccident);
        AccidentCreateDamageline->setObjectName(QStringLiteral("AccidentCreateDamageline"));
        AccidentCreateDamageline->setGeometry(QRect(58, 147, 56, 16));
        AccidentCreateDamageline->setStyleSheet(QLatin1String("\n"
"									   QLabel{\n"
"									   color:white\n"
"									   }\n"
"								   "));
        AccidentCreateDateline = new QLabel(FrameCreateAccident);
        AccidentCreateDateline->setObjectName(QStringLiteral("AccidentCreateDateline"));
        AccidentCreateDateline->setGeometry(QRect(58, 197, 56, 16));
        AccidentCreateDateline->setStyleSheet(QLatin1String("\n"
"									   QLabel{\n"
"									   color:white\n"
"									   }\n"
"								   "));
        AccidentCreateLocationline = new QLabel(FrameCreateAccident);
        AccidentCreateLocationline->setObjectName(QStringLiteral("AccidentCreateLocationline"));
        AccidentCreateLocationline->setGeometry(QRect(58, 247, 56, 16));
        AccidentCreateLocationline->setStyleSheet(QLatin1String("\n"
"									   QLabel{\n"
"									   color:white\n"
"									   }\n"
"								   "));
        AccidentCreateClientIDline = new QLabel(FrameCreateAccident);
        AccidentCreateClientIDline->setObjectName(QStringLiteral("AccidentCreateClientIDline"));
        AccidentCreateClientIDline->setGeometry(QRect(58, 57, 56, 16));
        AccidentCreateClientIDline->setStyleSheet(QLatin1String("\n"
"									   QLabel\n"
"									   {color:white\n"
"									   }\n"
"								   "));
        AccidentSubmit = new QPushButton(FrameCreateAccident);
        AccidentSubmit->setObjectName(QStringLiteral("AccidentSubmit"));
        AccidentSubmit->setGeometry(QRect(348, 207, 71, 21));
        AccidentCancel = new QPushButton(FrameCreateAccident);
        AccidentCancel->setObjectName(QStringLiteral("AccidentCancel"));
        AccidentCancel->setGeometry(QRect(348, 237, 71, 21));
        AccidentCreateClientID = new QComboBox(FrameCreateAccident);
        AccidentCreateClientID->setObjectName(QStringLiteral("AccidentCreateClientID"));
        AccidentCreateClientID->setGeometry(QRect(188, 57, 113, 22));
        AccidentCreateDate = new QDateEdit(FrameCreateAccident);
        AccidentCreateDate->setObjectName(QStringLiteral("AccidentCreateDate"));
        AccidentCreateDate->setGeometry(QRect(188, 197, 110, 25));
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
        AccidentDeleteIDline->setStyleSheet(QLatin1String("\n"
"									   QLabel{\n"
"									   color:white\n"
"									   }\n"
"								   "));
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
        AccidentUpdateIDline->setStyleSheet(QLatin1String("\n"
"									   QLabel{\n"
"									   color:white\n"
"									   }\n"
"								   "));
        AccidentUpdateClientIDline = new QLabel(frame_3);
        AccidentUpdateClientIDline->setObjectName(QStringLiteral("AccidentUpdateClientIDline"));
        AccidentUpdateClientIDline->setGeometry(QRect(60, 80, 56, 16));
        AccidentUpdateClientIDline->setStyleSheet(QLatin1String("\n"
"									   QLabel{\n"
"									   color:white\n"
"									   }\n"
"								   "));
        AccidentUpdateTypeline = new QLabel(frame_3);
        AccidentUpdateTypeline->setObjectName(QStringLiteral("AccidentUpdateTypeline"));
        AccidentUpdateTypeline->setGeometry(QRect(60, 120, 56, 16));
        AccidentUpdateTypeline->setStyleSheet(QLatin1String("\n"
"									   QLabel{\n"
"									   color:white\n"
"									   }\n"
"								   "));
        AccidentUpdateDamageline = new QLabel(frame_3);
        AccidentUpdateDamageline->setObjectName(QStringLiteral("AccidentUpdateDamageline"));
        AccidentUpdateDamageline->setGeometry(QRect(60, 160, 56, 16));
        AccidentUpdateDamageline->setStyleSheet(QLatin1String("\n"
"									   QLabel{\n"
"									   color:white\n"
"									   }\n"
"								   "));
        AccidentUpdateDateline = new QLabel(frame_3);
        AccidentUpdateDateline->setObjectName(QStringLiteral("AccidentUpdateDateline"));
        AccidentUpdateDateline->setGeometry(QRect(60, 200, 56, 16));
        AccidentUpdateDateline->setStyleSheet(QLatin1String("\n"
"									   QLabel{\n"
"									   color:white\n"
"									   }\n"
"								   "));
        AccidentUpdateLocationline = new QLabel(frame_3);
        AccidentUpdateLocationline->setObjectName(QStringLiteral("AccidentUpdateLocationline"));
        AccidentUpdateLocationline->setGeometry(QRect(60, 240, 56, 16));
        AccidentUpdateLocationline->setStyleSheet(QLatin1String("\n"
"									   QLabel{\n"
"									   color:white\n"
"									   }\n"
"								   "));
        AccidentUpdateID = new QLineEdit(frame_3);
        AccidentUpdateID->setObjectName(QStringLiteral("AccidentUpdateID"));
        AccidentUpdateID->setGeometry(QRect(160, 40, 113, 22));
        AccidentUpdateType = new QLineEdit(frame_3);
        AccidentUpdateType->setObjectName(QStringLiteral("AccidentUpdateType"));
        AccidentUpdateType->setGeometry(QRect(160, 120, 113, 22));
        AccidentUpdateDamage = new QLineEdit(frame_3);
        AccidentUpdateDamage->setObjectName(QStringLiteral("AccidentUpdateDamage"));
        AccidentUpdateDamage->setGeometry(QRect(160, 160, 113, 22));
        AccidentUpdateLocation = new QLineEdit(frame_3);
        AccidentUpdateLocation->setObjectName(QStringLiteral("AccidentUpdateLocation"));
        AccidentUpdateLocation->setGeometry(QRect(160, 240, 113, 22));
        AccidentUpdate = new QPushButton(frame_3);
        AccidentUpdate->setObjectName(QStringLiteral("AccidentUpdate"));
        AccidentUpdate->setGeometry(QRect(330, 260, 93, 28));
        AccidentUpdateClientID = new QComboBox(frame_3);
        AccidentUpdateClientID->setObjectName(QStringLiteral("AccidentUpdateClientID"));
        AccidentUpdateClientID->setGeometry(QRect(160, 80, 113, 22));
        AccidentUpdateDate = new QDateEdit(frame_3);
        AccidentUpdateDate->setObjectName(QStringLiteral("AccidentUpdateDate"));
        AccidentUpdateDate->setGeometry(QRect(160, 200, 110, 25));
        StackedAccident->addWidget(UpdateAccident);
        StatsAccident = new QFrame(page_4);
        StatsAccident->setObjectName(QStringLiteral("StatsAccident"));
        StatsAccident->setGeometry(QRect(10, 10, 481, 251));
        StatsAccident->setFrameShape(QFrame::NoFrame);
        featureBarAccident = new QFrame(page_4);
        featureBarAccident->setObjectName(QStringLiteral("featureBarAccident"));
        featureBarAccident->setGeometry(QRect(510, 30, 601, 61));
        featureBarAccident->setStyleSheet(QStringLiteral(""));
        featureBarAccident->setFrameShape(QFrame::NoFrame);
        addAccident = new QPushButton(featureBarAccident);
        addAccident->setObjectName(QStringLiteral("addAccident"));
        addAccident->setGeometry(QRect(30, 10, 41, 41));
        addAccident->setCursor(QCursor(Qt::PointingHandCursor));
        addAccident->setIcon(icon);
        addAccident->setIconSize(QSize(60, 60));
        deleteAccident = new QPushButton(featureBarAccident);
        deleteAccident->setObjectName(QStringLiteral("deleteAccident"));
        deleteAccident->setGeometry(QRect(130, 10, 41, 41));
        deleteAccident->setCursor(QCursor(Qt::PointingHandCursor));
        deleteAccident->setIcon(icon1);
        deleteAccident->setIconSize(QSize(40, 40));
        updateAccident = new QPushButton(featureBarAccident);
        updateAccident->setObjectName(QStringLiteral("updateAccident"));
        updateAccident->setGeometry(QRect(330, 10, 41, 41));
        updateAccident->setCursor(QCursor(Qt::PointingHandCursor));
        updateAccident->setIcon(icon2);
        updateAccident->setIconSize(QSize(60, 60));
        pdfAccident = new QPushButton(featureBarAccident);
        pdfAccident->setObjectName(QStringLiteral("pdfAccident"));
        pdfAccident->setGeometry(QRect(430, 10, 41, 41));
        pdfAccident->setCursor(QCursor(Qt::PointingHandCursor));
        pdfAccident->setIcon(icon3);
        pdfAccident->setIconSize(QSize(50, 50));
        sortAccident = new QPushButton(featureBarAccident);
        sortAccident->setObjectName(QStringLiteral("sortAccident"));
        sortAccident->setGeometry(QRect(230, 10, 41, 41));
        sortAccident->setCursor(QCursor(Qt::PointingHandCursor));
        sortAccident->setIcon(icon4);
        sortAccident->setIconSize(QSize(50, 50));
        historyAccident = new QPushButton(featureBarAccident);
        historyAccident->setObjectName(QStringLiteral("historyAccident"));
        historyAccident->setGeometry(QRect(530, 10, 41, 41));
        QIcon icon7;
        icon7.addFile(QStringLiteral("../Resources/Icons/history.png"), QSize(), QIcon::Normal, QIcon::Off);
        historyAccident->setIcon(icon7);
        historyAccident->setIconSize(QSize(40, 40));
        tableAccident = new QTableWidget(page_4);
        if (tableAccident->columnCount() < 6)
            tableAccident->setColumnCount(6);
        QTableWidgetItem *__qtablewidgetitem24 = new QTableWidgetItem();
        tableAccident->setHorizontalHeaderItem(0, __qtablewidgetitem24);
        QTableWidgetItem *__qtablewidgetitem25 = new QTableWidgetItem();
        tableAccident->setHorizontalHeaderItem(1, __qtablewidgetitem25);
        QTableWidgetItem *__qtablewidgetitem26 = new QTableWidgetItem();
        tableAccident->setHorizontalHeaderItem(2, __qtablewidgetitem26);
        QTableWidgetItem *__qtablewidgetitem27 = new QTableWidgetItem();
        tableAccident->setHorizontalHeaderItem(3, __qtablewidgetitem27);
        QTableWidgetItem *__qtablewidgetitem28 = new QTableWidgetItem();
        tableAccident->setHorizontalHeaderItem(4, __qtablewidgetitem28);
        QTableWidgetItem *__qtablewidgetitem29 = new QTableWidgetItem();
        tableAccident->setHorizontalHeaderItem(5, __qtablewidgetitem29);
        tableAccident->setObjectName(QStringLiteral("tableAccident"));
        tableAccident->setGeometry(QRect(520, 210, 591, 421));
        tableAccident->setFont(font);
        tableAccident->setShowGrid(true);
        tableAccident->setSortingEnabled(true);
        tableAccident->horizontalHeader()->setDefaultSectionSize(125);
        tableAccident->horizontalHeader()->setMinimumSectionSize(50);
        tableAccident->verticalHeader()->setVisible(false);
        tableAccident->verticalHeader()->setDefaultSectionSize(20);
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
        QIcon icon8;
        icon8.addFile(QStringLiteral("../Resources/Icons/logout.png"), QSize(), QIcon::Normal, QIcon::Off);
        logoutButton->setIcon(icon8);
        logoutButton->setIconSize(QSize(20, 20));

        retranslateUi(Dashboard);

        stackedWidget->setCurrentIndex(1);
        CrudEmployee->setCurrentIndex(1);
        StackedClient->setCurrentIndex(1);
        StackContract->setCurrentIndex(0);
        StackedAccident->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Dashboard);
    } // setupUi

    void retranslateUi(QDialog *Dashboard)
    {
        Dashboard->setWindowTitle(QApplication::translate("Dashboard", "Dashboard", Q_NULLPTR));
        role->setPlaceholderText(QApplication::translate("Dashboard", "Role", Q_NULLPTR));
        logo->setText(QString());
        helloBar->setPlaceholderText(QApplication::translate("Dashboard", "Hello,First Name Last Name", Q_NULLPTR));
        addEmployee->setText(QString());
        deleteEmployee->setText(QString());
        updateEmployee->setText(QString());
        pdfEmployee->setText(QString());
        sortEmployee->setText(QString());
        EmployeeEmail_C->setPlaceholderText(QString());
        EmployeeLastNameText_C->setPlainText(QApplication::translate("Dashboard", "Last Name", Q_NULLPTR));
        EmployeeAddressText_C->setPlainText(QApplication::translate("Dashboard", "Address", Q_NULLPTR));
        EmployeePhoneNumber_C->setText(QString());
        EmployeeCreateBtn->setText(QApplication::translate("Dashboard", "Create ", Q_NULLPTR));
        EmployeeEmailText_C->setPlainText(QApplication::translate("Dashboard", "Email", Q_NULLPTR));
        EmployeePhoneNumberText_C->setPlainText(QApplication::translate("Dashboard", "Phone Number", Q_NULLPTR));
        EmployeeFirstNameText_C->setPlainText(QApplication::translate("Dashboard", "First Name", Q_NULLPTR));
        EmployeeDobText_C->setPlainText(QApplication::translate("Dashboard", "Date Of Birth", Q_NULLPTR));
        EmployeeRole_C->clear();
        EmployeeRole_C->insertItems(0, QStringList()
         << QString()
         << QApplication::translate("Dashboard", "Role 1", Q_NULLPTR)
         << QApplication::translate("Dashboard", "Role 3", Q_NULLPTR)
         << QApplication::translate("Dashboard", "Role 2", Q_NULLPTR)
        );
        EmployeeCancelBtn_C->setText(QApplication::translate("Dashboard", "Cancel", Q_NULLPTR));
        EmployeeRoleText_C->setPlainText(QApplication::translate("Dashboard", "Role", Q_NULLPTR));
        EmployeePassword_C->setPlaceholderText(QString());
        EmployeePasswordText_C->setPlainText(QApplication::translate("Dashboard", "Password", Q_NULLPTR));
        EmployeeFirstNameText_U->setPlainText(QApplication::translate("Dashboard", "First Name", Q_NULLPTR));
        EmployeePhoneNumberText_U->setPlainText(QApplication::translate("Dashboard", "Phone Number", Q_NULLPTR));
        EmployeePasswordText_U->setPlainText(QApplication::translate("Dashboard", "Password", Q_NULLPTR));
        EmployeePhoneNumber_U->setText(QString());
        EmployeeRole_U->clear();
        EmployeeRole_U->insertItems(0, QStringList()
         << QString()
         << QApplication::translate("Dashboard", "Role 1", Q_NULLPTR)
         << QApplication::translate("Dashboard", "Role 3", Q_NULLPTR)
         << QApplication::translate("Dashboard", "Role 2", Q_NULLPTR)
        );
        EmployeeEmail_U->setPlaceholderText(QString());
        EmployeeDobText_U->setPlainText(QApplication::translate("Dashboard", "Date Of Birth", Q_NULLPTR));
        EmployeeRoleText_U->setPlainText(QApplication::translate("Dashboard", "Role", Q_NULLPTR));
        EmployeeAddressText_U->setPlainText(QApplication::translate("Dashboard", "Address", Q_NULLPTR));
        EmployeeEmailText_U->setPlainText(QApplication::translate("Dashboard", "Email", Q_NULLPTR));
        EmployeeUpdateBtn->setText(QApplication::translate("Dashboard", "Update ", Q_NULLPTR));
        EmployeeLastNameText_U->setPlainText(QApplication::translate("Dashboard", "Last Name", Q_NULLPTR));
        EmployeePassword_U->setPlaceholderText(QString());
        EmployeeCancelBtn_U->setText(QApplication::translate("Dashboard", "Cancel", Q_NULLPTR));
        EmployeeSelectIDText_U->setText(QApplication::translate("Dashboard", "Select ID", Q_NULLPTR));
        EmployeeSelectID_U->clear();
        EmployeeSelectID_U->insertItems(0, QStringList()
         << QString()
        );
        EmployeeDeleteBtn->setText(QApplication::translate("Dashboard", "Delete", Q_NULLPTR));
        EmployeeSelectID_D->clear();
        EmployeeSelectID_D->insertItems(0, QStringList()
         << QString()
        );
        EmployeeSelectIDText_D->setText(QApplication::translate("Dashboard", "Select ID", Q_NULLPTR));
        EmployeeCancelBtn_D->setText(QApplication::translate("Dashboard", "Cancel", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem = tableEmployee->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("Dashboard", "ID", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem1 = tableEmployee->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("Dashboard", "Email", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem2 = tableEmployee->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("Dashboard", "Password", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem3 = tableEmployee->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("Dashboard", "Role", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem4 = tableEmployee->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("Dashboard", "First Name", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem5 = tableEmployee->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("Dashboard", "Last Name", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem6 = tableEmployee->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QApplication::translate("Dashboard", "Phone Number", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem7 = tableEmployee->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QApplication::translate("Dashboard", "Address", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem8 = tableEmployee->horizontalHeaderItem(8);
        ___qtablewidgetitem8->setText(QApplication::translate("Dashboard", "Date Of Birth", Q_NULLPTR));
        EmployeeSelectStats->clear();
        EmployeeSelectStats->insertItems(0, QStringList()
         << QString()
        );
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
        QRCodeClientCombo->clear();
        QRCodeClientCombo->insertItems(0, QStringList()
         << QApplication::translate("Dashboard", "Select a Client", Q_NULLPTR)
        );
        QRCodeClientCombo->setPlaceholderText(QString());
        QRCodeClientTitle->setPlainText(QApplication::translate("Dashboard", "QR Code", Q_NULLPTR));
        QRCodeClientLabel->setPlainText(QApplication::translate("Dashboard", "Client ID", Q_NULLPTR));
        QRCodeClientGenerate->setText(QApplication::translate("Dashboard", "Generate", Q_NULLPTR));
        QRCodeClientCancel->setText(QApplication::translate("Dashboard", "Cancel", Q_NULLPTR));
        deleteClient->setText(QString());
        updateClient->setText(QString());
        pdfClient->setText(QString());
        sortClient->setText(QString());
        addClient->setText(QString());
        pieChartClient->setText(QString());
        QTableWidgetItem *___qtablewidgetitem9 = tableClient->horizontalHeaderItem(0);
        ___qtablewidgetitem9->setText(QApplication::translate("Dashboard", "ID", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem10 = tableClient->horizontalHeaderItem(1);
        ___qtablewidgetitem10->setText(QApplication::translate("Dashboard", "Email", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem11 = tableClient->horizontalHeaderItem(2);
        ___qtablewidgetitem11->setText(QApplication::translate("Dashboard", "First Name", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem12 = tableClient->horizontalHeaderItem(3);
        ___qtablewidgetitem12->setText(QApplication::translate("Dashboard", "Last Name", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem13 = tableClient->horizontalHeaderItem(4);
        ___qtablewidgetitem13->setText(QApplication::translate("Dashboard", "Address", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem14 = tableClient->horizontalHeaderItem(5);
        ___qtablewidgetitem14->setText(QApplication::translate("Dashboard", "Phone Number", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem15 = tableClient->horizontalHeaderItem(6);
        ___qtablewidgetitem15->setText(QApplication::translate("Dashboard", "Date Of Birth", Q_NULLPTR));
        LabelUserIdContract->setText(QApplication::translate("Dashboard", "USER_ID", Q_NULLPTR));
        LabelClientIdContract->setText(QApplication::translate("Dashboard", "CLIENT_ID", Q_NULLPTR));
        LabelPremiumAmountContract->setText(QApplication::translate("Dashboard", "PREMIUM_AMOUNT", Q_NULLPTR));
        LabelEffectiveDateContract->setText(QApplication::translate("Dashboard", "EFFECTIVE_DATE", Q_NULLPTR));
        LabelExpirationDateContract->setText(QApplication::translate("Dashboard", "EXPIRATION_DATE", Q_NULLPTR));
        LabelPaymentStatusContract->setText(QApplication::translate("Dashboard", "PAYMENT_STATUS", Q_NULLPTR));
        LabelTypeContract->setText(QApplication::translate("Dashboard", "TYPE", Q_NULLPTR));
        CancelCreateContract->setText(QApplication::translate("Dashboard", "Cancel", Q_NULLPTR));
        CreateContractButton->setText(QApplication::translate("Dashboard", "Create Contract", Q_NULLPTR));
        LabelContractId->setText(QApplication::translate("Dashboard", "Contract_Id", Q_NULLPTR));
        CancelDeleteContract->setText(QApplication::translate("Dashboard", "Cancel", Q_NULLPTR));
        DeleteContractButton->setText(QApplication::translate("Dashboard", "Delete Contract", Q_NULLPTR));
        UpdateContractButton->setText(QApplication::translate("Dashboard", "Update Contract", Q_NULLPTR));
        CancelUpdateContract->setText(QApplication::translate("Dashboard", "Cancel", Q_NULLPTR));
        LabelUserIdContractUpdate->setText(QApplication::translate("Dashboard", "USER_ID", Q_NULLPTR));
        LabelClientIdContractUpdate->setText(QApplication::translate("Dashboard", "CLIENT_ID", Q_NULLPTR));
        LabelPremiumAmountContractUpdate->setText(QApplication::translate("Dashboard", "PREMIUM_AMOUNT", Q_NULLPTR));
        LabelEffectiveDateContractUpdate->setText(QApplication::translate("Dashboard", "EFFECTIVE_DATE", Q_NULLPTR));
        LabelExpirationDateContractUpdate->setText(QApplication::translate("Dashboard", "EXPIRATION_DATE", Q_NULLPTR));
        LabelPaymentStatusContractUpdate->setText(QApplication::translate("Dashboard", "PAYMENT_STATUS", Q_NULLPTR));
        LabelTypeContractUpdate->setText(QApplication::translate("Dashboard", "TYPE", Q_NULLPTR));
        labelContractIDUpdate->setText(QApplication::translate("Dashboard", "Contract_ID", Q_NULLPTR));
        addContract->setText(QString());
        deleteContract->setText(QString());
        updateContract->setText(QString());
        pdfContract->setText(QString());
        sortContract->setText(QString());
        excelContract->setText(QString());
        QTableWidgetItem *___qtablewidgetitem16 = tableContract->horizontalHeaderItem(0);
        ___qtablewidgetitem16->setText(QApplication::translate("Dashboard", "ID", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem17 = tableContract->horizontalHeaderItem(1);
        ___qtablewidgetitem17->setText(QApplication::translate("Dashboard", "User ID", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem18 = tableContract->horizontalHeaderItem(2);
        ___qtablewidgetitem18->setText(QApplication::translate("Dashboard", "Client ID", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem19 = tableContract->horizontalHeaderItem(3);
        ___qtablewidgetitem19->setText(QApplication::translate("Dashboard", "Premium Amount", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem20 = tableContract->horizontalHeaderItem(4);
        ___qtablewidgetitem20->setText(QApplication::translate("Dashboard", "Effective Date", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem21 = tableContract->horizontalHeaderItem(5);
        ___qtablewidgetitem21->setText(QApplication::translate("Dashboard", "Expiration Date", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem22 = tableContract->horizontalHeaderItem(6);
        ___qtablewidgetitem22->setText(QApplication::translate("Dashboard", "Payment Status", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem23 = tableContract->horizontalHeaderItem(7);
        ___qtablewidgetitem23->setText(QApplication::translate("Dashboard", "Type", Q_NULLPTR));
        AccidentCreateTypeline->setText(QApplication::translate("Dashboard", "Type", Q_NULLPTR));
        AccidentCreateDamageline->setText(QApplication::translate("Dashboard", "Damage", Q_NULLPTR));
        AccidentCreateDateline->setText(QApplication::translate("Dashboard", "Date", Q_NULLPTR));
        AccidentCreateLocationline->setText(QApplication::translate("Dashboard", "Location", Q_NULLPTR));
        AccidentCreateClientIDline->setText(QApplication::translate("Dashboard", "Client ID", Q_NULLPTR));
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
        addAccident->setText(QString());
        deleteAccident->setText(QString());
        updateAccident->setText(QString());
        pdfAccident->setText(QString());
        sortAccident->setText(QString());
        historyAccident->setText(QString());
        QTableWidgetItem *___qtablewidgetitem24 = tableAccident->horizontalHeaderItem(0);
        ___qtablewidgetitem24->setText(QApplication::translate("Dashboard", "ID", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem25 = tableAccident->horizontalHeaderItem(1);
        ___qtablewidgetitem25->setText(QApplication::translate("Dashboard", "Client ID", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem26 = tableAccident->horizontalHeaderItem(2);
        ___qtablewidgetitem26->setText(QApplication::translate("Dashboard", "Type", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem27 = tableAccident->horizontalHeaderItem(3);
        ___qtablewidgetitem27->setText(QApplication::translate("Dashboard", "Damage", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem28 = tableAccident->horizontalHeaderItem(4);
        ___qtablewidgetitem28->setText(QApplication::translate("Dashboard", "Date", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem29 = tableAccident->horizontalHeaderItem(5);
        ___qtablewidgetitem29->setText(QApplication::translate("Dashboard", "Location", Q_NULLPTR));
        employees->setText(QApplication::translate("Dashboard", "Employees", Q_NULLPTR));
        clients->setText(QApplication::translate("Dashboard", "Clients", Q_NULLPTR));
        contracts->setText(QApplication::translate("Dashboard", "Contracts", Q_NULLPTR));
        accidents->setText(QApplication::translate("Dashboard", "Accidents", Q_NULLPTR));
        logoutButton->setText(QApplication::translate("Dashboard", "Logout", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Dashboard: public Ui_Dashboard {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DASHBOARD_H
