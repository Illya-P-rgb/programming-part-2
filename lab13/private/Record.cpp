#include "../public/Record.h"
#include "../public/StringUtils.h"

#include <sstream>
#include <regex>

bool parseRecord(
    const std::string& line,
    Record& record,
    std::string& errorMessage
) {
    std::string trimmedLine = normalizeSpaces(trim(line));

    if (trimmedLine.empty()) {
        errorMessage = "Empty line";
        return false;
    }

    const int MAX_FIELDS = 10;
    std::string fields[MAX_FIELDS];

    int fieldCount = split(trimmedLine, ';', fields, MAX_FIELDS);

    bool sensorFound = false;
    bool valueFound = false;
    bool unitFound = false;
    bool statusFound = false;

    std::regex sensorPattern("^[A-Z]\\d+$");

    for (int i = 0; i < fieldCount; ++i) {
        std::string key, valueText;

        if (!parseKeyValue(fields[i], key, valueText)) {
            errorMessage = "Invalid key=value pair: " + fields[i];
            return false;
        }

        if (key == "sensor") {
            if (!std::regex_match(valueText, sensorPattern)) {
                errorMessage = "Invalid sensor code";
                return false;
            }

            record.sensorCode = valueText;
            sensorFound = true;
        }
        else if (key == "value") {
            std::stringstream ss(valueText);
            double parsedValue;

            ss >> parsedValue;

            if (ss.fail() || !ss.eof()) {
                errorMessage = "Invalid numeric value";
                return false;
            }

            record.value = parsedValue;
            valueFound = true;
        }
        else if (key == "unit") {
            if (valueText != "C" && valueText != "F" && valueText != "K") {
                errorMessage = "Invalid measurement unit";
                return false;
            }

            record.unit = valueText;
            unitFound = true;
        }
        else if (key == "status") {
            if (
                valueText != "normal" &&
                valueText != "warning" &&
                valueText != "emergency"
            ) {
                errorMessage = "Invalid status";
                return false;
            }

            record.status = valueText;
            statusFound = true;
        }
        else {
            errorMessage = "Unknown field: " + key;
            return false;
        }
    }

    if (!sensorFound) {
        errorMessage = "Missing sensor field";
        return false;
    }

    if (!valueFound) {
        errorMessage = "Missing value field";
        return false;
    }

    if (!unitFound) {
        errorMessage = "Missing unit field";
        return false;
    }

    if (!statusFound) {
        errorMessage = "Missing status field";
        return false;
    }

    return true;
}