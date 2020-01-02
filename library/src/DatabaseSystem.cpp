#include "DatabaseSystem.h"
#include "json.hpp"
#include <fstream>

DatabaseSystem::DatabaseSystem(std::shared_ptr<Hotel> _hotel, std::string _path)
: hotel(_hotel), databaseFilename(_path) {}

std::shared_ptr<Hotel> DatabaseSystem::GetHotel(){
    return this->hotel;
}

void DatabaseSystem::SetPath(std::string newPath){
    this->databaseFilename = newPath;
}

void DatabaseSystem::Read(){
    // std::fstream databaseFile;
    // std::string databasePath = "../../data/hotelDatabase.json";
    
    // databaseFile.open(databasePath, std::fstream::in);
    // if( databaseFile.good() == true ){
    //     json db;
    //     databaseFile >> db;

    //     Hotel hotel(db["hotel"]["name"], db["hotel"]["stars"]);
    //     for(auto room : db["hotel"]["rooms"]){
    //         std::shared_ptr<Bedroom> roomObj = std::make_shared<Bedroom>(room["roomName"], room["roomArea"], room["roomPrice"], room["roomBeds"]);
    //         hotel.AddBedroom(roomObj);
    //     }
    //     std::cout << hotel.GetName() << " (" << hotel.GetStarsAmount() << ")" << std::endl;
    //     std::cout << "Rooms Amount: " << hotel.GetBedroomsAmount() << std::endl;
    //     for(auto room : hotel.GetBedrooms()){
    //         std::cout << "Room " << room->GetName() << " have the area " << room->GetArea() << std::endl;
    //     }
    // } else {
    //     std::cout << std::endl << "Cannot find data file! ( " << databasePath << " )" << std::endl;
    // }
    // databaseFile.close();
}

void DatabaseSystem::UpdateDatabase(){
    nlohmann::json db;
    db["hotel"]["name"] = this->hotel->GetName();
    db["hotel"]["stars"] = this->hotel->GetStarsAmount();
    for(auto bedroom : this->hotel->GetBedrooms()){
        nlohmann::json newBedroom;
        newBedroom["name"] = bedroom->GetName();
        newBedroom["area"] = bedroom->GetArea();
        newBedroom["price"] = bedroom->GetPrice();
        newBedroom["bedsAmount"] = bedroom->GetBedsAmount();
        nlohmann::json reservations = this->GetParsedReservations(bedroom->GetReservations());
        newBedroom["reservations"] = reservations;
        db["hotel"]["bedrooms"].push_back(newBedroom);
    }
    for(auto conferanceRoom : this->hotel->GetConferanceRooms()){
        nlohmann::json newConferanceRoom;
        newConferanceRoom["name"] = conferanceRoom->GetName();
        newConferanceRoom["area"] = conferanceRoom->GetArea();
        newConferanceRoom["price"] = conferanceRoom->GetPrice();
        newConferanceRoom["chairsAmount"] = conferanceRoom->GetChairsAmount();
        nlohmann::json reservations = this->GetParsedReservations(conferanceRoom->GetReservations());
        newConferanceRoom["reservations"] = reservations;
        db["hotel"]["conferanceRooms"].push_back(newConferanceRoom);
    }
    for(auto storeRoom : this->hotel->GetStorerooms()){
        nlohmann::json newStoreRoom;
        newStoreRoom["name"] = storeRoom->GetName();
        newStoreRoom["area"] = storeRoom->GetArea();
        newStoreRoom["capacity"] = storeRoom->GetCapacity();
        newStoreRoom["occupied"] = storeRoom->GetOccupied();
        db["hotel"]["storerooms"].push_back(newStoreRoom);
    }
    std::fstream databaseFileSave;
    databaseFileSave.open("../../data/" + this->databaseFilename, std::fstream::out);
    databaseFileSave << db << std::endl;
}

nlohmann::json DatabaseSystem::GetParsedReservations(std::vector<std::shared_ptr<Reservation>> reservations){
    nlohmann::json newReservation;
    nlohmann::json parsedReservations;
    for(auto reservation : reservations){
        tm checkinTime = reservation->GetCheckinDate();
        tm checkoutTime = reservation->GetCheckoutDate();
        tm deadlineTime = reservation->GetPayment()->GetDeadline();
        newReservation["checkin"] = mktime(&checkinTime);
        newReservation["checkout"] = mktime(&checkoutTime);
        newReservation["payment"]["rental"] = reservation->GetPayment()->GetRental();
        newReservation["payment"]["deadline"] = mktime(&deadlineTime);
        parsedReservations.push_back(newReservation);
    }
    return parsedReservations;
}