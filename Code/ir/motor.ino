void moveForward(int speed) {
  float distance = readSensorData();

  if(distance == 0.0) return;

  if (distance > 0.5) {
    if (distance > 10) {
      analogWrite(A_1B, 0);
      analogWrite(A_1A, int(speed));
      analogWrite(B_1B, int(speed));
      analogWrite(B_1A, 0);
    } else {
      stopMove();
      beeping = true;
    }
  }
}

void moveBackward(int speed) {
  analogWrite(A_1B, int(speed));
  analogWrite(A_1A, 0);
  analogWrite(B_1B, 0);
  analogWrite(B_1A, int(speed));
  
}
void forwardLeft(int speed) {
    int speedCp = speed;
  float distance = readSensorData();
  int left = digitalRead(leftIR);

  speedCp += 50; // motor correction

  if(speedCp > 250) speedCp = 250;

  if(distance == 0.0) return;

  if (distance > 0.5) {
    if (distance > 10 && left) {
      analogWrite(A_1B, 0);
      analogWrite(A_1A, speedCp);
      analogWrite(B_1A, 0);
    } else {
      stopMove();
      beeping = true;
    }
  }
}

void forwardRight(int speed) {
  float distance = readSensorData();
  int right = digitalRead(rightIR);

  if(distance == 0.0) return;

  if (distance > 0.5) {
    if (distance > 10 && right) {
      analogWrite(A_1B, 0);
      analogWrite(A_1A, 0);
      analogWrite(B_1B, speed);
      analogWrite(B_1A, 0);
    } else {
      stopMove();
      beeping = true;
    }
  } 
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
  analogWrite(B_1B, 0);
  analogWrite(B_1A, speed);
}

void stopMove() {
  flag = "NONE";

  analogWrite(A_1B, 0);
  analogWrite(A_1A, 0);
  analogWrite(B_1B, 0);
  analogWrite(B_1A, 0);
}