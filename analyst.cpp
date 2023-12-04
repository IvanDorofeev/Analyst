#include "analyst.h"

Analyst::Analyst() {
    statistics = {};
    collectedStatistics = {};
}

Analyst::Analyst(std::vector <Statistic> _statistics, std::vector <CollectedStatistic> _collectedStatistics) {
    statistics = _statistics;
    collectedStatistics = _collectedStatistics;
}

Analyst::Analyst(const Analyst& obj) {
    statistics = obj.statistics;
    collectedStatistics = obj.collectedStatistics;
}

Analyst::~Analyst(){}


void Analyst::addNewStatistics(QString tagName, uint64_t time, uint64_t num){
    statistics.push_back(Statistic(tagName, time, num));
    if (std::find(inputedTagNames.begin(), inputedTagNames.end(), tagName) == inputedTagNames.end()){
        inputedTagNames.push_back(tagName);
    }
}

void Analyst::showStatistics(QString tagName){

    /* Find tagName in collectedStatistics */
    bool flagOfCollStat = false;
    int indexOfTagName = 0;

    for(CollectedStatistic collectedStatistic : collectedStatistics) {
        if (collectedStatistic.getTagName() == tagName){
            flagOfCollStat = true;
            break;
        }
        indexOfTagName += 1;
    }

    /* Find tagName in inputedTagNames
     * If not find, started to process statistics */
    std::vector<QString>::iterator inputedTagNamesIter = std::find(inputedTagNames.begin(), inputedTagNames.end(), tagName);
    if (inputedTagNamesIter != inputedTagNames.end()){

        /* Groupping statistics by tagNames */
        std::vector <SomeStatistic> statisticsByTagName;

        for(Statistic statistic : statistics) {
            if (statistic.getTagName() == tagName){
                statisticsByTagName.push_back(SomeStatistic(statistic.getTime(), statistic.getNum()));
            }
        }

        /* Groupping statistics by nums */
        std::vector <uint64_t> numsInResult;

        /* Summarize times according to their num */
        std::vector <uint64_t> timesForNums;

        /* Summarize count of times according to their num */
        std::vector <int> countOfNums;

        for(SomeStatistic someStatistic : statisticsByTagName) {

            uint64_t currentNum = someStatistic.getNum();

            bool flagOfNum = false;
            int indexOfNum = 0;

            for(uint64_t num : numsInResult) {
                if (num == currentNum){
                    flagOfNum = true;
                    break;
                }
                indexOfNum += 1;
            }
            if (!flagOfNum){
                numsInResult.push_back(currentNum);
                timesForNums.push_back(0);
                countOfNums.push_back(0);
            }
            timesForNums[indexOfNum] += someStatistic.getTime();
            countOfNums[indexOfNum] += 1;
        }

        /* Add nums with their average times (SomeStatistics) to result */
        std::vector <SomeStatistic> result;

        for(unsigned long long i = 0; i < numsInResult.size(); i++) {
            result.push_back(SomeStatistic(timesForNums[i]/countOfNums[i], numsInResult[i]));
        }

        /* Add result with corresponding tagName to collectedStatistics */
        if (!flagOfCollStat){
            collectedStatistics.push_back(CollectedStatistic(tagName, result));
        }
        else{
            collectedStatistics[indexOfTagName] = CollectedStatistic(tagName, result);
        }

        inputedTagNames.erase(inputedTagNamesIter);
    }

    /* build histogram by tagName */
    showHistogram(indexOfTagName);
}

void Analyst::setStatistics(std::vector <Statistic> _statistics) {
    statistics = _statistics;
}

void Analyst::setSomeStatistics(std::vector <CollectedStatistic> _collectedStatistics) {
    collectedStatistics = _collectedStatistics;
}

std::vector <Statistic> Analyst::getStatistics() {
    return statistics;
}

std::vector <CollectedStatistic> Analyst::getCollectedStatistics() {
    return collectedStatistics;
}

void Analyst::showHistogram(int indexOfTagName) {

    CollectedStatistic currCollStat = collectedStatistics[indexOfTagName];

    /* calculate maxTime for max value of Y in histogram */
    uint64_t maxTime = 0;

    /* build qBarSets for histogram by nums */
    QBarSeries *series = new QBarSeries();
    for(unsigned long long i = 0; i < currCollStat.getSomeStatistics().size(); i ++){

        QBarSet *qBarSet = new QBarSet(QString::number(currCollStat.getSomeStatistics()[i].getNum()));

        uint64_t time = currCollStat.getSomeStatistics()[i].getTime();
        *qBarSet << time;

        if (time > maxTime){
            maxTime = time;
        }

        series->append(qBarSet);
    }

    QString title = currCollStat.getTagName();

    /* build chart */
    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Statistic for " + title);
    chart->setAnimationOptions(QChart::SeriesAnimations);

    QStringList categories;
    categories << "Axis of Nums";

    /* build X axis */
    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->append(categories);
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    /* build Y axis */
    QValueAxis *axisY = new QValueAxis();
    axisY->setRange(0, maxTime * 1.1);
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignRight);

    /* Change color of columns */
    QList<QBarSet *> sets = series->barSets();
    float currentHue = 0.0;
    for(int i = 0; i < sets.size(); ++i)
    {
        QColor col = QColor::fromHslF(currentHue, 0.7, 0.5);
        currentHue += 0.618033988749895f;
        currentHue = std::fmod(currentHue, 1.0f);
        sets[i]->setColor(col);
    }

    /* show widget with chart */
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->resize(1600, 900);
    chartView->show();
}
