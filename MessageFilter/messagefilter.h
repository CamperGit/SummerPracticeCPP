#ifndef MESSAGEFILTER_H
#define MESSAGEFILTER_H

#include "MessageFilter_global.h"
#include "message.h"
#include <QVector>
#include <QDateTime>

class MESSAGEFILTER_EXPORT MessageFilter
{
public:
    static QVector<Message> getMessagesSentBeforeSelectedTime(QVector<Message> messages, QDateTime timeBefore);
    static QVector<Message> filterByTime(QVector<Message> messages, QDateTime date);
};

#endif // MESSAGEFILTER_H
