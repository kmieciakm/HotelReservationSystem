#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <chrono>
#include <string>

std::tm GetIncreasedDate(std::tm date, int hours, int days);
bool IsFirstDateEarlier(std::tm dateOne, std::tm dateTwo);
std::tm GetCurrentTime();
std::string DateToString(std::tm date);
bool isIntNumber(std::string str);
bool isFloatNumber(std::string str);

#endif