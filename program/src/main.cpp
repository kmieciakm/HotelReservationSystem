#include <iostream>
#include "Hotel.h"
#include "Functions.h"
#include <chrono>

int main() {
    Hotel hotel("Grand Hotel", 5);
    std::cout << "Welcom in " << hotel.GetName() << " (";
    for(int i = 0; i < hotel.GetStarsAmount(); i++)
        std::cout << "*";
    std::cout << ")" << std::endl;
    std::cout << std::endl;
    return 0;
}
