#define BLYNK_PRINT Serial
#define ESP8266_BAUD 115200

#define BLYNK_TEMPLATE_ID "TMPL4NIcfe_yq"
#define BLYNK_TEMPLATE_NAME "Quickstart Template"

#include <ESP8266_Lib.h>
#include <BlynkSimpleShieldEsp8266.h>
#include <SoftwareSerial.h>
#include <IRremote.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "auth.h"

char auth[] = BLYNK_AUTH_TOKEN;

SoftwareSerial EspSerial(2, 11);
ESP8266 wifi(&EspSerial);

LiquidCrystal_I2C lcd(0x27, 16, 2);

const int IR_RECEIVE_PIN = 12;

const int A_1B = 5;
const int A_1A = 6;
const int B_1B = 9;
const int B_1A = 10;

const int echoPin = 4;
const int trigPin = 3;

const int rightIR = 7;
const int leftIR = 8;

const int buzzerPin = 17;

const int lineTrackPin = 13;

int speed = 150;
bool start = false;
bool isMoving = false;
String flag = "NONE";
bool beeping = false;

BLYNK_WRITE(V0){
  int pinValue = param.asInt();
  Serial.print(pinValue);
}

void setup() {
  // Serial.begin(9600);
  Serial.begin(115200);

  // // Motors
  // pinMode(A_1B, OUTPUT);
  // pinMode(A_1A, OUTPUT);
  // pinMode(B_1B, OUTPUT);
  // pinMode(B_1A, OUTPUT);

  // // Ultrasonic Module
  // pinMode(echoPin, INPUT);
  // pinMode(trigPin, OUTPUT);

  // // IR obstacle
  // pinMode(leftIR, INPUT);
  // pinMode(rightIR, INPUT);

  // // Line Track Module
  // pinMode(lineTrackPin, INPUT);

  // // LCD
  // lcd.init();
  // lcd.backlight();

  // // Buzzer
  // pinMode(buzzerPin, OUTPUT);

  // // IR Receiver Remote
  // IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK); 
  // Serial.println("REMOTE CONTROL START");

  // Blynk
  EspSerial.begin(ESP8266_BAUD);
  delay(10);
  Blynk.begin(auth, wifi, SSID, PASS);

}

void loop() {
  Blynk.run();

  // if(beeping) {
  //   beep();
  // }

  // if (IrReceiver.decode()) {
  //   String key = decodeKeyValue(IrReceiver.decodedIRData.command);
  //   if (key != "ERROR") {
  //     flag = key;
  //   }

  //   IrReceiver.resume();
  // }
  // if (flag == "AUTO") {
  //   AutoDrive(speed);
  // } else if (flag == "LINE") {
  //   lineTrack(speed);
  // }

  // action(flag);

  // if(!start){
  //   setDisplay("SMiW", "Testing!");
  //   animateText();

  //   start = true;
  // }
}