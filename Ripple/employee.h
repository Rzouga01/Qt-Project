#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <QDialog>
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDate>
#include <QTableWidget>
#include <QObject>
#include <QMap>
namespace Ui {
    class Employee;
}

class Employee : public QDialog {
    Q_OBJECT
private:
    int id;
    QString email;
    QString password;
    int role;
    QString first_name;
    QString last_name;
    QString phone_number;
    QString address;
    QDate dob;
    Ui::Employee* ui;
    QTableWidget* tableEmployee;

public:
    // Constructors
    explicit Employee(QWidget* parent = nullptr);
    explicit Employee(QTableWidget* tableWidget, QWidget* parent = nullptr);
    Employee(const QString& email, const QString& password, int role, const QString& first_name, const QString& last_name, const QString& phone_number, const QString& address, const QDate& dob);

    // Destructor
    ~Employee();

    // Getters
    int getId() const { return id; };
    QString getEmail() const { return email; };
    QString getPassword() const { return password; };
    int getRole() const { return role; };
    QString getFirstName() const { return first_name; };
    QString getLastName() const { return last_name; };
    QString getPhoneNumber() const { return phone_number; };
    QString getAddress() const { return address; };
    QDate getDOB() const { return dob; };
    // Setters
    void setEmail(const QString& mail) { email = mail; };
    void setPassword(const QString& newPassword) { password = newPassword; };
    void setRole(int newRole) { role = newRole; };
    void setFirstName(const QString& firstName) { first_name = firstName; };
    void setLastName(const QString& lastName) { last_name = lastName; };
    void setPhoneNumber(const QString& phoneNumber) { phone_number = phoneNumber; };
    void setAddress(const QString& newAddress) { address = newAddress; };
    void setDOB(const QDate& newDOB) { dob = newDOB; };
    void setTableEmployee(QTableWidget* table) { tableEmployee = table; };

    // CRUD 
    bool createEmployee(const QString& email, const QString& password, int role, const QString& first_name, const QString& last_name, const QString& phone_number, const QString& address, const QDate& dob);
    void readEmployee();
    bool updateEmployee(int id, const QString& email, const QString& password, int role, const QString& first_name, const QString& last_name, const QString& phone_number, const QString& address, const QDate& dob);
    bool deleteEmployee(int id);
  
    //Metiers
    void sortEmployeesByAge();
    void ExportEmployeesToPdf(const QString& filePath);
    void searchEmployee(const QString& searchText);
    QMap<QString, qreal> calculateEmployeeStats(int employeeID);
    QMap<QString, qreal> calculateGeneralStats();

   //Other
    void readEmployeeById(int id);
    void readEmployeeByIds(const QList<int>& ids);
    QStringList getAllEmployeeIDs();
    QStringList getEmployeeNames();
    int getEmployeeIdByName(const QString& name);
};

#endif // EMPLOYEE_H
