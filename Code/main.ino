#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <IRremote.h>

#define IR_RECEIVE_PIN 12

LiquidCrystal_I2C lcd(0x27, 16, 2);
// LCDDisplay lcdDisplay("SMiW", "Testing!");
bool isSetup = true;

void setup() {
  Serial.begin(9600);
  
  // LCD
  lcd.init();
  lcd.backlight();

  IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK);
}

void loop() {
  if(isSetup){
    setDisplay("SMiW", "Testing!");
    animateText();

    isSetup = false;
  }

  if (IrReceiver.decode()) {
    // Decode the received command
    long command = IrReceiver.decodedIRData.command;
    String key = decodeKeyValue(command);

    if (key != "ERROR") {
      setDisplay("COMMAND:", "XD");
      Serial.println(key);

      if(key == 2){
        display("Action", "Move foreward!");
      }
    }

    IrReceiver.resume();
  }
}
