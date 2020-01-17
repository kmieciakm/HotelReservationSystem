#include <iostream>
#include <chrono>
#include "Hotel.h"
#include "Bedroom.h"
#include "Functions.h"
#include "json.hpp"
#include "DatabaseSystem.h"
#include "HotelController.h"
#include <fstream>
#include "FortLibrary/fort.h"
#include "FortLibrary/fort.hpp"

using json = nlohmann::json;

int main() {
    std::cout << "Please enter database name: ";
    std::string dbName;
    std::cin >> dbName;

    try{
        std::shared_ptr<DatabaseSystem> dbHilton = std::make_shared<DatabaseSystem>(dbName);
        std::shared_ptr<Hotel> hiltonHotel = dbHilton->GetHotelFromDatabase();

        std::shared_ptr<HotelController> hotelController = std::make_shared<HotelController>(hiltonHotel, dbHilton); 
        std::shared_ptr<HotelView> hotelView = std::make_shared<HotelView>();
        hotelController->SetView(hotelView);
        hotelView->SetController(hotelController);

        hotelView->MainMenu();
    }catch(const std::exception& error){
        std::cout << error.what();
    }
    
    // hotelView->DisplayBedroomsUpTo(100.00);
    // std::tm start = {0 ,0 ,10, 5, 3, 120};
    // std::tm end = {0 ,0 ,10, 7, 3, 120};
    // hotelView->DisplayFreeBedroomsAt(start, end);
    // hotelView->DisplayFreeConferanceRoomsAt(start, end);
    // hotelView->DisplayErrorMessage("Everything is all right");
    return 0;
}