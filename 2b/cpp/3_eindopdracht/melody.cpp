//All credits for Melody go to Ciska Vriezenga https://github.com/ciskavriezenga/CSD_21-22/tree/taylorSwift/csd2b/theorie/session_5/01_melody

#include "melody.h"

Melody::Melody()
{}

Melody::~Melody()
{}

void Melody::setNoteHop(std::string melodyInput)
{
  // cast melodyInput string to a char* array
  charArray = &melodyInput[0];

  stringLength = melodyInput.length();
  // wrap numChars by using modulo
  int modulo = stringLength % NUM_NOTES;

  // hop through melody array
  // -1 so it can never be 6 in which case the note will stay the same
  if(modulo == NUM_NOTES -1){
    charHop = 1;
  }
  else if(modulo == 0){
    charHop = 1;
  }else{
    charHop = modulo;
  }
}

void Melody::setRhythmHop(std::string melodyInput){
  // make an array of the Ascii values of each char
  // divide the ascii value by 10 so it can be used as 
  // an time interval
  // Cast each char to its respective Ascii int
  // and append it to the rhythmHop array
  // Yes, I know the max length is set to 100...
  for(int i = 0; i < stringLength; i++){
    rhythmHop[i] = int(charArray[i]) / 100.f;
  }
}

float Melody::getPitch()
{
  // wrap index denpending on the number of midinotes
  
  index = index + charHop;
  if(index >= NUM_NOTES) {
    index = index - NUM_NOTES ;
  }
  // index++ --> first use current value to read from array, after this
  // increment with 1
  return baseMelody[index++];
}

int Melody::getStringLength(){
  return stringLength;
}

float* Melody::getRhythmHop(){
  return rhythmHop;
}