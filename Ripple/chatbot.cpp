#include "chatbot.h"
#include "ui_chatbot.h"

using namespace Microsoft::CognitiveServices::Speech;
using namespace Microsoft::CognitiveServices::Speech::Audio;

#define SAMPLE_RATE  (44100)
#define FRAMES_PER_BUFFER (512)
#define NUM_SECONDS     (5)
#define NUM_CHANNELS    (2)
#define DITHER_FLAG     (0)
#define WRITE_TO_FILE   (1) // Set to 1 to enable writing to file
#define FILE_NAME ".wav" 

// Define sample type
#define PA_SAMPLE_TYPE  paFloat32
typedef float SAMPLE;

// Define sample silence and print format
#define SAMPLE_SILENCE  (0.0f)
#define PRINTF_S_FORMAT "%.8f"


// PortAudio callback function for recording
static int recordCallback(const void* inputBuffer, void* outputBuffer,
    unsigned long framesPerBuffer,
    const PaStreamCallbackTimeInfo* timeInfo,
    PaStreamCallbackFlags statusFlags,
    void* userData)
{
    paTestData* data = (paTestData*)userData;
    const SAMPLE* rptr = (const SAMPLE*)inputBuffer;
    SAMPLE* wptr = &data->recordedSamples[data->frameIndex * NUM_CHANNELS];
    long framesToCalc;
    long i;
    int finished;
    unsigned long framesLeft = data->maxFrameIndex - data->frameIndex;

    // Check if recording is complete
    if (framesLeft < framesPerBuffer)
    {
        framesToCalc = framesLeft;
        finished = paComplete;
    }
    else
    {
        framesToCalc = framesPerBuffer;
        finished = paContinue;
    }

    // Copy input buffer to recorded samples
    if (inputBuffer == NULL)
    {
        for (i = 0; i < framesToCalc; i++)
        {
            *wptr++ = SAMPLE_SILENCE;
            if (NUM_CHANNELS == 2)
                *wptr++ = SAMPLE_SILENCE;
        }
    }
    else
    {
        for (i = 0; i < framesToCalc; i++)
        {
            *wptr++ = *rptr++;
            if (NUM_CHANNELS == 2)
                *wptr++ = *rptr++;
        }
    }
    data->frameIndex += framesToCalc;
    return finished;
}

chatbot::chatbot(QWidget* parent) :
    QDialog(parent),
    ui(new Ui::chatbot),
    m_paStream(nullptr)
{
    ui->setupUi(this);
    connect(ui->sendButton, &QPushButton::clicked, this, &chatbot::onSendMessageClicked);
    connect(ui->voiceButton, &QPushButton::clicked, this, &chatbot::onVoiceButtonClicked);
}

chatbot::~chatbot()
{
    delete ui;
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
    // Start recording voice
    recordVoice();
}

void chatbot::recordVoice()
{
    PaError err;
    SNDFILE* outfile;
    SF_INFO sfinfo;
    paTestData data;
    data.maxFrameIndex = NUM_SECONDS * SAMPLE_RATE;
    data.frameIndex = 0;
    int numSamples = data.maxFrameIndex * NUM_CHANNELS;
    data.recordedSamples = new SAMPLE[numSamples];

    err = Pa_Initialize();
    if (err != paNoError) {
        QMessageBox::critical(this, "Error", QString("Failed to initialize PortAudio: %1").arg(Pa_GetErrorText(err)));
        return;
    }

    PaStreamParameters inputParameters;
    inputParameters.device = Pa_GetDefaultInputDevice();
    if (inputParameters.device == paNoDevice) {
        QMessageBox::critical(this, "Error", "Error: No default input device.");
        Pa_Terminate();
        return;
    }
    inputParameters.channelCount = NUM_CHANNELS;
    inputParameters.sampleFormat = PA_SAMPLE_TYPE;
    inputParameters.suggestedLatency = Pa_GetDeviceInfo(inputParameters.device)->defaultLowInputLatency;
    inputParameters.hostApiSpecificStreamInfo = nullptr;

    err = Pa_OpenStream(&m_paStream, &inputParameters, nullptr, SAMPLE_RATE, FRAMES_PER_BUFFER, paClipOff, recordCallback, &data);
    if (err != paNoError) {
        QMessageBox::critical(this, "Error", QString("Failed to open PortAudio stream: %1").arg(Pa_GetErrorText(err)));
        Pa_Terminate();
        return;
    }

    err = Pa_StartStream(m_paStream);
    if (err != paNoError) {
        QMessageBox::critical(this, "Error", QString("Failed to start PortAudio stream: %1").arg(Pa_GetErrorText(err)));
        Pa_CloseStream(m_paStream);
        Pa_Terminate();
        return;
    }

    std::cout << "\n=== Now recording!! Please speak into the microphone. ===" << std::endl;

    // Wait until recording is complete
    while ((err = Pa_IsStreamActive(m_paStream)) == 1)
    {
        Pa_Sleep(1000);
        std::cout << "index = " << data.frameIndex << std::endl;
    }
    if (err < 0) {
        QMessageBox::critical(this, "Error", QString("Error during recording: %1").arg(Pa_GetErrorText(err)));
        Pa_CloseStream(m_paStream);
        Pa_Terminate();
        return;
    }

    err = Pa_StopStream(m_paStream);
    if (err != paNoError) {
        QMessageBox::critical(this, "Error", QString("Failed to stop PortAudio stream: %1").arg(Pa_GetErrorText(err)));
    }

    err = Pa_CloseStream(m_paStream);
    if (err != paNoError) {
        QMessageBox::critical(this, "Error", QString("Failed to close PortAudio stream: %1").arg(Pa_GetErrorText(err)));
    }

    err = Pa_Terminate();
    if (err != paNoError) {
        QMessageBox::critical(this, "Error", QString("Failed to terminate PortAudio: %1").arg(Pa_GetErrorText(err)));
    }

    // Initialize libsndfile info structure
    sfinfo.channels = NUM_CHANNELS;
    sfinfo.samplerate = SAMPLE_RATE;
    sfinfo.format = SF_FORMAT_WAV | SF_FORMAT_FLOAT; // Use SF_FORMAT_FLOAT for floating-point samples

    // Open WAV file for writing
    outfile = sf_open(FILE_NAME, SFM_WRITE, &sfinfo);
    if (!outfile) {
        QMessageBox::critical(this, "Error", "Error opening output file.");
        return;
    }

    // Write recorded data to WAV file
    sf_writef_float(outfile, data.recordedSamples, data.maxFrameIndex);

    // Close WAV file
    sf_close(outfile);
    std::cout << "Wrote data to '" << FILE_NAME << "'" << std::endl;
    sendAudioToChatbot(QString(FILE_NAME));
    delete[] data.recordedSamples;
}

void chatbot::sendAudioToChatbot(const QString& audioFilePath)  
{
    // Retrieve Azure Speech subscription key and region from environment variables
    const QString speechKey = QProcessEnvironment::systemEnvironment().value("SPEECH_KEY");
    const QString speechRegion = QProcessEnvironment::systemEnvironment().value("SPEECH_REGION");

    if (speechKey.isEmpty() || speechRegion.isEmpty()) {
        QMessageBox::critical(this, "Error", "Please set both SPEECH_KEY and SPEECH_REGION environment variables.");
        return;
    }

    // Initialize Speech SDK
    auto speechConfig = SpeechConfig::FromSubscription(speechKey.toStdString(), speechRegion.toStdString());
    speechConfig->SetSpeechRecognitionLanguage("en-US");

    // Check if the audio file exists
    QFile audioFile(audioFilePath);
    if (!audioFile.exists()) {
        QMessageBox::critical(this, "Error", QString("Audio file does not exist: %1").arg(audioFilePath));
        return;
    }

    // Create audio configuration from the audio file
    auto audioConfig = AudioConfig::FromWavFileInput(audioFilePath.toStdString());

    // Create speech recognizer
    auto speechRecognizer = SpeechRecognizer::FromConfig(speechConfig, audioConfig);

    // Recognize speech from the audio file
    auto result = speechRecognizer->RecognizeOnceAsync().get();

    // Process recognition result
    if (result->Reason == ResultReason::RecognizedSpeech) {
        QString recognizedText = QString::fromStdString(result->Text);
        ui->chat->append("<div class=\"user-message\">You (Voice): " + recognizedText + "</div><br></br>");
        sendUserMessage(recognizedText);
      
       
    }
    else if (result->Reason == ResultReason::NoMatch) {
        ui->chat->append("<div class=\"bot-response\">Bot: Speech could not be recognized.</div><br></br>");
    }
    else if (result->Reason == ResultReason::Canceled) {
        auto cancellation = CancellationDetails::FromResult(result);
        QString errorMessage = "Error: ";
        errorMessage += QString::number(static_cast<int>(cancellation->Reason));
        ui->chat->append("<div class=\"bot-response\">" + errorMessage + "</div><br></br>");
    }
}
