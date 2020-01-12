#include "ConferanceRoom.h"
#include "Functions.h" 
#include <stdexcept>

ConferanceRoom::ConferanceRoom(std::string _name, float _area, float _price, int _chairs)
: Reservationable(_name, _area, _price), chairsAmount(_chairs) {}

int ConferanceRoom::GetChairsAmount(){
    return this->chairsAmount;
}

void ConferanceRoom::SetChairsAmount(int newChairsAmount){
    if(newChairsAmount > 0)
        this->chairsAmount = newChairsAmount;
    else
        throw std::out_of_range("Unexcepted non-positive capacity");
}

void ConferanceRoom::Reserve(std::tm checkinDate, int period, int number){
    if(period > MAX_RESERVATION_HOURS)
        throw std::logic_error("Too wide reservation period, you can reserve a conferance room up to " + std::to_string(MAX_RESERVATION_HOURS) + " hours");
    
    std::tm checkoutDate = GetIncreasedDate(checkinDate, period, 0);
    if(this->IsFreeInTerm(checkinDate, checkoutDate)){
        std::string reservationId = "c" + std::to_string(number);
        std::shared_ptr<Reservation> newReservation = std::make_shared<Reservation>(checkinDate, checkoutDate, this->GetPrice() * period, reservationId);
        this->reservations.push_back( newReservation );
    }else{
        throw std::logic_error("Conferance room already booked in those hours");
    }
}