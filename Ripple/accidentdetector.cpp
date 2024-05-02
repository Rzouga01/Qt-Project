#include "accidentdetector.h"
#include <random>
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


QString AccidentDetector::parseData(int columnReturn, QString data) {
    QStringList dataList = data.split(" ");
    if (columnReturn >= 0 && columnReturn < dataList.size()) {
        return dataList[columnReturn];
    }
    else {
        qWarning() << "Invalid column"<<columnReturn<<" requested";
        return "";
    }
}


bool AccidentDetector::OnAccidentDetected() {

    QString data=arduino.readFromArduino();

    int clientID = parseData(0,data).toInt();

    // Validate location parsing (assuming parseData returns an int)
    int location = parseData(1, data).toInt();

      // Assuming location is parsed as an int
    float deltaAccela = parseData(2, data).toFloat();

    qDebug() << "Delta Accela: " << deltaAccela;

    QString accidentType = "Car Accident";
    int damage = 1000 * deltaAccela / 3;
    QDate date = QDate::currentDate();

    float accelerationThreshold = 10.0;

    // Ensure all required fields are set in the accident object
    accident accident(nullptr,nullptr);

    // Thread safety (if applicable)
    QMutex mutex;  // Example mutex for thread synchronization
    mutex.lock();
if (deltaAccela > accelerationThreshold && location != 0) {
    if (accident.create(accidentType,damage,date,location,clientID)){
        QMessageBox::information(nullptr, "Accident Detected",
                                 "An accident has been detected through the arduino and added to the database");
        QString writeData="*"+QString::number(clientID)+" "+QString::number(location);

        arduino.writeToArduino(writeData.toUtf8());

        mutex.unlock();
        return true;
    } else {
        QMessageBox::warning(nullptr, "Error", "An error occurred while adding the accident to the database");
        mutex.unlock();
        return false;
    }}
return false;
}


Arduino& AccidentDetector::getArduino()
{
    return arduino;
}

AccidentDetector::~AccidentDetector() {
    arduino.closeArduino();
}
