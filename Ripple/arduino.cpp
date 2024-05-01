#include "arduino.h"
#include <QtSerialPort/QtSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QDebug>

Arduino::Arduino() {
    data = "";
    arduinoPortName = "";
    arduinoIsAvailable = false;
    serial = new QSerialPort;
}

Arduino::~Arduino() {
    if (serial->isOpen()) {
        serial->close(); 
    }
    delete serial;
}

QString Arduino::getArduinoPortName() {
    return arduinoPortName;
}

QSerialPort* Arduino::getSerial() {
    return serial;
}

int Arduino::connectArduino() {
    if (!serial) {
        qDebug() << "Serial port is null!";
        return -1;
    }

    foreach(const QSerialPortInfo & serialPortInfo, QSerialPortInfo::availablePorts()) {
        qDebug() << "Port: " << serialPortInfo.portName();

        if (serialPortInfo.hasVendorIdentifier() && serialPortInfo.hasProductIdentifier()) {
            qDebug() << "Vendor ID: " << serialPortInfo.vendorIdentifier();
            qDebug() << "Product ID: " << serialPortInfo.productIdentifier();

            if (serialPortInfo.vendorIdentifier() == arduinoUnoVendorId && serialPortInfo.productIdentifier() == arduinoUnoProductId) {
                arduinoIsAvailable = true;
                arduinoPortName = serialPortInfo.portName();
                qDebug() << "Arduino Uno found on port: " << arduinoPortName;
            }
        }
    }

    if (arduinoIsAvailable) {
        serial->setPortName(arduinoPortName);
        if (serial->open(QSerialPort::ReadWrite)) {
            serial->setBaudRate(QSerialPort::Baud9600);
            serial->setDataBits(QSerialPort::Data8);     
            serial->setParity(QSerialPort::NoParity);    
            serial->setStopBits(QSerialPort::OneStop);   
            serial->setFlowControl(QSerialPort::NoFlowControl);
            qDebug() << "Serial port opened successfully!";
            return 0;
        }
        else {
            qDebug() << "Failed to open serial port!";
            return 1;
        }
    }
    else {
        qDebug() << "Arduino Uno not found!";
        return -1;
    }
}

int Arduino::closeArduino() {
    if (serial->isOpen()) {
        serial->close();
        qDebug() << "Serial port closed.";
        return 0;
    }
    else {
        qDebug() << "Serial port is not open!";
        return 1;
    }
}

QString Arduino::readFromArduino() {
    QString receivedData;

    if (serial->isOpen() && serial->isReadable()) {
        QByteArray requestData = serial->readAll(); 

        receivedData = QString::fromUtf8(requestData).trimmed();

        if (!receivedData.isEmpty()) {
            qDebug() << "RFID Card scanned:" << receivedData;

        }
    }

    return receivedData;
}

void Arduino::writeToArduino(const QByteArray& d) {
    if (serial->isOpen() && serial->isWritable()) {
        serial->write(d); 
        qDebug() << "Data sent to Arduino.";
    }
    else {
        qDebug() << "Serial port is not open or not writable!";
    }
}
