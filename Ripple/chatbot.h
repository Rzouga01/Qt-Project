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
#include <QScrollArea>
#include <QScrollBar>
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
	int frameIndex;
	int maxFrameIndex;
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
	PaStream* m_paStream;

	void sendUserMessage(const QString& message);
	void sendAudioToChatbot(const QString& audioFilePath);
    void addMessageBubble(const QString& text, bool isUser);
public slots:
	void moveScrollBarToBottom(int min, int max);
};


#endif // CHATBOT_H
