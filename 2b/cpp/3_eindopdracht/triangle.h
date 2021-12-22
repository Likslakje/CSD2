#ifndef _TRIANGLE_H_
#define _TRIANGLE_H_
#include <iostream>
#include "oscillator.h"

class Triangle : public Oscillator
{
public:
  Triangle(double frequency, double samplerate);
  ~Triangle();

protected:
  // override the virtual calculate from Oscillator
  void calculate() override;
};

#endif
