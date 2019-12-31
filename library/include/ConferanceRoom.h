#ifndef CONFERANCE_ROOM_H
#define CONFERANCE_ROOM_H

#include <Reservationable.h>

constexpr int MAX_RESERVATION_HOURS = 12;

class ConferanceRoom : public Reservationable {
private:
    int capacity;
public:
    ConferanceRoom(std::string _name, float _area, float _price, int _capacity);
    ~ConferanceRoom() = default;
    int GetCapacity();
    void SetCapacity(int newCapacity);
    void Reserve(std::tm checkInDate, int period) override;
};

#endif
