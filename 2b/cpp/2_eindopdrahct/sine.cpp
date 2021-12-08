//All credits for writeToFile, Sine and basically all the other types of oscillators
//go to Ciska Vriezenga https://github.com/ciskavriezenga/CSD_21-22/tree/master/csd2b/theorie/session_3
//Credits for Jack audio implementation go to Marc Groenewegen and Ciska Vriezenga
#include <iostream>
#include "sine.h"
using namespace std;

Sine::Sine(float frequency, double samplerate) : Oscillator(frequency, samplerate){
    cout<< "constructor Sine" <<endl;
}

Sine::~Sine(){
    cout<< "destructor Sine" <<endl;
}

float Sine::getSample(){
    return sample;
}

void Sine::calculate(){
    phase += getFrequency() / getSamplerate();
    if(phase < 1){
        sample = sin(M_PI * 2 * phase) * amplitude;
    }else{
        phase = 0;
    }
    cout<< "phase: " << phase << "sample: " << sample <<endl;
}