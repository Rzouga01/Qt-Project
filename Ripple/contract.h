#ifndef CONTRACT_H
#define CONTRACT_H

#include <QDialog>

namespace Ui {
class contract;
}

class contract : public QDialog
{
    Q_OBJECT

public:
    explicit contract(QWidget *parent = nullptr);
    ~contract();

private:
    Ui::contract *ui;
};

#endif // CONTRACT_H
