#ifndef HOTEL_VIEW_H
#define HOTEL_VIEW_H

#include <string>
#include <vector>
#include <memory>
#include <bits/stdc++.h>
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
    void DisplayErrorMessage(std::string error);
    void DisplayTitle();
    void DisplayDatabaseInfo();
    void DisplayAllReservations();
    void DisplayOverdueReservations();
    void DisplayReservationInfo(fort::char_table& table, std::string id, std::string start, std::string finish, std::string toPay, std::string paymentDeadline);
    void DisplayAllRooms();
    void DisplayRoomInfo(fort::char_table& table, std::string name, std::string area, std::string type);
    void DisplayAllBedrooms();
    void DisplayBedroomsUpTo(float maxPrice);
    void DisplayFreeBedroomsAt(std::tm start, std::tm end);
    void DisplayFreeConferanceRoomsAt(std::tm start, std::tm end);
    void DisplayBedroomInfo(fort::char_table& table, std::string name, std::string area, std::string bedsAmount, std::string price, std::string reservationsAmount);
    void DisplayConferanceRoomInfo(fort::char_table& table, std::string name, std::string area, std::string chairsAmount, std::string price, std::string reservationsAmount);
    void DisplayPaymentMenu();
    void ClearScreen();
    void MainMenu();
};

#endif

