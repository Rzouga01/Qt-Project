#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QPropertyAnimation>
#include <QEasingCurve>

#include "mainwindow.h"

#include <QApplication>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    ui->email->setAlignment(Qt::AlignCenter);
    ui->password->setAlignment(Qt::AlignCenter);


    connect(ui->themeSlider, &QSlider::valueChanged, this, &MainWindow::handleThemeChange);




  //Logo animation

    QPropertyAnimation *logoAnimation = new QPropertyAnimation(ui->logo, "geometry");

    // Set the duration of the animation (in milliseconds)
    logoAnimation->setDuration(500); // 0.5 seconds

    // Set the start and end scale factors for the logo (e.g., 1.0 to 1.2)
    logoAnimation->setStartValue(QRect(ui->logo->x(), ui->logo->y(), ui->logo->width(), ui->logo->height()));
    logoAnimation->setEndValue(QRect(ui->logo->x() - 10, ui->logo->y() - 10, ui->logo->width() + 20, ui->logo->height() + 20));

    // Set the easing curve for a smooth effect
    logoAnimation->setEasingCurve(QEasingCurve::OutBounce); // You can experiment with different easing curves

    // Start the animation
    logoAnimation->start();


}

MainWindow::~MainWindow()
{
    delete ui;



}
void MainWindow::handleThemeChange(int value) {
    if (value == 0) {
        // Dark theme
        ui->centralwidget->setStyleSheet("background-color: #171717; color: white;");
        ui->email->setStyleSheet("background-color: #FFFFFF; color: #171717;");
        ui->password->setStyleSheet("background-color: #FFFFFF; color: #171717;");
        QPixmap pixmap("../Resources/Logo/icon ripple.png"); // Load black icon pixmap
        ui->logo->setPixmap(pixmap); // Set the black icon pixmap
    } else {
        // Light theme
        ui->centralwidget->setStyleSheet("background-color: #FFFFFF; color: black;");
        ui->email->setStyleSheet("background-color: #333333; color: white;");
        ui->password->setStyleSheet("background-color: #333333; color: white;");
        QPixmap pixmap("../Resources/Logo/icon black.png"); // Load white icon pixmap
        ui->logo->setPixmap(pixmap); // Set the white icon pixmap
    }
}


