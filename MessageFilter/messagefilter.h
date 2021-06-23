#ifndef MESSAGEFILTER_H
#define MESSAGEFILTER_H

#include "MessageFilter_global.h"
#include "message.h"
#include <QVector>
#include <QDateTime>

class MESSAGEFILTER_EXPORT MessageFilter
{
public:
    static void filterByTime(QVector<Message>& messages);
    static void filterByAlphabet(QVector<Message>& messages);
};

#endif // MESSAGEFILTER_H
