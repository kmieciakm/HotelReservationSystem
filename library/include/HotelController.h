#ifndef HOTEL_CONTROLLER_H
#define HOTEL_CONTROLLER_H

#include <string>
#include <vector>
#include <memory>
#include "Hotel.h"
#include "HotelView.h"
#include "DatabaseSystem.h"
#include "FortLibrary/fort.h"
#include "FortLibrary/fort.hpp"

class HotelView;

class HotelController {
private:
    std::shared_ptr<Hotel> hotel;
    std::shared_ptr<DatabaseSystem> databaseSystem;
    std::shared_ptr<HotelView> hotelView;
    int GenerateReservationNumber();
public:
    HotelController(std::shared_ptr<Hotel> _hotel, std::shared_ptr<DatabaseSystem> _db);
    ~HotelController() = default;
    void SetView(std::shared_ptr<HotelView> view);
    std::string GetTitle();
    std::string GetDatabaseInfo();
    void GetAllReservationsInfo(fort::char_table& table);
    void GetOverdueReservationsInfo(fort::char_table& table);
    void GetAllRooms(fort::char_table& table);
    void GetAllBedrooms(fort::char_table& table);
    void GetAllConferanceRooms(fort::char_table& table);
    void GetAllStorerooms(fort::char_table& table);
    void GetBedroomsUpTo(fort::char_table& table, float maxPrice);
    void GetFreeBedroomsAt(fort::char_table& table, std::tm start, std::tm end);
    void GetFreeConferanceRoomsAt(fort::char_table& table, std::tm start, std::tm end);
    void HandlePayment(fort::char_table& table, std::string reservationId, float sum);
    void HandleReservation(fort::char_table& table, std::string roomName, tm start, int period);
    void HandleLoad(fort::char_table& table, std::string roomName, float amount);
    void HandleUnload(fort::char_table& table, std::string roomName, float amount);
};

#endif

