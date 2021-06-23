#include "messagefilter.h"
#include <QString>
/*
* Filters sent messages by sending time from small to big.
* @param QVector<Message> messages - messages to filter
*/

void MessageFilter::filterByTimeSmallToBig(QVector<Message> &messages)
{
    for (int i = 0; i < messages.size() - 1; i++)
    {
        for (int j = 0; j < messages.size() - i - 1; j++)
        {        
            if (messages[j].getSendTime() >= messages[j + 1].getSendTime())
            {
                Message temp = messages[j];
                messages[j] = messages[j + 1];
                messages[j + 1] = temp;
            }
        }
    }
}

/*
* Filters sent messages by alphabet from small to big.
* @param QVector<Message> messages - messages to filter
*/

void MessageFilter::filterByAlphabetSmallToBig(QVector<Message> &messages)
{
    for(int i=0; i< messages.size() - 1; i++)
    {
        for(int j=0; j < messages.size()-i-1; j++)
        {
            if(QString::compare(messages[j].getSubject(),messages[j+1].getSubject(),Qt::CaseInsensitive)>0)
            {
            Message tempSubject = messages[j];
            messages[j] = messages[j+1];
            messages[j+1] = tempSubject;
            }
        }
    }
}

/*
* Filters sent messages by sending time from big to small.
* @param QVector<Message> messages - messages to filter
*/

void MessageFilter::filterByTimeBigToSmall(QVector<Message> &messages)
{
    for (int i = 0; i < messages.size() - 1; i++)
    {
        for (int j = 0; j < messages.size() - i - 1; j++)
        {
            if (messages[j].getSendTime() <= messages[j + 1].getSendTime())
            {
                Message temp = messages[j];
                messages[j] = messages[j + 1];
                messages[j + 1] = temp;
            }
        }
    }
}

/*
* Filters sent messages by alphabet from big to small.
* @param QVector<Message> messages - messages to filter
*/

void MessageFilter::filterByAlphabetBigToSmall(QVector<Message> &messages)
{
    for(int i=0; i< messages.size() - 1; i++)
    {
        for(int j=0; j < messages.size()-i-1; j++)
        {
            if(QString::compare(messages[j].getSubject(),messages[j+1].getSubject(),Qt::CaseInsensitive)<0)
            {
            Message tempSubject = messages[j];
            messages[j] = messages[j+1];
            messages[j+1] = tempSubject;
            }
        }
    }
}
