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
        addOption("something", [](){ screen::print("Not implemented"); });
        addOption("nothing", [](){ screen::print("Not notinged"); });
        addOption("exit", [](){ screen::print("Exiting..."); });
    }

    void mainMenu() {
        // Read buttons
        char buf[20];
        uint8_t change_flag = 0;
        if (buttons::isPressed('a')) {
            navigateDown();
            change_flag = 1;
        }
        if (buttons::isPressed('b')) {
            navigateUp(); 
            change_flag = 1;
        }
        if (buttons::isLongPressed('b')) {
            selectOption();
        }
        if (!options.empty() && change_flag) {
            change_flag = 0;
            sprintf(buf, "> %s", options[currentOption].gameName.c_str());
            screen::displayMenu(buf);
        }
    }

    void navigateUp() {
        if (currentOption >= (int)options.size() - 1) {
            return; // no options
        }
        else {
            currentOption++;
        }
    }

    void navigateDown() {
        
        if (currentOption <= 0) {
            currentOption = 0;  // stay at first option
        }
        else {
            currentOption--;
        }
    }

    void selectOption() {
        if (!options.empty()) {
            options[currentOption].action();
        }
    }
}
