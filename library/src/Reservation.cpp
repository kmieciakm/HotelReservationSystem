#include "Reservation.h"

Reservation::Reservation(std::tm _checkin, std::tm _checkout, float _price)
: checkinDate(_checkin), checkoutDate(_checkout) {
    this->payment = std::make_shared<Payment>(_price, _checkout);
}

std::tm Reservation::GetCheckinDate(){
    return this->checkinDate;
}

std::tm Reservation::GetCheckoutDate(){
    return this->checkoutDate;
}

void Reservation::SetCheckoutDate(std::tm newCheckoutDate){
    // missing implementation 
    return;
}

std::shared_ptr<Payment> Reservation::GetPayment(){
    return this->payment;
}