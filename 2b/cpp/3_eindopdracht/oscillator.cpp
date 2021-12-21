//All credits for writeToFile, Sine and basically all the other types of oscillators
//go to Ciska Vriezenga https://github.com/ciskavriezenga/CSD_21-22/tree/master/csd2b/theorie/session_3
//Credits for Jack audio implementation go to Marc Groenewegen and Ciska Vriezenga
#include <iostream>
#include "oscillator.h"
using namespace std;

Oscillator::Oscillator(){

}

Oscillator::Oscillator(double frequency, double samplerate) : frequency(frequency), samplerate(samplerate),
    amplitude(1.0), phase(0.0), sample(0){
    cout<< "contructor Oscillator" <<endl;
}

Oscillator::~Oscillator(){
    cout<< "destructor Oscillator" <<endl;
}

void Oscillator::setFrequency(double frequency){
// debug low_level
#if DEBUG == 3
    std::cout << "• Oscillator::setFrequency - frequency: " << frequency
      << std::endl;
#endif
    this->frequency = frequency;
}

void Oscillator::setAmplitude(double newAmplitude){
// debug low_level
#if DEBUG == 3
    std::cout << "• Oscillator::setFrequency - amplitude: " << amplitude << std::endl;
#endif
    this->amplitude = newAmplitude;
}

void Oscillator::setSamplerate(double samplerate){
    this->samplerate = samplerate;
}

double Oscillator::getSample(){
    return sample;
}

void Oscillator::nextSample(){
    phase += frequency / samplerate;
    if(phase > 1.0) phase -= 1.0;
    calculate();
    sample *= amplitude;
}
