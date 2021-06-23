#include <QCoreApplication>
#include <QDateTime>
#include "message.h"
#include "messagefilter.h"
#include <QtDebug>
#include <string>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QDate date1(2021,6,23);
    QTime time1(23,16);
    QDate date2(2021,6,23);
    QTime time2(13,16);
    QDateTime sendDateTime1(date1,time1);
    QDateTime sendDateTime2(date2,time2);
    Message mes1("text",sendDateTime1,"subject","sender","receiver");
    Message mes2("text2",sendDateTime2,"subject2","sender2","receiver2");
    QVector<Message> messages;
    messages.push_back(mes2);
    messages.push_back(mes1);
    for(int i = 0; i < messages.size(); i++)
    {
        qDebug() << messages[i].getText();
    }
    MessageFilter::filterByTime(messages);
    for(int i = 0; i < messages.size(); i++)
    {
        qDebug() << messages[i].getText();
    }
    //QString val = filteredMessages[0].getText();

    //qDebug() << val;

    return a.exec();
}
