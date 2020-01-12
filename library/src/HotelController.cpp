#include "HotelController.h"
#include <iostream>
#include "Functions.h"

HotelController::HotelController(std::shared_ptr<Hotel> _hotel, std::shared_ptr<DatabaseSystem> _db)
: hotel(_hotel), databaseSystem(_db) {}

void HotelController::SetView(std::shared_ptr<HotelView> view){
    this->hotelView = view;
}

std::string HotelController::GetTitle(){
    std::string hotelTitle;
    hotelTitle = this->hotel->GetName() + " ";
    for(int i=0; i<this->hotel->GetStarsAmount(); i++)
        hotelTitle += "*";
   return hotelTitle;
}

void HotelController::GetAllReservationsInfo(fort::char_table& table){
    std::vector<std::shared_ptr<Reservation>> allReservations = this->hotel->GetAllReservations();

    for(std::shared_ptr<Reservation> reservation : allReservations){
        this->hotelView->DisplayReservationInfo(
            table,
            reservation->GetReservationId(),
            DateToString(reservation->GetCheckinDate()),
            DateToString(reservation->GetCheckoutDate()),
            std::to_string(reservation->GetPayment()->GetRental()),
            DateToString(reservation->GetPayment()->GetDeadline())
        );
    }
}


void HotelController::GetOverdueReservationsInfo(fort::char_table& table){
    std::vector<std::shared_ptr<Reservation>> allReservations = this->hotel->GetAllReservations();

    for(std::shared_ptr<Reservation> reservation : allReservations){
        if( IsFirstDateEarlier( reservation->GetPayment()->GetDeadline(), GetCurrentTime() ) ){
            this->hotelView->DisplayReservationInfo(
                table,
                reservation->GetReservationId(),
                DateToString(reservation->GetCheckinDate()),
                DateToString(reservation->GetCheckoutDate()),
                std::to_string(reservation->GetPayment()->GetRental()),
                DateToString(reservation->GetPayment()->GetDeadline())
            );
        }
    }
}

void HotelController::GetAllRooms(fort::char_table& table){
    for(std::shared_ptr<Bedroom> bedroom : this->hotel->GetBedrooms()){
        this->hotelView->DisplayRoomInfo(
            table,
            bedroom->GetName(),
            std::to_string(bedroom->GetArea()),
            "Bedroom"
        );
    }
    for(std::shared_ptr<ConferanceRoom> conferanceRoom : this->hotel->GetConferanceRooms()){
        this->hotelView->DisplayRoomInfo(
            table,
            conferanceRoom->GetName(),
            std::to_string(conferanceRoom->GetArea()),
            "Conferance Room"
        );
    }
    for(std::shared_ptr<Storeroom> storeroom : this->hotel->GetStorerooms()){
        this->hotelView->DisplayRoomInfo(
            table,
            storeroom->GetName(),
            std::to_string(storeroom->GetArea()),
            "Store Room"
        );
    }
}

void HotelController::GetAllBedrooms(fort::char_table& table){
    for(std::shared_ptr<Bedroom> bedroom : this->hotel->GetBedrooms()){
        this->hotelView->DisplayBedroomInfo(
            table,
            bedroom->GetName(),
            std::to_string(bedroom->GetArea()),
            std::to_string(bedroom->GetBedsAmount()),
            std::to_string(bedroom->GetPrice()),
            std::to_string(bedroom->GetReservationsAmount())
        );
    }
}

void HotelController::GetBedroomsUpTo(fort::char_table& table, float maxPrice){
    for(std::shared_ptr<Bedroom> bedroom : this->hotel->GetBedrooms()){
        if( bedroom->GetPrice() <= maxPrice){
            this->hotelView->DisplayBedroomInfo(
                table,
                bedroom->GetName(),
                std::to_string(bedroom->GetArea()),
                std::to_string(bedroom->GetBedsAmount()),
                std::to_string(bedroom->GetPrice()),
                std::to_string(bedroom->GetReservationsAmount())
            );
        }
    }
}

void HotelController::GetFreeBedroomsAt(fort::char_table& table, std::tm start, std::tm end){
    for(std::shared_ptr<Bedroom> bedroom : this->hotel->GetBedrooms()){
        if( bedroom->IsFreeInTerm(start, end) ){
            this->hotelView->DisplayBedroomInfo(
                table,
                bedroom->GetName(),
                std::to_string(bedroom->GetArea()),
                std::to_string(bedroom->GetBedsAmount()),
                std::to_string(bedroom->GetPrice()),
                std::to_string(bedroom->GetReservationsAmount())
            );
        }
    }
}

void HotelController::GetFreeConferanceRoomsAt(fort::char_table& table, std::tm start, std::tm end){
    for(std::shared_ptr<ConferanceRoom> corpoRoom : this->hotel->GetConferanceRooms()){
        if( corpoRoom->IsFreeInTerm(start, end) ){
            this->hotelView->DisplayConferanceRoomInfo(
                table,
                corpoRoom->GetName(),
                std::to_string(corpoRoom->GetArea()),
                std::to_string(corpoRoom->GetChairsAmount()),
                std::to_string(corpoRoom->GetPrice()),
                std::to_string(corpoRoom->GetReservationsAmount())
            );
        }
    }
}