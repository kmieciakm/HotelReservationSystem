#include <boost/test/unit_test.hpp>

#include "Bedroom.h"

BOOST_AUTO_TEST_SUITE(BedroomSuiteCorrect)

BOOST_AUTO_TEST_CASE(BedroomConstructor_InitialValues_AllCorrect) {
    Bedroom bedroom("BlackAndWhite", 40, 20, 2);
    BOOST_REQUIRE_EQUAL(bedroom.GetName(), "BlackAndWhite");
    BOOST_REQUIRE_EQUAL(bedroom.GetArea(), 40);
    BOOST_REQUIRE_EQUAL(bedroom.GetPrice(), 20);
    BOOST_REQUIRE_EQUAL(bedroom.GetBedsAmount(), 2);
    BOOST_REQUIRE_EQUAL(bedroom.GetReservationsAmount(), 0);
}

BOOST_AUTO_TEST_CASE(Bedroom_SettingBedsAmountToFour_GetBedsReturnValueCorrect) {
    Bedroom bedroom("BlackAndWhite", 40, 20, 2);
    bedroom.SetBedsAmount(6);
    BOOST_REQUIRE_EQUAL(bedroom.GetBedsAmount(), 6);
}

BOOST_AUTO_TEST_CASE(Bedroom_ChangeRoomPrice_NewPriceReturned) {
    Bedroom bedroom("BlackAndWhite", 40, 20, 2);
    bedroom.SetPrice(40);
    BOOST_REQUIRE_EQUAL(bedroom.GetPrice(), 40);
}

BOOST_AUTO_TEST_CASE(Bedroom_TryChangeToNegativePrice_ThrowError) {
    Bedroom bedroom("BlackAndWhite", 40, 20, 2);
    BOOST_REQUIRE_THROW(bedroom.SetPrice(-40), std::logic_error);
}

BOOST_AUTO_TEST_CASE(Bedroom_ReservingRoom_NewReservationInVariable) {
    Bedroom bedroom("BlackAndWhite", 40, 20, 2);
    std::tm arrival = {0, 0, 10, 10, 1, 400};
    int days = 2;
    bedroom.Reserve(arrival, days, 12);
    BOOST_CHECK(true);
}

BOOST_AUTO_TEST_CASE(Bedroom_GetWrongReservationId_ThrowError) {
    Bedroom bedroom("BlackAndWhite", 50, 30, 20);
    BOOST_REQUIRE_THROW(bedroom.GetReservation("b30"), std::logic_error);
}

BOOST_AUTO_TEST_CASE(Bedroom_CheckFreeTerm_RetrunTrue) {
    Bedroom bedroom("BlackAndWhite", 40, 20, 2);
    std::tm start = {0, 0, 10, 18, 0, 400};
    std::tm end = {0, 0, 10, 20, 0, 400};
    BOOST_REQUIRE_EQUAL(bedroom.IsFreeInTerm(start, end), true);
}

BOOST_AUTO_TEST_CASE(Bedroom_CheckReservedTerm_RetrunFalse) {
    Bedroom bedroom("BlackAndWhite", 50, 30, 3);
    std::tm arrival = {0, 0, 10, 10, 0, 400};
    bedroom.Reserve(arrival, 4, 12);
    std::tm start = {0, 0, 10, 8, 0, 400};
    std::tm end = {0, 0, 10, 11, 0, 400};
    BOOST_REQUIRE_EQUAL(bedroom.IsFreeInTerm(start, end), false);
}

BOOST_AUTO_TEST_CASE(Bedroom_TryReservedAlreadyReservedTerm_ThrowException) {
    Bedroom bedroom("BlackAndWhite", 50, 30, 3);
    std::tm arrival = {0, 0, 10, 10, 0, 400};
    bedroom.Reserve(arrival, 4, 12);
    std::tm start = {0, 0, 10, 8, 0, 400};
    BOOST_REQUIRE_THROW(bedroom.Reserve(start, 5, 14), std::logic_error);
}

BOOST_AUTO_TEST_CASE(Bedroom_TryReservedOnNegativePeriod_ThrowException) {
    Bedroom bedroom("BlackAndWhite", 50, 30, 3);
    std::tm arrival = {0, 0, 10, 10, 0, 400};
    BOOST_REQUIRE_THROW(bedroom.Reserve(arrival, -5, 14), std::logic_error);
}

BOOST_AUTO_TEST_CASE(Bedroom_TryReservedTooManyDays_ThrowException) {
    Bedroom bedroom("BlackAndWhite", 50, 30, 3);
    std::tm arrival = {0, 0, 10, 10, 0, 400};
    BOOST_REQUIRE_THROW(bedroom.Reserve(arrival, MAX_RESERVATION_DAYS + 5, 12), std::logic_error);
}

BOOST_AUTO_TEST_CASE(Bedroom_ReservingRoom_ReservationCheckoutDateCorrect){
    Bedroom bedroom("BlackAndWhite", 50, 30, 3);
    std::tm checkIn = {0, 0, 10, 10, 0, 400};
    std::tm expectedCheckout = {0, 0, 10, 15, 0, 400};
    bedroom.Reserve(checkIn, 5, 12);
    std::tm checkOut = bedroom.GetReservation("b12")->GetCheckoutDate();
    BOOST_REQUIRE_EQUAL(checkOut.tm_hour, expectedCheckout.tm_hour);
    BOOST_REQUIRE_EQUAL(checkOut.tm_mday, expectedCheckout.tm_mday);
    BOOST_REQUIRE_EQUAL(checkOut.tm_mon, expectedCheckout.tm_mon);
    BOOST_REQUIRE_EQUAL(checkOut.tm_year, expectedCheckout.tm_year);
}

BOOST_AUTO_TEST_SUITE_END()
