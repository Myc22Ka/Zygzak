#include <IRremote.h>

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

int speed = 150;
bool isMoving = false;
String flag = "NONE";
bool beeping = false;
bool volumed = false;

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
  }

  action(flag);
}