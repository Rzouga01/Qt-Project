#include "mailer.h"
#include <QTextStream>
#include <QDebug>

Mailer::Mailer(QObject *parent) : QObject(parent), smtpPort(587), socket(new QTcpSocket(this))
{
    connect(socket, &QTcpSocket::readyRead, this, &Mailer::onReadyRead);
    connect(socket, &QTcpSocket::disconnected, this, &Mailer::onDisconnected);
}

Mailer::~Mailer()
{
    if (socket->isOpen())
        socket->close();
}

void Mailer::setSmtpServer(const QString &server, int port)
{
    smtpServer = server;
    smtpPort = port;
}

void Mailer::setLoginCredentials(const QString &username, const QString &password)
{
    this->username = username;
    this->password = password;
}

void Mailer::setSender(const QString &senderEmail)
{
    this->senderEmail = senderEmail;
}

void Mailer::setRecipient(const QString &recipientEmail)
{
    this->recipientEmail = recipientEmail;
}

void Mailer::setSubject(const QString &subject)
{
    this->subject = subject;
}

void Mailer::setBody(const QString &body)
{
    this->body = body;
}

void Mailer::addAttachment(const QString &filePath)
{
    attachments.append(filePath);
}

bool Mailer::sendMail()
{
    if (!connectToSmtpServer()) {
        qDebug() << "Failed to connect to SMTP server.";
        return false;
    }

    QTextStream stream(socket);

    // Send email data
    stream << "HELO " << smtpServer << "\r\n";
    stream << "AUTH LOGIN\r\n";
    stream << username.toUtf8().toBase64() << "\r\n";
    stream << password.toUtf8().toBase64() << "\r\n";
    stream << "MAIL FROM:<" << senderEmail << ">\r\n";
    stream << "RCPT TO:<" << recipientEmail << ">\r\n";
    stream << "DATA\r\n";
    stream << "Subject:" << subject << "\r\n";
    stream << "From:" << senderEmail << ">\r\n";
    stream << "To:" << recipientEmail << "\r\n";
    stream << "\r\n";
    stream << body << "\r\n";
    stream << ".\r\n";
    stream << "QUIT\r\n";

    if (!readResponse().startsWith("250")) {
        qDebug() << "Failed to send email.";
        return false;
    }

    return true;
}

bool Mailer::connectToSmtpServer()
{
    socket->connectToHost(smtpServer, smtpPort);
    if (!socket->waitForConnected()) {
        qDebug() << "Failed to connect to SMTP server.";
        return false;
    }
    return true;
}

QString Mailer::readResponse()
{
    if (!socket->waitForReadyRead()) {
        qDebug() << "Failed to read response from SMTP server.";
        return "";
    }
    return QString::fromUtf8(socket->readAll());
}

bool Mailer::sendData(const QByteArray &data)
{
    socket->write(data);
    if (!socket->waitForBytesWritten()) {
        qDebug() << "Failed to write data to SMTP server.";
        return false;
    }
    return true;
}

void Mailer::onReadyRead()
{
    qDebug() << "Ready Read Signal Received";
}

void Mailer::onDisconnected()
{
    qDebug() << "Disconnected Signal Received";
}
