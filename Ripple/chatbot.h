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
#include <QFile>
#include <QFileDialog>
#include <QTextEdit>
#include <QScrollBar>
#include <QBuffer>
#include <QtMultimedia>
#include <QAudioInput>
#include <QAudioFormat>
#include <QMediaFormat>
#include <QMediaRecorder>


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

private:
    Ui::chatbot* ui;
    QMovie* loadingMovie;
    QNetworkAccessManager m_manager;
    QBuffer m_buffer;
    QAudioInput* m_audioInput;
    QAudioFormat m_format;

    void sendUserMessage(const QString& message);
};

class LoadingWidget : public QWidget {
    Q_OBJECT

public:
    LoadingWidget(QWidget* parent = nullptr) : QWidget(parent) {
        setWindowFlags(Qt::FramelessWindowHint | Qt::Dialog);
        setAttribute(Qt::WA_TranslucentBackground);
        setFixedSize(200, 100);

        QVBoxLayout* layout = new QVBoxLayout(this);
        loadingLabel = new QLabel(this);
        loadingMovie = new QMovie("../Resources/Gifs/chatloading.gif", QByteArray(), this);
        loadingLabel->setMovie(loadingMovie);
        loadingMovie->start();
        layout->addWidget(loadingLabel);
        setLayout(layout);
    }

    ~LoadingWidget() {
        delete loadingMovie;
    }

private:
    QLabel* loadingLabel;
    QMovie* loadingMovie;
};

#endif // CHATBOT_H
