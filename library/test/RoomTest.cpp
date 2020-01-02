#include <boost/test/unit_test.hpp>

#include "Room.h"

BOOST_AUTO_TEST_SUITE(RoomSuiteCorrect)

BOOST_AUTO_TEST_CASE(RoomConstructor_InitialValues_AllCorrect) {
    Room room("SampleRoom", 100);
    BOOST_REQUIRE_EQUAL(room.GetName(), "SampleRoom");
    BOOST_REQUIRE_EQUAL(room.GetArea(), 100);
}

BOOST_AUTO_TEST_CASE(Room_Rename_NameCorrectlyChange) {
    Room room("SampleRoom", 100);
    room.SetName("BlackAndWhite");
    BOOST_REQUIRE_EQUAL(room.GetName(), "BlackAndWhite");
}

BOOST_AUTO_TEST_SUITE_END()
