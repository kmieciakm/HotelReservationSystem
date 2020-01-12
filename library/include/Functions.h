#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <chrono>
#include <string>

std::tm GetIncreasedDate(std::tm date, int hours, int days);
std::tm GetCurrentTime();
std::string DateToString(std::tm date);

#endif