#include "accident.h"
#include "ui_accident.h"



accident::accident(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::accident)
{

    ui->setupUi(this);

}

accident::~accident()
{
    delete ui;
}
