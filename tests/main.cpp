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
    QTime time1(23,16);
    QTime time2(13,15);
    QTime time3(12,13);
    QTime time4(18,12);
    QDateTime sendDateTime1(date,time1);
    QDateTime sendDateTime2(date,time2);
    QDateTime sendDateTime3(date,time3);
    QDateTime sendDateTime4(date,time4);
    Message mes1("1",sendDateTime1,"subject","sender","receiver");
    Message mes2("2",sendDateTime2,"subject2","sender2","receiver2");
    Message mes3("3",sendDateTime3,"subject3","sender3","receiver3"); // 2 1 3 4
    Message mes4("4",sendDateTime4,"subject4","sender4","receiver4"); //3 2 4 1
    QVector<Message> messages;
    messages.push_back(mes2);
    messages.push_back(mes1);
    messages.push_back(mes3);
    messages.push_back(mes4);
    for(int i = 0; i < messages.size(); i++)
    {
        qDebug() << messages[i].getText();
    }
    qDebug() << "\n\n";
    MessageFilter::filterByTime(messages);
    for(int i = 0; i < messages.size(); i++)
    {
        qDebug() << messages[i].getText();
    }

    return a.exec();
}
