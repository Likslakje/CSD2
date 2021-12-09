//All credits for writeToFile, Sine and basically all the other types of oscillators
//go to Ciska Vriezenga https://github.com/ciskavriezenga/CSD_21-22/tree/master/csd2b/theorie/session_3
//Credits for Jack audio implementation go to Marc Groenewegen and Ciska Vriezenga
#include <iostream>
#include "additive.h"
#include "sine.h"
#include "saw.h"
#include "square.h"
using namespace std;

Additive::Additive(int midiNumber, double samplerate) : Synth(midiNumber, samplerate){
    cout<< "constructor Additive" <<endl;
    // setFrequency();
    makeOscillator();
}

Additive::~Additive(){
    cout<< "destructor Additive" <<endl;
}

void Additive::makeOscillator(){
    Sine sine(getFrequency(), getSamplerate());
}