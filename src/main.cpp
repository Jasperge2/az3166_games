#include "leds.h"
#include "buttons.h"
#include "menu.h"
#include "maxen.h"
#include "screen.h"

#include <Arduino.h>

int ctr = 0;
int ctr_l = 0;
int bctr = 0;
int bctr_l = 0;

char buffer[20];

void setup() {
  leds::setup();    // Init RGB LEDs only
  buttons::setup(); // Init buttons
  menu::setup();    // Init menu system
  screen::setup();  // Init screen
}

void loop() {

  menu::mainMenu();
  // if (buttons::isPressed('a')) {
  //   Screen.clean();
  //   sprintf(buffer, "Count A: %d", ++ctr);
  //   Screen.print(buffer);
  // }

  // if (buttons::isLongPressed('a')) {
  //   Screen.clean();
  //   sprintf(buffer, "Long A: %d", ++ctr_l);
  //   Screen.print(buffer); 
  // }

  // if (buttons::isLongPressed('b')){
  //   Screen.clean();
  //   sprintf(buffer, "Long B: %d", ++bctr_l);
  //   Screen.print(buffer);
  // }
  
  // if (buttons::isPressed('b')) {
  //   Screen.clean();
  //   sprintf(buffer, "Count B: %d", ++bctr);
  //   Screen.print(buffer);
  // }
    
}
