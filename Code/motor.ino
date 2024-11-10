void moveForward(int speed) {
  float distance = readSensorData();

  if (distance > 10) {
    analogWrite(A_1B, 0);
    analogWrite(A_1A, speed);
    analogWrite(B_1B, 0);
    analogWrite(B_1A, speed);
  } else {
    stopMove();
    beeping = true;
  }
  Serial.println(distance);
}

void moveBackward(int speed) {
  analogWrite(A_1B, speed);
  analogWrite(A_1A, 0);
  analogWrite(B_1B, speed);
  analogWrite(B_1A, 0);
}

void forwardLeft(int speed) {
  float distance = readSensorData();

  int left = digitalRead(leftIR);

  if (distance > 10 && left) {
    analogWrite(A_1B, 0);
    analogWrite(A_1A, speed);
    analogWrite(B_1B, 0);
    analogWrite(B_1A, 0);
  } else {
    stopMove();
    beeping = true;
  }
  Serial.println(distance);
}

void forwardRight(int speed) {
  float distance = readSensorData();

  int right = digitalRead(rightIR);

  if (distance > 10 && right) {
    analogWrite(A_1B, 0);
    analogWrite(A_1A, 0);
    analogWrite(B_1B, 0);
    analogWrite(B_1A, speed);
  } else {
    stopMove();
    beeping = true;
  }
  Serial.println(distance);
}

void backLeft(int speed) {
  analogWrite(A_1B, speed);
  analogWrite(A_1A, 0);
  analogWrite(B_1B, 0);
  analogWrite(B_1A, 0);
}

void backRight(int speed) {
  analogWrite(A_1B, 0);
  analogWrite(A_1A, 0);
  analogWrite(B_1B, speed);
  analogWrite(B_1A, 0);
}

void stopMove() {
  flag = "NONE";

  analogWrite(A_1B, 0);
  analogWrite(A_1A, 0);
  analogWrite(B_1B, 0);
  analogWrite(B_1A, 0);
}