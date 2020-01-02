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
    std::shared_ptr<Room> room = std::make_shared<Room>("BlackAndWhite", 50);
    hotel.AddRoom(room);
    BOOST_REQUIRE_EQUAL(hotel.GetRoom(0)->GetName(), "BlackAndWhite");
}

BOOST_AUTO_TEST_CASE(Hotel_AddThreeRooms_RoomsAmountCorrect) {
    Hotel hotel("Grand", 5);
    std::shared_ptr<Room> roomOne = std::make_shared<Room>("BlackAndWhite", 50);
    std::shared_ptr<Room> roomTwo = std::make_shared<Room>("RedGreenBlue", 60);
    std::shared_ptr<Room> roomThree = std::make_shared<Room>("BlackRedWhite", 150);
    hotel.AddRoom(roomOne);
    hotel.AddRoom(roomTwo);
    hotel.AddRoom(roomThree);
    BOOST_REQUIRE_EQUAL(hotel.GetRoomsAmount(), 3);
}

BOOST_AUTO_TEST_SUITE_END()
