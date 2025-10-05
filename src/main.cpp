#include "leds.h"
#include <Arduino.h>
#include <OledDisplay.h>   // OLED lib from DevKit SDK



// Button pins
#define BUTTON_A  4    // onboard A button
#define BUTTON_A_pn PA_4
#define BUTTON_B  10   // onboard B button
#define BUTTON_B_pn PA_10

// Flags set by ISRs
volatile bool buttonA_flag = false;
volatile bool buttonB_flag = false;
int ledState = 0;   // 0=Red, 1=Green, 2=Blue

// debounce handling
volatile unsigned long lastInterruptA = 0;
volatile unsigned long lastInterruptB = 0;
const unsigned long debounceDelay = 100; // ms

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
  leds::setup(); // Init RGB LEDs only
  // Buttons with pullups
  pinMode(BUTTON_A, INPUT_PULLUP);
  pinMode(BUTTON_B, INPUT_PULLUP);

  // Attach interrupts (falling = press, since pullups make idle HIGH)
  attachInterrupt(BUTTON_A_pn, handleButtonA, FALLING);
  attachInterrupt(BUTTON_B_pn, handleButtonB, FALLING);

  // Init OLED
  Screen.init();
  Screen.clean();
  Screen.print("Ready...");
}

void loop() {
  // Handle Button A → random number on OLED
  if (buttonA_flag) {
    buttonA_flag = false;   // reset flag
    int rnd = random(0, 1000);   // random number 0-999
    char buf[20];
    snprintf(buf, sizeof(buf), "Random: %d", rnd);
    Screen.clean();
    Screen.print(buf);
  }

  // Handle Button B → cycle LED color
  if (buttonB_flag) {
    buttonB_flag = false;   // reset flag

    // Turn off all LEDs first
    digitalWrite(RED_LED, LOW);
    digitalWrite(GREEN_LED, LOW);
    digitalWrite(BLUE_LED, LOW);

    // Cycle LED color
    if (ledState == 0) {
      digitalWrite(RED_LED, HIGH);
    } else if (ledState == 1) {
      digitalWrite(GREEN_LED, HIGH);
    } else if (ledState == 2) {
      digitalWrite(BLUE_LED, HIGH);
    }

    ledState = (ledState + 1) % 3;   // Next color
  }
}
