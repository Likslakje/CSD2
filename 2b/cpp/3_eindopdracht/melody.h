#pragma once

#include <iostream>

#define NUM_NOTES 7

class Melody
{
public:
  Melody();
  ~Melody();

  // setters and getters
  void setCharHop(int hop);
  float getPitch();

protected:
  // Cmaj -  arpeggio
  float baseMelody[NUM_NOTES] = {60, 62, 64, 65, 67, 69, 71};
  // the index of the current note - readIndex
  int charHop;
  int index = 0;
};
