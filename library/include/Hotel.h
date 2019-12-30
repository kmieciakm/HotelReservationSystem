#ifndef HOTEL_H
#define HOTEL_H

#include <string>

class Hotel {
private: 
    std::string name;
    int stars;
public:
    Hotel(std::string _name, int _stars);
    ~Hotel() = default;
    std::string GetName();
    int GetStarsAmount();
};

#endif

