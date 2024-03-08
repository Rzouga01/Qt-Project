/********************************************************************************
** Form generated from reading UI file 'dashboard.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DASHBOARD_H
#define UI_DASHBOARD_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
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
    QListWidget *readBoxEmployee;
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
    QComboBox *EmployeeSelectID_D;
    QLineEdit *EmployeeSelectIDText_D;
    QPushButton *EmployeeDeleteBtn;
    QFrame *statsEmployee;
    QLineEdit *searchBarEmployee;
    QTableWidget *tableEmployee;
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
            Dashboard->setObjectName("Dashboard");
        Dashboard->resize(1575, 800);
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
"#logoutButton,\n"
"#employees,\n"
"#clients,\n"
"#contracts,\n"
"#accidents {\n"
"    font-size: 15px;\n"
"    font-weight: bold;\n"
"    color: white; /* Set the default text color */\n"
"  "
                        "      background-color: #444444;;\n"
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
"#addEmployee::icon,\n"
"#delEmployee::icon,\n"
"#pdfEmployee::icon,\n"
"#updateEmployee::icon,\n"
"#sortEmployee::icon {\n"
"    padding: 0; /* Remove padding */\n"
""
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
        frame->setObjectName("frame");
        frame->setGeometry(QRect(0, -1, 1500, 800));
        frame->setStyleSheet(QString::fromUtf8(""));
        frame->setFrameShape(QFrame::NoFrame);
        role = new QLineEdit(frame);
        role->setObjectName("role");
        role->setGeometry(QRect(1160, 10, 281, 91));
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
        stackedWidget->setGeometry(QRect(330, 120, 1141, 841));
        page = new QWidget();
        page->setObjectName("page");
        page->setStyleSheet(QString::fromUtf8("#featureBarEmployee {\n"
"    background-color: white;\n"
"    border-radius: 25px;\n"
"}\n"
"\n"
"#CrudEmployee,\n"
"#CreateEmployee,\n"
"#UpdateEmployee,\n"
"#DeleteEmployee {\n"
"    background-color: #A7C34E;\n"
"    border-radius: 25px;\n"
"}\n"
"\n"
"#statsEmployee {\n"
"    background-color: #A7C34E;\n"
"    border-radius: 25px;\n"
"}\n"
"\n"
"#readBoxEmployee {\n"
"    border: none;\n"
"    background-color: #A7C34E;\n"
"    border-radius: 25px;\n"
"}\n"
"\n"
"#searchBarEmployee {\n"
"    background-color: white;\n"
"    border-radius: 20px;\n"
"}\n"
"\n"
"#addEmployee,\n"
"#deleteEmployee,\n"
"#pdfEmployee,\n"
"#updateEmployee,\n"
"#sortEmployee {\n"
"    border: none;\n"
"    background-color: transparent;\n"
"}\n"
"\n"
"#tableEmployee QTableWidget::item {\n"
"    color: white;\n"
"    font-family: \"Helvetica\";\n"
"    padding: 5px; \n"
"    min-height: 30px; \n"
"\n"
"}\n"
"#tableEmployee QHeaderView::section {\n"
"    background-color: #f2f2f2;\n"
"    border: 1px solid #dddddd;\n"
"    min-width"
                        ": 100px;\n"
"}\n"
"\n"
"/*Create*/\n"
"#EmployeeEmailText_C,\n"
"#EmployeePasswordText_C,\n"
"#EmployeeFirstNameText_C,\n"
"#EmployeeLastNameText_C,\n"
"#EmployeeAddressText_C,\n"
"#EmployeePhoneNumberText_C,\n"
"#EmployeeDobText_C,\n"
"#EmployeeRoleText_C,\n"
"#EmployeeSelectIDText_U {\n"
"    border: none; \n"
"    background-color: transparent; \n"
"    font-family: \"Helvetica\";\n"
"    font-size: 14px;\n"
"    color: white;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"#EmployeeEmail_C,\n"
"#EmployeePassword_C,\n"
"#EmployeeFirstName_C,\n"
"#EmployeeLastName_C,\n"
"#EmployeeAddress_C,\n"
"#EmployeePhoneNumber_C,a\n"
"#EmployeeDob_C,\n"
"#EmployeeRole_C,\n"
"#EmployeeSelectID_U {\n"
"    background-color: #444444;\n"
"    font-family: \"Helvetica\";\n"
"    font-size: 14px;\n"
"    color: white;\n"
"    font-weight: bold;\n"
"    border: none;\n"
"    border-radius: 15px;\n"
"}\n"
"\n"
"#EmployeeCancelBtn_C,\n"
"#EmployeeCreateBtn {\n"
"    background-color: #444444;\n"
"    color: white;\n"
"    font-family:"
                        " \"Helvetica\";\n"
"    font-size: 14px;\n"
"    font-weight: bold;\n"
"    border: none;\n"
"    border-radius: 15px;\n"
"    padding: 10px 20px;\n"
"    cursor: pointer;\n"
"    transition: background-color 0.3s ease;\n"
"}\n"
"\n"
"#EmployeeCancelBtn_C:hover,\n"
"#EmployeeCreateBtn:hover {\n"
"    background-color: #333333;\n"
"}\n"
"\n"
"/*Update*/\n"
"#EmployeeEmailText_U,\n"
"#EmployeePasswordText_U,\n"
"#EmployeeFirstNameText_U,\n"
"#EmployeeLastNameText_U,\n"
"#EmployeeAddressText_U,\n"
"#EmployeePhoneNumberText_U,\n"
"#EmployeeDobText_U,\n"
"#EmployeeRoleText_U {\n"
"    border: none; \n"
"    background-color: transparent; \n"
"    font-family: \"Helvetica\";\n"
"    font-size: 14px;\n"
"    color: white;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"#EmployeeEmail_U,\n"
"#EmployeePassword_U,\n"
"#EmployeeFirstName_U,\n"
"#EmployeeLastName_U,\n"
"#EmployeeAddress_U,\n"
"#EmployeePhoneNumber_U,\n"
"#EmployeeDob_U,\n"
"#EmployeeRole_U {\n"
"    background-color: #444444;\n"
"    font-family: \"Helvetica\";"
                        "\n"
"    font-size: 14px;\n"
"    color: white;\n"
"    font-weight: bold;\n"
"    border: none;\n"
"    border-radius: 15px;\n"
"}\n"
"#EmployeeCancelBtn_U,\n"
"#EmployeeUpdateBtn {\n"
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
"#EmployeeCancelBtn_U:hover,\n"
"#EmployeeUpdateBtn:hover {\n"
"    background-color: #333333;\n"
"}\n"
"/*Delete*/\n"
"#EmployeeSelectIDText_D {\n"
"    border: none;\n"
"    background-color: transparent;\n"
"    font-family: \"Helvetica\";\n"
"    font-size: 14px;\n"
"    color: white;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"#EmployeeSelectID_D {\n"
"    background-color: #444444;\n"
"    font-family: \"Helvetica\";\n"
"    font-size: 14px;\n"
"    color: white;\n"
"    font-weight: bold;\n"
"    border: none;\n"
"    border-"
                        "radius: 15px;\n"
"}\n"
"\n"
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
"#EmployeeCancelBtn_D:hover,\n"
"#EmployeeDeleteBtn:hover {\n"
"    background-color: #333333;\n"
"}\n"
""));
        featureBarEmployee = new QFrame(page);
        featureBarEmployee->setObjectName("featureBarEmployee");
        featureBarEmployee->setGeometry(QRect(620, 20, 501, 61));
        featureBarEmployee->setStyleSheet(QString::fromUtf8(""));
        featureBarEmployee->setFrameShape(QFrame::NoFrame);
        addEmployee = new QPushButton(featureBarEmployee);
        addEmployee->setObjectName("addEmployee");
        addEmployee->setGeometry(QRect(30, 10, 41, 41));
        addEmployee->setCursor(QCursor(Qt::PointingHandCursor));
        QIcon icon;
        icon.addFile(QString::fromUtf8("../Resources/Icons/add.png"), QSize(), QIcon::Normal, QIcon::Off);
        addEmployee->setIcon(icon);
        addEmployee->setIconSize(QSize(60, 60));
        deleteEmployee = new QPushButton(featureBarEmployee);
        deleteEmployee->setObjectName("deleteEmployee");
        deleteEmployee->setGeometry(QRect(130, 10, 41, 41));
        deleteEmployee->setCursor(QCursor(Qt::PointingHandCursor));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("../Resources/Icons/delete.png"), QSize(), QIcon::Normal, QIcon::Off);
        deleteEmployee->setIcon(icon1);
        deleteEmployee->setIconSize(QSize(40, 40));
        updateEmployee = new QPushButton(featureBarEmployee);
        updateEmployee->setObjectName("updateEmployee");
        updateEmployee->setGeometry(QRect(330, 10, 41, 41));
        updateEmployee->setCursor(QCursor(Qt::PointingHandCursor));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8("../Resources/Icons/update.png"), QSize(), QIcon::Normal, QIcon::Off);
        updateEmployee->setIcon(icon2);
        updateEmployee->setIconSize(QSize(60, 60));
        pdfEmployee = new QPushButton(featureBarEmployee);
        pdfEmployee->setObjectName("pdfEmployee");
        pdfEmployee->setGeometry(QRect(430, 10, 41, 41));
        pdfEmployee->setCursor(QCursor(Qt::PointingHandCursor));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8("../Resources/Icons/pdf.png"), QSize(), QIcon::Normal, QIcon::Off);
        pdfEmployee->setIcon(icon3);
        pdfEmployee->setIconSize(QSize(50, 50));
        sortEmployee = new QPushButton(featureBarEmployee);
        sortEmployee->setObjectName("sortEmployee");
        sortEmployee->setGeometry(QRect(230, 10, 41, 41));
        sortEmployee->setCursor(QCursor(Qt::PointingHandCursor));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8("../Resources/Icons/sort.png"), QSize(), QIcon::Normal, QIcon::Off);
        sortEmployee->setIcon(icon4);
        sortEmployee->setIconSize(QSize(50, 50));
        readBoxEmployee = new QListWidget(page);
        readBoxEmployee->setObjectName("readBoxEmployee");
        readBoxEmployee->setGeometry(QRect(500, 100, 631, 561));
        CrudEmployee = new QStackedWidget(page);
        CrudEmployee->setObjectName("CrudEmployee");
        CrudEmployee->setGeometry(QRect(10, 220, 460, 440));
        CrudEmployee->setFrameShape(QFrame::NoFrame);
        CreateEmployee = new QWidget();
        CreateEmployee->setObjectName("CreateEmployee");
        EmployeeEmail_C = new QLineEdit(CreateEmployee);
        EmployeeEmail_C->setObjectName("EmployeeEmail_C");
        EmployeeEmail_C->setGeometry(QRect(44, 65, 160, 30));
        EmployeeLastNameText_C = new QPlainTextEdit(CreateEmployee);
        EmployeeLastNameText_C->setObjectName("EmployeeLastNameText_C");
        EmployeeLastNameText_C->setGeometry(QRect(284, 115, 104, 31));
        EmployeeLastNameText_C->setTextInteractionFlags(Qt::NoTextInteraction);
        EmployeeAddress_C = new QLineEdit(CreateEmployee);
        EmployeeAddress_C->setObjectName("EmployeeAddress_C");
        EmployeeAddress_C->setGeometry(QRect(44, 225, 160, 30));
        EmployeeAddressText_C = new QPlainTextEdit(CreateEmployee);
        EmployeeAddressText_C->setObjectName("EmployeeAddressText_C");
        EmployeeAddressText_C->setGeometry(QRect(84, 195, 104, 31));
        EmployeeAddressText_C->setTextInteractionFlags(Qt::NoTextInteraction);
        EmployeeFirstName_C = new QLineEdit(CreateEmployee);
        EmployeeFirstName_C->setObjectName("EmployeeFirstName_C");
        EmployeeFirstName_C->setGeometry(QRect(44, 145, 160, 30));
        EmployeePhoneNumber_C = new QLineEdit(CreateEmployee);
        EmployeePhoneNumber_C->setObjectName("EmployeePhoneNumber_C");
        EmployeePhoneNumber_C->setGeometry(QRect(244, 225, 160, 30));
        EmployeeCreateBtn = new QPushButton(CreateEmployee);
        EmployeeCreateBtn->setObjectName("EmployeeCreateBtn");
        EmployeeCreateBtn->setGeometry(QRect(55, 355, 160, 40));
        EmployeeDob_C = new QDateEdit(CreateEmployee);
        EmployeeDob_C->setObjectName("EmployeeDob_C");
        EmployeeDob_C->setGeometry(QRect(44, 305, 160, 30));
        EmployeeLastName_C = new QLineEdit(CreateEmployee);
        EmployeeLastName_C->setObjectName("EmployeeLastName_C");
        EmployeeLastName_C->setGeometry(QRect(244, 145, 160, 30));
        EmployeeEmailText_C = new QPlainTextEdit(CreateEmployee);
        EmployeeEmailText_C->setObjectName("EmployeeEmailText_C");
        EmployeeEmailText_C->setGeometry(QRect(98, 35, 61, 31));
        EmployeeEmailText_C->setTextInteractionFlags(Qt::NoTextInteraction);
        EmployeePhoneNumberText_C = new QPlainTextEdit(CreateEmployee);
        EmployeePhoneNumberText_C->setObjectName("EmployeePhoneNumberText_C");
        EmployeePhoneNumberText_C->setGeometry(QRect(264, 195, 141, 31));
        EmployeePhoneNumberText_C->setTextInteractionFlags(Qt::NoTextInteraction);
        EmployeeFirstNameText_C = new QPlainTextEdit(CreateEmployee);
        EmployeeFirstNameText_C->setObjectName("EmployeeFirstNameText_C");
        EmployeeFirstNameText_C->setGeometry(QRect(84, 115, 91, 31));
        EmployeeFirstNameText_C->setTextInteractionFlags(Qt::NoTextInteraction);
        EmployeeDobText_C = new QPlainTextEdit(CreateEmployee);
        EmployeeDobText_C->setObjectName("EmployeeDobText_C");
        EmployeeDobText_C->setGeometry(QRect(84, 275, 104, 31));
        EmployeeDobText_C->setTextInteractionFlags(Qt::NoTextInteraction);
        EmployeeRole_C = new QComboBox(CreateEmployee);
        EmployeeRole_C->addItem(QString());
        EmployeeRole_C->addItem(QString());
        EmployeeRole_C->addItem(QString());
        EmployeeRole_C->addItem(QString());
        EmployeeRole_C->setObjectName("EmployeeRole_C");
        EmployeeRole_C->setGeometry(QRect(244, 305, 160, 30));
        EmployeeCancelBtn_C = new QPushButton(CreateEmployee);
        EmployeeCancelBtn_C->setObjectName("EmployeeCancelBtn_C");
        EmployeeCancelBtn_C->setGeometry(QRect(240, 355, 160, 40));
        EmployeeRoleText_C = new QPlainTextEdit(CreateEmployee);
        EmployeeRoleText_C->setObjectName("EmployeeRoleText_C");
        EmployeeRoleText_C->setGeometry(QRect(304, 275, 104, 31));
        EmployeeRoleText_C->setTextInteractionFlags(Qt::NoTextInteraction);
        EmployeePassword_C = new QLineEdit(CreateEmployee);
        EmployeePassword_C->setObjectName("EmployeePassword_C");
        EmployeePassword_C->setGeometry(QRect(244, 65, 160, 30));
        EmployeePasswordText_C = new QPlainTextEdit(CreateEmployee);
        EmployeePasswordText_C->setObjectName("EmployeePasswordText_C");
        EmployeePasswordText_C->setGeometry(QRect(284, 35, 141, 31));
        EmployeePasswordText_C->setTextInteractionFlags(Qt::NoTextInteraction);
        CrudEmployee->addWidget(CreateEmployee);
        UpdateEmployee = new QWidget();
        UpdateEmployee->setObjectName("UpdateEmployee");
        EmployeeFirstNameText_U = new QPlainTextEdit(UpdateEmployee);
        EmployeeFirstNameText_U->setObjectName("EmployeeFirstNameText_U");
        EmployeeFirstNameText_U->setGeometry(QRect(79, 145, 91, 31));
        EmployeeFirstNameText_U->setTextInteractionFlags(Qt::NoTextInteraction);
        EmployeePhoneNumberText_U = new QPlainTextEdit(UpdateEmployee);
        EmployeePhoneNumberText_U->setObjectName("EmployeePhoneNumberText_U");
        EmployeePhoneNumberText_U->setGeometry(QRect(259, 225, 141, 31));
        EmployeePhoneNumberText_U->setTextInteractionFlags(Qt::NoTextInteraction);
        EmployeeFirstName_U = new QLineEdit(UpdateEmployee);
        EmployeeFirstName_U->setObjectName("EmployeeFirstName_U");
        EmployeeFirstName_U->setGeometry(QRect(39, 175, 160, 30));
        EmployeeLastName_U = new QLineEdit(UpdateEmployee);
        EmployeeLastName_U->setObjectName("EmployeeLastName_U");
        EmployeeLastName_U->setGeometry(QRect(239, 175, 160, 30));
        EmployeeDob_U = new QDateEdit(UpdateEmployee);
        EmployeeDob_U->setObjectName("EmployeeDob_U");
        EmployeeDob_U->setGeometry(QRect(39, 335, 160, 30));
        EmployeePasswordText_U = new QPlainTextEdit(UpdateEmployee);
        EmployeePasswordText_U->setObjectName("EmployeePasswordText_U");
        EmployeePasswordText_U->setGeometry(QRect(279, 65, 141, 31));
        EmployeePasswordText_U->setTextInteractionFlags(Qt::NoTextInteraction);
        EmployeePhoneNumber_U = new QLineEdit(UpdateEmployee);
        EmployeePhoneNumber_U->setObjectName("EmployeePhoneNumber_U");
        EmployeePhoneNumber_U->setGeometry(QRect(239, 255, 160, 30));
        EmployeeRole_U = new QComboBox(UpdateEmployee);
        EmployeeRole_U->addItem(QString());
        EmployeeRole_U->addItem(QString());
        EmployeeRole_U->addItem(QString());
        EmployeeRole_U->addItem(QString());
        EmployeeRole_U->setObjectName("EmployeeRole_U");
        EmployeeRole_U->setGeometry(QRect(239, 335, 160, 30));
        EmployeeEmail_U = new QLineEdit(UpdateEmployee);
        EmployeeEmail_U->setObjectName("EmployeeEmail_U");
        EmployeeEmail_U->setGeometry(QRect(39, 95, 160, 30));
        EmployeeDobText_U = new QPlainTextEdit(UpdateEmployee);
        EmployeeDobText_U->setObjectName("EmployeeDobText_U");
        EmployeeDobText_U->setGeometry(QRect(79, 305, 104, 31));
        EmployeeDobText_U->setTextInteractionFlags(Qt::NoTextInteraction);
        EmployeeRoleText_U = new QPlainTextEdit(UpdateEmployee);
        EmployeeRoleText_U->setObjectName("EmployeeRoleText_U");
        EmployeeRoleText_U->setGeometry(QRect(299, 305, 104, 31));
        EmployeeRoleText_U->setTextInteractionFlags(Qt::NoTextInteraction);
        EmployeeAddressText_U = new QPlainTextEdit(UpdateEmployee);
        EmployeeAddressText_U->setObjectName("EmployeeAddressText_U");
        EmployeeAddressText_U->setGeometry(QRect(79, 225, 104, 31));
        EmployeeAddressText_U->setTextInteractionFlags(Qt::NoTextInteraction);
        EmployeeEmailText_U = new QPlainTextEdit(UpdateEmployee);
        EmployeeEmailText_U->setObjectName("EmployeeEmailText_U");
        EmployeeEmailText_U->setGeometry(QRect(93, 65, 61, 31));
        EmployeeEmailText_U->setTextInteractionFlags(Qt::NoTextInteraction);
        EmployeeUpdateBtn = new QPushButton(UpdateEmployee);
        EmployeeUpdateBtn->setObjectName("EmployeeUpdateBtn");
        EmployeeUpdateBtn->setGeometry(QRect(49, 385, 160, 40));
        EmployeeLastNameText_U = new QPlainTextEdit(UpdateEmployee);
        EmployeeLastNameText_U->setObjectName("EmployeeLastNameText_U");
        EmployeeLastNameText_U->setGeometry(QRect(279, 145, 104, 31));
        EmployeeLastNameText_U->setTextInteractionFlags(Qt::NoTextInteraction);
        EmployeePassword_U = new QLineEdit(UpdateEmployee);
        EmployeePassword_U->setObjectName("EmployeePassword_U");
        EmployeePassword_U->setGeometry(QRect(239, 95, 160, 30));
        EmployeeAddress_U = new QLineEdit(UpdateEmployee);
        EmployeeAddress_U->setObjectName("EmployeeAddress_U");
        EmployeeAddress_U->setGeometry(QRect(39, 255, 160, 30));
        EmployeeCancelBtn_U = new QPushButton(UpdateEmployee);
        EmployeeCancelBtn_U->setObjectName("EmployeeCancelBtn_U");
        EmployeeCancelBtn_U->setGeometry(QRect(249, 385, 160, 40));
        EmployeeSelectIDText_U = new QLineEdit(UpdateEmployee);
        EmployeeSelectIDText_U->setObjectName("EmployeeSelectIDText_U");
        EmployeeSelectIDText_U->setGeometry(QRect(10, 30, 113, 24));
        EmployeeSelectID_U = new QComboBox(UpdateEmployee);
        EmployeeSelectID_U->addItem(QString());
        EmployeeSelectID_U->setObjectName("EmployeeSelectID_U");
        EmployeeSelectID_U->setGeometry(QRect(80, 30, 81, 31));
        CrudEmployee->addWidget(UpdateEmployee);
        DeleteEmployee = new QWidget();
        DeleteEmployee->setObjectName("DeleteEmployee");
        EmployeeSelectID_D = new QComboBox(DeleteEmployee);
        EmployeeSelectID_D->setObjectName("EmployeeSelectID_D");
        EmployeeSelectID_D->setGeometry(QRect(210, 110, 151, 31));
        EmployeeSelectIDText_D = new QLineEdit(DeleteEmployee);
        EmployeeSelectIDText_D->setObjectName("EmployeeSelectIDText_D");
        EmployeeSelectIDText_D->setGeometry(QRect(80, 110, 113, 24));
        EmployeeDeleteBtn = new QPushButton(DeleteEmployee);
        EmployeeDeleteBtn->setObjectName("EmployeeDeleteBtn");
        EmployeeDeleteBtn->setGeometry(QRect(160, 180, 111, 51));
        CrudEmployee->addWidget(DeleteEmployee);
        statsEmployee = new QFrame(page);
        statsEmployee->setObjectName("statsEmployee");
        statsEmployee->setGeometry(QRect(10, 10, 461, 201));
        statsEmployee->setFrameShape(QFrame::NoFrame);
        searchBarEmployee = new QLineEdit(page);
        searchBarEmployee->setObjectName("searchBarEmployee");
        searchBarEmployee->setGeometry(QRect(750, 110, 361, 41));
        searchBarEmployee->setStyleSheet(QString::fromUtf8(""));
        searchBarEmployee->setClearButtonEnabled(true);
        tableEmployee = new QTableWidget(page);
        if (tableEmployee->columnCount() < 8)
            tableEmployee->setColumnCount(8);
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
        tableEmployee->setObjectName("tableEmployee");
        tableEmployee->setGeometry(QRect(500, 180, 631, 251));
        QFont font;
        font.setFamilies({QString::fromUtf8("Helvetica")});
        tableEmployee->setFont(font);
        tableEmployee->setStyleSheet(QString::fromUtf8("tableEmployee {\n"
"    color: white;\n"
"    font-family: \"Helvetica\";\n"
"}\n"
""));
        tableEmployee->setShowGrid(true);
        tableEmployee->setSortingEnabled(true);
        tableEmployee->horizontalHeader()->setCascadingSectionResizes(true);
        tableEmployee->horizontalHeader()->setMinimumSectionSize(20);
        tableEmployee->verticalHeader()->setVisible(false);
        tableEmployee->verticalHeader()->setMinimumSectionSize(10);
        tableEmployee->verticalHeader()->setDefaultSectionSize(10);
        tableEmployee->verticalHeader()->setHighlightSections(false);
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName("page_2");
        page_2->setStyleSheet(QString::fromUtf8("\n"
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
"    border: none; \n"
"    background-color: transparent; \n"
"    font-family: \"helvetica\";\n"
"    font"
                        "-size: 14px;\n"
"    color: white;\n"
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
"   "
                        " font-family: \"helvetica\";\n"
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
        readBoxClient->setObjectName("readBoxClient");
        readBoxClient->setGeometry(QRect(420, 100, 711, 561));
        searchBarClient = new QLineEdit(page_2);
        searchBarClient->setObjectName("searchBarClient");
        searchBarClient->setGeometry(QRect(720, 120, 391, 41));
        searchBarClient->setStyleSheet(QString::fromUtf8(""));
        searchBarClient->setClearButtonEnabled(true);
        CrudClient = new QFrame(page_2);
        CrudClient->setObjectName("CrudClient");
        CrudClient->setGeometry(QRect(10, 230, 371, 431));
        CrudClient->setFrameShape(QFrame::NoFrame);
        StackedClient = new QStackedWidget(CrudClient);
        StackedClient->setObjectName("StackedClient");
        StackedClient->setGeometry(QRect(-20, 0, 391, 431));
        CreateClientPage = new QWidget();
        CreateClientPage->setObjectName("CreateClientPage");
        CreateClient = new QFrame(CreateClientPage);
        CreateClient->setObjectName("CreateClient");
        CreateClient->setGeometry(QRect(20, 0, 371, 431));
        CreateClient->setFrameShape(QFrame::StyledPanel);
        CreateClient->setFrameShadow(QFrame::Raised);
        ClientCreateEmail = new QLineEdit(CreateClient);
        ClientCreateEmail->setObjectName("ClientCreateEmail");
        ClientCreateEmail->setGeometry(QRect(190, 50, 151, 31));
        ClientCreateFirstName = new QLineEdit(CreateClient);
        ClientCreateFirstName->setObjectName("ClientCreateFirstName");
        ClientCreateFirstName->setGeometry(QRect(190, 100, 151, 31));
        ClientCreateLastName = new QLineEdit(CreateClient);
        ClientCreateLastName->setObjectName("ClientCreateLastName");
        ClientCreateLastName->setGeometry(QRect(190, 150, 151, 31));
        ClientCreateDob = new QDateEdit(CreateClient);
        ClientCreateDob->setObjectName("ClientCreateDob");
        ClientCreateDob->setGeometry(QRect(190, 300, 151, 31));
        ClientCreateAddress = new QLineEdit(CreateClient);
        ClientCreateAddress->setObjectName("ClientCreateAddress");
        ClientCreateAddress->setGeometry(QRect(190, 200, 151, 31));
        ClientCreatePhoneNumber = new QLineEdit(CreateClient);
        ClientCreatePhoneNumber->setObjectName("ClientCreatePhoneNumber");
        ClientCreatePhoneNumber->setGeometry(QRect(190, 250, 151, 31));
        ClientCreateButton = new QPushButton(CreateClient);
        ClientCreateButton->setObjectName("ClientCreateButton");
        ClientCreateButton->setGeometry(QRect(60, 380, 80, 24));
        ClientCreateCancel = new QPushButton(CreateClient);
        ClientCreateCancel->setObjectName("ClientCreateCancel");
        ClientCreateCancel->setGeometry(QRect(230, 380, 80, 24));
        ClientCreateEmailLine = new QPlainTextEdit(CreateClient);
        ClientCreateEmailLine->setObjectName("ClientCreateEmailLine");
        ClientCreateEmailLine->setGeometry(QRect(50, 50, 104, 31));
        ClientCreateEmailLine->setTextInteractionFlags(Qt::NoTextInteraction);
        ClientCreateFirstNameLine = new QPlainTextEdit(CreateClient);
        ClientCreateFirstNameLine->setObjectName("ClientCreateFirstNameLine");
        ClientCreateFirstNameLine->setGeometry(QRect(50, 100, 104, 31));
        ClientCreateFirstNameLine->setTextInteractionFlags(Qt::NoTextInteraction);
        ClientCreateLastNameLine = new QPlainTextEdit(CreateClient);
        ClientCreateLastNameLine->setObjectName("ClientCreateLastNameLine");
        ClientCreateLastNameLine->setGeometry(QRect(50, 150, 104, 31));
        ClientCreateLastNameLine->setTextInteractionFlags(Qt::NoTextInteraction);
        ClientCreateAddressLine = new QPlainTextEdit(CreateClient);
        ClientCreateAddressLine->setObjectName("ClientCreateAddressLine");
        ClientCreateAddressLine->setGeometry(QRect(50, 200, 104, 31));
        ClientCreateAddressLine->setTextInteractionFlags(Qt::NoTextInteraction);
        ClientCreatePhoneNumberLine = new QPlainTextEdit(CreateClient);
        ClientCreatePhoneNumberLine->setObjectName("ClientCreatePhoneNumberLine");
        ClientCreatePhoneNumberLine->setGeometry(QRect(50, 250, 104, 31));
        ClientCreatePhoneNumberLine->setTextInteractionFlags(Qt::NoTextInteraction);
        ClientCreateDobLine = new QPlainTextEdit(CreateClient);
        ClientCreateDobLine->setObjectName("ClientCreateDobLine");
        ClientCreateDobLine->setGeometry(QRect(50, 300, 104, 31));
        ClientCreateDobLine->setTextInteractionFlags(Qt::NoTextInteraction);
        StackedClient->addWidget(CreateClientPage);
        UpdateClientPage = new QWidget();
        UpdateClientPage->setObjectName("UpdateClientPage");
        UpdateClient = new QFrame(UpdateClientPage);
        UpdateClient->setObjectName("UpdateClient");
        UpdateClient->setGeometry(QRect(20, 0, 371, 431));
        UpdateClient->setFrameShape(QFrame::StyledPanel);
        UpdateClient->setFrameShadow(QFrame::Raised);
        ClientUpdateID = new QLineEdit(UpdateClient);
        ClientUpdateID->setObjectName("ClientUpdateID");
        ClientUpdateID->setGeometry(QRect(190, 30, 151, 31));
        ClientUpdateEmail = new QLineEdit(UpdateClient);
        ClientUpdateEmail->setObjectName("ClientUpdateEmail");
        ClientUpdateEmail->setGeometry(QRect(190, 80, 151, 31));
        ClientUpdateFirstName = new QLineEdit(UpdateClient);
        ClientUpdateFirstName->setObjectName("ClientUpdateFirstName");
        ClientUpdateFirstName->setGeometry(QRect(190, 130, 151, 31));
        ClientUpdateLastName = new QLineEdit(UpdateClient);
        ClientUpdateLastName->setObjectName("ClientUpdateLastName");
        ClientUpdateLastName->setGeometry(QRect(190, 180, 151, 31));
        ClientUpdateDob = new QDateEdit(UpdateClient);
        ClientUpdateDob->setObjectName("ClientUpdateDob");
        ClientUpdateDob->setGeometry(QRect(190, 330, 151, 31));
        ClientUpdateAddress = new QLineEdit(UpdateClient);
        ClientUpdateAddress->setObjectName("ClientUpdateAddress");
        ClientUpdateAddress->setGeometry(QRect(190, 230, 151, 31));
        ClientUpdatePhoneNumber = new QLineEdit(UpdateClient);
        ClientUpdatePhoneNumber->setObjectName("ClientUpdatePhoneNumber");
        ClientUpdatePhoneNumber->setGeometry(QRect(190, 280, 151, 31));
        ClientUpdateButton = new QPushButton(UpdateClient);
        ClientUpdateButton->setObjectName("ClientUpdateButton");
        ClientUpdateButton->setGeometry(QRect(60, 380, 80, 24));
        ClientUpdateCancel = new QPushButton(UpdateClient);
        ClientUpdateCancel->setObjectName("ClientUpdateCancel");
        ClientUpdateCancel->setGeometry(QRect(230, 380, 80, 24));
        ClientUpdateIDLine = new QPlainTextEdit(UpdateClient);
        ClientUpdateIDLine->setObjectName("ClientUpdateIDLine");
        ClientUpdateIDLine->setGeometry(QRect(50, 30, 104, 31));
        ClientUpdateIDLine->setTextInteractionFlags(Qt::NoTextInteraction);
        ClientUpdateEmailLine = new QPlainTextEdit(UpdateClient);
        ClientUpdateEmailLine->setObjectName("ClientUpdateEmailLine");
        ClientUpdateEmailLine->setGeometry(QRect(50, 80, 104, 31));
        ClientUpdateEmailLine->setTextInteractionFlags(Qt::NoTextInteraction);
        ClientUpdateFirstNameLine = new QPlainTextEdit(UpdateClient);
        ClientUpdateFirstNameLine->setObjectName("ClientUpdateFirstNameLine");
        ClientUpdateFirstNameLine->setGeometry(QRect(50, 130, 104, 31));
        ClientUpdateFirstNameLine->setTextInteractionFlags(Qt::NoTextInteraction);
        ClientUpdateLastNameLine = new QPlainTextEdit(UpdateClient);
        ClientUpdateLastNameLine->setObjectName("ClientUpdateLastNameLine");
        ClientUpdateLastNameLine->setGeometry(QRect(50, 180, 104, 31));
        ClientUpdateLastNameLine->setTextInteractionFlags(Qt::NoTextInteraction);
        ClientUpdateAddressLine = new QPlainTextEdit(UpdateClient);
        ClientUpdateAddressLine->setObjectName("ClientUpdateAddressLine");
        ClientUpdateAddressLine->setGeometry(QRect(50, 230, 104, 31));
        ClientUpdateAddressLine->setTextInteractionFlags(Qt::NoTextInteraction);
        ClientUpdatePhoneNumberLine = new QPlainTextEdit(UpdateClient);
        ClientUpdatePhoneNumberLine->setObjectName("ClientUpdatePhoneNumberLine");
        ClientUpdatePhoneNumberLine->setGeometry(QRect(50, 280, 104, 31));
        ClientUpdatePhoneNumberLine->setTextInteractionFlags(Qt::NoTextInteraction);
        ClientUpdateDobLine = new QPlainTextEdit(UpdateClient);
        ClientUpdateDobLine->setObjectName("ClientUpdateDobLine");
        ClientUpdateDobLine->setGeometry(QRect(50, 330, 104, 31));
        ClientUpdateDobLine->setTextInteractionFlags(Qt::NoTextInteraction);
        StackedClient->addWidget(UpdateClientPage);
        DeleteClientPage = new QWidget();
        DeleteClientPage->setObjectName("DeleteClientPage");
        DeleteClient = new QFrame(DeleteClientPage);
        DeleteClient->setObjectName("DeleteClient");
        DeleteClient->setGeometry(QRect(20, 0, 371, 431));
        DeleteClient->setFrameShape(QFrame::StyledPanel);
        DeleteClient->setFrameShadow(QFrame::Raised);
        ClientDeleteID = new QLineEdit(DeleteClient);
        ClientDeleteID->setObjectName("ClientDeleteID");
        ClientDeleteID->setGeometry(QRect(190, 30, 151, 31));
        ClientDeleteButton = new QPushButton(DeleteClient);
        ClientDeleteButton->setObjectName("ClientDeleteButton");
        ClientDeleteButton->setGeometry(QRect(60, 380, 80, 24));
        ClientDeleteCancel = new QPushButton(DeleteClient);
        ClientDeleteCancel->setObjectName("ClientDeleteCancel");
        ClientDeleteCancel->setGeometry(QRect(230, 380, 80, 24));
        ClientDeleteIDLine = new QPlainTextEdit(DeleteClient);
        ClientDeleteIDLine->setObjectName("ClientDeleteIDLine");
        ClientDeleteIDLine->setGeometry(QRect(50, 30, 104, 31));
        ClientDeleteIDLine->setTextInteractionFlags(Qt::NoTextInteraction);
        StackedClient->addWidget(DeleteClientPage);
        statsClient = new QFrame(page_2);
        statsClient->setObjectName("statsClient");
        statsClient->setGeometry(QRect(10, 10, 371, 201));
        statsClient->setFrameShape(QFrame::NoFrame);
        featureBarClient = new QFrame(page_2);
        featureBarClient->setObjectName("featureBarClient");
        featureBarClient->setGeometry(QRect(620, 20, 501, 61));
        featureBarClient->setStyleSheet(QString::fromUtf8(""));
        featureBarClient->setFrameShape(QFrame::NoFrame);
        deleteClient = new QPushButton(featureBarClient);
        deleteClient->setObjectName("deleteClient");
        deleteClient->setGeometry(QRect(130, 10, 41, 41));
        deleteClient->setCursor(QCursor(Qt::PointingHandCursor));
        deleteClient->setIcon(icon1);
        deleteClient->setIconSize(QSize(40, 40));
        updateClient = new QPushButton(featureBarClient);
        updateClient->setObjectName("updateClient");
        updateClient->setGeometry(QRect(330, 10, 41, 41));
        updateClient->setCursor(QCursor(Qt::PointingHandCursor));
        updateClient->setIcon(icon2);
        updateClient->setIconSize(QSize(60, 60));
        pdfClient = new QPushButton(featureBarClient);
        pdfClient->setObjectName("pdfClient");
        pdfClient->setGeometry(QRect(430, 10, 41, 41));
        pdfClient->setCursor(QCursor(Qt::PointingHandCursor));
        pdfClient->setIcon(icon3);
        pdfClient->setIconSize(QSize(50, 50));
        sortClient = new QPushButton(featureBarClient);
        sortClient->setObjectName("sortClient");
        sortClient->setGeometry(QRect(230, 10, 41, 41));
        sortClient->setCursor(QCursor(Qt::PointingHandCursor));
        sortClient->setIcon(icon4);
        sortClient->setIconSize(QSize(50, 50));
        addClient = new QPushButton(featureBarClient);
        addClient->setObjectName("addClient");
        addClient->setGeometry(QRect(30, 10, 41, 41));
        addClient->setCursor(QCursor(Qt::PointingHandCursor));
        addClient->setIcon(icon);
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
        tableClient->setObjectName("tableClient");
        tableClient->setGeometry(QRect(430, 180, 681, 461));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("JetBrains Mono")});
        font1.setPointSize(10);
        tableClient->setFont(font1);
        tableClient->setAutoFillBackground(false);
        tableClient->setShowGrid(true);
        tableClient->setSortingEnabled(true);
        tableClient->horizontalHeader()->setMinimumSectionSize(50);
        tableClient->horizontalHeader()->setDefaultSectionSize(66);
        tableClient->verticalHeader()->setVisible(false);
        tableClient->verticalHeader()->setMinimumSectionSize(10);
        tableClient->verticalHeader()->setDefaultSectionSize(10);
        tableClient->verticalHeader()->setHighlightSections(false);
        stackedWidget->addWidget(page_2);
        page_3 = new QWidget();
        page_3->setObjectName("page_3");
        addFeature_3 = new QFrame(page_3);
        addFeature_3->setObjectName("addFeature_3");
        addFeature_3->setGeometry(QRect(10, 10, 371, 201));
        addFeature_3->setFrameShape(QFrame::NoFrame);
        stats_3 = new QFrame(page_3);
        stats_3->setObjectName("stats_3");
        stats_3->setGeometry(QRect(10, 230, 371, 231));
        stats_3->setFrameShape(QFrame::NoFrame);
        readBox_3 = new QListWidget(page_3);
        readBox_3->setObjectName("readBox_3");
        readBox_3->setGeometry(QRect(400, 90, 501, 371));
        searchBar_3 = new QLineEdit(page_3);
        searchBar_3->setObjectName("searchBar_3");
        searchBar_3->setGeometry(QRect(620, 120, 241, 41));
        searchBar_3->setStyleSheet(QString::fromUtf8(""));
        searchBar_3->setClearButtonEnabled(true);
        featureBar_3 = new QFrame(page_3);
        featureBar_3->setObjectName("featureBar_3");
        featureBar_3->setGeometry(QRect(400, 10, 501, 61));
        featureBar_3->setStyleSheet(QString::fromUtf8(""));
        featureBar_3->setFrameShape(QFrame::NoFrame);
        add_3 = new QPushButton(featureBar_3);
        add_3->setObjectName("add_3");
        add_3->setGeometry(QRect(30, 10, 41, 41));
        add_3->setCursor(QCursor(Qt::PointingHandCursor));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8("../../../../.designer/Resources/Icons/add.png"), QSize(), QIcon::Normal, QIcon::Off);
        add_3->setIcon(icon5);
        add_3->setIconSize(QSize(60, 60));
        del_3 = new QPushButton(featureBar_3);
        del_3->setObjectName("del_3");
        del_3->setGeometry(QRect(130, 10, 41, 41));
        del_3->setCursor(QCursor(Qt::PointingHandCursor));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8("../../../../.designer/Resources/Icons/delete.png"), QSize(), QIcon::Normal, QIcon::Off);
        del_3->setIcon(icon6);
        del_3->setIconSize(QSize(40, 40));
        update_3 = new QPushButton(featureBar_3);
        update_3->setObjectName("update_3");
        update_3->setGeometry(QRect(330, 10, 41, 41));
        update_3->setCursor(QCursor(Qt::PointingHandCursor));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8("../../../../.designer/Resources/Icons/update.png"), QSize(), QIcon::Normal, QIcon::Off);
        update_3->setIcon(icon7);
        update_3->setIconSize(QSize(60, 60));
        pdf_3 = new QPushButton(featureBar_3);
        pdf_3->setObjectName("pdf_3");
        pdf_3->setGeometry(QRect(430, 10, 41, 41));
        pdf_3->setCursor(QCursor(Qt::PointingHandCursor));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8("../../../../.designer/Resources/Icons/pdf.png"), QSize(), QIcon::Normal, QIcon::Off);
        pdf_3->setIcon(icon8);
        pdf_3->setIconSize(QSize(50, 50));
        sort_3 = new QPushButton(featureBar_3);
        sort_3->setObjectName("sort_3");
        sort_3->setGeometry(QRect(230, 10, 41, 41));
        sort_3->setCursor(QCursor(Qt::PointingHandCursor));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8("../../../../.designer/Resources/Icons/sort.png"), QSize(), QIcon::Normal, QIcon::Off);
        sort_3->setIcon(icon9);
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
        tableWidget_3->setObjectName("tableWidget_3");
        tableWidget_3->setGeometry(QRect(400, 170, 501, 261));
        tableWidget_3->setFont(font1);
        tableWidget_3->setShowGrid(true);
        tableWidget_3->setSortingEnabled(true);
        tableWidget_3->horizontalHeader()->setMinimumSectionSize(50);
        tableWidget_3->horizontalHeader()->setDefaultSectionSize(62);
        tableWidget_3->verticalHeader()->setVisible(false);
        tableWidget_3->verticalHeader()->setMinimumSectionSize(10);
        tableWidget_3->verticalHeader()->setDefaultSectionSize(10);
        tableWidget_3->verticalHeader()->setHighlightSections(false);
        stackedWidget->addWidget(page_3);
        page_4 = new QWidget();
        page_4->setObjectName("page_4");
        readBox_4 = new QListWidget(page_4);
        readBox_4->setObjectName("readBox_4");
        readBox_4->setGeometry(QRect(400, 90, 501, 371));
        searchBar_4 = new QLineEdit(page_4);
        searchBar_4->setObjectName("searchBar_4");
        searchBar_4->setGeometry(QRect(620, 120, 241, 41));
        searchBar_4->setStyleSheet(QString::fromUtf8(""));
        searchBar_4->setClearButtonEnabled(true);
        stats_4 = new QFrame(page_4);
        stats_4->setObjectName("stats_4");
        stats_4->setGeometry(QRect(10, 230, 371, 231));
        stats_4->setFrameShape(QFrame::NoFrame);
        addFeature_4 = new QFrame(page_4);
        addFeature_4->setObjectName("addFeature_4");
        addFeature_4->setGeometry(QRect(10, 10, 371, 201));
        addFeature_4->setFrameShape(QFrame::NoFrame);
        featureBar_4 = new QFrame(page_4);
        featureBar_4->setObjectName("featureBar_4");
        featureBar_4->setGeometry(QRect(400, 10, 501, 61));
        featureBar_4->setStyleSheet(QString::fromUtf8(""));
        featureBar_4->setFrameShape(QFrame::NoFrame);
        add_4 = new QPushButton(featureBar_4);
        add_4->setObjectName("add_4");
        add_4->setGeometry(QRect(30, 10, 41, 41));
        add_4->setCursor(QCursor(Qt::PointingHandCursor));
        add_4->setIcon(icon);
        add_4->setIconSize(QSize(60, 60));
        del_4 = new QPushButton(featureBar_4);
        del_4->setObjectName("del_4");
        del_4->setGeometry(QRect(130, 10, 41, 41));
        del_4->setCursor(QCursor(Qt::PointingHandCursor));
        del_4->setIcon(icon1);
        del_4->setIconSize(QSize(40, 40));
        update_4 = new QPushButton(featureBar_4);
        update_4->setObjectName("update_4");
        update_4->setGeometry(QRect(330, 10, 41, 41));
        update_4->setCursor(QCursor(Qt::PointingHandCursor));
        update_4->setIcon(icon2);
        update_4->setIconSize(QSize(60, 60));
        pdf_4 = new QPushButton(featureBar_4);
        pdf_4->setObjectName("pdf_4");
        pdf_4->setGeometry(QRect(430, 10, 41, 41));
        pdf_4->setCursor(QCursor(Qt::PointingHandCursor));
        pdf_4->setIcon(icon3);
        pdf_4->setIconSize(QSize(50, 50));
        sort_4 = new QPushButton(featureBar_4);
        sort_4->setObjectName("sort_4");
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
        tableWidget_4->setObjectName("tableWidget_4");
        tableWidget_4->setGeometry(QRect(400, 170, 501, 261));
        tableWidget_4->setFont(font1);
        tableWidget_4->setShowGrid(true);
        tableWidget_4->setSortingEnabled(true);
        tableWidget_4->horizontalHeader()->setMinimumSectionSize(50);
        tableWidget_4->horizontalHeader()->setDefaultSectionSize(62);
        tableWidget_4->verticalHeader()->setVisible(false);
        tableWidget_4->verticalHeader()->setMinimumSectionSize(10);
        tableWidget_4->verticalHeader()->setDefaultSectionSize(10);
        tableWidget_4->verticalHeader()->setHighlightSections(false);
        stackedWidget->addWidget(page_4);
        employees = new QPushButton(frame);
        employees->setObjectName("employees");
        employees->setGeometry(QRect(50, 210, 200, 50));
        employees->setCursor(QCursor(Qt::PointingHandCursor));
        clients = new QPushButton(frame);
        clients->setObjectName("clients");
        clients->setGeometry(QRect(50, 310, 200, 50));
        clients->setCursor(QCursor(Qt::PointingHandCursor));
        contracts = new QPushButton(frame);
        contracts->setObjectName("contracts");
        contracts->setGeometry(QRect(50, 410, 200, 50));
        contracts->setCursor(QCursor(Qt::PointingHandCursor));
        accidents = new QPushButton(frame);
        accidents->setObjectName("accidents");
        accidents->setGeometry(QRect(50, 510, 200, 50));
        accidents->setCursor(QCursor(Qt::PointingHandCursor));
        logoutButton = new QPushButton(frame);
        logoutButton->setObjectName("logoutButton");
        logoutButton->setGeometry(QRect(50, 610, 200, 50));
        logoutButton->setCursor(QCursor(Qt::PointingHandCursor));
        logoutButton->setAutoFillBackground(false);
        logoutButton->setStyleSheet(QString::fromUtf8(""));
        QIcon icon10;
        icon10.addFile(QString::fromUtf8("../Resources/Icons/logout.png"), QSize(), QIcon::Normal, QIcon::Off);
        logoutButton->setIcon(icon10);
        logoutButton->setIconSize(QSize(20, 20));

        retranslateUi(Dashboard);

        stackedWidget->setCurrentIndex(0);
        CrudEmployee->setCurrentIndex(2);
        StackedClient->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Dashboard);
    } // setupUi

    void retranslateUi(QDialog *Dashboard)
    {
        Dashboard->setWindowTitle(QCoreApplication::translate("Dashboard", "Dashboard", nullptr));
        role->setPlaceholderText(QCoreApplication::translate("Dashboard", "Role", nullptr));
        logo->setText(QString());
        helloBar->setPlaceholderText(QCoreApplication::translate("Dashboard", "Hello,First Name Last Name", nullptr));
        addEmployee->setText(QString());
        deleteEmployee->setText(QString());
        updateEmployee->setText(QString());
        pdfEmployee->setText(QString());
        sortEmployee->setText(QString());
        EmployeeEmail_C->setPlaceholderText(QString());
        EmployeeLastNameText_C->setPlainText(QCoreApplication::translate("Dashboard", "Last Name", nullptr));
        EmployeeAddressText_C->setPlainText(QCoreApplication::translate("Dashboard", "Address", nullptr));
        EmployeePhoneNumber_C->setText(QString());
        EmployeeCreateBtn->setText(QCoreApplication::translate("Dashboard", "Create ", nullptr));
        EmployeeEmailText_C->setPlainText(QCoreApplication::translate("Dashboard", "Email", nullptr));
        EmployeePhoneNumberText_C->setPlainText(QCoreApplication::translate("Dashboard", "Phone Number", nullptr));
        EmployeeFirstNameText_C->setPlainText(QCoreApplication::translate("Dashboard", "First Name", nullptr));
        EmployeeDobText_C->setPlainText(QCoreApplication::translate("Dashboard", "Date Of Birth", nullptr));
        EmployeeRole_C->setItemText(0, QString());
        EmployeeRole_C->setItemText(1, QCoreApplication::translate("Dashboard", "Role 1", nullptr));
        EmployeeRole_C->setItemText(2, QCoreApplication::translate("Dashboard", "Role 3", nullptr));
        EmployeeRole_C->setItemText(3, QCoreApplication::translate("Dashboard", "Role 2", nullptr));

        EmployeeCancelBtn_C->setText(QCoreApplication::translate("Dashboard", "Cancel", nullptr));
        EmployeeRoleText_C->setPlainText(QCoreApplication::translate("Dashboard", "Role", nullptr));
        EmployeePassword_C->setPlaceholderText(QString());
        EmployeePasswordText_C->setPlainText(QCoreApplication::translate("Dashboard", "Password", nullptr));
        EmployeeFirstNameText_U->setPlainText(QCoreApplication::translate("Dashboard", "First Name", nullptr));
        EmployeePhoneNumberText_U->setPlainText(QCoreApplication::translate("Dashboard", "Phone Number", nullptr));
        EmployeePasswordText_U->setPlainText(QCoreApplication::translate("Dashboard", "Password", nullptr));
        EmployeePhoneNumber_U->setText(QString());
        EmployeeRole_U->setItemText(0, QString());
        EmployeeRole_U->setItemText(1, QCoreApplication::translate("Dashboard", "Role 1", nullptr));
        EmployeeRole_U->setItemText(2, QCoreApplication::translate("Dashboard", "Role 3", nullptr));
        EmployeeRole_U->setItemText(3, QCoreApplication::translate("Dashboard", "Role 2", nullptr));

        EmployeeEmail_U->setPlaceholderText(QString());
        EmployeeDobText_U->setPlainText(QCoreApplication::translate("Dashboard", "Date Of Birth", nullptr));
        EmployeeRoleText_U->setPlainText(QCoreApplication::translate("Dashboard", "Role", nullptr));
        EmployeeAddressText_U->setPlainText(QCoreApplication::translate("Dashboard", "Address", nullptr));
        EmployeeEmailText_U->setPlainText(QCoreApplication::translate("Dashboard", "Email", nullptr));
        EmployeeUpdateBtn->setText(QCoreApplication::translate("Dashboard", "Update ", nullptr));
        EmployeeLastNameText_U->setPlainText(QCoreApplication::translate("Dashboard", "Last Name", nullptr));
        EmployeePassword_U->setPlaceholderText(QString());
        EmployeeCancelBtn_U->setText(QCoreApplication::translate("Dashboard", "Cancel", nullptr));
        EmployeeSelectIDText_U->setText(QCoreApplication::translate("Dashboard", "Select ID", nullptr));
        EmployeeSelectID_U->setItemText(0, QString());

        EmployeeSelectIDText_D->setText(QCoreApplication::translate("Dashboard", "Select ID", nullptr));
        EmployeeDeleteBtn->setText(QCoreApplication::translate("Dashboard", "Delete", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableEmployee->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("Dashboard", " ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableEmployee->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("Dashboard", "Email", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableEmployee->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("Dashboard", "Role", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableEmployee->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("Dashboard", "First Name", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableEmployee->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("Dashboard", "Last Name", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableEmployee->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("Dashboard", "Phone Number", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableEmployee->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("Dashboard", "Address", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tableEmployee->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("Dashboard", "Date Of Birth", nullptr));
        ClientCreateEmail->setPlaceholderText(QString());
        ClientCreateButton->setText(QCoreApplication::translate("Dashboard", "Create Client", nullptr));
        ClientCreateCancel->setText(QCoreApplication::translate("Dashboard", "Cancel", nullptr));
        ClientCreateEmailLine->setPlainText(QCoreApplication::translate("Dashboard", "Email", nullptr));
        ClientCreateFirstNameLine->setPlainText(QCoreApplication::translate("Dashboard", "First Name", nullptr));
        ClientCreateLastNameLine->setPlainText(QCoreApplication::translate("Dashboard", "Last Name", nullptr));
        ClientCreateAddressLine->setPlainText(QCoreApplication::translate("Dashboard", "Address", nullptr));
        ClientCreatePhoneNumberLine->setPlainText(QCoreApplication::translate("Dashboard", "Phone Number", nullptr));
        ClientCreateDobLine->setPlainText(QCoreApplication::translate("Dashboard", "Date Of Birth", nullptr));
        ClientUpdateButton->setText(QCoreApplication::translate("Dashboard", "Update Client", nullptr));
        ClientUpdateCancel->setText(QCoreApplication::translate("Dashboard", "Cancel", nullptr));
        ClientUpdateIDLine->setPlainText(QCoreApplication::translate("Dashboard", "ID", nullptr));
        ClientUpdateEmailLine->setPlainText(QCoreApplication::translate("Dashboard", "Email", nullptr));
        ClientUpdateFirstNameLine->setPlainText(QCoreApplication::translate("Dashboard", "First Name", nullptr));
        ClientUpdateLastNameLine->setPlainText(QCoreApplication::translate("Dashboard", "Last Name", nullptr));
        ClientUpdateAddressLine->setPlainText(QCoreApplication::translate("Dashboard", "Address", nullptr));
        ClientUpdatePhoneNumberLine->setPlainText(QCoreApplication::translate("Dashboard", "Phone Number", nullptr));
        ClientUpdateDobLine->setPlainText(QCoreApplication::translate("Dashboard", "Date Of Birth", nullptr));
        ClientDeleteButton->setText(QCoreApplication::translate("Dashboard", "Delete Client", nullptr));
        ClientDeleteCancel->setText(QCoreApplication::translate("Dashboard", "Cancel", nullptr));
        ClientDeleteIDLine->setPlainText(QCoreApplication::translate("Dashboard", "ID", nullptr));
        deleteClient->setText(QString());
        updateClient->setText(QString());
        pdfClient->setText(QString());
        sortClient->setText(QString());
        addClient->setText(QString());
        QTableWidgetItem *___qtablewidgetitem8 = tableClient->horizontalHeaderItem(0);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("Dashboard", " ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = tableClient->horizontalHeaderItem(1);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("Dashboard", "Email", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = tableClient->horizontalHeaderItem(2);
        ___qtablewidgetitem10->setText(QCoreApplication::translate("Dashboard", "First Name", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = tableClient->horizontalHeaderItem(3);
        ___qtablewidgetitem11->setText(QCoreApplication::translate("Dashboard", "Last Name", nullptr));
        QTableWidgetItem *___qtablewidgetitem12 = tableClient->horizontalHeaderItem(4);
        ___qtablewidgetitem12->setText(QCoreApplication::translate("Dashboard", "Address", nullptr));
        QTableWidgetItem *___qtablewidgetitem13 = tableClient->horizontalHeaderItem(5);
        ___qtablewidgetitem13->setText(QCoreApplication::translate("Dashboard", "Phone Number", nullptr));
        QTableWidgetItem *___qtablewidgetitem14 = tableClient->horizontalHeaderItem(6);
        ___qtablewidgetitem14->setText(QCoreApplication::translate("Dashboard", "Date Of Birth", nullptr));
        add_3->setText(QString());
        del_3->setText(QString());
        update_3->setText(QString());
        pdf_3->setText(QString());
        sort_3->setText(QString());
        QTableWidgetItem *___qtablewidgetitem15 = tableWidget_3->horizontalHeaderItem(0);
        ___qtablewidgetitem15->setText(QCoreApplication::translate("Dashboard", " ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem16 = tableWidget_3->horizontalHeaderItem(1);
        ___qtablewidgetitem16->setText(QCoreApplication::translate("Dashboard", "User ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem17 = tableWidget_3->horizontalHeaderItem(2);
        ___qtablewidgetitem17->setText(QCoreApplication::translate("Dashboard", "Client ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem18 = tableWidget_3->horizontalHeaderItem(3);
        ___qtablewidgetitem18->setText(QCoreApplication::translate("Dashboard", "Premium Amount", nullptr));
        QTableWidgetItem *___qtablewidgetitem19 = tableWidget_3->horizontalHeaderItem(4);
        ___qtablewidgetitem19->setText(QCoreApplication::translate("Dashboard", "Effective Date", nullptr));
        QTableWidgetItem *___qtablewidgetitem20 = tableWidget_3->horizontalHeaderItem(5);
        ___qtablewidgetitem20->setText(QCoreApplication::translate("Dashboard", "Expiration Date", nullptr));
        QTableWidgetItem *___qtablewidgetitem21 = tableWidget_3->horizontalHeaderItem(6);
        ___qtablewidgetitem21->setText(QCoreApplication::translate("Dashboard", "Payment Status", nullptr));
        QTableWidgetItem *___qtablewidgetitem22 = tableWidget_3->horizontalHeaderItem(7);
        ___qtablewidgetitem22->setText(QCoreApplication::translate("Dashboard", "Type", nullptr));
        add_4->setText(QString());
        del_4->setText(QString());
        update_4->setText(QString());
        pdf_4->setText(QString());
        sort_4->setText(QString());
        QTableWidgetItem *___qtablewidgetitem23 = tableWidget_4->horizontalHeaderItem(0);
        ___qtablewidgetitem23->setText(QCoreApplication::translate("Dashboard", " ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem24 = tableWidget_4->horizontalHeaderItem(1);
        ___qtablewidgetitem24->setText(QCoreApplication::translate("Dashboard", "Client ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem25 = tableWidget_4->horizontalHeaderItem(2);
        ___qtablewidgetitem25->setText(QCoreApplication::translate("Dashboard", "Type", nullptr));
        QTableWidgetItem *___qtablewidgetitem26 = tableWidget_4->horizontalHeaderItem(3);
        ___qtablewidgetitem26->setText(QCoreApplication::translate("Dashboard", "Damage", nullptr));
        QTableWidgetItem *___qtablewidgetitem27 = tableWidget_4->horizontalHeaderItem(4);
        ___qtablewidgetitem27->setText(QCoreApplication::translate("Dashboard", "Date", nullptr));
        QTableWidgetItem *___qtablewidgetitem28 = tableWidget_4->horizontalHeaderItem(5);
        ___qtablewidgetitem28->setText(QCoreApplication::translate("Dashboard", "Location", nullptr));
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
