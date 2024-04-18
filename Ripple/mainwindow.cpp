#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPropertyAnimation>
#include <QEasingCurve>
#include "mainwindow.h"
#include <QApplication>
#include "dashboard.h"
#include "employee.h"

MainWindow::MainWindow(QWidget* parent)
	: QMainWindow(parent),
	ui(new Ui::MainWindow),
	logoAnimation(nullptr)
{
	ui->setupUi(this);
	ui->email->setAlignment(Qt::AlignCenter);
	ui->password->setAlignment(Qt::AlignCenter);
	ui->logo->setAlignment(Qt::AlignCenter);
	connect(ui->themeSlider, &QSlider::valueChanged, this, &MainWindow::handleThemeChange);
	connect(ui->loginButton, &QPushButton::clicked, this, &MainWindow::onLoginButtonClicked);
	connect(ui->password, &QLineEdit::returnPressed, this, &MainWindow::onLoginButtonClicked);
	connect(ui->email, &QLineEdit::returnPressed, this, &MainWindow::onLoginButtonClicked);
}

MainWindow::~MainWindow()
{
	delete ui;

}

void MainWindow::animation()
{
	// If logoAnimation already exists, stop and delete it to prevent memory leaks
	if (logoAnimation) {
		logoAnimation->stop();
		delete logoAnimation;
		logoAnimation = nullptr;
	}

	// Store the original geometry of the logo QLabel if it's not stored yet
	static QRect originalLogoGeometry = ui->logo->geometry();

	// Create a new logo animation
	logoAnimation = new QPropertyAnimation(ui->logo, "geometry");

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

void MainWindow::resetLogoSize(const QRect& size)
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

	}
	else {
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

void MainWindow::onLoginButtonClicked()
{
	QString email = ui->email->text();
	QString password = ui->password->text();
	Employee employee;
	if (employee.login(email, password)) {
		int role = employee.getRole();
		// Create a dynamic instance of Dashboard
		Dashboard* dash = new Dashboard();
		dash->setAttribute(Qt::WA_DeleteOnClose);
		dash->showPageForRole(role);
		dash->createSession(&employee);
		dash->show(); // Show the dashboard
		this->hide(); // Hide the main window
	}
	else {
		QMessageBox::warning(this, "Error", "Invalid email or password.");
	}
}


