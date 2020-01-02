#include <boost/test/unit_test.hpp>

#include "Storeroom.h"

BOOST_AUTO_TEST_SUITE(StoreroomSuiteCorrect)

BOOST_AUTO_TEST_CASE(StoreroomConstructor_InitialValues_AllCorrect) {
    Storeroom storeroom("StoreroomOne", 100, 200.0);
    BOOST_REQUIRE_EQUAL(storeroom.GetName(), "StoreroomOne");
    BOOST_REQUIRE_EQUAL(storeroom.GetArea(), 100);
    BOOST_REQUIRE_CLOSE_FRACTION(storeroom.GetCapacity(), 200.0, 0.000001);
    BOOST_REQUIRE_CLOSE_FRACTION(storeroom.GetOccupied(), 0.0, 0.000001);
    BOOST_REQUIRE_EQUAL(storeroom.IsFull(), false);
}

BOOST_AUTO_TEST_CASE(Room_RoomLoadedToMaximum_IsFullReturnTrue) {
    Storeroom storeroom("StoreroomOne", 100, 200.0);
    storeroom.Load(200.0);
    BOOST_REQUIRE_EQUAL(storeroom.IsFull(), true);
}

BOOST_AUTO_TEST_CASE(Room_RoomLoadedToHalf_IsFullReturnFalse) {
    Storeroom storeroom("StoreroomOne", 100, 200.0);
    storeroom.Load(100.0);
    BOOST_REQUIRE_EQUAL(storeroom.IsFull(), false);
}

BOOST_AUTO_TEST_CASE(Room_RoomLoaded_OccupiedCorrectlySet) {
    Storeroom storeroom("StoreroomOne", 100, 200.0);
    storeroom.Load(100.0);
    BOOST_REQUIRE_CLOSE_FRACTION(storeroom.GetOccupied(), 100.0, 0.000001);
}

BOOST_AUTO_TEST_CASE(Room_RoomLoadedThenUnloaded_OccupiedEqualZero) {
    Storeroom storeroom("StoreroomOne", 100, 200.0);
    storeroom.Load(100.0);
    storeroom.Unload(100.0);
    BOOST_REQUIRE_CLOSE_FRACTION(storeroom.GetOccupied(), 0.0, 0.000001);
}

BOOST_AUTO_TEST_CASE(Room_TryLoadMoreThenCapacity_ThrowException) {
    Storeroom storeroom("StoreroomOne", 100, 200.0);
    BOOST_REQUIRE_THROW(storeroom.Load(300.0), std::out_of_range);
}

BOOST_AUTO_TEST_CASE(Room_TryUnLoadMoreThenOccupied_ThrowException) {
    Storeroom storeroom("StoreroomOne", 100, 200.0);
    storeroom.Load(100.0);
    BOOST_REQUIRE_THROW(storeroom.Unload(300.0), std::out_of_range);
}

BOOST_AUTO_TEST_CASE(Room_TryLoadNegative_ThrowException) {
    Storeroom storeroom("StoreroomOne", 100, 200.0);
    BOOST_REQUIRE_THROW(storeroom.Load(-100.0), std::logic_error);
}

BOOST_AUTO_TEST_CASE(Room_TryUnloadNegative_ThrowException) {
    Storeroom storeroom("StoreroomOne", 100, 200.0);
    storeroom.Load(150.00); 
    BOOST_REQUIRE_THROW(storeroom.Unload(-100.0), std::logic_error);
}

BOOST_AUTO_TEST_SUITE_END()