#include "Functions.h"
#include <time.h>
#include <iostream>
#include <string>
#include <vector>

constexpr int MAX_YEAR = 2050;
constexpr int SecondsPerMinute = 60;
constexpr int SecondsPerHour = 3600;
constexpr int SecondsPerDay = 86400;
constexpr int DaysOfMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool IsLeapYear(short year)
{
    if (year % 4 != 0) return false;
    if (year % 100 != 0) return true;
    return (year % 400) == 0;
}

time_t mkgmtime(const struct tm *ptm) {
    time_t secs = 0; 
    int year = ptm->tm_year + 1900;
    for (int y = 1970; y < year; ++y) {
        secs += (IsLeapYear(y)? 366: 365) * SecondsPerDay;
    }
    for (int m = 0; m < ptm->tm_mon; ++m) {
        secs += DaysOfMonth[m] * SecondsPerDay;
        if (m == 1 && IsLeapYear(year)) secs += SecondsPerDay;
    }
    secs += (ptm->tm_mday - 1) * SecondsPerDay;
    secs += ptm->tm_hour       * SecondsPerHour;
    secs += ptm->tm_min        * SecondsPerMinute;
    secs += ptm->tm_sec;
    return secs;
}

std::tm GetIncreasedDate(std::tm date, int hours, int days){
    long secondsToAdd = (hours * 3600) + (days * 86400);
    std::time_t dateTime = mkgmtime(&date) + secondsToAdd;
    std::tm newDate = *gmtime(&dateTime);
    return newDate;
}

bool IsFirstDateEarlier(std::tm dateOne, std::tm dateTwo){
    std::time_t timeOne = mkgmtime(&dateOne);
    std::time_t timeTwo = mkgmtime(&dateTwo);
    return timeOne < timeTwo;
}

std::tm GetCurrentTime(){
    std::time_t t = time(NULL);
    std::tm currentTime = *gmtime(&t);
    return currentTime;
}

std::string DateToString(std::tm datePassed){
    std::tm date = datePassed;
    std::time_t dateTime = mkgmtime(&date);
    date = *std::gmtime(&dateTime);
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
    if( std::stoi(str.substr(6, 4)) < 1900 || std::stoi(str.substr(6, 4)) > MAX_YEAR)
        throw std::logic_error("Date is not valid, year out of range");

    std::tm date;
    date.tm_sec = 0;
    date.tm_min = 0;
    date.tm_hour = 10;
    date.tm_mday = std::stoi(str.substr(0, 2));
    date.tm_mon = std::stoi(str.substr(3, 2)) - 1;
    date.tm_year = std::stoi(str.substr(6, 4)) - 1900;
    date.tm_isdst = false;

    return date;
}

bool isExitString(std::string str){
    return (str.length() == 0 || str.at(0) == 27);
}