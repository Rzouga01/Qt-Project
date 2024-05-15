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
        return "";
    }
}


bool AccidentDetector::OnAccidentDetected() {
    QString writeData = "*"; // Initialize writeData with the message prefix

    QString data = arduino.readFromArduino();

    int clientID = parseData(0, data).toInt();
    int location = parseData(1, data).toInt();
    float deltaAccela = parseData(2, data).toFloat();

    QString accidentType = "Vehicule Accident";
    int damage = 1000 * deltaAccela / 3;
    QDate date = QDate::currentDate();

    float accelerationThreshold = 5.0;
    QString Information="";

    accident accident(nullptr, nullptr); // Ensure all required fields are set in the accident object

    QMutex mutex; // Example mutex for thread synchronization
    mutex.lock(); // Lock the mutex

    if (deltaAccela > accelerationThreshold && location != 0) {
        if (accident.create(accidentType, damage, date, location, clientID)) {
            QMessageBox msgBox;
            msgBox.setWindowTitle("Accident Detected");
            msgBox.setText("An accident has been detected!");

            QSqlQuery qry;

            // Query the CLIENTS table to get the client name
            qry.prepare("SELECT * FROM CLIENTS WHERE CLIENT_ID = :id");
            qry.bindValue(":id", clientID);

            if (qry.exec() && qry.next()) {
                QString ClientName = qry.value(2).toString();
                Information+="Client Name:"+ClientName+"\n";
                Information+="Client Last Name:"+qry.value(3).toString()+"\n";
                Information+="Client Phone:"+qry.value(5).toString()+"\n";

                writeData += ClientName; // Append client name to writeData
            } else {
                QMessageBox::warning(nullptr, "Error", "Error querying client data");
                mutex.unlock(); // Unlock the mutex before returning
                return false;
            }

            // Query the LOCATION table to get the location name
            qry.prepare("SELECT * FROM LOCATION WHERE LOCATION_ID = :id");
            qry.bindValue(":id", location);

            if (qry.exec() && qry.next()) {
                QString locationName = qry.value(1).toString();
                Information+="Location Name:"+locationName+"\n";
                writeData += " " + locationName; // Append location name to writeData
            } else {
                QMessageBox::warning(nullptr, "Error", "Error querying location data");
                mutex.unlock(); // Unlock the mutex before returning
                return false;
            }

            // Send the formatted message to Arduino
            QString message = "Accident Detected\n" + Information;
            msgBox.setInformativeText(message);

            QPushButton* mapButton = msgBox.addButton(tr("Show on Map"), QMessageBox::ActionRole);
            QPushButton* closeButton = msgBox.addButton(QMessageBox::Close);

            msgBox.setIcon(QMessageBox::Information);
            msgBox.setDefaultButton(mapButton);

            // Show the pop-up dialog and wait for user response
            msgBox.exec();

            if (msgBox.clickedButton() == mapButton) {
                showMapAccident(location);
            }

            arduino.writeToArduino(writeData.toUtf8());
            mutex.unlock(); // Unlock the mutex before returning
            return true;
        } else {
            QMessageBox::warning(nullptr, "Error", "Error creating accident entry");
            mutex.unlock(); // Unlock the mutex before returning
            return false;
        }
    }

    mutex.unlock(); // Unlock the mutex before returning
    return false;
}

void AccidentDetector::showMapAccident(int locationID) {
    QSqlQuery qry;
    qry.prepare("SELECT * FROM LOCATION WHERE LOCATION_ID = ?");
    qry.addBindValue(locationID);
    if (qry.exec() && qry.next()) {
        float x = qry.value(2).toFloat();
        float y = qry.value(3).toFloat();
        qDebug() << "Location coordinates retrieved from database - x:" << x << ", y:" << y;

        map p(nullptr, x, y);
        p.exec();
    } else {
        qDebug() << "Failed to retrieve location from the database.";
    }
}

Arduino& AccidentDetector::getArduino()
{
    return arduino;
}

AccidentDetector::~AccidentDetector() {
    arduino.closeArduino();
}
