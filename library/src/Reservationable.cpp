#include "Reservationable.h"
#include <stdexcept>

Reservationable::Reservationable(std::string _name, float _area, float _price)
: Room(_name, _area), price(_price) {}

float Reservationable::GetPrice(){
    return this->price;
}

void Reservationable::SetPrice(float newPrice){
    if(newPrice > 0)
        this->price = newPrice;
    else
        throw std::out_of_range("Unexcepted non-positive price");
}