#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>

#include "public/StringUtils.h"
#include "public/Record.h"
#include "public/ReportBuilder.h"

int main() {
    // ============================
    // UTF-8 and std::string demo
    // ============================
    std::string english = "cat";
    std::string ukrainian = "кіт";

    std::cout << english << ": " << english.size() << " bytes\n";
    std::cout << ukrainian << ": " << ukrainian.size() << " bytes\n";

    // ============================
    // C-string and buffer demo
    // ============================
    std::string sensorName = "T1";
    const char* rawSensor = sensorName.c_str();

    char buffer[64];
    int sensorId = 101;

    int written = std::snprintf(
        buffer,
        sizeof(buffer),
        "sensor=%s; id=%d",
        rawSensor,
        sensorId
    );

    if (written < 0 || static_cast<std::size_t>(written) >= sizeof(buffer)) {
        std::cerr << "Buffer is too small\n";
    } else {
        std::cout << "Buffer content: " << buffer << "\n";
    }

    // ============================
    // File processing
    // ============================
    const int MAX_RECORDS = 1000;
    const int MAX_ERRORS = 1000;

    Record validRecords[MAX_RECORDS];
    ParseError errors[MAX_ERRORS];

    int validCount = 0;
    int errorCount = 0;

    std::ifstream inputFile("/home/ilya/programming-part-2/lab13/data/input.txt");

    if (!inputFile.is_open()) {
        std::cerr << "Failed to open input file.\n";
        return 1;
    }

    std::string line;
    std::size_t lineNumber = 0;

    while (std::getline(inputFile, line)) {
        lineNumber++;

        std::string trimmed = trim(line);

        if (trimmed.empty()) {
            continue;
        }

        Record record;
        record.lineNumber = static_cast<int>(lineNumber);

        std::string errorMessage;

        if (parseRecord(trimmed, record, errorMessage)) {
            if (validCount < MAX_RECORDS) {
                validRecords[validCount++] = record;
            }
        } else {
            if (errorCount < MAX_ERRORS) {
                errors[errorCount].lineNumber = lineNumber;
                errors[errorCount].line = line;
                errors[errorCount].message = errorMessage;
                errorCount++;
            }
        }
    }

    inputFile.close();

    std::string report = buildReport(
        validRecords,
        validCount,
        errors,
        errorCount
    );

    std::ofstream outputFile("/home/ilya/programming-part-2/lab13/data/report.txt");

    if (!outputFile.is_open()) {
        std::cerr << "Failed to create report file.\n";
        return 1;
    }

    outputFile << report;
    outputFile.close();

    std::cout << "\nProcessing complete.\n";
    std::cout << "Valid records: " << validCount << "\n";
    std::cout << "Invalid records: " << errorCount << "\n";
    std::cout << "Report written to data/report.txt\n";

    return 0;
}