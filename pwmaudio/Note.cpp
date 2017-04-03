#include <Arduino.h>
#include "Note.h"

const static short scales[][16] = {
  /*SCALE_MAJOR*/ {523, 587, 659, 698, 784, 880, 987, 1046, 1174, 1318, 1396, 1568, 1760, 1975, 2093, 2349},
  /*SCALE_MINOR*/ {523, 587, 622, 698, 784, 880, 987, 1046, 1174, 1244, 1396, 1568, 1760, 1975, 2093, 2349}
};

void play(NoteSong song) {
  /*
   * For each event:
   *   Set the tone as (scales[song.scale] << song.octave)
   *   Wait for (song.tick_length * song.notes[n].ticks)
   */
  pinMode(10, OUTPUT);
  Serial.begin(9600);
  for (short i=0; i < song.nsize; i++) {
    NoteEvent note = song.notes[i];
    if (note.on.is_on == 1) {
      Serial.println(F("Note on"));
      short pitch = scales[song.scale][note.on.pitch];
      signed char octave = song.octave;
      if (octave < 0) {
        tone(10, pitch >> -octave);
      } else {
        tone(10, pitch << octave);
      }
      delay(note.on.ticks * song.tick_length);
    } else {
      Serial.println(F("Note off"));
      noTone(10);
      delay(note.off.ticks * song.tick_length);
    }
  }
  noTone(10);
}

