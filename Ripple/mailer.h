#ifndef MAILER_H
#define MAILER_H

#include <QObject>
#include <QTcpSocket>

class Mailer : public QObject
{
    Q_OBJECT
public:
    explicit Mailer(QObject *parent = nullptr);
    ~Mailer();

    void setSmtpServer(const QString &server, int port = 587);
    void setLoginCredentials(const QString &username, const QString &password);
    void setSender(const QString &senderEmail);
    void setRecipient(const QString &recipientEmail);
    void setSubject(const QString &subject);
    void setBody(const QString &body);
    void addAttachment(const QString &filePath);

    bool sendMail();

private:
    QString smtpServer;
    int smtpPort;
    QString username;
    QString password;
    QString senderEmail;
    QString recipientEmail;
    QString subject;
    QString body;
    QStringList attachments;
    QTcpSocket *socket;

    bool connectToSmtpServer();
    QString readResponse();
    bool sendData(const QByteArray &data);

private slots:
    void onReadyRead();
    void onDisconnected();
};

#endif // MAILER_H
