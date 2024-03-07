#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <QDialog>
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDate>

namespace Ui {
    class Employee;
}

class Employee : public QDialog {
    Q_OBJECT
private:
    Ui::Employee* ui;
    QString email;
    QString password;
    QString role;
    QString first_name;
    QString last_name;
    QString phone_number;
    QString address;
    QDate dob;

public:
    explicit Employee(QWidget* parent = nullptr);
    Employee( QString email, QString password,  QString role,	 QString first_name,  QString last_name,  QString phone_number, QString address,  QDate dob);
    ~Employee();

    // Getters
    QString getEmail() const { return email; };
    QString getPassword() const { return password; };
    QString getRole() const { return role; };
    QString getFirstName() const { return first_name; };
    QString getLastName() const { return last_name; };
    QString getPhoneNumber() const { return phone_number; };
    QString getAddress() const { return address; };
    QDate getDOB() const { return dob; };

    // Setter
    void setPassword(const QString& password) { this->password = password; };
    void setRole(const QString& role) { this->role = role; };
    void setFirstName(const QString& firstName) { this->first_name = firstName; };
    void setLastName(const QString& lastName) { this->last_name = lastName; };
    void setPhoneNumber(const QString& phoneNumber) { this->phone_number = phoneNumber; };
    void setAddress(const QString& address) { this->address = address; };
    void setDOB(const QDate& dob) { this->dob = dob; };

    // CRUD
    bool createEmployee();
    void readEmployee();
    bool updateEmployee(int id);
    bool deleteEmployee(int id);
};

#endif // EMPLOYEE_H
