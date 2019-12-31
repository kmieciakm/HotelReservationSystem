#ifndef STOREROOM_H
#define STOREROOM_H

class Storeroom {
private:
    float capacity;
    float occupied;
public:
    Storeroom(float _capacity);
    ~Storeroom() = default;
    float GetCapacity();
    float GetOccupied();
    void Load(float stuff);
    void Unload(float stuff);
    bool IsFull();
};

#endif