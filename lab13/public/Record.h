#ifndef RECORD_H
#define RECORD_H

#include <string>

struct Record {
    int lineNumber{};
    std::string sensorCode;
    double value{};
    std::string unit;
    std::string status;
};

struct ParseError {
    std::size_t lineNumber{};
    std::string line;
    std::string message;
};

bool parseRecord(
    const std::string& line,
    Record& record,
    std::string& errorMessage
);

#endif