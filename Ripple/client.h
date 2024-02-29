#ifndef CLIENT_H
#define CLIENT_H

#include <QDialog>
#include <QDate>

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
    QString adress;
    QDate dob;

public:
    explicit Client(QWidget *parent = nullptr);
    ~Client();
    Client();
    Client(QString email, QString first_name, QString last_name, QString phone_number, QString adress, QDate dob);

private:
    Ui::Client *ui;

public:
    void CreateClient();
    void ReadClient();
    void UpdateClient();
    void DeleteClient(int id);


    QString getEmail() {return email;};
    QString getFirstName() {return first_name;};
    QString getLastName() {return last_name;};
    QString getPhoneNumber() {return phone_number;};
    QString getAdress() {return adress;};
    QDate getDob() {return dob;};


    void setEmail(QString email) {this->email = email;};
    void setFirstName(QString first_name) {this->first_name = first_name;};
    void setLastName(QString last_name) {this->last_name = last_name;};
    void setPhoneNumber(QString phone_number) {this->phone_number = phone_number;};
    void setAdress(QString adress) {this->adress = adress;};
    void setDob(QDate dob) {this->dob = dob;};



};

#endif // CLIENT_H
