//All credits for writeToFile, Sine and basically all the other types of oscillators
//go to Ciska Vriezenga https://github.com/ciskavriezenga/CSD_21-22/tree/master/csd2b/theorie/session_3
//Credits for Jack audio implementation go to Marc Groenewegen and Ciska Vriezenga
#include <iostream>
#include "beating.h"
using namespace std;

Beating::Beating(int midiNumber, double samplerate) : Synth(midiNumber, samplerate){
    cout<< "constructor Beating" <<endl;
}

Beating::~Beating(){
    cout<< "destructor Beating" <<endl;
}

void Beating::typeSynthCalc(){
    // get the sample of 2 waveforms and add them?
    //retrun that sample
    sine.nextSample();
    sample = sine.getSample();
}