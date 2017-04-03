/*
 * PWM audio script. Connect Pin 10 to the signal jack of a passive buzzer.
 */
#include "Note.h"

const byte pin = 10;

NoteEvent notes[] = {
  0x21,
  0x23,
  0x25,
  0x27,
  0x29,
  0x2b,
  0x2d,
  0x4f,
  0x0,
  0x3f,
  0x3d,
  0x3b,
  0x39,
  0x37,
  0x35,
  0x33,
  0x31,
  0x2f,
};

void setup() {
  pinMode(10, OUTPUT);
  NoteSong song(
    notes,
    sizeof(notes) / sizeof(NoteEvent),
    SCALE_MINOR,
    -3,
    250
  );
  play(song);
}

void loop() {
  
}
