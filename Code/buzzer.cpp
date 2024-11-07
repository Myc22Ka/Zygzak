#include "Buzzer.h"
#include "pitches.h"

Buzzer::Buzzer(int pin) : BUZZER_PIN(pin) {}

void Buzzer::begin() {
  pinMode(BUZZER_PIN, OUTPUT);
  off();
}

void Buzzer::on() {
  digitalWrite(BUZZER_PIN, HIGH);
}

void Buzzer::off() {
  digitalWrite(BUZZER_PIN, LOW);
  noTone(BUZZER_PIN);
}

void Buzzer::play() {
  int size = sizeof(durations) / sizeof(int);

  for (int note = 0; note < size; note++) {
    int duration = 1000 / durations[note];
    tone(BUZZER_PIN, melody[note], duration);

    int pauseBetweenNotes = duration * 1.30;
    delay(pauseBetweenNotes);
    
    noTone(BUZZER_PIN);
  }
}