#include "Bedroom.h"
#include <stdexcept>

Bedroom::Bedroom(std::string _name, float _area, float _price, int _beds)
: Reservationable(_name, _area, _price), bedsAmount(_beds) {}

int Bedroom::GetBedsAmount(){
    return this->bedsAmount;
}

void Bedroom::SetBedsAmount(int newBedsAmount){
    if(newBedsAmount > 0)
        this->bedsAmount = newBedsAmount;
    else
        throw std::out_of_range("Unexcepted non-positive beds amount");
}

void Bedroom::Reserve(std::tm checkInDate, int period){
    // missing implementation !!!!!!!!!!
    return;
}