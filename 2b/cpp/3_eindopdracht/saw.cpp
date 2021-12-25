#include <iostream>
#include "saw.h"

Saw::Saw(double frequency, double samplerate) : Oscillator(frequency, samplerate)
{
	#if DEBUG >= 1
	std::cout<< "constructor Saw" <<std::endl;
	#endif
}

Saw::~Saw()
{
	#if DEBUG >= 1
	std::cout<< "destructor Saw" <<std::endl;
	#endif
}

void Saw::calculate()
{
	// calculate saw wavefrom
	sample = (phase * 2 -1);
}
