#include "ConferanceRoom.h"
#include "Functions.h" 
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

void ConferanceRoom::Reserve(std::tm checkinDate, int period){
    if(period > MAX_RESERVATION_HOURS)
        throw std::logic_error("Too wide reservation period, you can reserve a conferance room up to " + std::to_string(MAX_RESERVATION_HOURS) + " hours");
    
    std::tm checkoutDate = GetIncreasedDate(checkinDate, period, 0, 0, 0);
    if(this->IsFreeInTerm(checkinDate, checkoutDate)){
        std::shared_ptr<Reservation> newReservation = std::make_shared<Reservation>(checkinDate, checkoutDate, this->GetPrice());
        this->reservations.push_back( newReservation );
    }else{
        throw std::logic_error("Conferance room already booked in those hours");
    }
}