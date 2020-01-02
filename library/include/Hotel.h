#ifndef HOTEL_H
#define HOTEL_H

#include <string>
#include <vector>
#include <memory>
#include "Storeroom.h"
#include "Bedroom.h"
#include "ConferanceRoom.h"
#include "Room.h"

class Hotel {
private:
    std::string name;
    int stars;
    std::vector<std::shared_ptr<Bedroom>> bedrooms;
    std::vector<std::shared_ptr<ConferanceRoom>> conferanceRooms;
    std::vector<std::shared_ptr<Storeroom>> storeRooms;
public:
    Hotel(std::string _name, int _stars);
    ~Hotel() = default;
    void SetName(std::string newName);
    std::string GetName();
    int GetStarsAmount();
    void AddConferanceRoom(std::shared_ptr<ConferanceRoom> conferanceroom);
    void AddBedroom(std::shared_ptr<Bedroom> bedroom);
    void AddStoreroom(std::shared_ptr<Storeroom> storeroom);
    std::shared_ptr<ConferanceRoom> GetConferanceRoom(int roomId);
    std::shared_ptr<Storeroom> GetStoreroom(int roomId);
    std::shared_ptr<Bedroom> GetBedroom(int roomId);
    std::vector<std::shared_ptr<ConferanceRoom>> GetConferanceRooms();
    std::vector<std::shared_ptr<Storeroom>> GetStorerooms();
    std::vector<std::shared_ptr<Bedroom>> GetBedrooms();
    int GetConferanceRoomsAmount();
    int GetBedroomsAmount();
    int GetStoreroomsAmount();
};

#endif

