#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <string>

#ifdef _WIN32
#define CLEAR_SCREEN "cls"
#else
#define CLEAR_SCREEN "clear"
#endif

#define RESET_COLOR "\033[0m"
#define GREEN_COLOR "\033[32m"
#define RED_COLOR "\033[31m"

void clearConsole();
void printColored(std::string text, std::string color);

#endif