#include <iostream>
#include <chrono>
#include "Hotel.h"
#include "Bedroom.h"
#include "Functions.h"
#include "json.hpp"
#include <fstream>

using json = nlohmann::json;

int main() {
    Hotel hotel("Grand Hotel", 5);
    std::cout << "Welcome in " << hotel.GetName() << " (";
    for(int i = 0; i < hotel.GetStarsAmount(); i++)
        std::cout << "*";
    std::cout << ")" << std::endl;

    Bedroom bedroom("Badroom", 20, 20, 1);
    std::tm arrival = {0 ,0 ,10, 5, 0, 200};
    bedroom.Reserve(arrival, 30);
    std::cout << "Reservation Amount: " << bedroom.GetReservationsAmount() << std::endl;
    std::cout << "Reservation deadline: " << bedroom.GetReservation(0)->GetCheckoutDate().tm_mday << " - " 
              << bedroom.GetReservation(0)->GetCheckoutDate().tm_mon + 1 << " - "
              << bedroom.GetReservation(0)->GetCheckoutDate().tm_year + 1900 << std::endl;

    // -------------------------------- READ SYSTEM -------------------------------------
    std::fstream databaseFile;
    std::string databasePath = "../../data/hotelDatabase.json";
    
    databaseFile.open(databasePath, std::fstream::in);
    if( databaseFile.good() == true ){
        json db;
        databaseFile >> db;

        Hotel hotel(db["hotel"]["name"], db["hotel"]["stars"]);
        for(auto room : db["hotel"]["rooms"]){
            std::shared_ptr<Room> roomObj = std::make_shared<Room>(room["roomName"], room["roomArea"]);
            hotel.AddRoom(roomObj);
        }
        std::cout << hotel.GetName() << " (" << hotel.GetStarsAmount() << ")" << std::endl;
        std::cout << "Rooms Amount: " << hotel.GetRoomsAmount() << std::endl;
        for(auto room : hotel.GetRooms()){
            std::cout << "Room " << room->GetName() << " have the area " << room->GetArea() << std::endl;
        }
    } else {
        std::cout << std::endl << "Cannot find data file! ( " << databasePath << " )" << std::endl;
    }
    databaseFile.close();
    // ---------------------------------------------------------------------

    // -------------------------------SAVE SYSTEM--------------------------------------

    Hotel grandHotel("Grand", 4);
    std::shared_ptr<Room> roomOne = std::make_shared<Room>("RedGreenBlue", 60);
    std::shared_ptr<Room> roomTwo = std::make_shared<Room>("RGB", 90);
    grandHotel.AddRoom(roomOne);
    grandHotel.AddRoom(roomTwo);

    json db;
    db["hotel"]["name"] = grandHotel.GetName();
    db["hotel"]["stars"] = grandHotel.GetStarsAmount();
    for(auto room : grandHotel.GetRooms()){
        json newRoom;
        newRoom["roomName"] = room->GetName();
        newRoom["roomArea"] = room->GetArea();
        db["hotel"]["rooms"].push_back(newRoom);
    }

    std::fstream databaseFileSave;
    databaseFileSave.open("../../data/newDatabase.json", std::fstream::out);
    databaseFileSave << db << std::endl;

    // ---------------------------------------------------------------------

    std::cout << std::endl;
    return 0;
}