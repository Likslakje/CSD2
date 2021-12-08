//All credits for writeToFile, Sine and basically all the other types of oscillators
//go to Ciska Vriezenga https://github.com/ciskavriezenga/CSD_21-22/tree/master/csd2b/theorie/session_3
//Credits for Jack audio implementation go to Marc Groenewegen and Ciska Vriezenga
#include <iostream>
#include "oscillator.h"
using namespace std;

Oscillator::Oscillator(float frequency, double samplerate) : frequency(frequency), samplerate(samplerate){
    cout<< "contructor Oscillator" <<endl;
}

Oscillator::~Oscillator(){
    cout<< "destructor Oscillator" <<endl;
}

void Oscillator::setFrequency(float frequency){
    this->frequency = frequency;
}

void Oscillator::setSamplerate(double samplerate){
    this->samplerate = samplerate;
}

float Oscillator::getFrequency(){
    return frequency;
}

double Oscillator::getSamplerate(){
    return samplerate;
}


