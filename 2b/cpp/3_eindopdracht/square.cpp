#include <iostream>
#include "square.h"

Square::Square(double frequency, double samplerate) : Oscillator(frequency, samplerate)
{
	std::cout<< "constructor Square" <<std::endl;
}

Square::~Square()
{
	std::cout<< "destructor Square" <<std::endl;
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