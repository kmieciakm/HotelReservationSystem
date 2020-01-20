#include <boost/test/unit_test.hpp>

#include "Functions.h"

BOOST_AUTO_TEST_SUITE(FunctionsSuiteCorrect)

BOOST_AUTO_TEST_CASE(isFloatNumber_PassFloat_ReturnTrue) {
    std::string str = "3.4";
    BOOST_REQUIRE_EQUAL(isFloatNumber(str), true);
}

BOOST_AUTO_TEST_CASE(isFloatNumber_PassText_ReturnFalse) {
    std::string str = "eleven";
    BOOST_REQUIRE_EQUAL(isFloatNumber(str), false);
}

BOOST_AUTO_TEST_CASE(isIntNumber_PassInt_ReturnTrue) {
    std::string str = "3";
    BOOST_REQUIRE_EQUAL(isIntNumber(str), true);
}

BOOST_AUTO_TEST_CASE(isIntNumber_PassFloat_ReturnFalse) {
    std::string str = "3.4";
    BOOST_REQUIRE_EQUAL(isIntNumber(str), false);
}

BOOST_AUTO_TEST_CASE(isIntNumber_PassText_ReturnFalse) {
    std::string str = "oneandtwo";
    BOOST_REQUIRE_EQUAL(isIntNumber(str), false);
}

BOOST_AUTO_TEST_CASE(StrToDate_PassDate_DateCorrect){
    std::tm date = {0,0,10,1,0,120};
    std::string dateStr = "01-01-2020";
    BOOST_REQUIRE_EQUAL(StrToDate(dateStr).tm_sec, date.tm_sec);
    BOOST_REQUIRE_EQUAL(StrToDate(dateStr).tm_min, date.tm_min);
    BOOST_REQUIRE_EQUAL(StrToDate(dateStr).tm_hour, date.tm_hour);
    BOOST_REQUIRE_EQUAL(StrToDate(dateStr).tm_mday, date.tm_mday);
    BOOST_REQUIRE_EQUAL(StrToDate(dateStr).tm_mon, date.tm_mon);
    BOOST_REQUIRE_EQUAL(StrToDate(dateStr).tm_year, date.tm_year);
}

BOOST_AUTO_TEST_CASE(DateToString_PassDate_StringCorrect){
    std::tm date = {0,0,14,1,0,120};
    std::string dateStr = "01 Jan. 2020 14:00";
    BOOST_REQUIRE_EQUAL(DateToString(date), dateStr);
    date = {0,0,12,5,5,122};
    dateStr = "05 June 2022 12:00";
    BOOST_REQUIRE_EQUAL(DateToString(date), dateStr);
}

BOOST_AUTO_TEST_CASE(GetIncreasedDate_AddedDaysAndHours_DateCorrect){
    std::tm date = {0,0,14,1,0,120};
    std::tm dateExpected = {0,0,19,3,0,120};
    std::tm dateIncreased = GetIncreasedDate(date, 5, 2);
    BOOST_REQUIRE_EQUAL(dateIncreased.tm_sec, dateExpected.tm_sec);
    BOOST_REQUIRE_EQUAL(dateIncreased.tm_min, dateExpected.tm_min);
    BOOST_REQUIRE_EQUAL(dateIncreased.tm_hour, dateExpected.tm_hour);
    BOOST_REQUIRE_EQUAL(dateIncreased.tm_mday, dateExpected.tm_mday);
    BOOST_REQUIRE_EQUAL(dateIncreased.tm_mon, dateExpected.tm_mon);
    BOOST_REQUIRE_EQUAL(dateIncreased.tm_year, dateExpected.tm_year);
}

BOOST_AUTO_TEST_CASE(GetIncreasedDate_AddedDaysAndHours_DateStringCorrect){
    std::tm date = {0,0,14,1,0,120};
    std::string dateExpectedStr = "03 Jan. 2020 19:00";
    std::tm dateIncreased = GetIncreasedDate(date, 5, 2);
    BOOST_REQUIRE_EQUAL(DateToString(dateIncreased), dateExpectedStr);

}

BOOST_AUTO_TEST_SUITE_END()
