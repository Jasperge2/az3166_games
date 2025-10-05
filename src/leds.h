#ifndef LEDS_H
#define LEDS_H

#include <Arduino.h>

// LED pins
#define RED_LED   20
#define GREEN_LED 19
#define BLUE_LED  39

// Extra LEDs (not used here, but defined in your code)
#define WIFI_LED  18
#define USER_LED  45

namespace leds {
    void setup(bool red = 1, bool green = 1 , bool blue = 1 , bool wifi = 1, bool user = 1);
    void set(int led, bool state);
}
#endif // LEDS_H