#include "LCDDisplay.h"

LCDDisplay::LCDDisplay(uint8_t address, uint8_t cols, uint8_t rows)
  : lcd(address, cols, rows) {}

void LCDDisplay::begin() {
  lcd.init();
  lcd.backlight();
}

void LCDDisplay::show(const char* text, int& cols){
  int len = strlen(text);

  lcd.setCursor((cols - len) / 2, 0);
  lcd.print(text);
}

void LCDDisplay::leftRotateString(char* str, int d) {
  int n = strlen(str);
  d %= n;
        
  for (int i = 0; i < d; i++) {
    char first_char = str[0];
    for (int j = 0; j < n - 1; j++) {
      str[j] = str[j + 1];
    }
    str[n - 1] = first_char;
  }
}

void LCDDisplay::scrollMessage(int row, const char* message, int delayTime, int cols) {
  char displayText[cols];
  strncpy(displayText, message, cols - 1);

  int len = strlen(displayText);
  if (len >= cols) return;
        
  for (int i = len; i < cols - 1; ++i) displayText[i] = ' ';

  displayText[cols - 1] = '\0';

  while(true) {
    lcd.setCursor(0, row);
    lcd.print(displayText);
    delay(delayTime);
            
    leftRotateString(displayText, 1);
  }
}

void LCDDisplay::animateText(const char* upperText, const char* text, unsigned long speed) {
  int cols = 16;

  lcd.setCursor(0, 0);
  show(upperText, cols);
  scrollMessage(1, text, speed, cols);
}