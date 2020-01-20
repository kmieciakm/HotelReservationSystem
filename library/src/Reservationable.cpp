#include "Reservationable.h"
#include "Functions.h"
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

void Reservationable::SetReservations(std::vector<std::shared_ptr<Reservation>> reservations){
    this->reservations = reservations;
}

bool Reservationable::IsFreeInTerm(std::tm start, std::tm end){
    std::time_t startTime = mkgmtime(&start);
    std::time_t endTime = mkgmtime(&end);

    for(auto reservation : this->reservations){
        std::tm checkinDate = reservation->GetCheckinDate();
        std::tm checkoutDate = reservation->GetCheckoutDate();
        std::time_t reservationBegining = mkgmtime(&checkinDate);
        std::time_t reservationEnd = mkgmtime(&checkoutDate);
        
        if( (startTime < reservationBegining && endTime > reservationBegining)
            || (startTime >= reservationBegining && startTime <= reservationEnd) ){
            return false;
        }
    }
    return true;
}

std::shared_ptr<Reservation> Reservationable::GetReservation(std::string id){
    for(auto reservation : this->GetReservations()){
        if(reservation->GetReservationId() == id)
            return reservation;
    }
    throw std::logic_error("Reservation " + id + " not found");
};

std::vector<std::shared_ptr<Reservation>> Reservationable::GetReservations(){
    return this->reservations;
}

int Reservationable::GetReservationsAmount(){
    return this->reservations.size();
};