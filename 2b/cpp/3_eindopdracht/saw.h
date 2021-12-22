#ifndef _SAW_H_
#define _SAW_H_
#include <iostream>
#include "oscillator.h"

class Saw : public Oscillator
{
public:
	Saw(double frequency, double samplerate);
	~Saw();

protected:
	// override the virtual calculate from Oscillator
	void calculate() override;
};

#endif