#include "statistic.h"

Statistic::Statistic() : SomeStatistic(){
    tagName = "";
}

Statistic::Statistic(QString _tagName, uint64_t _time, uint64_t _num) : SomeStatistic(_time, _num){
    tagName = _tagName;
}

Statistic::Statistic(const Statistic& obj) : SomeStatistic(obj.time, obj.num){
    tagName = obj.tagName;
}

Statistic::~Statistic(){}

void Statistic::setTagName(QString _tagName) {
    tagName = _tagName;
}

void Statistic::setTime(uint64_t _time) {
    SomeStatistic::setTime(_time);
}

void Statistic::setNum(uint64_t _num) {
    SomeStatistic::setNum(_num);
}

QString Statistic::getTagName() {
    return tagName;
}

uint64_t Statistic::getTime() {
    return time;
}

uint64_t Statistic::getNum() {
    return num;
}
bool Statistic::operator==(Statistic someStatistic){
    return SomeStatistic::operator==(someStatistic);
}

bool Statistic::operator!=(Statistic someStatistic){
    return SomeStatistic::operator!=(someStatistic);
}

bool Statistic::operator>(Statistic someStatistic){
    return SomeStatistic::operator>(someStatistic);
}

bool Statistic::operator<(Statistic someStatistic){
    return SomeStatistic::operator<(someStatistic);
}
