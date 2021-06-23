#include "messagefilter.h"

/*
* @param QVector<Message> messages - messages to filter
* @param QDateTime timeBefore - time for filter
* @return - filtered message list
*/
QVector<Message> MessageFilter::getMessagesSentBeforeSelectedTime(QVector<Message> messages, QDateTime timeBefore)
{
    QVector<Message> filteredMessages;
    for (int i = 0 ; i < messages.size();i++)
    {
        if (messages[i].getSendTime().currentSecsSinceEpoch() <= timeBefore.currentSecsSinceEpoch())
        {
            filteredMessages.push_back(messages[i]);
        }
    }
    return filteredMessages;
}

QVector<Message> MessageFilter::filterByTime(QVector<Message> messages, QDateTime date)
{

}
