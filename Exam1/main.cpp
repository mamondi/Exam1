#include <iostream>
#include "HangmanGame.h"
#include "Utils.h"
#include "Lib.h"

using namespace std;

int main() {
    srand(time(0)); 

    vector<string> words = readWordsFromFile("words.txt");

    if (words.empty()) {
        cerr << "Error: No words in the file." << endl;
        return 1;
    }

    int randomIndex = rand() % 50 + 1;

  
    string selectedWord;
    if (randomIndex <= words.size()) {
        selectedWord = words[randomIndex - 1]; 
    }
    else {
        cerr << "Error: Not enough words in the file." << endl;
        return 1;
    }

    HangmanGame game(selectedWord);

    cout << "Guess the word. Initial state: " << game.getGuessedWord() << endl;

    while (!game.isGameOver()) {
        clearConsole();

        cout << "Attempts remaining: " << GREEN_COLOR << game.getAttempts() << RESET_COLOR << endl;
        cout << "Guessed word: ";
        for (size_t i = 0; i < game.getGuessedWord().length(); ++i) {
            if (game.getGuessedWord()[i] == '_') {
                printColored("_", RED_COLOR);
            }
            else {
                printColored(string(1, game.getGuessedWord()[i]), GREEN_COLOR);
            }
        }
        cout << endl;

        cout << "Enter a letter: ";
        string input;
        cin >> input;

        if (input.length() == 1 && isalpha(input[0])) {
            char letter = tolower(input[0]); 
            if (game.guessLetter(letter)) {
                cout << "Correct guess!" << endl;
            }
            else {
                cout << "Incorrect letter. Try again." << endl;
            }
        }
        else {
            cout << endl;
            cout << RED_COLOR << ">> Invalid input. Please enter a single letter <<" << RESET_COLOR << endl;
            cin.clear(); 
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin.get(); 
        }
    }
    displayGameStatistics(game);
    return 0;
}