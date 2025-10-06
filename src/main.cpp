#include "leds.h"
#include "buttons.h"

#include <Arduino.h>
#include <OledDisplay.h>   // OLED lib from DevKit SDK

void setup() {
  leds::setup(); // Init RGB LEDs only
  buttons::setup(); // Init buttons
  
  // Init OLED
  Screen.init();
  Screen.clean();
  Screen.print("Ready...");
}

void loop() {
  if (buttons::isPressed('a')) {
    Screen.clean();
    Screen.print("Button A");
    leds::set(0, true); // Turn off current LED
  }
  if (buttons::isPressed('b')) {
    Screen.clean();
    Screen.print("Button B");
    leds::set(0, false); // Turn off current LED
  }
    
}
