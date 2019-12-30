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
    if( (newDeadline.tm_year < this->deadline.tm_year)
      || (newDeadline.tm_year == this->deadline.tm_year && newDeadline.tm_mon < this->deadline.tm_mon)
      || (newDeadline.tm_year == this->deadline.tm_year && newDeadline.tm_mon == this->deadline.tm_mon && newDeadline.tm_mday < this->deadline.tm_mday)
    )
        throw std::logic_error("Deadline cannot be regress");
    else
        this->deadline = newDeadline;
}

bool Payment::IsPaidUp(){
    return rental <= 0;
}

bool Payment::HasExpired(){
    time_t now = time(0);
    time ( &now );
    std::tm * currentTime = localtime ( &now );
    if ( (currentTime->tm_year > this->deadline.tm_year)
      || (currentTime->tm_year == this->deadline.tm_year && currentTime->tm_mon > this->deadline.tm_mon) 
      || (currentTime->tm_year == this->deadline.tm_year && currentTime->tm_mon == this->deadline.tm_mon && currentTime->tm_mday > this->deadline.tm_mday)
      || (currentTime->tm_year == this->deadline.tm_year && currentTime->tm_mon == this->deadline.tm_mon && currentTime->tm_mday == this->deadline.tm_mday && currentTime->tm_hour > this->deadline.tm_hour)  ){
        delete(currentTime);
        return true;
    }

    delete(currentTime);
    return false;
}