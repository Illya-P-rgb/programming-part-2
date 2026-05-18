#ifndef REPORTBUILDER_H
#define REPORTBUILDER_H

#include "Record.h"
#include <string>

struct Statistics {
    int totalLines{};
    int validCount{};
    int invalidCount{};

    int normalCount{};
    int warningCount{};
    int emergencyCount{};

    double averageValue{};
    double maxValue{};

    Record maxRecord;
};

Statistics computeStatistics(
    const Record records[],
    int recordCount,
    int invalidCount
);

std::string buildReport(
    const Record records[],
    int recordCount,
    const ParseError errors[],
    int errorCount
);


#endif