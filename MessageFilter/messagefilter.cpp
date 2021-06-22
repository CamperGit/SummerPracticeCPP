#include "messagefilter.h"

QVector<Message> MessageFilter::getMessagesSentBeforeSelectedTime(QVector<Message> messages, QDateTime timeBefore)
{
    QVector<Message> filteredMessages;
    for (int i = 0 ; i < messages.size();i++)
    {
        if (messages[i].getSendTime().currentSecsSinceEpoch() < timeBefore.currentSecsSinceEpoch())
        {
            filteredMessages.push_back(messages[i]);
        }
    }
    return filteredMessages;
}
