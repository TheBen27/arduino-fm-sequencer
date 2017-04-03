#include <iostream>

typedef unsigned char byte;

// Anatomy of a note event:
// 000 0000 0
// ticks pitch is_on

struct NoteOn {
    byte is_on: 1;
    byte pitch: 4;
    byte ticks: 3;
};

struct NoteOff {
    byte is_off:  1;
    byte padding: 7;
};

union Note {
  byte raw;
  NoteOn on;
  NoteOff off;
};

// Note event specification
Note noteOn(byte ticks, byte pitch) {
  Note n;
  n.on = NoteOn{ 1, pitch, ticks };
  return n;
}

Note noteOff(byte ticks) {
  Note n;
  n.off = NoteOff { 0 };
  return n;
}

Note notes[] = {
  noteOn(1, 0),
  noteOn(1, 1),
  noteOn(1, 2),
  noteOn(1, 3),
  noteOn(1, 4),
  noteOn(1, 5),
  noteOn(1, 6),
  noteOn(2, 7),
  noteOff(2),
  noteOn(1, 15),
  noteOn(1, 14),
  noteOn(1, 13),
  noteOn(1, 12),
  noteOn(1, 11),
  noteOn(1, 10),
  noteOn(1, 9),
  noteOn(1, 8),
  noteOn(1, 7)
};

int main(void) {
  std::cout << "Size of Note: " << sizeof(Note) << std::endl;
  std::cout << "NoteEvent notes[] = {" << std::endl;
  std::cout << std::hex;
  for (auto n : notes) {
    std::cout << "\t0x" << +n.raw << "," << std::endl;
  }
  std::cout << "};" << std::endl;
}
