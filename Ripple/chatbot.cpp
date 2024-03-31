#include "ui_chatbot.h"
#include "chatbot.h"


chatbot::chatbot(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::chatbot)
{
    ui->setupUi(this);
}

chatbot::~chatbot()
{
    delete ui;
}
