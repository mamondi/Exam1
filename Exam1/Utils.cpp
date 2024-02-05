    #include "Utils.h"

    void clearConsole() {
        std::system(CLEAR_SCREEN);
    }

    void printColored(std::string text, std::string color) {
        std::cout << color << text << RESET_COLOR;
    }
