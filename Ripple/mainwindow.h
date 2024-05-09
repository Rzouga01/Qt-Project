#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPropertyAnimation>
#include "sms.h"
#include "arduino.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void handleThemeChange(int value);
    void animation();
    void resetLogoSize(const QRect &size);
    void onLoginButtonClicked();
    QString generateVerificationCode();
    void onEmailEditingFinished();
    Arduino& getArduino();

private:
    Ui::MainWindow *ui;
     QPropertyAnimation *logoAnimation;
     QString m_verificationCode;    
     SMS *m_sms;
     bool m_rememberMe = false;
     QString m_storedEmail;
     bool m_isRemembered = false;
     Arduino arduino;
     bool isRFIDLoginActive = false;
private slots:
    void RFIDLogin();
};
#endif // MAINWINDOW_H
