#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <IRremote.h>
#include "buzzer.h"

Buzzer buzzer;

LiquidCrystal_I2C lcd(0x27, 16, 2);
const int IR_RECEIVE_PIN = 12;

void setup()
{
  lcd.init();
  lcd.backlight();

  IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK);
  Serial.println("REMOTE CONTROL START");

  buzzer.begin();
}

void loop()
{
  if (IrReceiver.decode()) {
    String key = decodeKeyValue(IrReceiver.decodedIRData.command);
    if (key != "ERROR") {
      Serial.println(key);

      if (key == "+") {
        lcd.setCursor(3, 0);
        lcd.print("Spierdalaj");
        lcd.setCursor(5, 1);
        lcd.print("Mobile");
      }
      if(key == "-"){
        buzzer.play();
      }
    }

    IrReceiver.resume();
  }
}