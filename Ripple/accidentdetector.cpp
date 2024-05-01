#include "accidentdetector.h"

class AccidentDetectorData : public QSharedData
{
public:
};

AccidentDetector::AccidentDetector()
    : data(new AccidentDetectorData)
{}

AccidentDetector::AccidentDetector(const AccidentDetector &rhs)
    : data{rhs.data}
{}

AccidentDetector &AccidentDetector::operator=(const AccidentDetector &rhs)
{
    if (this != &rhs)
        data.operator=(rhs.data);
    return *this;
}


QString AccidentDetector::parseData(int columnReturn, QString data)
{
    return data.split("_")[columnReturn];

}

bool AccidentDetector::OnAccidentDetected(QString data)
{

    int clientID = parseData(0,data).toInt();

    int location=parseData(1,data).toInt();

    float accelaX = parseData(2,data).toFloat();
    float accelaY = parseData(3,data).toFloat();
    float accelaZ = parseData(4,data).toFloat();

    float deltaAccela = abs(accelaX)+abs(accelaY)+abs(accelaZ);

    QString accidentType="Car Accident";

    int damage=1000*deltaAccela/3;
    QDate date=QDate::currentDate();

    accident accident(nullptr,nullptr);

    if(accident.create(accidentType,damage,date,QString::number(location),clientID))
    {
        QMessageBox::information(nullptr,"Accident Detected","An accident has been detected and added to the database");

        return true;
    }
    return false;
}



Arduino& AccidentDetector::getArduino()
{
    return arduino;
}

AccidentDetector::~AccidentDetector() {
    arduino.closeArduino();
}
