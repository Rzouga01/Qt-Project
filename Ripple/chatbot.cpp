#include "chatbot.h"
#include "ui_chatbot.h"

using namespace Microsoft::CognitiveServices::Speech;
using namespace Microsoft::CognitiveServices::Speech::Audio;

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
void chatbot::moveScrollBarToBottom(int min, int max) {
    Q_UNUSED(min);
    ui->chat->verticalScrollBar()->setValue(max);
}

chatbot::chatbot(QWidget* parent) :
    QDialog(parent),
    ui(new Ui::chatbot),
    m_paStream(nullptr)
{
    ui->setupUi(this);
    connect(ui->sendButton, &QPushButton::clicked, this, &chatbot::onSendMessageClicked);
    connect(ui->voiceButton, &QPushButton::clicked, this, &chatbot::onVoiceButtonClicked);
    ui->chatContainer->setLayout(new QVBoxLayout()); 
    ui->chatContainer->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
    ui->chat->setWidgetResizable(true);
    ui->chat->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);


}

chatbot::~chatbot()
{
    delete ui;
}

void chatbot::addMessageBubble(const QString& text, bool isUser) {
    // Create a new QLabel for the message text
    QLabel* messageLabel = new QLabel(text);

    // Set word wrap for the message label
    messageLabel->setWordWrap(true);

    // Apply styling based on whether the message is from the user or bot
    QString bubbleColor = isUser ? "#A7C34E" : "#E4E6EB";
    QString textColor = "#000000"; // Black text color for both user and bot
    QString bubbleStyle = QString("background-color: %1; color: %2; border-radius: 10px; padding: 10px;").arg(bubbleColor, textColor);
    messageLabel->setStyleSheet(bubbleStyle);

    // Calculate the size hint for the message label based on the text content
    QSize textSize = messageLabel->sizeHint();

    // Set the maximum width of the bubble to 120% of the chat container's width
    int maxWidth = ui->chatContainer->width() * 1.2;
    if (textSize.width() > maxWidth) {
        textSize.setWidth(maxWidth);
        messageLabel->setFixedWidth(maxWidth);
    }

    // Set the size hint for the message label
    messageLabel->setMinimumSize(textSize);

    // Create a container widget for the message label
    QWidget* bubbleContainer = new QWidget();
    QVBoxLayout* bubbleLayout = new QVBoxLayout(bubbleContainer);
    bubbleLayout->setSpacing(10); // Adjust the spacing between bubbles (e.g., 10 pixels)
    bubbleLayout->addWidget(messageLabel);

    bubbleLayout->setAlignment(Qt::AlignTop | Qt::AlignLeft);
    if (isUser) {
        bubbleLayout->setAlignment(Qt::AlignTop | Qt::AlignRight);
    }

    // Add the bubble
    ui->chatContainer->layout()->addWidget(bubbleContainer);
    ui->chatContainer->layout()->update();

    // Scroll to the bottom of the chat
    QScrollBar* scrollbar = ui->chat->verticalScrollBar();
    connect(scrollbar, SIGNAL(rangeChanged(int, int)), this, SLOT(moveScrollBarToBottom(int, int)));
    scrollbar->setValue(scrollbar->maximum());
}

void chatbot::sendUserMessage(const QString& message)
{
    if (message.isEmpty())
        return;
    addMessageBubble(message, true);

    const QString apiKey = QProcessEnvironment::systemEnvironment().value("GEMINI_API");
    if (apiKey.isEmpty()) {
        qWarning() << "API Key environment variable (GEMINI_API) is not set.";
        return;
    }

    QJsonObject requestJson;
    QJsonArray contentsArray;

    QJsonObject content1;
    QJsonArray parts1;
    QJsonObject part1_1;
    part1_1["text"] = QString("You are RippleAssist, a valued assistant in the dynamic world of Ripple Insurance, a smart insurance agency focused on excellence. Your role is pivotal � you're here to lend a helping hand to our dedicated employees. Now, let's talk about our insurance desktop app. It's the backbone of our operations, managing four vital entities: employees, clients, contracts, and accidents. Here's the drill: for verification purposes , When someone reaches out to you, your first task is to inquire about their name and their role within our agency. We've got four main roles here: the General Director (who's also overseeing our employees), the Customer Relationship Director, the Contract Administrator, and the Accident Investigation Administrator. Once you've got that info, it's all about tailoring your assistance to their needs. If they're the General Director, focus on matters related to our dedicated employees. For the Customer Relationship Director, it's all about client interactions. The Contract Administrator? You've got it � handle contract management. And last but not least, for the Accident Investigation Administrator, your expertise will be invaluable in addressing accident-related inquiries. Your support is absolutely crucial in keeping our operations running smoothly. Ready to step up and make a difference, RippleAssist? Let's dive in together");
    parts1.append(part1_1);
    content1["role"] = QString("user");
    content1["parts"] = parts1;
    contentsArray.append(content1);

    QJsonObject content2;
    QJsonArray parts2;
    QJsonObject part2_1;
    part2_1["text"] = QString("Absolutely, I'm RippleAssist and I'm fully prepared to assist the incredible team at Ripple Insurance! Let's ensure everything runs seamlessly. To best support you, may I please know your name and your role within Ripple Insurance? Remember, whether you're the General Director, Customer Relationship Director, Contract Administrator, or Accident Investigation Administrator, I'm here to provide tailored assistance.");
    parts2.append(part2_1);
    content2["role"] = QString("model");
    content2["parts"] = parts2;
    contentsArray.append(content2);

    QJsonObject content3;
    QJsonArray parts3;
    QJsonObject part3_1;
    part3_1["text"] = message;
    parts3.append(part3_1);
    content3["role"] = QString("user");
    content3["parts"] = parts3;
    contentsArray.append(content3);

    requestJson["contents"] = contentsArray;

    QJsonObject generationConfig;
    generationConfig["temperature"] = 1;
    generationConfig["topK"] = 1;
    generationConfig["topP"] = 1;
    generationConfig["maxOutputTokens"] = 2048;
    generationConfig["stopSequences"] = QJsonArray();
    requestJson["generationConfig"] = generationConfig;

    QJsonArray safetySettings;
    QJsonObject safetySetting1;
    safetySetting1["category"] = QString("HARM_CATEGORY_HARASSMENT");
    safetySetting1["threshold"] = QString("BLOCK_MEDIUM_AND_ABOVE");
    safetySettings.append(safetySetting1);

    QJsonObject safetySetting2;
    safetySetting2["category"] = QString("HARM_CATEGORY_HATE_SPEECH");
    safetySetting2["threshold"] = QString("BLOCK_MEDIUM_AND_ABOVE");
    safetySettings.append(safetySetting2);

    QJsonObject safetySetting3;
    safetySetting3["category"] = QString("HARM_CATEGORY_SEXUALLY_EXPLICIT");
    safetySetting3["threshold"] = QString("BLOCK_MEDIUM_AND_ABOVE");
    safetySettings.append(safetySetting3);

    QJsonObject safetySetting4;
    safetySetting4["category"] = QString("HARM_CATEGORY_DANGEROUS_CONTENT");
    safetySetting4["threshold"] = QString("BLOCK_MEDIUM_AND_ABOVE");
    safetySettings.append(safetySetting4);

    requestJson["safetySettings"] = safetySettings;

    QJsonDocument jsonDocument(requestJson);
    QByteArray jsonData = jsonDocument.toJson();

    QNetworkRequest request(QUrl("https://generativelanguage.googleapis.com/v1beta/models/gemini-1.0-pro:generateContent?key=" + apiKey));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    QNetworkAccessManager* manager = new QNetworkAccessManager(this);

    QNetworkReply* reply = manager->post(request, jsonData);

    QObject::connect(reply, &QNetworkReply::finished, [=]() {
        handleBotResponse(reply);
        reply->deleteLater();
        });

    QEventLoop loop;
    QObject::connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
    loop.exec();

    if (reply->error() == QNetworkReply::NoError) {
        QByteArray responseData = reply->readAll();
        QString responseString(responseData);
        qDebug() << "Response: " << responseString;
    }
    else {
        qDebug() << "Error: " << reply->errorString();
    }
}

void chatbot::handleBotResponse(QNetworkReply* reply) {
 
    QString botResponse;
    bool isError = false;

    if (reply->error() == QNetworkReply::NoError) {
        // Retrieve bot's response
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
        isError = true;
    }

    // Add bot response to chat container
    addMessageBubble(isError ? "Error: " + botResponse : botResponse, false);
}

void chatbot::onSendMessageClicked() {
    QString userMessage = ui->messageInput->text().trimmed();

    if (!userMessage.isEmpty()) {
        // Clear the message input field
        ui->messageInput->clear();

        // Set focus back to the message input field
        ui->messageInput->setFocus();

        // Send user message to the chatbot
        sendUserMessage(userMessage);
    }
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

        sendUserMessage(recognizedText);
    }
    else if (result->Reason == ResultReason::NoMatch) {
        // Inform the user that speech could not be recognized
        QLabel* errorLabel = new QLabel("Speech could not be recognized.");
        errorLabel->setWordWrap(true);
        addMessageBubble("Speech could not be recognized.", false);
    }
    else if (result->Reason == ResultReason::Canceled) {
        // Handle cancellation errors
        auto cancellation = CancellationDetails::FromResult(result);
        QString errorMessage = "Error: ";
        errorMessage += QString::number(static_cast<int>(cancellation->Reason));
        addMessageBubble(errorMessage, false);  
    }
}
