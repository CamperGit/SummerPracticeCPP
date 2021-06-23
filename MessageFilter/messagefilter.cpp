#include "messagefilter.h"

void MessageFilter::filterByTime(QVector<Message>& messages)
{
    for (int i = 0 ; i < messages.size();i++)
    {
        for (int j = 0; j < messages.size()-1; j++)
          {
            if (messages[j].getSendTime().currentSecsSinceEpoch() > messages[j-1].getSendTime().currentSecsSinceEpoch())
            {
              Message extraVarialbeToSave = messages[j]; // создали дополнительную переменную
              messages[j] = messages[j+1]; // меняем местами
              messages[j] = extraVarialbeToSave; // значения элементов
            }
        }
    }


}
