#ifndef ARDUINO_H
#define ARDUINO_H

#include <QDebug>
#include <QSerialPort>
#include <QSerialPortInfo>

class Arduino {
public:
    Arduino();
    ~Arduino();

    int connectArduino();               // Establish connection with Arduino
    int disconnectArduino();           // Close the connection
    int connect(QString port);        // Connect to Arduino on a specific port
    int write(QByteArray data);      // Send data to Arduino
    QByteArray read();              // Receive data from Arduino
    QSerialPort* getSerial();                  
    QString getPortName();                  
    bool isOpen();               // Check if the connection is open
   

private:
    QSerialPort* serial;
    QString portName;
    static const quint16 vendorId = 9025;       // Vendor ID for Arduino
    static const quint16 productId = 67;       // Product ID for Arduino
    bool isAvailable;
    QByteArray data;
};

#endif // ARDUINO_H
