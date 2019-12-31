#include <iostream>
#include <chrono>
#include "Hotel.h"
#include "Bedroom.h"
#include "Functions.h"

int main() {
    Hotel hotel("Grand Hotel", 5);
    std::cout << "Welcome in " << hotel.GetName() << " (";
    for(int i = 0; i < hotel.GetStarsAmount(); i++)
        std::cout << "*";
    std::cout << ")" << std::endl;

    Bedroom bedroom("KillYourself", 20, 20, 1);
    std::tm arrival = {0 ,0 ,10, 5, 0, 200};
    bedroom.Reserve(arrival, 30);
    std::cout << "Reservation Amount: " << bedroom.GetReservationsAmount() << std::endl;
    std::cout << "Reservation deadline: " << bedroom.GetReservation(1)->GetCheckoutDate().tm_mday << " - " 
              << bedroom.GetReservation(1)->GetCheckoutDate().tm_mon + 1 << " - "
              << bedroom.GetReservation(1)->GetCheckoutDate().tm_year + 1900 << std::endl;

    std::cout << std::endl;
    return 0;
}