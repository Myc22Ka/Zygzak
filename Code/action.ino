void action(String key){
  lcd.clear();

  if(isMoving) {
     stopMove();
     delay(50);
  }

  if(beeping){
    beeping = false;
  }

  if (key == "+") {
        speed += 50;
        Serial.println(speed);
      } else if (key == "-") {
        speed -= 50;
        Serial.println(speed);
      } else if (key == "2") {
        moveForward(speed);
      } else if (key == "1") {
        forwardLeft(speed);
      } else if (key == "3") {
        forwardRight(speed);
      } else if (key == "7") {
        backLeft(speed);
      } else if (key == "9") {
        backRight(speed);
      } else if (key == "8") {
        moveBackward(speed);
      } else if (key == "CYCLE") {
        flag = "LINE";
      } else if (key == "U/SD") {
        flag = "AUTO";
      } else if (key == "0") {
        stopMove();
      } else if (key == "FORWARD") {
        flag = "ULTR";
      } else if (key == "BACKWARD") {
        flag = "IROB";
      } else if (key == "EQ") {
        flag = "FOLW";
      }

      if (speed >= 255) {
        speed = 255;
      }
      if (speed <= 0) {
        speed = 0;
      }
}