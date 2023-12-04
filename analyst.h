#ifndef ANALYST_H
#define ANALYST_H

#include <vector>
#include <QtCharts>
#include "collectedStatistic.h"
#include "statistic.h"

/* Class for accumulate statistics (tagName, num, time) */
class ANALYST_EXPORT Analyst
{
    /* Unprocessed statistics with different tagNames */
    std::vector <Statistic> statistics;

    /* Processed statistics, each tagName with array of nums and corresponding times
     * Used like cach of processed statistics */
    std::vector <CollectedStatistic> collectedStatistics;

    /* Array of unprocessed tagNames
     * If tagName is not contain, processing not started */
    std::vector <QString> inputedTagNames;

public:
    Analyst();
    Analyst(std::vector <Statistic> statistics, std::vector <CollectedStatistic> collectedStatistics);
    Analyst(const Analyst& obj);
    ~Analyst();

    /* Method for adding of unprocessed statistic
     * tagName - name of tested method
     * time - time result of testing
     * num - parameter of tested method */
    void addNewStatistics(QString tagName, uint64_t time, uint64_t num);

    /* Processing of statistics by tagName and call showHistogram()
     * tagName - name of tested method */
    void showStatistics(QString tagName);

    void setStatistics(std::vector <Statistic> _statistics);
    void setSomeStatistics(std::vector <CollectedStatistic> _collectedStatistics);

    std::vector <Statistic> getStatistics();
    std::vector <CollectedStatistic> getCollectedStatistics();

    /* Method for building histogram
     * indexOfTagName - index of name of tested method in collectedStatistics */
private: void showHistogram(int indexOfTagName);
};

#endif // ANALYST_H
