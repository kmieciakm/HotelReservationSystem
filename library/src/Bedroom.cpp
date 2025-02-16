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

void Bedroom::Reserve(std::tm checkinDate, int period, int number){
    if(period > MAX_RESERVATION_DAYS)
        throw std::logic_error("Too wide reservation period, you can reserve a room up to " + std::to_string(MAX_RESERVATION_DAYS) + " days");
    if(period <= 0)
        throw std::logic_error("Cannot handle negative days");
    if( IsFirstDateEarlier( checkinDate, GetCurrentTime() ) )
        throw std::logic_error("Reservation not possible in this term, please insert proper date");    
    
    std::tm checkoutDate = GetIncreasedDate(checkinDate, 0, period);
    if(this->IsFreeInTerm(checkinDate, checkoutDate)){
        std::string reservationId = "b" + std::to_string(number);
        std::shared_ptr<Reservation> newReservation = std::make_shared<Reservation>(checkinDate, checkoutDate, this->GetPrice() * period, reservationId);
        this->reservations.push_back( newReservation );
    }else{
        throw std::logic_error("Room already booked in this term");
    }
}