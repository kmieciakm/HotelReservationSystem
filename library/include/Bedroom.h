#ifndef BEDROOM_H
#define BEDROOM_H

#include "Reservationable.h"

constexpr int MAX_RESERVATION_DAYS = 30;

class Bedroom : public Reservationable {
private:
    int bedsAmount;
public:
    Bedroom(std::string _name, float _area, float _price, int _beds);
    ~Bedroom() = default;
    int GetBedsAmount();
    void SetBedsAmount(int newBedsAmount);
    virtual void Reserve(std::tm checkInDate, int period, int number) final;
};

#endif
