#include "chatbot.h"
#include "ui_chatbot.h"

chatbot::chatbot(QWidget* parent) :
	QDialog(parent),
	ui(new Ui::chatbot)
{
	ui->setupUi(this);
	connect(ui->sendButton, &QPushButton::clicked, this, &chatbot::onSendMessageClicked);
	loadingMovie = new QMovie("../Resources/Gifs/chatloading.gif", QByteArray(), this);

}

chatbot::~chatbot()
{
	delete ui;
}

void chatbot::sendUserMessage(const QString& message)
{
	if (message.isEmpty())
		return;

	// Create a label to measure the size of the text
	QLabel label;
	label.setWordWrap(true);
	label.setText(message);
	QSize size = label.sizeHint();

	// Append user input to conversation with appropriate styling
	QListWidgetItem* userItem = new QListWidgetItem(message);
	userItem->setTextAlignment(Qt::AlignRight);
	userItem->setSizeHint(size); // Set dynamic size based on text content
	ui->chat->addItem(userItem);

	// Display a loading message immediately after sending
	QListWidgetItem* loadingItem = new QListWidgetItem;
	loadingItem->setSizeHint(QSize(0, 50)); // Adjust size if needed
	ui->chat->addItem(loadingItem);
	ui->chat->setItemWidget(loadingItem, createLoadingWidget());

	ui->chat->scrollToBottom();

	// Prepare API request
	QNetworkAccessManager* manager = new QNetworkAccessManager(this);
	const QString apiKey = QProcessEnvironment::systemEnvironment().value("GEMINI_API");

	if (apiKey.isEmpty()) {
		qWarning() << "Password environment variable (GEMINI_API) is not set.";
		return;
	}
	QUrl url("https://generativelanguage.googleapis.com/v1beta/models/gemini-pro:generateContent?key=" + apiKey);
	QNetworkRequest request(url);
	request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

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

	// Send API request
	QNetworkReply* reply = manager->post(request, postData);
	connect(reply, &QNetworkReply::finished, [=]() {
		handleBotResponse(reply);
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
	}

	// Remove the loading message
	QListWidgetItem* loadingItem = ui->chat->item(ui->chat->count() - 1);
	delete loadingItem;

	// Create a label to measure the size of the text
	QLabel label;
	label.setWordWrap(true);
	label.setText(botResponse);
	QSize size = label.sizeHint();

	// Display the bot's actual response with appropriate styling
	QListWidgetItem* botItem = new QListWidgetItem(botResponse);
	botItem->setTextAlignment(Qt::AlignLeft);
	botItem->setSizeHint(size); // Set dynamic size based on text content
	ui->chat->addItem(botItem);

	ui->chat->scrollToBottom();
}

QWidget* chatbot::createLoadingWidget()
{
	QWidget* loadingWidget = new QWidget;
	QLabel* loadingLabel = new QLabel;
	loadingLabel->setMovie(loadingMovie);
	loadingMovie->start();

	QHBoxLayout* layout = new QHBoxLayout(loadingWidget);
	layout->addWidget(loadingLabel, 0, Qt::AlignCenter);
	loadingWidget->setLayout(layout);

	return loadingWidget;
}

void chatbot::onSendMessageClicked()
{
	QString userMessage = ui->messageBar->text();
	sendUserMessage(userMessage);
	ui->messageBar->clear();
	ui->messageBar->setFocus();
}
