#ifndef CHATBOT_H
#define CHATBOT_H

#include <QDialog>
#include <QMovie>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>
#include <QVBoxLayout>
#include <QLabel>
#include <QListWidget>
#include <QPushButton>
#include <QDebug>
#include <QScrollBar>
#include <QtCore/QProcessEnvironment>
QT_BEGIN_NAMESPACE
namespace Ui { class chatbot; }
QT_END_NAMESPACE

class chatbot : public QDialog
{
    Q_OBJECT

public:
    chatbot(QWidget* parent = nullptr);
    ~chatbot();

private slots:
    void onSendMessageClicked();
    void handleBotResponse(QNetworkReply* reply);
    QWidget* createLoadingWidget();

private:
    Ui::chatbot* ui;
    QMovie* loadingMovie;

    void sendUserMessage(const QString& message);
};

#endif // CHATBOT_H
