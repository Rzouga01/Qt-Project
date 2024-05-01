#include "employeesrfid.h"

EmployeesRFID::EmployeesRFID(QObject* parent) : QObject(parent), arduino()
{
    
}

EmployeesRFID::~EmployeesRFID()
{
    arduino.closeArduino();
}

Arduino& EmployeesRFID::getArduino()
{
    return arduino;
}

void EmployeesRFID::processRFIDData()
{
    QString RFIDString = arduino.readFromArduino();

    if (!RFIDString.isEmpty()) {
        // Check if RFIDString contains valid RFID data
        if (RFIDString.contains(" ")) {
            QSqlQuery query;
            query.prepare("SELECT user_id FROM employees WHERE RFID = :RFID");
            query.bindValue(":RFID", RFIDString);

            if (query.exec() && query.next()) {
                int employeeId = query.value(0).toInt();
                qDebug() << "Employee with RFID" << RFIDString << "and ID" << employeeId << "checked in.";
                emit employeeCheckedIn(employeeId);
            }
            else {
                qDebug() << "RFID" << RFIDString << "not found in the database.";
            }
        }
        else {
            qDebug() << "Invalid RFID data.";
        }
    }
}

bool EmployeesRFID::checkIN(const QString& RFIDData)
{
    QDateTime currentDateTime = QDateTime::currentDateTime();
    QString arrivalStatus = "Late";
    QTime currentTime = currentDateTime.time();

    if (currentTime < QTime(8, 0, 0)) {
        arrivalStatus = "On Time";
    }
    else if (currentTime >= QTime(8, 0, 0) && currentTime <= QTime(8, 15, 0)) {
        arrivalStatus = "Arrived";
    }

    QSqlQuery query;
    query.prepare("INSERT INTO EMPLOYEES_PRESENCE (RFID, CHECK_IN_TIME, ARRIVAL_STATUS) VALUES (:RFID, :CHECK_IN_TIME, :ARRIVAL_STATUS)");
    query.bindValue(":RFID", RFIDData);
    query.bindValue(":CHECK_IN_TIME", currentDateTime);
    query.bindValue(":ARRIVAL_STATUS", arrivalStatus);

    if (query.exec()) {
        return true;
    }
    else {
        qDebug() << "Error executing query:" << query.lastError().text();
        return false;
    }
}
