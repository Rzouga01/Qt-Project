
#ifndef CLIENT_H
#define CLIENT_H

#include <QDialog>
#include <QDate>
#include <QTableWidget>


namespace Ui {
    class Client;
}

class Client : public QDialog
{
    Q_OBJECT

private:
    int id;
    QString email;
    QString first_name;
    QString last_name;
    QString phone_number;
    QString address;
    QDate dob;

public:
   explicit Client(QWidget* parent = nullptr);
   explicit Client(QTableWidget *tableWidget, QWidget *parent = nullptr);
   ~Client();
    Client();
    Client(const QString &email, const QString &first_name, const QString & last_name, const QString &phone_number, const QString &address, const QDate &dob);
    Client(const Client& other);

    


private:
    Ui::Client* ui;
    QTableWidget *tableClient;

public:
    void CreateClient();
    void CreateClient(QString email,QString first_name,QString last_name,QString phone_number,QString address,QDate dob);
    void ReadClient();
    void UpdateClient(int clientID, const Client& NewClient);
    void UpdateClient(int clientID, QString email,QString first_name,QString last_name,QString phone_number,QString address,QDate dob);
    void DeleteClient(int id);

    QString getEmail() const { return email; };
    QString getFirstName() const { return first_name; };
    QString getLastName() const { return last_name; };
    QString getPhoneNumber() const { return phone_number; };
    QString getAddress() const  { return address; };
    QDate getDob() const  { return dob; };

    void setEmail(QString email) { this->email = email; };
    void setFirstName(QString first_name) { this->first_name = first_name; };
    void setLastName(QString last_name) { this->last_name = last_name; };
    void setPhoneNumber(QString phone_number) { this->phone_number = phone_number; };
    void setAddress(QString address) { this->address = address; };
    void setDob(QDate dob) { this->dob = dob; };


    void setTableWidget(QTableWidget *tableWidget);
};

#endif // CLIENT_H
