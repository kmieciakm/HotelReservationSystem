#ifndef RESERVATION_H
#define RESERVATION_H

#include <memory>
#include "Payment.h"

class Reservation {
private:
    std::tm checkinDate;
    std::tm checkoutDate;
    std::shared_ptr<Payment> payment;
    std::string reservationId;
public:
    Reservation(std::tm _checkin, std::tm _checkout, float _price, std::string _reservationId);
    Reservation(std::tm _checkin, std::tm _checkout, float _price, std::tm _deadline, std::string _reservationId);
    ~Reservation() = default;
    std::string GetReservationId();
    std::tm GetCheckinDate();
    std::tm GetCheckoutDate();
    void SetCheckoutDate(std::tm newCheckoutDate);
    std::shared_ptr<Payment> GetPayment();
    bool HasPassed();
};

#endif
