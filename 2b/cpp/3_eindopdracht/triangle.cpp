#include <iostream>
#include "triangle.h"
#include "math.h"
Triangle::Triangle(double frequency, double samplerate) : Oscillator(frequency, samplerate)
{
	#if DEBUG >= 1
	std::cout<< "constructor Triangle" <<std::endl;
	#endif
}

Triangle::~Triangle()
{
	#if DEBUG >= 1
	std::cout<< "destructor Triangle" <<std::endl;
	#endif
}

void Triangle::calculate()
{
	double newSample = phase;
	if(newSample > 0.5) {
	// [0.5, 1] --> [0.5, 0]
	newSample = 1.0 - newSample;  
	sample = newSample;
	}
	// transform all values between [0, 0.5] to [-1, 1] 
	newSample *= 4.0;
	newSample -=1.0;
	sample = newSample;
}

