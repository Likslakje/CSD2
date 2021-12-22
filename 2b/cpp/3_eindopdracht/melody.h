//All credits for Melody go to Ciska Vriezenga https://github.com/ciskavriezenga/CSD_21-22/tree/taylorSwift/csd2b/theorie/session_5/01_melody

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
  // Cmaj midinotes
  float baseMelody[NUM_NOTES] = {60, 62, 64, 65, 67, 69, 71};

  // the index of the current note equals the index + charHop
  // then readIndex
  int charHop;
  int index = 0;
};
