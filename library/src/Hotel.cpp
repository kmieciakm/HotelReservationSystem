#include "Hotel.h"

Hotel::Hotel(std::string _name, int _stars) 
: name(_name), stars(_stars) {}

std::string Hotel::GetName(){
    return this->name; 
}

void Hotel::SetName(std::string newName){
    this->name = newName;
}

int Hotel::GetStarsAmount(){
    return this->stars;
}

void Hotel::AddStoreroom(std::shared_ptr<Storeroom> storeroom){
    this->storeRooms.push_back(storeroom);
}

std::shared_ptr<Storeroom> Hotel::GetStoreroom(int roomId){
    if(roomId >= this->storeRooms.size() || roomId < 0)
        throw std::out_of_range("Bad room id");
    return this->storeRooms.at(roomId);
}

std::vector<std::shared_ptr<Storeroom>> Hotel::GetStorerooms(){
    return this->storeRooms;
}

int Hotel::GetStoreroomsAmount(){
    return this->storeRooms.size();
}

void Hotel::AddBedroom(std::shared_ptr<Bedroom> bedroom){
    this->bedrooms.push_back(bedroom);
};

std::shared_ptr<Bedroom> Hotel::GetBedroom(int roomId){
    if(roomId >= this->bedrooms.size() || roomId < 0)
        throw std::out_of_range("Bad room id");
    return this->bedrooms.at(roomId);
};

std::vector<std::shared_ptr<Bedroom>> Hotel::GetBedrooms(){
    return this->bedrooms;
}

int Hotel::GetBedroomsAmount(){
    return this->bedrooms.size();
}

void Hotel::AddConferanceRoom(std::shared_ptr<ConferanceRoom> conferanceRoom){
    this->conferanceRooms.push_back(conferanceRoom);
};

std::shared_ptr<ConferanceRoom> Hotel::GetConferanceRoom(int roomId){
    if(roomId >= this->conferanceRooms.size() || roomId < 0)
        throw std::out_of_range("Bad room id");
    return this->conferanceRooms.at(roomId);
};

std::vector<std::shared_ptr<ConferanceRoom>> Hotel::GetConferanceRooms(){
    return this->conferanceRooms;
}

int Hotel::GetConferanceRoomsAmount(){
    return this->conferanceRooms.size();
}