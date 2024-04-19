#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPropertyAnimation>
#include "sms.h"

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

private:
    Ui::MainWindow *ui;
     QPropertyAnimation *logoAnimation;
     QString m_verificationCode;
     SMS *m_sms;
};
#endif // MAINWINDOW_H
