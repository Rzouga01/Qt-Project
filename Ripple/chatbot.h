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
#include <QThread>

#define SAMPLE_RATE  (44100)
#define FRAMES_PER_BUFFER (512)
#define NUM_SECONDS     (10)
#define NUM_CHANNELS    (2)
#define DITHER_FLAG     (0)
#define WRITE_TO_FILE   (1) 
#define FILE_NAME ".wav" 
#define PA_SAMPLE_TYPE  paFloat32
typedef float SAMPLE;
#define SAMPLE_SILENCE  (0.0f)
#define PRINTF_S_FORMAT "%.8f"

typedef struct
{
	int frameIndex;
	int maxFrameIndex;
	SAMPLE* recordedSamples;
} paTestData;

QT_BEGIN_NAMESPACE
namespace Ui { class chatbot; }
QT_END_NAMESPACE

class RecordingThread : public QThread
{
	Q_OBJECT

public:
	explicit RecordingThread(QObject* parent = nullptr);
	void run() override;
	void stopRecording(); 

signals:
	void recordingFinished(const QString& filePath);

private:
	PaStream* m_paStream;
	bool m_isRecording; 

	void recordVoice();
};

class chatbot : public QDialog
{
	Q_OBJECT

public:
	chatbot(QWidget* parent = nullptr);
	~chatbot();

private slots:
	void moveScrollBarToBottom(int min, int max);
	void onSendMessageClicked();
	void onVoiceButtonClicked();
	void handleBotResponse(QNetworkReply* reply);
	void handleRecordingFinished(const QString& filePath);
	void showTypingIndicator(bool show);
private:
	Ui::chatbot* ui;
	QNetworkAccessManager m_manager;
	RecordingThread m_recordingThread;
	bool isRecording;
	QLabel* typingIndicator=nullptr;
	void sendUserMessage(const QString& message);
	void sendAudioToChatbot(const QString& audioFilePath);
    void addMessageBubble(const QString& text, bool isUser);
	
};

#endif // CHATBOT_H
