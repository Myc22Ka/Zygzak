#ifndef LCDDisplay_h
#define LCDDisplay_h

#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Arduino.h>

class LCDDisplay {
  public:
    LCDDisplay(uint8_t address = 0x27, uint8_t cols = 16, uint8_t rows = 2);
    void begin();
    void animateText(const char* upperText, const char* text, unsigned long speed);

  private:
    LiquidCrystal_I2C lcd;

    void scrollMessage(int row, const char* message, int delayTime, int totalColumns);
    void show(const char* text, int& cols);
    void leftRotateString(char* str, int d);
};

#endif
