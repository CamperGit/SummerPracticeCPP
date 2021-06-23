#include "messagefilter.h"

void MessageFilter::filterByTime(QVector<Message>& messages)
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
