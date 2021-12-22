#include "melody.h"

Melody::Melody()
{}

Melody::~Melody()
{}

void Melody::setCharHop(int hop){
  charHop = hop;
}

float Melody::getPitch()
{
  // wrap index
  index = index + charHop;
  if(index >= NUM_NOTES) {
    index = index - NUM_NOTES ;
  }
  // index++ --> first use current value to read from array, after this
  // increment with 1
  return baseMelody[index++];
}
