#include "employeesrfid.h"

EmployeesRFID::EmployeesRFID(QObject* parent) : QObject(parent)
{
    int arduinoConn = arduino.connectArduino(); 
    switch (arduinoConn) {
    case (0):
        qDebug() << "arduino is available and connected to : "
            << arduino.getPortName();
        break;
    case (1):
        qDebug() << "given arduino is not available";
    }

    QObject::connect(arduino.getSerial(), SIGNAL(readyRead()), this,
        SLOT(processRFIDData()));
}

EmployeesRFID::~EmployeesRFID()
{
    arduino.disconnectArduino();
}

void EmployeesRFID::processRFIDData()
{
    QByteArray RFIDData = arduino.read();
    QString RFIDString = QString(RFIDData);

    if (checkIN(RFIDString)) {
        qDebug() << "Employee with RFID" << RFIDString << "checked in.";
    }
    else {
        qDebug() << "Failed to update database for RFID" << RFIDString;
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
