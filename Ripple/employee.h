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
    QString EMAIL;
    QString PASSWORD;
    QString ROLE;
    QString FIRST_NAME;
    QString LAST_NAME;
    QString PHONE_NUMBER;
    QString ADDRESS;
    QDate DOB;

public:
    explicit Employee(QWidget *parent = nullptr);
    ~Employee();

    // Getters
    QString getEmail() const;
    QString getPassword() const;
    QString getRole() const;
    QString getFirstName() const;
    QString getLastName() const;
    QString getPhoneNumber() const;
    QString getAddress() const;
    QDate getDOB() const;

    // Setters
    void setEmail(const QString &email);
    void setPassword(const QString &password);
    void setRole(const QString &role);
    void setFirstName(const QString &firstName);
    void setLastName(const QString &lastName);
    void setPhoneNumber(const QString &phoneNumber);
    void setAddress(const QString &address);
    void setDOB(const QDate &dob);

    // CRUD
    bool createEmployee();
    void readEmployee();
    bool updateEmployee();
    bool deleteEmployee();
};

#endif // EMPLOYEE_H
