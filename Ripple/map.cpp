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


map::map(QWidget* parent, float x, float y) :
    QDialog(parent),
    ui(new Ui::map)
{
    ui->setupUi(this);
    ui->quickWidget->setSource(QUrl(QStringLiteral("qrc:/QmlMap.qml")));

    // Check if the QML file is loaded successfully
    auto obj = ui->quickWidget->rootObject();
    if (!obj) {
        QMessageBox::critical(this, "Error", "Failed to load QML file.");
        return;
    }

    // Connect signals to corresponding slots in QML
    bool connected = connect(this, SIGNAL(setCenter(QVariant, QVariant)), obj, SLOT(setCenter(QVariant, QVariant)));
    if (!connected) {
        QMessageBox::critical(this, "Error", "Failed to connect setCenter signal.");
        return;
    }

    connected = connect(this, SIGNAL(addMarker(QVariant, QVariant)), obj, SLOT(addMarker(QVariant, QVariant)));
    if (!connected) {
        QMessageBox::critical(this, "Error", "Failed to connect addMarker signal.");
        return;
    }

    // Set initial map center and add marker
    emit setCenter(x, y);
    emit addMarker(x, y);
}

/*void map::setPointer(float x, float y) {
     setCenter(x,y);
     addMarker(x,y);
}*/
map::~map()
{
    delete ui;
}


