#ifndef CHATBOT_H
#define CHATBOT_H

#include <QWidget>

namespace Ui {
class chatbot;
}

class chatbot : public QWidget
{
    Q_OBJECT

public:
    explicit chatbot(QWidget *parent = nullptr);
    ~chatbot();

private:
    Ui::chatbot *ui;
};

#endif // CHATBOT_H
