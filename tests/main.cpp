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
    QDate date1(2021,7,23);
    QTime time1(13,16);
    QDateTime sendDateTime(date,time);
    QDateTime sendDateTime1(date1,time1);
    Message mes1("text",sendDateTime,"subject","sender","receiver");
    Message mes2("text2",sendDateTime1,"subject2","sender2","receiver2");
    QVector<Message> messages;
    messages.push_back(mes1);
    messages.push_back(mes2);
    for(int i = 0; i < messages.size()-1; i++)
    {
        qDebug() << messages[i].getText();
    }
    MessageFilter::filterByTime(messages);
    for(int i = 0; i < messages.size()-1; i++)
    {
        qDebug() << messages[i].getText();
    }
    //QString val = filteredMessages[0].getText();

    //qDebug() << val;

    return a.exec();
}
