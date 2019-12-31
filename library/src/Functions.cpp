#include "Functions.h"

std::tm GetIncreasedDate(std::tm date, int hours, int days, int months, int years){
    date.tm_hour += hours;
    date.tm_mday += days;
    date.tm_mon += months;
    date.tm_year += years;
    time_t dateTime = mktime(&date);
    std::tm* checkOutDateNew = localtime ( &dateTime );
    std::tm newDate = *checkOutDateNew;
    delete(checkOutDateNew);
    return newDate;
}