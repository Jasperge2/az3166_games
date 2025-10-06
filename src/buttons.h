#ifndef BUTTONS_H
#define BUTTONS_H

#include <Arduino.h>

// Button pins
#define BUTTON_A  4    // onboard A button
#define BUTTON_A_pn PA_4
#define BUTTON_B  10   // onboard B button
#define BUTTON_B_pn PA_10

#define debounceDelay 100 // ms

namespace buttons {    
    void setup();
    bool isPressed(char button);
}

#endif // BUTTONS_H