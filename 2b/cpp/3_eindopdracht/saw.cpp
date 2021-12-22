#include <iostream>
#include "saw.h"

Saw::Saw(double frequency, double samplerate) : Oscillator(frequency, samplerate)
{
	std::cout<< "constructor Saw" <<std::endl;
}

Saw::~Saw()
{
	std::cout<< "destructor Saw" <<std::endl;
}

void Saw::calculate()
{
	// calculate saw wavefrom
	sample = (phase * 2 -1);
}
