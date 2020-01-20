#include "Reservation.h"
#include "Functions.h"
#include <stdexcept>

Reservation::Reservation(std::tm _checkin, std::tm _checkout, float _price, std::string _reservationId)
: checkinDate(_checkin), checkoutDate(_checkout), reservationId(_reservationId){
    this->payment = std::make_shared<Payment>(_price, _checkout);
}

Reservation::Reservation(std::tm _checkin, std::tm _checkout, float _price, std::tm _deadline, std::string _reservationId)
: checkinDate(_checkin), checkoutDate(_checkout), reservationId(_reservationId){
    this->payment = std::make_shared<Payment>(_price, _deadline);
}

std::tm Reservation::GetCheckinDate(){
    return this->checkinDate;
}

std::tm Reservation::GetCheckoutDate(){
    return this->checkoutDate;
}

std::string Reservation::GetReservationId(){
    return this->reservationId;
}

void Reservation::SetCheckoutDate(std::tm newCheckoutDate){
    std::time_t checkinTime = mkgmtime(&this->checkinDate);
    std::time_t checkoutTime = mkgmtime(&this->checkoutDate);
    std::time_t newCheckoutTime = mkgmtime(&newCheckoutDate);

    if(newCheckoutTime < checkinTime)
        throw std::logic_error("Checkout date not valid, prior then checkin");
    else if (this->HasPassed())
        throw std::logic_error("Cannot change checkout date, reservation has already passed");
    else
        this->checkoutDate = newCheckoutDate;
}

std::shared_ptr<Payment> Reservation::GetPayment(){
    return this->payment;
}

bool Reservation::HasPassed(){
    std::time_t currentTime = time(0);
    std::time_t endTime = mkgmtime(&this->checkoutDate);
    return currentTime > endTime;
}