#ifndef ACCIDENTDETECTOR_H
#define ACCIDENTDETECTOR_H

#include <QObject>
#include <QSharedDataPointer>
#include <accident.h>
#include "arduino.h"
#include <map.h>

class AccidentDetectorData;

class AccidentDetector : public QObject  // Inherit from QObject
{
    Q_OBJECT
public:
    AccidentDetector();
    AccidentDetector(const AccidentDetector &);
    AccidentDetector &operator=(const AccidentDetector &);
    ~AccidentDetector();
    QString parseData(int columnReturn, QString data);
    Arduino& getArduino();
    bool OnAccidentDetected();
    bool sendAccidentNotification(const accident& accident);
    void showMapAccident(int locationID);

private:
    Arduino arduino;
    QSharedDataPointer<AccidentDetectorData> data;
};

#endif // ACCIDENTDETECTOR_H
