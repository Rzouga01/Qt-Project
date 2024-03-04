#include "employee.h"
#include "ui_employee.h"
#include "connection.h"
#include <QMessageBox>
#include <QtDebug>
#include <QDate>

Employee::Employee(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Employee)
{
    ui->setupUi(this);
    email = "";
    password = "";
    role = "";
    first_name = "";
    last_name = "";
    phone_number = "";
    address = "";
    dob = QDate::currentDate();
}

Employee::Employee(const QString &email, const QString &password, const QString &role,
                   const QString &first_name, const QString &last_name, const QString &phone_number,
                   const QString &address, const QDate &dob, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Employee),
    email(email),
    password(password),
    role(role),
    first_name(first_name),
    last_name(last_name),
    phone_number(phone_number),
    address(address),
    dob(dob)
{
    ui->setupUi(this);
}

Employee::~Employee()
{
    delete ui;
}

bool Employee::createEmployee()
{
    QSqlQuery qry;

    qry.prepare("INSERT INTO employees (email, password, role, first_name, last_name, phone_number, address, dob) "
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
        qDebug() << "Error creating employee:" << qry.lastError().text(); // Changed error message
        return false;
    }
}

bool Employee::deleteEmployee(int id)
{
    QSqlQuery qry;

    qry.prepare("DELETE FROM employees WHERE employee_id = :id");
    qry.bindValue(":id", id);
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


void Employee::readEmployee()
{
    QSqlQuery qry;
    qry.prepare("SELECT * FROM employees");
    if (qry.exec())
    {
        while (qry.next())
        {
            qDebug() << "Employee ID :" << qry.value(0).toInt() <<
                "\nEmail :" << qry.value(1).toString() <<
                "\nPassword :" << qry.value(2).toString() <<
                "\nRole :" << qry.value(3).toString() <<
                "\nFirst Name :" << qry.value(4).toString() <<
                "\nLast Name :" << qry.value(5).toString() <<
                "\nPhone Number :" << qry.value(6).toString() <<
                "\nAddress :" << qry.value(7).toString() <<
                "\nDate of Birth :" << qry.value(8).toDate();
            qDebug() << "---------------------------------------";
        }
    }
    else
    {
        qDebug() << "Error executing query:" << qry.lastError().text();
    }
}
