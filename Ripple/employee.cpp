#include "employee.h"
#include "ui_employee.h"

Employee::Employee(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Employee)
{
    ui->setupUi(this);
    ui->role->setText("Employee Manager");
    ui->helloBar->setPlainText("Hello,\nAbd Razek Nakhli");
}

Employee::~Employee()
{
    delete ui;
};
