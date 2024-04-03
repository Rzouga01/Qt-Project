// chatbot.cpp
#include "chatbot.h"
#include "ui_chatbot.h"
#include <QMessageBox> 

chatbot::chatbot(QWidget* parent) :
    QDialog(parent),
    ui(new Ui::chatbot),
    m_audioInput(nullptr)
{
    ui->setupUi(this);
    connect(ui->sendButton, &QPushButton::clicked, this, &chatbot::onSendMessageClicked);

    // Set word wrap mode
    ui->chat->setWordWrapMode(QTextOption::WrapAtWordBoundaryOrAnywhere);

    // Load CSS style
    QFile styleFile("../Resources/Css/chat.css");
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
    ui->chat->append("<div class=\"bot-response\">Bot: " + botResponse + "</div><br></br>");

    // Scroll to the bottom
    ui->chat->verticalScrollBar()->setValue(ui->chat->verticalScrollBar()->maximum());
}

void chatbot::onSendMessageClicked()
{
    QString userMessage = ui->messageBar->text().trimmed();

    if (userMessage.isEmpty())
        return;

    // Append user's message with formatting
    ui->chat->append("<div class=\"user-message\">You: " + userMessage + "</div><br></br>");
    // Send user's message
    sendUserMessage(userMessage);

    // Clear input field
    ui->messageBar->clear();

    // Set focus back to input field
    ui->messageBar->setFocus();

    // Scroll to the bottom
    ui->chat->verticalScrollBar()->setValue(ui->chat->verticalScrollBar()->maximum());
}
