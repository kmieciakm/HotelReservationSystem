#include "ConferanceRoom.h"
#include <stdexcept>

ConferanceRoom::ConferanceRoom(std::string _name, float _area, float _price, int _capacity)
: Reservationable(_name, _area, _price), capacity(_capacity) {}

int ConferanceRoom::GetCapacity(){
    return this->capacity;
}

void ConferanceRoom::SetCapacity(int newCapacity){
    if(newCapacity > 0)
        this->capacity = newCapacity;
    else
        throw std::out_of_range("Unexcepted non-positive capacity");
}

void ConferanceRoom::Reserve(std::tm checkInDate, int period){
    // missing implementation !!!!!!!!!!
    return;
}