#include "HotelView.h"
#include <iostream>
#include "Functions.h"

void HotelView::SetController(std::shared_ptr<HotelController> controller){
    this->hotelController = controller;
}

void HotelView::DisplayErrorMessage(std::string error){
    std::cout << "Sorry, but ..." << std::endl << error << std::endl;
}

void HotelView::DisplayTitle(){
    fort::char_table table;
    table.set_border_style(FT_SOLID_STYLE);
    table << fort::header
        << this->hotelController.lock()->GetTitle() << fort::endr;
    table.column(0).set_cell_text_align(fort::text_align::center);

    std::cout << table.to_string() << std::endl;
}

void HotelView::DisplayDatabaseInfo(){
    fort::char_table table;
    table.set_border_style(FT_SOLID_STYLE);
    table << fort::header
        << "Database" << fort::endr
        << this->hotelController.lock()->GetDatabaseInfo() << fort::endr;
    table.column(0).set_cell_text_align(fort::text_align::center);

    std::cout << table.to_string() << std::endl;
}

void HotelView::DisplayAllReservations(){
    fort::char_table table;
    table.set_border_style(FT_SOLID_STYLE);

    table << fort::header
        << "Reservation Id" << "Checkin Date" << "Checkout Date" << "Renting" << "Payment Deadline" << fort::endr;
    if(auto c = this->hotelController.lock())
        c->GetAllReservationsInfo(table);

    std::cout << "All reservations" << std::endl;
    std::cout << table.to_string() << std::endl;
}

void HotelView::DisplayOverdueReservations(){
    fort::char_table table;
    table.set_border_style(FT_SOLID_STYLE);

    table << fort::header
        << "Reservation Id" << "Checkin Date" << "Checkout Date" << "Renting" << "Payment Deadline" << fort::endr;
    if(auto c = this->hotelController.lock())
        c->GetOverdueReservationsInfo(table);

    std::cout << "Overdue Payments" << std::endl;
    std::cout << "Current time: " << DateToString( GetCurrentTime() ) << std::endl;
    std::cout << table.to_string() << std::endl;
}

void HotelView::DisplayReservationInfo(fort::char_table& table, std::string id, std::string start, std::string finish, std::string toPay, std::string paymentDeadline){
    table << id << start << finish << std::stof(toPay) << paymentDeadline << fort::endr;
}

void HotelView::DisplayAllRooms(){
    fort::char_table table;
    table.set_border_style(FT_SOLID_STYLE);

    table << fort::header
        << "Room name" << "Area" << "Type" << fort::endr;
    if(auto c = this->hotelController.lock())
        c->GetAllRooms(table);

    std::cout << "All rooms" << std::endl;
    std::cout << table.to_string() << std::endl;
}

void HotelView::DisplayAllBedrooms(){
    fort::char_table table;
    table.set_border_style(FT_SOLID_STYLE);

    table << fort::header
        << "Room name" << "Area" << "Beds" << "Price(per day)" << "Reservations Amount" << fort::endr;
    if(auto c = this->hotelController.lock())
        c->GetAllBedrooms(table);

    std::cout << "All ours bedrooms" << std::endl;
    std::cout << table.to_string() << std::endl;
}

void HotelView::DisplayBedroomsUpTo(float maxPrice){
    fort::char_table table;
    table.set_border_style(FT_SOLID_STYLE);

    table << fort::header
        << "Room name" << "Area" << "Beds" << "Price(per day)" << "Reservations Amount" << fort::endr;
    if(auto c = this->hotelController.lock())
        c->GetBedroomsUpTo(table, maxPrice);

    std::cout << "Bedrooms with max price equal " << std::to_string(maxPrice) << std::endl;
    std::cout << table.to_string() << std::endl;
}

void HotelView::DisplayFreeBedroomsAt(std::tm start, std::tm end){
    fort::char_table table;
    table.set_border_style(FT_SOLID_STYLE);

    table << fort::header
        << "Room name" << "Area" << "Beds" << "Price(per day)" << "Reservations Amount" << fort::endr;
    if(auto c = this->hotelController.lock())
        c->GetFreeBedroomsAt(table, start, end);

    std::cout << "Bedrooms free from: " << DateToString(start) << " to " << DateToString(end) << std::endl;
    std::cout << table.to_string() << std::endl;
}

void HotelView::DisplayFreeConferanceRoomsAt(std::tm start, std::tm end){
    fort::char_table table;
    table.set_border_style(FT_SOLID_STYLE);

    table << fort::header
        << "Room name" << "Area" << "Places" << "Price(per day)" << "Reservations Amount" << fort::endr;
    if(auto c = this->hotelController.lock())
        c->GetFreeConferanceRoomsAt(table, start, end);

    std::cout << "Conferance rooms free from: " << DateToString(start) << " to " << DateToString(end) << std::endl;
    std::cout << table.to_string() << std::endl;
}

void HotelView::DisplayBedroomInfo(fort::char_table& table, std::string name, std::string area, std::string bedsAmount, std::string price, std::string reservationsAmount){
    table << name << std::stof(area) << bedsAmount << std::stof(price) << reservationsAmount << fort::endr;
}

void HotelView::DisplayConferanceRoomInfo(fort::char_table& table, std::string name, std::string area, std::string chairsAmount, std::string price, std::string reservationsAmount){
    table << name << std::stof(area) << chairsAmount << std::stof(price) << reservationsAmount << fort::endr;
}

void HotelView::DisplayRoomInfo(fort::char_table& table, std::string name, std::string area, std::string type){
    table << name << std::stof(area) << type << fort::endr;
}

void HotelView::DisplayPaymentMenu(){
    std::string choosedReservation;
    std::string insertedSum;

    fort::char_table table;
    table.set_border_style(FT_SOLID_STYLE);
    table << fort::header
        << "Reservation Id" << "Checkin Date" << "Checkout Date" << "Renting" << "Payment Deadline" << fort::endr;
    
    this->ClearScreen();
    while(true){
        try{
            this->DisplayAllReservations();
            
            std::cout << "Choose reservation to pay: [ESC to return] ";
            std::cin.sync();
            std::getline(std::cin, choosedReservation);
            if(choosedReservation.at(0) == 27){
                std::cin.clear();
                std::cout.flush();
                break;
            }
            std::cout << "Pass sum: ";
            std::cin.sync();
            std::getline(std::cin, insertedSum);
            if(!isFloatNumber(insertedSum))
                throw std::logic_error("Passed sum not valid");

            if(auto c = this->hotelController.lock())
                c->HandlePayment(table, choosedReservation, std::stof(insertedSum));
            std::cout << std::endl << table.to_string() << std::endl;
            break;
        }catch(const std::exception& error){
            this->ClearScreen();
            std::cout << "\033[1;31m" << error.what() << "\033[0m\n" << std::endl << std::endl;
        }
    }
}

void HotelView::ClearScreen(){
    system("clear");
}

void HotelView::MainMenu(){
    char key;
    while(key != 27){
        this->ClearScreen();
        this->DisplayTitle();
        this->DisplayDatabaseInfo();
        
        fort::char_table table;
        table.set_border_style(FT_SOLID_STYLE);
        table << fort::header 
            << "Key" << "Option" << fort::endr
            << "1"   << "Display All Rooms" << fort::endr 
            << "2"   << "Display All Bedrooms" << fort::endr << fort::separator 
            << "3"   << "Display All Reservations" << fort::endr 
            << "4"   << "Display Overdue Reservations" << fort::endr 
            << "5"   << "Pay for reservation" << fort::endr << fort::separator 
            << "ESC" << "Exit" << fort::endr;
        table.column(0).set_cell_text_align(fort::text_align::center);
        std::cout << table.to_string() << std::endl << std::endl;

        std::cout << "Option: ";
        std::cin.sync();
        std::cin >> key;

        this->ClearScreen(); 
        switch(key){
            case '1': 
                this->DisplayAllRooms(); break;
            case '2': 
                this->DisplayAllBedrooms(); break;
            case '3': 
                this->DisplayAllReservations(); break;
            case '4': 
                this->DisplayOverdueReservations(); break;
            case '5': 
                this->DisplayPaymentMenu(); break;
            default: break;
        }

        if(key != 27){
            std::cout << std::endl << "Press any key to continue ..." << std::endl;
            std::cin.sync();
            getchar();
        }
    }
}