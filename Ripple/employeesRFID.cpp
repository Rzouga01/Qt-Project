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
        if (RFIDString.contains(" ")) {
            QSqlQuery query;
            query.prepare("SELECT * FROM employees WHERE RFID = :RFID");
            query.bindValue(":RFID", RFIDString.trimmed());

            if (query.exec() && query.next()) {
                int employeeId = query.value(0).toInt();
                QString employeeName = query.value(4).toString();
                qDebug() << "Employee with RFID" << RFIDString << "and ID" << employeeId << "checked in.";
                emit employeeCheckedIn(employeeId, QDateTime::currentDateTime().toString("dd MMM yyyy hh:mm:ss"));
        
                if (!checkIN(RFIDString)) {
                    qDebug() << "Error adding check-in record to the database.";
                }

                arduino.writeToArduino("1");
                arduino.writeToArduino(QString("Welcome %1").arg(employeeName).toUtf8());


            }
            else {
                qDebug() << "RFID" << RFIDString << "not found in the database.";
                emit employeeCheckedIn(-1, QDateTime::currentDateTime().toString("dd MMM yyyy hh:mm:ss"));
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
        arrivalStatus = "Early";
    }
    else if (currentTime >= QTime(8, 0, 0) && currentTime <= QTime(8, 15, 0)) {
        arrivalStatus = "On Time";
    }

    QSqlQuery query;
    query.prepare("SELECT USER_ID FROM EMPLOYEES WHERE RFID = :RFID");
    query.bindValue(":RFID", RFIDData);

    if (query.exec() && query.next()) {
        int employeeId = query.value(0).toInt();

        query.prepare("INSERT INTO EMPLOYEES_PRESENCE (USER_ID, CHECK_IN_TIME, ARRIVAL_STATUS) VALUES (:USER_ID, :CHECK_IN_TIME, :ARRIVAL_STATUS)");
        query.bindValue(":USER_ID", employeeId);
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
    else {
        qDebug() << "Error searching for employee with RFID:" << RFIDData;
        return false;
    }
}


