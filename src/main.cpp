#include "leds.h"
#include "buttons.h"
#include "menu.h"
#include "maxen.h"

#include <Arduino.h>
#include <OledDisplay.h>   // OLED lib from DevKit SDK

void setup() {
  leds::setup();    // Init RGB LEDs only
  buttons::setup(); // Init buttons
  menu::setup();    // Init menu system
  Screen.init();    // Init OLED
  
  Screen.clean();
  Screen.print("Ready...");
}

void loop() {
  if (buttons::isPressed('a')) {
    Screen.clean();
    char buffer[20];
    snprintf(buffer, sizeof(buffer), "Score: %d", maxen::score);
    Screen.print(buffer);
    leds::set(0, true); // Turn off current LED
  }
  if (buttons::isPressed('b')) {
    Screen.clean();
    Screen.print("Button B");
    leds::set(0, false); // Turn off current LED
  }
    
}
