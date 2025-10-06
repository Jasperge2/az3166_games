#include "buttons.h"

namespace buttons {

    // Flags
    static volatile bool buttonA_flag = false;        // short press
    static volatile bool buttonB_flag = false;        
    static volatile bool buttonA_longPress = false;   // long press (>=1.5s)
    static volatile bool buttonB_longPress = false;

    // Timing
    static volatile unsigned long pressStartA = 0;
    static volatile unsigned long pressStartB = 0;



    // ISR for Button A
    void handleButtonA() {
        unsigned long now = millis();

        if (digitalRead(BUTTON_A) == LOW) { // pressed (active low)
            // Only register new press if debounce passed
            if (now - pressStartA > debounceDelay) {
                pressStartA = now; 
            }
        } else { // released
            unsigned long heldTime = now - pressStartA;
            if (heldTime >= longPressTime) {
                buttonA_longPress = true;
            } else if (heldTime >= debounceDelay) {
                buttonA_flag = true;
            }
        }
    }

    // ISR for Button B
    void handleButtonB() {
        unsigned long now = millis();

        if (digitalRead(BUTTON_B) == LOW) { // pressed
            if (now - pressStartB > debounceDelay) {
                pressStartB = now;
            }
        } else { // released
            unsigned long heldTime = now - pressStartB;
            if (heldTime >= longPressTime) {
                buttonB_longPress = true;
            } else if (heldTime >= debounceDelay) {
                buttonB_flag = true;
            }
        }
    }

    void setup() {
        pinMode(BUTTON_A, INPUT_PULLUP);
        pinMode(BUTTON_B, INPUT_PULLUP);

        attachInterrupt(BUTTON_A_pn, handleButtonA, CHANGE);
        attachInterrupt(BUTTON_B_pn, handleButtonB, CHANGE);
    }

    bool isPressed(char button) {
        switch (button) {
        case 'a':
            if (buttonA_flag) { buttonA_flag = false; return true; }
            return false;
        case 'b':
            if (buttonB_flag) { buttonB_flag = false; return true; }
            return false;
        default:
            return false;
        }
    }

    bool isLongPressed(char button) {
        switch (button) {
        case 'a':
            if (buttonA_longPress) { buttonA_longPress = false; return true; }
            return false;
        case 'b':
            if (buttonB_longPress) { buttonB_longPress = false; return true; }
            return false;
        default:
            return false;
        }
    }
}
