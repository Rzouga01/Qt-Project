#include "employee.h"
#include "ui_employee.h"
#include "connection.h"
#include <QMessageBox>
#include <QtDebug>
#include <QDate>

Employee::Employee(QWidget* parent) :
    QDialog(parent),
    ui(new Ui::Employee)
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

Employee::Employee(QString email, QString password, int role, QString first_name, QString last_name, QString phone_number, QString address, QDate dob)
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

// Getters
QString Employee::getEmail() const {
    return email;
}

QString Employee::getPassword() const {
    return password;
}

int Employee::getRole() const {
    return role;
}

QString Employee::getFirstName() const {
    return first_name;
}

QString Employee::getLastName() const {
    return last_name;
}

QString Employee::getPhoneNumber() const {
    return phone_number;
}

QString Employee::getAddress() const {
    return address;
}

QDate Employee::getDob() const {
    return dob;
}

// Setters
void Employee::setEmail(const QString& email) {
    this->email = email;
}

void Employee::setPassword(const QString& password) {
    this->password = password;
}

void Employee::setRole(const int& role) {
    this->role = role;
}

void Employee::setFirstName(const QString& first_name) {
    this->first_name = first_name;
}

void Employee::setLastName(const QString& last_name) {
    this->last_name = last_name;
}

void Employee::setPhoneNumber(const QString& phone_number) {
    this->phone_number = phone_number;
}

void Employee::setAddress(const QString& address) {
    this->address = address;
}

void Employee::setDob(const QDate& dob) {
    this->dob = dob;
}

bool Employee::createEmployee()
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
        return true;
    }
    else
    {
        qDebug() << "Error creating employee:" << qry.lastError().text();
        return false;
    }
}

void Employee::readEmployee()
{
    QSqlQuery qry("SELECT * FROM EMPLOYEES");
    if (qry.exec())
    {
        while (qry.next())
        {
            qDebug() << "Employee ID :" << qry.value("USER_ID").toInt() <<
                "\nEmail :" << qry.value("EMAIL").toString() <<
                "\nPassword :" << qry.value("PASSWORD").toString() <<
                "\nRole :" << qry.value("ROLE").toString() <<
                "\nFirst Name :" << qry.value("FIRST_NAME").toString() <<
                "\nLast Name :" << qry.value("LAST_NAME").toString() <<
                "\nPhone Number :" << qry.value("PHONE_NUMBER").toString() <<
                "\nAddress :" << qry.value("ADDRESS").toString() <<
                "\nDate of Birth :" << qry.value("DOB").toDate();
            qDebug() << "---------------------------------------";
        }
    }
    else
    {
        qDebug() << "Error executing query:" << qry.lastError().text();
    }
}


bool Employee::updateEmployee(int user_id)
{
    QSqlQuery qry;

    qry.prepare("UPDATE EMPLOYEES SET EMAIL = :email, PASSWORD = :password, ROLE = :role, FIRST_NAME = :first_name, "
        "LAST_NAME = :last_name, PHONE_NUMBER = :phone_number, ADDRESS = :address, DOB = :dob WHERE USER_ID = :user_id");

    qry.bindValue(":user_id", user_id);

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
        qDebug() << "Employee updated successfully." << "Data:" <<
            "\nUser ID :" << user_id <<
            "\nEmail :" << email <<
            "\nPassword :" << password <<
            "\nRole :" << role <<
            "\nFirst Name :" << first_name <<
            "\nLast Name :" << last_name <<
            "\nPhone Number :" << phone_number <<
            "\nAddress :" << address <<
            "\nDate of Birth :" << dob.toString();
        return true;
    }
    else
    {
        qDebug() << "Error updating employee:" << qry.lastError().text();
        return false;
    }
}

bool Employee::deleteEmployee(int user_id)
{
    QSqlQuery qry;

    qry.prepare("DELETE FROM EMPLOYEES WHERE USER_ID = :user_id");
    qry.bindValue(":user_id", user_id);
    if (qry.exec())
    {
        QMessageBox::critical(nullptr, tr("Deleted"), tr("Deleted"));
        return  true;
    }
    else
    {
        qDebug() << "Error executing query:" << qry.lastError().text();
        QMessageBox::critical(nullptr, tr("Error"), qry.lastError().text());
        return false;
    }
}
