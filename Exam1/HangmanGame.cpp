#include "HangmanGame.h"

HangmanGame::HangmanGame(const std::string& word) : secretWord(word), attempts(word.length() + 5) {
    guessedWord = std::string(secretWord.length(), '_');
    startTime = std::chrono::steady_clock::now();
}

bool HangmanGame::guessLetter(char letter) {
    bool found = false;

    letter = std::tolower(letter); 

    for (size_t i = 0; i < secretWord.length(); ++i) {
        if (std::tolower(secretWord[i]) == letter) {
            guessedWord[i] = secretWord[i];
            found = true;
        }
    }

    if (!found) {
        --attempts;
    }

    guessedLetters.push_back(letter);

    return found;
}

bool HangmanGame::isGameOver() const {
    return guessedWord == secretWord || attempts <= 0;
}

std::string HangmanGame::getGuessedWord() const {
    return guessedWord;
}

std::string HangmanGame::getSecretWord() const {
    return secretWord;
}

int HangmanGame::getAttempts() const {
    return attempts;
}

std::vector<char> HangmanGame::getGuessedLetters() const {
    return guessedLetters;
}

std::chrono::duration<double> HangmanGame::getElapsedTime() const {
    auto endTime = std::chrono::steady_clock::now();
    return std::chrono::duration_cast<std::chrono::duration<double>>(endTime - startTime);
}

void displayGameStatistics(HangmanGame& game) {
    clearConsole();

    std::cout << GREEN_COLOR << "\n       Game Over!\n" << RESET_COLOR;
    std::cout << "\n>> Game Statistics <<\n";
    std::cout << "Elapsed Time: " << GREEN_COLOR << game.getElapsedTime().count() << RESET_COLOR << " seconds\n";
    std::cout << "Number of Attempts Left: " << GREEN_COLOR << game.getAttempts() << RESET_COLOR << "\n";
    std::cout << "Secret Word: " << GREEN_COLOR << game.getSecretWord() << RESET_COLOR << "\n";
    std::cout << "Guessed Letters: ";

    for (char letter : game.getGuessedLetters()) {
        if (game.guessLetter(letter)) {
            std::cout << GREEN_COLOR << letter << " ";
        }
        else {
            std::cout << RED_COLOR << letter << " ";
        }
    }

    std::cout << RESET_COLOR << "\n";
}

std::vector<std::string> readWordsFromFile(const std::string& filename) {
    std::vector<std::string> words;
    std::ifstream file(filename);

    if (file.is_open()) {
        std::string word;
        while (std::getline(file, word)) {
            for (char& ch : word) {
                if (std::isalpha(ch)) {
                    ch = static_cast<char>(std::toupper(ch) - 1); 
                    if (ch < 'A') {
                        ch = 'Z'; 
                    }
                }
            }
            words.push_back(word);
        }
        file.close();
    }
    else {
        std::cerr << "Error: Unable to open file '" << filename << "'" << std::endl;
    }

    return words;
}