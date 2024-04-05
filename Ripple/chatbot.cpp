#include "chatbot.h"
#include "ui_chatbot.h"
#include <QFile>
#include <QTextStream>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QNetworkAccessManager>
#include <QTemporaryFile>
#include <QProcessEnvironment>
using namespace Microsoft::CognitiveServices::Speech;
using namespace Microsoft::CognitiveServices::Speech::Audio;
chatbot::chatbot(QWidget* parent) :
    QDialog(parent),
    ui(new Ui::chatbot),    
    m_paStream(nullptr),
    m_recordedBuffer(),
    m_recordedFrames(0)
{
    ui->setupUi(this);
    connect(ui->sendButton, &QPushButton::clicked, this, &chatbot::onSendMessageClicked);
    connect(ui->voiceButton, &QPushButton::clicked, this, &chatbot::onVoiceButtonClicked);

    // Set word wrap mode
    ui->chat->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    ui->chat->setWordWrapMode(QTextOption::WrapAtWordBoundaryOrAnywhere);

    PaError err = Pa_Initialize();
    if (err != paNoError) {
        qWarning() << "Error initializing PortAudio:" << Pa_GetErrorText(err);
    }

    // Load CSS style
    QFile styleFile(":/Resources/Css/chat.css");
    if (styleFile.open(QFile::ReadOnly | QFile::Text)) {
        QTextStream stream(&styleFile);
        QString cssStyle = stream.readAll();
        styleFile.close();
        ui->chat->document()->setDefaultStyleSheet(cssStyle);
    }
    else {
        qDebug() << "Failed to open style file";
    }
}

chatbot::~chatbot()
{
    delete ui;
    if (m_paStream) {
        Pa_StopStream(m_paStream);
        Pa_CloseStream(m_paStream);
        m_paStream = nullptr;
    }
    Pa_Terminate();
}

void chatbot::sendUserMessage(const QString& message)
{
    if (message.isEmpty())
        return;

    // Display loading animation
    LoadingWidget* loadingWidget = new LoadingWidget(this);
    loadingWidget->move(geometry().center() - loadingWidget->rect().center());
    loadingWidget->show();

    // Create network manager
    QNetworkAccessManager* manager = new QNetworkAccessManager(this);
    const QString apiKey = QProcessEnvironment::systemEnvironment().value("GEMINI_API");

    if (apiKey.isEmpty()) {
        qWarning() << "Password environment variable (GEMINI_API) is not set.";
        return;
    }

    // Prepare request
    QUrl url("https://generativelanguage.googleapis.com/v1beta/models/gemini-pro:generateContent?key=" + apiKey);
    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    // Prepare request body
    QJsonObject requestBody;
    QJsonArray contentsArray;

    QJsonObject userPart;
    userPart["role"] = "user";
    QJsonArray userPartsArray;
    userPartsArray.append(QJsonObject{ {"text", message} });
    userPart["parts"] = userPartsArray;
    contentsArray.append(userPart);

    requestBody["contents"] = contentsArray;

    QJsonDocument doc(requestBody);
    QByteArray postData = doc.toJson();

    // Send request
    QNetworkReply* reply = manager->post(request, postData);
    connect(reply, &QNetworkReply::finished, [=]() {
        handleBotResponse(reply);
        loadingWidget->close();
        reply->deleteLater();
        });
}

void chatbot::handleBotResponse(QNetworkReply* reply)
{
    QString botResponse;
    if (reply->error() == QNetworkReply::NoError) {
        QByteArray responseData = reply->readAll();
        QJsonDocument responseDoc = QJsonDocument::fromJson(responseData);
        QJsonObject responseObj = responseDoc.object();
        if (responseObj.contains("candidates") && responseObj["candidates"].isArray()) {
            QJsonArray candidatesArray = responseObj["candidates"].toArray();
            if (!candidatesArray.isEmpty()) {
                QJsonObject contentObj = candidatesArray.first().toObject()["content"].toObject();
                if (contentObj.contains("parts") && contentObj["parts"].isArray()) {
                    QJsonArray partsArray = contentObj["parts"].toArray();
                    if (!partsArray.isEmpty()) {
                        botResponse = partsArray.first().toObject()["text"].toString();
                    }
                }
            }
        }
    }
    else {
        qDebug() << "Error:" << reply->errorString();
        botResponse = "Sorry, an error occurred while processing your request.";
    }

    // Append bot's response with formatting
    ui->chat->append("<div><b>Bot:</b> " + botResponse + "</div>");

    // Scroll to the bottom
    ui->chat->verticalScrollBar()->setValue(ui->chat->verticalScrollBar()->maximum());
}

void chatbot::onSendMessageClicked()
{
    QString userMessage = ui->messageBar->text().trimmed();

    if (userMessage.isEmpty())
        return;

    // Append user's message with formatting
    ui->chat->append("<div align=\"right\"><b>You:</b> " + userMessage + "</div>");

    // Send user's message
    sendUserMessage(userMessage);

    // Clear input field
    ui->messageBar->clear();

    // Set focus back to input field
    ui->messageBar->setFocus();

    // Scroll to the bottom
    ui->chat->verticalScrollBar()->setValue(ui->chat->verticalScrollBar()->maximum());
}

void chatbot::onVoiceButtonClicked()
{
    // Choose audio file using QFileDialog
    QString audioFilePath = QFileDialog::getOpenFileName(this, "Choose Audio File", "", "Audio Files (*.wav)");

    // Check if a file was selected
    if (!audioFilePath.isEmpty()) {
        // Send the selected audio file to the chatbot for recognition
        sendAudioToChatbot(audioFilePath);
    }
}

int chatbot::recordCallback(const void* inputBuffer, void* /*outputBuffer*/,
    unsigned long framesPerBuffer,
    const PaStreamCallbackTimeInfo* /*timeInfo*/,
    PaStreamCallbackFlags /*statusFlags*/,
    void* userData)
{/*
    chatbot* chatbotInstance = static_cast<chatbot*>(userData);
    if (inputBuffer != nullptr) {
        // Convert the input buffer data to float
        const float* input = static_cast<const float*>(inputBuffer);

        // Calculate the total number of samples
        int numSamples = framesPerBuffer * NUM_CHANNELS;

        // Convert the float buffer to QByteArray
        QByteArray byteArray(reinterpret_cast<const char*>(input), numSamples * sizeof(float));

        // Append the QByteArray to the recorded buffer
        chatbotInstance->m_recordedBuffer.append(byteArray);

        // Increment the recorded frames count
        chatbotInstance->m_recordedFrames += framesPerBuffer;
    }
    return paContinue;
    */
    return 0;
}

void chatbot::startRecording()
{/*
    PaStreamParameters inputParameters;
    inputParameters.device = Pa_GetDefaultInputDevice();
    if (inputParameters.device == paNoDevice) {
        qWarning() << "Error: No default input device.";
        return;
    }
    inputParameters.channelCount = NUM_CHANNELS;
    inputParameters.sampleFormat = PA_SAMPLE_TYPE;
    inputParameters.suggestedLatency = Pa_GetDeviceInfo(inputParameters.device)->defaultLowInputLatency;
    inputParameters.hostApiSpecificStreamInfo = nullptr;

    // Open the stream for recording
    PaError err = Pa_OpenStream(&m_paStream, &inputParameters, nullptr, SAMPLE_RATE,
        FRAMES_PER_BUFFER, paClipOff, recordCallback, this);
    if (err != paNoError) {
        qWarning() << "Error opening PortAudio stream:" << Pa_GetErrorText(err);
        return;
    }

    // Start recording
    err = Pa_StartStream(m_paStream);
    if (err != paNoError) {
        qWarning() << "Error starting PortAudio stream:" << Pa_GetErrorText(err);
        Pa_CloseStream(m_paStream);
        m_paStream = nullptr;
        return;
    }
    */
}

void chatbot::stopRecording()
{/*
    if (m_paStream) {
        // Stop the PortAudio stream
        PaError err = Pa_StopStream(m_paStream);
        if (err != paNoError) {
            qWarning() << "Error stopping PortAudio stream:" << Pa_GetErrorText(err);
        }

        // Close the PortAudio stream
        err = Pa_CloseStream(m_paStream);
        if (err != paNoError) {
            qWarning() << "Error closing PortAudio stream:" << Pa_GetErrorText(err);
        }

        m_paStream = nullptr;

        // Send the recorded audio to the chatbot for recognition
        sendRecordedAudio();
    }
    else {
        qWarning() << "PortAudio stream is not initialized.";
    }
    */
}

void chatbot::sendRecordedAudio()
{/*
    // Create a temporary file to store the recorded audio
    QTemporaryFile tempFile;
    if (!tempFile.open()) {
        qWarning() << "Failed to create temporary file:" << tempFile.errorString();
        return;
    }

    // Write the recorded audio to the temporary file
    QFile audioFile(tempFile.fileName());
    if (!audioFile.open(QIODevice::WriteOnly)) {
        qWarning() << "Failed to open temporary file for writing:" << audioFile.errorString();
        return;
    }

    // Calculate the total number of bytes in the recorded buffer
    qint64 totalBytes = m_recordedBuffer.size();

    // Write the recorded audio data to the temporary file
    qint64 bytesWritten = audioFile.write(m_recordedBuffer);

    // Check if all bytes were written
    if (bytesWritten != totalBytes) {
        qWarning() << "Error writing to temporary file:" << audioFile.errorString();
        return;
    }

    // Close the temporary file
    audioFile.close();

    // Send the recorded audio to the chatbot for recognition
    sendAudioToChatbot(tempFile.fileName());
    */
}


void chatbot::sendAudioToChatbot(const QString& audioFilePath)
{
    // Retrieve Azure Speech subscription key and region from environment variables
    const QString speechKey = QProcessEnvironment::systemEnvironment().value("SPEECH_KEY");
    const QString speechRegion = QProcessEnvironment::systemEnvironment().value("SPEECH_REGION");

    if (speechKey.isEmpty() || speechRegion.isEmpty()) {
        qWarning() << "Please set both SPEECH_KEY and SPEECH_REGION environment variables.";
        return;
    }

    // Initialize Speech SDK
    auto speechConfig = SpeechConfig::FromSubscription(speechKey.toStdString(), speechRegion.toStdString());
    speechConfig->SetSpeechRecognitionLanguage("en-US");

    // Check if the audio file exists
    QFile audioFile(audioFilePath);
    if (!audioFile.exists()) {
        qWarning() << "Audio file does not exist:" << audioFilePath;
        return;
    }

    // Create audio configuration from the audio file
    auto audioConfig = AudioConfig::FromWavFileInput(audioFilePath.toStdString());

    // Create speech recognizer
    auto speechRecognizer = SpeechRecognizer::FromConfig(speechConfig, audioConfig);

    // Recognize speech from the audio file
    auto result = speechRecognizer->RecognizeOnceAsync().get();

    // Process recognition result
    if (result->Reason == ResultReason::RecognizedSpeech)
    {
        QString recognizedText = QString::fromStdString(result->Text);
        // Assuming ui->chat->append appends text to a chat interface
        ui->chat->append("<div class=\"user-message\">You (Voice): " + recognizedText + "</div><br></br>");
        // Assuming sendUserMessage sends the recognized text to your chatbot
        sendUserMessage(recognizedText);
    }
    else if (result->Reason == ResultReason::NoMatch)
    {
        ui->chat->append("<div class=\"bot-response\">Bot: Speech could not be recognized.</div><br></br>");
    }
    else if (result->Reason == ResultReason::Canceled)
    {
        auto cancellation = CancellationDetails::FromResult(result);
        QString errorMessage = "Error: ";
        errorMessage += QString::number(static_cast<int>(cancellation->Reason));
        ui->chat->append("<div class=\"bot-response\">" + errorMessage + "</div><br></br>");
    }
}
