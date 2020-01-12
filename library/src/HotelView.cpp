#include "HotelView.h"
#include <iostream>
#include "Functions.h"

void HotelView::SetController(std::shared_ptr<HotelController> controller){
    this->hotelController = controller;
}

void HotelView::DisplayErrorMessage(std::string error){
    std::cout << "Sorry, but ..." << std::endl << error << std::endl;
}

void HotelView::DisplayMainPage(){
    fort::char_table table;
    table.set_border_style(FT_SOLID_STYLE);
    table << fort::header
        << this->hotelController.lock()->GetTitle() << fort::endr;
    table.column(0).set_cell_text_align(fort::text_align::center);

    std::cout << table.to_string() << std::endl;
}

void HotelView::DisplayAllReservations(){
    fort::char_table table;
    table.set_border_style(FT_SOLID_STYLE);

    table << fort::header
        << "Reservation Id" << "Checkin Date" << "Checkout Date" << "Renting" << "Payment Deadline" << fort::endr;
    this->hotelController.lock()->GetAllReservationsInfo(table);

    std::cout << "All reservations" << std::endl;
    std::cout << table.to_string() << std::endl;
}

void HotelView::DisplayOverdueReservations(){
    fort::char_table table;
    table.set_border_style(FT_SOLID_STYLE);

    table << fort::header
        << "Reservation Id" << "Checkin Date" << "Checkout Date" << "Renting" << "Payment Deadline" << fort::endr;
    this->hotelController.lock()->GetOverdueReservationsInfo(table);

    std::cout << "Overdue Payments" << std::endl;
    std::cout << "Current time: " << DateToString( GetCurrentTime() ) << std::endl;
    std::cout << table.to_string() << std::endl;
}

void HotelView::DisplayReservationInfo(fort::char_table& table, std::string id, std::string start, std::string finish, std::string toPay, std::string paymentDeadline){
    table << id << start << finish << toPay << paymentDeadline << fort::endr;
}

void HotelView::DisplayAllRooms(){
    fort::char_table table;
    table.set_border_style(FT_SOLID_STYLE);

    table << fort::header
        << "Room name" << "Area" << "Type" << fort::endr;
    this->hotelController.lock()->GetAllRooms(table);

    std::cout << "All rooms" << std::endl;
    std::cout << table.to_string() << std::endl;
}

void HotelView::DisplayAllBedrooms(){
    fort::char_table table;
    table.set_border_style(FT_SOLID_STYLE);

    table << fort::header
        << "Room name" << "Area" << "Beds" << "Price(per day)" << "Reservations Amount" << fort::endr;
    this->hotelController.lock()->GetAllBedrooms(table);

    std::cout << "All ours bedrooms" << std::endl;
    std::cout << table.to_string() << std::endl;
}

void HotelView::DisplayBedroomsUpTo(float maxPrice){
    fort::char_table table;
    table.set_border_style(FT_SOLID_STYLE);

    table << fort::header
        << "Room name" << "Area" << "Beds" << "Price(per day)" << "Reservations Amount" << fort::endr;
    this->hotelController.lock()->GetBedroomsUpTo(table, maxPrice);

    std::cout << "Bedrooms with max price equal " << std::to_string(maxPrice) << std::endl;
    std::cout << table.to_string() << std::endl;
}

void HotelView::DisplayFreeBedroomsAt(std::tm start, std::tm end){
    fort::char_table table;
    table.set_border_style(FT_SOLID_STYLE);

    table << fort::header
        << "Room name" << "Area" << "Beds" << "Price(per day)" << "Reservations Amount" << fort::endr;
    this->hotelController.lock()->GetFreeBedroomsAt(table, start, end);

    std::cout << "Bedrooms free from: " << DateToString(start) << " to " << DateToString(end) << std::endl;
    std::cout << table.to_string() << std::endl;
}

void HotelView::DisplayFreeConferanceRoomsAt(std::tm start, std::tm end){
    fort::char_table table;
    table.set_border_style(FT_SOLID_STYLE);

    table << fort::header
        << "Room name" << "Area" << "Places" << "Price(per day)" << "Reservations Amount" << fort::endr;
    this->hotelController.lock()->GetFreeConferanceRoomsAt(table, start, end);

    std::cout << "Conferance rooms free from: " << DateToString(start) << " to " << DateToString(end) << std::endl;
    std::cout << table.to_string() << std::endl;
}

void HotelView::DisplayBedroomInfo(fort::char_table& table, std::string name, std::string area, std::string bedsAmount, std::string price, std::string reservationsAmount){
    table << name << area << bedsAmount << price << reservationsAmount << fort::endr;
}

void HotelView::DisplayConferanceRoomInfo(fort::char_table& table, std::string name, std::string area, std::string chairsAmount, std::string price, std::string reservationsAmount){
    table << name << area << chairsAmount << price << reservationsAmount << fort::endr;
}

void HotelView::DisplayRoomInfo(fort::char_table& table, std::string name, std::string area, std::string type){
    table << name << area << type << fort::endr;
}