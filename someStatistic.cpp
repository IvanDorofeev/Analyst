#include "someStatistic.h"

SomeStatistic::SomeStatistic(){
    time = 0;
    num = 0;
}

SomeStatistic::SomeStatistic(uint64_t _time, uint64_t _num) {
    time = _time;
    num = _num;
}

SomeStatistic::SomeStatistic(const SomeStatistic& obj) {
    time = obj.time;
    num = obj.num;
}

SomeStatistic::~SomeStatistic(){}


void SomeStatistic::setTime(uint64_t _time) {
    time = _time;
}

void SomeStatistic::setNum(uint64_t _num) {
    num = _num;
}

uint64_t SomeStatistic::getTime() {
    return time;
}

uint64_t SomeStatistic::getNum() {
    return num;
}

bool SomeStatistic::operator==(SomeStatistic someStatistic){
    return (num == someStatistic.num);
}

bool SomeStatistic::operator!=(SomeStatistic someStatistic){
    return (num != someStatistic.num);
}

bool SomeStatistic::operator>(SomeStatistic someStatistic){
    return (num > someStatistic.num);
}

bool SomeStatistic::operator<(SomeStatistic someStatistic){
    return (num < someStatistic.num);
}
