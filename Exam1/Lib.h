#ifndef LIB_H
#define LIB_H

#include "HangmanGame.h"
#include "Utils.h"

std::vector<std::string> readWordsFromFile(const std::string& filename);
void displayGameStatistics(HangmanGame& game);

#endif
