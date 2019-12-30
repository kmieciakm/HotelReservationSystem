#ifndef BEDROOM_H
#define BEDROOM_H

#include <Reservationable.h>

class Bedroom : public Reservationable{
private:
    int bedsAmount;
public:
    Bedroom(std::string _name, float _area, float _price, int _beds);
    ~Bedroom() = default;
    int GetBedsAmount();
    void SetBedsAmount(int newBedsAmount);
    void Reserve(std::tm checkInDate, int period) override;
};

#endif
