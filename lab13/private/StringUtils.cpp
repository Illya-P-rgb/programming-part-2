#include "../public/StringUtils.h"
#include <regex>

std::string trim(const std::string& text) {
    size_t start = text.find_first_not_of(" \t\n\r");
    if (start == std::string::npos) {
        return "";
    }

    size_t end = text.find_last_not_of(" \t\n\r");

    return text.substr(start, end - start + 1);
}

int split(
    const std::string& text,
    char delimiter,
    std::string parts[],
    int maxParts
) {
    int count = 0;
    size_t start = 0;
    size_t end;

    while ((end = text.find(delimiter, start)) != std::string::npos) {
        if (count >= maxParts) {
            return count;
        }

        parts[count++] = text.substr(start, end - start);
        start = end + 1;
    }

    if (count < maxParts) {
        parts[count++] = text.substr(start);
    }

    return count;
}

bool parseKeyValue(
    const std::string& text,
    std::string& key,
    std::string& value
) {
    size_t pos = text.find('=');

    if (pos == std::string::npos) {
        return false;
    }

    key = trim(text.substr(0, pos));
    value = trim(text.substr(pos + 1));

    if (key.empty() || value.empty()) {
        return false;
    }

    return true;
}

std::string normalizeSpaces(const std::string& text) {
    std::regex spacesPattern("\\s{2,}");
    return std::regex_replace(text, spacesPattern, " ");
}