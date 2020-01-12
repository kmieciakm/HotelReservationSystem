#include <boost/test/unit_test.hpp>

#include "ConferanceRoom.h"

BOOST_AUTO_TEST_SUITE(ConferanceRoomSuiteCorrect)

BOOST_AUTO_TEST_CASE(ConferanceRoomConstructor_InitialValues_AllCorrect) {
    ConferanceRoom conferanceRoom("CorpoOne", 100, 10, 32);
    BOOST_REQUIRE_EQUAL(conferanceRoom.GetName(), "CorpoOne");
    BOOST_REQUIRE_EQUAL(conferanceRoom.GetArea(), 100);
    BOOST_REQUIRE_EQUAL(conferanceRoom.GetPrice(), 10);
    BOOST_REQUIRE_EQUAL(conferanceRoom.GetChairsAmount(), 32);
    BOOST_REQUIRE_EQUAL(conferanceRoom.GetReservationsAmount(), 0);
}

BOOST_AUTO_TEST_CASE(ConferanceRoom_SettingBedsAmountToFour_GetBedsReturnValueCorrect) {
    ConferanceRoom ConferanceRoom("CorpoOne", 100, 10, 32);
    ConferanceRoom.SetChairsAmount(40);
    BOOST_REQUIRE_EQUAL(ConferanceRoom.GetChairsAmount(), 40);
}

BOOST_AUTO_TEST_CASE(ConferanceRoom_ReservingRoom_NewReservationInVariable) {
    ConferanceRoom conferanceRoom("CorpoOne", 100, 10, 32);
    std::tm arrival = {0, 0, 10, 12, 0, 400};
    int hours = 5;
    conferanceRoom.Reserve(arrival, hours, 13);
    BOOST_REQUIRE_EQUAL(conferanceRoom.GetReservationsAmount(), 1);
}

BOOST_AUTO_TEST_CASE(ConferanceRoom_CheckFreeTerm_RetrunTrue) {
    ConferanceRoom conferanceRoom("CorpoOne", 100, 10, 32);
    std::tm start = {0, 0, 10, 18, 0, 400};
    std::tm end = {0, 0, 15, 18, 0, 400};
    BOOST_REQUIRE_EQUAL(conferanceRoom.IsFreeInTerm(start, end), true);
}

BOOST_AUTO_TEST_CASE(ConferanceRoom_CheckReservedTerm_RetrunFalse) {
    ConferanceRoom conferanceRoom("CorpoOne", 100, 10, 32);
    std::tm arrival = {0, 0, 10, 12, 0, 400};
    int hours = 5;
    conferanceRoom.Reserve(arrival, hours, 13);
    std::tm start = {0, 0, 10, 10, 0, 400};
    std::tm end = {0, 0, 10, 20, 0, 400};
    BOOST_REQUIRE_EQUAL(conferanceRoom.IsFreeInTerm(start, end), false);
}

BOOST_AUTO_TEST_CASE(ConferanceRoom_TryReservedAlreadyReservedTerm_ThrowException) {
    ConferanceRoom conferanceRoom("CorpoOne", 50, 30, 3);
    std::tm arrival = {0, 0, 10, 10, 0, 400};
    conferanceRoom.Reserve(arrival, 4, 13);
    std::tm start = {0, 0, 11, 10, 0, 400};
    BOOST_REQUIRE_THROW(conferanceRoom.Reserve(start, 5, 14), std::logic_error);
}

BOOST_AUTO_TEST_CASE(ConferanceRoom_TryReservedTooManyHours_ThrowException) {
    ConferanceRoom ConferanceRoom("CorpoOne", 50, 30, 3);
    std::tm arrival = {0, 0, 10, 10, 0, 400};
    BOOST_REQUIRE_THROW(ConferanceRoom.Reserve(arrival, MAX_RESERVATION_HOURS + 5, 13), std::logic_error);
}

BOOST_AUTO_TEST_SUITE_END()
