#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPropertyAnimation>


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

private:
    Ui::MainWindow *ui;
     QPropertyAnimation *logoAnimation;
};
#endif // MAINWINDOW_H
