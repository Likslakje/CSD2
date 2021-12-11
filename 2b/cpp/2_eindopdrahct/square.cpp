//All credits for writeToFile, Sine and basically all the other types of oscillators
//go to Ciska Vriezenga https://github.com/ciskavriezenga/CSD_21-22/tree/master/csd2b/theorie/session_3
//Credits for Jack audio implementation go to Marc Groenewegen and Ciska Vriezenga
#include <iostream>
#include "square.h"
using namespace std;

Square::Square(float frequency, double samplerate) : Oscillator(frequency, samplerate){
    cout<< "constructor Square" <<endl;
}

Square::~Square(){
    cout<< "destructor Square" <<endl;
}

void Square::calculate(){
    phase += frequency / samplerate;
    if(phase < 1){
        if(phase >= 0.5){
            sample = -1.0f;
        }else{
            sample = 1.0f;
        }
        sample = sample * amplitude;
    }else{
        phase = 0;
    }
    cout<< "phase: " << phase << "sample: " << sample <<endl;
  
}