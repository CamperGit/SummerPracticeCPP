#include <QCoreApplication>
#include <QDateTime>
#include "message.h"
#include "messagefilter.h"
#include <QtDebug>
#include <string>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QDate date(2021,6,23);
    QTime time(13,16);
    QDateTime sendDateTime(date,time);
    Message mes1("text",sendDateTime,"subject","sender","receiver");
    Message mes2("text2",sendDateTime,"subject2","sender2","receiver2");
    QVector<Message> messages;
    messages.push_back(mes1);
    messages.push_back(mes2);
    QVector<Message> filteredMessages = MessageFilter::getMessagesSentBeforeSelectedTime(messages,sendDateTime);
    QString val = filteredMessages[0].getText();

    qDebug() << val;

    return a.exec();
}
