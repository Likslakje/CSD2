//All credits for writeToFile, Sine and basically all the other types of oscillators
//go to Ciska Vriezenga https://github.com/ciskavriezenga/CSD_21-22/tree/master/csd2b/theorie/session_3
//Credits for Jack audio implementation go to Marc Groenewegen and Ciska Vriezenga
#include <iostream>
#include "additive.h"
using namespace std;

Additive::Additive(int midiNumber, double samplerate) : Synth(midiNumber, samplerate){
    cout<< "constructor Additive" <<endl;
}

Additive::~Additive(){
    cout<< "destructor Additive" <<endl;
}

void Additive::typeSynthCalc(){
    // get the sample of 2 waveforms and add them?
    //retrun that sample
    waveforms[0]->nextSample();
    sample = waveforms[0]->getSample();
}