#include "HotelView.h"
#include <iostream>

void HotelView::SetController(std::shared_ptr<HotelController> controller){
    this->hotelController = controller;
}

void HotelView::DisplayAllReservations(){
    fort::char_table table;
    table.set_border_style(FT_SOLID_STYLE);

    table << fort::header
        << "Reservation Id" << "Checkin Date" << "Checkout Date" << "Renting" << "Payment Deadline" << fort::endr;
    this->hotelController.lock()->GetAllReservationsInfo(table);

    std::cout << table.to_string() << std::endl;
}

void HotelView::DisplayReservationInfo(fort::char_table& table, std::string id, std::string start, std::string finish, std::string toPay, std::string paymentDeadline){
    table << id << start << finish << toPay << paymentDeadline << fort::endr;
}