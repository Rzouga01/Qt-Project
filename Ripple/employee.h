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
    Ui::Employee *ui;
    QString email;
    QString password;
     int role;
    QString first_name;
    QString last_name;
    QString phone_number;
    QString address;
    QDate dob;

public:
    explicit Employee(QWidget *parent = nullptr);
    Employee(QString email, QString password, int role, QString first_name, QString last_name, QString phone_number, QString address, QDate dob);
    ~Employee();

    // Getters
    QString getEmail() const;
    QString getPassword() const;
    int getRole() const;
    QString getFirstName() const;
    QString getLastName() const;
    QString getPhoneNumber() const;
    QString getAddress() const;
    QDate getDob() const;

    // Setters
    void setEmail(const QString &email);
    void setPassword(const QString &password);
    void setRole(const int &role);
    void setFirstName(const QString &firstName);
    void setLastName(const QString &lastName);
    void setPhoneNumber(const QString &phoneNumber);
    void setAddress(const QString &address);
    void setDob(const QDate &dob);

    // CRUD
    bool createEmployee();
    void readEmployee();
    bool updateEmployee(int id);
    bool deleteEmployee(int id);
};

#endif // EMPLOYEE_H
