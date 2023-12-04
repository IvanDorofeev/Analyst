QT += core gui widgets charts

TEMPLATE = lib
DEFINES += ANALYST_LIBRARY

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    analyst.cpp \
    collectedStatistic.cpp \
    someStatistic.cpp \
    statistic.cpp

HEADERS += \
    Analyst_global.h \
    analyst.h \
    collectedStatistic.h \
    someStatistic.h \
    statistic.h

TRANSLATIONS += \
    Analyst_en_GB.ts

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target
