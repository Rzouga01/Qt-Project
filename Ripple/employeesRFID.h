#ifndef EMPLOYEESRFID_H
#define EMPLOYEESRFID_H

#include <QObject>
#include <QDateTime>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlError>
#include "arduino.h"
#include "employee.h"

class EmployeesRFID : public QObject
{
    Q_OBJECT
public:
    explicit EmployeesRFID(QObject* parent = nullptr);
    ~EmployeesRFID();
    Arduino& getArduino();

signals:
    void employeeCheckedIn(int employeeId);

private slots:
    void processRFIDData();

private:
    Arduino arduino;
    Employee employee;
    bool checkIN(const QString& RFIDData);
   
};

#endif // EMPLOYEESRFID_H
