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
};

#endif // EMPLOYEE_H
