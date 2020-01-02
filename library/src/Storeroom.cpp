#include "Storeroom.h"
#include <stdexcept>

Storeroom::Storeroom(std::string _name, int _area, float _capacity) 
: Room(_name, _area), capacity(_capacity), occupied(0.0) {}

float Storeroom::GetCapacity(){
    return this->capacity; 
}

float Storeroom::GetOccupied(){
    return this->occupied;
}

void Storeroom::Load(float stuff){
    if(stuff < 0){
        throw std::logic_error("Cannot load negative values");
    }else if(this->occupied + stuff <= this->capacity){
        this->occupied += stuff;
    } else {
        throw std::out_of_range("Not enought space in storeroom");
    }
}

void Storeroom::Unload(float stuff){
    if(stuff < 0){
        throw std::logic_error("Cannot unload negative values");
    }else if(this->occupied - stuff >= 0){
        this->occupied -= stuff;
    } else {
        throw std::out_of_range("No so many stuff in storeroom");
    }
}

bool Storeroom::IsFull(){
    return occupied >= capacity;
}