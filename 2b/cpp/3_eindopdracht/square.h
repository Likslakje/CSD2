#ifndef _SQUARE_H_
#define _SQUARE_H_
#include <iostream>
#include "oscillator.h"

class Square : public Oscillator
{
public:
	Square(double frequency, double samplerate);
	~Square();
	
protected:
  // override the virtual calculate from Oscillator
	void calculate() override; 
};

#endif