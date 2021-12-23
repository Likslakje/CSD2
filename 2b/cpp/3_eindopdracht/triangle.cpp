#include <iostream>
#include "triangle.h"
#include "math.h"
Triangle::Triangle(double frequency, double samplerate) : Oscillator(frequency, samplerate)
{
	std::cout<< "constructor Triangle" <<std::endl;
}

Triangle::~Triangle()
{
	std::cout<< "destructor Triangle" <<std::endl;
}

void Triangle::calculate()
{
	// calculate the triangle waveform
	if(phase <= 0.5){
			sample = phase;
	}else{
			sample = (phase * -1) + 0.5;
	}
}

