#include "screen.h"

namespace screen {

    static OLEDDisplay Screen; // define the object
    
    void setup() {
        Screen.init();   // Screen is a global object provided by the SDK
        Screen.clean();
        Screen.print("Ready...");
    }

    void clear() {
        Screen.clean();
    }

    void displayMenu(char gameName[20]) {
        Screen.clean();
        Screen.print(0, "GAMES", 1); // for now
        Screen.print(1, gameName, 0);
        // Screen.print(gameName);
    }

    void print(const std::string& text) {
        Screen.clean();
        Screen.print(0, 0, text.c_str());
    }
}
