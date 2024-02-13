#include "client.h"
#include "ui_client.h"

Client::Client(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Client)
{
    ui->setupUi(this);
    ui->role->setText("Customer");
    ui->helloBar->setPlainText("Hello,\nMalek Bsaissa");

    ui->helloBar->setFixedWidth(200);
}

Client::~Client()
{
    delete ui;
}
