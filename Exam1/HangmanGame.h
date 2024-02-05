#ifndef HANGMANGAME_H
#define HANGMANGAME_H

#include <string>
#include <vector>
#include <chrono>
#include <fstream>
#include "Utils.h"

class HangmanGame {
private:
    std::string secretWord;
    std::string guessedWord;
    int attempts;
    std::vector<char> guessedLetters;
    std::chrono::time_point<std::chrono::steady_clock> startTime;

public:
    HangmanGame(const std::string& word);
    bool guessLetter(char letter);
    bool isGameOver() const;
    std::string getGuessedWord() const;
    std::string getSecretWord() const;
    int getAttempts() const;
    std::vector<char> getGuessedLetters() const;
    std::chrono::duration<double> getElapsedTime() const;
};

#endif
