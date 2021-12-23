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
  void setNoteHop(std::string melodyInput);
  void setRhythmHop(std::string melodyInput);
  float getPitch();
  int getStringLength();
  // pointer cuz it retruns the value at the rhythmHop adres
  float* getRhythmHop();

protected:
  // Cmaj midinotes
  float baseMelody[NUM_NOTES] = {60, 62, 64, 65, 67, 69, 71};

  // to cast melodyInput string to
  char* charArray;

  int stringLength;
  // the index of the current note equals the index + charHop
  // then readIndex
  int charHop;

  // rhythmHop array as long as number of possible notes
  // TODO: make array length dynamic depending on UserInput
  float rhythmHop[NUM_NOTES];
  int index = 0;
};
