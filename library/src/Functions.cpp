#include "Functions.h"
#include <iostream>
#include <string>
#include <vector>

std::tm GetIncreasedDate(std::tm date, int hours, int days){
    long secondsToAdd = (hours * 3600) + (days * 86400);
    time_t dateTime = mktime(&date) + secondsToAdd;
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
    time_t dateTime = mktime(&date);
    date = *localtime(&dateTime);
    std::string dateStr, day, month, year, hour, min;
    std::vector<std::string> months = { "Jan.","Feb.","Mar.","Apr.","May ","June","July","Aug.","Sept","Oct.","Nov.","Dec."};
    
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

bool isIntNumber(std::string str){
    for (int i=0 ; i < str.length(); i++){
        if(str[0] == '-') continue;
        if ( !isdigit(str[i]) ) 
            return false;
    }
    return true;
}

bool isFloatNumber(std::string str){
    for (int i=0 ; i < str.length(); i++){
        if(str[0] == '-') continue;
        if(str[i] == '.') continue;
        if ( !isdigit(str[i]) ) 
            return false;
    }
    return true;
}

std::tm StrToDate(std::string str){
    
    // dd-mm-yyyy
    if(str.length() != 10) 
        throw std::logic_error("Date is not valid, check date format");
    if( !isIntNumber(str.substr(0, 2)) || !isIntNumber(str.substr(3, 2)) || !isIntNumber(str.substr(6, 4)) ) 
        throw std::logic_error("Date is not valid, check date format");
    if( std::stoi(str.substr(0, 2)) <= 0 || std::stoi(str.substr(0, 2)) > 31)
        throw std::logic_error("Date is not valid, day out of range");
    if( std::stoi(str.substr(3, 2)) < 1 || std::stoi(str.substr(3, 2)) > 12)
        throw std::logic_error("Date is not valid, month out of range");
    if( std::stoi(str.substr(6, 4)) < 1900)
        throw std::logic_error("Date is not valid, year out of range");

    std::tm date;
    date.tm_sec = 0;
    date.tm_min = 0;
    date.tm_hour = 10;
    date.tm_mday = std::stoi(str.substr(0, 2));
    date.tm_mon = std::stoi(str.substr(3, 2)) - 1;
    date.tm_year = std::stoi(str.substr(6, 4)) - 1900;

    return date;
}

bool isExitString(std::string str){
    return (str.length() == 0 || str.at(0) == 27);
}