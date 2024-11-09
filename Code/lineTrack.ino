void lineTrack(int speed) {
  int lineColor = digitalRead(lineTrackPin);  // 0:white  1:black
  Serial.println(lineColor);
  if (lineColor) {
    forwardLeft(speed);
  } else {
    forwardRight(speed);
  }
}