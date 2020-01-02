#include <boost/test/unit_test.hpp>

#include "Hotel.h"

BOOST_AUTO_TEST_SUITE(HotelSuiteCorrect)

BOOST_AUTO_TEST_CASE(HotelConstructor_InitialValues_AllCorrect) {
    Hotel hotel("Grand", 5);
    BOOST_REQUIRE_EQUAL(hotel.GetName(), "Grand");
    BOOST_REQUIRE_EQUAL(hotel.GetStarsAmount(), 5);
}

BOOST_AUTO_TEST_CASE(Hotel_SetName_RenameCorrectly) {
    Hotel hotel("Grand", 5);
    hotel.SetName("Hotel Hilton");
    BOOST_REQUIRE_EQUAL(hotel.GetName(), "Hotel Hilton");
}

BOOST_AUTO_TEST_CASE(Hotel_AddRoom_RoomAdded) {
    Hotel hotel("Grand", 5);
    std::shared_ptr<Bedroom> room = std::make_shared<Bedroom>("BlackAndWhite", 50.0, 30.0, 2);
    hotel.AddBedroom(room);
    BOOST_REQUIRE_EQUAL(hotel.GetBedroom(0)->GetName(), "BlackAndWhite");
}

BOOST_AUTO_TEST_CASE(Hotel_AddTwoRooms_RoomsAmountCorrect) {
    Hotel hotel("Grand", 5);
    std::shared_ptr<Bedroom> roomOne = std::make_shared<Bedroom>("BlackAndWhite", 50.0, 30.0, 2);
    std::shared_ptr<Bedroom> roomTwo = std::make_shared<Bedroom>("RedGreenBlue", 60.0, 20.0, 4);
    hotel.AddBedroom(roomOne);
    hotel.AddBedroom(roomTwo);
    BOOST_REQUIRE_EQUAL(hotel.GetBedroomsAmount(), 2);
}

BOOST_AUTO_TEST_SUITE_END()
