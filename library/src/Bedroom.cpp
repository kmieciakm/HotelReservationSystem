#include "Bedroom.h"
#include "Functions.h"
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

void Bedroom::Reserve(std::tm checkinDate, int period){
    if(period > MAX_RESERVATION_DAYS)
        throw std::logic_error("Too wide reservation period, you can reserve a room up to " + std::to_string(MAX_RESERVATION_DAYS) + " days");
    
    std::tm checkoutDate = GetIncreasedDate(checkinDate, 0, period, 0, 0);
    if(this->IsFreeInTerm(checkinDate, checkoutDate)){
        std::shared_ptr<Reservation> newReservation = std::make_shared<Reservation>(checkinDate, checkoutDate, this->GetPrice());
        this->reservations.push_back( newReservation );
    }else{
        throw std::logic_error("Room already booked in this term");
    }
}