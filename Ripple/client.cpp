#include "client.h"
#include "ui_client.h"

Client::Client(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Client)
{
    ui->setupUi(this);
    ui->role->setText("Customer Manager");
    ui->helloBar->setPlainText("Hello,\nMalek Bsaissa");

}

Client::~Client()
{
    delete ui;
}
