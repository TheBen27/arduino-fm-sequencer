#include <Arduino.h>

// Basic note datatype
union NoteEvent {
  byte raw;
  struct NoteOn {
    byte is_on: 1;
    byte pitch: 4;
    byte ticks: 3;
  } on;
  struct NoteOff {
    byte is_off:  1;
    byte padding: 4;
    byte ticks:   3;
  } off;
};

enum NoteScale {
  SCALE_MAJOR,
  SCALE_MINOR
};

struct NoteSong {
  // Array of note events to play
  NoteEvent *notes;
  unsigned short nsize;
  // Scale to use for each note
  NoteScale scale;
  // Octave multiplier
  signed char octave;
  // Length of each "tick", in milliseconds
  byte tick_length;

  NoteSong() = delete;
  NoteSong(NoteEvent *n, unsigned short nsize, NoteScale scale, byte octave, byte tick_length) {
    notes = n;
    this->nsize = nsize;
    this->scale = scale;
    this->octave = octave;
    this->tick_length = tick_length;
  }
};

void play(NoteSong song);

