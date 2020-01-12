#include "HotelController.h"
#include <iostream>
#include "Functions.h"

HotelController::HotelController(std::shared_ptr<Hotel> _hotel, std::shared_ptr<DatabaseSystem> _db)
: hotel(_hotel), databaseSystem(_db) {}

void HotelController::SetView(std::shared_ptr<HotelView> view){
    this->hotelView = view;
}

void HotelController::GetAllReservationsInfo(fort::char_table& table){
    std::vector<std::shared_ptr<Reservation>> allReservations; 
    for(std::shared_ptr<ConferanceRoom> cRoom : this->hotel->GetConferanceRooms()){
        for(std::shared_ptr<Reservation> reservation : cRoom->GetReservations()){
            allReservations.push_back(reservation);
        }
    }
    for(std::shared_ptr<Bedroom> bRoom : this->hotel->GetBedrooms()){
        for(std::shared_ptr<Reservation> reservation : bRoom->GetReservations()){
            allReservations.push_back(reservation);
        }
    }

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