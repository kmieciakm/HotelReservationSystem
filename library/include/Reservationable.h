#ifndef RESERVATIONABLE_H
#define RESERVATIONABLE_H

#include <chrono>
#include <vector>
#include <memory>
#include "Room.h"
#include "Reservation.h"

class Reservationable : public Room {
private:
    float price;
    std::vector<std::shared_ptr<Reservation>> reservations;
public:
    Reservationable(std::string _name, float _area, float _price);
    ~Reservationable() = default;
    float GetPrice();
    void SetPrice(float newPrice);
    virtual void Reserve(std::tm checkInDate, int period) = 0;
};

#endif
