#ifndef SCREEN_H
#define SCREEN_H

#undef min
#undef max
#include <string>
#include <OledDisplay.h>   // OLED lib from DevKit SDK

namespace screen {
    void setup();
    void clear();
    void displayMenu(char gameName[20]);
    void print(const std::string& text);
}

#endif // SCREEN_H
