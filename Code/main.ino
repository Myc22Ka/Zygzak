#include <Wire.h>
#include "LCDDisplay.h"

LCDDisplay lcdDisplay;

void setup() {
  lcdDisplay.begin();
}

void loop() {
  lcdDisplay.animateText("SMiW", "Testing!", 350);
}
