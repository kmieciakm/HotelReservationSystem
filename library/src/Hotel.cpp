#include "Hotel.h"

Hotel::Hotel(std::string _name, int _stars) 
: name(_name), stars(_stars) {}

std::string Hotel::GetName(){
    return this->name; 
}

void Hotel::SetName(std::string newName){
    this->name = newName;
}

int Hotel::GetStarsAmount(){
    return this->stars;
}