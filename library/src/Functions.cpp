#include "Functions.h"
#include <iostream>
#include <string>
#include <vector>

std::tm GetIncreasedDate(std::tm date, int hours, int days){
    long secondsToAdd = (hours * 3600) + (days * 86400);
    time_t dateTime = mktime(&date);
    dateTime += secondsToAdd;
    std::tm newDate = *localtime(&dateTime);
    return newDate;
}

bool IsFirstDateEarlier(std::tm dateOne, std::tm dateTwo){
    time_t timeOne = mktime(&dateOne);
    time_t timeTwo = mktime(&dateTwo);
    return timeOne < timeTwo;
}

std::tm GetCurrentTime(){
    std::time_t t = std::time(0);
    std::tm currentTime = *std::localtime(&t);
    return currentTime;
}

std::string DateToString(std::tm date){
    std::string dateStr, day, month, year, hour, min;
    std::vector<std::string> months = { "Jan","Feb.","Mar","Apr","May","June","July","Aug.","Sept","Oct.","Nov.","Dec."};
    
    if(date.tm_mday < 10)
        day = "0" + std::to_string(date.tm_mday);
    else
        day = std::to_string(date.tm_mday);
    month = months[date.tm_mon];
    year = std::to_string(date.tm_year + 1900);

    if(date.tm_hour < 10)
        hour = "0" + std::to_string(date.tm_hour);
    else
        hour = std::to_string(date.tm_hour);

    if(date.tm_min < 10)
        min = "0" + std::to_string(date.tm_min);
    else
        min = std::to_string(date.tm_min);
     
    dateStr = day + " " + month + " " + year + " " + hour + ":" + min;
    return dateStr;
}