#include "Functions.h"
#include <iostream>

std::tm GetIncreasedDate(std::tm date, int hours, int days){
    long secondsToAdd = (hours * 3600) + (days * 86400);
    time_t dateTime = mktime(&date);
    dateTime += secondsToAdd;
    std::tm newDate = *localtime(&dateTime);
    return newDate;
}