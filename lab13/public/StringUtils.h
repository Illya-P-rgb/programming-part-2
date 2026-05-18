#ifndef STRINGUTILS_H
#define STRINGUTILS_H

#include <string>

std::string trim(const std::string& text);
std::string normalizeSpaces(const std::string& text);

int split(
    const std::string& text,
    char delimiter,
    std::string parts[],
    int maxParts
);

bool parseKeyValue(
    const std::string& text,
    std::string& key,
    std::string& value
);

#endif