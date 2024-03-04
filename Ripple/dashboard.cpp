#include "dashboard.h"
#include "ui_dashboard.h"

#include <QApplication>
#include <QtWidgets>
#include <QUiLoader>
#include "mainwindow.h"
#include "connection.h"
#include "client.h"

Dashboard::Dashboard(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dashboard)
{
    ui->setupUi(this);
    Client client(ui->tableClient, this);
    Connection con;

    if(!con.createconnect())
    {
        qDebug() << "Not Connected";
    }
    else
    {
        client.ReadClient();
        update();
    }

}

void Dashboard::update() {

   QIcon addIcon("../Resources/Icons/add.png");
   QIcon deleteIcon("../Resources/Icons/delete.png");
   QIcon updateIcon("../Resources/Icons/update.png");
   QIcon sortIcon("../Resources/Icons/sort.png");
   QIcon pdfIcon("../Resources/Icons/pdf.png");

    ui->add->setIcon(addIcon);
    ui->del->setIcon(deleteIcon);
    ui->update->setIcon(updateIcon);
    ui->sort->setIcon(sortIcon);
    ui->pdf->setIcon(pdfIcon);

    QObject::connect(ui->add, &QPushButton::clicked, this, &Dashboard::onAddClicked);
    QObject::connect(ui->del, &QPushButton::clicked, this, &Dashboard::onDeleteClicked);
    QObject::connect(ui->update, &QPushButton::clicked, this, &Dashboard::onUpdateClicked);
    QObject::connect(ui->sort, &QPushButton::clicked, this, &Dashboard::onSortClicked);
    QObject::connect(ui->pdf, &QPushButton::clicked, this, &Dashboard::onPdfClicked);

    QObject::connect(ui->employees, &QPushButton::clicked, this, [this](){ ui->stackedWidget->setCurrentIndex(0); });
    QObject::connect(ui->clients, &QPushButton::clicked, this, [this](){ ui->stackedWidget->setCurrentIndex(1); });
    QObject::connect(ui->contracts, &QPushButton::clicked, this, [this](){ ui->stackedWidget->setCurrentIndex(2); });
    QObject::connect(ui->accidents, &QPushButton::clicked, this, [this](){ ui->stackedWidget->setCurrentIndex(3); });

    QObject::connect(ui->logoutButton, &QPushButton::clicked, this, &Dashboard::onLogoutButtonClicked);
    this->repaint();
}


void Dashboard::onLogoutButtonClicked() {
    close();
    mainWindowRef.show();
}



void Dashboard::onAddClicked() {
    // Handle add button click
}

void Dashboard::onDeleteClicked() {
    // Handle delete button click
}

void Dashboard::onUpdateClicked() {
    // Handle update button click
}

void Dashboard::onSortClicked() {
    // Handle sort button click
}

void Dashboard::onPdfClicked() {
    // Handle pdf button click
}

Dashboard::~Dashboard() {
    delete ui;
}


