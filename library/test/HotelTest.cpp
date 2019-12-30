#include <boost/test/unit_test.hpp>

#include "Hotel.h"

BOOST_AUTO_TEST_SUITE(HotelSuiteCorrect)

BOOST_AUTO_TEST_CASE(HotelConstructor_InitialValues_AllCorrect) {
    Hotel hotel("Grand", 5);
    BOOST_REQUIRE_EQUAL(hotel.GetName(), "Grand");
    BOOST_REQUIRE_EQUAL(hotel.GetStarsAmount(), 5);
}

BOOST_AUTO_TEST_SUITE_END()
