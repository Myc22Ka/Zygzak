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