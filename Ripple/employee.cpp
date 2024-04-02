#include "employee.h"
#include "ui_employee.h"
#include "connection.h"
#include <QSqlQuery>
#include <QMessageBox>
#include <QtDebug>
#include <QDate>
#include <QTableWidget>
#include <QHeaderView>
#include <QFont>
#include <QTableWidgetItem>
#include <QTextDocument>
#include <QPdfWriter>
#include <QPainter>
#include <QPageSize>
#include <QMarginsF>
#include <QTextTable>

Employee::Employee(QWidget* parent) :
    QDialog(parent),
    ui(new Ui::Employee),
    tableEmployee(nullptr)
{
    ui->setupUi(this);
    email = "";
    password = "";
    role = -1;
    first_name = "";
    last_name = "";
    phone_number = "";
    address = "";
    dob = QDate::currentDate();
}

Employee::Employee(QTableWidget* tableWidget, QWidget* parent)
    : QDialog(parent), ui(new Ui::Employee), tableEmployee(tableWidget)

{
    ui->setupUi(this);
}

Employee::Employee(const QString& email, const QString& password, int role, const QString& first_name, const QString& last_name, const QString& phone_number, const QString& address, const QDate& dob)
{
	this->email = email;
	this->password = password;
	this->role = role;
	this->first_name = first_name;
	this->last_name = last_name;
	this->phone_number = phone_number;
	this->address = address;
	this->dob = dob;
}

Employee::~Employee()
{
    delete ui;
}

QString mapNumberToRole(int role)
{
    switch (role)
    {
    case 0:
        return "General Director";
    case 1:
        return "Customer relationship director";
    case 2:
        return "Contract Administrator";
    default:
        return "Accident investigation manager";
    }
}

bool Employee::createEmployee(const QString& email, const QString& password, int role, const QString& first_name, const QString& last_name, const QString& phone_number, const QString& address, const QDate& dob)
{
    QSqlQuery qry;
    qry.prepare("INSERT INTO EMPLOYEES (EMAIL, PASSWORD, ROLE, FIRST_NAME, LAST_NAME, PHONE_NUMBER, ADDRESS, DOB) "
        "VALUES (:email, :password, :role, :first_name, :last_name, :phone_number, :address, :dob)");

    qry.bindValue(":email", email);
    qry.bindValue(":password", password);
    qry.bindValue(":role", role);
    qry.bindValue(":first_name", first_name);
    qry.bindValue(":last_name", last_name);
    qry.bindValue(":phone_number", phone_number);
    qry.bindValue(":address", address);
    qry.bindValue(":dob", dob);

    if (qry.exec())
    {
        qDebug() << "Employee saved successfully." << "Data:" <<
            "\nEmail :" << email <<
            "\nPassword :" << password <<
            "\nRole :" << role <<
            "\nFirst Name :" << first_name <<
            "\nLast Name :" << last_name <<
            "\nPhone Number :" << phone_number <<
            "\nAddress :" << address <<
            "\nDate of Birth :" << dob.toString();
        return  true;
    }
    else
    {
        qDebug() << "Error creating employee:" << qry.lastError().text();
        return false;
    }
}

void Employee::readEmployee()
{
    if (tableEmployee == nullptr) {
        qDebug() << "Error: tableEmployee is null";
        return;
    }

    tableEmployee->clearContents();
    tableEmployee->setRowCount(0);

    QSqlQuery qry;
    qry.prepare("SELECT * FROM employees");
    if (qry.exec())
    {
        tableEmployee->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);

        while (qry.next())
        {
            int row = tableEmployee->rowCount();
            tableEmployee->insertRow(row);

            tableEmployee->setFont(QFont("Helvetica", 10));

            tableEmployee->setItem(row, 0, new QTableWidgetItem(qry.value(0).toString()));
            tableEmployee->setItem(row, 1, new QTableWidgetItem(qry.value(1).toString()));
            tableEmployee->setItem(row, 2, new QTableWidgetItem(qry.value(2).toString()));
            tableEmployee->setItem(row, 3, new QTableWidgetItem(mapNumberToRole(qry.value(3).toInt())));
            tableEmployee->setItem(row, 4, new QTableWidgetItem(qry.value(4).toString()));
            tableEmployee->setItem(row, 5, new QTableWidgetItem(qry.value(5).toString()));
            tableEmployee->setItem(row, 6, new QTableWidgetItem(qry.value(6).toString()));
            tableEmployee->setItem(row, 7, new QTableWidgetItem(qry.value(7).toString()));
            tableEmployee->setItem(row, 8, new QTableWidgetItem(qry.value(8).toDate().toString()));
        }
        tableEmployee->resizeColumnsToContents();
        tableEmployee->horizontalHeader()->setSectionResizeMode(QHeaderView::Interactive); 
        tableEmployee->repaint();
    }
    else
    {
        qDebug() << "Error executing query:" << qry.lastError().text();
    }
}

bool Employee::updateEmployee(int id, const QString& email, const QString& password, int role, const QString& first_name, const QString& last_name, const QString& phone_number, const QString& address, const QDate& dob)
{
    QSqlQuery qry;
    qry.prepare("UPDATE employees  SET EMAIL = :email, PASSWORD = :password, ROLE = :role, FIRST_NAME = :first_name, LAST_NAME = :last_name, PHONE_NUMBER = :phone_number, ADDRESS = :address, DOB = :dob WHERE USER_ID = :id");

    qry.bindValue(":email", email);
    qry.bindValue(":password", password);
    qry.bindValue(":role", role);
    qry.bindValue(":first_name", first_name);
    qry.bindValue(":last_name", last_name);
    qry.bindValue(":phone_number", phone_number);
    qry.bindValue(":address", address);
    qry.bindValue(":dob", dob);
    qry.bindValue(":id", id);

    if (qry.exec())
    {
        qDebug() << "Employee updated successfully." << "Data:" <<
            "\nID :" << id <<
            "\nEmail :" << email <<
            "\nPassword :" << password <<
            "\nRole :" << role <<
            "\nFirst Name :" << first_name <<
            "\nLast Name :" << last_name <<
            "\nPhone Number :" << phone_number <<
            "\nAddress :" << address <<
            "\nDate of Birth :" << dob.toString(Qt::ISODate);
        return true;
    }
    else
    {
        qDebug() << "Error updating employee:" << qry.lastError().text();
        return false;
    }
}

bool Employee::deleteEmployee(int id)
{   
    QSqlQuery qry;

    qry.prepare("DELETE FROM employees WHERE USER_ID = :id");
    qry.bindValue(":id", id);
    if (qry.exec())
    {
        return  true;
    }
    else
    {
        qDebug() << "Error executing query:" << qry.lastError().text();
        return false;
    }
}

void Employee::readEmployeeById(int id) {
    QSqlQuery qry;
    qry.prepare("SELECT * FROM employees WHERE user_id = :id");
    qry.bindValue(":id", id);
    if (qry.exec()) {
        if (qry.next()) {
            setEmail(qry.value("EMAIL").toString());
            setPassword(qry.value("PASSWORD").toString());
            setFirstName(qry.value("FIRST_NAME").toString());
            setLastName(qry.value("LAST_NAME").toString());
            setAddress(qry.value("ADDRESS").toString());
            setPhoneNumber(qry.value("PHONE_NUMBER").toString());
            setDOB(qry.value("DOB").toDate());
        }
    }
    else {
        qDebug() << "Error executing query:" << qry.lastError().text();
    }
}

void Employee::readEmployeeByIds(const QList<int>& employeeIDs) {
    if (tableEmployee == nullptr) {
        qDebug() << "Error: tableEmployee is null";
        return;
    }

    // Iterate over each employee ID and read the corresponding employee data
    for (int employeeID : employeeIDs) {
        readEmployeeById(employeeID);
    }
}

QStringList Employee::getAllEmployeeIDs() {
    QStringList ids;
    QSqlQuery qry;
    qry.prepare("SELECT USER_ID FROM EMPLOYEES");
    if (qry.exec()) {
        while (qry.next()) {
            ids.append(qry.value(0).toString());
        }
    }
    else {
        qDebug() << "Error executing query:" << qry.lastError().text();
    }
    return ids;
}

    QStringList Employee::getEmployeeNames() {
        QStringList names;
        QSqlQuery query;
        query.prepare("SELECT first_name, last_name FROM EMPLOYEES");
        if (query.exec()) {
            while (query.next()) {
                QString fullName = query.value("first_name").toString() + " " + query.value("last_name").toString();
                names << fullName;
            }
        }
        else {
            qDebug() << "Error fetching employee names:" << query.lastError().text();
        }
        return names;
    }

void Employee::sortEmployeesByAge()
{
    if (tableEmployee == nullptr) {
        qDebug() << "Error: tableEmployee is null";
        return;
    }

    tableEmployee->clearContents();
    tableEmployee->setRowCount(0);

    QSqlQuery qry;
    qry.prepare("SELECT * FROM employees ORDER BY DOB ASC");
    if (qry.exec())
    {
        tableEmployee->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);

        while (qry.next())
        {
            int row = tableEmployee->rowCount();
            tableEmployee->insertRow(row);

            tableEmployee->setFont(QFont("Helvetica", 10));

            tableEmployee->setItem(row, 0, new QTableWidgetItem(qry.value(0).toString()));
            tableEmployee->setItem(row, 1, new QTableWidgetItem(qry.value(1).toString()));
            tableEmployee->setItem(row, 2, new QTableWidgetItem(qry.value(2).toString()));
            tableEmployee->setItem(row, 3, new QTableWidgetItem(mapNumberToRole(qry.value(3).toInt())));
            tableEmployee->setItem(row, 4, new QTableWidgetItem(qry.value(4).toString()));
            tableEmployee->setItem(row, 5, new QTableWidgetItem(qry.value(5).toString()));
            tableEmployee->setItem(row, 6, new QTableWidgetItem(qry.value(6).toString()));
            tableEmployee->setItem(row, 7, new QTableWidgetItem(qry.value(7).toString()));
            tableEmployee->setItem(row, 8, new QTableWidgetItem(qry.value(8).toDate().toString()));
        }
        tableEmployee->resizeColumnsToContents();
        tableEmployee->horizontalHeader()->setSectionResizeMode(QHeaderView::Interactive);
        tableEmployee->repaint();
    }
    else
    {
        qDebug() << "Error executing query:" << qry.lastError().text();
    }
}

void Employee::ExportEmployeesToPdf(const QString& filePath)
{
    qDebug() << "Exporting employee data to PDF:" << filePath;

    if (filePath.isEmpty()) {
        qDebug() << "File path is empty.";
        return;
    }

    if (!tableEmployee) {
        qDebug() << "Table widget is invalid.";
        return;
    }

    if (tableEmployee->rowCount() == 0 || tableEmployee->columnCount() == 0) {
        qDebug() << "No data to export.";
        return;
    }

    
    QTextDocument doc;


    QTextCursor cursor(&doc);

    cursor.insertHtml("<h1 style='text-align: center; color: #333333;'>Employee List</h1><br>");

    QTextTableFormat tableFormat;
    tableFormat.setAlignment(Qt::AlignHCenter); 
    tableFormat.setHeaderRowCount(1);
    tableFormat.setWidth(QTextLength(QTextLength::PercentageLength, 95)); 
    tableFormat.setCellPadding(8); 
    tableFormat.setCellSpacing(0); 
    tableFormat.setBorder(1); 
    tableFormat.setBorderStyle(QTextFrameFormat::BorderStyle_Solid); 

    QTextCharFormat headerFormat;
    headerFormat.setBackground(QColor("#C0C0C0")); 
    headerFormat.setForeground(Qt::black); 
    headerFormat.setFontWeight(QFont::Bold); 
    headerFormat.setFontPointSize(12); 

    
    QTextCharFormat altRowFormat;
    altRowFormat.setBackground(Qt::lightGray);

    int numRows = tableEmployee->rowCount();
    int numCols = tableEmployee->columnCount();

    
    QTextTable* table = cursor.insertTable(numRows + 1, numCols, tableFormat);

    
    for (int col = 0; col < numCols; ++col) {
        QTextTableCell headerCell = table->cellAt(0, col);
        QTextCursor cellCursor = headerCell.firstCursorPosition();
        cellCursor.setCharFormat(headerFormat); 
        cellCursor.insertText(tableEmployee->horizontalHeaderItem(col)->text()); 
    }

    for (int row = 0; row < numRows; ++row) {
        for (int col = 0; col < numCols; ++col) {
            QTableWidgetItem* item = tableEmployee->item(row, col);
            if (item) {
                QTextTableCell dataCell = table->cellAt(row + 1, col);
                QTextCursor cellCursor = dataCell.firstCursorPosition();
                if (row % 2 == 1) {
                    cellCursor.setCharFormat(altRowFormat); 
                }
                QTextCharFormat dataFormat;
                dataFormat.setFontPointSize(10); 
                cellCursor.setCharFormat(dataFormat);
                cellCursor.insertText(item->text()); 
            }
        }
    }

    QPdfWriter pdfWriter(filePath);
    pdfWriter.setPageSize(QPageSize(QPageSize::Letter)); 
    pdfWriter.setResolution(150); 

    QPainter painter(&pdfWriter);
    painter.begin(&pdfWriter); 

    doc.drawContents(&painter);

    painter.end(); 

    qDebug() << "PDF file successfully created:" << filePath;
    QMessageBox::information(nullptr, "Export Successful", "Employee data has been successfully exported to PDF.\nFile saved to: " + filePath);
}

void Employee::searchEmployee(const QString& search)
{
    if (tableEmployee == nullptr) {
        qDebug() << "Error: tableEmployee is null";
        return;
    }

    tableEmployee->clearContents();
    tableEmployee->setRowCount(0);

    QSqlQuery qry;
    qry.prepare("SELECT * FROM employees WHERE LOWER(FIRST_NAME) LIKE LOWER(:search) OR LOWER(LAST_NAME) LIKE LOWER(:search)");
    qry.bindValue(":search", "%" + search.toLower() + "%");

    if (qry.exec())
    {
        tableEmployee->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);

        while (qry.next())
        {
            int row = tableEmployee->rowCount();
            tableEmployee->insertRow(row);

            tableEmployee->setFont(QFont("Helvetica", 10));

            tableEmployee->setItem(row, 0, new QTableWidgetItem(qry.value(0).toString()));
            tableEmployee->setItem(row, 1, new QTableWidgetItem(qry.value(1).toString()));
            tableEmployee->setItem(row, 2, new QTableWidgetItem(qry.value(2).toString()));
            tableEmployee->setItem(row, 3, new QTableWidgetItem(mapNumberToRole(qry.value(3).toInt())));
            tableEmployee->setItem(row, 4, new QTableWidgetItem(qry.value(4).toString()));
            tableEmployee->setItem(row, 5, new QTableWidgetItem(qry.value(5).toString()));
            tableEmployee->setItem(row, 6, new QTableWidgetItem(qry.value(6).toString()));
            tableEmployee->setItem(row, 7, new QTableWidgetItem(qry.value(7).toString()));
            tableEmployee->setItem(row, 8, new QTableWidgetItem(qry.value(8).toDate().toString()));
        }

        tableEmployee->resizeColumnsToContents();
        tableEmployee->horizontalHeader()->setSectionResizeMode(QHeaderView::Interactive);
        tableEmployee->repaint();

        if (tableEmployee->rowCount() == 0) {
            qDebug() << "No matching records found for search:" << search;
        }
    }
    else
    {
        qDebug() << "Error executing query:" << qry.lastError().text();

    }
}

QMap<QString, qreal> Employee::calculateEmployeeStats(int employeeID) {
    QMap<QString, qreal> stats;

    // Convert the employee ID to a string
    QString employeeIDStr = QString::number(employeeID);

    QString queryStr;
    QSqlQuery query;

    // Query to check if there are any records for the specified employee
    queryStr = "SELECT COUNT(*) FROM employees_presence WHERE USER_ID = '" + employeeIDStr + "'";
    query.exec(queryStr);
    query.next();
    int numRecords = query.value(0).toInt();

    // If no records are found, return an empty map
    if (numRecords == 0) {
        return stats;
    }

    // Query to calculate total working days for the specified employee
    queryStr = "SELECT COUNT(*) FROM employees_presence WHERE USER_ID = '" + employeeIDStr + "'";
    query.exec(queryStr);
    query.next();
    int totalWorkingDays = query.value(0).toInt();

    // Query to calculate late arrival frequency for the specified employee
    queryStr = "SELECT COUNT(*) FROM employees_presence WHERE USER_ID = '" + employeeIDStr + "' AND ARRIVAL_STATUS = 'Late'";
    query.exec(queryStr);
    query.next();
    int lateArrivals = query.value(0).toInt();

    // Query to calculate early departure frequency for the specified employee
    queryStr = "SELECT COUNT(*) FROM employees_presence WHERE USER_ID = '" + employeeIDStr + "' AND ARRIVAL_STATUS = 'Early Departure'";
    query.exec(queryStr);
    query.next();
    int earlyDepartures = query.value(0).toInt();

    // Calculate absenteeism rate
    int absenteeismDays = totalWorkingDays - lateArrivals - earlyDepartures;
    qreal absenteeismRate = static_cast<qreal>(absenteeismDays) / totalWorkingDays * 100.0;

    stats["Total Working Days"] = totalWorkingDays;
    stats["Late Arrivals"] = lateArrivals;
    stats["Early Departures"] = earlyDepartures;
    stats["Absenteeism Rate"] = absenteeismRate;

    return stats;
}

QMap<QString, qreal> Employee::calculateGeneralStats() {
    QMap<QString, qreal> generalStats;

    QString queryStr;
    QSqlQuery query;

    // Query to count the total number of employees
    queryStr = "SELECT COUNT(*) FROM employees";
    query.exec(queryStr);
    query.next();
    int totalEmployees = query.value(0).toInt();

    // Query to calculate total working hours for all employees
    queryStr = "SELECT SUM(TOTAL_HOURS) FROM employees_presence";
    query.exec(queryStr);
    query.next();
    qreal totalWorkingHours = query.value(0).toReal();

    // Query to calculate the total number of late arrivals for all employees
    queryStr = "SELECT COUNT(*) FROM employees_presence WHERE ARRIVAL_STATUS = 'Late'";
    query.exec(queryStr);
    query.next();
    int totalLateArrivals = query.value(0).toInt();

    // Query to calculate the total number of early departures for all employees
    queryStr = "SELECT COUNT(*) FROM employees_presence WHERE ARRIVAL_STATUS = 'Early Departure'";
    query.exec(queryStr);
    query.next();
    int totalEarlyDepartures = query.value(0).toInt();

    // Calculate absenteeism rate for all employees
    qreal totalAbsenteeismRate = 0.0;
    if (totalEmployees > 0) {
        // Query to count the total number of absences for all employees
        queryStr = "SELECT COUNT(*) FROM employees_presence WHERE ARRIVAL_STATUS = 'Absent'";
        query.exec(queryStr);
        query.next();
        int totalAbsences = query.value(0).toInt();

        // Calculate absenteeism rate
        totalAbsenteeismRate = static_cast<qreal>(totalAbsences) / totalEmployees * 100.0;
    }

    // Calculate average attendance rate
    qreal averageAttendanceRate = 100.0 - totalAbsenteeismRate;

    // Insert calculated values into the generalStats map
    generalStats["Total Employees"] = totalEmployees;
    generalStats["Average Attendance Rate"] = averageAttendanceRate;
    generalStats["Total Working Hours"] = totalWorkingHours;
    generalStats["Total Late Arrivals"] = totalLateArrivals;
    generalStats["Total Early Departures"] = totalEarlyDepartures;
    generalStats["Absenteeism Rate"] = totalAbsenteeismRate;

    return generalStats;
}

int Employee::getEmployeeIdByName(const QString& name) {
    QSqlQuery query;
    query.prepare("SELECT user_id FROM EMPLOYEES WHERE first_name || ' ' || last_name = ?");
    query.bindValue(0, name);
    if (query.exec() && query.next()) {
        return query.value("user_id").toInt();
    }
    else {
        qDebug() << "Error fetching employee ID by name:" << query.lastError().text();
        return -1; 
    }
}

bool Employee::login(const QString& email, const QString& password) {
    QSqlQuery qry;
    qry.prepare("SELECT * FROM employees WHERE EMAIL = :email AND PASSWORD = :password");
    qry.bindValue(":email", email);
    qry.bindValue(":password", password);

    if (qry.exec() && qry.next()) {
        
        setEmail(qry.value("EMAIL").toString());
        setPassword(qry.value("PASSWORD").toString());
        setRole(qry.value("ROLE").toInt());
        setFirstName(qry.value("FIRST_NAME").toString());
        setLastName(qry.value("LAST_NAME").toString());
        setPhoneNumber(qry.value("PHONE_NUMBER").toString());
        setAddress(qry.value("ADDRESS").toString());
        setDOB(qry.value("DOB").toDate());
        return true;
    }
    else {
       
        return false;
    }
}





