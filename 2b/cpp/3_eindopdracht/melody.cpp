//All credits for Melody go to Ciska Vriezenga https://github.com/ciskavriezenga/CSD_21-22/tree/taylorSwift/csd2b/theorie/session_5/01_melody

#include "melody.h"

Melody::Melody()
{}

Melody::~Melody()
{}

void Melody::setCharHop(int hop)
{
  // set the charHop after userInput
  charHop = hop;
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
