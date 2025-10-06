#ifndef MENU_H
#define MENU_H

//games includes
#include "maxen.h"

#include "screen.h"


#pragma once
#undef min
#undef max

#include <functional>
#include <vector>
#include <string>

namespace menu {

    struct MenuOption {
        std::string gameName;
        std::function<void()> action;  // function to call when selected
    };

    void setup();
    void mainMenu();
    void navigateUp();
    void navigateDown();
    void selectOption();

    void addOption(const std::string& name, std::function<void()> action);
}

#endif // MENU_H
