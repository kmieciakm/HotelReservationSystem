#include <boost/test/unit_test.hpp>

#include "Reservation.h"

BOOST_AUTO_TEST_SUITE(ReservationSuiteCorrect)

BOOST_AUTO_TEST_CASE(ReservationConstructor_InitialValues_AllCorrect) {
    std::tm arrival = {0, 0, 10, 12, 0, 120};
    std::tm departure = {0, 0, 10, 14, 0, 120};
    Reservation reservation(arrival, departure, 50, arrival, "c123");
    BOOST_REQUIRE_EQUAL(reservation.GetCheckinDate().tm_mday, arrival.tm_mday);
    BOOST_REQUIRE_EQUAL(reservation.GetCheckoutDate().tm_mday, departure.tm_mday);
    BOOST_REQUIRE_EQUAL(reservation.GetReservationId(), "c123");
    BOOST_REQUIRE(reservation.GetPayment());
}

BOOST_AUTO_TEST_CASE(Reservation_ChangeToValidDate_DateCorrect) {
    std::tm arrival = {0, 0, 10, 12, 0, 400};
    std::tm departure = {0, 0, 10, 14, 0, 400};
    Reservation reservation(arrival, departure, 50, "c123");

    std::tm newDate = {0, 0, 10, 1, 1, 400};
    reservation.SetCheckoutDate(newDate);
    BOOST_REQUIRE_EQUAL(reservation.GetCheckoutDate().tm_mday, newDate.tm_mday);
    BOOST_REQUIRE_EQUAL(reservation.GetCheckoutDate().tm_mon, newDate.tm_mon);
    BOOST_REQUIRE_EQUAL(reservation.GetCheckoutDate().tm_year, newDate.tm_year);
}

BOOST_AUTO_TEST_CASE(Reservation_ChangeToInvalidDate_ThrowException) {
    std::tm arrival = {0, 0, 10, 12, 0, 400};
    std::tm departure = {0, 0, 10, 14, 0, 400};
    Reservation reservation(arrival, departure, 50, "c123");

    std::tm newDate = {0, 0, 10, 1, 5, 120};
    BOOST_REQUIRE_THROW(reservation.SetCheckoutDate(newDate), std::logic_error);
}

BOOST_AUTO_TEST_CASE(Reservation_TryChangeDateOfPassedReservation_ThrowException) {
    std::tm arrival = {0, 0, 10, 12, 0, 100};
    std::tm departure = {0, 0, 10, 14, 0, 100};
    Reservation reservation(arrival, departure, 50, "c123");

    std::tm newDate = {0, 0, 10, 16, 0, 100};
    BOOST_REQUIRE_THROW(reservation.SetCheckoutDate(newDate), std::logic_error);
}

BOOST_AUTO_TEST_SUITE_END()
