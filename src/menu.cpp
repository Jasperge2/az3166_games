#include "menu.h"
#include "buttons.h"
#include <iostream>   // for debug printing

namespace menu {

    static std::vector<MenuOption> options;
    static int currentOption = 0;

    void addOption(const std::string& name, std::function<void()> action) {
        options.push_back({name, action});
    }

    void setup() {
        //add your games here
        addOption("Maxen", [](){ maxen::setup(); });
    }

    void mainMenu() {
        // Read buttons
        if (buttons::isPressed('a')) {
            navigateDown();
        }
        if (buttons::isPressed('b')) {
            navigateUp(); 
        }
}

    void navigateUp() {
        currentOption++;
        if (currentOption >= (int)options.size()) {
            currentOption = 0;  // loop back
        }
    }

    void navigateDown() {
        currentOption--;
        if (currentOption < 0) {
            currentOption = options.size() - 1; // loop back
        }
    }

    void selectOption() {
        if (!options.empty()) {
            options[currentOption].action();
        }
    }
}
