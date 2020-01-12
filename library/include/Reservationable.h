#ifndef RESERVATIONABLE_H
#define RESERVATIONABLE_H

#include <chrono>
#include <vector>
#include <memory>
#include "Room.h"
#include "Reservation.h"

class Reservationable : public Room {
protected:
    float price;
    std::vector<std::shared_ptr<Reservation>> reservations;
public:
    Reservationable(std::string _name, float _area, float _price);
    ~Reservationable() = default;
    float GetPrice();
    void SetPrice(float newPrice);
    void SetReservations(std::vector<std::shared_ptr<Reservation>> reservations);
    std::shared_ptr<Reservation> GetReservation(int id);
    std::vector<std::shared_ptr<Reservation>> GetReservations();
    int GetReservationsAmount();
    virtual void Reserve(std::tm checkInDate, int period, int number) = 0;
    bool IsFreeInTerm(std::tm start, std::tm end);
};

#endif
