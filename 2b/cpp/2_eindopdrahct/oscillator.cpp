//All credits for writeToFile, Sine and basically all the other types of oscillators
//go to Ciska Vriezenga https://github.com/ciskavriezenga/CSD_21-22/tree/master/csd2b/theorie/session_3
//Credits for Jack audio implementation go to Marc Groenewegen and Ciska Vriezenga
#include <iostream>
#include "oscillator.h"
using namespace std;

Oscillator::Oscillator(double frequency, double samplerate) : frequency(frequency), samplerate(samplerate){
    cout<< "contructor Oscillator" <<endl;
}

Oscillator::~Oscillator(){
    cout<< "destructor Oscillator" <<endl;
}

bool Oscillator::setFrequency(double frequency){
    if(frequency > 20 && frequency < 20500) {
        this->frequency = frequency;
        return true;
    }
    return false;
}

void Oscillator::setSamplerate(double samplerate){
    this->samplerate = samplerate;
}

double Oscillator::getSample(){
    return sample;
}

void Oscillator::tick(){
    phase += frequency / samplerate;
    if(phase > 1.0) phase -= 1.0;
    calculate();
}