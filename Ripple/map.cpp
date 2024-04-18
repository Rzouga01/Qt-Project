#include "map.h"
#include "ui_map.h"
#include "accident.h"
#include <QQuickItem>
#include <QMessageBox>
#include <QDebug>
#include <QDialog>
#include <QMessageBox>
#include <QDebug>
#include <QtDebug>


map::map(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::map)
{
    ui->setupUi(this);
    ui->quickWidget->setSource(QUrl(QStringLiteral("qrc:/QmlMap.qml")));
    ui->quickWidget->show();
    auto obj = ui->quickWidget->rootObject();

    if (!obj) {
        QMessageBox::critical(this, "Error", "Failed to load QML file.");
        return;
    }

    bool connected = true;

    connected = connect(this, SIGNAL(setCenter(QVariant, QVariant)), obj, SLOT(setCenter(QVariant, QVariant)));
    if (!connected) {
        QMessageBox::critical(this, "Error", "Failed to connect setCenter signal.");
        return;
    }

    connected = connect(this, SIGNAL(addMarker(QVariant, QVariant)), obj, SLOT(addMarker(QVariant, QVariant)));
    if (!connected) {
        QMessageBox::critical(this, "Error", "Failed to connect addMarker signal.");
        return;
    }

    connected = connect(this, SIGNAL(addSecondMarker(QVariant, QVariant)), obj, SLOT(addSecondMarker(QVariant, QVariant)));
    if (!connected) {
        QMessageBox::critical(this, "Error", "Failed to connect addSecondMarker signal.");
        return;
    }


    emit setCenter(36.8980217004885, 10.189632936848941);
    emit addMarker(36.8980217004885, 10.189632936848941);
}

map::~map()
{
    delete ui;
}


