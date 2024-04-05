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
#include <QMessageBox>
#include "portaudio.h"
#include <QProcessEnvironment>
#include <speechapi_cxx.h>

#define SAMPLE_RATE         (44100)
#define PA_SAMPLE_TYPE      paFloat32
#define NUM_CHANNELS        (1)
#define FRAMES_PER_BUFFER   (512)

QT_BEGIN_NAMESPACE
namespace Ui { class chatbot; }
QT_END_NAMESPACE

class chatbot : public QDialog
{
    Q_OBJECT

public:
    chatbot(QWidget* parent = nullptr);
    ~chatbot();
    static int recordCallback(const void* inputBuffer, void* outputBuffer,
        unsigned long framesPerBuffer,
        const PaStreamCallbackTimeInfo* timeInfo,
        PaStreamCallbackFlags statusFlags,
        void* userData);
private slots:
    void onSendMessageClicked();
    void onVoiceButtonClicked();
    void handleBotResponse(QNetworkReply* reply);
    void sendAudioToChatbot(const QString& audioFilePath);
    void startRecording();
    void stopRecording();
    void sendRecordedAudio();

private:
    Ui::chatbot* ui;
    QNetworkAccessManager m_manager;
    QBuffer m_audioBuffer;
    PaStream* m_paStream;
    int m_recordedFrames;
    QByteArray m_recordedBuffer;

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
