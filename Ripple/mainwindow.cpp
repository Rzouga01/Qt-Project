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
    ui->logo->setAlignment(Qt::AlignCenter);


    connect(ui->themeSlider, &QSlider::valueChanged, this, &MainWindow::handleThemeChange);


}

MainWindow::~MainWindow()
{
    delete ui;



}
void MainWindow::animation()
{
    // Store the original geometry of the logo QLabel
    QRect originalLogoGeometry = ui->logo->geometry();

    // Logo animation
    QPropertyAnimation *logoAnimation = new QPropertyAnimation(ui->logo, "geometry");

    // Set the duration of the animation (in milliseconds)
    logoAnimation->setDuration(500); // 0.5 seconds

    // Set the start and end scale factors for the logo (e.g., 1.0 to 1.2)
    logoAnimation->setStartValue(QRect(ui->logo->x(), ui->logo->y(), ui->logo->width(), ui->logo->height()));
    logoAnimation->setEndValue(QRect(ui->logo->x() - 10, ui->logo->y() - 10, ui->logo->width() + 20, ui->logo->height() + 20));

    // Set the easing curve for a smooth effect
    logoAnimation->setEasingCurve(QEasingCurve::OutBounce); // You can experiment with different easing curves

    // Connect the finished() signal of the animation to the resetLogoSize slot
    connect(logoAnimation, &QPropertyAnimation::finished, [=]() {
resetLogoSize(originalLogoGeometry);
    });

    // Start the animation
    logoAnimation->start();
}

void MainWindow::resetLogoSize(const QRect &size)
{
    // Reset the size of the logo QLabel to its original size
    ui->logo->setGeometry(size);
}


void MainWindow::handleThemeChange(int value) {
    MainWindow::animation();
    if (value == 0) {
        // Dark theme
        ui->centralwidget->setStyleSheet("background-color: #171717; color: white;");
        ui->email->setStyleSheet("background-color: #FFFFFF; color: #171717;");
        ui->password->setStyleSheet("background-color: #FFFFFF; color: #171717;");
        ui->dark_theme->setStyleSheet("color: #FFFFFF;");
        ui->light_theme->setStyleSheet("color: #FFFFFF;");
        QPixmap pixmap("../Resources/Logo/icon ripple.png");
        ui->logo->setPixmap(pixmap);

    } else {
        // Light theme
        ui->centralwidget->setStyleSheet("background-color: #FFFFFF; color: black;");
        ui->email->setStyleSheet("background-color: #333333; color: white;");
        ui->password->setStyleSheet("background-color: #333333; color: white;");
        ui->dark_theme->setStyleSheet("color: #171717;");
        ui->light_theme->setStyleSheet("color: #171717;");
        QPixmap pixmap("../Resources/Logo/icon white.png");
        ui->logo->setPixmap(pixmap);
    }
}


