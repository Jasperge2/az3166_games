#include "leds.h"
#include <Arduino.h>

namespace leds {
    void setup(bool red, bool green , bool blue , bool wifi, bool user) {
        if(red) pinMode(RED_LED, OUTPUT);
        if(green) pinMode(GREEN_LED, OUTPUT);
        if(blue) pinMode(BLUE_LED, OUTPUT);
        if(wifi) pinMode(WIFI_LED, OUTPUT);
        if(user) pinMode(USER_LED, OUTPUT);
    }

    void set(uint8_t led, bool state) {
        int pin;
        switch(led) {
            case 0: pin = RED_LED; break;
            case 1: pin = GREEN_LED; break;
            case 2: pin = BLUE_LED; break;
            case 3: pin = WIFI_LED; break;
            case 4: pin = USER_LED; break;
            default: return; // invalid LED index
        }
        digitalWrite(pin, state);

    } // namespace leds
}