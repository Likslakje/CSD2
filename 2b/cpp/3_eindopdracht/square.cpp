#include <iostream>
#include "square.h"

Square::Square(double frequency, double samplerate) : Oscillator(frequency, samplerate)
{
	#if DEBUG >= 1
	std::cout<< "constructor Square" <<std::endl;
	#endif
}

Square::~Square()
{
	#if DEBUG >= 1
	std::cout<< "destructor Square" <<std::endl;
	#endif
}

void Square::calculate()
{
	// calculate square waveform
	if(phase <= 0.5){
			sample = -1.0f;
	}else{
			sample = 1.0f;
	}
}