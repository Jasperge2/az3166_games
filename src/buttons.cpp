#include "buttons.h"

namespace buttons {

    // Flags set by ISRs
    static volatile bool buttonA_flag = false;
    static volatile bool buttonB_flag = false;

    // debounce handling
    static volatile unsigned long lastInterruptA = 0;
    static volatile unsigned long lastInterruptB = 0;

    // ISR for Button A
    void handleButtonA() {
        unsigned long now = millis();
        if (now - lastInterruptA > debounceDelay) {
            buttonA_flag = true;
            lastInterruptA = now;
        }
    }

    // ISR for Button B
    void handleButtonB() {
        unsigned long now = millis();
        if (now - lastInterruptB > debounceDelay) {
            buttonB_flag = true;
            lastInterruptB = now;
        }
    }

    void setup() {
        pinMode(BUTTON_A, INPUT_PULLUP);
        pinMode(BUTTON_B, INPUT_PULLUP);

        // Attach interrupts (falling = press, since pullups make idle HIGH)
        attachInterrupt(BUTTON_A_pn, handleButtonA, FALLING);
        attachInterrupt(BUTTON_B_pn, handleButtonB, FALLING);
    }

    bool isPressed(char button) {

        switch (button)
        {
        case 'a':
            if (buttonA_flag){ buttonA_flag = false; return true;} // Active low
            return false;
        case 'b':
            if (buttonB_flag){ buttonB_flag = false; return true;} // Active low
            return false;
        default:
            return false;
        }
    }
    
}