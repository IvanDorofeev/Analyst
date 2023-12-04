#ifndef SOMESTATISTIC_H
#define SOMESTATISTIC_H

#include "Analyst_global.h"
#include <QString>

/* Class for some statistic (without tagName)
 * Used in CollectedStatistic because tagName is not need to each statistic (it's common characteristic) */
class ANALYST_EXPORT SomeStatistic
{
protected:
    uint64_t time;
    uint64_t num;

public:
    SomeStatistic();
    SomeStatistic(uint64_t time, uint64_t num);
    SomeStatistic(const SomeStatistic& obj);
    ~SomeStatistic();

    void setTime(uint64_t time);
    void setNum(uint64_t num);

    uint64_t getTime();
    uint64_t getNum();

    /* Override for sorting */
    bool operator== (SomeStatistic someStatistic);
    bool operator!= (SomeStatistic someStatistic);
    bool operator> (SomeStatistic someStatistic);
    bool operator< (SomeStatistic someStatistic);
};

#endif // SOMESTATISTIC_H
