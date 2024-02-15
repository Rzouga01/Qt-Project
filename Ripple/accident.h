#ifndef ACCIDENT_H
#define ACCIDENT_H

#include <QDialog>

namespace Ui {
class accident;
}

class accident : public QDialog
{
    Q_OBJECT

public:
    explicit accident(QWidget *parent = nullptr);
    ~accident();

private:
    Ui::accident *ui;
};

#endif // ACCIDENT_H
