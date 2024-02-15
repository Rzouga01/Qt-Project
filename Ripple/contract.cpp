#include "contract.h"
#include "ui_contract.h"

contract::contract(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::contract)
{
    ui->setupUi(this);
    ui->role->setText("Contracts Manager");
    ui->helloBar->setPlainText("Hello,\nAmine Larbi");
}

contract::~contract()
{
    delete ui;
}
