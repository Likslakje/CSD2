//All credits for writeToFile, Triangle and basically all the other types of oscillators
//go to Ciska Vriezenga https://github.com/ciskavriezenga/CSD_21-22/tree/master/csd2b/theorie/session_3
//Credits for Jack audio implementation go to Marc Groenewegen and Ciska Vriezenga
#ifndef _TRIANGLE_H_
#define _TRIANGLE_H_
#include <iostream>
#include "oscillator.h"
using namespace std;

class Triangle : public Oscillator{
  public:
    Triangle(double frequency, double samplerate);
    ~Triangle();
  protected:
    void calculate() override;
};

#endif
