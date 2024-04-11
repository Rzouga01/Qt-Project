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
#include <QStyledItemDelegate>
#include <QPainter>
#include <QStyleOptionViewItem>
#include <QModelIndex>
#include <QFontMetrics>
#include <QTextDocument>
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
#include <QMediaRecorder>
#include <QMessageBox>
#include <portaudio.h>
#include <sndfile.h>
#include <speechapi_cxx.h>

// Define constants
#define SAMPLE_RATE  (44100)
#define FRAMES_PER_BUFFER (512)
#define NUM_SECONDS     (5)
#define NUM_CHANNELS    (2)
#define DITHER_FLAG     (0)
#define WRITE_TO_FILE   (1) // Set to 1 to enable writing to file
#define FILE_NAME "recorded.wav" // Output WAV file name

// Define sample type
#define PA_SAMPLE_TYPE  paFloat32
typedef float SAMPLE;

// Define sample silence and print format
#define SAMPLE_SILENCE  (0.0f)
#define PRINTF_S_FORMAT "%.8f"

// Define data structure for recording
typedef struct
{
    int          frameIndex;  /* Index into sample array. */
    int          maxFrameIndex;
    SAMPLE* recordedSamples;
} paTestData;

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
    void onVoiceButtonClicked();
    void handleBotResponse(QNetworkReply* reply);
    void recordVoice();
private:
    Ui::chatbot* ui;
    QNetworkAccessManager m_manager;
    paTestData m_paTestData; // Declare m_paTestData
    PaStream* m_paStream; // Declare m_paStream

    void sendUserMessage(const QString& message);
    void sendAudioToChatbot(const QString& audioFilePath);
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

class MessageBubbleDelegate : public QStyledItemDelegate {
public:
    MessageBubbleDelegate(QObject* parent = nullptr) : QStyledItemDelegate(parent) {}

    void paint(QPainter* painter, const QStyleOptionViewItem& option, const QModelIndex& index) const override {
        QString text = index.data(Qt::DisplayRole).toString();
        bool isSentByUser = index.data(Qt::UserRole).toBool(); // Assuming you set UserRole to identify if the message is sent by the user

        // Define colors and margins
        QColor bubbleColor = isSentByUser ? QColor("#A7C34E") : QColor("#333333");
        QColor textColor = isSentByUser ? Qt::white : Qt::white; // Adjust text color
        int bubbleMargin = 10;
        int bubblePadding = 10;
        int borderRadius = 10;

        // Set the background color and other properties based on whether the message is sent by the user or not
        painter->setRenderHint(QPainter::Antialiasing);
        painter->setBrush(bubbleColor);
        painter->setPen(Qt::NoPen);

        // Calculate the size of the bubble
        QFontMetrics metrics(option.font);
        QSize bubbleSize = metrics.boundingRect(QRect(0, 0, option.rect.width() - 2 * bubbleMargin, 0), Qt::AlignLeft | Qt::TextWordWrap, text).size() + QSize(2 * bubblePadding, 2 * bubblePadding);

        // Calculate the position of the bubble
        int bubbleX = isSentByUser ? option.rect.right() - bubbleSize.width() - bubbleMargin : option.rect.left() + bubbleMargin;
        int bubbleY = option.rect.top() + bubbleMargin;

        // Draw the bubble rectangle
        QRect bubbleRect(bubbleX, bubbleY, bubbleSize.width(), bubbleSize.height());
        painter->drawRoundedRect(bubbleRect, borderRadius, borderRadius);

        // Draw the text inside the bubble
        QTextDocument doc;
        doc.setDefaultFont(option.font);
        doc.setDefaultStyleSheet(QString("body { color: %1; }").arg(textColor.name()));
        doc.setHtml("<body>" + text + "</body>");

        // Draw the text with proper alignment
        QRect textRect = bubbleRect.adjusted(bubblePadding, bubblePadding, -bubblePadding, -bubblePadding);
        painter->translate(textRect.topLeft());
        doc.drawContents(painter);
        painter->translate(-textRect.topLeft());
    }
};
#endif // CHATBOT_H
