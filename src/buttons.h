#ifndef BUTTONS_H
#define BUTTONS_H

#include <Arduino.h>

// Button pins
#define BUTTON_A  4    // onboard A button
#define BUTTON_A_pn PA_4
#define BUTTON_B  10   // onboard B button
#define BUTTON_B_pn PA_10

#define debounceDelay 40       // 40 ms RAAD AAN NIET TE VERHOGEN SINDS DE IMPLEMENTATIE HET NIET HEEL GRAPPIG VINDT!!! 
#define longPressTime 700       // 0.7 sec

namespace buttons {    
    void setup();
    bool isPressed(char button);
    bool isLongPressed(char button);
}

#endif // BUTTONS_H