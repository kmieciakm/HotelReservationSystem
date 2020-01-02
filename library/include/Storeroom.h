#ifndef STOREROOM_H
#define STOREROOM_H

#include "Room.h"

class Storeroom : public Room{
private:
    float capacity;
    float occupied;
public:
    Storeroom(std::string _name, int _area, float _capacity);
    ~Storeroom() = default;
    float GetCapacity();
    float GetOccupied();
    void Load(float stuff);
    void Unload(float stuff);
    bool IsFull();
};

#endif