#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QPropertyAnimation>
#include <QEasingCurve>

#include "client.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    ui->email->setAlignment(Qt::AlignCenter);
    ui->password->setAlignment(Qt::AlignCenter);



    // Assuming your logo is represented by a QLabel named 'logoLabel'

    // Create a property animation for the logo label
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


