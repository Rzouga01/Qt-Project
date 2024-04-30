#include "arduino.h"

Arduino::Arduino() {
    data = "";
    portName = "";
    isAvailable = false;
    serial = new QSerialPort;
}

Arduino::~Arduino() {
    disconnectArduino();
}

QString Arduino::getPortName() {
    return portName;
}

QSerialPort* Arduino::getSerial() {
    return serial;
}

int Arduino::connect(QString port) {
    portName = port;
    serial->setPortName(portName);

    if (serial->open(QSerialPort::ReadWrite)) {
 
        serial->setBaudRate(QSerialPort::Baud9600);
        serial->setDataBits(QSerialPort::Data8);
        serial->setParity(QSerialPort::NoParity);
        serial->setStopBits(QSerialPort::OneStop);
        serial->setFlowControl(QSerialPort::NoFlowControl);
        return 0; // Success
    }

    return 1; // Failed to open port
}

int Arduino::connectArduino() {
    foreach(const QSerialPortInfo & info, QSerialPortInfo::availablePorts()) {
        if (info.hasVendorIdentifier() && info.hasProductIdentifier()) {
            if (info.vendorIdentifier() == vendorId && info.productIdentifier() == productId) {
                isAvailable = true;
                portName = info.portName();
            }
        }
    }

    qDebug() << "Arduino port name is: " << portName;
    if (isAvailable) {
        return connect(portName);
    }

    return -1; // No Arduino found
}

int Arduino::disconnectArduino() {
    if (isOpen()) {
        serial->close();
        return 0; // Success
    }
    return 1; // Not connected
}

bool Arduino::isOpen() {
    return serial->isOpen();
}

QByteArray Arduino::read() {
    QByteArray receivedData;
    if (isOpen() && serial->waitForReadyRead()) {
        receivedData = serial->readAll();
    }
    return receivedData;
}

int Arduino::write(QByteArray data) {
    if (isOpen() && serial->isWritable()) {
        serial->write(data);
        return 0; // Success
    }
    return 1; // Write failed
}
