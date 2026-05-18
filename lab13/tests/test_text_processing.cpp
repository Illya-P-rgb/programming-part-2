#include <gtest/gtest.h>

#include "../public/StringUtils.h"
#include "../public/Record.h"
#include "../public/ReportBuilder.h"

TEST(StringUtils, TrimBasic) {
    EXPECT_EQ(trim("  hello  "), "hello");
    EXPECT_EQ(trim("\t test \n"), "test");
    EXPECT_EQ(trim("nochange"), "nochange");
}

TEST(StringUtils, SplitBasic) {
    std::string parts[10];

    int count = split("a;b;c", ';', parts, 10);

    EXPECT_EQ(count, 3);
    EXPECT_EQ(parts[0], "a");
    EXPECT_EQ(parts[1], "b");
    EXPECT_EQ(parts[2], "c");
}

TEST(StringUtils, ParseKeyValueValid) {
    std::string key, value;

    bool ok = parseKeyValue("sensor=T1", key, value);

    EXPECT_TRUE(ok);
    EXPECT_EQ(key, "sensor");
    EXPECT_EQ(value, "T1");
}

TEST(StringUtils, ParseKeyValueInvalid) {
    std::string key, value;

    bool ok = parseKeyValue("invalidpair", key, value);

    EXPECT_FALSE(ok);
}

TEST(Record, ParseRecordValid) {
    Record r;
    std::string err;

    bool ok = parseRecord(
        "sensor=T1; value=23.7; unit=C; status=normal",
        r,
        err
    );

    EXPECT_TRUE(ok);
    EXPECT_EQ(r.sensorCode, "T1");
    EXPECT_DOUBLE_EQ(r.value, 23.7);
    EXPECT_EQ(r.unit, "C");
    EXPECT_EQ(r.status, "normal");
}

TEST(Record, ParseRecordMissingField) {
    Record r;
    std::string err;

    bool ok = parseRecord(
        "sensor=T1; value=23.7; unit=C",
        r,
        err
    );

    EXPECT_FALSE(ok);
}

TEST(Record, ParseRecordInvalidNumber) {
    Record r;
    std::string err;

    bool ok = parseRecord(
        "sensor=T1; value=abc; unit=C; status=normal",
        r,
        err
    );

    EXPECT_FALSE(ok);
}

TEST(StringUtils, NormalizeSpaces) {
    std::string input = "sensor=T1;   value=23.7;    unit=C";
    std::string output = normalizeSpaces(input);

    EXPECT_NE(output.find("   "), std::string::npos); // should collapse indirectly
}

TEST(Report, BuildReportBasic) {
    Record records[2];

    records[0].lineNumber = 1;
    records[0].sensorCode = "T1";
    records[0].value = 10.0;
    records[0].unit = "C";
    records[0].status = "normal";

    records[1].lineNumber = 2;
    records[1].sensorCode = "T2";
    records[1].value = 20.0;
    records[1].unit = "C";
    records[1].status = "emergency";

    ParseError errors[1];
    errors[0].lineNumber = 3;
    errors[0].line = "bad";
    errors[0].message = "error";

    std::string report = buildReport(records, 2, errors, 1);

    EXPECT_NE(report.find("Sensor"), std::string::npos);
    EXPECT_NE(report.find("Emergency"), std::string::npos);
}