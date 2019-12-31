#ifndef ROOM_H
#define ROOM_H

#include <string>

class Room {
protected:
    std::string name;
    float area;
public:
    Room(std::string _name, float _area);
    ~Room() = default;
    std::string GetName();
    void SetName(std::string name);
    float GetArea();
};

#endif
