#ifndef STATISTIC_H
#define STATISTIC_H

#include "someStatistic.h"

/* Class for some statistic with tagName
 * Used for unprocessed statistics (tagName is personal characteristic) */
class ANALYST_EXPORT Statistic : public SomeStatistic
{
    QString tagName;

public:
    Statistic();
    Statistic(QString tagName, uint64_t time, uint64_t num);
    Statistic(const Statistic& obj);
    ~Statistic();

    void setTagName(QString tagName);
    void setTime(uint64_t time);
    void setNum(uint64_t num);

    QString getTagName();
    uint64_t getTime();
    uint64_t getNum();

    bool operator== (Statistic someStatistic);
    bool operator!= (Statistic someStatistic);
    bool operator> (Statistic someStatistic);
    bool operator< (Statistic someStatistic);
};

#endif // STATISTIC_H
