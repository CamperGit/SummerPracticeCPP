#include "message.h"

Message::Message()
{

}

Message::Message(QString text, QDateTime sendTime, QString subject, QString senderLogin, QString receiverLogin)
{
    this->text = text;
    this->sendTime = sendTime;
    this->subject = subject;
    this->senderLogin = senderLogin;
    this->receiverLogin = receiverLogin;
}

QString Message::getText()
{
    return text;
}

QDateTime Message::getSendTime()
{
    return sendTime;
}

QString Message::getSubject()
{
    return subject;
}

QString Message::getSenderLogin()
{
    return senderLogin;
}

QString Message::getReceiverLogin()
{
    return receiverLogin;
}

void Message::setText(const QString text)
{
    this->text = text;
}

void Message::setSendTime(const QDateTime time)
{
    this->sendTime = time;
}

void Message::setSubject(const QString subject)
{
    this->subject = subject;
}

void Message::setSenderLogin(const QString senderLogin)
{
    this->senderLogin = senderLogin;
}

void Message::setReceiverLogin(const QString receiverLogin)
{
    this->receiverLogin = receiverLogin;
}




