#ifndef CONFERANCE_ROOM_H
#define CONFERANCE_ROOM_H

#include "Reservationable.h"

constexpr int MAX_RESERVATION_HOURS = 12;

class ConferanceRoom : public Reservationable {
private:
    int chairsAmount;
public:
    ConferanceRoom(std::string _name, float _area, float _price, int _chairs);
    ~ConferanceRoom() = default;
    int GetChairsAmount();
    void SetChairsAmount(int newChairsAmount);
    virtual void Reserve(std::tm checkInDate, int period, int number) override;
};

#endif
