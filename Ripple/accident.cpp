#include "accident.h"
#include "ui_accident.h"

accident::accident(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::accident)
{

    ui->setupUi(this);
    ui->role->setText("Accident Manager");
    ui->helloBar->setPlainText("Hello,\nWalaa Eddine Ghrairi");
}

accident::~accident()
{
    delete ui;
}
