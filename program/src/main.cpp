#include <iostream>
#include "Hotel.h"
#include <chrono>

int main() {
    Hotel hotel("Grand Hotel", 5);
    std::cout << "Welcom in " << hotel.GetName() << " (";
    for(int i = 0; i < hotel.GetStarsAmount(); i++)
        std::cout << "*";
    std::cout << ")" << std::endl;

   constexpr int DAY = 9;
   constexpr int MONTH = 1;
   constexpr int YEAR = 2014;
   constexpr int PERIOD = 4;

    std::tm checkInDate = {0, 0, 10, (DAY), MONTH, YEAR };
    std::tm checkOutDate = {0, 0, 10, (DAY+PERIOD), MONTH, YEAR };
    std::cout << checkInDate.tm_mday << " - " << checkInDate.tm_mon << " - " << checkInDate.tm_year << std::endl;
    std::cout << checkOutDate.tm_mday << " - " << checkOutDate.tm_mon << " - " << checkOutDate.tm_year;
    std::cout << std::endl;
    return 0;
}