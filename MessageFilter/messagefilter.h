#ifndef MESSAGEFILTER_H
#define MESSAGEFILTER_H

#include "MessageFilter_global.h"
#include "message.h"
#include <QVector>
#include <QDateTime>

class MESSAGEFILTER_EXPORT MessageFilter
{
public:
    static void filterByTimeSmallToBig(QVector<Message>& messages);
    static void filterByAlphabetSmallToBig(QVector<Message>& messages);
    static void filterByTimeBigToSmall(QVector<Message>& messages);
    static void filterByAlphabetBigToSmall(QVector<Message>& messages);
};

#endif // MESSAGEFILTER_H
