#include "Payment.h"
#include <stdexcept>

Payment::Payment(float _rental, std::tm _deadline)
: rental(_rental), deadline(_deadline) {}

float Payment::GetRental(){
    return this->rental;
}

std::tm Payment::GetDeadline(){
    return this->deadline;
}

void Payment::SetDeadline(std::tm newDeadline){
    time_t newDeadlineTime = mktime(&newDeadline);
    time_t deadlineTime = mktime(&this->deadline);

    if(deadlineTime < newDeadlineTime)
        throw std::logic_error("Deadline cannot be regress");
    else
        this->deadline = newDeadline;
}

bool Payment::IsPaidUp(){
    return rental <= 0;
}

bool Payment::HasExpired(){
    time_t currentTime = time(0);
    time_t deadlineTime = mktime(&this->deadline);
    return currentTime > deadlineTime;
}