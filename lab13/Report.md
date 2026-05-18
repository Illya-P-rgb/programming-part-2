# Lab 13 — Text Processing, Files, and Regular Expressions in
C++


---
**Course:** Programming, Part 2  
**Institution:** NTU KhPI, Kharkiv, Ukraine  
**Student:** Illya Paralynov 
**Date:** 05/18/2026
---

## Task Objective

The objective of this assignment is to develop practical skills in processing text,
handling text files, and utilizing regular expressions in C++.
To achieve this aim, it is necessary to:
• use std::string for application-level text processing;
• create custom helper functions for trimming and splitting strings;
• parse records in the key=value format;
• convert text fields into typed values using string streams;
• read input data from a text file and write results to a separate file;
• generate a text report with the processing results;
• apply std::regex for local validation and replacement of text fragments;
• explain the relationship between std::string, C strings, fixed-size buffers,
UTF-8 text, and structured formats, in particular JSON.

## Variant

```text
Sensor measurements. Format: sensor=T1; value=23.7; unit=C; status=normal. Compute the average value, the number of emergency statuses, and the maximum value. Validate the sensor code with the pattern [A-Z]\d+, the numeric field value, the measurement unit, and allowed statuses
```

## The project structure

```text
lab13/
├── data/
    ├── expected_report_example.txt
    └── input.txt
├── private/
    ├── Record.cpp
    ├── ReportBuilder.cpp
    └── StringUtils.cpp
├── public/
    ├── Record.h
    ├── ReportBuilder.h
    └── StringUtils.h
├── tests/
    └── test_text_processing.cpp
├── CMakeLists.txt
├── main.cpp
└── Report.md
```

## A description of the input file format

The input file consists of multiple lines, where each line represents a single sensor measurement record. Each record is written in a structured key=value format, with individual fields separated by semicolons.

## An example of input data

sensor=T1; value=23.7; unit=C; status=normal
sensor=A2; value=50.1; unit=C; status=emergency
sensor=B3; value=10; unit=F; status=warning
sensor=12; value=23.7; unit=C; status=normal
sensor=T1; value=abc; unit=C; status=normal
sensor=T2; value=20.5; unit=X; status=normal
sensor=T3; value=15.0; unit=C
sensor=Z9; value=0; unit=C; status=emergency
sensor= A1 ; value= 100 ; unit= C ; status= normal


## trim()

std::string trim(const std::string& text) {
    size_t start = text.find_first_not_of(" \t\n\r");
    if (start == std::string::npos) {
        return "";
    }

    size_t end = text.find_last_not_of(" \t\n\r");

    return text.substr(start, end - start + 1);
}

## split()

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

## parseKeyValue()

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

## The record structure

Contains the following fields:

sensorCode 
value 
unit 
status 
lineNumber 

## The logic of parseRecord()

The parseRecord() function converts a raw input line into a structured Record.

The steps are:

Trim the input line.
Split the line into key-values.
Parse each segment with parseKeyValue().

Validate each field:
Sensor code is validated using an expression [A-Z]\d+
Numeric values are converted using string streams
Unit and status fields are checked against allowed values
If all validations pass, the function fills a Record structure.
If any validation fails, an error message is output.


## Examples of valid and invalid lines

Valid examples:

sensor=T1; value=23.7; unit=C; status=normal
sensor=A2; value=50.0; unit=C; status=emergency

Invalid examples:

sensor=12; value=23.7; unit=C; status=normal (invalid sensor format)
sensor=T1; value=abc; unit=C; status=normal (non-numeric value)
sensor=T1; value=23.7; unit=X; status=normal (invalid unit)
sensor=T1; value=23.7; unit=C (missing field)

## An example of the generated report

Sensor Measurements Report
==========================

Total valid records: 5
Total invalid records: 4

Status Statistics:
Normal: 2
Warning: 1
Emergency: 2

Average Value: 36.76
Maximum Value: 100.00
Sensor with Maximum Value: A1 (100.00 C)

Emergency Records:
Line 2: sensor=A2; value=50.10; unit=C; status=emergency
Line 8: sensor=Z9; value=0.00; unit=C; status=emergency

Invalid Records:
Line 4: Invalid sensor code | sensor=12; value=23.7; unit=C; status=normal
Line 5: Invalid numeric value | sensor=T1; value=abc; unit=C; status=normal
Line 6: Invalid measurement unit | sensor=T2; value=20.5; unit=X; status=normal
Line 7: Missing status field | sensor=T3; value=15.0; unit=C

## An explanation of the regular expression used

The regular expression used for sensor validation is:

^[A-Z]\d+$

This pattern ensures that the sensor identifier starts with one uppercase letter
it must also be followed by one or more digits
no additional characters are allowed at all

The expression is used with std::regex_match()

## An explanation of std::regex_replace()

std::regex_replace() is used to fix input text by replacing sequences of multiple whitespace characters with a single space.

This step improves parsing reliability by making sure that strange spacing does not break key-value extraction.

## Results of the UTF-8 observation; an example with c_str() and std::snprintf

The UTF-8 observation shows that std::string::size() returns the number of bytes, not the number of visible characters. As a result, non-ASCII characters such as cyrillic letters may occupy more than one byte per character.

Example from main:

"cat" has a size of 3 bytes
"кіт" has a size of 6 bytes

## An explanation of the limits of regular expressions for JSON or a similar format

Regular expressions are not suitable for parsing structured formats, such as JSON, because such formats contain hierarchical structures. JSON supports recursion, arrays, and complex escaping rules that cannot be reliably handled using regular expressions.

Regex is useful for simple validation tasks, but it cannot correctly represent or parse hierarchical data structures.

## Conclusions

I found this lab to be extremely complicated, probably the most complicated so far. Although i do understand that text processing, file input and output, as well as wide strings and such are quite important for c++, i couldnt help but think about how simple most of the previous labs were. I suppose it shows the progress we've made as programmers, and a students.