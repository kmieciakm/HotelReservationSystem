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
public:
    HotelController(std::shared_ptr<Hotel> _hotel, std::shared_ptr<DatabaseSystem> _db);
    ~HotelController() = default;
    void SetView(std::shared_ptr<HotelView> view);
    void GetAllReservationsInfo(fort::char_table& table);
};

#endif

