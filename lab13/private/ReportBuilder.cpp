#include "../public/ReportBuilder.h"

#include <sstream>
#include <iomanip>

Statistics computeStatistics(
    const Record records[],
    int recordCount,
    int invalidCount
) {
    Statistics stats{};

    stats.validCount = recordCount;
    stats.invalidCount = invalidCount;
    stats.totalLines = recordCount + invalidCount;

    if (recordCount == 0) {
        return stats;
    }

    double sum = 0.0;

    stats.maxValue = records[0].value;
    stats.maxRecord = records[0];

    for (int i = 0; i < recordCount; ++i) {
        const Record& record = records[i];

        sum += record.value;

        if (record.status == "normal") {
            stats.normalCount++;
        }
        else if (record.status == "warning") {
            stats.warningCount++;
        }
        else if (record.status == "emergency") {
            stats.emergencyCount++;
        }

        if (record.value > stats.maxValue) {
            stats.maxValue = record.value;
            stats.maxRecord = record;
        }
    }

    stats.averageValue = sum / recordCount;

    return stats;
}

std::string buildReport(
    const Record records[],
    int recordCount,
    const ParseError errors[],
    int errorCount
) {
    Statistics stats = computeStatistics(records, recordCount, errorCount);

    std::ostringstream report;

    report << "Sensor Measurements Report\n";
    report << "==========================\n\n";

    report << "Total valid records: " << stats.validCount << "\n";
    report << "Total invalid records: " << stats.invalidCount << "\n\n";

    report << "Status Statistics:\n";
    report << "Normal: " << stats.normalCount << "\n";
    report << "Warning: " << stats.warningCount << "\n";
    report << "Emergency: " << stats.emergencyCount << "\n\n";

    report << std::fixed << std::setprecision(2);

    report << "Average Value: " << stats.averageValue << "\n";
    report << "Maximum Value: " << stats.maxValue << "\n";
    report << "Sensor with Maximum Value: "
           << stats.maxRecord.sensorCode
           << " (" << stats.maxRecord.value
           << " " << stats.maxRecord.unit << ")\n\n";

    report << "Emergency Records:\n";

    for (int i = 0; i < recordCount; ++i) {
        if (records[i].status == "emergency") {
            report << "Line " << records[i].lineNumber
                   << ": sensor=" << records[i].sensorCode
                   << "; value=" << records[i].value
                   << "; unit=" << records[i].unit
                   << "; status=" << records[i].status
                   << "\n";
        }
    }

    report << "\nInvalid Records:\n";

    for (int i = 0; i < errorCount; ++i) {
        report << "Line " << errors[i].lineNumber
               << ": " << errors[i].message
               << " | " << errors[i].line
               << "\n";
    }

    return report.str();
}