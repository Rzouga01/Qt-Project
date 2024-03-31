#ifndef CHATBOX_H
#define CHATBOX_H

#include <QWidget>

namespace Ui {
class chat;
}

class chatbox : public QWidget
{
    Q_OBJECT

public:
    explicit chatbox(QWidget *parent = nullptr);
    ~chatbox();

private:
    Ui::chat *ui;
};

#endif // CHATBOX_H
