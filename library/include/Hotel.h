#ifndef HOTEL_H
#define HOTEL_H

#include <string>
#include <vector>
#include <memory>
#include "Room.h"

class Hotel {
private:
    std::string name;
    int stars;
    std::vector<std::shared_ptr<Room>> rooms;
public:
    Hotel(std::string _name, int _stars);
    ~Hotel() = default;
    std::string GetName();
    void SetName(std::string newName);
    int GetStarsAmount();
    void AddRoom(std::shared_ptr<Room> room);
    std::shared_ptr<Room> GetRoom(int roomId);
    std::vector<std::shared_ptr<Room>> GetRooms();
    int GetRoomsAmount(); 
};

#endif

