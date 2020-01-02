#include "Reservation.h"
#include <stdexcept>

Reservation::Reservation(std::tm _checkin, std::tm _checkout, float _price)
: checkinDate(_checkin), checkoutDate(_checkout){
    this->payment = std::make_shared<Payment>(_price, _checkout);
}

Reservation::Reservation(std::tm _checkin, std::tm _checkout, float _price, std::tm _deadline)
: checkinDate(_checkin), checkoutDate(_checkout){
    this->payment = std::make_shared<Payment>(_price, _deadline);
}

std::tm Reservation::GetCheckinDate(){
    return this->checkinDate;
}

std::tm Reservation::GetCheckoutDate(){
    return this->checkoutDate;
}

void Reservation::SetCheckoutDate(std::tm newCheckoutDate){
    time_t checkinTime = mktime(&this->checkinDate);
    time_t checkoutTime = mktime(&this->checkoutDate);
    time_t newCheckoutTime = mktime(&newCheckoutDate);

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
    time_t currentTime = time(0);
    time_t endTime = mktime(&this->checkoutDate);
    return currentTime > endTime;
}