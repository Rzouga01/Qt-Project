#include "menu.h"
#include "ui_menu.h"

Menu::Menu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Menu)
{
    ui->setupUi(this);

    QIcon icon("../Resources/Icons/logout.png");

    ui->logoutButton->setIcon(icon);
    ui->logoutButton->setText("Logout");
}

Menu::~Menu()
{
    delete ui;
}
