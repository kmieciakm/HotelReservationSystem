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

void Hotel::AddRoom(std::shared_ptr<Room> room){
    this->rooms.push_back(room);
}

std::shared_ptr<Room> Hotel::GetRoom(int roomId){
    if(roomId >= this->rooms.size() || roomId < 0)
        throw std::out_of_range("Bad room id");
    return this->rooms.at(roomId);
}

std::vector<std::shared_ptr<Room>> Hotel::GetRooms(){
    return this->rooms;
}

int Hotel::GetRoomsAmount(){
    return this->rooms.size();
}