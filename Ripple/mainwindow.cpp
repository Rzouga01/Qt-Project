#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPropertyAnimation>
#include <QEasingCurve>
#include "mainwindow.h"
#include <QApplication>
#include "dashboard.h"
#include "employee.h"
#include "sms.h"
MainWindow::MainWindow(QWidget* parent)
	: QMainWindow(parent),
	ui(new Ui::MainWindow),
	logoAnimation(nullptr),
    m_sms(new SMS("ACfe07e61a81cc5a2cb361954afc499a79", "7d64376ed5101e3c558756437800e7a9", "+18603986293"))
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
        // Generate a random verification code
        QString verificationCode = generateVerificationCode();

        // Store the verification code
        m_verificationCode = verificationCode;

        // Send the verification code via SMS
        QString phoneNumber = "+216" + employee.getPhoneNumber();

        QString message = "Your verification code is: " + verificationCode;
        m_sms->sendSms(phoneNumber, message);

        // Prompt the user to enter the verification code
        bool ok;
        QString enteredCode = QInputDialog::getText(this, "Verification Code", "Enter the verification code sent to your phone:", QLineEdit::Normal, "", &ok);

        if (ok && !enteredCode.isEmpty()) {
            // Compare the entered code with the generated code
            if (enteredCode == m_verificationCode) {
                // Codes match, proceed with showing the dashboard
                int role = employee.getRole();
                Dashboard* dash = new Dashboard();
                dash->setAttribute(Qt::WA_DeleteOnClose);
                dash->showPageForRole(role);
                dash->createSession(&employee);
                dash->show(); // Show the dashboard
                this->hide(); // Hide the main window
            }
            else {
                // Codes don't match, show error message
                QMessageBox::warning(this, "Error", "Invalid verification code.");
            }
        }
        else {
            // User canceled or entered empty code, show error message
            QMessageBox::warning(this, "Error", "Verification code is required.");
        }
    }
    else {
        QMessageBox::warning(this, "Error", "Invalid email or password.");
    }
}


QString MainWindow::generateVerificationCode()
{
	const QString possibleCharacters = "0123456789"; // Define the characters allowed in the verification code

	// Set the length of the verification code
	const int codeLength = 6;

	// Seed the random number generator
	QRandomGenerator randomGenerator = QRandomGenerator::securelySeeded();

	// Generate the verification code
	QString verificationCode;
	for (int i = 0; i < codeLength; ++i) {
		int index = randomGenerator.bounded(possibleCharacters.length());
		QChar nextChar = possibleCharacters.at(index);
		verificationCode.append(nextChar);
	}

	return verificationCode;
}


