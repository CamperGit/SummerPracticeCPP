#ifndef MESSAGEFILTER_H
#define MESSAGEFILTER_H

#include "MessageFilter_global.h"
#include "message.h"
#include <QVector>
#include <QDateTime>

class MESSAGEFILTER_EXPORT MessageFilter
{
public:
<<<<<<< Updated upstream
    static QVector<Message> filterByTime(QVector<Message> messages, QDateTime date);
=======
    static QVector<Message> getMessagesSentBeforeSelectedTime(QVector<Message> messages, QDateTime timeBefore);
    static void filterByTime(QVector<Message>& messages);
>>>>>>> Stashed changes
};

#endif // MESSAGEFILTER_H
