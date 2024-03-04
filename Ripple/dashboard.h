#ifndef DASHBOARD_H
#define DASHBOARD_H

#include <QDialog>
#include <QApplication>
#include <QtWidgets>
#include <QUiLoader>
#include "mainwindow.h"

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
    void onAddClicked();
    void onDeleteClicked();
    void onUpdateClicked();
    void onSortClicked();
    void onPdfClicked();

private:
    Ui::Dashboard *ui;
    MainWindow mainWindowRef;
};

#endif // DASHBOARD_H
