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
	m_sms(new SMS("ACfe07e61a81cc5a2cb361954afc499a79", "7d64376ed5101e3c558756437800e7a9", "+18603986293")),
	isRFIDLoginActive(false)
{
	ui->setupUi(this);
	ui->email->setAlignment(Qt::AlignCenter);
	ui->password->setAlignment(Qt::AlignCenter);
	ui->logo->setAlignment(Qt::AlignCenter);
	connect(ui->themeSlider, &QSlider::valueChanged, this, &MainWindow::handleThemeChange);
	connect(ui->loginButton, &QPushButton::clicked, this, &MainWindow::onLoginButtonClicked);
	connect(ui->password, &QLineEdit::returnPressed, this, &MainWindow::onLoginButtonClicked);
	connect(ui->email, &QLineEdit::returnPressed, this, &MainWindow::onLoginButtonClicked);
	connect(ui->email, &QLineEdit::editingFinished, this, &MainWindow::onEmailEditingFinished);

	int arduinoConn = arduino.connectArduino();
	switch (arduinoConn) {
	case 0:
		qDebug() << "Arduino is available and connected to : "
			<< arduino.getArduinoPortName();
		break;
	case 1:
		qDebug() << "Given Arduino is not available";
		break;
	case -1:
		qDebug() << "Arduino not found";
		break;
	}
	QObject::connect(arduino.getSerial(), SIGNAL(readyRead()), this,
		SLOT(RFIDLogin()));
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

void MainWindow::onLoginButtonClicked() {
	QString email = ui->email->text().trimmed();
	QString password = ui->password->text();
	QString storedEmail;
	bool require2FA;
	bool currentRememberMeChecked = ui->rememberMe->isChecked();

	QString settingsPath = QApplication::applicationDirPath() + "/settings.ini";
	QSettings settings(settingsPath, QSettings::IniFormat);

	storedEmail = settings.value("StoredEmail").toString();
	require2FA = settings.value("Require2FA", true).toBool();

	if (email.isEmpty() || password.isEmpty()) {
		QMessageBox::warning(this, "Error", "Email and password cannot be empty.");
		return;
	}

	Employee employee;
	if (!employee.login(email, password)) {
		QMessageBox::warning(this, "Error", "Invalid email or password.");
		return;
	}

	if (require2FA) {
		QString employeePhoneNumber = employee.getPhoneNumber();
		QString lastThreeDigits = employeePhoneNumber.right(3);
		QString phoneNumber = QInputDialog::getText(this, "Phone Number Verification", "Please enter your phone number ending in ****" + lastThreeDigits + " for verification:");
		if (phoneNumber.isEmpty() || phoneNumber.right(3) != lastThreeDigits) {
			QMessageBox::warning(this, "Error", "Entered phone number does not match the employee's phone number.");
			return;
		}

		// 2FA required
		QString verificationCode = generateVerificationCode();
		m_verificationCode = verificationCode;
		m_sms->sendSms("+216" + phoneNumber, verificationCode);

		bool ok;
		QString enteredCode = QInputDialog::getText(this, "Verification Code", "Enter the verification code sent to your phone:", QLineEdit::Normal, "", &ok);

		if (!ok || enteredCode.isEmpty()) {
			QMessageBox::warning(this, "Error", "Verification code is required.");
			return;
		}

		if (enteredCode != m_verificationCode) {
			QMessageBox::warning(this, "Error", "Invalid verification code.");
			return;
		}
	}

	// Login successful
	int role = employee.getRole();
	Dashboard* dash = new Dashboard();
	dash->setAttribute(Qt::WA_DeleteOnClose);
	dash->showPageForRole(role);
	dash->createSession(&employee);
	dash->show();
	this->hide();

	require2FA = !currentRememberMeChecked;

	settings.setValue("StoredEmail", email);
	settings.setValue("Require2FA", require2FA);
	settings.sync();
}

void MainWindow::RFIDLogin()
{
	if (isRFIDLoginActive) {
		QMessageBox::warning(this, "Error", "For security purposes, RFID logins are allowed only once per session. Please log in manually.");
		return;
	}

	QString RFIDString = arduino.readFromArduino().trimmed();
	if (!RFIDString.isEmpty()) {
		QSqlQuery query;
		query.prepare("SELECT FIRST_NAME, EMAIL, PASSWORD, ROLE FROM employees WHERE RFID = :RFID");
		query.bindValue(":RFID", RFIDString);

		if (query.exec() && query.next()) {
			isRFIDLoginActive = true;
			 
			QObject::disconnect(arduino.getSerial(), SIGNAL(readyRead()), this, SLOT(RFIDLogin()));

			QString firstName = query.value(0).toString();
			QString email = query.value(1).toString();
			QString password = query.value(2).toString();
			int role = query.value(3).toInt();
			QString name = "2" + firstName;
			arduino.writeToArduino(name.toUtf8());

			Employee employee;
			if (!employee.login(email, password)) {
				return;
			}

			Dashboard* dash = new Dashboard();
			dash->setAttribute(Qt::WA_DeleteOnClose);
			dash->showPageForRole(role);
			dash->createSession(&employee);
			dash->show();
			arduino.closeArduino();
			dash->startRFID();
			this->close();
		}
		else {
			qDebug() << "Failed to retrieve employee details or no such RFID in the system.";
		}
	}
	else {
		qDebug() << "Invalid RFID data.";
	}
}

QString MainWindow::generateVerificationCode()
{
	const QString possibleCharacters = "0123456789";
	const int codeLength = 6;
	QRandomGenerator randomGenerator = QRandomGenerator::securelySeeded();
	QString verificationCode;
	for (int i = 0; i < codeLength; ++i) {
		int index = randomGenerator.bounded(possibleCharacters.length());
		QChar nextChar = possibleCharacters.at(index);
		verificationCode.append(nextChar);
	}

	return verificationCode;
}

void MainWindow::onEmailEditingFinished() {
	QString email = ui->email->text();
	QString settingsPath = QApplication::applicationDirPath() + "/settings.ini";
	QSettings settings(settingsPath, QSettings::IniFormat);
	QString storedEmail = settings.value("StoredEmail").toString();
	bool require2FA = settings.value("Require2FA", false).toBool();
	ui->rememberMe->setChecked(email == storedEmail && !require2FA);
}
Arduino& MainWindow::getArduino()
{
	return arduino;
}