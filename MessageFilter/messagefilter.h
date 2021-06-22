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
};

#endif // MESSAGEFILTER_H
