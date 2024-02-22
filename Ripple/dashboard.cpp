#include "dashboard.h"
#include "ui_dashboard.h"

#include <QApplication>
#include <QtWidgets>
#include <QUiLoader>

#include "mainwindow.h"



Dashboard::Dashboard(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dashboard),
    mainWindowRef()

{
    ui->setupUi(this);
    ui->role->setText("Role Test");
    ui->helloBar->setPlainText("Hello,\nFirst Name Last Name");

    update();
}


void Dashboard::onLogoutButtonClicked() {
    close();
    mainWindowRef.show();
}

void Dashboard::update(){

    QStackedWidget stackedWidget;


    QUiLoader loader;


    QObject::connect(ui->employees, &QPushButton::clicked, this, [this](){ ui->stackedWidget->setCurrentIndex(0); });
    QObject::connect(ui->clients, &QPushButton::clicked, this, [this](){ ui->stackedWidget->setCurrentIndex(1); });
    QObject::connect(ui->contracts, &QPushButton::clicked, this, [this](){ ui->stackedWidget->setCurrentIndex(2); });
    QObject::connect(ui->accidents, &QPushButton::clicked, this, [this](){ ui->stackedWidget->setCurrentIndex(3); });

    QObject::connect(ui->logoutButton, &QPushButton::clicked, this, &Dashboard::onLogoutButtonClicked);
    stackedWidget.show();

}

Dashboard::~Dashboard()
{
    delete ui;
}
