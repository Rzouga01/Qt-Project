#ifndef DASHBOARD_H
#define DASHBOARD_H



#include <QDialog>
#include <QApplication>
#include <QtWidgets>
#include <QUiLoader>


namespace Ui {
class Dashboard;
}

class Dashboard : public QDialog
{
    Q_OBJECT

public:
    explicit Dashboard(QWidget *parent = nullptr);
    ~Dashboard();

    void update();
    void onLogoutButtonClicked();

private:
    Ui::Dashboard *ui;

};



#endif // DASHBOARD_H
