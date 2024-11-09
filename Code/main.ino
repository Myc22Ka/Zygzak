#include <IRremote.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

const int IR_RECEIVE_PIN = 12;  // Define the pin number for the IR Sensor

const int A_1B = 5;
const int A_1A = 6;
const int B_1B = 9;
const int B_1A = 10;

const int echoPin = 4;
const int trigPin = 3;

const int rightIR = 7;
const int leftIR = 8;

const int buzzerPin = 11;

const int lineTrackPin = 2;

int speed = 150;
bool start = false;
bool isMoving = false;
String flag = "NONE";
bool beeping = false;

void setup() {
  Serial.begin(9600);

  // Motors
  pinMode(A_1B, OUTPUT);
  pinMode(A_1A, OUTPUT);
  pinMode(B_1B, OUTPUT);
  pinMode(B_1A, OUTPUT);

  // Ultrasonic Module
  pinMode(echoPin, INPUT);
  pinMode(trigPin, OUTPUT);

  // IR obstacle
  pinMode(leftIR, INPUT);
  pinMode(rightIR, INPUT);

  // Line Track Module
  pinMode(lineTrackPin, INPUT);

  // LCD
  lcd.init();
  lcd.backlight();

  // Buzzer
  pinMode(buzzerPin, OUTPUT);

  // IR Receiver Remote
  IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK); 
  Serial.println("REMOTE CONTROL START");

}

void loop() {

  if(beeping) {
    beep();
  }

  if (IrReceiver.decode()) {
    String key = decodeKeyValue(IrReceiver.decodedIRData.command);
    if (key != "ERROR") {
      flag = key;
    }

    IrReceiver.resume();
  }
  if (flag == "AUTO") {
    AutoDrive(speed);
  } else if (flag == "LINE") {
    lineTrack(speed);
  }

  action(flag);

  if(!start){
    setDisplay("SMiW", "Testing!");
    animateText();

    start = true;
  }
}