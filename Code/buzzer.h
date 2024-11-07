#pragma once
#ifndef BUZZER_H
#define BUZZER_H

#include <Arduino.h>
#include "pitches.h"

class Buzzer {
private:
  int BUZZER_PIN;

  int melody[15] = {
  REST, NOTE_D4,
  NOTE_G4, NOTE_AS4, NOTE_A4,
  NOTE_G4, NOTE_D5,
  NOTE_C5, 
  NOTE_A4,
  NOTE_G4, NOTE_AS4, NOTE_A4,
  NOTE_F4, NOTE_GS4,
  NOTE_D4
};

int durations[15] = {
  2, 4,
  4, 8, 4,
  2, 4,
  2, 
  2,
  4, 8, 4,
  2, 4,
  1
};
  
public:
  Buzzer(int pin = 13);

  void begin();

  void on();

  void off();

  void play();

};

#endif // BUZZER_H