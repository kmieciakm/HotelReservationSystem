#ifndef DATABASESYSTEM_H
#define DATABASESYSTEM_H

#include "Hotel.h"
#include "json.hpp"

class DatabaseSystem {
private:
    std::shared_ptr<Hotel> hotel;
    std::string databaseFilename;
    nlohmann::json GetSerializedReservations(std::vector<std::shared_ptr<Reservation>> reservations);
    std::vector<std::shared_ptr<Reservation>> GetDeserializedReservations(nlohmann::json reservationsJson);
    void Read();
public:
    DatabaseSystem(std::shared_ptr<Hotel> _hotel, std::string _path);
    DatabaseSystem(std::string _path);
    ~DatabaseSystem() = default;
    void SetPath(std::string newPath);
    std::shared_ptr<Hotel> GetHotelFromDatabase();
    void UpdateDatabase();
};

#endif
