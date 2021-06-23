#include "messagefilter.h"

QVector<Message> MessageFilter::filterByDateAndTime(QVector<Message> messages)
{
    QVector<Message> filteredMessages;
    for (int i = 0 ; i < messages.size();i++)
    {
        if (messages[i].getSendTime().currentSecsSinceEpoch() < messages[i+1].getSendTime().currentSecsSinceEpoch())
        {
            filteredMessages.push_back(messages[i]);
        }
    }
    return filteredMessages;
}
