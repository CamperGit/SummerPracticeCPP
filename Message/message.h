#ifndef MESSAGE_H
#define MESSAGE_H

#include "Message_global.h"
#include <QString>
#include <QDateTime>

class MESSAGE_EXPORT Message
{
private:
    QString text;
    QDateTime sendTime;
    QString subject;
    QString senderLogin;
    QString receiverLogin;
public:
    Message();
    Message(QString text, QDateTime sendTime, QString subject,QString senderLogin,QString receiverLogin);

    QString getText();
    QDateTime getSendTime();
    QString getSubject();
    QString getSenderLogin();
    QString getReceiverLogin();

    void setText(const QString text);
    void setSendTime(const QDateTime time);
    void setSubject(const QString subject);
    void setSenderLogin(const QString senderLogin);
    void setReceiverLogin(const QString receiverLogin);
};

Q_DECLARE_METATYPE( Message )

#endif // MESSAGE_H
