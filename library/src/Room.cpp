#include "Room.h"

Room::Room(std::string _name, float _area) 
: name(_name), area(_area) {}

std::string Room::GetName(){
    return this->name; 
}

void Room::SetName(std::string newName){
    this->name = newName;
}

float Room::GetArea(){
    return this->area;
}