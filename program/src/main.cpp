#include <iostream>
#include <chrono>
#include "Hotel.h"
#include "Bedroom.h"
#include "Functions.h"
#include "json.hpp"
#include "DatabaseSystem.h"
#include <fstream>

using json = nlohmann::json;

int main() {
    std::shared_ptr<Hotel> grandHotel = std::make_shared<Hotel>("Grand", 4);
    DatabaseSystem db(grandHotel, "newDatabase.json");
    std::shared_ptr<Bedroom> bedroom = std::make_shared<Bedroom>("RedGreenBlue", 60.0, 40.0, 3);
    std::shared_ptr<Bedroom> bedroom2 = std::make_shared<Bedroom>("BlackAndWhite", 100.0, 70.0, 4);
    std::shared_ptr<ConferanceRoom> conferanceRoom = std::make_shared<ConferanceRoom>("CorpoOne", 100.0, 120.0, 20);
    std::shared_ptr<ConferanceRoom> conferanceRoom2 = std::make_shared<ConferanceRoom>("CorpoTwo", 100.0, 150.0, 30);
    std::shared_ptr<Storeroom> storeroom = std::make_shared<Storeroom>("UnderStairs", 100.0, 150.0);
    grandHotel->AddBedroom(bedroom);
    grandHotel->AddBedroom(bedroom2);
    grandHotel->AddConferanceRoom(conferanceRoom);
    grandHotel->AddConferanceRoom(conferanceRoom2);
    grandHotel->AddStoreroom(storeroom);
    std::tm arrivalDate = {0 ,0 ,10, 5, 3, 120};
    bedroom->Reserve(arrivalDate, 5, 1);
    std::tm meetingDate = {0 ,0 ,12, 5, 3, 120};
    conferanceRoom2->Reserve(meetingDate, 4, 2);
    db.UpdateDatabase();

    DatabaseSystem dbHilton("hotelDatabase.json");
    std::shared_ptr<Hotel> hiltonHotel = dbHilton.GetHotelFromDatabase();
    dbHilton.SetPath("output.json");
    dbHilton.UpdateDatabase();

    std::cout << std::endl;
    return 0;
}