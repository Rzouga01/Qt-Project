#ifndef SMS_H
#define SMS_H

#include <QObject>
#include <QDebug>
#include <QtNetwork/QNetworkReply>

class SMS : public QObject
{
    Q_OBJECT
public:
    explicit SMS(QString sid, QString token, QString from);

signals:
    void finished();

public slots:
    void sendSms(QString to, QString message);
    void responseReceived(QNetworkReply* reply);

private:
    QString sid;
    QString token;
    QString from;
};

#endif // SMS_H
