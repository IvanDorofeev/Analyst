#ifndef COLLECTEDSTATISTIC_H
#define COLLECTEDSTATISTIC_H

#include "someStatistic.h"

/* Class for accumulate statistic by tagName */
class ANALYST_EXPORT CollectedStatistic
{
    /* tagName of statistic (corresponding to each statistic in someStatistics) */
    QString tagName;

    /* Array of nums with corresponding times */
    std::vector <SomeStatistic> someStatistics;

public:
    CollectedStatistic();

    /* Constructor wich also sorting the someStatistics to normal analysis and show */
    CollectedStatistic(QString tagName, std::vector <SomeStatistic> someStatistics);
    CollectedStatistic(const CollectedStatistic& obj);
    ~CollectedStatistic();

    void setTagName(QString tagName);
    void setSomeStatistics(std::vector <SomeStatistic> someStatistics);

    QString getTagName();
    std::vector <SomeStatistic> getSomeStatistics();
};

#endif // COLLECTEDSTATISTIC_H
