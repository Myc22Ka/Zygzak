// Comment this out to disable prints and save space
#define BLYNK_PRINT Serial

#define BLYNK_TEMPLATE_ID "TMPL4NIcfe_yq"
#define BLYNK_TEMPLATE_NAME "Quickstart Template"
#define BLYNK_AUTH_TOKEN "ieMJ9tXCeYs7hhq_lykVx7w-zqX2WIC0"

#include <ESP8266_Lib.h>
#include <BlynkSimpleShieldEsp8266.h>

char auth[] = BLYNK_AUTH_TOKEN;

char ssid[] = "xxx";
char pass[] = "123456789";

// or Software Serial on Uno, Nano...
#include <SoftwareSerial.h>
SoftwareSerial EspSerial(11, 2); // RX, TX

// Your ESP8266 baud rate:
#define ESP8266_BAUD 115200

ESP8266 wifi(&EspSerial);

/*car init*/

const int A_1B = 5;
const int A_1A = 6;
const int B_1B = 9;
const int B_1A = 10;

const int echoPin = 4;
const int trigPin = 3;

const int rightIR = 7;
const int leftIR = 8;

const int buzzerPin = 17;

String flag = "NONE";
int speed = 150;
bool beeping = false;
bool isMoving = false;

BLYNK_WRITE(V0)
{
  beeping = param.asInt();
}

BLYNK_WRITE(V2)
{
  speed = param.asInt();
}

BLYNK_WRITE(V10)
{
  int key = param.asInt();

  if (key == 1) {
        flag = "FORWARD";
      } else if (key == 4) {
        flag = "FORWARD_LEFT";
      } else if (key == 3) {
        flag = "FORWARD_RIGHT";
      } else if (key == 6) {
        flag = "BACK_LEFT";
      } else if (key == 5) {
        flag = "BACK_RIGHT";
      } else if (key == 2) {
        flag = "BACK";
      } else if (key == 0) {
        flag = "NONE";
      }
}


void setup()
{
  // Debug console
  Serial.begin(115200);

  // Set ESP8266 baud rate
  EspSerial.begin(ESP8266_BAUD);
  delay(15);

  Blynk.begin(auth, wifi, ssid, pass);

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
}

void loop()
{
  Blynk.run();

  if (!Blynk.connected()) {
    Serial.print("offline!");
    bool result = Blynk.connect();
    Serial.println(result);
  }

  if(beeping) {
    beep();
    beeping = false;
  }

  if(isMoving) {
    stopMove();
    delay(50);
  }

  if (flag == "FORWARD") {
    moveForward(speed);
  } else if (flag == "FORWARD_LEFT") {
    forwardLeft(speed);
  } else if (flag == "FORWARD_RIGHT") {
    forwardRight(speed);
  } else if (flag == "BACK_LEFT") {
    backLeft(speed);
  } else if (flag == "BACK_RIGHT") {
    backRight(speed);
  } else if (flag == "BACK") {
    moveBackward(speed);
  } else if (flag == "NONE") {
    stopMove();
  }
}

float readSensorData() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  float distance = pulseIn(echoPin, HIGH) / 58.00; //Equivalent to (340m/s*1us)/2
  return distance;
}

void beep(){
  for (int i = 0; i < 50; i++)
  {
    digitalWrite(buzzerPin, HIGH);
    delay(3);
    digitalWrite(buzzerPin, LOW);
    delay(3);
  }
  delay(1000);
}