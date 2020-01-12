#ifndef HOTEL_VIEW_H
#define HOTEL_VIEW_H

#include <string>
#include <vector>
#include <memory>
#include "HotelController.h"
#include "FortLibrary/fort.h"
#include "FortLibrary/fort.hpp"


class HotelController;

class HotelView {
private:
    std::weak_ptr<HotelController> hotelController;
public:
    HotelView() = default;
    ~HotelView() = default;
    void SetController(std::shared_ptr<HotelController> controller);
    void DisplayAllReservations();
    void DisplayReservationInfo(fort::char_table& table, std::string id, std::string start, std::string finish, std::string toPay, std::string paymentDeadline);
};

#endif

