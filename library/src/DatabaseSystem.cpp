#include "DatabaseSystem.h"
#include "json.hpp"
#include "stdexcept"
#include "functions.h"
#include <fstream>
#include <iostream>

DatabaseSystem::DatabaseSystem(std::shared_ptr<Hotel> _hotel, std::string _path)
: hotel(_hotel), databaseFilename(_path) {}

DatabaseSystem::DatabaseSystem(std::string _path)
: hotel(nullptr), databaseFilename(_path) {}

std::shared_ptr<Hotel> DatabaseSystem::GetHotelFromDatabase(){
    UpdateHotel();
    this->lastUpdate = GetCurrentTime();
    return this->hotel;
}

void DatabaseSystem::SetPath(std::string newPath){
    this->databaseFilename = newPath;
}

std::tm DatabaseSystem::GetLastUpdate(){
    return this->lastUpdate;
}

void DatabaseSystem::UpdateHotel(){
    std::fstream databaseFile;
    databaseFile.open("../../data/" + this->databaseFilename, std::fstream::in);
    if( databaseFile.good() == true ){
        nlohmann::json db;
        databaseFile >> db;
        this->hotel = std::make_shared<Hotel>(db["hotel"]["name"], db["hotel"]["stars"]);
        for(auto room : db["hotel"]["bedrooms"]){
            std::shared_ptr<Bedroom> roomObj = std::make_shared<Bedroom>(room["name"], room["area"], room["price"], room["bedsAmount"]);
            if(!room["reservations"].is_null())
                roomObj->SetReservations(GetDeserializedReservations(room["reservations"]));
            hotel->AddBedroom(roomObj);
        }
        for(auto room : db["hotel"]["conferanceRooms"]){
            std::shared_ptr<ConferanceRoom> roomObj = std::make_shared<ConferanceRoom>(room["name"], room["area"], room["price"], room["chairsAmount"]);
            if(!room["reservations"].is_null())
                roomObj->SetReservations(GetDeserializedReservations(room["reservations"]));
            hotel->AddConferanceRoom(roomObj);
        }
        for(auto room : db["hotel"]["storerooms"]){
            std::shared_ptr<Storeroom> roomObj = std::make_shared<Storeroom>(room["name"], room["area"], room["capacity"], room["occupied"]);
            hotel->AddStoreroom(roomObj);
        }
    } else {
        throw std::invalid_argument("File " + this->databaseFilename + " not found");
    }
    databaseFile.close();
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
        nlohmann::json reservations = this->GetSerializedReservations(bedroom->GetReservations());
        newBedroom["reservations"] = reservations;
        db["hotel"]["bedrooms"].push_back(newBedroom);
    }
    for(auto conferanceRoom : this->hotel->GetConferanceRooms()){
        nlohmann::json newConferanceRoom;
        newConferanceRoom["name"] = conferanceRoom->GetName();
        newConferanceRoom["area"] = conferanceRoom->GetArea();
        newConferanceRoom["price"] = conferanceRoom->GetPrice();
        newConferanceRoom["chairsAmount"] = conferanceRoom->GetChairsAmount();
        nlohmann::json reservations = this->GetSerializedReservations(conferanceRoom->GetReservations());
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
    std::fstream databaseFile;
    databaseFile.open("../../data/" + this->databaseFilename, std::fstream::out);
    databaseFile << db << std::endl;
    databaseFile.close();
}

nlohmann::json DatabaseSystem::GetSerializedReservations(std::vector<std::shared_ptr<Reservation>> reservations){
    nlohmann::json newReservation;
    nlohmann::json parsedReservations;
    for(auto reservation : reservations){
        tm checkinDate = reservation->GetCheckinDate();
        tm checkoutDate = reservation->GetCheckoutDate();
        tm deadlineDate = reservation->GetPayment()->GetDeadline();
        newReservation["checkin"] = mktime(&checkinDate);
        newReservation["checkout"] = mktime(&checkoutDate);
        newReservation["id"] = reservation->GetReservationId();
        newReservation["payment"]["rental"] = reservation->GetPayment()->GetRental();
        newReservation["payment"]["deadline"] = mktime(&deadlineDate);
        parsedReservations.push_back(newReservation);
    }
    return parsedReservations;
}

std::vector<std::shared_ptr<Reservation>> DatabaseSystem::GetDeserializedReservations(nlohmann::json reservationsJson){
    std::shared_ptr<Reservation> newReservation;
    std::vector<std::shared_ptr<Reservation>> reservations;
    for(auto reservation : reservationsJson){
        time_t checkinDate = reservation["checkin"];
        tm checkinTime = *localtime(&checkinDate);
        time_t checkoutDate = reservation["checkout"];
        tm checkoutTime = *localtime(&checkoutDate);
        float rental = reservation["payment"]["rental"];
        time_t deadlineDate = reservation["payment"]["deadline"];
        tm deadlineTime = *localtime(&deadlineDate);
        std::string reservationId = reservation["id"];
        newReservation = std::make_shared<Reservation>(checkinTime, checkoutTime, rental, deadlineTime, reservationId);
        reservations.push_back(newReservation);
    }
    return reservations;
}