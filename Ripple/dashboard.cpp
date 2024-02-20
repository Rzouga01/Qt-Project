#include "dashboard.h"
#include "ui_dashboard.h"

#include <QApplication>
#include <QtWidgets>
#include <QUiLoader>


Dashboard::Dashboard(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dashboard)
{
    ui->setupUi(this);
    ui->role->setText("Customer Manager");
    ui->helloBar->setPlainText("Hello,\nMalek Bsaissa");

    update();


}

void Dashboard::update(){

    QStackedWidget stackedWidget;

    QUiLoader loader;


    QObject::connect(ui->employees, &QPushButton::clicked, [this](){ ui->stackedWidget->setCurrentIndex(0); });
    QObject::connect(ui->clients, &QPushButton::clicked, [this](){ ui->stackedWidget->setCurrentIndex(1); });
    QObject::connect(ui->contracts, &QPushButton::clicked, [this](){ ui->stackedWidget->setCurrentIndex(2); });
    QObject::connect(ui->accidents, &QPushButton::clicked, [this](){ ui->stackedWidget->setCurrentIndex(3); });




    stackedWidget.show();

}

Dashboard::~Dashboard()
{
    delete ui;
}
