#include "collectedStatistic.h"

CollectedStatistic::CollectedStatistic(){
    tagName = "";
    someStatistics = {};
}

CollectedStatistic::CollectedStatistic(QString _tagName, std::vector <SomeStatistic> _someStatistics){
    tagName = _tagName;

    /* Sorting someStatistics by num */
    std::sort(_someStatistics.begin(), _someStatistics.end());
    someStatistics = _someStatistics;
}

CollectedStatistic::CollectedStatistic(const CollectedStatistic& obj){
    tagName = obj.tagName;
    someStatistics = obj.someStatistics;
}

CollectedStatistic::~CollectedStatistic(){}

void CollectedStatistic::setTagName(QString _tagName) {
    tagName = _tagName;
}

void CollectedStatistic::setSomeStatistics(std::vector <SomeStatistic> _someStatistics) {
    someStatistics = _someStatistics;
}

QString CollectedStatistic::getTagName() {
    return tagName;
}

std::vector <SomeStatistic> CollectedStatistic::getSomeStatistics() {
    return someStatistics;
}
